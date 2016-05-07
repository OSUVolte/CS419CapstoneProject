/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 4
* Filename: randomtestcard.c
* Description: Random test for the playSmithy card function
*
* Business Requirements:
* 1 - Current player draws three cards from their deck.
* 2 - No change to the other player's hand or deck.
* 3 - No change to the victory card piles and kingdom card piles.
* 4 - Discard smithy card after playing it.
**************************************************************************/	

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test_helpers.h"

int smithyTestOracle(int testNum, int currPlayer, int smithyPos, struct gameState G, struct gameState controlG);
int treasure[3] = {copper, silver, gold};


int main() {
	int failedTests = 0;
	int passedTest;
	int seed = 1000;
	int i, j, p, numPlayers, deckCount, discardCount, handCount, smithyPos;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    
    struct gameState G, controlG;

	int maxDeckCount = MAX_DECK;
	int maxHandCount = MAX_HAND;

	int numRandomTests = 10;
	int testNum;

	for (testNum = 0; testNum < numRandomTests; testNum++) {

		numPlayers = (rand() % 3) + 1;
		//numPlayers = 2;
		initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards

		p = rand() % numPlayers;
		G.whoseTurn = p;

		handCount = (rand() % maxHandCount) + 1;						// Create random hand
		G.handCount[p] = handCount;
		for (i = 0; i < handCount; i++) {
			
			j = rand() % 2;

			if (j == 0)
				G.hand[p][i] = k[rand() % 10];
			else
				G.hand[p][i] = treasure[rand() % 3];
		}
		smithyPos = rand() % handCount;								// randomy place a smithy
		G.hand[p][smithyPos] = smithy;

		deckCount = (rand() % maxDeckCount) + 1;					// Create random deck
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

		playSmithy(p, &G, smithyPos);							// call playSmithy w current player

		passedTest = smithyTestOracle(testNum, p, smithyPos, G, controlG);

		if (passedTest == 0) {
			failedTests++;
		}
	}
	printf(">>>>>>>> playSmithy random tests completed with %d / %d failed tests. <<<<<<<<<\n\n", failedTests, numRandomTests);
	return 0;
}

/****************************************************************************
* smithyTestOracle
* Description: Determines if smithy is acting correctly
* Parameters: two game states one that has changes and one that acts as the 
* control to determine how the game state has changed
*****************************************************************************/
int smithyTestOracle(int testNum, int currPlayer, int smithyPos, struct gameState G, struct gameState controlG) {
	int p, i;
	int testPassed  = 1;
	printf("Testing: playSmithy - Test Number: %d ---------------------------------\n", testNum + 1);
	printf("\tTest included %d cards in hand, %d deck cards and %d discard cards.\n", controlG.handCount[currPlayer], controlG.deckCount[currPlayer], controlG.discardCount[currPlayer]);
	
	// Check current player has three more cards 
	if(G.handCount[currPlayer] != controlG.handCount[currPlayer] + 3) {
		printf("\tCurrent Player = %d, Handcount = %d, Expected handCount = %d\n", currPlayer, G.handCount[currPlayer], controlG.handCount[currPlayer] + 3);
		testPassed = 0;
	}

	// Check the current players deck is -3
	if(G.deckCount[currPlayer] != controlG.deckCount[currPlayer] - 3) {
		printf("\tCurrent Player = %d, deckcount = %d, Expected deckCount = %d\n", currPlayer, G.deckCount[currPlayer], controlG.deckCount[currPlayer] - 3);
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