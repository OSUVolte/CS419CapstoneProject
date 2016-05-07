#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testDiscardCard(struct gameState *G){

	int prevCount;
	int discarded = G->hand[0][0];

	prevCount = G->handCount[0];
	discardCard(0, 0, G, 0); //handpos, current player
	if(prevCount == G->handCount[0] + 1){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}

	if(G->playedCardCount == 1){
		printf("SUCCESS! Played card count.\n");
	}else{
		printf("FAIL! Incorrect played card count.\n");
	}

	if(G->playedCards[G->playedCardCount - 1] == discarded){
		printf("SUCCESS! Played card was added.\n");
	}else{
		printf("FAIL! Incorrect played card.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testDiscardCard(&G);

	return 0;
}