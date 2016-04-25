/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Unit Test for gainCard()
*************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTFCN "gainCard()"

int main() {
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int thisPlayer = 0;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;

    printf("----------------- Testing Function: %s ----------------\n", TESTFCN);
    
    // Test 1
    printf("TEST 1: Return -1 if no cards in supply pile\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &testG);
    testG.supplyCount[copper] = 0;

    if(gainCard(copper, &testG, 0, thisPlayer) == -1) {
    	printf("SUCCESS\n");
    }
    else {
    	printf("FAILURE\n");
    }

    // Test 2
    printf("TEST 1: toFlag = 0. Card should discard\n");
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    if(gainCard(copper, &testG, 0, thisPlayer) == 0 && testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]+1) {
    	printf("SUCCESS\n");
    }
    else {
    	printf("FAILURE\n");
    }


    // Test 3
    printf("TEST 3: toFlag = 1. Card should be added to deck \n");
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    if(gainCard(copper, &testG, 1, thisPlayer) == 0 && testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] + 1) {
    	printf("SUCCESS\n");
    }
    else {
    	printf("FAILURE\n");
    }


    // Test 3
    printf("TEST 3: toFlag = 2. Card should be added to hand \n");
	initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    if(gainCard(copper, &testG, 2, thisPlayer) == 0 && testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1) {
    	printf("SUCCESS\n");
    }
    else {
    	printf("FAILURE\n");
    }
   	

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFCN);

    return 0;
}



