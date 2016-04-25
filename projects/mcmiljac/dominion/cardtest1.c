//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testPlayAdventurer(int handpos, struct gameState *post){
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));
	int currentPlayer = whoseTurn(post);
	int r;  
	r = playAdventurer(post);
	
	if (r != 0)
		printf("r != 0\n");
	if  (pre.numActions - 1 != post->numActions)
		printf ("pre.numActions - 1 != post->numActions\n");
	if (pre.handCount[currentPlayer] + 1 != post->handCount[currentPlayer])
		printf("pre.handCount[currentPlayer] + 1 != post->handCount[currentPlayer]\n");
	if (pre.playedCardCount + 1 != post->playedCardCount)
		printf("pre.playedCardCount + 1 != post->playedCardCount\n");
	if (post->playedCards[post->playedCardCount - 1] != adventurer)
		printf("post->playedCards[post->playedCardCount - 1] != adventurer\n");	

	//Check that the 2 most recently drawn cards in hand are treasure cards 
	if (post->hand[currentPlayer][post->handCount[currentPlayer] - 2] != copper
		 && post->hand[currentPlayer][post->handCount[currentPlayer] - 2] != silver
		 && post->hand[currentPlayer][post->handCount[currentPlayer] - 2] != gold)
		 printf("post->hand[currentPlayer][post->handCount[currentPlayer] - 2] not treasure card\n");
	
	if (post->hand[currentPlayer][post->handCount[currentPlayer] - 1] != copper
		 && post->hand[currentPlayer][post->handCount[currentPlayer] - 1] != silver
		 && post->hand[currentPlayer][post->handCount[currentPlayer] - 1] != gold)
		printf("post->hand[currentPlayer][post->handCount[currentPlayer] - 1] not treasure card\n");
}

int main () {
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};

	struct gameState G;
	  
	printf ("Testing playAdventurer()\n"); 

	
	memset(&G, 23, sizeof(struct gameState)); 
	initializeGame(2, k, 1, &G);
	G.hand[0][0] = adventurer;
	testPlayAdventurer(0, &G);
	
	printf("Done\n\n");
	return 0;
}
