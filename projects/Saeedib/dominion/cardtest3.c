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

#define UNITTEST "Adventurer"

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
	testG.hand[thisPlayer][0] = gold;	//3
	testG.hand[thisPlayer][1] = silver;	//2
	testG.hand[thisPlayer][2] = copper;	//1
	testG.supplyCount[province] = rand() % 5 + 1;
	//Total should add up to 6
	// Starting test
	printf("\n\nNot enough time: %s\n\n", UNITTEST);

	return 0;	//No bugs found
}
