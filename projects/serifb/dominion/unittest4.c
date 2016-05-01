/*
	Bryan Serif
	CS 362
	04/24/2016

	This file tests the function fullDeckCount()
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
	int handCount = 1;
	int r;
	int deck;
	int player = 0;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	struct gameState G;
	
	memset(&G, 23, sizeof(struct gameState));
	
	r = initializeGame(2, k, 10, &G);
	
	printf("\n-----Testing Full Deck Count-----\n");
	
	G.handCount[player] = handCount;
	
	//checking against max deck size
	deck = fullDeckCount(player, 0, &G);
	if (deck <= MAX_DECK)
		printf("Expected Cards: %d. Actual Cards: %d. Success!\n", MAX_DECK, deck);
	else
		printf("Expected Cards: %d. Actual Cards: %d. Failure!\n", MAX_DECK, deck);
	
	printf("\n-----Full Deck Count Testing Complete\n");
	return 0;
}