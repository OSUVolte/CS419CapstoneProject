/*
 * cardtest3.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraActions = 0;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0; int secondPlayer = 1;
    int xtraPlayedCard = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0: %s ----------------\n", TESTCARD);
	newCards = 3;
	xtraActions = 0;
	xtraPlayedCard= 1;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}

	newCards = 0;
	xtraActions = 0;
	discarded = 0;
	printf("----------------- Player 1: %s ----------------\n", TESTCARD);
	printf("hand count = %d, expected = %d\n", testG.handCount[secondPlayer], G.handCount[secondPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[secondPlayer], G.deckCount[secondPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	assert(testG.handCount[secondPlayer] == G.handCount[secondPlayer] + newCards - discarded);
	assert(testG.deckCount[secondPlayer] == G.deckCount[secondPlayer] - newCards + shuffledCards);
	assert(testG.numActions == G.numActions + xtraActions);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}