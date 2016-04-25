/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

Tests the adventurer card

Tested behavior: Cards are revealed from the player's own deck until two treasure cards are
revealed and added to the player's hand. If the deck needs to be reshuffled, the cards that
have already been revealed are not reshuffled. All revealed cards not placed into the player's
hand are discarded.  The adventurer card itself should also be discarded.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, k, x, handPos,
	int player=0;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int maxHandPos = 5;
    struct gameState T, G;

    /////// Announce testing
    printf("Testing Adventurer card:\n");

    //Initialize game
    x = initializeGame(numPlayers, k, seed, &T);

    // Fill player's deck
    T.deckCount[player] = 5;
    T.deck[player][0] = smithy;
    T.deck[player][1] = smithy;
    T.deck[player][2] = smithy;
    T.deck[player][3] = silver;
    T.deck[player][4] = gold;

    //Set up player's hand.
    T.handCount[player] = 1;
    T.hand[player][0] = adventurer;

    // Set initial discard to zero
    T.discardCount[player] = 0;

    // Copy initial state T into G
    memcpy(&G, &T, sizeof(struct gameState));

    // Expected Results
    int played = 4; // adventurer and 3 smithy cards on top of deck
    int newCoins = 2;
    int estHand = 2; // There should just be the 2 treasure cards
    int estDeck = 0; // treasure to hand and others discarded

    // Play adventurer card
    adventurerCard(&G, player, handpos)

    // Print results
    printf("TEST 1: hand count = %d. Expected result = %d.\n", G.handCount[player], estHand));

    // Error message if hand count not expected
    if (G.handCount[player] != estHand){
        printf("TEST 1 FAILED!\n");
    }

    // Print results
    printf("TEST 2: played count = %d. Expected result = %d.\n", G.playedCardCount, played));

    // Error message if played cards not expected
    if (G.playedCardCount != played){
        printf("TEST 2 FAILED!\n");
    }

    // Print results
    printf("TEST 3: coins = %d. Expected result = %d.\n", G.coins[player], newCoins));

    // Error message if new coins not as expected
    if (G.coins[player] != newCoins){
        printf("TEST 3 FAILED!\n");
    }

    // Print results
    printf("TEST 4: deck count = %d. Expected result = %d.\n", G.deckCount[player], estDeck));

    // Error message if deck count not reduced as expected
    if (G.deckCount[player] != estDeck){
        printf("TEST 4 FAILED!\n");
    }

    // Print passed message if all tests passed
    if (G.handCount[player] == estHand && G.playedCardCount == played && G.coins[player] == newCoins && G.deckCount[player] == estDeck){
        printf("All 4 tests passed!\n");
    }
    return 0;
}
