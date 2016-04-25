// Osbaldo Esquivel
// CS 362
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTNUM 4000

int gardenTest(struct gameState *,int,int);

int main() {
	struct gameState state;
	int val, i = 0, j = 0, pos;

	SelectStream(2);
	PutSeed(3);

	printf("TEST garden BEGINS\n");

	while(i < TESTNUM) {
		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}

		val = floor(Random() * 2);

		state.whoseTurn = val;
		state.deckCount[val] = floor(Random() * MAX_DECK);
		j = 0;
		while(j < state.deckCount[val]) {
			state.deck[val][j] = floor(Random() * 25);
			j++;
		}

		state.handCount[val] = floor(Random() * MAX_HAND);
		j = 0;
		while(j < state.handCount[val]) {
			state.hand[val][j] = floor(Random() * 25);
			j++;
		}

		state.discardCount[val] = floor(Random() * MAX_DECK);
		j = 0;
		while(j < state.discardCount[val]) {
			state.discard[val][j] = floor(Random() * 25);
			j++;
		}

		pos = floor(Random() * state.handCount[val]);
		state.hand[val][pos] = 13;

		gardenTest(&state,pos,val);

		i++;
	}

	printf("TESTS COMPLETED SUCCESSFULLY");

	return 0;
}

int gardenTest(struct gameState *state, int pos, int val) {
	int test;
	struct gameState initial;

	memcpy(&initial,state,sizeof(struct gameState));

	test = cardEffect(gardens,0,0,0,state,pos,0);

	assert(test == -1);

	assert(memcmp(&initial,state,sizeof(struct gameState)) == 0);

	return 0;
}
