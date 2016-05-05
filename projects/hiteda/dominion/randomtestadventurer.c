/******************************************************************************
 * Filename:			randomtestadventurer.c
 * Author:			David Hite
 * Date Created:		5/3/2016
 * Last Date Edited:		5/3/2016
 *
 * Description:
 * Performs a random test on the playAdventurer() method in dominion.c
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"

void RunTest(struct gameState* state);

int main()
{
	printf("Random test playAdventurer()...\n");
	struct gameState* state = newGame();
	srand(time(NULL));
	
	int i;
	for (i = 0; i < 100; i++)
	{
		RunTest(state);
	}
	
	free(state);
	return 0;
}

void RunTest(struct gameState* state)
{
	// try random valid and invalid parameters
	state->numPlayers = rand() % 7 - 1;
	int isNumPlayersValid = (state->numPlayers > 1 && state->numPlayers < MAX_PLAYERS + 1) ? 1 : 0;
	
	int i;
	int isSupplyCountValid = 1;
	for (i = curse; i <= treasure_map; i++)
	{
		state->supplyCount[i] = rand() % 40 - 5;
		if (state->supplyCount[i] < -1)
			isSupplyCountValid = 0;
	}
	
	// had to change because drawCard() could not handle invalid input
	state->whoseTurn = rand() % 4;
	state->numActions = rand() % 10 - 1;
	int isNumActionsValid = (state->numActions > -1) ? 1 : 0;
	
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
			state->hand[i][j] = rand() % (treasure_map + 3) - 2;
			if (state->hand[i][j] < curse || state->hand[i][j] > treasure_map)
				isHandValid = 0;
			state->handCount[i]++;
		}
		
		numHands = rand() % MAX_DECK + 1;
		state->deckCount[i] = 0;
		for (j = 0; j < numHands; j++)
		{
			state->deck[i][j] = rand() % (treasure_map + 3) - 2;
			if (state->deck[i][j] < curse || state->deck[i][j] > treasure_map)
				isDeckValid = 0;
			state->deckCount[i]++;
		}
		
		numHands = rand() % MAX_DECK + 1;
		state->discardCount[i] = 0;
		for (j = 0; j < numHands; j++)
		{
			state->discard[i][j] = rand() % (treasure_map + 3) - 2;
			if (state->discard[i][j] < curse || state->discard[i][j] > treasure_map)
				isDiscardValid = 0;
			state->discardCount[i]++;
		}
	}
	
	for (i = 0; i < MAX_DECK; i++)
	{
		state->playedCards[i] = -1;
	}
	
	state->playedCardCount = 0;
	
	int returnValue = playAdventurer(state, state->whoseTurn);
	
	if (!isNumPlayersValid ||
		!isSupplyCountValid ||
		!isNumActionsValid ||
		!isHandValid ||
		!isDeckValid ||
		!isDiscardValid)
	{
		if (returnValue != -1)
		{
			printf("playAdventurer() did not return invalid\n");
		}
	}
}