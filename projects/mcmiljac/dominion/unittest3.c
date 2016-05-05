//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//added card for [whoseTurn] current player:
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand
  
void testGainCard(int supplyPos, struct gameState *post, int toFlag, int player){
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));
	int r;  
	r = gainCard(supplyPos, post, toFlag, player);

	// Check that gainCard() returns 0 as expected.
	if (r != 0)
		printf("r != 0\n");
	
	// Check that correct count has increased by 1 as determined by toFlag
	if (toFlag == 0){
		if (pre.discardCount[player] + 1 != post->discardCount[player])
			printf("pre.discardCount[currentPlayer] + 1 != post->discardCount[currentPlayer]\n");
	} else if (toFlag == 1){
		if (pre.deckCount[player] + 1 != post->deckCount[player])
			printf("pre.deckCount[currentPlayer] + 1 != post->deckCount[currentPlayer]\n");
	} else {
		if (pre.handCount[player] + 1 != post->handCount[player])
			printf("pre.handCount[currentPlayer] + 1 != post->handCount[currentPlayer]\n");
	}
	
	// Check that supply of gained card has decreased by 1
	if (pre.supplyCount[supplyPos] - 1 != post->supplyCount[supplyPos])
		printf("pre.supplyCount[supplyPos] - 1 != post->supplyCount[supplyPos]\n");
}

int main () {
	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};
	struct gameState G;
	printf ("Testing gainCard()\n"); 
	
	//Test gaining cards with supply positions 0-9 to discard pile of player 0
	for (i = 0; i < 10; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(2, k, 1, &G);
		testGainCard(i, &G, 0, 0);
	}
	
	//Test gaining cards with supply positions 0-9 to deck of player 1
	for (i = 0; i < 10; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(3, k, 1, &G);
		testGainCard(i, &G, 1, 1);
	}
	
	//Test gaining cards with supply positions 0-9 to hand of player 2
	for (i = 0; i < 10; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(4, k, 1, &G);
		testGainCard(i, &G, 2, 2);
	}
	
	printf("Done\n\n");
	return 0;
}