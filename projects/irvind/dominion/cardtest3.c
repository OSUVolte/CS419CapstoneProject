/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--cardtest3.c
* Tests the village card
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

/* Citation for card requirements: http://wiki.dominionstrategy.com/index.php/Village
Village Card's requirements:
1. Current player should receive exactly 1 card from the deck.
2. Actions should be increased by exactly 2.
3. No state change should occur for other players.
4. No state change should occur to the victory card piles and kingdom card piles.
*/

int main () {
	int seed = 1000;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numPlayers = 2;
	int thisPlayer = 0;
	int secPlayer = 1;
	struct gameState G, testG;
	SelectStream(2);
	PutSeed(3);
	

	// Initialize a game with the village card in Player 1's hand
	initializeGame(numPlayers, k, seed, &G);
	gainCard(village, &G, 2, 0);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------Testing the Village card's basic requirements:----------\n");
	cardEffect(village, 0, 0, 0, &G, G.handCount[0]-1, 0);
	
	// Add 1 card to current player's hand (draw from the deck)
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]+1);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer]+1) {
		printf("Failure: did not add 1 card to current player's hand.\n\n");
	}
	
	// Decrement the deck by 1
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]-1);
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer]-1){
		printf("Failure: did not decrement the current player's deck by 1.\n\n");
	}
	
	// Actions should be increased by 2
	printf("action count = %d, expected = %d\n", testG.numActions, G.numActions+2);
	if(testG.numActions != G.numActions+2){
		printf("Failure: actions did not increase by 2.\n\n");
	}
	
	/*---------------------------------------------------------*/
	
	printf ("----------Testing the Village card's effect on Player 2:----------\n");
	// Checks whether player 1's Village card affected player 2's hand count, deck count, or discard count.
	printf("hand count = %d, expected %d\n", testG.handCount[secPlayer], G.handCount[secPlayer]);
	if(testG.handCount[secPlayer] != G.handCount[secPlayer]){
		printf("Failure: Player 2's hand count was modified.\n\n");
	}
	
	printf("deck count = %d, expected %d\n", testG.deckCount[secPlayer], G.deckCount[secPlayer]);
	if(testG.deckCount[secPlayer] != G.deckCount[secPlayer]){
		printf("Failure: Player 2's deck count was modified.\n\n");
	}
	
	printf("discard count = %d, expected %d\n\n", testG.discardCount[secPlayer], G.discardCount[secPlayer]);
	if(testG.discardCount[secPlayer] != G.discardCount[secPlayer]){
		printf("Failure: Player 2's deck count was modified.\n\n");
	}

	/*---------------------------------------------------------*/
	
	printf("----------Testing the Village card's effect on Victory and Kingdom piles:----------\n");
	int arraySize = sizeof(G.supplyCount) / sizeof(int);
	int i = 0;
	for(i = 0; i < arraySize; i++){
		printf("supply count = %d, expected %d\n", testG.supplyCount[i], G.supplyCount[i]);
		if(testG.supplyCount[i] != G.supplyCount[i]){
			printf("Failure: The supply of Victory and Kingdom cards was modified.\n");
		}
	}	
	printf("\n ---Village card's testing is complete--- \n\n");
	return 0;
}
