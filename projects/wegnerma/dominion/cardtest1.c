//playAdventurer() unit test

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
	struct gameState state;
	int i;

	printf("------playAdventurer unit test-------\n");

	//set up counts, hand, and whose turn
	state.deckCount[1] = 10;
	state.handCount[1] = 1;
	state.hand[1][0] = adventurer;
	state.whoseTurn = 1;

	/************* two treasures in deck ************/
	//set deck cards
	for (i = 0; i < 8; i++) {
		state.deck[1][i] = smithy;
	}
	for (i = 8; i < 10; i++) {
		state.deck[1][i] = copper;
	}

	playAdventurer(&state, 0); //play

	//PASS or FAIL
	//Pass if hand contains two copper treasures
	if (state.handCount[1] == 2 && state.hand[1][0] == copper && state.hand[1][1] == copper) {
		printf("playAdventurer: PASS when two treasures are in deck\n");
	}
	else {
		printf("playAdventurer: FAIL when two treasures are in deck\n");
	}

	/************** cards have to be reshuffled ***************/
	//set up counts, hand, and whose turn
	state.discardCount[1] = 10;
	state.deckCount[1] = 0;
	state.handCount[1] = 1;
	state.hand[1][0] = adventurer;
	state.whoseTurn = 1;

	//set discard cards
	for (i = 0; i < 8; i++) {
		state.discard[1][i] = estate;
	}
	for (i = 8; i < 10; i++) {
		state.discard[1][i] = silver;
	}

	playAdventurer(&state, 0); //play

	//PASS or FAIL
	//Pass if hand contains two silver treasures
	if (state.handCount[1] == 2 && state.hand[1][0] == silver && state.hand[1][1] == silver) {
		printf("playAdventurer: PASS when cards have to be reshuffled\n");
	}
	else {
		printf("playAdventurer: FAIL when cards have to be reshuffled\n");
	}

	/*************** no tresure in deck, must shuffle discard **********/
	//set up counts, hand, and whose turn
	state.discardCount[1] = 10;
	state.deckCount[1] = 3;
	state.handCount[1] = 1;
	state.hand[1][0] = adventurer;
	state.whoseTurn = 1;

	//set discard cards
	for (i = 0; i < 8; i++) {
		state.discard[1][i] = estate;
	}
	for (i = 8; i < 10; i++) {
		state.discard[1][i] = gold;
	}

	//set deck cards
	for (i = 0; i < 3; i++) {
		state.deck[1][i] = village;
	}

	playAdventurer(&state, 0); //play

	//PASS or FAIL
	//Pass if hand contains two gold treasures	
	if (state.handCount[1] == 2 && state.hand[1][0] == gold && state.hand[1][1] == gold) {
		printf("playAdventurer: PASS when cards in deck and then have to be reshuffled\n\n");
	}
	else {
		printf("playAdventurer: FAIL when cards in deck and then have to be reshuffled\n\n");
	}

	return 0;
}
