// Unit test for initializeGame() function

#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	struct gameState Game;

	// Just listing random 10 cards
	int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};

	int i = initializeGame(2,card,2,&Game);

	assert(i == 0);

	printf("initializeGame unit test passed\n");

	return 0;
}