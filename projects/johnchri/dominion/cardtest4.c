#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testEffectFeast(struct gameState *G){

	effectFeast(G, 10);

	if (G->handCount[0] == 5){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}

	if (G->discard[0][G->discardCount[0] - 1] == 10){
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

	initializeGame(2, k, 9, &G);

	testEffectFeast(&G);

	return 0;
}