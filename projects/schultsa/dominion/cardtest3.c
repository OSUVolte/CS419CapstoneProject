#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int testRemodel(struct gameState *state, int handPos, int choice1, int choice2){
	struct gameState *testState = newGame();
	memcpy(testState, state, sizeof(struct gameState));
	printf("Testing Remodel.\n");
	playRemodel(state, handPos, choice1, choice2);
	assert(state->playedCardCount == testState->playedCardCount+1);
	//assert(state->discardCount[state->whoseTurn] == testState->discardCount[testState->whoseTurn]+2);
	return 0;

}









int main(){
	
	printf("Intializing.\n");
	int players = 2;
	int seed = 433;
	struct gameState *state = newGame();
	int card[10] = {adventurer, remodel, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(players, card, seed, state);
	state->hand[state->whoseTurn][1] = remodel;
	state->hand[state->whoseTurn][2] = adventurer;
	testRemodel(state, 1, 2, 3);
	return 0;
}