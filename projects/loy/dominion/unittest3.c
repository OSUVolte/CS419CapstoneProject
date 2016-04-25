// Unit test for isGameOver() function

#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	struct gameState Game;

	int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};
	int i;

	initializeGame(2,card,2,&Game);

	Game.supplyCount[province] = 0;

	i = isGameOver(&Game);

	assert(i == 1);

	printf("isGameOver unit test passed\n");

	return 0;
}