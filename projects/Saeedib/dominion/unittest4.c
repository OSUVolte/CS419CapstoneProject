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

#define UNITTEST "scoreFor"

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
	testG.hand[thisPlayer][0] = duchy;	//3
	testG.hand[thisPlayer][1] = province;	//6
	testG.hand[thisPlayer][2] = great_hall;	//1
	testG.hand[thisPlayer][3] = estate; //1
	testG.hand[thisPlayer][4] = estate; //1
	for(int i = 0; i < testG.discardCount[thisPlayer]; i++)
		testG.discard[thisPlayer][i] = estate;
	//Total should add up to 12
	// Starting test
	printf("\n\nTesting Unit %s\n\n", UNITTEST);
	printf("Test 1: Checking the function.\n");
	out = scoreFor(thisPlayer,&testG);
	printf("ScoreFor returned: %d(expected 12).\n",out);
	assert(out == 12);
	testG.hand[thisPlayer][3] = province; //6
	out = scoreFor(thisPlayer,&testG);
	printf("new ScoreFor returned: %d (expected 17).\n",out);
	assert(out == 17);
	printf("Test 1 Passed\n");

	printf("\nTest 2: discarding a card.\n");
	out = discardCard(4,thisPlayer,&testG,0);
	out = discardCard(3,thisPlayer,&testG,0);
	out = scoreFor(thisPlayer,&testG);
	printf("new ScoreFor returned: %d (expected 10).\n",out);
	assert(out == 10);
	printf("Test 2 Passed\n");

	return 0;	//No bugs found
}
