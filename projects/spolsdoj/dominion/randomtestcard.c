#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int isVillageValid(struct gameState * state, int player, int prevActions, int prevDeckCount);

int main(){
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int result, players, player, handCount, deckCount, numActions, seed, handPos, coinBonus, i;
	struct gameState state;
	int tests = 1000;

	srand(time(NULL));

	printf("STARTED: Running random Village card test.\n");

	for(i=0; i < tests; i++){
		players = rand() % (MAX_PLAYERS - 2) + 2;
		seed = rand();
		coinBonus = 0;
		handPos = rand() % 4;
		player = i % (players + 1);

		// set up game state
		initializeGame(players, k, seed, &state);

		// set up game state variables
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;

		// copy state variables for test comparison
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];
		numActions = state.numActions;

		// run card effect
		cardEffect(village, 1, 1, 1, &state, handPos, &coinBonus);

		// make sure the result is valid
		result = isVillageValid(&state, player, numActions, deckCount);
		assert(result == 1); 	      
	}
	printf("Test Complete: ran %d tests with SUCCESS!\n", tests);
	
	return 0;
}

int isVillageValid(struct gameState * state, int player, int prevActions, int prevDeckCount){
	// test to see if the deck count is smaller than before villiage
	if(state->deckCount[player] > prevDeckCount && prevDeckCount != 0){
		printf("Test Failure: deck count is not smaller than before\n");
		printf("deckCount before: %d \ndeckCount after: %d\n", prevActions, state->numActions);
	}
	else if(state->numActions != prevActions + 2){
		printf("Test Failure: actions are not two larger than before card\n");
		printf("numActions before: %d \nnumActions after: %d\n", prevActions, state->numActions);
	}
	return 1;	 
} 
