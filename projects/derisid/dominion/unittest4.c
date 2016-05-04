//unit test for isGameOver function


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

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	struct gameState G, testG;

	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing function: isGameOver ----------------\n");

	printf("----------- Test 1:  Is this a new game? ----------\n");

	if(isGameOver(&testG) == 0)
		printf("TEST PASSED\n");
	else
	    printf("TEST FAILED\n");

	printf("----------- Test 2:  Is game declared over on empty Province pile? ----------\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));
  	testG.supplyCount[province] = 0;
  	if(isGameOver(&testG) == 1)
  		printf("TEST PASSED\n");
	else
	    printf("TEST FAILED\n");

	printf("----------- Test 3:  Is game declared over on empty supply piles? ----------\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.supplyCount[adventurer] = 0;
	testG.supplyCount[embargo] = 0;
	testG.supplyCount[village] = 0;
	if(isGameOver(&testG) == 1)
  		printf("TEST PASSED\n");
	else
	    printf("TEST FAILED\n");

	printf("---------- isGameOver unit testing completed. ----------\n\n");

 return 0;
}

