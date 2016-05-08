/* unittest4.c */

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

	printf("----------------- Testing Function: isGameOver ----------------\n");

	// ----------- TEST 1: Should determine game is over if no more province cards --------------
	printf("TEST 1:  Should determine game is over if no more province cards\n\n");

	testG.supplyCount[province] = 0;

	int result = isGameOver(&testG);

	printf("Result = %d, expected = 1\n", result);
	assert(result == 1);


	printf("\n");
	// ----------- TEST 2: Should determine game is over if three supply piles are empty --------------
	printf("TEST 2: Should determine game is over if three supply piles are empty\n\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("Emptying adventurer, cutpurse, and minion.\n");
	testG.supplyCount[adventurer] = 0;
	testG.supplyCount[cutpurse] = 0;
	testG.supplyCount[minion] = 0;

	result = isGameOver(&testG);

	printf("Result = %d, expected = 1\n", result);
	assert(result == 1);

	printf("\n");
	// ----------- TEST 3: Should determine game is not over if there are province cards left and less than three supply piles are empty --------------
	printf("TEST 3: Should determine game is not over if there are province cards left and less than three supply piles are empty \n\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Emptying nothing.\n");

	result = isGameOver(&testG);
	printf("Result = %d, expected = 0\n", result);
	assert(result == 0);

	printf("Emptying only adventurer.\n");
	testG.supplyCount[adventurer] = 0;

	result = isGameOver(&testG);
	printf("Result = %d, expected = 0\n", result);
	assert(result == 0);

	printf("Emptying adventurer and minion.\n");
	testG.supplyCount[minion] = 0;

	result = isGameOver(&testG);
	printf("Result = %d, expected = 0\n", result);
	assert(result == 0);

	printf("\n");
	// ----------- TEST 4: Should not change state of current player --------------
	printf("TEST 4: Should not change state of current player \n\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	result = isGameOver(&testG);

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
	// ----------- TEST 5: Should not change state of other players --------------
	printf("TEST 5: Should not change state of other players \n\n");

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
	// ----------- TEST 6: Should not change state of victory or kingdom cards --------------
	printf("TEST 6: Should not change state of victory or kingdom cards \n\n");

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

	printf("\n >>>>> SUCCESS: Testing complete isGameOver <<<<<\n\n");

	return 0;
}