/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
    printf("TEST 1: Draw 4 cards \n");
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));

    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("Hand Count: actual %d, expected %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 4 - discarded);
    
    if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 4 - discarded)
    {
        printf("TEST PASSED\n\n");
    }
    else
    {
        printf("TEST FAILED\n\n");
    }
    
    // ----------- TEST 2: --------------
    printf("TEST 2: Other player draws a card \n");
    
    printf("Hand Count for other player: actual %d, expected %d\n", testG.handCount[thisPlayer+1], G.handCount[thisPlayer+1] + 1);
    
    if (testG.handCount[thisPlayer+1] == G.handCount[thisPlayer+1] + 1)
    {
        printf("TEST PASSED\n\n");
    }
    else
    {
        printf("TEST FAILED\n\n");
    }
    
    // ----------- TEST 3: --------------
    printf("TEST 3: Number of Buys + 1 \n");
    
    printf("NumBuys: actual: %d, expected %d\n", testG.numBuys, G.numBuys +1 );
    
    if (testG.numBuys == G.numBuys +1)
    {
        printf("TEST PASSED\n\n");
    }
    else
    {
        printf("TEST FAILED\n\n");
    }
    
 
    
    

    return 0;

}