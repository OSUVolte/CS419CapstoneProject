/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--cardtest1.c
* Tests the smithy card
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

/*Smithy Card's requirements:
1. Current player should receive exactly 3 cards.
2. 3 cards should come from his own pile.
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
	

	// Initialize a game with the smithy card in Player 1's hand
	initializeGame(numPlayers, k, seed, &G);
	gainCard(smithy, &G, 2, 0);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------Testing the Smithy card's basic requirements:----------\n");
	cardEffect(smithy, 0, 0, 0, &G, G.handCount[0]-1, 0);
	
	// Add 3 cards to current player's hand
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 3);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + 3){
		printf("Failure: did not add three cards to player 1's current hand.\n\n");
	}
	
	// Take 3 cards from current player's pile
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] + 3);
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] + 3){
		printf("Failure: did not reduce player 1's deck count by 3.\n\n");
	}
	
	/*---------------------------------------------------------*/
	
	printf ("----------Testing the Smithy card's effect on Player 2:----------\n");
	
	// Checks whether player 1's Smithy card affected player 2's hand count, deck count, or discard count.
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
	
	printf("----------Testing the Smithy card's effect on Victory and Kingdom piles:----------\n");
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
