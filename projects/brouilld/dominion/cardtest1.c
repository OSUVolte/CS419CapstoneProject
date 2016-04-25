#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"


void testSmithyCard(){

	// Test Suite Setup: Test variables
	int returnedValue = -50;
	int startingCount;
	int endingCount;
	int count;
	struct gameState *currentState = newGame();
	int currentPlayer = whoseTurn(currentState);



	/*
	* TEST: state->numBuys < 1
	*/

		// Before Test Setup
		currentState->deck[currentPlayer][0] = smithy;
		currentState->deckCount[currentPlayer]++;
		currentState->deck[currentPlayer][1] = smithy;
		currentState->deckCount[currentPlayer]++;
		currentState->deck[currentPlayer][2] = smithy;
		currentState->deckCount[currentPlayer]++;
		currentState->deck[currentPlayer][3] = smithy;
		currentState->deckCount[currentPlayer]++;

		count = setCard(currentPlayer, currentState, smithy);
		startingCount = currentState->handCount[currentPlayer];

		// Test
		returnedValue = cardEffect(smithy, -1, -1, -1, currentState, count, 0);
		endingCount = currentState->handCount[currentPlayer];
		assertTest((endingCount - startingCount), 3, "'smithy' adds 3 cards to hand");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 1;
}
