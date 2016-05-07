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

	printf("----------------- Testing function: playCard ----------------\n");


	printf("----------- Test 1:  Checking playCard invocation refusal if numActions < 1 ----------\n");
	testG.numActions = 0;

	if(playCard(0, 0, 0, 0, &testG) == -1)
		printf("TEST PASSED\n");
	else
	    printf("TEST FAILED\n");

	printf("----------- Test 2:  Checking playCard compliance with available action ----------\n");

	memcpy(&testG, &G, sizeof(struct gameState));

	if(playCard(smithy, 0, 0, 0, &testG) == 0)
		printf("TEST PASSED\n");
	else
	    printf("TEST FAILED\n");


printf("---------- playCard unit testing completed. ----------\n\n");


return 0;

}