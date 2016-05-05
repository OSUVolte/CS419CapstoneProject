/******************************************************************************
 * Filename:			randomtestadventurer.c
 * Author:			David Hite
 * Date Created:		5/3/2016
 * Last Date Edited:		5/4/2016
 *
 * Description:
 * Performs a random test on the playAdventurer() method in dominion.c
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"

int RunTest(struct gameState* state, int failCount);

int main()
{
	printf("Random test playAdventurer()...\n");
	struct gameState* state = newGame();
	srand(time(NULL));
	int failCount = 0;
	
	int i;
	for (i = 0; i < 1000; i++)
	{
		failCount = RunTest(state, failCount);
	}
	
	free(state);
	
	printf("Testing complete!\n");
	printf("%d tests failed\n", failCount);
	return 0;
}

int RunTest(struct gameState* state, int failCount)
{
	int i;
	
	// had to change to only valid inputs because drawCard() could not handle invalid input
	state->whoseTurn = rand() % 4;
	
	// a hand, deck, or discard pile is counted invalid if it has invalid "cards"
	int j;
	int isHandValid = 1;
	int isDeckValid = 1;
	int isDiscardValid = 1;
	for (i = 0; i < MAX_PLAYERS; i++)
	{
		int numHands = rand() % MAX_HAND + 1;
		state->handCount[i] = 0;
		for (j = 0; j < numHands; j++)
		{
			state->hand[i][j] = rand() % (treasure_map + 1) - 2;
			if (state->hand[i][j] < curse || state->hand[i][j] > treasure_map)
				isHandValid = 0;
			state->handCount[i]++;
		}
		
		numHands = rand() % MAX_DECK + 1;
		state->deckCount[i] = 0;
		for (j = 0; j < numHands; j++)
		{
			state->deck[i][j] = rand() % (treasure_map + 1) - 2;
			if (state->deck[i][j] < curse || state->deck[i][j] > treasure_map)
				isDeckValid = 0;
			state->deckCount[i]++;
		}
		
		numHands = rand() % MAX_DECK + 1;
		state->discardCount[i] = 0;
		for (j = 0; j < numHands; j++)
		{
			state->discard[i][j] = rand() % (treasure_map + 1) - 2;
			if (state->discard[i][j] < curse || state->discard[i][j] > treasure_map)
				isDiscardValid = 0;
			state->discardCount[i]++;
		}
	}
	
	// get original hand count for comparison
	int oldHandCount = state->handCount[state->whoseTurn];
	
	// run the test
	int returnValue = playAdventurer(state, state->whoseTurn);

	// check if playAdventurer() caught invalid cards
	if (!isHandValid)
	{
		if (returnValue != -1)
		{
			printf("Error: playAdventurer() did not recognize invalid cards in hand\n");
			failCount++;
		}
	}
	if (!isDeckValid)
	{
		if (returnValue != -1)
		{
			printf("Error: playAdventurer() did not recognize invalid cards in deck\n");
			failCount++;
		}
	}
	if (!isDiscardValid)
	{
		if (returnValue != -1)
		{
			printf("Error: playAdventurer() did not recognize invalid cards in discard\n");
			failCount++;
		}
	}
	
	// make sure that two cards were added to the current player's hand
	if (oldHandCount != (state->handCount[state->whoseTurn] - 2))
	{
		printf("Error: hand is %d instead of %d\n", state->handCount[state->whoseTurn], oldHandCount + 2);
		failCount++;
	}
	
	return failCount;
}