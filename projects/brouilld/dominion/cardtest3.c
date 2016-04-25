#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

void testCouncilRoomCard(){
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
	* TEST: Council Room adds 4 cards to hand
	*/

		// Before Test Setup
		setup(currentState, currentPlayer, copper);
		count = currentState->handCount[currentPlayer];

		// Test
		returnedValue = cardEffect(council_room, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->handCount[currentPlayer] - count);

		assertTest(endingCount, 4, "'Council Room' adds 4 cards to hand");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 0;


	/*
	* TEST: Council Room adds 1 buy to player
	*/

		// Before Test Setup
		setup(currentState, currentPlayer, copper);
		count = currentState->handCount[currentPlayer];
		temp = currentState->numBuys;

		// Test
		returnedValue = cardEffect(council_room, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->numBuys - temp);

		assertTest(endingCount, 1, "'Council Room' adds 1 buy to player");

		// After Test Cleanup
		currentState->numBuys = 2;


	/*
	* TEST: Council Room adds 1 card to other player's hand
	*/

		// Before Test Setup
		currentState->numPlayers = 2;
		setup(currentState, currentPlayer, copper);
		setup(currentState, 2, copper);
		count = currentState->handCount[currentPlayer];
		temp = currentState->handCount[2];

		// Test
		returnedValue = cardEffect(council_room, -1, -1, -1, currentState, count, 0);
		endingCount = (currentState->handCount[2] - temp);

		assertTest(endingCount, 1, "'Council Room' adds 1 card to other player's hand");

		// After Test Cleanup
		currentState->handCount[2] = 0;
		currentState->numPlayers = 1;



}
