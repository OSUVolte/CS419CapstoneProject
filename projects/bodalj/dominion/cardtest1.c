/******************************************************************************
 * Filename: cardtest1.c
 * Author: Jens Bodal
 * Date: April 23, 2016
 * Description: 
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h" 
#include "assert.h"
#include <stdio.h>

int drawSpecificCard(struct gameState *state, int player, int card);
int placeOnDeck(struct gameState *state, int player, int card);
void printHand(int *phand, int numCards);
int countCardInHand(struct gameState *state, int player, int card);

int main() {
    int players = 4;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 187;
    int trash = 1;
    int targetPlayer = 0;
    int i;
    int iterations = 10;
    int FOUND_BUG = 0;
    struct gameState game;
    struct gameState *state = &game;
    initializeGame(players, cards, seed, &game);

    // get card order and count before smithy
    int oldCount = state->handCount[targetPlayer];
    int oldPos[oldCount];
    memcpy(oldPos, state->hand[targetPlayer], oldCount * sizeof(int));
    // draw smithy
    int smithyPos = drawSpecificCard(state, targetPlayer, smithy);
    
    // put three minion cards on top of deck to ensure they are the ones drawn with smithy
    placeOnDeck(state, targetPlayer, adventurer);
    placeOnDeck(state, targetPlayer, minion);
    placeOnDeck(state, targetPlayer, mine);
    // play smithy from previously acquired position
    playSmithy(targetPlayer, smithyPos, state);
    // compare order of cards before Smithy and after playing Smithy, order should not change
    // NOTE: This does not concern that cards that Smithy draws, only those that were there before playing Smithy
    int comparePos;
    if (comparePos = memcmp(oldPos, state->hand[targetPlayer], oldCount *sizeof(int))) {
        printf("FAIL: [playSmithy] Card order has changed (%d)\n", comparePos);
    }
    else {
        printf("SUCCESS: [playSmithy] Card order unchanged\n");
    }

    // check that we drew three cards and discarded one
    if ((oldCount+3) != state->handCount[targetPlayer]) {
        printf("FAIL: [playSmithy] Wrong number of cards in hand after playing smithy\n");
    }
    else {
        printf("SUCCESS: [playSmithy] Correct number of cards drawn and discarded\n");
    }
    // make sure we have no Smithys in hand and that he was discarded
    int smithyCount = countCardInHand(state, targetPlayer, smithy);    
    if (smithyCount != 0) {
        printf("FAIL: [playSmithy] We have %d Smithy in hand and we should have %d\n", smithyCount, 0);
    }
    else {
        printf("SUCCESS: [playSmithy] Smithy has been discarded\n");
    }
         
    return 0;
}

// places specified card in deck then draws it
int drawSpecificCard(struct gameState *state, int player, int card) {
    int i;
    int pos = state->deckCount[player]++;
    state->deck[player][pos] = card;
    if (drawCard(player, state) == -1) {
        return -1;   
    }
    return pos; 
}

int placeOnDeck(struct gameState *state, int player, int card) {
    int i;
    int pos = state->deckCount[player]++;
    state->deck[player][pos] = card;
    return 1;
}

void printHand(int *pHand, int numCards) {
    int i;
    printf("Printing current hand:\n");
    for (i = 0; i < numCards; i++) {
        printf("  Pos [%d] Card [%d]\n", i, pHand[i]);
    }
}

int countCardInHand(struct gameState *state, int player, int card) {
    int i;
    int count = 0;
    for (i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) count++;
    }
    return count;
}


