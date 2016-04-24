#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// great_hall test

// This file tests the great_hall card effect.

// What to test:
    // Current player handcount increased by 1
    // Current player's deck count reduces by 1
    // Current player gets one more action
    // Council_room card has been replaced by next card in hand

int main (int argc, char** argv) {
    printf ("---------- Testing great_hall() ----------\n");
    int handPos = 0;
    int coin_bonus = 0;
    
    // Create a game
    int numPlayers = 2;
    struct gameState G;     // initial state
    struct gameState G2;    // post great_hall card state
    int z[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, z, 10, &G);
    initializeGame(numPlayers, z, 10, &G2);
    
    // Default current player
    G.whoseTurn = 0;
    
    // Set Great Hall card to handPos
    G.hand[G.whoseTurn][handPos] = great_hall;
    
    // Play the card
    cardEffect(great_hall, 0,0,0, &G2, handPos, &coin_bonus);
    
    // TEST 1
    // Current player adds one card to their hand
    if (G2.handCount[G.whoseTurn] == G.handCount[G.whoseTurn])
        printf ("great_hall test1: passed.\n");
    else
        printf ("great_hall test1: failed.\n");
    
    // TEST 2
    // Current player's deck count reduces by 1
    if (G2.deckCount[G.whoseTurn] == (G.deckCount[G.whoseTurn] - 1))
        printf ("great_hall test2: passed.\n");
    else
        printf ("great_hall test2: failed.\n");
    
    // TEST 3
    // Current player gets one more action
    if (G2.numActions == (G.numActions + 1))
        printf ("great_hall test3: passed.\n");
    else
        printf ("great_hall test3: failed.\n");
    
    // TEST 4
    // Council_room card has been replaced by next card in hand
    if (G2.hand[G.whoseTurn][handPos] > -1)
        printf ("great_hall test4: passed.\n");
    else
        printf ("great_hall test4: failed.\n");
    
    return 0;
}