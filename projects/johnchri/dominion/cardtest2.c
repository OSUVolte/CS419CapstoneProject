#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//smithy
int testEffectSmithy(struct gameState *G){

	effectSmithy(G, 2);

	if (G->handCount[0] == 7){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testEffectSmithy(&G);

	return 0;
}