// Unit test for whoseTurn() function

#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	struct gameState Game;

	int turn = 1;
	int i = 0;

	while(turn <= 20)
	{
		Game.whoseTurn = turn;
		i = whoseTurn(&Game);

		assert(i == turn);
		turn++;
	}

	printf("whoseTurn unit test passed\n");

	return 0;
}