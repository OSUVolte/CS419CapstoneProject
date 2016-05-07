#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"

void setup(struct gameState *state, int currentPlayer, int cardType){
	int i;
	int j;


	state->deckCount[currentPlayer] = 0;

	for (j = 0; j < 15; j++)
	{
		state->deck[currentPlayer][j] = cardType;
		state->deckCount[currentPlayer]++;
	}

}



void testAdventurerCard(){

	// Test Suite Setup: Test variables
	int returnedValue = -50;
	int startingCount;
	int endingCount;
	int count;
	struct gameState *currentState = newGame();
	currentState->numPlayers = 1;
	currentState->whoseTurn = 1;
	int currentPlayer = whoseTurn(currentState);


	/*
	* TEST: Adventurer adds 2 treasure cards to hand
	*/

		// Before Test Setup
		setup(currentState, currentPlayer, copper);
		count = currentState->handCount[currentPlayer];

		// Test
		returnedValue = cardEffect(adventurer, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->handCount[currentPlayer] - count);

		assertTest(endingCount, 2, "'Adventurer' adds 2 treasure cards to hand");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 1;


	/*
	* TEST: Adventurer adds 2 treasure cards to hand with copper deck
	*/

		// Before Test Setup
		setup(currentState, currentPlayer, copper);
		count = currentState->handCount[currentPlayer];

		// Test
		returnedValue = cardEffect(adventurer, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->handCount[currentPlayer] - count);

		assertTest(endingCount, 2, "'Adventurer' adds 2 treasure cards to hand with copper deck");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 1;


	/*
	* TEST: Adventurer adds 2 treasure cards to hand with silver deck
	*/

		// Before Test Setup
		setup(currentState, currentPlayer, silver);
		count = currentState->handCount[currentPlayer];

		// Test
		returnedValue = cardEffect(adventurer, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->handCount[currentPlayer] - count);

		assertTest(endingCount, 2, "'Adventurer' adds 2 treasure cards to hand with silver deck");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 1;


	/*
	* TEST: Adventurer adds 2 treasure cards to hand with gold deck
	*/

		// Before Test Setup
		setup(currentState, currentPlayer, gold);
		count = currentState->handCount[currentPlayer];

		// Test
		returnedValue = cardEffect(adventurer, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->handCount[currentPlayer] - count);

		assertTest(endingCount, 2, "'Adventurer' adds 2 treasure cards to hand with gold deck");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 1;


}


