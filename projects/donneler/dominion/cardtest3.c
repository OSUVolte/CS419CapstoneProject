/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: cardtest3.c
* Description: Tests playEmbargo function
*
* Lines to include in makefile:
*
* Business Requirements:
* 1 - Current player get +2 coins.
* 2 - An embargo token gets added to the to supply pile. (When a player buys a card, he 
* 		gains a Curse card per Embargo token on that pile.)
* 3 - No change to any player's hand or deck.
* 4 - No change to the victory card piles and kingdom card piles.
* 5 - Check embargo card got discarded.
* 6 - Cant place embargo on a supply pile that is depleted.
**************************************************************************/		

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test_helpers.h"


char *TESTCARD = "playEmbargo()";

int main() {
	int seed = 1000;
	int numPlayers = 2;
	int i, p, handCount, r;
	int k[10] = {adventurer, embargo, feast, gardens, mine
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
		for (handCount = 1; handCount <= maxHandCount; handCount++) {
			
			// TEST 1 ******************************************************************************
			printf("TEST 1 *****************************************************************\n");
			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.handCount[p] = handCount;
			G.hand[p][handCount - 1] = embargo;
			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case

			playEmbargo(p, &G, handCount - 1, 0);			// call playEmbargo with current player

			// Check current player get +2 coins.
			if (G.coins != controlG.coins + 2) {
				printf("Coins = %d, Expected Coins = %d\n", G.coins, controlG.coins + 2);
			}

			// Check an embargo token gets added to the to supply pile.
			if (G.embargoTokens[0] != controlG.embargoTokens[0] + 1) {
				printf("Embargo tokens = %d, Expected = %d\n", G.embargoTokens[0], controlG.embargoTokens[0] + 1);
			}

			// Check no change to any other player's hand or deck.
			for (i = 0; i < numPlayers; i++) {
				checkDeck(i, G, controlG);		// check deck of all players

				if(i != p) {		// check hand of all others players
					checkHand(i, G, controlG);
				}
			}

			// Check no change to the victory card piles and kingdom card piles.
			checkSupply(G, controlG);

			// Check embargo card was discarded.
			if((G.hand[p][handCount - 1] == embargo) && (G.discardCount[p] == controlG.discardCount[p])) {
				printf("\tEmbargo was not discarded.\n");
			}

			// TEST 2 ******************************************************************************
			printf("TEST 2 *****************************************************************\n");
			// Check depeleted supply pile
			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.handCount[p] = handCount;
			G.hand[p][handCount - 1] = embargo;
			G.supplyCount[1] = 0;										//no supply left
			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case

			r = playEmbargo(p, &G, handCount - 1, 1);			// call playEmbargo with current player

			if (r == 0) {
				printf("playEmbargo returned successfully, but choosen supply Pile was empty.\n");
			}
			// Check current player get 0 coins.
			if (G.coins != controlG.coins) {
				printf("\tCoins = %d, Expected Coins = %d\n", G.coins, controlG.coins);
			}

			// Check no embargo token gets added to the to supply pile.
			if (G.embargoTokens[1] != controlG.embargoTokens[1]) {
				printf("\tEmbargo tokens = %d, Expected = %d\n", G.embargoTokens[1], controlG.embargoTokens[1]);
			}
	
		}
	}

	printf("\n >>>>>>>>>>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<<<<\n\n", TESTCARD);
	return 0;
}

