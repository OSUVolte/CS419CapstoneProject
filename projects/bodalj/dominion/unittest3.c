/******************************************************************************
 * Filename: unittest3.c
 * Author: Jens Bodal
 * Date: April 23, 2016
 * Description: testing drawCard function
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h" 
#include "assert.h"
#include <stdio.h>

int BUG_FOUND = 0;

void fillDeckWithCards(struct gameState *state, int player);
int countCardInDeck(struct gameState *state, int player, int card);
int countCardInHand(struct gameState *state, int player, int card);
int countCardInDiscard(struct gameState *state, int player, int card);
int countCardInPlayed(struct gameState *state, int card);
void setCounts(struct gameState *state, int targetPlayer, int **counts);
void discardHand(struct gameState *state, int player, int trashFlag);

int main() {
    int players = 4;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 187;
    int cardDeckCount, cardHandCount, cardDiscardCount, cardPlayedCount, deckCount, handCount, discardCount, playedCardCount;
    int *counts[] = {&cardDeckCount, &cardHandCount, &cardDiscardCount, &cardPlayedCount, &deckCount, &handCount, &discardCount, &playedCardCount};
    int trash = 1;
    int targetPlayer = 0;
    struct gameState game;
    struct gameState *state = &game;
    
    printf("TESTING drawCard function\n");
    
    // draw 5 adventurers
    printf("-- CONTROL TEST INTERNAL COUNT FUNCTION --\n");
    initializeGame(players, cards, seed, state);
    fillDeckWithCards(state, targetPlayer);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    setCounts(state, targetPlayer, counts);
    
    if (cardDeckCount != 4) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [cardDeckCount]\n");
    }
    if (cardHandCount != 5) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [cardHandCount]\n");
    }
    if (cardDiscardCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [cardDiscardCount]\n");
    }
    if (cardPlayedCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [cardPlayedCount]\n");
    }
    if (deckCount != 5) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [deckCount]\n");
    }
    if (handCount != 10) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [handCount]\n");
    }
    if (discardCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [discardCount]\n");
    }
    if (playedCardCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Draw 5 [playedCardCount]\n");
    }
    if (BUG_FOUND == 0) {
        printf("SUCCESS: Draw 5 cards\n");
    }
    
    // draw 2 adventurers, discard top card to discard pile, will be an adventurer
    printf("-- TEST DISCARD NOT TRASH --\n");
    initializeGame(players, cards, seed, state);
    fillDeckWithCards(state, targetPlayer);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    discardCard(state->handCount[targetPlayer]-1, targetPlayer, state, !trash);
    setCounts(state, targetPlayer, counts);
    
    if (cardDeckCount != 7) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [cardDeckCount is (%d) should be (%d)]\n", cardDeckCount, 7);
    }
    if (cardHandCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [cardHandCount is (%d) should be (%d)]\n", cardHandCount, 1);
    }
    if (cardDiscardCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [cardDiscardCount is (%d) should be (%d)]\n", cardDiscardCount, 1);
    }
    if (cardPlayedCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [cardPlayedCount is (%d) should be (%d)]\n", cardPlayedCount, 1);
    }
    if (deckCount != 8) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [deckCount is (%d) should be (%d)]\n", deckCount, 8);
    }
    if (handCount != 6) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [handCount is (%d) should be (%d)]\n", handCount, 6);
    }
    if (discardCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [discardCount is (%d) should be (%d)]\n", discardCount, 1);
    }
    if (playedCardCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [not trash] [playedCardCount is (%d) should be (%d)]\n", playedCardCount, 1);
    }
    if (BUG_FOUND == 0) {
        printf("SUCCESS: Discard [not trash] cards\n");
    }

    // discard top card to trash, will be an adventurer card
    printf("-- TEST DISCARD TO TRASH --\n");
    initializeGame(players, cards, seed, state);
    fillDeckWithCards(state, targetPlayer);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    discardCard(state->handCount[targetPlayer]-1, targetPlayer, state, trash);
    setCounts(state, targetPlayer, counts); 
    
    if (cardDeckCount != 6) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [cardDeckCount is (%d) should be (%d)]\n", cardDeckCount, 6);
    }
    if (cardHandCount != 2) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [cardHandCount is (%d) should be (%d)]\n", cardHandCount, 2);
    }
    if (cardDiscardCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [cardDiscardCount is (%d) should be (%d)]\n", cardDiscardCount, 0);
    }
    if (cardPlayedCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [cardPlayedCount is (%d) should be (%d)]\n", cardPlayedCount, 1);
    }
    if (deckCount != 7) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [deckCount is (%d) should be (%d)]\n", deckCount, 7);
    }
    if (handCount != 7) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [handCount is (%d) should be (%d)]\n", handCount, 7);
    }
    if (discardCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [discardCount is (%d) should be (%d)]\n", discardCount, 0);
    }
    if (playedCardCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard [is trash] [playedCardCount is (%d) should be (%d)]\n", playedCardCount, 1);
    }
    if (BUG_FOUND == 0) {
        printf("SUCCESS: Discard [is trash] cards\n");
    }

    // draw all but 2 cards (smithy and adventurer) and discard hand
    printf("-- TEST DISCARD HAND --\n");
    initializeGame(players, cards, seed, state);
    fillDeckWithCards(state, targetPlayer);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    drawCard(targetPlayer, state);
    discardHand(state, 0, !trash);
    setCounts(state, targetPlayer, counts); 
    
    if (cardDeckCount != 1) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [cardDeckCount is (%d) should be (%d)]\n", cardDeckCount, 1);
    }
    if (cardHandCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [cardHandCount is (%d) should be (%d)]\n", cardHandCount, 0);
    }
    if (cardDiscardCount != 8) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [cardDiscardCount is (%d) should be (%d)]\n", cardDiscardCount, 8);
    }
    if (cardPlayedCount != 13) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [cardPlayedCount is (%d) should be (%d)]\n", cardPlayedCount, 13);
    }
    if (deckCount != 2) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [deckCount is (%d) should be (%d)]\n", deckCount, 2);
    }
    if (handCount != 0) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [handCount is (%d) should be (%d)]\n", handCount, 0);
    }
    if (discardCount != 13) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [discardCount is (%d) should be (%d)]\n", discardCount, 13);
    }
    if (playedCardCount != 13) {
        BUG_FOUND = 1;
        printf("ERROR: Discard hand [not trash] [playedCardCount is (%d) should be (%d)]\n", playedCardCount, 13);
    }
    if (BUG_FOUND == 0) {
        printf("SUCCESS: Discard hand [not trash] cards\n");
    }
 
    return 0;
}

// replaces deck with 1 smithy card (bottom of pile) and 9 adventurer cards
void fillDeckWithCards(struct gameState *state, int player) {
    int i;
    state->deckCount[player] = 10;

    state->deck[player][0] = smithy;
    
    for (i = 1; i < 10; i++) {
        state->deck[player][i] = adventurer;
    }
}

int countCardInDeck(struct gameState *state, int player, int card) {
    int i;
    int count = 0;
    for (i = 0; i < state->deckCount[player]; i++) {
        if (state->deck[player][i] == card) count++;
    }
    return count;
}

int countCardInDiscard(struct gameState *state, int player, int card) {
    int i;
    int count = 0;
    for (i = 0; i < state->discardCount[player]; i++) {
        if (state->discard[player][i] == card) count++;
    }
    return count;
}

int countCardInHand(struct gameState *state, int player, int card) {
    int i;
    int count = 0;
    for (i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) count++;
    }
    return count;

}

int countCardInPlayed(struct gameState *state, int card) {
    int i;
    int count = 0;
    for (i = 0; i < state->playedCardCount; i++) {
        if (state->playedCards[i] == card) count++;
    }
    return count;
}

void setCounts(struct gameState *state, int targetPlayer, int **counts) {
    *(counts[0]) = countCardInDeck(state, targetPlayer, adventurer);
    *(counts[1]) = countCardInHand(state, targetPlayer, adventurer);
    *(counts[2]) = countCardInDiscard(state, targetPlayer, adventurer);
    *(counts[3]) = countCardInPlayed(state, adventurer);
    *(counts[4]) = state->deckCount[targetPlayer];
    *(counts[5]) = state->handCount[targetPlayer];
    *(counts[6]) = state->discardCount[targetPlayer];
    *(counts[7]) = state->playedCardCount;
}

void discardHand(struct gameState *state, int player, int trashFlag) {
    int i;
    int numCards = state->handCount[player];
    for (i = 0; i < numCards; i++) {
        discardCard(i, player, state, trashFlag);
    }
}
