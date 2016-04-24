#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"


int main () {

	printf("Testing Gardens.\n");

	int effect;
	struct gameState G;
	int k[10] = {adventurer, great_hall, embargo, village, minion, duchy, feast,
	       steward, estate, smithy};


	//initialize to 2 players to show hand updates 		
	initializeGame(2, k, 5, &G);

	effect = cardEffect(gardens, 0, 0, 0, &G, 0, 0);
	printf("Function Success Test: "); 
	assert(effect == -1);
	printf("PASSED\n");
	

	printf("Testing complete. All tests passed.\n");
	return 0;
}
