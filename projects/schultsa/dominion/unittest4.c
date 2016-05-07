#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testFullDeckCount(int player, int card, struct gameState *state){
	struct gameState *testState = newGame();
	memcpy(testState, state, sizeof(struct gameState));
	printf("Testing fullDeckCount\n");
	assert(fullDeckCount(player, card, state) == fullDeckCount(player, card, testState));


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
	for(i=0; i<players; i++){
		for(k=0; k<10; k++){
			testFullDeckCount(i, k, state);	
		}
		
	}
	return 0;
}