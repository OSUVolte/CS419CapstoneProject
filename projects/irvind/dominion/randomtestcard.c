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
#include "rngs.h"
#include "math.h"

#define NUM_TESTS 1000

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
	int secPlayer = 1;
	int numPlayers = 0;
	struct gameState G, testG;
	SelectStream(2);
	PutSeed(3);
	
    // Randomize game variables
	for(i = 0; i < NUM_TESTS; i++){
		numPlayers = floor(Random() * (MAX_PLAYERS - 2)) + 2; 
		seed = floor(Random() * 2000);
		initializeGame(numPlayers, k, seed, &G);	
		thisPlayer = floor(Random() * numPlayers);	
		G.whoseTurn = thisPlayer;	
		
		// Create a random hand 
		for( i = 0; i < numPlayers; i++){
			handCount = floor(Random() * MAX_HAND); 
			G.handCount[i] = handCount;			
			for(j = 0; j < handCount; j++){ 
				G.hand[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		
		// Create a random deck
		for(i = 0; i < G.numPlayers; i++){
			remCards = MAX_DECK - G.handCount[i]; 
			deckCount = floor(Random() * remCards);	
			G.deckCount[i] = deckCount; 
			for(j = 0; j < deckCount; j++){
				G.deck[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		
	//Initialize a game with the smithy card in Player 1's hand
	gainCard(smithy, &G, 2, thisPlayer);
    memcpy(&testG, &G, sizeof(struct gameState));
	//cardEffect(smithy, 0, 0, 0, &testG, handPos, 0);
	playCard((G.handCount[thisPlayer] - 1), 0, 0, 0, &G);
	
	printf ("----------Testing the Smithy card's effect on current player----------\n");

	// Add 3 cards to current player's hand (since smithy is discarded, only 2 are actually added)
	printf("hand count = %d   expected = %d\n", testG.handCount[thisPlayer], G.deckCount[thisPlayer] - 2);
    if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + 2){ 
		printf("Failure: hand count did not increase by 3.\n");
	}
	
	// Take 3 cards from current player's pile
	printf("deck count = %d   expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 3);
    if(G.deckCount[thisPlayer] - 3 != testG.deckCount[thisPlayer]){  
        printf("Failure: deck count did not decrease by 3.\n");
	}
	
	// Current player's discard pile should be unaltered
	printf("discard count = %d   expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - 3);
    if(G.discardCount[thisPlayer] - 3 != testG.discardCount[thisPlayer]){  
        printf("Failure: deck count did not decrease by 3.\n");
	}
	/*---------------------------------------------------------*/
	
	printf ("\n----------Testing the Smithy card's effect on player 2:----------\n");
	
	// Checks whether player 1's Smithy card affected player 2's hand count, deck count, or discard count.
    printf("hand count = %d   expected = %d\n", testG.handCount[secPlayer], G.handCount[secPlayer]);
	if(testG.handCount[secPlayer] != G.handCount[secPlayer]){
		printf("Failure: player 1's smithy card affected player 2's hand count.\n");
	}

    printf("deck count = %d   expected = %d\n", testG.deckCount[secPlayer], G.deckCount[secPlayer]);
	if(testG.deckCount[secPlayer] != G.deckCount[secPlayer]){
		printf("Failure: player 1's smithy card affected player 2's deck count.\n");
    }
	
	printf("discard count = %d   expected = %d\n", testG.discardCount[secPlayer], G.discardCount[secPlayer]);
	if(testG.discardCount[secPlayer] != G.discardCount[secPlayer]){
		printf("Failure: player 1's smithy card affected player 2's discard count.\n");
    }
	/*---------------------------------------------------------*/

	printf("\n----------Testing the Smithy card's effect on Victory and Kingdom piles:----------\n");
	int arraySize = sizeof(G.supplyCount) / sizeof(int);
	int i = 0;
	for(i = 0; i < arraySize; i++){
		printf("supply count = %d, expected %d\n", testG.supplyCount[i], G.supplyCount[i]);
		if(testG.supplyCount[i] != G.supplyCount[i]){
			printf("Failure: The supply of Victory and Kingdom cards was modified.\n");
		}
	}
	
	printf("\n ---Smithy card's testing is complete--- \n\n");
	return 0;
	}
}
