/*
Behnam Saeedi
Saeedib
93227697
Unit test
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define UNITTEST "Smithy"

int main(int argc, char ** argv)
{
	srand(time(NULL));
	//Generating player:
	int out;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	// generating a random state
	memcpy(&testG, &G, sizeof(struct gameState));
	int count;
	count = testG.handCount[thisPlayer];
	for(int i = 0; i < count; i++)
		testG.hand[thisPlayer][i] = estate;
	for(int i = 0; i < 25; i++)
		testG.supplyCount[i] = 10;
	testG.hand[thisPlayer][0] = gold;	
	testG.hand[thisPlayer][1] = silver;	
	testG.hand[thisPlayer][2] = copper;	
	testG.discardCount[thisPlayer] = 0;
	// Starting test
	printf("\n\nTesting card: %s\n\n", UNITTEST);

	printf("Test 1: Checking the function.\n");
	out = Smithy(thisPlayer, 3, &testG);
	printf("smithy function should return cost of smithy card : %d.\n",out);
	assert(out==4);
	printf("New Hand count is: %d.\n",testG.handCount[thisPlayer]);
	if(testG.handCount[thisPlayer] < 7)
		printf("Test 1 failed, it needs to return: %d\n", 5 - 1 + 3);
	else
		printf("Test 1 Passed\n");

	printf("Test 2: Discard Pile.\n");
	printf("Discard count is: %d.\n",testG.discardCount[thisPlayer]);
	if(testG.discardCount[thisPlayer] == 1 )
		printf("Test 2 passed.\n");
	else
		printf("Test 2 failed, discard count is not correct.\n");
	return 0;	//No bugs found
}
