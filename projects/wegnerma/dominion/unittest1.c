//updateCoins() unit test

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
	struct gameState state;
	int i;

	printf("------updateCoins unit test-------\n");

	state.handCount[1] = 5;

	/********* No coins in hand ************/
	for (i = 0; i < 5; i++ ) {
		state.hand[1][i] = smithy;
	}

	updateCoins(1, &state, 0);

	if (state.coins == 0) {
		printf("updateCoins: PASS when no coins in hand.\n");
	}
	else {
		printf("updateCoins: FAIL when no coins in hand.\n");
	}


	/********** 5 copper cards **********/
	for (i=0; i < 5; i++) {
		state.hand[1][i] = copper;
	}

	updateCoins(1, &state, 0);

	if (state.coins == 5) {
		printf("updateCoins: PASS when 5 coppper coins in hand.\n");
	}
	else {
		printf("updateCoins: FAIL when 5 copper coins in hand.\n");
	}


	/********** 5 silver cards **********/
	for (i=0; i < 5; i++) {
		state.hand[1][i] = silver;
	}

	updateCoins(1, &state, 0);

	if (state.coins == 10) {
		printf("updateCoins: PASS when 5 silver coins in hand.\n");
	}
	else {
		printf("updateCoins: FAIL when 5 silver coins in hand.\n");
	}


	/********** 5 gold cards **********/
	for (i=0; i < 5; i++) {
		state.hand[1][i] = gold;
	}

	updateCoins(1, &state, 0);

	if (state.coins == 15) {
		printf("updateCoins: PASS when 5 gold coins in hand.\n");
	}
	else {
		printf("updateCoins: FAIL when 5 gold coins in hand.\n");
	}


	/************ 5 copper cards and bonus of 5 *************/
	for (i=0; i < 5; i++) {
		state.hand[1][i] = copper;
	}

	updateCoins(1, &state, 5);

	if (state.coins == 10) {
		printf("updateCoins: PASS when 5 copper coins in hand and bonus=5.\n");
	}
	else {
		printf("updateCoins: FAIL when 5 copper coins in hand and bonus=5.\n");
	}


	/********* No coins in hand and bonus=5************/
	for (i = 0; i < 5; i++ ) {
		state.hand[1][i] = smithy;
	}

	updateCoins(1, &state, 5);

	if (state.coins == 5) {
		printf("updateCoins: PASS when no coins in hand and bonus=5.\n");
	}
	else {
		printf("updateCoins: FAIL when no coins in hand and bonus=5.\n");
	}


	/********* hand of coin and non-coin cards **************/
	state.hand[1][0] = estate;
	state.hand[1][1] = copper;
	state.hand[1][2] = silver;
	state.hand[1][3] = smithy;
	state.hand[1][4] = gold;

	updateCoins(1, &state, 0);

	if (state.coins == 6) {
		printf("updateCoins: PASS when coin and non-coin cards.\n\n");
	}
	else {
		printf("updateCoins: FAIL when coin and non-coin cards.\n\n");
	}

	return 0;
}