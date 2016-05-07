/*---------------------------------------
* Brett Irvin
* 4/24/16
* CS362_400 Software Engineering II
* Assignment 4--randomtestcard.c
* Random tester for the Smithy card
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include "math.h"

#define NUM_TESTS 50

/*Smithy Card's requirements:
1. Current player should receive exactly 3 cards.
2. 3 cards should come from his own pile.
3. No state change should occur for other players.
4. No state change should occur to the victory card piles and kingdom card piles.
*/

int main() {
	int i, j;
	int deckCount, remCards, handCount, seed;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	int thisPlayer = 0;
	int numPlayers = 0;
	struct gameState G, testG;
	SelectStream(2);
	PutSeed(3);
	
    // Randomize game variables--always need at least 2 players, but can have 4 maximum
	for(i = 0; i < NUM_TESTS; i++){
		numPlayers = floor(Random() * (MAX_PLAYERS - 2)) + 2;
		// printf("Num players: %d\n", numPlayers);		
		seed = floor(Random() * 2000);
		//printf("Seed: %d \n", seed);
		
		initializeGame(numPlayers, k, seed, &G);	
		thisPlayer = floor(Random() * numPlayers);
		//printf("thisPlayer: %d \n", thisPlayer);
		G.whoseTurn = thisPlayer;	
		//printf("thisPlayer NOW: %d \n", thisPlayer);
		
		// Create a random hand 
		for( i = 0; i < numPlayers; i++){
			handCount = floor(Random() * MAX_HAND); 	// random size of hand
			//printf("hand count: %d\n", handCount);
			G.handCount[i] = handCount;					// assign to handCount	
			//printf("G.handCount[i] is %d\n", G.handCount[i]);
			for(j = 0; j < handCount; j++){ 			// handCount is set, iterate thru and assign randoms 
				G.hand[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		
		// Create a random deck
		for(i = 0; i < G.numPlayers; i++){				
			remCards = MAX_DECK - G.handCount[i]; 		// maximum possible cards left for deck
			deckCount = floor(Random() * remCards);		// random number of cards in deck 0 to remCards
			G.deckCount[i] = deckCount; 				// set deck size for player i
			for(j = 0; j < deckCount; j++){				//for each card in deck, select random card
				G.deck[i][j] = floor(Random() * (treasure_map + 1));
				//printf("deck: %i, %i\n", i, G.deck[i][j]);
			}
		}
		
	//Initialize a game with the smithy card in Player 1's hand
	gainCard(smithy, &G, 2, thisPlayer);
    memcpy(&testG, &G, sizeof(struct gameState));
	//cardEffect(smithy, 0, 0, 0, &testG, handPos, 0);
	playCard((G.handCount[thisPlayer] - 1), 0, 0, 0, &G);
	
	/*---------------------------------------------------------*/
	// Testing the Smithy card's effect on current player

	// Add 3 cards to current player's hand (since smithy is discarded, only 2 are actually added)
	printf("hand count = %d   expected = %d\n", testG.handCount[thisPlayer], G.deckCount[thisPlayer] - 2);
    if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + 2){ 
		printf("FAIL: hand count did not increase by 3.\n");
	}
	
	// Take 3 cards from current player's pile
	printf("deck count = %d   expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 3);
    if(G.deckCount[thisPlayer] - 3 != testG.deckCount[thisPlayer]){  
        printf("FAIL: deck count did not decrease by 3.\n");
	}
	
	// Current player's discard pile should be unaltered
	printf("discard count = %d   expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - 3);
    if(G.discardCount[thisPlayer] - 3 != testG.discardCount[thisPlayer]){  
        printf("FAIL: deck count did not decrease by 3.\n");
	}
	/*---------------------------------------------------------*/
	
	// Testing the Smithy card's effect on the other players
	
	// Checks whether player 1's Smithy card affected player 2's hand count, deck count, or discard count.
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

	//Testing the Smithy card's effect on Victory and Kingdom piles
	int arraySize = sizeof(G.supplyCount) / sizeof(int);
	int i = 0;
	for(i = 0; i < arraySize; i++){
		printf("supply count = %d, expected %d\n", testG.supplyCount[i], G.supplyCount[i]);
		if(testG.supplyCount[i] != G.supplyCount[i]){
			printf("FAIL: The supply of Victory and Kingdom cards was modified.\n");
		}
	}	
	printf("\n ---Smithy card's testing is complete--- \n\n");
	}
	return 0;
}
