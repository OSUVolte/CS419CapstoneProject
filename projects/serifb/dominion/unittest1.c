/*
	Bryan Serif
	CS 362
	04/24/2016

	This file tests the functions updateCoins()
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	int i;
	int seed = 1000;
	struct gameState G;
	int numPlayers = 2;
	int bonus;
	int handCount;
	int maxHandCount = 5;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	int maxBonus = 10;


	for (i = 0; i < MAX_HAND; i++)
	{
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}

	printf("\n-----Testing Update Coins-----\n");

	for (i = 0; i < numPlayers; i++)
	{
		for (handCount = 1; handCount <= maxHandCount; handCount++)
		{
			for (bonus = 0; bonus < maxBonus; bonus++)
			{
				printf("Player %d has %d treasure cards and a max bonus of %d.\n", i, handCount, bonus);
				memset(&G, 23, sizeof(struct gameState));
				initializeGame(numPlayers, k, seed, &G);
				G.handCount[i] = handCount;

				// test with all coppers first
				printf("Test 1: Testing with Copper Cards\n");
				memcpy(G.hand[i], coppers, sizeof(int)*handCount);
				updateCoins(i, &G, bonus);
				if (G.coins == (handCount + bonus))
				{
					printf("G.coins = %d, expected coins = %d. Success!\n", G.coins, (handCount + bonus));
				}
				else
				{
					printf("G.coins = %d, expected coins = %d. Failure!\n", G.coins, (handCount + bonus));
				}

				//next test with silvers
				printf("\nTest 2: Testing with Silver Cards\n");
				memcpy(G.hand[i], silvers, sizeof(int)*handCount);
				updateCoins(i, &G, bonus);
				if (G.coins == (handCount * 2 + bonus))
				{
					printf("Actual Coins: %d. Expected coins: %d. Success!\n", G.coins, (handCount * 2 + bonus));
				}
				else
				{
					printf("Actual Coins: %d. Expected coins: %d. Failure!\n", G.coins, (handCount * 2 + bonus));
				}

				//finally testing with all Golds
				printf("\nTest 3: Testing with Gold Cards\n");
				memcpy(G.hand[i], golds, sizeof(int)*handCount);
				updateCoins(i, &G, bonus);
				if (G.coins == (handCount * 3 + bonus))
				{
					printf("Actual Coins: %d. Expected coins: %d. Success!\n", G.coins, (handCount * 3 + bonus));
				}
				else
				{
					printf("Actual Coins: %d. Expected coins: %d. Failure!\n", G.coins, (handCount * 3 + bonus));
				}
			}
		}
	}
	printf("\n-----Testing of Update Coins Complete-----\n");
	return 0;
}