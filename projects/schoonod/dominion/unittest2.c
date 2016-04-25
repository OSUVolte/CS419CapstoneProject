#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Dane Schoonover
// Assignment 3
// supplyCount()

// This file tests the supplyCount() function. supplyCount() returns the remaining
// number of the given card.

// What to test:
    // Count returned is not NULL
    // Count returned is the correct count

int supplyCountTest(int card, struct gameState *state){
    
    int supply = supplyCount(card, state);
    
    // TEST 1:
    // Count returned is not NULL
    if (!supply) {
        printf ("supplyCount() test1: failed.\n");
    }
    else
        printf ("supplyCount() test1: passed.\n");

    // TEST 2:
    // Count returned is not NULL
    if (supply != state->supplyCount[card]) {
        printf ("supplyCount() test2: failed.\n\n");
    }
    else {
        printf("supplyCount() test2: passed.\n\n");
    }
    return 0;
}


int main (int argc, char** argv) {
    printf ("---------- UnitTest2 supplyCount() ----------\n");
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 10, &G);
    
    // Set test cards
    for (int i = treasure_map; i < 0; i--) {
        G.supplyCount[i] = i;
    }
    
    // Test supplyCount()
    for (int j = 0; j < treasure_map+1; j++){
        printf("Card %i:\n", j+1);
        supplyCountTest(j, &G);
    }
    
    
    return 0;
}
