/*---------------------------------------
* Brett Irvin
* 4/24/16
* CS362_400 Software Engineering II
* Assignment 4--randomtestadventurer.c
* Random tester for the Adventurer card
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

#define NUM_TESTS 50

/* Citation for card requirements: http://wiki.dominionstrategy.com/index.php/Adventurer
Adventurer Card's requirements:
1. Current player should reveal cards from deck until 2 Treasure cards are shown.  
2. Those Treasure cards go in the player's hand, and the other revealed cards are discarded.
3. No state change should occur for other players.
4. No state change should occur to the victory card piles and kingdom card piles.
*/

int main () {
	int i, j;
	int deckCount, handCount, remCards, seed;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	int thisPlayer = 0;
	int numPlayers = 0;
	struct gameState G, testG;
	SelectStream(1);
	PutSeed(3);
	
	
	// Randomize game variables--always need at least 2 players, but can have 4 maximum
	for(i = 0; i < NUM_TESTS; i++){
		numPlayers = 2 + floor(Random() * (MAX_PLAYERS - 1));
		//printf("Num players: %d\n", numPlayers);
		seed = floor(Random() * 2000);
		//printf("Seed: %d \n", seed);
		
		initializeGame(numPlayers, k, seed, &G);	
		thisPlayer = floor(Random() * numPlayers);	
		//printf("thisPlayer: %d \n", thisPlayer);
		G.whoseTurn = thisPlayer;	
		//printf("thisPlayer NOW: %d \n", thisPlayer);

		// Create a random hand
		for(i = 0; i < G.numPlayers; i++){
			handCount = floor(Random() * MAX_HAND / 2);	// random size of hand
			//printf("hand count: %d\n", handCount);			
			G.handCount[i] = handCount;					// assign to handCount
			//printf("G.handCount[i] is %d\n", G.handCount[i]);
				for (i = 0; i < handCount; i++){		// handCount is set, iterate thru and assign randoms 
					G.hand[thisPlayer][i] = floor(Random() * (treasure_map + 1));
					//printf("G.hand[thisPlayer][i] = %d\n", G.hand[thisPlayer][i]);
				}										
		}
		
		// Create a random deck	
		for(i = 0; i < G.numPlayers; i++){
			remCards = MAX_DECK - G.handCount[i]; 		// maximum possible cards left for deck
			deckCount = floor(Random() * remCards);		// random number of cards in deck 0 to remCards
			G.deckCount[i] = deckCount; 				//set deck size for player i
				for(j = 0; j < deckCount; j++){ 		//for each card in deck, select random card
					G.deck[i][j] = floor(Random() * (treasure_map + 1));
					//printf("deck: %i, %i\n", i, G.deck[i][j]);
				}
		}
				
		// Initialize a game with the adventurer card in Player 1's hand
		gainCard(adventurer, &G, 2, thisPlayer);
		memcpy(&testG, &G, sizeof(struct gameState));
		playCard((G.handCount[thisPlayer] - 1), 0, 0, 0, &G);
		
		/*---------------------------------------------------------*/
		// Testing the Adventurer card's effect on current player
	
		// Add 2 cards to current player's deck (since adventurer is discarded, only 1 is actually added)
		if(testG.handCount[thisPlayer] + 1 != G.handCount[thisPlayer]){
			printf("FAIL: Player 1's hand count did not increase by 1. Count = %d   expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
		}
		
		// Make sure the top 2 cards in the current player's hand are both Treasure cards.
		if(G.hand[thisPlayer][G.handCount[thisPlayer] - 1] != copper && G.hand[thisPlayer][G.handCount[thisPlayer] - 1] != silver && G.hand[thisPlayer][G.handCount[thisPlayer] - 1] != gold){
			printf("FAIL: First card in player 1's hand was not a Treasure card.\n");
		}
		if(G.hand[thisPlayer][G.handCount[thisPlayer] - 2] != copper && G.hand[thisPlayer][G.handCount[thisPlayer] - 2] != silver && G.hand[thisPlayer][G.handCount[thisPlayer] - 2] != gold){
			printf("FAIL: Second card in player 1's hand was not a Treasure card.\n");
		}
		
		// Verify that the two Treasure cards were drawn from the deck.
		if(testG.deckCount[thisPlayer] - 2 != G.deckCount[thisPlayer]){
			printf("FAIL: Player 1's deck count did not decrease by 2. Count = %d   expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
		}
		/*---------------------------------------------------------*/
	
		// Testing the Adventurer card's effect on the other players
		
		// Checks whether player 1's Adventurer card affected the other players' hand count, deck count, or discard count.
		for(i = 0; i < G.numPlayers; i++){
			if(i != thisPlayer){
				if(testG.handCount[i] != G.handCount[i]){
					printf("FAIL: Hand count mismatch for player %d. Count = %d   expected = %d\n", i, testG.handCount[i], G.handCount[i]);
				}
				if(testG.deckCount[i] != G.deckCount[i]){
					printf("FAIL: Deck count mismatch for player %d. Count = %d   expected = %d\n", i, testG.deckCount[i], G.deckCount[i]);
				}
				if(testG.discardCount[i] != G.discardCount[i]){
					printf("FAIL: Discard count mismatch for player %d. Count = %d   expected = %d\n", i, testG.discardCount[i], G.discardCount[i]);
				}
			}
		}
		/*---------------------------------------------------------*/
		
		// Testing the Adventurer card's effect on Victory and Kingdom piles
		int arraySize = sizeof(G.supplyCount) / sizeof(int);
		for(i = 0; i < arraySize; i++){
			if(testG.supplyCount[i] != G.supplyCount[i]){
				printf("FAIL: Supply cards were altered. Supply count = %d   expected = %d\n", testG.supplyCount[i], G.supplyCount[i]);
			}
		}
	printf("\n ---Adventurer card's testing is complete--- \n\n");	
	}
	return 0;
}




