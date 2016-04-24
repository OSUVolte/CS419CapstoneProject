//gainCard() unit test

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
	struct gameState state;
	int x;

		printf("------gainCard unit test-------\n");

	/***************** Supply pile is empty ***************/
	state.supplyCount[copper] = 0;

	x = gainCard(copper, &state, 0, 1);

	if (x == -1) {
		printf("gainCard: PASS when supply pile is empty\n");
	}
	else {
		printf("gainCard: FAIL when supply pile is empty\n");
	}

	/*******************Add to deck********************/
	state.supplyCount[copper] = 10;
	state.deckCount[1] = 5;

	x = gainCard(copper, &state, 1, 1);

	if(x != -1 && state.deck[1][5] == copper && state.deckCount[1] == 6 && state.supplyCount[copper] == 9) {
		printf("gainCard: PASS when added to deck\n");
	}
	else {
		printf("gainCard: FAIL when added to deck\n");
	}

	/****************** Add to  hand *********************/
	state.supplyCount[copper] = 10;
	state.handCount[1] = 5;

	x = gainCard(copper, &state, 2, 1);

	if(x != -1 && state.hand[1][5] == copper && state.handCount[1] == 6 && state.supplyCount[copper] == 9) {
		printf("gainCard: PASS when added to hand\n");
	}
	else {
		printf("gainCard: FAIL when added to hand\n");
	}

	/**************** Add to discard ******************/
	state.supplyCount[copper] = 10;
	state.discardCount[1] = 5;

	x = gainCard(copper, &state, 0, 1);

	if(x != -1 && state.discard[1][5] == copper && state.discardCount[1] == 6 && state.supplyCount[copper] == 9) {
		printf("gainCard: PASS when added to discard\n\n");
	}
	else {
		printf("gainCard: FAIL when added to discard\n\n");
	}

	return 0;
}