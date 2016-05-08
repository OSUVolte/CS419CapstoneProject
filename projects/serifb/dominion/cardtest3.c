/*
	Bryan Serif
	CS 362
	04/24/2016

	This file tests the Great Hall Card
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
	int i, player, handCount, r;
	struct gameState G;
	struct gameState T;
	int k[10] = { adventurer, embargo, village, great_hall, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int maxHandCount = 5;
	
	printf("\n-----Testing for Great Hall Card-----\n");
	
	for(player = 0; player < 2; player++)
	{
		printf("Testing for player %d.\n", player);
		
		memset(&G, 23, sizeof(struct gameState));
		memset(&T, 23, sizeof(struct gameState));
		r = initializeGame(2, k, 1000, &T);
		
		memcpy(&G, &T, sizeof(struct gameState));
		
		G.whoseTurn = player;
		
		G.hand[player][0] = great_hall;
		
		playGreatHall(&G, player, 0);
		
		if(G.handCount[player] == T.handCount[player])
			printf("Expected hand count: %d. Actual hand count: %d. Success!\n", T.handCount[player], G.handCount[player]);
		else
			printf("Expected hand count: %d. Actual hand count: %d. Failed!\n", T.handCount[player], G.handCount[player]);
		
		//check the number of actions increased
		if (G.numActions == T.numActions)
			printf("Expected number of actions: %d. Actual number of Actions: %d. Success!\n", T.numActions, G.numActions);
		else
			printf("Expected number of actions: %d. Actual number of Actions: %d. Failure!\n", T.numActions, G.numActions);
	}
	
	printf("\n-----Great Hall Card Testing Complete-----\n");	
	return 0;
}