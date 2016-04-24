/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: unittest4.c
* Description: Tests endTurn function
*
* Lines to include in makefile:
* unittest4: unittest4.c dominion.o rngs.o test_helpers.o
*	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o test_helpers.o $(CFLAGS) 
*
* Business Requirements:
* 1 - Current player's entire hand is discarded to their discard pile
* 2 - The next player becomes the current player
* 3 - The next player gets 1 action and get one buy.
* 4 - The next player gets 5 cards from their deck + their coins are updated.
* 5 - No change to the victory card piles and kingdom card piles.
**************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test_helpers.h"

char *TESTFXN = "endTurn()";

int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, controlG;
	int p, nextP, i, coinCount;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);		// initialize a game state and player cards

	printf("----------------- Testing Function: %s ----------------\n", TESTFXN);


	for (p = 0; p < numPlayers; p++) {
		G.whoseTurn = p;									// set current player

		memcpy(&controlG, &G, sizeof(struct gameState));	// copy game state to test case

		endTurn(&G);					// call endTurn

		//Figure out whose up next
		assert(G.whoseTurn != controlG.whoseTurn);
		if (p < numPlayers - 1) {
			nextP = controlG.whoseTurn + 1;
		}
		else {
			nextP = 0;	
		}
		
		assert(G.whoseTurn != controlG.whoseTurn);
		assert(G.handCount[p] == 0);		// assert last players hand is now empty
		assert(G.whoseTurn == nextP);		// assert correct next player
		assert(G.numActions == 1); 			// assert one action for next player
		assert(G.numBuys == 1);				// assert num of buys for next player
		assert(G.handCount[nextP] == 5);		// assert 5 cards drawn for next player
		
		// check players coins are updated
		coinCount = 0;
		for (i = 0; i < 5; i++) {
			if (G.hand[nextP][i] == copper) {
				coinCount += 1;
			}
			else if (G.hand[nextP][i] == silver) {
				coinCount += 2;
			}
			if (G.hand[nextP][i] == gold) {
				coinCount += 3;
			}
		}
		assert(G.coins == coinCount);

		// check no changes to victory or kingdom piles
		checkSupply(G, controlG); 			// check supply hasnt changed		
	}


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFXN);
	return 0;
}