/******************************************************************************
 * Filename: cardtest3.c
 * Author: Jens Bodal
 * Date: April 24, 2016
 * Description: testing village
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h" 
#include "assert.h"
#include <stdio.h>
#include <string.h>

int drawSpecificCard(struct gameState *state, int player, int card);
int placeOnDeck(struct gameState *state, int player, int card);
void printCards(int *phand, int numCards, char *dtype);
char *getCardName(int card);
void printHand(struct gameState *state, int player);
int countCardInHand(struct gameState *state, int player, int card);
int countTreasureInHand(struct gameState *state, int targetPlayer);
void testAdventurer(struct gameState *state, int treasure1, int treasure2);
void checkPlayAdventurer(struct gameState *state, int targetPlayer);

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
    
    drawSpecificCard(state, targetPlayer, village);
    printHand(state, targetPlayer);
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

void printCards(int *pHand, int numCards, char *dtype) {
    int i;
    printf("Printing current %s:\n", dtype);
    for (i = 0; i < numCards; i++) {
        printf("  Pos [%d] Card [%d:%s]\n", i, pHand[i], getCardName(pHand[i]));
    }
    printf("  Cards in %s: %d\n\n", dtype, numCards);
}

void printHand(struct gameState *state, int player) {
    printCards(state->hand[player], state->handCount[player], "hand");
}

char *getCardName(int card) {
    switch(card) {
        case curse:
            return "curse";
        case estate:
            return "estate";
        case duchy:
            return "duchy";
        case province:
            return "province";
        case copper:
            return "copper";
        case silver:
            return "silver";
        case gold:
            return "gold";
        case adventurer:
            return "adventurer";
        case council_room:
            return "council_room";
        case feast:
            return "feast";
        case gardens:
            return "gardens";
        case mine:
            return "mine";
        case remodel:
            return "remodel";
        case smithy:
            return "smithy";
        case village:
            return "village";
        case baron:
            return "baron";
        case great_hall:
            return "great_hall";
        case minion:
            return "minion";
        case steward:
            return "steward";
        case tribute:
            return "tribute";
        case ambassador:
            return "ambassador";
        case cutpurse:
            return "cutpurse";
        case embargo:
            return "embargo";
        case outpost:
            return "outpost";
        case salvager:
            return "salvager";
        case sea_hag:
            return "sea_hag";
        case treasure_map:
            return "treasure_map";
        default:
            return "unknown";
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

int countTreasureInHand(struct gameState *state, int targetPlayer) {
    int treasureCount = 0;
    treasureCount += countCardInHand(state, targetPlayer, copper);
    treasureCount += countCardInHand(state, targetPlayer, silver);
    treasureCount += countCardInHand(state, targetPlayer, gold);
    return treasureCount;
}

void testAdventurer(struct gameState *state, int treasure1, int treasure2) {
    int targetPlayer = 0;
    // put two copper on top so that when we play adventurer they should be drawn
    placeOnDeck(state, targetPlayer, treasure1);
    placeOnDeck(state, targetPlayer, treasure2);
    // get card order and count before smithy
    checkPlayAdventurer(state, targetPlayer);

}

void checkPlayAdventurer(struct gameState *state, int targetPlayer) {
    int oldCount = state->handCount[targetPlayer];
    int oldPos[oldCount];
    memcpy(oldPos, state->hand[targetPlayer], oldCount * sizeof(int));
    // count treasure
    int treasureCount = countTreasureInHand(state, targetPlayer);
    // count adventurer 
    int adventCount = countCardInHand(state, targetPlayer, adventurer);
    // draw adventurer
    int adventurerPos = drawSpecificCard(state, targetPlayer, adventurer);
   
    // play adventurer from previously acquired position
    playAdventurer(targetPlayer, state);
    
    // check treasure count has increased by 2
    if (countTreasureInHand(state, targetPlayer) != treasureCount + 2) {
        printf("FAIL: [playAdventurer] We did not gain two treasure cards\n");
    }
    else {
        printf("SUCCESS: [playAdventurer] Correct number of treasure cards gained\n");
    }
    // check adventurer count is same before drawing adventurer and after playing him
    if (countCardInHand(state, targetPlayer, adventurer) != adventCount) {
        printf("FAIL: [playAdventurer] Adventurer card was not discarded\n");
    }
    else {
        printf("SUCCESS: [playAdventurer] Adventurer card was discarded\n");
    }
    // check hand is 2 bigger than before drawing adventurer and after playing him

}

