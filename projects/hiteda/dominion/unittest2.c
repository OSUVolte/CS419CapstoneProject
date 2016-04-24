/******************************************************************************
 * Filename:			unittest2.c
 * Author:			David Hite
 * Date Created:		4/23/2016
 * Last Date Modified:		4/23/2016
 *
 * Description:
 * Tests the gamestate after initializeGame() is called
 *****************************************************************************/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"

int RunTest(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state, int failureCount);

int main()
{
	struct gameState* state = newGame();
	// test with valid values
	int* kCards = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int numPlayers = 2;
	const int randomSeed = 25;
	int failureCount = 0;
	
	printf("Normal game state, 2 players:\n");
	failureCount = RunTest(numPlayers, kCards, randomSeed, state, failureCount);
	
	printf("\nNormal game state, 3 players:\n");
	numPlayers = 3;
	failureCount = RunTest(numPlayers, kCards, randomSeed, state, failureCount);
	
	printf("\nNormal game state, 4 players:\n");
	numPlayers = 4;
	failureCount = RunTest(numPlayers, kCards, randomSeed, state, failureCount);
	
	printf("\nFaulty game state, 1 player:\n");
	numPlayers = 1;
	failureCount = RunTest(numPlayers, kCards, randomSeed, state, failureCount);
	
	printf("\nFaulty game state, 5 player:\n");
	numPlayers = 5;
	failureCount = RunTest(numPlayers, kCards, randomSeed, state, failureCount);
	
	printf("\nFaulty game state, invalid card set:\n");
	numPlayers = 2;
	free(kCards);
	// Each card must be distinct
	kCards = kingdomCards(1, 1, 3, 4, 5, 6, 7, 8, 9, 9);
	failureCount = RunTest(numPlayers, kCards, randomSeed, state, failureCount);
	
	printf("\nFaulty game state, invalid card values:\n");
	numPlayers = 2;
	free(kCards);
	kCards = kingdomCards(curse - 1, treasure_map + 1, treasure_map + 2, 4, 5, 6, 7, 8, 9, 10);
	failureCount = RunTest(numPlayers, kCards, randomSeed, state, failureCount);
	
	free(kCards);
	free(state);
	
	if (failureCount > 0)
	{
		printf("%d tests failed\n", failureCount);
	}
	
	printf("Tests completed!\n");
	
	return 0;
}

int RunTest(int numPlayers, int kCards[10], int randomSeed, struct gameState *state, int failureCount)
{
	int returnValue = initializeGame(numPlayers, kCards, randomSeed, state);
	
	// check if cards are valid
	int validCards = 1;
	int i, j;
	for (i = 0; i < 10; i++)
	{
		if (kCards[i] < curse || kCards[i] > treasure_map)
		{
			validCards = 0;
		}
		for (j = 0; j < 10; j++)
		{
			if (j != i && kCards[j] == kCards[i])
			{
			  validCards = 0;
			}
		}
	}
	// check if number of players is valid
	int validPlayers = (numPlayers > MAX_PLAYERS || numPlayers < 2)? 0 : 1;
	
	// check if initializeGame() missed any invalid parameters
	if (returnValue != -1)
	{
		if (validPlayers == 0)
		{
			printf("Error: initializeGame() failed to catch the invalid player number\n");
			failureCount = failureCount + 1;
			return failureCount;
		}
		if (validCards == 0)
		{
			printf("Error: initializeGame() failed to catch the invalid card set\n");
			failureCount = failureCount + 1;
			return failureCount;
		}
	}
	else
	{
		if (validPlayers == 0)
		{
			printf("initializeGame() caught invalid number of players\n");
			return failureCount;
		}
		if (validCards == 0)
		{
			printf("initializeGame() caught invalid card set\n");
			return failureCount;
		}
	}
	
	// gameState->numPlayers should == numberPlayers passed in, if valid
	if (state->numPlayers != numPlayers)
	{
		printf("Error: number of players modified by initializeGame()\n");
		printf("numPlayers: %d\tstate->numPlayers: %d\n", numPlayers, state->numPlayers);
		failureCount = failureCount + 1;
	}
	
	// state->coins should reflect player 1's coin count
	if (state->coins != 7)
	{
		printf("Error: %d coins instead of 7\n", state->coins);
		failureCount = failureCount + 1;
	}
	
	// check that each player has 3 estate cards and 7 copper cards
	int totalPlayerCards = 0;
	for (i = 0; i < numPlayers; i++)
	{
		int estateCount = 0, copperCount = 0;
		totalPlayerCards = totalPlayerCards + state->deckCount[i];
		if ((state->deckCount[i] + state->handCount[i]) != 10)
		{
			printf("Error: deck count is %d for player %d instead of 10\n", state->deckCount[i], i + 1);
			failureCount = failureCount + 1;
		}
		for (j = 0; j < state->deckCount[i]; j++)
		{
			if (state->deck[i][j] == estate)
			{
				estateCount = estateCount + 1;
			}
			if (state->deck[i][j] == copper)
			{
				copperCount = copperCount + 1;
			}
		}
		
		if (state->handCount[i] > 0)
		{
			for (j = 0; j < state->handCount[i]; j++)
			{
				if (state->deck[i][j] == estate)
				{
					estateCount = estateCount + 1;
				}
				if (state->deck[i][j] == copper)
				{
					copperCount = copperCount + 1;
				}	
			}
		}
		
		if (state->discardCount[i] > 0)
		{
			for (j = 0; j < state->discardCount[i]; j++)
			{
				if (state->discard[i][j] == estate)
				{
					estateCount = estateCount + 1;
				}
				if (state->discard[i][j] == copper)
				{
					copperCount = copperCount + 1;
				}	
			}
		}
		
		if (i != 0 && estateCount != 3)
		{
			printf("Error: player %d has %d estates instead of 3\n", i + 1, estateCount);
			failureCount = failureCount + 1;
		}
		if (i != 0 && copperCount != 7)
		{
			printf("Error: player %d has %d copper instead of 7\n", i + 1, copperCount);
			failureCount = failureCount + 1;
		}
		if (i == 0 && estateCount < 3)
		{
			printf("Error: player %d has fewer estates than 3\n", i + 1);
			failureCount = failureCount + 1;
		}
		if (i == 0 && copperCount < 7)
		{
			printf("Error: player %d has fewer copper than 7\n", i + 1);
			failureCount = failureCount + 1;
		}
	}
	
	// check for card availability per number of players
	int numCurse, numVic;
	if (numPlayers == 2)
	{
		// 10 curse cards, 8 victory cards
		numCurse = 10;
		numVic = 8;
	}
	else
	{
		// 10 curse cards for every player beyond 2, 12 victory cards
		numCurse = 10 * (numPlayers - 1);
		numVic = 12;
	}
	
	// there should be numCurse curse cards
	if (state->supplyCount[curse] != numCurse)
	{
		printf("Error: %d curse cards available instead of %d\n", state->supplyCount[curse], numCurse);
		failureCount = failureCount + 1;
	}
	// there should be numVic province cards
	if (state->supplyCount[province] != numVic)
	{
		printf("Error: %d province cards available instead of %d\n", state->supplyCount[province], numVic);
		failureCount = failureCount + 1;
	}
	// there should be numVic duchy cards
	if (state->supplyCount[duchy] != numVic)
	{
		printf("Error: %d duchy cards available instead of %d\n", state->supplyCount[duchy], numVic);
		failureCount = failureCount + 1;
	}
	// there should be numVic estate cards
	if (state->supplyCount[estate] != numVic)
	{
		printf("Error: %d estate cards available instead of %d\n", state->supplyCount[estate], numVic);
		failureCount = failureCount + 1;
	}
	/*
	int totalCardCount = 0;
	for (i = curse; i <= treasure_map; i++)
	{
		totalCardCount = totalCardCount + state->supplyCount[i];
	}
	
	printf("%d total cards\n", totalCardCount + totalPlayerCards);
	*/
	
	// No cards should have been played yet
	if (state->playedCardCount != 0)
	{
		printf("Error: playedCardCount is %d instead of 0\n", state->playedCardCount);
		failureCount = failureCount + 1;
	}
	
	// Phase should start at 0
	if (state->phase != 0)
	{
		printf("Error: phase is %d instead of 0\n", state->phase);
		failureCount = failureCount + 1;
	}
	
	// Number of actions available should be 1
	if (state->numActions != 1)
	{
		printf("Error: numActions is %d instead of 1\n", state->numActions);
		failureCount = failureCount + 1;
	}
	
	// Number of buys available should be 1
	if (state->numBuys != 1)
	{
		printf("Error: numBuys is %d instead of 1\n", state->numBuys);
		failureCount = failureCount + 1;
	}
	
	// It should be the first player's turn
	if (state->whoseTurn != 0)
	{
		printf("Error: whoseTurn is %d instead of 0\n", state->whoseTurn);
		failureCount = failureCount + 1;
	}
	
	return failureCount;
}