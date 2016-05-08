/* randomtestadventurer.c - a random tester for the Adventurer card
	By Dave Martinez, martind2@oregonstate.edu
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define TEST_AMT 50

int main() {
	// Counters
	int i, j;

	// Reporting
	int test_results[3] = {0, 0, 0},
		tests_passed = 0,
		tests_failed = 0;

	printf("RANDOM TEST: Adventurer card\n");
	printf("Test attempts: %d\n\n", TEST_AMT);
	printf("--- BEGIN TEST OUTPUT ---\n");

	for (i=0; i<TEST_AMT; i++) {

		sleep(1);
		struct gameState G, testG;
		int p, treasure1, treasure2, card1, card2;
		
		// Random
		PlantSeeds(-1);
		SelectStream(0);
		
		// Random bytes
		for (j=0; j<sizeof(struct gameState); j++) {
			((char*)&G)[j] = floor(Random()*256);
		}

		// Preconditions:
		// - Player has adventurer
		// - There are at least two treasure cards in the deck
		p = floor(Random() * 2);
		G.whoseTurn = p;
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = 0;
		G.handCount[p] = floor(Random() * (G.deckCount[p] - 10));

		// Add random cards to p's deck
		for (j=0; j<G.deckCount[p]; j++) {
			G.deck[p][j] = floor(Random() * treasure_map);
		}


		// Add two trasures to p's deck
		card1 = floor(Random() * G.deckCount[p]);
		card2 = card1;
		while (card1 == card2) {
			card2 = floor(Random() * G.deckCount[p]);
		}
		treasure1 = floor(Random() * 2);
		treasure2 = floor(Random() * 2);
		if (treasure1 == 0) {
			G.deck[p][card1] = copper;
		} else if (treasure1 == 1) {
			G.deck[p][card1] = silver;
		} else if (treasure1 == 2) {
			G.deck[p][card1] = gold;
		}
		if (treasure2 == 0) {
			G.deck[p][card2] = copper;
		} else if (treasure2 == 1) {
			G.deck[p][card2] = silver;
		} else if (treasure2 == 2) {
			G.deck[p][card2] = gold;
		}

		// Add adventurer to player's hand
		G.hand[p][ G.handCount[p] ] = adventurer;
		G.handCount[p]++;

		memcpy(&testG, &G, sizeof(struct gameState));
		playAdventurer(&G);

		// Tests
		// Test 1: Hand size increases by 2
		if (G.handCount[p] != testG.handCount[p] + 2) {
			test_results[0] += 1;
			tests_failed += 1;
			printf("TEST 1 FAILED (%d): Player %d hand count = %d, expecting %d\n", 
				i+1, p, G.handCount[p], testG.handCount[p] + 2);
		} else {
			tests_passed += 1;
		}

		// Test 2: Are the last two cards in player's hand treasures?
		if ((G.hand[p][G.handCount[p] - 1] != copper 
    	&& G.hand[p][G.handCount[p] - 1] != silver 
    	&& G.hand[p][G.handCount[p] - 1] != gold) || 
    	(G.hand[p][G.handCount[p] - 2] != copper 
    	&& G.hand[p][G.handCount[p] - 2] != silver 
    	&& G.hand[p][G.handCount[p] - 2] != gold)) {
			test_results[1] += 1;
			tests_failed += 1;
			printf("TEST 2 FAILED (%d): Player %d last two cards are not treasures, they are: %d %d", 
				i+1, p, G.hand[p][G.handCount[p]-1], G.hand[p][G.handCount[p]-2]);
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
		printf("Test %d: %d\n", i, test_results[i]);
	}

	printf("\n--- END ADVENTURER RANDOM TESTER ---\n\n");

	return 0;
}