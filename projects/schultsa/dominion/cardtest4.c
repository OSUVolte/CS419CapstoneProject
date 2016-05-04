#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int testVillage(struct gameState *state, int handPos){
	struct gameState *testState = newGame();
	memcpy(testState, state, sizeof(struct gameState));
	printf("Testing Village.\n");
	playVillage(state, handPos);
	assert(state->numActions == testState->numActions+2);
	//assert(state->discardCount[state->whoseTurn] == testState->discardCount[testState->whoseTurn]+1);
	return 0;
}













int main(){
	
	printf("Intializing.\n");
	int players = 2;
	int seed = 433;
	struct gameState *state = newGame();
	int card[10] = {adventurer, remodel, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(players, card, seed, state);
	state->hand[state->whoseTurn][1] = village;
	
	testVillage(state, 1);
	return 0;
}