//discardCard() unit test

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
	struct gameState state;
	int x;

	printf("------discardCard unit test-------\n");

	state.handCount[1] = 5;

	state.hand[1][0] = copper;
	state.hand[1][1] = silver;
	state.hand[1][2] = estate;
	state.hand[1][3] = smithy;
	state.hand[1][4] = gold;


	/************* card = last card in hand ****************/
	x = discardCard(4, 1, &state, 1);

	if (x != -1 && state.handCount[1] == 4 && state.hand[1][4] == -1) {
		printf("discardCard: PASS when last card in hand array\n");
	}
	else {
		printf("discardCard: FAIL when last card in hand array\n");
	}

	/************* card = first card in hand ****************/
	state.handCount[1] = 5;

	state.hand[1][0] = copper;
	state.hand[1][1] = silver;
	state.hand[1][2] = estate;
	state.hand[1][3] = smithy;
	state.hand[1][4] = gold;

	x = discardCard(0, 1, &state, 1);

	if (x != -1 && state.handCount[1] == 4 && state.hand[1][4] == -1 
		&& state.hand[1][0] == gold) {
		printf("discardCard: PASS when first card in hand array\n");
	}
	else {
		printf("discardCard: FAIL when first card in hand array\n");
	}	

	/************** only one card in hand *****************/
	state.handCount[1] = 1;
	state.hand[1][0] = copper;

	x = discardCard(0, 1, &state, 1);

	if (x != -1 && state.hand[1][0] == -1 && state.handCount[1] == 0) {
		printf("discardCard: PASS when one card in hand\n");
	}
	else {
		printf("discardCard: FAIL when one card in hand\n");
	}


	/************* card is not trashed ********************/
	state.handCount[1] = 5;

	state.hand[1][0] = copper;
	state.hand[1][1] = silver;
	state.hand[1][2] = estate;
	state.hand[1][3] = smithy;
	state.hand[1][4] = gold;

	state.playedCardCount = 0;

	x = discardCard(4, 1, &state, 0);

	if (x != -1 && state.playedCardCount == 1 && state.playedCards[0] == gold) {
		printf("discardCard: PASS when card trashed\n\n");
	}
	else {
		printf("discardCard: FAIL when card trashed\n\n");
	}

	return 0;
}