// Card test for village

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
	initializeGame(2,card,1,&Game);

	Game.numActions = 0;

	// Player should have 5 cards
	assert(numHandCards(&Game) == 5);
	// Player should have 0 actions
	assert(Game.numActions == 0);

	assert(cardEffect(village,0,0,0,&Game,0,0) == 0);

	// Player should still have 5 cards; draws 1 additional card, but discard the village card
	assert(numHandCards(&Game) == 5);
	// Player now should have +2 actions
	assert(Game.numActions == 2);

	printf("Village card test passed\n");

	return 0;
}
