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

#define UNITTEST "isGameOver"

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
	printf("\n\nTesting Unit %s\n\n", UNITTEST);


	printf("Test 1: Checking the function.\n");
	for(int i = 0; i < 25; i++)
		assert(testG.supplyCount[i] >= 0);
	out = isGameOver(&testG);
	if(out != 1)
		printf("Game is not over(expected)\n");
	else
		printf("Game is over(unexpected)\n");
	assert(out != 1);
	printf("Setting the province cards to 0\n");
	testG.supplyCount[province] = 0;
	out = isGameOver(&testG);
	if(out == 1)
		printf("Game is over(expected)\n");
	else
		printf("Game is Not over(unexpected)\n");
	assert(out == 1);
	printf("Test 1 Passed\n");

	printf("\nTest 2: testing decrease in province cards.\n");
	testG.supplyCount[province] = 5;
	for(int i = 0; i < 5; i++)
	{
		testG.supplyCount[province] = testG.supplyCount[province] -1;
		out = isGameOver(&testG);
		printf("value of %d: %d\n",i,out);
		if(i != 4)
			assert(out == 0);
		else
			assert(out == 1);
	}
	printf("Test 2 Passed\n");

	printf("\nTest 3: Testing 3 piles are at 0.\n");
	for(int i = 0; i < 3; i++)
	{
		printf("supply count of %d was %d.\n",i,testG.supplyCount[i]);
		for(; testG.supplyCount[i] != 0; testG.supplyCount[i] = testG.supplyCount[i] -1);
		printf("supply count of %d now is %d.\n",i,testG.supplyCount[i]);
	}
	testG.supplyCount[province] = 10;
	out = isGameOver(&testG);
	assert(out == 1);
	printf("Test 3 Passed\n");

	printf("\nTest 4: Checking unexpected input/Output\n");
	for(int i = 0; i < 10; i++)
	{
		int mem[3] = {0,0,0};
		for(int i = 0; i < 3; i++)
		{
			mem[i] = rand() % 25;
		}
		testG.supplyCount[mem[0]] = 0;
		testG.supplyCount[mem[1]] = 0;
		testG.supplyCount[mem[2]] = 0;
		printf("Supplies %d, %d and %d are set to 0\n", mem[0],mem[1],mem[2]);
		if(mem[0] != mem[1] && mem[1] != mem[2] && mem[0] != mem[2])
			assert(isGameOver(&testG) == 1);
		for(int j = 0; j < 25; j++)
			testG.supplyCount[j] = 10;
	}
	
	printf("Test 4 Passed\n");
	return 0;	//No bugs found
}
