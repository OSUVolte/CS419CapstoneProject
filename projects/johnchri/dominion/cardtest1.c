#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testEffectAdventurer(struct gameState *G){

	effectAdventurer(G);
	if(G->handCount[0] == 6){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}

	if(G->discardCount[0] != 0){
		printf("SUCCESS! Discards increased.\n");
	}else{
		printf("FAIL! Incorrect coins.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testEffectAdventurer(&G);

	return 0;
}