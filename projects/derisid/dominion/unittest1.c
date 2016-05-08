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

	printf("----------------- Testing function: numHandCards ----------------\n");

	testG.whoseTurn = 0;
	printf("----------------- Testing correct return value with empty hand ----------------\n");
	testG.handCount[0] = 0;
	if(numHandCards(&testG) == 0)
		printf("TEST PASSED\n");
	else
	    printf("TEST FAILED\n");
	
	printf("----------------- Testing correct return value with populated hand ----------------\n");
	testG.handCount[0] = 4;
	if(numHandCards(&testG) == testG.handCount[0])
		printf("TEST PASSED\n");
	else
	    printf("TEST FAILED\n");

	printf("---------- numHandCards unit testing completed. ----------\n\n");


return 0;

}


