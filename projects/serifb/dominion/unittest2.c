/*
	Bryan Serif
	CS 362
	04/24/2016

	This file tests the function isGameOver()
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
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int result;
	struct gameState G;
	int i;
	
	memset(&G, 0, sizeof(struct gameState));
	
	initializeGame(2, k, 10, &G);
	
	printf("\n-----Testing Is Game Over-----\n");
	
	//test with no province cards
	printf("\nTesting with no province cards\n");	
	G.supplyCount[province] = 0;
	result = isGameOver(&G);
	if (result == 1)
		printf("Expected: Game is Over. Actual: Game is over. Success!\n");

	else
		printf("Expected: Game is Over. Actual: Game is not Over. Failure!\n");
	
	//reset one province card
	G.supplyCount[province] = 1;
	
	//testing with province > 0
	printf("\nTesting with Provinces > 0\n");
	result = isGameOver(&G);
	if (result == 1)
		printf("Expected: Game is not Over. Actual: Game is over. Failed!\n");
	else
		printf("Expected: Game is not Over. Actual: Game is not Over. Success!\n");
	
	//test supply piles
	
	//test if one is empty
	printf("\nTesting with 1 supply pile empty\n");
	for (i = 0; i < 10; i++)
	{
		G.supplyCount[k[i]] = 0;
		result = isGameOver(&G);
		if (result == 1)
			printf("Expected: Game is not Over. Actual: Game is over. Failed!\n");
		else
			printf("Expected: Game is not Over. Actual: Game is not Over. Success!\n");
		G.supplyCount[k[i]] = 1;
	}	
	//test if two are empty
	printf("\nTesting with 2 supply piles empty\n");
	G.supplyCount[k[0]] = 0;
	for (i = 1; i < 10; i++)
	{
		G.supplyCount[k[i]] = 0;
		result = isGameOver(&G);
		if (result == 1)
			printf("Expected: Game is not Over. Actual: Game is over. Failed!\n");
		else
			printf("Expected: Game is not Over. Actual: Game is not Over. Success!\n");
		G.supplyCount[k[i]] = 1;
	}
	//test if three are empty
	printf("\nTesting with 3 supply piles empty\n");
	G.supplyCount[k[1]] = 0;
	for (i = 2; i < 10; i++)
	{
		G.supplyCount[k[i]] = 0;
		result = isGameOver(&G);
		if (result == 1)
			printf("Expected: Game is Over. Actual: Game is over. Success!\n");
		else
			printf("Expected: Game is Over. Actual: Game is not Over. Failed!\n");
		G.supplyCount[k[i]] = 1;
	}
	
	printf("\n-----Testing Is Game Over Complete---\n");
	return 0;
}