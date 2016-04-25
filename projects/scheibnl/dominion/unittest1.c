/* unittest1.c */

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

	printf("----------------- Testing Function: discardCard ----------------\n");

	int trashFlag = 0;
	int funcResult;

	funcResult = discardCard(handpos, thisPlayer, &testG, trashFlag);

	// ----------- TEST 1: One card leaves player's hand --------------
	printf("TEST 1:  One card leaves player's hand\n\n");

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - 1);
	assert(testG.handCount[thisPlayer] == (G.handCount[thisPlayer] - 1));


	printf("\n");
	// ----------- TEST 2: One card added to played pile (if trashed flag isn't set)--------------
	printf("TEST 2:  One card added to played pile (if trashed flag isn't set)\n\n");

	printf("played pile = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + 1);
	assert(testG.playedCardCount == (G.playedCardCount + 1));


	printf("\n");
	// ----------- TEST 3: The card removed from player's hand is the same as the card added to played pile --------------
	printf("TEST 3: The card removed from player's hand is the same as the card added to played pile\n\n");
	printf("card in played pile = %d, expected = %d\n", testG.playedCards[testG.playedCardCount - 1], G.hand[thisPlayer][handpos]);


	printf("\n");
	// ----------- TEST 4: No state changes for other players --------------
	printf("TEST 4: No state changes for other players\n\n");

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
	// ----------- TEST 5: No state changes for victory or kingdom cards --------------
	printf("TEST 5: No state changes for victory or kingdom cards\n\n");

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
	// ----------- TEST 6: No other state changes for current player (besides discard) --------------
	printf("TEST 6: No other state changes for current player (besides discard)\n\n");


	printf("Asserting here that cards in current player's deck haven't changed.\n");
	for (j = 0; j < MAX_DECK; j++)
	{
		assert(testG.deck[thisPlayer][j] == G.deck[thisPlayer][j]);
	}

	printf("Current player: deck count = %d, expected = %d\n",testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
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
	// ----------- TEST 7: If trash flag is set, see that card is removed from hand, but not added to played pile --------------
	printf("TEST 7: If trash flag is set, see that card is removed from hand, but not added to played pile\n\n");

	// copy current game state to the test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	trashFlag = 1;

	funcResult = discardCard(handpos, thisPlayer, &testG, trashFlag);

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - 1);
	assert(testG.handCount[thisPlayer] == (G.handCount[thisPlayer] - 1));

	printf("played pile = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount);
	assert(testG.playedCardCount == G.playedCardCount);


	printf("\n");
	// ----------- TEST 8: Check for correct result if card is last in hand, but not the only card --------------
	printf("TEST 8: Check for correct result if card is last in hand, but not the only card \n\n");

	memcpy(&testG, &G, sizeof(struct gameState));

	trashFlag = 0;

	funcResult = discardCard((testG.handCount[thisPlayer] - 1), thisPlayer, &testG, trashFlag);

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - 1);
	assert(testG.handCount[thisPlayer] == (G.handCount[thisPlayer] - 1));

	printf("played pile = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + 1);
	assert(testG.playedCardCount == (G.playedCardCount + 1));

	printf("\n");
	// ----------- TEST 9: Check for correct result if player only has one card to discard --------------
	printf("TEST 9: Check for correct result if player only has one card to discard\n\n");

	initializeGame(numPlayers, k, seed, &G);
	G.handCount[thisPlayer] = 1;
	memcpy(&testG, &G, sizeof(struct gameState));

	funcResult = discardCard((testG.handCount[thisPlayer] - 1), thisPlayer, &testG, trashFlag);

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - 1);
	assert(testG.handCount[thisPlayer] == (G.handCount[thisPlayer] - 1));

	printf("played pile = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + 1);
	assert(testG.playedCardCount == (G.playedCardCount + 1));


	printf("\n >>>>> SUCCESS: Testing complete discardCard <<<<<\n\n");

	return 0;
}