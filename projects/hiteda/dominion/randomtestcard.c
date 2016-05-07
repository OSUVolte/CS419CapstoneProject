/******************************************************************************
 * Filename:			randomtestcard.c
 * Author:			David Hite
 * Date Created:		5/4/2016
 * Last Date Edited:		5/4/2016
 *
 * Description:
 * Performs a random test on the playVillage() method in dominion.c
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"

int RunTest(struct gameState* state, int failCount);

int main()
{
	printf("Random test playVillage()...\n");
	struct gameState* state = newGame();
	srand(time(NULL));
	int failCount = 0;
	
	int i;
	for (i = 0; i < 30000; i++)
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
	state->numActions = rand() % 10 - 1;
	int oldNumActions = state->numActions;
	
	state->playedCardCount = rand() % 10 - 1;
	int oldPlayedCardCount = state->playedCardCount;
	
	state->whoseTurn = rand() % 4;
	int whoseTurn = state->whoseTurn;
	
	// a hand, deck, or discard pile is counted invalid if it has invalid "cards"
	int i, j;
	int isHandValid = 1;
	int isDeckValid = 1;
	int isDiscardValid = 1;
	int isVillage = 0;
	int villagePos = -1;

	int numHands = rand() % MAX_HAND + 1;
	state->handCount[whoseTurn] = 0;
	for (j = 0; j < numHands; j++)
	{
		state->hand[whoseTurn][j] = rand() % (treasure_map + 1) - 2;
		if (state->hand[whoseTurn][j] < curse || state->hand[whoseTurn][j] > treasure_map)
			isHandValid = 0;
		if (state->hand[whoseTurn][j] == village)
		{
			isVillage = 1;
			villagePos = i;
		}
		state->handCount[whoseTurn]++;
	}
	
	numHands = rand() % MAX_DECK + 1;
	state->deckCount[whoseTurn] = 0;
	for (j = 0; j < numHands; j++)
	{
		state->deck[whoseTurn][j] = rand() % (treasure_map + 1) - 2;
		if (state->deck[whoseTurn][j] < curse || state->deck[whoseTurn][j] > treasure_map)
			isDeckValid = 0;
		state->deckCount[whoseTurn]++;
	}
	
	numHands = rand() % MAX_DECK + 1;
	state->discardCount[whoseTurn] = 0;
	for (j = 0; j < numHands; j++)
	{
		state->discard[whoseTurn][j] = rand() % (treasure_map + 1) - 2;
		if (state->discard[whoseTurn][j] < curse || state->discard[whoseTurn][j] > treasure_map)
			isDiscardValid = 0;
		state->discardCount[whoseTurn]++;
	}
	
	// get original hand count and deck count for comparison
	int oldHandCount = state->handCount[whoseTurn];
	int oldDeckCount = state->deckCount[whoseTurn];
	
	// run the test
	int returnValue = playVillage(state, villagePos, whoseTurn);

	// check if playVillage() caught invalid cards
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
	
	// check that village is no longer in hand if it was
	if (isVillage)
	{
		if (state->hand[whoseTurn][villagePos] == village)
		{
			printf("Error: Village card not removed\n");
			failCount++;
		}
	}
	
	// check that hand count has not changed
	if (oldHandCount != state->handCount[whoseTurn])
	{
		printf("Error: hand count is %d instead of %d\n", state->handCount[whoseTurn], oldHandCount);
		failCount++;
	}
	
	// check that numActions has increased by 2
	if (state->numActions != oldNumActions + 2)
	{
		printf("Error: number of actions is %d instead of %d\n", state->numActions, oldNumActions + 2);
		failCount++;
	}
	
	// check that the played card count has incremented
	if (state->playedCardCount != oldPlayedCardCount + 1)
	{
		printf("Error: played card count is %d instead of %d\n", state->playedCardCount, oldPlayedCardCount);
		failCount++;
	}
	
	// check that the deck has had a card removed
	if (state->deckCount[whoseTurn] != oldDeckCount - 1)
	{
		printf("Error: deck count is %d instead of %d\n", state->deckCount[whoseTurn], oldDeckCount);
		failCount++;
	}
	
	return failCount;
}