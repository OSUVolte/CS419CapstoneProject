#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <math.h>

#define MAX_TESTS 1000

int testingAdventurer(struct gameState *state, struct gameState *game);

int main()
{
	srand(time(NULL));

	struct gameState state;
	struct gameState game;

	int i, j, player, players, seed; 

	int errorCount = 0;

	int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};

	printf("\nRandom Village Card Testing...\n");

	for(i = 0; i < MAX_TESTS; i++)
	{
		do
		{
			players = rand() % 4;
		} while(players < 2);

		assert(players > 1);

		// Making sure that seed does not equal to zero
		seed = i + 1 + rand();

		// Initialize game
		initializeGame(players, card, seed, &state);

		// Picking a random player
		do
		{
			player = rand() % players;
			if(player == 0 || player == 1)
				{
					player = 1;
					break;
				}
		}while(player == 0);

		// Initialize valid state variables
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;

		// Initalize deck and discard to random cards

		for(j = 0; j < state.deckCount[player]; j++)
		{
			state.deck[player][j] = rand() % (treasure_map + 1);
		}
		for(j = 0; j < state.discardCount[player]; j++)
		{
			state.discard[player][j] = rand() % (treasure_map + 1);
		}

		// Setting the first card to be village
		state.handCount[player] = rand() % (treasure_map + 1);
		state.hand[player][0] = adventurer;
		for(j = 1; j < state.handCount[player]; j++)
		{
			state.hand[player][j] = rand() % (treasure_map + 1);
		}

		memcpy(&game, &state, sizeof(struct gameState));

		if(testingAdventurer(&state, &game) != 0)
		{
			errorCount++;
		}
	}

	printf("\n%d Random Testing completed with %d errors\n", MAX_TESTS, errorCount);


	return 0;
}

int testingAdventurer(struct gameState *state, struct gameState *game)
{
	int p = 0;
	p = whoseTurn(game);

	cardEffect(adventurer, 0, 0, 0, state, 0, 0);

	// Took the assert out since this is where the error is at (see randomhistory.c)
	//assert(state->handCount[p] == 6);
	if(state->handCount[p] != 6)
	{
		return 1;
	}

	return 0;
}
