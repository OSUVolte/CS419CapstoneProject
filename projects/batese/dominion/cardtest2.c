/*
File: cardtest1.c
Author: Elliot Bates
Description: Unit test for the smithy card function in dominion.c
*/

/*
int smithyCard(int currentPlayer, struct gameState *state, int handPos)
{
	int i = 0;
      //+3 Cards
      for (i = 0; i > 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i, r, p; 					 				
	int c1, c2;								// cards
	int pos;
	int seed = 1000;
	int numPlayers = 2;  					// players for valid gamestate
	struct gameState O;						// original gameState
	struct gameState G;						// test gameState
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int handPos;
	int maxHandPos = 4;

	printf("Testing SMITHY card.\n");
	for (p = 0; p < numPlayers; p++) {
		for (handPos = 0; handPos < maxHandPos; handPos++) {
			printf("Testing for player %d and handPos %d.\n", p, handPos);
			//Create game state
			memset(&O, 23, sizeof(struct gameState));   // clear the game state
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayers, k, seed, &O); // initialize a new game
			memcpy(&G, &O, sizeof(struct gameState)); // Copy game state
			G.whoseTurn = p; //set players turn
			//play card
			cardEffect(smithy, 0, 0, 0, &G, handPos, 0);
			
			//Check players hand has gained 2 cards
			if (G.handCount[p] == (O.handCount[p] + 2))
				printf("PASSED: New hand count = %d, expected = %d.\n", G.handCount[p], (O.handCount[p] + 2));
			else
				printf("FAILED: New hand count = %d, expected = %d.\n", G.handCount[p], (O.handCount[p] + 2));
			
			//check player has discarded 1 card
			if (G.discardCount[p] == (O.discardCount[p] + 1))
				printf("PASSED: New discard count = %d, expected = %d.\n", G.discardCount[p], (O.discardCount[p] + 1));
			else
				printf("FAILED: New discard count = %d, expected = %d.\n", G.discardCount[p], (O.discardCount[p] + 1));
		}
	}
	return 0;
}