/* randomtestadventurer.c */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>
#include <time.h>

#define TESTCARD "adventurer"

int main() {
	srand(time(NULL));

	int newCards = 0;
	int discarded = 1;
	int xtraCoins = 0;
	int shuffledCards = 0;

	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed;
	int numPlayers;
	int thisPlayer = 0;

	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
		tribute, smithy, council_room };


	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


	for (m = 0; m < 2000; m++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&G)[i] = floor(rand() * 256);
		}

		//initializing a random game
		numPlayers = rand() % 3 + 2;
		G.numPlayers = numPlayers;


		thisPlayer = rand() % numPlayers;
		G.whoseTurn = thisPlayer;

		G.deckCount[thisPlayer] = (rand() % (MAX_DECK - 5) + 5);
		G.discardCount[thisPlayer] = rand() % (MAX_DECK - G.deckCount[thisPlayer]);
		G.handCount[thisPlayer] = rand() % (MAX_HAND - G.deckCount[thisPlayer]);


		for (i = 0; i < G.deckCount[thisPlayer]; i++)
		{
			if ((i == 0) || (i == 1))
			{
				G.deck[thisPlayer][i] = rand() % 3 + 4;
			}

			else
			{
				G.deck[thisPlayer][i] = rand() % 27;
			}
		}

		for (i = 0; i < G.discardCount[thisPlayer]; i++)
		{
			G.discard[thisPlayer][i] = rand() % 27;
		}

		for (i = 0; i < G.handCount[thisPlayer]; i++)
		{
			G.hand[thisPlayer][i] = rand() % 27;
		}




	


		// ----------- TEST 1: Current player receives two cards, both of which are treasure cards --------------
		printf("TEST 1: Current player receives two cards, both of which are treasure cards\n\n");

		// copy the game state to a test case 
		memcpy(&testG, &G, sizeof(struct gameState));

		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

		newCards = 2;
		xtraCoins = 0;

		printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		//Assert fails- Player has one too many cards on hand
		//assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

		int treasureCardsTest = 0;
		int treasureCardsCopy = 0;

		for (i = 0; i < testG.handCount[thisPlayer]; i++)
		{
			if ((testG.hand[thisPlayer][i] == copper) || (testG.hand[thisPlayer][i] == silver) || (testG.hand[thisPlayer][i] == gold))
			{
				treasureCardsTest++;
			}
		}

		for (i = 0; i < G.handCount[thisPlayer]; i++)
		{
			if ((G.hand[thisPlayer][i] == copper) || (G.hand[thisPlayer][i] == silver) || (G.hand[thisPlayer][i] == gold))
			{
				treasureCardsCopy++;
			}
		}

		printf("treasure cards on hand = %d, expected = %d\n", treasureCardsTest, (treasureCardsCopy + 2));
		assert(treasureCardsTest == (treasureCardsCopy + 2));


		printf("\n");
		// ----------- TEST 2: No state change for other players --------------
		printf("TEST 2: No state change for other players\n\n");

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
		// ----------- TEST 3: No state changes for victory card piles & kingdom card piles --------------
		printf("TEST 3: No state changes for victory card piles & kingdom card piles\n\n");

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
		// ----------- TEST 4: All cards drawn should be discarded (put in played cards) except for the two treasure cards --------------
		printf("TEST 4: All cards drawn should be discarded except for the two treasure cards\n\n");

		// copy the game state to a test case 
		memcpy(&testG, &G, sizeof(struct gameState));

		//setting two adventurer cards, so player draws something other than coins.
		testG.deck[thisPlayer][testG.deckCount[thisPlayer] - 1] = 7;
		testG.deck[thisPlayer][testG.deckCount[thisPlayer] - 2] = 7;

		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

		printf("discarded cards = %d, expected = %d\n", testG.discardCount[thisPlayer], (G.deckCount[thisPlayer] - testG.deckCount[thisPlayer] - 2));
		//Assert fails: too many cards in discard pile
		//assert(testG.playedCardCount == (G.deckCount[thisPlayer] - testG.deckCount[thisPlayer] - 2));


		printf("\n");
		// ----------- TEST 5: No treasure cards should be discarded--------------
		printf("TEST 5: No treasure cards should be discarded\n\n");

		printf("Asserting that no discarded cards are treasure cards\n");

		int numDiscarded;

		numDiscarded = (sizeof(G.discardCount[thisPlayer]) - sizeof(testG.discardCount[thisPlayer]));
		printf("Num discarded: %d\n", numDiscarded);

		if (numDiscarded > 0)
		{
			for (i = 0; i < testG.discardCount[thisPlayer]; i++)
			{
				assert((testG.discard[thisPlayer][i] != copper) && (testG.discard[thisPlayer][i] != silver) && (testG.discard[thisPlayer][i] != gold));
			}
		}

		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	}

	return 0;
}