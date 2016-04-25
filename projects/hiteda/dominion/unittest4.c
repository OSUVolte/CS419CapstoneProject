/******************************************************************************
 * Filename:		unittest4.c
 * Author:		David Hite
 * Date Created:	4/24/2016
 * Last Date Edited:	4/24/2016
 *
 * Description:
 * Tests the gamestate after fullDeckCount() is called
 *****************************************************************************/
#include <stdio.h>
#include "dominion.h"

int main()
{
	printf("Testing fullDeckCount()...\n");
	struct gameState* state = newGame();
	int failCount = 0;
	int player = 0;
	
	// set up player's cards
	state->deckCount[player] = 10;
	state->handCount[player] = 5;
	state->discardCount[player] = 7;
	
	int i;
	for (i = 0; i < 10; i++)
	{
		state->deck[player][i] = i;
		
		if (i < 5)
			state->hand[player][i] = i;
		if (i < 7)
			state->discard[player][i] = i;
	}
	
	// check for returning correct values
	int sixCount = fullDeckCount(player, 6, state);
	int nineCount = fullDeckCount(player, 9, state);
	int oneCount = fullDeckCount(player, 1, state);
	int outOfRangeCount = fullDeckCount(player, 15, state);
	
	if (sixCount != 2)
	{
		printf("Error: fullDeckCount() returned %d instead of 2\n", sixCount);
		failCount = failCount + 1;
	}
	if (nineCount != 1)
	{
		printf("Error: fullDeckCount() returned %d instead of 1\n", nineCount);
		failCount = failCount + 1;
	}
	if (oneCount != 3)
	{
		printf("Error: fullDeckCount() returned %d instead of 3\n", oneCount);
		failCount = failCount + 1;
	}
	if (outOfRangeCount != 0)
	{
		printf("Error: fullDeckCount() returned %d instead of 0\n", outOfRangeCount);
		failCount = failCount + 1;
	}
	
	// check that the count of each deck has not changed
	if (state->deckCount[player] != 10)
	{
		printf("Error: deckCount is %d instead of 10\n", state->deckCount[player]);
		failCount = failCount + 1;
	}
	
	if (state->handCount[player] != 5)
	{
		printf("Error: handCount is %d instead of 5\n", state->handCount[player]);
		failCount = failCount + 1;
	}
	
	if (state->discardCount[player] != 7)
	{
		printf("Error: discardCount is %d instead of 7\n", state->discardCount[player]);
		failCount = failCount + 1;
	}
	
	// check that each deck has not changed
	for (i = 0; i < 10; i++)
	{
		if (state->deck[player][i] != i)
		{
			printf("Error: deck at %d is %d instead of %d\n", i, state->deck[player][i], i);
			failCount = failCount + 1;
		}
		
		if (i < 5)
		{
			if (state->hand[player][i] != i)
			{
				printf("Error: hand at %d is %d instead of %d\n", i, state->hand[player][i], i);
				failCount = failCount + 1;
			}
		}
		if (i < 7)
		{
			if (state->discard[player][i] != i)
			{
				printf("Error: discard at %d is %d instead of %d\n", i, state->discard[player][i], i);
				failCount = failCount + 1;
			}
		}
	}
	
	printf("%d tests failed!\n", failCount);
	printf("Testing complete!\n");
	return 0;
}