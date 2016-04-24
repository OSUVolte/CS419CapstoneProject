/*
File: cardtest1.c
Author: Elliot Bates
Description: Unit test for the adventurer card function in dominion.c
*/

/*
int adventurerCard(int currentPlayer, struct gameState *state)
{
	int temphand[MAX_HAND];// moved above the if statement
	int drawntreasure=0;
	int cardDrawn;
	int z = 0;// this is the counter for the temp hand
	
      while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
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

	printf("Testing ADVENTURER card.\n");
	for (p = 0; p < numPlayers; p++) {
		printf("Testing for player %d.\n", p);
		//Create game state
		memset(&O, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayer, k, seed, &O); // initialize a new game
		memcpy(&G, &O, sizeof(struct gameState)) // Copy game state
		G.whoseTurn = p; //set players turn
		//play card
		cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
		
		//Check players hand has gained 2 cards
		if (G.handCount[p] == (O.handCount[p] + 2))
			printf("PASSED: New hand count = %d, expected = %d.\n", G.handCount[p], (O.handCount[p] + 2));
		else
			printf("FAILED: New hand count = %d, expected = %d.\n", G.handCount[p], (O.handCount[p] + 2));
		
		//Check 2 cards gained are treasure
		c1 = G.hand[p][G.handCount[p]-2]; // first added card
		c2 = G.hand[p][G.handCount[p]-1]; // second added card
		if (c1 == 4 || c1 == 5 || c1 == 6)
			printf("PASSED: First card added = %d, expected 4, 5, or 6.\n", c1);
		else
			printf("FAILED: First card added = %d, expected 4, 5, or 6.\n", c1);
		if (c2 == 4 || c2 == 5 || c2 == 6)
			printf("PASSED: Second card added = %d, expected 4, 5, or 6.\n", c2);
		else
			printf("FAILED: Second card added = %d, expected 4, 5, or 6.\n", c2);
	}
	return 0;
}