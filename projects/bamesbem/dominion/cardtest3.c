/*
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Village"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    
    // ----------- TEST 1: --------------
    printf("TEST 1: Draw card \n");
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("Hand count: actual: %d, expected %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1 - discarded);
    
    if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1 - discarded){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    // ----------- TEST 2: --------------
    printf("TEST 2: Add two actions \n");
    
    printf("Action count: actual %d, expected %d\n", testG.numActions, G.numActions + 2 );
    
    if (testG.numActions == G.numActions + 2 ){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    
    return 0;
}

