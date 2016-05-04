#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"


int setCard(int currentPlayer, struct gameState *currentState, int cardToAdd)
{
	int beginningCount = currentState->handCount[currentPlayer];
	currentState->hand[currentPlayer][beginningCount] = cardToAdd;
	currentState->handCount[currentPlayer]++;
	return currentState->handCount[currentPlayer] - 1;
}

void removeCard(int currentPlayer, struct gameState *currentState)
{
	currentState->handCount[currentPlayer]--;
}

void testPlayCard(){

	// Test Suite Setup: Test variables
	int count;
	int returnedValue = -50;
	struct gameState *currentState = newGame();
	int currentPlayer = whoseTurn(currentState);
	int tempPhase = currentState->phase;
	int tempNumActions = currentState->numActions;

	/*
	* TEST: state->phase == 0
	*/

		// Before Test Setup
		currentState->phase = 0;
		currentState->numActions = 3;
		
		count = setCard(currentPlayer, currentState, smithy);

		// Test
		returnedValue = playCard(count, -1, -1, -1, currentState);
		assertTest(returnedValue, 0, "state->phase returns 0");

		// After Test Cleanup
		removeCard(currentPlayer, currentState);
		returnedValue = -50;
		currentState->phase = tempPhase;
		currentState->numActions = tempNumActions;


	/*
	* TEST: state->phase != 0
	*/

		// Before Test Setup
		currentState->phase = 1;
		currentState->numActions = 3;

		// Test
		returnedValue = playCard(-1, -1, -1, -1, currentState);
		assertTest(returnedValue, -1, "state->phase returns -1");

		// After Test Cleanup
		returnedValue = -50;
		currentState->phase = tempPhase;
		currentState->numActions = tempNumActions;


	/*
	* TEST: state->numActions < 1
	*/

		// Before Test Setup
		currentState->phase = 0;
		currentState->numActions = 0;

		// Test
		returnedValue = playCard(-1, -1, -1, -1, currentState);
		assertTest(returnedValue, -1, "state->numActions returns -1");

		// After Test Cleanup
		returnedValue = -50;
		currentState->phase = tempPhase;
		currentState->numActions = tempNumActions;

	/*
	* TEST: state->numActions > 1
	*/

		// Before Test Setup
		currentState->phase = 0;
		currentState->numActions = 2;
		count = setCard(currentPlayer, currentState, smithy);

		// Test
		returnedValue = playCard(count, -1, -1, -1, currentState);
		assertTest(returnedValue, 0, "state->numActions returns 0");

		// After Test Cleanup
		removeCard(currentPlayer, currentState);
		returnedValue = -50;
		currentState->phase = tempPhase;
		currentState->numActions = tempNumActions;

}
