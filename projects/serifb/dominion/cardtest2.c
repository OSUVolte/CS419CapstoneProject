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
	int card1;
	int card2;
	
	printf("\n-----Testing for Adventurer Card-----\n");
	
	for(player = 0; player < 2; player++)
	{
		printf("Testing for player %d.\n", player);
		
		memset(&G, 23, sizeof(struct gameState));
		memset(&T, 23, sizeof(struct gameState));
		r = initializeGame(2, k, 1000, &T);
		
		memcpy(&G, &T, sizeof(struct gameState));
		
		G.whoseTurn = player;
		
		playAdventurer(&G, player);
		
		if(G.handCount[player] == T.handCount[player] + 1)
			printf("Expected hand count: %d. Actual hand count: %d. Success!\n", T.handCount[player] + 1, G.handCount[player]);
		else
			printf("Expected hand count: %d. Actual hand count: %d. Failed!\n", T.handCount[player] + 1, G.handCount[player]);
		handCount = G.handCount[player];
		card1 = G.hand[player][(handCount - 1)];
		card2 = G.hand[player][(handCount - 2)];
		
		//check the first returned card
		if (card1 == 4 || card1 == 5 || card1 == 6)
			printf("Expected cards: 4, 5, or 6. Actual Card: %d. Success!\n", card1);
		else
			printf("Expected cards: 4, 5, or 6. Actual Card: %d. Failure!\n", card1);
		
		//check the second returned card
		if (card2 == 4 || card2 == 5 || card2 == 6)
			printf("Expected cards: 4, 5, or 6. Actual Card: %d. Success!\n", card2);
		else
			printf("Expected cards: 4, 5, or 6. Actual Card: %d. Failure!\n", card2);
	}
	
	printf("\n-----Adevnturer Card Testing Complete-----\n");	
	return 0;
}