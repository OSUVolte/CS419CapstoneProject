#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int testSmithy(struct gameState *state, int handPos){
	printf("Testing Smithy Card.\n");
	struct gameState *testState = newGame();
	memcpy(testState, state, sizeof(struct gameState));

	playSmithy(state, handPos);
	assert(testState->handCount[testState->whoseTurn]+2 == state->handCount[state->whoseTurn]);
	//assert(testState->discardCount[testState->whoseTurn]+1 == state->discardCount[state->whoseTurn]);

	return 0;
}

int  main(){
	int i, k;
	printf("Intializing.\n");
	int players = 2;
	int seed = 433;
	struct gameState *state = newGame();
	int card[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(players, card, seed, state);
	gainCard(8, state, 1, state->whoseTurn);
	testSmithy(state, state->hand[state->whoseTurn][state->handCount[state->whoseTurn]-1]);
	return 0;
}

