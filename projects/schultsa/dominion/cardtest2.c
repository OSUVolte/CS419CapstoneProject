#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int testAdventurer(struct gameState *state){
	struct gameState *testState = newGame();
	memcpy(testState, state, sizeof(struct gameState));
	printf("Testing Adventurer.\n");

	playAdventurer(state);
	assert((testState->handCount[testState->whoseTurn])+2 == state->handCount[state->whoseTurn]);
	//assert(state->discardCount[state->whoseTurn] > 1);
	//assert(state->coins > testState->coins);
	return 0;
}

int main(){
	int i, k;
	printf("Intializing.\n");
	int players = 2;
	int seed = 433;
	struct gameState *state = newGame();
	int card[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(players, card, seed, state);
	testAdventurer(state);
	return 0;
}