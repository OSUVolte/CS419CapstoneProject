/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: unittest3.c
* Description: Tests discardCard function
*
* Lines to include in makefile:
* unittest3: unittest3.c dominion.o rngs.o test_helpers.o
*	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o test_helpers.o $(CFLAGS)
*
* Business Requirements:
* 1 - Adds non-trashed card's to played pile
* 2 - Removes the discarded card from the player's hand
* 3 - Nothing in the other player's game state should change
* 4 - Current players's hand count is decremented
* 5 - Neither player's deck changes
* 6 - No change to the victory card piles and kingdom card piles
**************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "test_helpers.h"

char *TESTFXN = "discardCard()";

int main() {
	int p, i, handPos;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, controlG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int discardCount, handCount;

	int maxDeckCount = 50;
	int maxHandCount = 15;

	int silvers[maxDeckCount];
	int adventurers[maxHandCount];
	
	for (i = 0; i < maxHandCount; i++) {
		adventurers[i] = adventurer;
	}

	for (i = 0; i < maxDeckCount; i++) {
		silvers[i] = silver;
	}

	initializeGame(numPlayers, k, seed, &G);		// initialize a game state and player cards

	printf("----------------- Testing Function: %s ----------------\n", TESTFXN);

	for (p = 0; p < numPlayers; p++) {
		for (handCount = 0; handCount <= maxHandCount; handCount++) {
			for (discardCount = 0; discardCount <= maxDeckCount; discardCount++) {

// ********************* TEST 1 *************************************************************
				// Set up hand and discard pile
				G.handCount[p] = handCount;                 			// set cards on hand
				memcpy(G.hand[p], adventurers, sizeof(int) * handCount); 
				G.discardCount[p] = discardCount;					// set discarded
				memcpy(G.discard[p], silvers, sizeof(int) * discardCount);
				G.playedCardCount = 0;

				memcpy(&controlG, &G, sizeof(struct gameState));	// copy game state to test case
				
				handPos = 0;
				discardCard(handPos, p, &G, 0); 		// Discard of first card with trash flag

				if (handCount > 0) {
					assert(G.handCount[p] == controlG.handCount[p] - 1);	// check handcount decreased

					// played card count incremented
					//assert(G.playedCardCount == controlG.playedCardCount + 1); 
				}
				else {
					//assert(G.handCount[p] == controlG.handCount[p]);	// check handcount didnt dec
					if (G.handCount[p] != controlG.handCount[p] - 1) {
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
						printf("\tHandcount = %d, Expected = %d\n", G.handCount[p], controlG.handCount[p]);						
					}
				}

				if (G.handCount[p] < 0) {
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
						printf("\tInvalid Handcount = %d\n", G.handCount[p]);						
				}

				if (G.playedCardCount != controlG.playedCardCount + 1) {
					printf("*******************************************************************\n");
					printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
					printf("\tPlayed card count = %d, Expected = %d\n", G.playedCardCount, controlG.playedCardCount + 1);
				}
				
				
				for (i = 0; i < numPlayers; i++) {	// Check deck of all players
					checkDeck(i, G, controlG);		// check deck hasnt changed

					if(p != i) {
						checkHand(i, G, controlG);		//check deck of all other players
					}
				}

				checkSupply(G, controlG); 			// check supply hasnt changed
				



// ********************* TEST 2 *************************************************************
				// Set up hand and discard pile
				G.handCount[p] = handCount;                 			// set cards on hand
				memcpy(G.hand[p], adventurers, sizeof(int) * handCount); 
				G.discardCount[p] = discardCount;					// set discarded
				memcpy(G.discard[p], silvers, sizeof(int) * discardCount);

				memcpy(&controlG, &G, sizeof(struct gameState));	// copy game state to test case
		
				handPos = maxHandCount;
				discardCard(handPos, p, &G, 1); 					// Discard of first card with trash flag

				if (handPos < handCount) {
					if (handCount > 0) {
						assert(G.handCount[p] == controlG.handCount[p] - 1);	// check handcount decreased
					}
					else {
						//assert(G.handCount[p] == controlG.handCount[p]);	// check handcount didnt dec
						if (G.handCount[p] != controlG.handCount[p] - 1) {
							printf("*******************************************************************\n");
							printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
							printf("\tHandcount = %d, Expected = %d\n", G.handCount[p], controlG.handCount[p]);						
						}
					}

					if (G.handCount[p] < 0) {
							printf("*******************************************************************\n");
							printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
							printf("\tInvalid Handcount = %d\n", G.handCount[p]);						
					}

					if (G.playedCardCount != controlG.playedCardCount) {
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
						printf("\tPlayed card count = %d, Expected = %d\n", G.playedCardCount, controlG.playedCardCount);
					}

				}
				else {				//invalid card position 
					//assert(G.handCount[p] == controlG.handCount[p]);	//should not dec handCount
					if (G.handCount[p] != controlG.handCount[p]) {
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard. Asked for an invalid card removal.\n", p, handCount, discardCount);
						printf("\tHand count = %d, Expected = %d\n", G.handCount[p], controlG.handCount[p]);						
					}
				}

				
				
				for (i = 0; i < numPlayers; i++) {	// Check deck of all players
					checkDeck(i, G, controlG);		// check deck hasnt changed

					if(p != i) {
						checkHand(i, G, controlG);		//check deck of all other players
					}
				}

				checkSupply(G, controlG); 			// check supply hasnt changed

// ********************* TEST 3 *************************************************************
				// Set up hand and discard pile
				G.handCount[p] = handCount;                 			// set cards on hand
				memcpy(G.hand[p], adventurers, sizeof(int) * handCount); 
				G.discardCount[p] = discardCount;					// set discarded
				memcpy(G.discard[p], silvers, sizeof(int) * discardCount);

				memcpy(&controlG, &G, sizeof(struct gameState));	// copy game state to test case
		
				handPos = handCount / 2;
				discardCard(handPos, p, &G, 0); 		// Discard of a middle card with trash flag


				if (handCount > 0) {
					assert(G.handCount[p] == controlG.handCount[p] - 1);	// check handcount decreased
				}
				else {
					//assert(G.handCount[p] == controlG.handCount[p]);	// check handcount didnt dec
					if (G.handCount[p] != controlG.handCount[p] - 1) {
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
						printf("\tHandcount = %d, Expected = %d\n", G.handCount[p], controlG.handCount[p]);						
					}	
				}

				if (G.handCount[p] < 0) {
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
						printf("\tInvalid Handcount = %d\n", G.handCount[p]);						
				}

				if (G.playedCardCount != controlG.playedCardCount + 1) {
					printf("*******************************************************************\n");
					printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
					printf("\tPlayed card count = %d, Expected = %d\n", G.playedCardCount, controlG.playedCardCount + 1);
				}
				
				
				for (i = 0; i < numPlayers; i++) {	// Check deck of all players
					checkDeck(i, G, controlG);		// check deck hasnt changed

					if(p != i) {
						checkHand(i, G, controlG);		//check deck of all other players
					}
				}

				checkSupply(G, controlG); 			// check supply hasnt changed

// ********************* TEST 4 *************************************************************
				// Set up hand and discard pile
				G.handCount[p] = handCount;                 			// set cards on hand
				memcpy(G.hand[p], adventurers, sizeof(int) * handCount); 
				G.discardCount[p] = discardCount;					// set discarded
				memcpy(G.discard[p], silvers, sizeof(int) * discardCount);

				memcpy(&controlG, &G, sizeof(struct gameState));	// copy game state to test case
		
				handPos = handCount;
				discardCard(handPos, p, &G, 0); 		// Discard of last card without trash flag


				if (handCount >= 0) {
					assert(G.handCount[p] == controlG.handCount[p] - 1);	// check handcount decreased
				}
				else {
					//assert(G.handCount[p] == controlG.handCount[p]);	// check handcount didnt dec
					if (G.handCount[p] != controlG.handCount[p] - 1) {
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
						printf("\tHandcount = %d, Expected = %d\n", G.handCount[p], controlG.handCount[p]);						
					}	
				}

				if (G.handCount[p] < 0) {			// check hand count is non negative
						printf("*******************************************************************\n");
						printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
						printf("\tInvalid Handcount = %d\n", G.handCount[p]);						
				}
				
				if (G.playedCardCount != controlG.playedCardCount + 1) {
					printf("*******************************************************************\n");
					printf("Test player %d with %d card(s) in hand and %d cards in discard.\n", p, handCount, discardCount);
					printf("\tPlayed card count = %d, Expected = %d\n", G.playedCardCount, controlG.playedCardCount + 1);
				}
				
				
				for (i = 0; i < numPlayers; i++) {	// Check deck of all players
					checkDeck(i, G, controlG);		// check deck hasnt changed

					if(p != i) {
						checkHand(i, G, controlG);		//check deck of all other players
					}
				}

				checkSupply(G, controlG); 			// check supply hasnt changed

			}
		}
	}



	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFXN);
	return 0;
}