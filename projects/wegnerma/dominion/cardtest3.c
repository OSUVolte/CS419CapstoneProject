//playVillage() unit test

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
	struct gameState state;
	state.whoseTurn = 1;
	int i;

	printf("------playVillage unit test-------\n");

	//set up hand
	state.handCount[1] = 1;
	state.hand[1][0] = village;

	//set up deck
	state.deckCount[1] = 3;
	for (i = 0; i < 3; i++) {
			state.deck[1][i] = copper;
	}

	state.numActions = 0;

	state.playedCardCount = 0;

	playVillage(&state, 0); //play

	/****************Add actions*************/
	//PASS or FAIL
	//Pass if 2 actions are added to numActions
	if (state.numActions == 2) {
		printf("playVillage: PASS add actions\n");
	}
	else {
		printf("playVillage: FAIL add actions\n");
	}

	/***************Discard card *************/
	//PASS or FAIL
	//Pass if card is discarded and in playedCards
	if (state.playedCards[0] == village && state.playedCardCount == 1) {
		printf("playVillage: PASS discard card\n");
	}
	else {
		printf("playVillage: FAIL discard card\n");
	}

	/*************Draws card ****************/
	//PASS or FAIL
	//Passes if hand count == hand count before action
	if (state.handCount[1] == 1) {
		printf("playVillage: PASS draw card\n\n");
	}
	else {
		printf("playVillage: FAIL draw card\n\n");
	}

	return 0;
}