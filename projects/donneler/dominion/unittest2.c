/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: unittest2.c
* Description: Tests drawCard function
*
* Lines to include in makefile:
* unittest2: unittest2.c dominion.o rngs.o test_helpers.o
*	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o test_helpers.o $(CFLAGS) 
*
* Business Requirements:
* 1 - Replace empty deck with shuffled discarded cards from the player.
* 2 - Adds one card to current player's hand from the top of their deck.
* 3 - Other player's hand and deck are not changed.
* 4 - No change to the victory card piels and kingdom card piles
**************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test_helpers.h"

char *TESTFXN = "drawCard()";

int main() {
	int i, p, handCount, deckCount;
	int seed = 1000;

	int numPlayers = 2;

	struct gameState G, controlG;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	int coppers[MAX_HAND];		// arrays of all coppers, silvers, and golds
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	int adventurers[MAX_HAND];
	
	for (i = 0; i < MAX_HAND; i++) {
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
		adventurers[i] = adventurer;
	}

	printf("----------------- Testing Function: %s ----------------\n", TESTFXN);

	for (p = 0; p < numPlayers; p++) {
		for (handCount = 0; handCount <= MAX_HAND; handCount++) {
			for (deckCount = 0; deckCount <= MAX_DECK; deckCount++) {			

				initializeGame(numPlayers, k, seed, &G);			// init a game state and player cards
				G.handCount[p] = handCount;                 			// set cards on hand
				memcpy(G.hand[p], adventurers, sizeof(int) * handCount); 
				G.deckCount[p] = deckCount;									// set deck 
				memcpy(G.deck[p], golds, sizeof(int) * deckCount); 	
				G.discardCount[p] = MAX_DECK - deckCount;					// set discarded
				memcpy(G.discard[p], silvers, sizeof(int) * (MAX_DECK - deckCount)); 

				memcpy(&controlG, &G, sizeof(struct gameState));	// copy game state to test case

				drawCard(p, &G);					// call the drawCard function

				if (controlG.deckCount[p] == 0) {	// check empty deck was replenished
					assert(G.deckCount[p] > 0);
				}
				else { 			// if deck had cards, it should have dereased the deck count
					assert(G.deckCount[p] == controlG.deckCount[p] - 1);
				}

				assert(G.handCount[p] == controlG.handCount[p] + 1);	//assert we have one more card

				checkSupply(G, controlG); 			// check supply hasnt changed

				for (i = 0; i < numPlayers; i++) {	// Check hand and deck of all other players
					if (i != p) {
						checkDeck(i, G, controlG);
						checkHand(i, G, controlG);
					}
				}


			}

		}
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFXN);
	return 0;
}