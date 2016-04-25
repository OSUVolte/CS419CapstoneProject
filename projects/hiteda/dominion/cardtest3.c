/******************************************************************************
 * Filename:		cardtest3.c
 * Author:		David Hite
 * Date Created:	4/24/2016
 * Laste Date Edited:	4/24/2016
 *
 * Description:
 * Tests the gamestate after playVillage() is called
 *****************************************************************************/
#include <stdio.h>
#include "dominion.h"

int main()
{
	printf("Testing playVillage()...\n");
	struct gameState* state = newGame();
	int player = 0;
	state->numActions = 1;
	state->numPlayers = 4;
	state->playedCardCount = 0;
	int failCount = 0;
	
	// set hand to a known state
	state->handCount[player] = 3;
	state->hand[player][0] = copper;
	state->hand[player][1] = village;
	state->hand[player][2] = estate;
	
	// set deck to a known state
	state->deckCount[player] = 3;
	state->deck[player][0] = copper;
	state->deck[player][1] = gold;
	state->deck[player][2] = copper;

	// set other players' cards to a known state
	int i;
	for (i = 1; i < state->numPlayers; i++)
	{
		state->handCount[i] = 0;
		state->deckCount[i] = 0;
		state->discardCount[i] = 0;
	}
	
	// call the function being tested
	playVillage(state, 1, player);
	
	// check that handCount has not changed (1 card added, 1 discarded)
	if (state->handCount[player] != 3)
	{
		printf("Error: handCount is %d instead of 3\n", state->handCount[player]);
		failCount++;
	}
	
	// check that numActions has increased by 2
	if (state->numActions != 3)
	{
		printf("Error: numActions is %d instead of 3\n", state->numActions);
		failCount++;
	}
	
	// check that deck has had a card removed
	if (state->deckCount[player] != 2)
	{
		printf("Error: deckCount is %d instead of 2\n", state->deckCount[player]);
		failCount++;
	}
	
	// check that village card is no longer in the player's hand
	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == village)
		{
			printf("Error: village card not discarded\n");
			failCount++;
		}
	}
	
	// check that the played card count has incremented
	if (state->playedCardCount != 1)
	{
		printf("Error: playedCardCount is %d instead of 1\n", state->playedCardCount);
		failCount++;
	}
	
	// check that the other players' cards were not modified
	for (i = 1; i < state->numPlayers; i++)
	{
		if (state->handCount[i] != 0)
		{
			printf("Error: player %d's handCount is %d instead of 0\n", i + 1, state->handCount[i]);
			failCount++;
		}
		if (state->deckCount[i] != 0)
		{
			printf("Error: player %d's deckCount is %d instead of 0\n", i + 1, state->deckCount[i]);
			failCount++;
		}
		if (state->discardCount[i] != 0)
		{
			printf("Error: player %d's discardCount is %d instead of 0\n", i + 1, state->discardCount[i]);
			failCount++;
		}
	}
	
	printf("Testing complete!\n%d errors found.\n", failCount);
	return 0;
}
