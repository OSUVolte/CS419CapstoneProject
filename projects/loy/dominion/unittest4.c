// Unit test for numHandCards() function

#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	struct gameState Game;

	int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};

	initializeGame(2,card,2,&Game);

	int i = numHandCards(&Game);

	// Each player should have 5 cards
	assert(i == 5);

	printf("numHandCards unit test passed\n");

	return 0;
}