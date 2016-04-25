/******************************************************************************
 * Filename:		cardtest1.c
 * Author:		David Hite
 * Date Created:	4/24/2016
 * Last Date Edited:	4/24/2016
 *
 * Description:
 * Tests the gamestate after calling playSmithy()
 *****************************************************************************/
#include <stdio.h>
#include "dominion.h"

int main()
{
	printf("Testing playSmithy()...\n");
	struct gameState* state = newGame();
	int player = 0;
	int failCount = 0;
	state->numPlayers = 4;
	
	// start each player with a total of 15 cards
	int i;
	for (i = 0; i < state->numPlayers; i++)
	{
		state->handCount[i] = 5;
		state->deckCount[i] = 5;
		state->discardCount[i] = 5;
	}
	
	int nonCurrPlayerTotalCount = 15, currPlayerTotalCount = 15;
	
	playSmithy(state, 3, player);
	
	for (i = 0; i < state->numPlayers; i++)
	{
		if (i == player)
		{
			// 3 cards should move from deck to hand, 1 discarded from hand
			if (state->handCount[i] != 7 ||
				state->deckCount[i] != 2 ||
				state->discardCount[i] != 5)
			{
				printf("Error: Player 1 did not move 3 cards from deck to hand and discard one from hand\n");
				failCount++;
			}
		}
		else
		{
			// check that no other player's cards were affected
			int currCardCount = (state->handCount[i] + state->deckCount[i] + state->discardCount[i]);
			if (currCardCount != 15)
			{
				printf("Error: Player %d's card count is %d instead of 15\n", i + 1, currCardCount);
				failCount++;
			}
		}
	}
	
	printf("%d tests failed!\n", failCount);
	printf("Testing completed!\n");
	return 0;
}