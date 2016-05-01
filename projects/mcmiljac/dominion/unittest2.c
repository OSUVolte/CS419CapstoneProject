//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testDiscardCard(int handPos, struct gameState *post, int trashFlag){
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));
	int currentPlayer = whoseTurn(post);
	int r;  
	r = discardCard(handPos, currentPlayer, post, trashFlag);

	// Check that discardCard() returns 0 as expected.
	if (r != 0)
		printf("r != 0\n");
	// Check that hand count has decreased by 1
	if (pre.handCount[currentPlayer] - 1 != post->handCount[currentPlayer])
		printf("pre.handCount[currentPlayer] + 2 != post->handCount[currentPlayer]\n");
	
	// Check replacement of discarded card with last card in hand
	if (pre.hand[currentPlayer][pre.handCount[currentPlayer] - 1] == post->hand[currentPlayer][handPos])
		printf("pre.hand[currentPlayer][pre.handcount[currentPlayer] - 1] == post->hand[currentPlayer][handPos]\n");
	
	// If card not trashed, check that card was played and is on top of the played card pile
	if (trashFlag == 0){
		if (pre.playedCardCount + 1 != post->playedCardCount)
			printf("pre.playedCardCount + 1 != post->playedCardCount\n");
		if (post->playedCards[post->playedCardCount - 1] != pre.hand[currentPlayer][handPos])
			printf("post->playedCards[post->playedCardCount - 1] != pre.hand[currentplayer][handPos]\n");
	} 
	
}

int main () {
	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};

	struct gameState G;
	  
	printf ("Testing discardCard()\n"); 
	
	//test discarding from various positions in hand
	for (i = 0; i < 5; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(2, k, 1, &G);
		testDiscardCard (0, &G, 0);
	}
	
	//test trashing cards from various positions in hand
	for (i = 0; i < 5; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(2, k, 1, &G);
		testDiscardCard (0, &G, 1);
	}
	
	printf("Done\n\n");
	return 0;
}