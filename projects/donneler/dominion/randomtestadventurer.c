/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 4
* Filename: randomtestadventurer.c
* Description: A random test that tests the playAdventurer card function
*
* Business Requirements:
* 1 - Add two treasure cards to current players hand from their deck
* 2 - Other revealed cards are put into player's discard pile
* 3 - If the players deck is empty, you can shuffle the discard pile and
* 		replenish the deck once.
* 4 - No change to the other player's hand or deck.
* 5 - No change to the victory card piles and kingdom card piles.
**************************************************************************/	

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int adventurerTestOracle(int testNum, int currPlayer, struct gameState G, struct gameState controlG);
int treasure[3] = {copper, silver, gold};

int main() {
	int failedTests = 0;
	int passedTest;
	int seed = 1000;
	int i, j, p, numPlayers, deckCount, discardCount;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    
    struct gameState G, controlG;

	int maxDeckCount = MAX_DECK;

	int numRandomTests = 100;
	int testNum;

	for (testNum = 0; testNum < numRandomTests; testNum++) {

		numPlayers = (rand() % 3) + 1;
		//numPlayers = 2;
		initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards

		p = rand() % numPlayers;
		G.whoseTurn = p;

		deckCount = (rand() % maxDeckCount) + 1;						// Create random deck
		G.deckCount[p] = deckCount;
		for (i = 0; i < deckCount; i++) {
			
			j = rand() % 2;

			if (j == 0)
				G.deck[p][i] = k[rand() % 10];
			else
				G.deck[p][i] = treasure[rand() % 3];

		}

		discardCount = (rand() % maxDeckCount) + 1;					// Create random discard pile
		G.discardCount[p] = discardCount;
		for (i = 0; i < discardCount; i++) {
			
			j = rand() % 2;

			if (j == 0)
				G.discard[p][i] = k[rand() % 10];
			else
				G.discard[p][i] = treasure[rand() % 3];
		}

		memcpy(&controlG, &G, sizeof(struct gameState));		// copy game state to test case

		playAdventurer(p, &G);									// call playAdventurer w current player

		passedTest = adventurerTestOracle(testNum, p, G, controlG);

		if (passedTest == 0) {
			failedTests++;
		}
	}
	printf(">>>>>>>> playAdventurer random tests completed with %d / %d failed tests. <<<<<<<<<\n\n", failedTests, numRandomTests);
	return 0;
}

/****************************************************************************
* adventurerTestOracle
* Description: Determines if adventurer is acting correctly
* Parameters: two game states one that has changes and one that acts as the 
* control to determine how the game state has changed
*****************************************************************************/
int adventurerTestOracle(int testNum, int currPlayer, struct gameState G, struct gameState controlG) {
	int p, i;
	int testPassed  = 1;
	printf("Testing: playAdventurer - Test Number: %d ---------------------------------\n", testNum + 1);
	printf("\tTest included %d deck cards and %d discard cards.\n", controlG.deckCount[currPlayer], controlG.discardCount[currPlayer]);
	// Check current player has two more cards 
	if(G.handCount[currPlayer] != controlG.handCount[currPlayer] + 2) {
		printf("\tCurrent Player = %d, Handcount = %d, Expected handCount = %d\n", currPlayer, G.handCount[currPlayer], controlG.handCount[currPlayer] + 2);
		testPassed = 0;
	}

	// Check player has two more treasures
	int newTreasureCount = 0;
	int oldTreasureCount = 0;
	for (i = 0; i < G.handCount[currPlayer]; i++) {
		if ((G.hand[currPlayer][i] == treasure[0])
			|| (G.hand[currPlayer][i] == treasure[1])
			|| (G.hand[currPlayer][i] == treasure[2])
			) {
			newTreasureCount++;
		}
	}
	for (i = 0; i < controlG.handCount[currPlayer]; i++) {
		if ((controlG.hand[currPlayer][i] == treasure[0])
			|| (controlG.hand[currPlayer][i] == treasure[1])
			|| (controlG.hand[currPlayer][i] == treasure[2])
			) {
			oldTreasureCount++;
		}
	}
	if (newTreasureCount != oldTreasureCount+ 2) {
		printf("\tPlayer %d has %d treasures, expected %d treasures.\n", currPlayer, newTreasureCount, oldTreasureCount + 2);
		testPassed = 0;
	}

	// Check other players hand and deck have not changed
	for (p = 0; p < controlG.numPlayers; p++) {
		if (p != currPlayer) {
			if (G.handCount[p] != controlG.handCount[p]) {
				printf("\tOther Player = %d, Handcount = %d, Expected handCount = %d\n", p, G.handCount[p], controlG.handCount[p]);
				testPassed = 0;
			}

			for (i = 0; i < G.handCount[p]; i++) {
				if (G.hand[p][i] != controlG.hand[p][i]) {
					printf("\tOther player = %d, card %d in their hand has changed when it shouldn't have.\n", p, i);
					testPassed = 0;
				}
			}

			if (G.deckCount[p] != controlG.deckCount[p]) {
				printf("\tOther Player = %d, Deckcount = %d, Expected deckCount = %d\n", p, G.deckCount[p], controlG.deckCount[p]);
				testPassed = 0;
			}	

			for (i = 0; i < G.deckCount[p]; i++) {
				if (G.deck[p][i] != controlG.deck[p][i]) {
					printf("\tOther player = %d, card %d in their deck has changed when it shouldn't have.\n", p, i);
					testPassed = 0;
				}
			}		
		}
	}

	// Check supply had changed
	if ((G.supplyCount[copper] != controlG.supplyCount[copper])
		|| (G.supplyCount[silver] != controlG.supplyCount[silver])
		|| (G.supplyCount[gold] != controlG.supplyCount[gold])	
		|| (G.supplyCount[estate] != controlG.supplyCount[estate])
		|| (G.supplyCount[duchy] != controlG.supplyCount[duchy])
		|| (G.supplyCount[province] != controlG.supplyCount[province])
		) {
		printf("Supply levels have changed, when they are expected to stay the same.\n");
		testPassed = 0;
	}

	if (testPassed == 1) {
		printf("\tTest %d: PASSED\n\n", testNum + 1);
		return 1;
	}
	else {
		printf("\tTest %d : FAILED\n\n", testNum + 1);
		return 0;
	}
}