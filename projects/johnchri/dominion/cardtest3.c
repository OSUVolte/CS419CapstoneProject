#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testEffectCouncilRoom(struct gameState *G){

	int prev = G->hand[0][2];
	effectCouncilRoom(G, 2);

	if (G->handCount[0] == 8){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}

	if (G->discard[0][G->discardCount[0] - 1] == prev){
		printf("SUCCESS! Correct card discarded.\n");
	}else{
		printf("FAIL! Incorrect card discarded.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 7, &G);

	testEffectCouncilRoom(&G);

	return 0;
}