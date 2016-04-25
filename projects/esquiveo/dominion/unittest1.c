// Osbaldo Esquivel
// CS 362
// Assignment 3

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

#define TESTNUM 4000

int isGameOverTest(struct gameState *);

int main() {
	struct gameState state;
	int val, i = 0, j = 0;
	
	SelectStream(2);
	PutSeed(3);
	
	printf("TEST isGameOver() BEGINS\n");

	while(i < TESTNUM) {
		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}
		
		val = floor(Random() * 2);
		
		state.discardCount[val] = floor(Random() * MAX_DECK);
		state.deckCount[val] = floor(Random() * MAX_DECK);
		state.handCount[val] = floor(Random() * MAX_HAND);
		
		j = 0;
		while(j < treasure_map) {
			state.supplyCount[j] = floor(Random() * 50);
			j++;
		}
	
		i++;
	}	
	
	printf("TESTS COMPLETED SUCCESSFULLY");
		
	return 0;
}	

int isGameOverTest(struct gameState *state) {
	struct gameState initial;
	int end, supplyOut, test, i = 0;
	
	memcpy(&initial,state,sizeof(struct gameState));
	
	while(i < 25) {
		initial.supplyCount[i] = floor(Random() * 12);
		
		if(initial.supplyCount[i] == 0) {
			supplyOut = supplyOut + 1;
		}
		i++;
	}
	
	if(initial.supplyCount[province] == 0) {
		end = 1;
	}
	else if(supplyOut >= 3) {
		end = 1;
	}
	else {
		end = 0;
	}
	
	test = isGameOver(state);
	
	assert(test == end);
	
	return 0;
}
