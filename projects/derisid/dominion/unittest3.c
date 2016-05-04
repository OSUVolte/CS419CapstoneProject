#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
	int seed = 1000;
    int numPlayer = 2;
    int thisPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	struct gameState G, testG;

	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing function: whoseTurn() ----------------\n");

	printf("----------- Test 1: Is it player 1's turn ----------\n");

	testG.whoseTurn = thisPlayer;
	if(whoseTurn(&testG) == 0)
		printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");
	
	printf("----------- Test 2: Is it player 2's turn ----------\n");

	thisPlayer = 1;
	testG.whoseTurn = thisPlayer;
	if(whoseTurn(&testG) == 1)
		printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");

printf("---------- whoseTurn unit testing completed. ----------\n\n");


return 0;

}