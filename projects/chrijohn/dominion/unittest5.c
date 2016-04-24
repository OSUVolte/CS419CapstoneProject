// This additional unit test was done since I only really modified unittest1 from the example.

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int r;
	int error = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	printf("TESTING scoreFor()\n");
		// Test all curse
		memset(&G, 23, sizeof(struct gameState));  
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 5;
		G.discardCount[1] = 5;
		G.deckCount[1] = 5;
		for (i = 0; i < 5; i++)
		{
			G.hand[1][i] = curse;
			G.discard[1][i] = curse;
			G.deck[1][i] = curse;
		}
		if (scoreFor(1, &G) != -15)
		{
			printf("Error on curse!");
			error = 1;
		}

		// Test all estate
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 5;
		G.discardCount[1] = 5;
		G.deckCount[1] = 5;
		for (i = 0; i < 5; i++)
		{
			G.hand[1][i] = estate;
			G.discard[1][i] = estate;
			G.deck[1][i] = estate;
		}
		if (scoreFor(1, &G) != 15)
		{
			printf("Error on estate!");
			error = 1;
		}
		// Test all duchy
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 5;
		G.discardCount[1] = 5;
		G.deckCount[1] = 5;
		for (i = 0; i < 5; i++)
		{
			G.hand[1][i] = duchy;
			G.discard[1][i] = duchy;
			G.deck[1][i] = duchy;
		}
		if (scoreFor(1, &G) != 45)
		{
			printf("Error on duchy!");
			error = 1;
		}
		// Test all province
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 5;
		G.discardCount[1] = 5;
		G.deckCount[1] = 5;
		for (i = 0; i < 5; i++)
		{
			G.hand[1][i] = province;
			G.discard[1][i] = province;
			G.deck[1][i] = province;
		}
		if (scoreFor(1, &G) != 90)
		{
			printf("Error on province!");
			error = 1;
		}
		// Test all great halls
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 5;
		G.discardCount[1] = 5;
		G.deckCount[1] = 5;
		for (i = 0; i < 5; i++)
		{
			G.hand[1][i] = great_hall;
			G.discard[1][i] = great_hall;
			G.deck[1][i] = great_hall;
		}
		if (scoreFor(1, &G) != 15)
		{
			printf("Error on great hall!");
			error = 1;
		}
		// Test all gardens
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 5;
		G.discardCount[1] = 5;
		G.deckCount[1] = 5;
		for (i = 0; i < 5; i++)
		{
			G.hand[1][i] = gardens;
			G.discard[1][i] = gardens;
			G.deck[1][i] = gardens;
		}
		if (scoreFor(1, &G) != 15)
		{
			printf("Error on gardens!\n");
			error = 1;
		}
		// Test all no victory points (all smithy)
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 5;
		G.discardCount[1] = 5;
		G.deckCount[1] = 5;
		for (i = 0; i < 5; i++)
		{
			G.hand[1][i] = smithy;
			G.discard[1][i] = smithy;
			G.deck[1][i] = smithy;
		}
		if (scoreFor(1, &G) != 0)
		{
			printf("Error on no victory points!");
			error = 1;
		}
		// Test different size hands
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 4;
		G.discardCount[1] = 5;
		G.deckCount[1] = 6;
		for (i = 0; i < 6; i++)
		{
			G.hand[1][i] = estate;
			G.discard[1][i] = estate;
			G.deck[1][i] = estate;
		}
		if (scoreFor(1, &G) != 15)
		{
			printf("Error on different size decks!\n");
			error = 1;
		}
		// Test different size hands
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayer, k, seed, &G);
		G.handCount[1] = 0;
		G.discardCount[1] = 0;
		G.deckCount[1] = 0;
		if (scoreFor(1, &G) != 0)
		{
			printf("Error on empty decks!\n");
			error = 1;
		}

		if (error == 0)
		{
			printf("All tests passed!\n");
		}

	return 0;
}
