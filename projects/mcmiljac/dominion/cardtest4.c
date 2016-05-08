//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 3
// 24 April 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testPlayCouncil_Room(int handpos, struct gameState *post){
	struct gameState pre;
	memcpy (&pre, post, sizeof(struct gameState));
	int currentPlayer = whoseTurn(post);
	int i, r;  
	r = playCouncil_Room(post, handpos);

	if (r != 0)
		printf("r != 0\n");
	
	//Check number of actions decreases by 1
	if  (pre.numActions - 1 != post->numActions) 
		printf ("pre.numActions - 1 != post->numActions\n");
	
	//Check number of buys increases by 1
	if (pre.numBuys + 1 != post->numBuys)
		printf ("pre.numBuys + 1 != post->numBuys\n");
	
	if (pre.handCount[currentPlayer] + 3 != post->handCount[currentPlayer]) 
		printf("pre.handCount[currentPlayer] + 3 != post->handCount[currentPlayer]\n");
	if (pre.playedCardCount + 1 != post->playedCardCount)
		printf("pre.playedCardCount + 1 != post->playedCardCount\n");
	if (post->playedCards[post->playedCardCount - 1] != council_room)
		printf("post->playedCards[post->playedCardCount - 1] != council_room\n");
	
	//Check that the player's deck count decreases by 4
	if (pre.deckCount[currentPlayer] >= 4){
		if (pre.deckCount[currentPlayer] - 4 != post->deckCount[currentPlayer])
			printf("pre.deckCount[currentPlayer] - 4 != post->deckCount[currentPlayer]\n");
	} else {
		if (pre.deckCount[currentPlayer] + pre.discardCount[currentPlayer] - 4 != post->deckCount[currentPlayer])
			printf("pre.deckCount[currentPlayer] + pre.discardCount[currentPlayer] - 4 != post->deckCount[currentPlayer]\n");
	}
	
	// Check that handsize of every other player increases by 1 and deck size decreases by 1.
	for (i = 0; i < pre.numPlayers; i++){
		if (i != currentPlayer) {
			if (pre.handCount[i] + 1 != post->handCount[i])
				printf("pre.handCount[i] + 1 != post->handCount[i]");
			if (pre.deckCount[i] >= 1){
				if (pre.deckCount[i] - 1 != post->deckCount[i])
					printf("pre.deckCount[i] - 1 != post->deckCount[i]\n");
			}
				
			else {
				if (pre.deckCount[i] + pre.discardCount[i] - 1 != post->deckCount[i])
					printf("pre.deckCount[i] + pre.discardCount[i] - 1 != post->deckCount[i]\n");
			}
		}
			
	}
	
}

int main () {
	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};
	struct gameState G;
	  
	printf ("Testing playCouncil_Room()\n"); 

	for (i = 0; i < 5; i++){
		memset(&G, 23, sizeof(struct gameState)); 
		initializeGame(2, k, 1, &G);
		G.hand[0][i] = council_room;
		testPlayCouncil_Room(i, &G);
	}
	
	memset(&G, 23, sizeof(struct gameState)); 
	initializeGame(2, k, 1, &G);
		
	for (i = 0; i < 5; i++){
		G.discard[0][G.discardCount[0]] = copper;
		G.discardCount[0]++;
	}
			
	for (i = 0; i < 4; i++)
		drawCard(0,&G);
	G.hand[0][0] = council_room;
	testPlayCouncil_Room(0, &G);
	
	printf("Done\n\n");
	return 0;
}