//// Jake McMillen; mcmiljac@oregonstate.edu
// CS 362 - Assignment 4
// 8 May 2016

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
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
	srand(time(NULL));
	int i,j,n, numPlayers, randomSeed, drawCount, handPosition, supplyPosition;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};

	struct gameState G;
	  
	printf ("Testing playSmithy()\n"); 

	// Randomize game state
	// # of players, # cards in hand, # cards in deck, # cards in discard, cards in deck
	
	for (i = 0; i < 1000; i++){
		memset(&G, 23, sizeof(struct gameState));
		// Select random number of players between 2 and 4 inclusive
		numPlayers = (rand() % 3) + 2;
		printf("numPlayers: %d\n",numPlayers);
		// Select random seed for initializeGame() function
		randomSeed = 1 + rand() % 10;
		initializeGame(numPlayers, k, randomSeed, &G);
		
		for (j = 0; j < numPlayers; j++){
			
			// Each player gains a random number (1-10) of randomly chosen cards to their deck.
			drawCount = 1 + rand() % 10;
			for (n = 0; n < drawCount; n++){
				supplyPosition = 1+ rand() % 14;
				gainCard(supplyPosition, &G, 1, j);	
			}
			
			//Shuffle decks
			shuffle(j,&G);
			
			// Each player draws a random number of cards
			drawCount = 1 + rand() % 8;
			for (n = 0; n < drawCount; n++)
				drawCard(j, &G);
			
			// A random number of cards are added to each player's discard pile
			drawCount = rand() % 8;
			for (n = 0; n < drawCount; n++){
				supplyPosition = 1+ rand() % 14;
				gainCard(supplyPosition, &G, 0, j);	
			}
		}
		// Choose random player to have next turn.
		G.whoseTurn = rand() % numPlayers;
		updateCoins(G.whoseTurn, &G, 0);
		
		// Display info on game state
		printf("G.whoseTurn: %d\n",G.whoseTurn);
		printf("Handcount0: %d\n",G.handCount[0]);
		printf("Deckcount0: %d\n",G.deckCount[0]);
		printf("Discardcount0: %d\n",G.discardCount[0]);
		printf("Handcount1: %d\n",G.handCount[1]);
		printf("Deckcount1: %d\n",G.deckCount[1]);
		printf("Discardcount1: %d\n",G.discardCount[1]);
		printf("Handcount2: %d\n",G.handCount[2]);
		printf("Deckcount2: %d\n",G.deckCount[2]);
		printf("Discardcount2: %d\n",G.discardCount[2]);
		printf("Handcount3: %d\n",G.handCount[3]);
		printf("Deckcount3: %d\n",G.deckCount[3]);
		printf("Discardcount3: %d\n",G.discardCount[3]);
		
		// Chose a random position in current player's hand and add Smithy card there. 
		handPosition = rand() % G.handCount[G.whoseTurn];
		printf("handPosition: %d\n",handPosition);
		
		// Call testPlaySmithy function with current game state
		G.hand[G.whoseTurn][handPosition] = smithy;
		testPlaySmithy(handPosition, &G);
	}
	
	printf("Done\n\n");
	return 0;
}