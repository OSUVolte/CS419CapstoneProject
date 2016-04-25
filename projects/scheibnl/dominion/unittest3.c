/* unittest3.c */

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


	printf("----------------- Testing Function: gainCard ----------------\n");


	// ----------- TEST 1: Player's discard/deck/or hand size should increase by one, depending on flag --------------
	printf("TEST 1: Player's discard/deck/or hand size should increase by one, depending on flag\n\n");

	// toFlag = 0 : add to discard
	// toFlag = 1 : add to deck
	// toFlag = 2 : add to hand

	printf("Setting flag to 0, seeing if discard increases, deck and hand remain same.\n");
	int toFlag = 0;

	//adventurer card
	int supplyPos = 7;

	// copy the game state to a test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	gainCard(supplyPos, &testG, toFlag, thisPlayer);

	printf("Current player: discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + 1);
	assert(testG.discardCount[thisPlayer] == (G.discardCount[thisPlayer] + 1));

	printf("Current player: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);

	printf("Current player: hand count = %d, expected = %d\n\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);

	printf("Setting flag to 1, seeing if deck increases, others remain same.\n");
	toFlag = 1;

	// copy the game state to a test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	gainCard(supplyPos, &testG, toFlag, thisPlayer);

	printf("Current player: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] + 1);
	assert(testG.deckCount[thisPlayer] == (G.deckCount[thisPlayer] + 1));

	printf("Current player: discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);

	printf("Current player: hand count = %d, expected = %d\n\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);

	printf("Setting flag to 2, seeing if hand increases, others remain same.\n");
	toFlag = 2;

	// copy the game state to a test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	gainCard(supplyPos, &testG, toFlag, thisPlayer);

	printf("Current player: hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1);
	assert(testG.handCount[thisPlayer] == (G.handCount[thisPlayer] + 1));

	printf("Current player: discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);

	printf("Current player: deck count = %d, expected = %d\n\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);

	printf("\n");
	// ----------- TEST 2: Added card should be the card specified --------------
	printf("TEST 2:  Added card should be the card specified\n\n");

	printf("New card on hand = %d, expected = %d\n", testG.hand[thisPlayer][(testG.handCount[thisPlayer] - 1)], 7);
	assert(testG.hand[thisPlayer][(testG.handCount[thisPlayer] - 1)] == 7);

	printf("\n");
	// ----------- TEST 3: Pile providing card should decrease by one --------------
	printf("TEST 3: Pile providing card should decrease by one\n\n");

	printf("Size of adventurer pile = %d, expected = %d\n", testG.supplyCount[7], G.supplyCount[7] - 1);


	printf("\n");
	// ----------- TEST 4: If card isn't available, function should return -1 and do nothing--------------
	printf("TEST 4: If card isn't available, function should return -1 and do nothing\n\n");

	//feast card... not in game
	supplyPos = 9;

	// copy the game state to a test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	int result = gainCard(supplyPos, &testG, toFlag, thisPlayer);

	printf("Result = %d, expected = %d\n", result, -1);
	assert(result == -1);

	printf("Current player: discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == (G.discardCount[thisPlayer]));

	printf("Current player: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);

	printf("Current player: hand count = %d, expected = %d\n\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);

	printf("\n");
	// ----------- TEST 5: No state changes for other players --------------
	printf("TEST 5: No state changes for other players\n\n");

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
	// ----------- TEST 6: No state changes for victory or kingdom cards (besides gained card) --------------
	printf("TEST 6: No state changes for victory or kingdom cards (besides gained card)\n\n");

	for(i = 0; i < (treasure_map + 1); i++)
	{
		if (i != 7)
		{
			printf("Card %d: supply count = %d, expected = %d\n", i, testG.supplyCount[i], G.supplyCount[i]);
			assert(testG.supplyCount[i] == G.supplyCount[i]);
		}

	}

	printf("\n");

	for(i = 0; i < (treasure_map + 1); i++)
	{
		printf("Card %d: embargo tokens = %d, expected = %d\n", i, testG.embargoTokens[i], G.embargoTokens[i]);
		assert(testG.embargoTokens[i] == G.embargoTokens[i]);
	}

	printf("\n >>>>> SUCCESS: Testing complete gainCard <<<<<\n\n");


	return 0;
}