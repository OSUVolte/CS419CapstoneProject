/* randomtestadventurer.c - a random tester for the Village card
	By Dave Martinez, martind2@oregonstate.edu
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

#define TEST_AMT 50

int main() {
	// Counters
	int i, j;

	// Reporting
	int test_results[3] = {0, 0, 0},
		tests_passed = 0,
		tests_failed = 0;

	printf("RANDOM TEST: Village card\n");
	printf("Test attempts: %d\n\n", TEST_AMT);
	printf("--- BEGIN TEST OUTPUT ---\n");

	for (i=0; i<TEST_AMT; i++) {
		sleep(1);
		struct gameState G, testG;
		int p;
		
		// Random
		PlantSeeds(-1);
		SelectStream(0);
		
		// Random bytes
		for (j=0; j<sizeof(struct gameState); j++) {
			((char*)&G)[j] = floor(Random()*256);
		}

		// Preconditions
		p = floor(Random() * 2);
		G.whoseTurn = p;
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.playedCardCount = floor(Random() * MAX_DECK);
		G.numActions = floor(Random() * 1000);
		G.discardCount[p] = 0;
		G.handCount[p] = floor(Random() * (G.deckCount[p] - 10));
		for (j=0; j<G.handCount[p]; j++) {
			G.hand[p][j] = floor(Random() * treasure_map);
		}
		for (j=0; j<G.deckCount[p]; j++) {
			G.deck[p][j] = floor(Random() * treasure_map);
		}

		// Add adventurer to player's hand
		G.hand[p][ G.handCount[p] ] = village;
		G.handCount[p]++;

		memcpy(&testG, &G, sizeof(struct gameState));
		playVillage(&G, (G.handCount[p]-1));

		// Test 1: increase hand size by one?
		if (G.handCount[p] != testG.handCount[p] + 1) {
			test_results[0] += 1;
			tests_failed += 1;
			printf("TEST 1 FAILED (%d): PLayer %d hand count = %d, expecting %d\n",
				i+1, p, G.handCount[p], testG.handCount[p] + 2);
		} else {
			tests_passed += 1;
		}

		// Test 2: player has two additional actions?
		if (G.numActions != testG.numActions + 2) {
			test_results[1] += 1;
			tests_failed += 1;
			printf("TEST 2 FAILED (%d): Player %d actions = %d, expecting %d\n",
				i+1, p, G.numActions, testG.numActions + 2);
		} else {
			tests_passed += 1;
		}
	}


	printf("--- END TEST OUTPUT ---\n\n");
	
	printf("TEST RESULTS:\n");
	printf("Tests passed: %d\n", tests_passed);
	printf("Tests failed: %d\n", tests_failed);
	printf("Which tests failed how many times?\n");
	for (i=0; i<2; i++) {
		printf("Test %d: %d\n", i+1, test_results[i]);
	}

	printf("\n--- END VILLAGE RANDOM TESTER ---\n\n");

	return 0;
}