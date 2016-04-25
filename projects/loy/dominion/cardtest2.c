// Card test for smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	struct gameState Game;

	int card[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, council_room, great_hall, minion};

	initializeGame(2,card,2,&Game);

	// Player should have 5 cards
	assert(numHandCards(&Game) == 5);
	
	assert(cardEffect(smithy,0,0,0,&Game,0,0) == 0);

	// Player should have 7 cards now; player draws 3 cards and discard the smithy card
	assert(numHandCards(&Game) == 7);

	printf("smithy card test passed\n");

	return 0;
}
