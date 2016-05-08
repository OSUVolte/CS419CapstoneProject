#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"


void testUpdateCoins()
{
	// Test Suite Setup: Test variables
	struct gameState *currentState = newGame();
	int currentPlayer = whoseTurn(currentState);

	/*
	* TEST: copper == 0, silver == 0, gold == 0, bonus == 0
	*/

		// Test
		updateCoins(currentPlayer, currentState, 0);

		assertTest(currentState->coins, 0, "copper == 0, silver == 0, gold == 0, and bonus == 0");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);


	/*
	* TEST: copper == 1, silver == 0, gold == 0, bonus == 0
	*/
		// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 1);

		// Test
		updateCoins(currentPlayer, currentState, 0);
		assertTest(currentState->coins, 1, "copper == 1, silver == 0, gold == 0, and bonus == 0");


		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);


	/*
	* TEST: copper == 1, silver == 0, gold == 0, bonus == 4
	*/
		// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 1);

		// Test
		updateCoins(currentPlayer, currentState, 4);
		assertTest(currentState->coins, 5, "copper == 1, silver == 0, gold == 0, and bonus == 4");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);


	/*
	* TEST: copper == 0, silver == 1, gold == 0, bonus == 0
	*/
		// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 2);

		// Test
		updateCoins(currentPlayer, currentState, 0);
		assertTest(currentState->coins, 2, "copper == 0, silver == 1, gold == 0, and bonus == 0");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);


	/*
	* TEST: copper == 0, silver == 1, gold == 0, bonus == 5
	*/

		// Before Test Setup
		addTreasureCard(currentPlayer, currentState, 2);

		// Test
		updateCoins(currentPlayer, currentState, 5);
		assertTest(currentState->coins, 7, "copper == 0, silver == 1, gold == 0, and bonus == 5");


		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);


	/*
	* TEST: copper == 0, silver == 0, gold == 1, bonus == 0
	*/
		// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 3);

		// Test
		updateCoins(currentPlayer, currentState, 0);
		assertTest(currentState->coins, 3, "copper == 0, silver == 0, gold == 1, and bonus == 0");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);



	/*
	* TEST: copper == 0, silver == 0, gold == 1, bonus == 7
	*/
	// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 3);

		// Test
		updateCoins(currentPlayer, currentState, 7);
		assertTest(currentState->coins, 10, "copper == 0, silver == 0, gold == 1, and bonus == 0");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);



	/*
	* TEST: copper == 1, silver == 1, gold == 1, bonus == 0
	*/
		// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 3);

		// Test
		updateCoins(currentPlayer, currentState, 0);
		assertTest(currentState->coins, 6, "copper == 1, silver == 1, gold == 1, and bonus == 0");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);


	/*
	* TEST: copper == 2, silver == 5, gold == 3, bonus == 0
	*/
		// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 3);
		addTreasureCard(currentPlayer, currentState, 3);
		addTreasureCard(currentPlayer, currentState, 3);

		// Test
		updateCoins(currentPlayer, currentState, 0);
		assertTest(currentState->coins, 21, "copper == 2, silver == 5, gold == 3, and bonus == 0");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);


	/*
	* TEST: copper == 3, silver == 4, gold == 3, bonus == 8
	*/
		// Before Test Setup
		currentState->coins = 0;
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 1);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 2);
		addTreasureCard(currentPlayer, currentState, 3);
		addTreasureCard(currentPlayer, currentState, 3);
		addTreasureCard(currentPlayer, currentState, 3);

		// Test
		updateCoins(currentPlayer, currentState, 0);
		assertTest(currentState->coins, 22, "copper == 5, silver == 4, gold == 3, and bonus == 8");

		// After Test Cleanup
		currentState->coins = 0;
		clearHand(currentPlayer, currentState);

}


int addTreasureCard(int player, struct gameState *state, int tCard)
{
	if (tCard == 1)
	{
		state->hand[player][state->handCount[player]] = copper;
		state->handCount[player]++;
	}
	else if (tCard == 2)
	{
		state->hand[player][state->handCount[player]] = silver;
		state->handCount[player]++;
	}
	else if (tCard == 3)
	{
		state->hand[player][state->handCount[player]] = gold;
		state->handCount[player]++;
	}

	return 0;
}

int clearHand(int player, struct gameState *state)
{
	int i;
	int handLength = state->handCount[player];

	for (i = 0; i < handLength; i++)
	{
		state->hand[player][state->handCount[player]] = curse;
		state->handCount[player] = 0;
	}

	return 0;
}
