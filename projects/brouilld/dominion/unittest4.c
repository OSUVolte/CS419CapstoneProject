#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"

void testBuyCard(){

	// Test Suite Setup: Test variables
	int temp = -50;
	int temp2 = -50;
	int temp3 = -50;
	int returnedValue = -50;
	struct gameState *currentState = newGame();

	/*
	* TEST: state->numBuys < 1
	*/

		// Before Test Setup
		temp = currentState->numBuys;
		currentState->numBuys = 0;

		// Test
		returnedValue = buyCard(smithy, currentState);
		assertTest(returnedValue, -1, "currentState->numBuys < 1 returns -1");

		// After Test Cleanup
		currentState->numBuys = temp;
		temp = -50;
		returnedValue = -50;


	/*
	* TEST: supplyCount Conditional returns -1
	*/

		// Before Test Setup
		temp = currentState->supplyCount[smithy];
		currentState->supplyCount[smithy] = 0;

		// Test
		returnedValue = buyCard(smithy, currentState);
		assertTest(returnedValue, -1, "supplyCount conditional returns -1");

		// After Test Cleanup
		currentState->supplyCount[smithy] = temp;
		temp = -50;
		returnedValue = -50;


	/*
	* TEST: supplyCount Conditional returns -1
	*/

		// Before Test Setup
		temp = currentState->coins;
		currentState->coins = 0;

		// Test
		returnedValue = buyCard(smithy, currentState);
		assertTest(returnedValue, -1, "state->coins conditional returns -1");

		// After Test Cleanup
		currentState->coins = temp;
		temp = -50;
		returnedValue = -50;


	/*
	* TEST: True on all conditionals returns 0
	*/
		// Before Test Setup
		temp = currentState->numBuys;
		currentState->numBuys = 2;

		temp2 = currentState->supplyCount[smithy];
		currentState->supplyCount[smithy] = 5;

		temp3 = currentState->coins;
		currentState->coins = 10;

		// Test
		returnedValue = buyCard(smithy, currentState);
		assertTest(returnedValue, 0, "True on all conditionals returns 0");

		// After Test Cleanup
		returnedValue = -50;
		temp = -50;
		temp2 = -50;
		temp3 = -50;
}
