/******************************************************************************
 * Filename:			unittest3.c
 * Author:			David Hite
 * Date Created:		4/23/2016
 * Last Date Modified:		4/23/2016
 *
 * Description:
 * Tests the gamestate after shuffle() is called
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

int RunTest(int player, struct gameState* state, int failCount);
int TestChanged(int player, struct gameState* state, int failCount, int origDeckCount);

int main()
{
	printf("Testing shuffle()...\n");
	struct gameState* state = newGame();
	int player = 0;
	int failCount = 0;
	state->numPlayers = 3;
	
	int j;
	for (j = 1; j <= MAX_DECK; j++)
	{
		printf("Testing shuffle() on %d cards...\n", j);
		state->deckCount[player] = j;
		int i;
		// cards will be curse, estate, duchy, province, copper
		for (i = 0; i < state->deckCount[player]; i++)
		{
			state->deck[player][i] = i;
		}
		
		failCount = RunTest(player, state, failCount);
	}
	
	printf("%d tests failed.\n", failCount);
	printf("Testing complete!\n");
	
	return 0;
}

int RunTest(int player, struct gameState* state, int failCount)
{
	// check that each player's deck has not lost or added any cards
	int i;
	for (i = 0; i < state->numPlayers; i++)
	{
		int origDeckCount = state->deckCount[i];
		printf("Checking player %d's deck...\n", i + 1);
		if (i == 0)
			shuffle(player, state);
		
		failCount = TestChanged(i, state, failCount, origDeckCount);	
	}
	
	return failCount;
}


int TestChanged(int player, struct gameState* state, int failCount, int origDeckCount)
{
	// check that deckCount has not changed
	if (state->deckCount[player] != origDeckCount)
	{
		printf("Error: deckCount has changed from %d to %d\n", origDeckCount, state->deckCount[player]);
		failCount = failCount + 1;
	}
	
	// cardsCount will hold a count of the returned card types
	int* cardsCount = malloc(sizeof(int) * origDeckCount);
	int i;
	for (i = 0; i < origDeckCount; i++)
	{
		cardsCount[i] = 0;
	}
	
	// check that no cards are missing or were duplicated
	int j;	
	for (i = 0; i < state->deckCount[player]; i++)
	{
		for (j = 0; j < origDeckCount; j++)
		{
			if (state->deck[player][i] == j)
				cardsCount[j] = cardsCount[j] + 1;
		}
	}
	
	// check that only 1 of each card type was returned
	for (i = 0; i < origDeckCount; i++)
	{
		if (cardsCount[i] != 1)
		{
			printf("Error: cardsCount[%d] is %d instead of 1\n", i, cardsCount[i]);
			failCount = failCount + 1;
			break;
		}
	}
	
	free(cardsCount);
	return failCount;
}