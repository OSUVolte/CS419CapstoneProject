#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

#define NUM_TESTS 50


int main() {
	int i, j;
	int deckCount, handCount, remCards, seed;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	int thisPlayer = 0;
	int numPlayers = 0;
	struct gameState G, testG;
	SelectStream(1);
	PutSeed(73);
	

	for(i = 0; i < NUM_TESTS; i++){
		numPlayers = floor(Random() * (MAX_PLAYERS - 2)) + 2; 
		seed = floor(Random() * 2000);
		initializeGame(numPlayers, k, seed, &G);	
		thisPlayer = floor(Random() * numPlayers);	
		G.whoseTurn = thisPlayer;	
		

		for( i = 0; i < numPlayers; i++){
			handCount = floor(Random() * MAX_HAND); 
			G.handCount[i] = handCount;			
			for(j = 0; j < handCount; j++){ 
				G.hand[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		

		for(i = 0; i < G.numPlayers; i++){
			remCards = MAX_DECK - G.handCount[i]; 
			deckCount = floor(Random() * remCards);	
			G.deckCount[i] = deckCount; 
			for(j = 0; j < deckCount; j++){
				G.deck[i][j] = floor(Random() * (treasure_map + 1));
			}
		}
		

		gainCard(adventurer, &G, 2, thisPlayer);
		memcpy(&testG, &G, sizeof(struct gameState));
		playCard((G.handCount[thisPlayer] - 1), 0, 0, 0, &G);

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

		
		//printf("\n----------Testing the Adventurer card's effect on Victory and Kingdom piles:----------\n");
		int arraySize = sizeof(G.supplyCount) / sizeof(int);
		for(i = 0; i < arraySize; i++){
			if(testG.supplyCount[i] != G.supplyCount[i]){
				printf("FAIL: Supply cards were altered. Supply count = %d   expected = %d\n", testG.supplyCount[i], G.supplyCount[i]);
			}
		}
	}
	printf("\n ---Adventurer card's testing is complete--- \n\n");
	return 0;
}




