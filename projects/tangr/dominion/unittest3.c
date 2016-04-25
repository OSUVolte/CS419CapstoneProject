/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	unittest3.c
*
*	Description: 
*		Test for Treasure Value Count
********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

#include <stdlib.h>
#include <time.h>

void treasureCountTestHelper (struct gameState *testGame, int goldCount, int silverCount, int copperCount, int bonus, int handSize)
{
	int currentPlayer = 0;
	int i;
	int coin;
	int coinValue = ((goldCount * 3) + (silverCount * 2) + (copperCount) + bonus);
	int testSize = 10;
	
	int currentHand[testSize];
	
	for (i = 0; i < goldCount; i++)
		currentHand[i] = gold;
	
	coin = goldCount + silverCount;
	for (i = goldCount; i < coin; i++)
		currentHand[i] = silver;

	coin = goldCount + silverCount + copperCount;
	for (i = goldCount + silverCount; i < coin; i++)
		currentHand[i] = copper;
	
	for (i = coin; i < handSize; i++)
		currentHand[i] = 0;
	
	testGame->handCount[currentPlayer] = handSize;
//	testGame->hand[currentPlayer] = currentHand;
//	error - use memcpy()
	memcpy(testGame->hand[currentPlayer], currentHand, (sizeof(int) * handSize));

	updateCoins(currentPlayer, testGame, bonus);
	
	
	printf("Gold Count = %d \t Silver Count = %d \t Copper Count = %d, bonus = %d \n", goldCount, silverCount, copperCount, bonus);
	if (testGame->coins == coinValue )
		printf("Test - pass\n");
	else
	{
		printf("Test - fail\n");
		printf("Expected Value = %d \t Calculated Value = %d\n", testGame->coins, coinValue);
	}
}

void treasureCountTest()
//		requires "3" tests
//	base case
//		1 copper
//		1 silver
//		1 gold
//	then random coins
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	// cards used are irrelevant for this test

	
	int numPlayer = 2;
	int seed = 1000;
	struct gameState* testGame = newGame();
	
	initializeGame(numPlayer, k, seed, testGame);
	//	retain the reference information for game;
	
	// test one of each coin
	// hand size = 5
	
	int handSize = 5;
	int goldCount = 0;
	int silverCount = 0;
	int copperCount = 1;
	int bonus = 0;
	treasureCountTestHelper (testGame, goldCount, silverCount, copperCount, bonus, handSize);
	
	goldCount = 0;
	silverCount = 1;
	copperCount = 0;
	bonus = 0;
	treasureCountTestHelper (testGame, goldCount, silverCount, copperCount, bonus, handSize);
	
	goldCount = 1;
	silverCount = 0;
	copperCount = 0;
	bonus = 0;
	treasureCountTestHelper (testGame, goldCount, silverCount, copperCount, bonus, handSize);

	goldCount = 0;
	silverCount = 0;
	copperCount = 0;
	bonus = 1;
	treasureCountTestHelper (testGame, goldCount, silverCount, copperCount, bonus, handSize);

	printf("Starting Random Tests\n\n");
	free(testGame);
	initializeGame(numPlayer, k, seed, testGame);
	// generate 5 random tests for 5 random sizes
	//		duplicates possible
	
	srand(time(NULL));
	int coinCount;
	int i;
	int testSize = 10;
	
	for (i = 0; i < 10; i++)
	{
		handSize = rand() % (testSize) + 1;		// number 1 - 10		
		coinCount = (rand() % handSize) + 1;	// 1 - 10
		copperCount = rand() % (coinCount);
		if (copperCount != coinCount)
		{
			silverCount = (rand() % (coinCount - copperCount + 1));
			goldCount = coinCount - copperCount - silverCount;
		}
		bonus = rand() % 6;
		treasureCountTestHelper (testGame, goldCount, silverCount, copperCount, bonus, handSize);
		
	}
}

int main()
{
	treasureCountTest();
	return 0;
}