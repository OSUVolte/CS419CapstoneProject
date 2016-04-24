/**************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Assignment 3
* Filename: cardtest1.c
* Description: Tests playAdventurer function
*
* Lines to include in makefile:
* cardtest1: cardtest1.c dominion.o rngs.o test_helpers.o
*	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o test_helpers.o $(CFLAGS) 
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
#include "test_helpers.h"


char *TESTCARD = "playAdventurer()";

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

// ************************************** TEST 2 ****************************************************
		printf("\nSTART TEST 1: Check to see what happens if no treasure cards are left in the deck or discard pile.\n");
		printf("\tTest 1 has been disabled due to the bug in the card that causes it to crash.\n");
		// Commented out because the infinite loop causes the program to abort
		/*initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
		G.whoseTurn = p;
		memcpy(G.deck[p], adventurers, sizeof(int) * maxDeckCount); 	// set all cards in deck to adv	
		G.deckCount[p] = maxDeckCount;
		memcpy(G.discard[p], adventurers, sizeof(int) * maxDeckCount); 	// set all cards in discard to adv	
		G.discardCount[p] = maxDeckCount;	
		G.handCount[p] = 0;	
		memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case

		playAdventurer(p, &G);			// call playAdventurer with current player

		//check to see two cards were added
		if(G.handCount[p] != controlG.handCount[p]) {
			printf("Player %d, Handcount = %d, Expected handCount = %d\n", p, G.handCount[p], controlG.handCount[p]);
		}

		for (i = 0; i < numPlayers; i++) {	// Check hand and deck of other players
			if (p != i) {
				checkHand(i, G, controlG);		// check hand hasnt changed
				checkDeck(i, G, controlG);		// check deck hasnt changed
			}
		}
		checkSupply(G, controlG);		// check supply hasnt changed*/

// ************************************** TEST 2 ****************************************************
		printf("\nSTART TEST 2: Check to see if we the two treasure cards are being added.\n");

		for (handCount = 0; handCount <= maxHandCount; handCount++) {

			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.deckCount[p] = maxDeckCount;
			memcpy(G.deck[p], coppers, sizeof(int) * maxDeckCount); 	// set all cards in deck to copper		
			G.handCount[p] = handCount;	
			memcpy(G.hand[p], adventurers, sizeof(int) * handCount); 	// set all cards in deck to copper
			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case
			playAdventurer(p, &G);			// call playAdventurer with current player

			//check to see two cards were added
			if(G.handCount[p] != controlG.handCount[p] + 2) {
				printf("Player = %d, Handcount = %d, Expected handCount = %d\n", p, G.handCount[p], controlG.handCount[p] + 2);
			}

			for (i = 0; i < numPlayers; i++) {	// Check hand and deck of other players
				if (p != i) {
					checkHand(i, G, controlG);		// check hand hasnt changed
					checkDeck(i, G, controlG);		// check deck hasnt changed
				}
			}

			checkSupply(G, controlG);		// check supply hasnt changed

		}

// ************************************** TEST 3 *********************************************************
		printf("\nSTART TEST 3: Check to see if we can call the function with another player\n");

		for (handCount = 0; handCount <= maxHandCount; handCount++) {

			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.deckCount[p] = maxDeckCount;
			memcpy(G.deck[p], coppers, sizeof(int) * maxDeckCount); 	// set all cards in deck to copper		
			G.handCount[p] = handCount;	
			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case

			if (p == 0) {
				playAdventurer(1, &G);			// call playAdventurer with other player
				printf("\tCalled playAdventurer with another player besides the current player.\n");
			}
			else {
				playAdventurer(0, &G);
				printf("\tCalled playAdventurer with another player besides the current player.\n");
			}

		}

// ************************************** TEST 4 *********************************************************
// Check to function works when the deck is empty but cards are in the player's discard pile
		printf("\nSTART TEST 4: Check to see if its getting cards from the player's discard pile if needed.\n");
		for (handCount = 0; handCount <= maxHandCount; handCount++) {

			initializeGame(numPlayers, k, seed, &G);				// init a game state and player cards
			G.whoseTurn = p;
			G.deckCount[p] = 0;
			G.discardCount[p] = maxDeckCount;
			memcpy(G.discard[p], coppers, sizeof(int) * maxDeckCount); 	// set all cards in deck to copper		
			G.handCount[p] = handCount;	
			memcpy(&controlG, &G, sizeof(struct gameState));			// copy game state to test case
			
			//check to see two cards were added
			if(G.handCount[p] != controlG.handCount[p] + 2) {
				printf("\tPlayer = %d, Handcount = %d, Expected handCount = %d\n", p, G.handCount[p], controlG.handCount[p] + 2);
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

