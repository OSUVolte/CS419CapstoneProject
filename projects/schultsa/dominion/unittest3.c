#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int testDiscardCard(int handPos, int player, struct gameState *state, int trashFlag){
	printf("Testing discardCard\n");
	struct gameState *testState = newGame();
	memcpy(testState, state, sizeof(struct gameState));
	switch(trashFlag){
		case 0:
			printf("Testing trashFlag = 0\n");
			discardCard(handPos, player, state, trashFlag);
			assert(testState->handCount[player]-1 == state->handCount[player]);
			assert(testState->playedCardCount+1 == state->playedCardCount);
			break;
		case 1:
			printf("Testing trashFlag = 1\n");
			discardCard(handPos, player, state, trashFlag);
			assert(testState->handCount[player]-1 == state->handCount[player]);
			assert(testState->playedCardCount == state->playedCardCount);
			break;
	}
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
		for(k=0; k<2; k++){
			testDiscardCard(1, i, state, k);
		}	
	}
	return 0;
}