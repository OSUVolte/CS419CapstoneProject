#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// isGameOver() test

// This file tests the isGameOver() function. isGameOver() determines if the game is
// over by checking the number of empty provinces and supply piles.

// What to test:
    // Immediately after game initialization
    // 3 empty piles of action cards
    // 2 empty piles of action cards
    // 1 empty pile of action cards
    // 1 empty pile of province cards

int main (int argc, char** argv) {
    printf ("---------- Testing isGameOver() ----------\n");
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 10, &G);
    
    
    // TEST 1:
    // Immediately after game initialization
    if(!isGameOver(&G))
        printf ("isGameOver() test1: passed.\n");
    else
        printf ("isGameOver() test1: failed.\n");

    
    // Create 3 empty piles and test.
    G.supplyCount[adventurer] = 0;
    G.supplyCount[council_room] = 0;
    G.supplyCount[feast] = 0;
    
    
    // TEST 2:
    // 3 empty piles of action cards
    if(isGameOver(&G))
        printf ("isGameOver() test2: passed.\n");
    else
        printf ("isGameOver() test2: failed.\n");

    
    // TEST 3:
    // 2 empty piles of action cards
    G.supplyCount[adventurer] = 1;
    if(!isGameOver(&G))
        printf ("isGameOver() test3: passed.\n");
    else
        printf ("isGameOver() test3: failed.\n");

    
    // TEST 4:
    // 1 empty pile of action cards
    G.supplyCount[council_room] = 1;
    if(!isGameOver(&G))
        printf ("isGameOver() test4: passed.\n");
    else
        printf ("isGameOver() test4: failed.\n");


    // TEST 5:
    // 1 empty pile of province cards
    G.supplyCount[province] = 0;
    if(isGameOver(&G))
        printf ("isGameOver() test5: passed.\n");
    else
        printf ("isGameOver() test5: failed.\n");

    return 0;
}