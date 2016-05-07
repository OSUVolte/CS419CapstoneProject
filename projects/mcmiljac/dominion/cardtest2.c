//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testPlaySmithy(int handpos, struct gameState *post){
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));
	int currentPlayer = whoseTurn(post);
	int r;  
	r = playSmithy(post, handpos);

	if (r != 0)
		printf("r != 0\n");
	if  (pre.numActions - 1 != post->numActions)
		printf ("pre.numActions - 1 != post->numActions\n");
	if (pre.handCount[currentPlayer] + 2 != post->handCount[currentPlayer])
		printf("pre.handCount[currentPlayer] + 2 != post->handCount[currentPlayer]\n");
	if (pre.playedCardCount + 1 != post->playedCardCount)
		printf("pre.playedCardCount + 1 != post->playedCardCount\n");
	if (post->playedCards[post->playedCardCount - 1] != smithy)
		printf("post->playedCards[post->playedCardCount - 1] != smithy\n");
	
	if (pre.deckCount[currentPlayer] >= 3){
		if (pre.deckCount[currentPlayer] - 3 != post->deckCount[currentPlayer])
			printf("pre.deckCount[currentPlayer] - 3 != post->deckCount[currentPlayer]\n");
	} else {
		if (pre.deckCount[currentPlayer] + pre.discardCount[currentPlayer] - 3 != post->deckCount[currentPlayer])
			printf("pre.deckCount[currentPlayer] + pre.discardCount[currentPlayer] - 3 != post->deckCount[currentPlayer]\n");
	}
}

int main () {
	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};

	struct gameState G;
	  
	printf ("Testing playSmithy()\n"); 

	for (i = 0; i < 5; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(2, k, 1, &G);
		G.hand[0][i] = smithy;
		testPlaySmithy(i, &G);
	}
	
	memset(&G, 23, sizeof(struct gameState)); 
	initializeGame(2, k, 1, &G);
		
	for (i = 0; i < 5; i++){
		G.discard[0][G.discardCount[0]] = copper;
		G.discardCount[0]++;
	}
			
	for (i = 0; i < 4; i++)
		drawCard(0,&G);
	G.hand[0][0] = smithy;
	testPlaySmithy(0, &G);
	printf("Done\n\n");
	return 0;
}