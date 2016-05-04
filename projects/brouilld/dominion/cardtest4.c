#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

void testVillageCard(){
	// Test Suite Setup: Test variables
	int returnedValue = -50;
	int startingCount;
	int endingCount;
	int count;
	int temp;
	struct gameState *currentState = newGame();
	currentState->numPlayers = 1;
	currentState->whoseTurn = 1;
	currentState->numBuys = 2;
	int currentPlayer = whoseTurn(currentState);


	/*
	* TEST: Village adds one card to hand
	*/

		// Before Test Setup
		setup(currentState, currentPlayer, copper);
		count = currentState->handCount[currentPlayer];


		// Test
		returnedValue = cardEffect(village, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->handCount[currentPlayer] - count);

		assertTest(endingCount, 1, "'Village' adds one card to hand");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 0;

	/*
	* TEST: Village adds two actions
	*/

		// Before Test Setup
		currentState->numActions = 1;
		setup(currentState, currentPlayer, copper);
		count = currentState->handCount[currentPlayer];
		temp = currentState->numActions;

		// Test
		returnedValue = cardEffect(village, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->numActions - temp);

		assertTest(endingCount, 2, "'Village' adds two actions");

		// After Test Cleanup
		currentState->numActions = 1;

}
