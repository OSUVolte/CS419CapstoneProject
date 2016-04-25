/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: cardtest2.c
* Description: Tests playSmithy function
*
* Lines to include in makefile:
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


char *TESTCARD = "playSmithy()";

int main() {
	int seed = 1000;
	int numPlayers = 2;
	int i, p, handCount;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, controlG;

	int maxDeckCount = 100;
	int maxHandCount = 15;
    
	int coppers[maxDeckCount];		// arrays of all coppers, silvers, and golds
	int adventurers[maxDeckCount];

	for (i = 0; i < maxDeckCount; i++) {
		coppers[i] = copper;
		adventurers[i] = adventurer;
	}

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	for (p = 0; p < numPlayers; p++) {
		for (handCount = 0; handCount <= maxHandCount; handCount++) {

			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.handCount[p] = handCount;
			G.hand[p][handCount - 1] = smithy;
			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case

			playSmithy(p, &G, handCount - 1);			// call playSmithy with current player

			//check to see three cards were added
			if(G.handCount[p] != controlG.handCount[p] + 3) {
				printf("\tPlayer = %d, Handcount = %d, Expected handCount = %d\n", p, G.handCount[p], controlG.handCount[p] + 3);
			}

			//Check to see if smithy has been discarded
			if((G.hand[p][handCount - 1] == smithy) && (G.discardCount[p] == controlG.discardCount[p])) {
				printf("\tSmithy was not been discarded.\n");
			}

			for (i = 0; i < numPlayers; i++) {	// Check hand and deck of other players
				if (p != i) {
					checkHand(i, G, controlG);		// check hand hasnt changed
					checkDeck(i, G, controlG);		// check deck hasnt changed
				}
			}

			checkSupply(G, controlG);		// check supply hasnt changed

		}


	}

	printf("\n >>>>>>>>>>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<<<<\n\n", TESTCARD);
	return 0;
}

