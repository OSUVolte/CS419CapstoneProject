//playSmithy() unit test

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main() {
	struct gameState state;
	int i;

	printf("------playSmithy unit test-------\n");

	state.whoseTurn = 1; //set whose turn

	//set up hand count and hand
	state.handCount[1] = 1;
	state.hand[1][0] = smithy;

	//played count
	state.playedCardCount = 0;

	/*************** With cards in deck ****************/
	//set up deck count and deck
	state.deckCount[1] = 4;
	for (i = 0; i < 4; i++) {
		state.deck[1][i] = copper;
	}

	playSmithy(&state, 0); //play

	//PASS or FAIL
	//Pass if 3 cards added to hand, smithy discarded, and 
	//deck decremented
	if (state.handCount[1] == 3  && state.playedCards[0] == smithy && state.deckCount[1] == 1) {
		printf("playSmithy: PASS when cards are in deck\n");
	}
	else {
		printf("playSmithy: FAIL when cards are in deck\n");
	}

	/************* With no cards in deck ***************/
	//set up hand and count
	state.handCount[1] = 1;
	state.hand[1][0] = smithy;

	//played count
	state.playedCardCount = 0;

	//deck count =  0
	state.deckCount[1] = 0;

	//set up discard and count
	state.discardCount[1] = 4;
	for (i = 0; i < 4; i++) {
		state.discard[1][i] = estate;
	}

	playSmithy(&state,0); //play

	//PASS or FAIL
	//Pass if 3 cards added to hand, smith discarded, and remaining card
	//in deck
	if (state.handCount[1] == 3 && state.playedCards[0] == smithy && state.deckCount[1] == 1) {
		printf("playSmithy: PASS when cards are not in deck\n\n");
	}
	else {
		printf("playSmithy: FAIL when cards are not in deck\n\n");
	}

	return 0;
}