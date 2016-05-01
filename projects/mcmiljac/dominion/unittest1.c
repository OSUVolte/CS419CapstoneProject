//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testHandCard(struct gameState *state){
	int i;
	
	// For each position in hand, check that the handCard function returns the correct card.
	for (i = 0; i < state->handCount[state->whoseTurn]; i++){	
		if (state->hand[state->whoseTurn][i] != handCard(i,state))
			printf("state->hand[0][i] != handCard(i,state)");
	}
}

int main () {
	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};

	struct gameState G;
	  
	printf ("Testing handCard()\n"); 

	memset(&G, 23, sizeof(struct gameState)); 
	initializeGame(4, k, 1, &G);
	
	// Test handCard() for players 0-3
	for (i = 0; i < 4; i++){
		G.whoseTurn = i;
		// Set hand to contain variety of cards.
		G.hand[i][0] = copper;
		G.hand[i][1] = adventurer;
		G.hand[i][2] = smithy;
		G.hand[i][3] = village;
		G.hand[i][4] = estate;
		testHandCard(&G);
	}
	printf("Done\n\n");
	return 0;
}