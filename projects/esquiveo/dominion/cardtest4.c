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

int villageTest(struct gameState *,int);

int main() {
	struct gameState state;
	int val, i = 0, j = 0;

	SelectStream(2);
	PutSeed(3);

	printf("TEST village BEGINS\n");

	while(i < TESTNUM) {
		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}
	
		val = floor(Random() * MAX_PLAYERS);

		state.whoseTurn = val;
		state.handCount[val] = floor(Random() * MAX_HAND);
		state.deckCount[val] = floor(Random() * MAX_DECK);
		state.playedCardCount = floor(Random() * MAX_DECK);
		state.discardCount[val] = floor(Random() * MAX_HAND);

		villageTest(&state,val);
	
		i++;
	}

	printf("TESTS COMPLETED SUCCESSFULLY");

	return 0;
}

int villageTest(struct gameState *state, int play) {
	struct gameState initial;
	int pos, test;

	pos = floor(Random() * state->handCount[play]);

	memcpy(&initial,state,sizeof(struct gameState));

	SelectStream(2);
	PutSeed(3);

	test = cardEffect(village,0,0,0,state,pos,0);

	drawCard(play,&initial);

	discardCard(pos,play,&initial,0);

	assert(memcmp(&initial,state,sizeof(struct gameState)) == 0);
	assert(test == 0);

	return 0;
}
			
	
