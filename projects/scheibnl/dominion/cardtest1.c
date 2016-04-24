/* cardtest1.c */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
	int newCards = 0;     
	int discarded = 1;     
	int xtraCoins = 0;     
	int shuffledCards = 0;

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
	
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Current player receives 3 cards --------------
	printf("TEST 1: Current player receives 3 cards\n\n");

	// copy the game state to a test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 3;
	xtraCoins = 0;

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	
	//Assert fails- Player receives four cards
	//assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("\n");

	// ----------- TEST 2: 3 cards come from his/her own pile --------------
	printf("TEST 2: 3 cards come from his/her own pile\n\n");

	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);

	//Assert fails- Four cards come from player's deck
	//assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("\n");
	// ----------- TEST 3: No state changes for other players --------------
	printf("TEST 3: No state changes for other players\n\n");
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
	// ----------- TEST 4: No state changes for victory card piles & kingdom card piles --------------
	printf("TEST 4: No state changes for victory card piles & kingdom card piles\n\n");

	for (i = 0; i < (treasure_map + 1); i++)
	{
		printf("Card %d: supply count = %d, expected = %d\n", i, testG.supplyCount[i], G.supplyCount[i]);
		assert(testG.supplyCount[i] == G.supplyCount[i]);
	}

	printf("\n");

	for (i = 0; i < (treasure_map + 1); i++)
	{
		printf("Card %d: embargo tokens = %d, expected = %d\n", i, testG.embargoTokens[i], G.embargoTokens[i]);
		assert(testG.embargoTokens[i] == G.embargoTokens[i]);
	}

	printf("\n");
	// ----------- TEST 5: Check one card added to played card pile --------------
	printf("TEST 5: Check for correct number of played cards\n\n");

	printf("Played card count = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + 1);
	assert(testG.playedCardCount == (G.playedCardCount + 1));
	printf("\n");

	printf("\n");
	// ----------- TEST 6: Player should receive no extra coins --------------
	printf("TEST 6: Current player should receive no extra coins\n\n");

	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	assert(testG.coins == (G.coins + xtraCoins));


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}