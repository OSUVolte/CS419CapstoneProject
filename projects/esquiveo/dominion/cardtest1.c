// Osbaldo Esquivel
// CS 362
// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "math.h"

#define TESTNUM 4000

int adventurerTest(struct gameState *,int);
int deckShuffle(struct gameState *, int);

int main() {
	struct gameState state;
	int val, i = 0, j = 0;

	SelectStream(2);
	PutSeed(3);

	printf("TEST adventurerTest() BEGINS\n");

	while(i < TESTNUM) {
		SelectStream(3);

		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}
		
		val = floor(Random() * 2);

		state.deckCount[val] = floor(Random() * MAX_DECK);
		state.playedCardCount = floor(Random() * MAX_DECK);
		state.discardCount[val]	= floor(Random() * MAX_HAND);
		state.handCount[val] = floor(Random() * MAX_HAND);
		state.whoseTurn = val;

		deckShuffle(&state,val);

		adventurerTest(&state,val);

		i++;
	}

	printf("TEST COMPLETED SUCCESSFULLY\n");

	return 0;
}

int adventurerTest(struct gameState *state, int val) {
	int pos = floor(Random() * state->handCount[val]), temp = 0,
	    numTreasure = 0, test, card, handTest[MAX_HAND];
	struct gameState initial;

	SelectStream(2);
	PutSeed(3);

	memcpy(&initial,state,sizeof(struct gameState));

	test = cardEffect(adventurer,0,0,0,state,pos,0);

	PutSeed(3);

	while(numTreasure < 2) {
		if(initial.discardCount[val] == 0 && initial.deckCount[val] == 0) {
				assert(test == -1);
				return 1;
		}

		drawCard(val,&initial);

		card = initial.hand[val][initial.handCount[val]-1];

		if(card == silver || card == gold || card == copper) {
			numTreasure = numTreasure + 1;
		}
		else {
			handTest[temp] = card;
			initial.handCount[val] = initial.handCount[val] - 1;
			temp = temp + 1;
		}
	}

	while(temp-1 >= 0) {
		initial.discard[val][initial.discardCount[val]++] = handTest[temp - 1];
		temp = temp - 1;
	}
	
	discardCard(pos,val,&initial,0);

	assert(test == 0);
	assert(memcmp(&initial,state,sizeof(struct gameState)) == 0);
	
	return 0;
}

int deckShuffle(struct gameState *state, int val) {
	int i = 0;

	if(state == NULL) {
		return -1;
	}

	while(i < state->deckCount[val]) {
		state->deck[val][i] = floor(Random() * 27);
		i++;
	}

	i = 0;
	while(i < state->playedCardCount) {
		state->playedCards[i] = floor(Random() * 27);
		i++;
	}

	i = 0;
	while(i < state->handCount[val]) {
		state->hand[val][i] = floor(Random() * 27);
		i++;
	}

	i = 0;
	while(i < state->discardCount[val]) {
		state->discard[val][i] = floor(Random() * 27);
		i++;
	}

	return 1;
}
