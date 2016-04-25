/*
Behnam Saeedi
Saeedib
93227697
Unit test

testing updateCoin:
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define UNITTEST "updateCoins"

int main(int argc, char ** argv)
{
	srand(time(NULL));
	//Generating player:
	int out;
	int bonus = 0;
	int seed = 999;
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
	testG.hand[thisPlayer][0] = gold;	//3
	testG.hand[thisPlayer][1] = silver;	//2
	testG.hand[thisPlayer][2] = copper;	//1
	//Total should add up to 6
	// Starting test
	printf("\n\nTesting Unit %s\n\n", UNITTEST);


	printf("Test 1: Checking validity of value (in range).\n");
	int bef = testG.handCount[thisPlayer];
	printf("getting initial handCount\n");
	out = updateCoins(thisPlayer,&testG, bonus);

	printf("coinUpdate returned: %d\n",out);
	printf("bonus is: %d\n",bonus);
	printf("Number of playing player is: %d\n",thisPlayer);
	printf("coinUpdate set the coin value to: %d (expected value is: %d)\n",testG.coins,bonus+6);
	assert(testG.coins == bonus + 6);
	printf("handCount is: %d (%d is expected)\n",testG.handCount[thisPlayer],bef);
	assert(testG.handCount[thisPlayer] == bef);
	printf("Test 1 Passed\n");

	printf("\nTest 2: Checking addition of coins (all the possible ways to add coin, bonus and cards).\n");
	bonus++;
	printf("bonus is: %d\n",bonus);
	printf("coinUpdate set the coin value to: %d (expected value is: %d)\n",testG.coins,bonus-1+6);
	assert(testG.coins == bonus-1 + 6);
	out = updateCoins(thisPlayer,&testG, bonus);
	printf("coinUpdate set the coin value to: %d (expected value is: %d)\n",testG.coins,bonus+6);
	assert(testG.coins == bonus + 6);
	printf("Test 2 Passed\n");

	printf("\nTest 3: Checking looking for copper, silver and gold coins.\n");
	bonus = 0;
	printf("bonus is: %d\n",bonus);
	out = updateCoins(thisPlayer,&testG, bonus);
	printf("coinUpdate set the coin value to: %d (expected value is: %d)\n",testG.coins,6);
	assert(testG.coins == 6);
	testG.hand[thisPlayer][3] = gold;
	printf("adding an aditional gold card...\n");
	printf("coinUpdate set the coin value to: %d (expected value is: %d)\n",testG.coins,9);
	out = updateCoins(thisPlayer,&testG, bonus);
	assert(testG.coins == 9);
	printf("cards are:\n");
	for(int i =0; i < count; i++)
	{
		if(testG.hand[thisPlayer][i] == gold)
			printf("gold");
		else if(testG.hand[thisPlayer][i] == silver)
			printf("silver");
		else if(testG.hand[thisPlayer][i] == copper)
			printf("copper");
		else
			printf("Empty");
		if(i != count -1)
			if(i != count -2)
				printf(", ");
			else
				printf(" and ");
		else
			printf("\n");
	}
	assert(testG.hand[thisPlayer][0] == gold);
	assert(testG.hand[thisPlayer][1] == silver);
	assert(testG.hand[thisPlayer][2] == copper);
	assert(testG.hand[thisPlayer][3] == gold);
	printf("Test 3 Passed\n");

	printf("\nTest 4: Checking unexpected input\n");

	bonus = 9999999999999999999999;
	out = updateCoins(thisPlayer,&testG, bonus);
	assert(testG.coins == bonus + 9);
	printf("coinUpdate set the coin value to: %d (expected value is: %d)\n",testG.coins,9 + bonus);
	if(testG.coins < 0)
		printf("Test 4 failed: Failed to return a positive value.\n");
	else
		printf("Test 4 Passed\n");
//	assert(testG.coins >= 0);
	bonus = 0;

	return 0;	//No bugs found
}
