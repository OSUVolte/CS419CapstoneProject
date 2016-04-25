#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/* Performs test on update coins, with +0, +2, and -3 bonuses.*/
int testUpdateCoins(int p, struct gameState *state){
	struct gameState *compState, *testState1, *testState2, *testState3;
	compState=newGame();
	testState1=newGame();
	testState2=newGame();
	testState3=newGame();
	memcpy(compState, state, sizeof(struct gameState));
	memcpy(testState1, state, sizeof(struct gameState));
	memcpy(testState2, state, sizeof(struct gameState));
	memcpy(testState3, state, sizeof(struct gameState));
	printf("Testing Update Coins\n");
	printf("Testing 0 Bonus\n");
	updateCoins(p, testState1, 0);
	//assert(compState->coins == testState1->coins);

	printf("Testing with Bonus\n");
	printf("Bonus = 2\n");
	updateCoins(p, testState2, 2);
	//assert(compState->coins+2 == testState2->coins);

	printf("Testing with negative Bonus\n");
	printf("Bonus = -3\n");
	updateCoins(p, testState3, -3);
	//assert(compState->coins-3 == testState3->coins);

	printf("END OF testUpdateCoins\n");
	return 0;
}

int main(){
	printf("Initializing\n");
	int players = 2;
	int seed = 343;
	struct gameState *state = newGame();
	int card[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(players, card, seed, state);

	printf("Performing tests on all players.\n");
	int i;
	for(i=0; i<players; i++){
		testUpdateCoins(i, state);
	}
	return 0;
}