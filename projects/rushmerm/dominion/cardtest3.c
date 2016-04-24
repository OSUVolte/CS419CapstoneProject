/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Test for Steward Card
*************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "steward"

int main() {

    int i, j;
    int handpos = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// Test 1: Choice 1, verify 2 cards have been drawn
	printf("TEST 1: choice 1. Verify 2 cards drawn\n");
	// Play adventurer
	cardEffect(steward, 1, 0, 0, &testG, handpos, 0);
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1) {
		printf("SUCCESS\n");
	}
	else {
		printf("FAILURE\n");
	}

	// Test 2: Choice 2, verify 2 coins are added
	printf("TEST 2: choice 3. Verify 2 coins added\n");
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(steward, 2, 0, 0, &testG, handpos, 0);
	if(testG.coins == G.coins + 2) {
		printf("SUCCESS\n");
	}
	else {
		printf("FAILURE\n");
	}

	// Test 3: Choice 3, verify 2 cards have been trashed
	printf("TEST 3: choice 3. Verify 2 cards trashed\n");
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(steward, 3, 1, 2, &testG, handpos, 0);
	if(G.handCount[thisPlayer] == testG.handCount[thisPlayer]) {
		printf("SUCCESS\n");
	}
	else {
		printf("FAILURE\n");
	}



	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
