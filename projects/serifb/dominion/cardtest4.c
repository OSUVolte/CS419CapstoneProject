/*
	Bryan Serif
	CS 362
	04/24/2016

	This file tests the Council Room Card
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
	int numPlayers = 2;
	struct gameState G;
	struct gameState T;
	int k[10] = { adventurer, embargo, village, great_hall, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int maxHandCount = 5;
	
	printf("\n-----Testing for Council Room Card-----\n");
	
	for(player = 0; player < 2; player++)
	{
		printf("Testing for player %d.\n", player);
		
		memset(&G, 23, sizeof(struct gameState));
		memset(&T, 23, sizeof(struct gameState));
		r = initializeGame(numPlayers, k, 1000, &T);
		
		memcpy(&G, &T, sizeof(struct gameState));
		
		G.whoseTurn = player;
		
		G.hand[player][0] = council_room;
		
		playCouncilRoom(&G, player, 0);
		
		
		
		//check the number of actions increased
		if (G.numBuys == T.numBuys + 1)
			printf("Expected number of actions: %d. Actual number of Actions: %d. Success!\n", T.numActions, G.numActions);
		else
			printf("Expected number of actions: %d. Actual number of Actions: %d. Failure!\n", T.numActions, G.numActions);
		
		//check all hands to make sure they increased
		for (i = 0; i < numPlayers; i++)
		{
			if (player == i)
			{
				if(G.handCount[player] == T.handCount[player] + 3)
					printf("Expected hand count: %d. Actual hand count: %d. Success!\n", T.handCount[player] + 3, G.handCount[player]);
				else
					printf("Expected hand count: %d. Actual hand count: %d. Failed!\n", T.handCount[player] + 3, G.handCount[player]);
			}
			else
			{
				if(G.handCount[i] == T.handCount[i] + 1)
					printf("Expected hand count: %d. Actual hand count: %d. Success!\n", T.handCount[i] + 1, G.handCount[i]);
				else
					printf("Expected hand count: %d. Actual hand count: %d. Failed!\n", T.handCount[i] + 1, G.handCount[i]);
			}
		}
	}
	
	printf("\n-----Council Room Card Testing Complete-----\n");	
	return 0;
}