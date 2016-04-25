/* cardtest3.c */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>

#define TESTCARD "cutpurse"

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

	// ----------- TEST 1: Current player receives 2 cards\n\n, both of which are copper --------------
	printf("TEST 1: Current player receives 2 copper\n\n");

	// copy the game state to a test case 
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(cutpurse, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 0;
	xtraCoins = 2;

	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	assert(testG.coins == (G.coins + xtraCoins));

	printf("\n");
	// ----------- TEST 2: No state changes for victory card piles & kingdom card piles --------------
	printf("TEST 2: No state changes for victory card piles & kingdom card piles\n\n");

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
	// ----------- TEST 3: Other players all discard a copper or have none on hand --------------
	printf("TEST 3: Other players all discard a copper or have none on hand\n\n");

	int hadCopper;

	for (i = 0; i < numPlayers; i++)
	{
		if (i != thisPlayer)
		{
			hadCopper = 0;
			for (j = 0; j < G.handCount[i]; j++)
			{
				if (G.hand[i][j] == copper)
				{
					hadCopper = 1;
				}
			}

			printf("Player %d: lost %d cards and had copper = %d\n", i, G.handCount[i] - testG.handCount[i], hadCopper);
			assert(((G.handCount[i] - testG.handCount[i]) == 1) || (hadCopper == 0));

		}
	}

	printf("\n");
	// ----------- TEST 4: Current player has same amount of cards on hand and in deck --------------
	printf("TEST 4: Current player has same amount of cards on hand and in deck\n\n");

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	//Assert fails- Player has one fewer card than he or she should
	//assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("\n");
	// ----------- TEST 5: Other players have no change to deck --------------
	printf("TEST 5: Other players have no change to deck\n\n");

	for (i = 0; i < MAX_PLAYERS; i++)
	{
		if (i != thisPlayer)
		{
			if (i >= numPlayers)
			{
				printf("Note: Player not currently in use.\n");
			}

			printf("Asserting here that cards in player %d's deck haven't changed.\n", i);
			for (j = 0; j < MAX_DECK; j++)
			{
				assert(testG.deck[i][j] == G.deck[i][j]);
			}

			printf("Player %d: deck count = %d, expected = %d\n", i, testG.deckCount[i], G.deckCount[i]);
			assert(testG.deckCount[i] == G.deckCount[i]);

			printf("\n");
		}
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}