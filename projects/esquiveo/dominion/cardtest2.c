// Osbaldo Esquivel
// CS 362
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTNUM 10000

int smithyTest(struct gameState *,int,int);

int main() {
	struct gameState state;
	int val, pos, i = 0, j = 0;

	SelectStream(2);
	PutSeed(3);

	printf("TEST smithy BEGINS\n");

	while(i < TESTNUM) {
		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}

		val = floor(Random() * MAX_PLAYERS);

		state.handCount[val] = floor(Random() * MAX_HAND);
		state.deckCount[val] = floor(Random() * MAX_DECK);
		state.discardCount[val] = floor(Random() * MAX_DECK);
	
		pos = floor(Random() * state.handCount[val]);

		smithyTest(&state,pos,val);

		i++;
	}

	printf("TESTS COMPLETED SUCCESSFULLY\n");

	return 0;
}

int smithyTest(struct gameState *state, int pos, int val) {
	struct gameState initial;
	int test, i = 0;

	memcpy(&initial,state,sizeof(struct gameState));

	test = cardEffect(smithy,0,0,0,state,pos,0);

	while(i < 2) {
		drawCard(val,&initial);
		i++;
	}

	discardCard(pos,val,&initial,0);

	assert(memcmp(&initial,state,sizeof(struct gameState)) == 0);
	assert(test == 0);

	return 0;
}
