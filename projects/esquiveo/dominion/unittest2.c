// Osbaldo Esquivel
// CS 362
// Assignment 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "math.h"

#define TESTNUM 4000

int shuffleTest(struct gameState *,int);

int main() {
	struct gameState state;
	int val, i = 0, j = 0;
	
	SelectStream(2);
	PutSeed(3);

	printf("TEST shuffle() BEGINS\n");
	
	while(i < TESTNUM) {
		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}
		
		val = floor(Random() * 2);
		
		state.handCount[val] = floor(Random() * MAX_HAND);
		state.deckCount[val] = floor(Random() * MAX_DECK);
		state.discardCount[val]  = floor(Random() * MAX_DECK);
		
		j = 0;
		while(j < state.handCount[val]) {
			state.hand[val][j] = (int)(Random() * MAX_HAND);
			j++;
		}
		j = 0;
		while(j < state.deckCount[val]) {
			state.deck[val][j] = (int)(Random() * MAX_DECK);
			j++;
		}
		j = 0;
		while(j < state.discardCount[val]) {
			state.discard[val][j] = (int)(Random() * MAX_DECK);
			j++;
		}
		
		i++;
	}

	printf("TESTS COMPLETED SUCCESSFULLY\n");

	return 0;
}

int shuffleTest(struct gameState *state, int val) {
	struct gameState initial;
	int test, temp;
	
	memcpy(&initial,state,sizeof(struct gameState));
	
	if(initial.deckCount[val] < 1) {
		temp = -1;
	}
	else {
		temp = 0;
	}
	
	test = shuffle(val,state);
	
	assert(test == temp);
	
	return 0;
}
	 
				
	
