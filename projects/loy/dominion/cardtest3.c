// Card test for great hall

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

	assert(cardEffect(great_hall,0,0,0,&Game,0,0) == 0);

	// Player now should have 5 (or 6 cards? this is the one I'm confused on);
	// draws 1 additional card, but this counts as a victory card...
	assert(numHandCards(&Game) == 5);
	// Player now should have +1 action
	assert(Game.numActions == 1);

	printf("Great Hall card test passed\n");

	return 0;
}
