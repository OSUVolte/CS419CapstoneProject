#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int isAdventurerValid(struct gameState * state, int player, int prevHandCount, int prevDeckCount);

int main(){
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int players, player, handCount, deckCount, seed, handPos, coinBonus, result, i;
	struct gameState state;
	int tests = 100;

	srand(time(NULL));

	printf("STARTED: Running random Adventurer Card test\n");

	for(i = 0; i < tests; i++){
		// set up loop veriables for each test run
		players = rand() % (MAX_PLAYERS - 2) + 2;
		seed = rand();
		coinBonus = 0;
		handPos = rand() % 4;
		player = i % (players);

		// initialize the game state
		initializeGame(players, k, seed, &state);

		// take care of game state variables
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;

		// transfer variables for comparison
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];

		// run card effect
		cardEffect(adventurer, 1, 1, 1, &state, handPos, &coinBonus);
		
		// make sure the effect is valid
		result = isAdventurerValid(&state, player, handCount, deckCount);

		assert(result == 1);    	
	}
 	
	printf("Test Complete: ran 100 tests with SUCCESS\n");
	
	return 0;
}

int isAdventurerValid(struct gameState * state, int player, int prevHandCount, int prevDeckCount){
	// make sure that the hand count is great after drawing adventurer
	if(state->handCount[player] < prevHandCount){
		printf("Test Failure: hand count is not greater after drawing adventurer\n");
		printf("handCount before: %d \nhandCount after: %d\n", prevHandCount, state->handCount[player]);
		return 0;
	}
	 
	// make sure that the deck is smaller than before adventurer
	else if(state->deckCount[player] > prevDeckCount && prevDeckCount != 0){
		printf("Test Failure: deck count is not smaller than after drawing adventurer\n");
		printf("deckCount before: %d \ndeckCount after: %d\n", prevDeckCount, state->deckCount[player]);
		return 0;
	}
	return 1;
}


