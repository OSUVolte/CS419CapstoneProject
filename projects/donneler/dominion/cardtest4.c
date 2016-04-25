/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: cardtest4.c
* Description: Tests playCutpurse function
*
* Lines to include in makefile:
*
* Business Requirements:
* 1 - Current player gets +2 coins.
* 2 - Each other player loses a copper or reveals a hand w no copper.
* 3 - No change to any players deck.
* 4 - No change to the victory card piles and kingdom card piles.
* 5 - Current players hand doesnt change besides discarding the cutpurse.
**************************************************************************/		

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test_helpers.h"


char *TESTCARD = "playCutpurse()";

int main() {
	int seed = 1000;
	int numPlayers = 2;
	int i, p, handCount;
	int k[10] = {adventurer, cutpurse, feast, gardens, mine
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
			// Other players have no copper
			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.handCount[p] = handCount;
			G.hand[p][handCount - 1] = cutpurse;
			updateCoins(p, &G, 0);
			
			// Fill other players hand w adventurers
			for (i = 0; i < numPlayers; i++) {
				if (i != p) {
					G.handCount[i] = handCount;
					memcpy(G.hand[i], adventurers, sizeof(int) * handCount); 
				}
			}

			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case

			playCutpurse(p, &G, handCount - 1);			// call playCutpurse with current player

			// 1 - Current player gets +2 coins.
			if (G.coins != controlG.coins + 2) {
				printf("\tCoins = %d, Expected Coins = %d\n", G.coins, controlG.coins + 2);
			}
			
			// No change to any players deck.
			for (i = 0; i < numPlayers; i++) {
				checkDeck(i, G, controlG);		// check none of deck changed

				if (p != i) {		// check hands of other players didnt change since no copper
					checkHand(i, G, controlG);
				}
			}

			// No change to the victory card piles and kingdom card piles.
			checkSupply(G, controlG);

			// Current players hand doesnt change besides discarding the cutpurse.
			if((G.hand[p][handCount - 1] == cutpurse) && (G.discardCount[p] == controlG.discardCount[p])) {
				printf("\tCutpurse was not discarded.\n");
			}


			// TEST 2 ******************************************************************************
			printf("TEST 2 *****************************************************************\n");
			// Other players have copper
			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.handCount[p] = handCount;
			G.hand[p][handCount - 1] = cutpurse;
			updateCoins(p, &G, 0);
			
			// Fill other players hand w adventurers
			for (i = 0; i < numPlayers; i++) {
				if (i != p) {
					G.handCount[i] = handCount;
					memcpy(G.hand[i], coppers, sizeof(int) * handCount); 
				}
			}

			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case

			playCutpurse(p, &G, handCount - 1);			// call playCutpurse with current player

			// Check other players have lost a copper
			for (i = 0; i < numPlayers; i++) {
				if (i != p) {
					if(G.handCount[i] != controlG.handCount[i] - 1) {
						printf("\tPlayer %d handcount = %d, Expected handCount = %d\n", i, G.handCount[i],controlG.handCount[i] - 1);
					}
				}
			}		
		}
	}

	printf("\n >>>>>>>>>>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<<<<\n\n", TESTCARD);
	return 0;
}

