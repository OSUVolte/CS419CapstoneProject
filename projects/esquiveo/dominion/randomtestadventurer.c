// Osbaldo Esquivel
// CS 362
// 03MAY2016

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUMTESTS 4000

/*
 * This program will randomly test the adventurer card by running
 * a user-defined number of tests. The state of the game will be
 * randomized and then the results of the test function will be compared
 * to expected results.
 */

int testAdventurer(struct gameState *, int);

int main() {
	struct gameState game;
	int val, i, j;

	// set rngs variables	
	SelectStream(2);
	PutSeed(3);
	
	printf("Test begins for adventurer\n");
	
	// run user-defined number of tests
	for(i = 0; i < NUMTESTS; i++) {
		// randomize game state
		for(j = 0; j < sizeof(struct gameState); j++) {
			((char *)&game)[j] = floor(Random() * 256);
		}
		
		// set random number of players
		val = floor(Random() * 2);
		
		// set game state to random values
		game.discardCount[val] = floor(Random() * MAX_HAND);
		game.handCount[val] = floor(Random() * MAX_HAND);
		game.playedCardCount = floor(Random() * MAX_DECK);
		game.deckCount[val] = floor(Random() * MAX_DECK);
		game.whoseTurn = val;
		
		// send game state and random value to test function
		testAdventurer(&game, val);
	}
	
	printf("All tests completed for adventurer.\n");
	
	return 0;
}

// this function runs the actual test for the adventurer card
// and will utilize several assert statements to check expected
// vs actual values
int testAdventurer(struct gameState *g, int val) {
	struct gameState start;
	int testHand[MAX_HAND], tempCard, testVal, temp = 0, pos, numTreasure = 0;
	
	// set random hand position
	pos = floor(Random() * g->handCount[val]);
	
	// copy state of game to initial state
	memcpy(&start, g, sizeof(struct gameState));
	
	// set testVal to value returned by cardEffect
	// for the adventurer card
	testVal = cardEffect(adventurer,0,0,0,g,pos,0);
	
	// as long as treasure is less than two, continue to draw
	// a card
	while(numTreasure < 2) {
		// make sure the deck card count is valid
		if(start.deckCount[val] == 0 && start.discardCount[val] == 0) {
			assert(testVal == -1);
			return 1;
		}
		
		// draw a card
		drawCard(val,&start);
		
		// set a temp card
		tempCard = start.hand[val][start.handCount[val]-1];
		
		// when a gold, silver, or copper card is drawn, increase count
		// of treasure
		if(tempCard == gold || tempCard == silver || tempCard == copper) {
			numTreasure++;
		}
		else {
			testHand[temp] = tempCard;
			start.handCount[val] = start.handCount[val] - 1;
			tempCard++;
		}
	}
	
	while(tempCard-1 >= 0) {
		start.discard[val][start.discardCount[val]++] = testHand[tempCard-1];
		tempCard++;
	}
	
	// discard a card	
	discardCard(pos,val,&start,0);
		
	// check actual values vs expected values
	assert(testVal == 0);
	assert(memcmp(&start,g,sizeof(struct gameState)) == 0);
	
	return 0;
}
