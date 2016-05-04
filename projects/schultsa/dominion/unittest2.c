#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


  //added card for [whoseTurn] current player:
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand

int testGainCard(int supplyPos, struct gameState *state, int toFlag, int player){
	 printf("Begining testGainCard.\n");
	 struct gameState *testState = newGame();
	 memcpy(testState, state, sizeof(struct gameState));
	 switch(toFlag){
	 		case 0: 
	 			printf("Testing Discard count.\n");
	 			gainCard(supplyPos, state, toFlag, player);
	 			assert(testState->discardCount[player]+1 == state->discardCount[player]);
	 			break;
	 		case 1:
	 			printf("Testing add to deck.\n");
	 			gainCard(supplyPos, state, toFlag, player);
	 			assert(testState->deckCount[player]+1 == state->deckCount[player]);
	 			break;
	 		case 2:
	 			printf("Testing add to hand.\n");
	 			gainCard(supplyPos, state, toFlag, player);
	 			assert(testState->handCount[player]+1 == state->handCount[player]);
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
		for(k=0; k<3; k++){
			testGainCard(1, state, k, i);
		}
	}
	return 0;
}