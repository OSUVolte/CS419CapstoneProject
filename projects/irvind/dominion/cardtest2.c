/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--cardtest2.c
* Tests the adventurer card
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

/* Citation for card requirements: http://wiki.dominionstrategy.com/index.php/Adventurer
Adventurer Card's requirements:
1. Current player should reveal cards from deck until 2 Treasure cards are shown.  
2. Those Treasure cards go in the player's hand, and the other revealed cards are discarded.
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
	int handCard1 = 0;
	int handCard2 = 0;
	int newCards = 0;
	struct gameState G, testG;

	// Initialize a game with the adventurer card in Player 1's hand
	initializeGame(numPlayers, k, seed, &G);
	gainCard(adventurer, &G, 2, 0);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf ("\n----------Testing the Adventurer card's basic requirements:----------\n");
	cardEffect(adventurer, 0, 0, 0, &G, G.handCount[0]-1, 0);
	
	// Verify that the discard pile incremented by at least 1
	printf("discard count = %d, expected %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+1);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] +1 ){
		printf("Failure: the discard pile did not increment by at least 1.\n\n");
	}
	
	// Two Treasure cards should go into the player's hand
	if(newCards >= 1){
		handCard1 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1];
		printf("This card should be a treasure card.\n");
		if(handCard1 == gold || handCard1 == silver || handCard1 == copper){
			printf("Success: Treasure card found.\n");
		}
		else{
			printf("Failure: Less than 2 Treasure cards found in current hand.\n");
		}
	}	
	
	if(newCards >= 1){
		handCard2 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 2];
		printf("This card should be a treasure card.\n");
		if(handCard2 == gold || handCard2 == silver || handCard2 == copper){
			printf("Success: Treasure card found.\n");
		}		
		else{
			printf("Failure: Less than 2 Treasure cards found in current hand.\n");
		}
	}
	/*---------------------------------------------------------*/
	
	printf ("----------Testing the Adventurer card's effect on Player 2:----------\n");
	
	// Checks whether player 1's Adventurer card affected player 2's hand count, deck count, or discard count.
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

	printf("----------Testing the Adventurer card's effect on Victory and Kingdom piles:----------\n");
	int arraySize = sizeof(G.supplyCount) / sizeof(int);
	int i = 0;
	for(i = 0; i < arraySize; i++){
		printf("supply count = %d, expected %d\n", testG.supplyCount[i], G.supplyCount[i]);
		if(testG.supplyCount[i] != G.supplyCount[i]){
			printf("Failure: The supply of Victory and Kingdom cards was modified.");
		}
	}	
	printf("\n ---Adventurer card's testing is complete--- \n\n");
	return 0;
}
