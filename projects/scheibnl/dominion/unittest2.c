/* unittest2.c */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>

int main() {

	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;

	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
		tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	// copy the game state to a test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	updateCoins(thisPlayer, &testG, bonus);

	printf("----------------- Testing Function: updateCoins ----------------\n");


	// ----------- TEST 1: Coin count should match coin cards in current player's hand --------------
	printf("TEST 1:  Coin count should match coin cards in current player's hand\n\n");
	int coinTotal = 0;

	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		if (testG.hand[thisPlayer][i] == copper)
		{
			coinTotal += 1;
		}
		else if (testG.hand[thisPlayer][i] == silver)
		{
			coinTotal += 2;
		}
		else if (testG.hand[thisPlayer][i] == gold)
		{
			coinTotal += 3;
		}
	}

	printf("coin count = %d, expected = %d\n", testG.coins, coinTotal);
	assert(testG.coins == coinTotal);

	printf("\n");
	// ----------- TEST 2: No state changes for other players --------------
	printf("TEST 2: No state changes for other players\n\n");

	for (i = 0; i < MAX_PLAYERS; i++)
	{
		if (i != thisPlayer)
		{
			if (i >= numPlayers)
			{
				printf("Note: Player not currently in use.\n");
			}

			printf("Asserting here that cards in player %d's hand haven't changed.\n", i);
			for (j = 0; j < MAX_HAND; j++)
			{
				assert(testG.hand[i][j] == G.hand[i][j]);
			}

			printf("Player %d: hand count = %d, expected = %d\n", i, testG.handCount[i], G.handCount[i]);
			assert(testG.handCount[i] == G.handCount[i]);

			printf("Asserting here that cards in player %d's deck haven't changed.\n", i);
			for (j = 0; j < MAX_DECK; j++)
			{
				assert(testG.deck[i][j] == G.deck[i][j]);
			}

			printf("Player %d: deck count = %d, expected = %d\n", i, testG.deckCount[i], G.deckCount[i]);
			assert(testG.deckCount[i] == G.deckCount[i]);

			printf("Asserting here that cards in player %d's discard pile haven't changed.\n", i);
			for (j = 0; j < MAX_DECK; j++)
			{
				assert(testG.discard[i][j] == G.discard[i][j]);
			}

			printf("Player %d: discard count = %d, expected = %d\n", i, testG.discardCount[i], G.discardCount[i]);
			assert(testG.discardCount[i] == G.discardCount[i]);
			printf("\n");
		}
	}


	printf("\n");
	// ----------- TEST 3: No state changes for victory or kingdom cards --------------
	printf("TEST 3: No state changes for victory or kingdom cards\n\n");

	for(i = 0; i < (treasure_map + 1); i++)
	{
		printf("Card %d: supply count = %d, expected = %d\n", i, testG.supplyCount[i], G.supplyCount[i]);
		assert(testG.supplyCount[i] == G.supplyCount[i]);
	}

	printf("\n");

	for(i = 0; i < (treasure_map + 1); i++)
	{
		printf("Card %d: embargo tokens = %d, expected = %d\n", i, testG.embargoTokens[i], G.embargoTokens[i]);
		assert(testG.embargoTokens[i] == G.embargoTokens[i]);
	}

	printf("\n");
	// ----------- TEST 4: No other state changes for current player (besides updating coins) --------------
	printf("TEST 4: No other state changes for current player (besides updating coins)\n\n");

	printf("Asserting here that cards in current player's hand haven't changed.\n");
	for (j = 0; j < MAX_DECK; j++)
	{
		assert(testG.hand[thisPlayer][j] == G.hand[thisPlayer][j]);
	}

	printf("Current player: hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);


	printf("Asserting here that cards in current player's deck haven't changed.\n");
	for (j = 0; j < MAX_DECK; j++)
	{
		assert(testG.deck[thisPlayer][j] == G.deck[thisPlayer][j]);
	}

	printf("Current player: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);

	printf("Asserting here that cards in current player's discard pile haven't changed.\n");
	for (j = 0; j < MAX_DECK; j++)
	{
		assert(testG.discard[thisPlayer][j] == G.discard[thisPlayer][j]);
	}

	printf("Current player: discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);
	printf("\n");

	printf("\n");
	// ----------- TEST 5: Check that a bonus is appropriately added to coin count --------------
	printf("TEST 5: Check that a bonus is appropriately added to coin count\n\n");

	bonus = 3;

	updateCoins(thisPlayer, &testG, bonus);


	coinTotal = 0;

	for (i = 0; i < testG.handCount[thisPlayer]; i++)
	{
		if (testG.hand[thisPlayer][i] == copper)
		{
			coinTotal += 1;
		}
		else if (testG.hand[thisPlayer][i] == silver)
		{
			coinTotal += 2;
		}
		else if (testG.hand[thisPlayer][i] == gold)
		{
			coinTotal += 3;
		}
	}

	printf("coin count = %d, expected = %d\n", testG.coins, coinTotal + bonus);
	assert(testG.coins == (coinTotal + bonus));



	printf("\n >>>>> SUCCESS: Testing complete updateCoins <<<<<\n\n");

	return 0;
}