// Osbaldo Esquivel
// CS 362
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTNUM 4000

int fullDeckCountTest(int,int,struct gameState *);

int main() {
	struct gameState state;
	int i = 0, j = 0, val, tempCard;

	SelectStream(2);
	PutSeed(3);

	printf("TEST fullDeckCount() BEGIN\n");

	while(i < TESTNUM) {
		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}
		

		val = floor(Random() * 4);

		state.whoseTurn = val;
		state.deckCount[val] = floor(Random() * MAX_DECK);
		state.discardCount[val] = floor(Random() * MAX_DECK);
		state.handCount[val] = floor(Random() * MAX_DECK);

		tempCard = floor(Random() * 26);

		fullDeckCountTest(tempCard,val,&state);

		i++;
	}

	printf("TEST COMPLETED SUCCESSFULLY\n");

	return 0;
}

int fullDeckCountTest(int c, int play, struct gameState *state) {
	int countReal = 0, countTemp = 0, i = 0;

	while(i < state->deckCount[play]) {
		if(state->deck[play][i] == c) {
			countReal = countReal + 1;
		}
		i++;
	}
	i = 0;
	while(i < state->handCount[play]) {
		if(state->hand[play][i] == c) {
			countReal = countReal + 1;
		}
		i++;
	}
	i = 0;
	while(i < state->discardCount[play]) {
		if(state->discard[play][i] == c) {
			countReal = countReal + 1;
		}
		i++;
	}

	countTemp = fullDeckCount(play,c,state);;

	assert(countReal == countTemp);

	return 0;
}
