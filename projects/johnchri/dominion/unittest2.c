#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testBuyCard(struct gameState *G){

	G->coins = 6;
	buyCard(7, G);
	if(G->numBuys == 0){
		printf("SUCCESS! Num buys is now 0.\n");
	}else{
		printf("FAIL! Num buys was not decremented.\n");
	}
	if(G->coins == 0){
		printf("SUCCESS! Num coins is now 0.\n");
	}else{
		printf("FAIL! Num coins was not decremented.\n");
	}

	G->coins = 3;
	G->numBuys = 1;
	if(buyCard(7, G) == -1){
		printf("SUCCESS! Didn't have enough coins.\n");
	}else{
		printf("FAIL! Should have returned -1.\n");
	}

	G->coins = 6;
	G->numBuys = 0;
	if(buyCard(7, G) == -1){
		printf("SUCCESS! Didn't have enough buys.\n");
	}else{
		printf("FAIL! Should have returned -1.\n");
	}

	G->coins = 6;
	G->numBuys = 1;
	G->supplyCount[adventurer] = 0;
	if(buyCard(7, G) == -1){
		printf("SUCCESS! Didn't have any adventurer cards left.\n");
	}else{
		printf("FAIL! Should have returned -1.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testBuyCard(&G);

	return 0;
}