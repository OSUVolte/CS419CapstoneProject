// Card test for adventurer

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
	int bonus;

	initializeGame(2,card,1,&Game);

	assert(cardEffect(adventurer,0,0,0,&Game,0,&bonus) == 0);

	printf("Adventurer card test passed\n");

	return 0;
}