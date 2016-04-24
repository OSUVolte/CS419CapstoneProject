/******************************************************************************
 * Filename: unittest1.c
 * Author: Jens Bodal
 * Date: April 22, 2016
 * Description: 
 * Input: 
 * Output: 
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "assert.h"
#include <stdio.h>

// fills deck with one of each type of card
void fillDeck(struct gameState *state);

// checks inability to shuffle an empty deck by drawing all cards and trying to shuffle deck
void testShuffleEmptyDeck(struct gameState *state);

// checks count of deck, hand, and discard before and after shuffling
void testPostShuffleCounts(struct gameState *state);

// checks count of each card before and after shuffling
void testPostShuffleCards(struct gameState *state, int *cards, int numCards);

int main() {
    int players = 4;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 187;

    struct gameState game;
    initializeGame(players, cards, seed, &game);

    printf("Testing shuffle");
    printf("-- SIMPLE FIXED TESTS --\n");
    
    printf(" -- TESTING INABILITY TO SHUFFLE EMPTY DECK -- \n");
    initializeGame(players, cards, seed, &game);
    fillDeck(&game);
    testShuffleEmptyDeck(&game);
   
    printf(" -- TESTING COUNT OF DECK, HAND, & DISCARD PRE AND POST SHUFFLE -- \n");
    initializeGame(players, cards, seed, &game);
    fillDeck(&game);    
    testPostShuffleCounts(&game);
    
    printf(" -- TESTING COUNT OF KNOWN CARDS PRE & POST SHUFFLE -- \n");
    initializeGame(players, cards, seed, &game);
    fillDeck(&game);
    testPostShuffleCards(&game, cards, 10);

    printf(" -- TESTING COUNT OF INITIALIZED CARDS PRE & POST SHUFFLE -- \n");
    initializeGame(players, cards, seed, &game);
    testPostShuffleCards(&game, cards, 10);
    return 0;
}

void fillDeck(struct gameState *state) {
    int i;
    for (i = 0; i < state->numPlayers; i++) {
        state->deckCount[i] = 10;
        state->deck[i][0] = adventurer;
        state->deck[i][1] = gardens;
        state->deck[i][2] = embargo;
        state->deck[i][3] = village;
        state->deck[i][4] = minion;
        state->deck[i][5] = mine;
        state->deck[i][6] = cutpurse;
        state->deck[i][7] = sea_hag;
        state->deck[i][8] = tribute;
        state->deck[i][9] = smithy;
    }
}

void testShuffleEmptyDeck(struct gameState *state) {
    int p = state->whoseTurn;
    int i;
    // draw cards until we have no more cards in our deck
    for (i = state->deckCount[p]; i > 0; i--) {
        drawCard(p, state);
    }
    // assert there are no cards in deck
    assert(state->deckCount[p] == 0);
    int shuffleResult = shuffle(p, state);
    // assert that we cannot shuffle an empty deck
    assert(shuffleResult == -1);
    printf("SUCCESS: Cannot shuffle an empty deck\n");
}

void testPostShuffleCounts(struct gameState *state) {
    int player = state->whoseTurn;
    int players = state->numPlayers;
    int preDeckCount[players];
    int preHandCount[players];
    int preDiscardCount[players];
    int postDeckCount[players];
    int postHandCount[players];
    int postDiscardCount[players];
    int i;

    for (i = 0; i < players; i++) {
        preDeckCount[i] = state->deckCount[i];
        preHandCount[i] = state->deckCount[i];
        preDiscardCount[i] = state->deckCount[i];
    }
    
    shuffle(player, state);
    
    for (i = 0; i < players; i++) {
        postDeckCount[i] = state->deckCount[i];
        postHandCount[i] = state->deckCount[i];
        postDiscardCount[i] = state->deckCount[i];
        assert(preDeckCount[i] == postDeckCount[i]);
        printf("SUCCESS: deckCount for player [%d] same size before and after shuffling\n", i);
        assert(preHandCount[i] == postHandCount[i]);
        printf("SUCCESS: handCount for player [%d] same size before and after shuffling\n", i);
        assert(preDiscardCount[i] == postDiscardCount[i]);
        printf("SUCCESS: discardCount for player [%d] same size before and after shuffling\n", i);
    }
}

void testPostShuffleCards(struct gameState *state, int *cards, int numCards) {
    int i, j;
    int preCounts[state->numPlayers][MAX_DECK];
    int postCounts[state->numPlayers][MAX_DECK];

    // initialize all counts to 0
    for (i = 0; i < state->numPlayers; i++) {
        for (j = 0; j < MAX_DECK; j++) {
            preCounts[i][j] = 0;
            postCounts[i][j] = 0;
        }
    }

    // use card's enum value as index and increment counter
    for (i = 0; i < state->numPlayers; i++) {
        for (j = 0; j < state->deckCount[i]; j++) {
            int card = state->deck[i][j];
            preCounts[i][card]++;
        }
        // after counting cards in players' deck, shuffle their deck
        shuffle(i, state);

        // count the number of cards in each player's deck after it's been shuffled
        for (j = 0; j < state->deckCount[i]; j++) {
            int card = state->deck[i][j];
            postCounts[i][card]++;
        }
    }

    // using the enum value of each card in our game, check the pre and post counts for that card
    for (i = 0; i < state->numPlayers; i++) {
        for (j = 0; j < numCards; j++) {
            int card = cards[j];
            assert(postCounts[i][card] == preCounts[i][card]);
        }
        printf("SUCCESS: player [%d] has same card counts before and after shuffling\n", i);
    }
}

