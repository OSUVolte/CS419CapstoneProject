/*
	Bryan Serif
	CS 362
	04/24/2016

	This file tests the Smithy Card
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
	
	printf("\n-----Testing for Smithy Card-----\n");
	
	for(player = 0; player < 2; player++)
	{
		for(handCount = 0; handCount < maxHandCount; handCount++)
		{
			printf("Testing for player %d, hand count %d:\n", player, handCount);
			
			memset(&G, 23, sizeof(struct gameState));
			memset(&T, 23, sizeof(struct gameState));
			r = initializeGame(2, k, 1000, &T);
			
			T.whoseTurn = player;
			if(player != 0)
			{
				for (i = 0; i < 5; i++)
					drawCard(T.whoseTurn, &T);
			}
			
			memcpy(&G, &T, sizeof(struct gameState));
			
			cardEffect(smithy, 0, 0, 0, &G, handCount, 0);
			
			if (G.playedCardCount == T.playedCardCount + 1)
				printf("Expected played count: %d. Actual played count: %d. Success!\n", T.playedCardCount + 1, G.playedCardCount);
			else
				printf("Expected played count: %d. Actual played count: %d. Failed!\n", T.playedCardCount + 1, G.playedCardCount);
			
			if(G.handCount[player] == T.handCount[player] + 2)
				printf("Expected hand count: %d. Actual hand count: %d. Success!\n", T.handCount[player] + 2, G.handCount[player]);
			else
				printf("Expected hand count: %d. Actual hand count: %d. Failed!\n", T.handCount[player] + 2, G.handCount[player]);
			
		}
	}
	
	printf("\n-----Smithy Card Testing Complete-----\n");	
	return 0;
}