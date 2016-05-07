#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testEndTurn(struct gameState *G){

	endTurn(G);
	if(G->whoseTurn == 1){
		printf("SUCCESS! Correct players turn.\n");
	}else{
		printf("FAIL! Player turn incorrect.\n");
	}
	if(G->handCount[0] == 0){
		printf("SUCCESS! Correct players handCount.\n");
	}else{
		printf("FAIL! Player handCount incorrect.\n");
	}

	endTurn(G);
	if(G->whoseTurn == 0){
		printf("SUCCESS! Correct players turn.\n");
	}else{
		printf("FAIL! Player turn incorrect.\n");
	}
	if(G->handCount[1] == 0){
		printf("SUCCESS! Correct players handCount.\n");
	}else{
		printf("FAIL! Player handCount incorrect.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testEndTurn(&G);

	return 0;
}