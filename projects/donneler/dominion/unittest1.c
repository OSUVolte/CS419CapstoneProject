/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: unittest1.c
* Description: Tests updateCoins function
*
* Lines to include in makefile:
* unittest1: unittest1.c dominion.o rngs.o test_helpers.o
*	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o test_helpers.o $(CFLAGS) 
*
* Business Requirements:
* 1 - Only update coins in the game state, nothing else should change
* 2 - Coins only come from treasures in player's current hand or bonus pts
* 3 - Adds 1 coin for each copper, 2 for each silver, 3 for each gold
* 4 - no change to the victory card piels and kingdom card piles
**************************************************************************/		

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test_helpers.h"



char *TESTFXN = "updateCoins()";

int main() {
	int seed = 1000;
	int numPlayers = 2;
	int maxBonus = 10;
	int i, p, handCount, bonus;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, controlG;
    int maxHandCount = MAX_HAND;
    
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
		for (handCount = 0; handCount <= maxHandCount; handCount++) {
			for (bonus = 0; bonus <= maxBonus; bonus++) {

				initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
				G.handCount[p] = handCount;                 			// set no of cards on hand

// ************************************** TEST 1 ****************************************************			
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 	// set all cards to copper
				memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case
				updateCoins(p, &G, bonus);

				assert(G.coins == handCount * 1 + bonus); 		// check num coins for copper/bonus is correct
				
				for (i = 0; i < numPlayers; i++) {	// Check hand and deck of all players
					checkHand(i, G, controlG);		// check hand hasnt changed
					checkDeck(i, G, controlG);		// check deck hasnt changed
				}

				checkSupply(G, controlG);		// check supply hasnt changed

// ************************************** TEST 2 ****************************************************	
				memcpy(G.hand[p], silvers, sizeof(int) * handCount); 	// set all cards to silver
				memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case
				updateCoins(p, &G, bonus);				

				assert(G.coins == handCount * 2 + bonus);		// check num coins for silver/bonus is correct
				
				for (i = 0; i < numPlayers; i++) {	// Check hand and deck of all players
					checkHand(i, G, controlG);		// check hand hasnt changed
					checkDeck(i, G, controlG);		// check deck hasnt changed
				}

				checkSupply(G, controlG);		// check supply hasnt changed

// ************************************** TEST 3 ****************************************************	
				memcpy(G.hand[p], golds, sizeof(int) * handCount); 		// set all cards to gold
				memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case
				updateCoins(p, &G, bonus);			

				assert(G.coins == handCount * 3 + bonus);		// check num coins for gold/bonus is correct
				
				for (i = 0; i < numPlayers; i++) {	// Check hand and deck of all players
					checkHand(i, G, controlG);		// check hand hasnt changed
					checkDeck(i, G, controlG);		// check deck hasnt changed
				}

				checkSupply(G, controlG);		// check supply hasnt changed

// ************************************** TEST 4 ****************************************************	
				memcpy(G.hand[p], adventurers, sizeof(int) * handCount); 		// set all cards to gold
				memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case
				updateCoins(p, &G, bonus);			

				assert(G.coins == bonus);		// check num coins for no treasures/bonus is correct
				
				for (i = 0; i < numPlayers; i++) {	// Check hand and deck of all players
					checkHand(i, G, controlG);		// check hand hasnt changed
					checkDeck(i, G, controlG);		// check deck hasnt changed
				}

				checkSupply(G, controlG);		// check supply hasnt changed
			}
		}
	}

	printf("\n >>>>>>>>>>>>>> SUCCESS: Testing complete %s <<<<<<<<<<<<<<\n\n", TESTFXN);
	return 0;
}

