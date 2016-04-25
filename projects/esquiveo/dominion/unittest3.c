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
#include "interface.h"
#include "rngs.h"

#define TESTNUM 4000

int numHandCardsTest(struct gameState *);

int main() {
	int checkComplete = 0, check = 0, tempArray[3], i = 0, j = 0,
	    ii = 0, jj = 0, val;
	struct gameState state;

	SelectStream(2);
	PutSeed(3);

	printf("TEST numHandCards() BEGIN\n");

	while(i < TESTNUM) {
		while(j < sizeof(struct gameState)) {
			((char *)&state)[j] = floor(Random() * 256);
			j++;
		}

		val = floor(Random() * 2) + 2;

		while(j < val) {
			while(ii < 500) {
				state.hand[j][ii] = floor(Random() * 26);
				ii++;
			}
			while(jj < 3) {
				tempArray[i] = floor(Random() * 500);
				jj++;
			}
	
			state.deckCount[j] = tempArray[0];
			state.handCount[j] = tempArray[1];
			j++;
		}
		
		state.numPlayers = val;
		state.whoseTurn = floor(Random() * val);

		if(numHandCardsTest(&state) == 0) {
			check = check + 1;
		}

		i++;
	}

	checkComplete = check;

	printf("Passed: %d/%d\n",checkComplete,TESTNUM);
	printf("TESTS PASSED SUCCESSFULLY\n");

	return 0;
}

int numHandCardsTest(struct gameState *state) {
	struct gameState initial;
	
	memcpy(&initial,state,sizeof(struct gameState));

	if(numHandCards(state) != initial.handCount[initial.whoseTurn]
		|| memcmp(&initial,state,sizeof(struct gameState)) != 0) {
			return -1;
	}

	return 0;
}
