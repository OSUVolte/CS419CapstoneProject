//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testUpdateCoins(struct gameState *post, int bonus){
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));
	int currentPlayer = whoseTurn(post);
	int r;
	
	// Add 1 of each treasure card to player's hand
	post->handCount[currentPlayer] += 3;
	post->hand[currentPlayer][post->handCount[currentPlayer] - 1] = copper;
	post->hand[currentPlayer][post->handCount[currentPlayer] - 2] = silver;
	post->hand[currentPlayer][post->handCount[currentPlayer] - 3] = gold;
	  
	// Perform updateCoins() on post gamestate with passed in bonus value
	r = updateCoins(currentPlayer, post, bonus);
	
	// Check that updateCoins() returns 0 as expected.
	if (r != 0)
		printf("r != 0\n");
	
	// Check that updated coin total in post matches the amount in pre + 1 + 2 + 3 + bonus
	if (pre.coins + 6 + bonus != post->coins)
		printf("pre.coins + 6 + bonus != post->coins\n");
	
}

int main () {
	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};
	struct gameState G;
	  
	printf ("Testing updateCoins()\n"); 
	
	//Test updating coins with bonus values 0-4
	for (i = 0; i < 5; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(2, k, 1, &G);
		testUpdateCoins(&G,i);
	}
	printf("Done\n\n");
	return 0;
}