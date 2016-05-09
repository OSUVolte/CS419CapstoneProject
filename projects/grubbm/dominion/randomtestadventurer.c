/*************************************************
Name: Max Grubb
File: randomtestadventurer.c
Description: Random test for the Adventurer Card
Date: 5/8/2016
**************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <assert.h>


#define TEST_COUNT 75 	

int setUpGameState(struct gameState *testState);
int runRandomTest();

int main()
{
	
	int passCheck = 0;
	int result = 0;
	int i; 
	
	srand(time(NULL));

	printf("Random Testing for Adventurer Card\n\n");

	for(i = 1; i <= TEST_COUNT; i++)
	{
		
		printf("------------ Test %d ------------\n", i);
		result = runRandomTest();
		
			if(result == 1)
				passCheck++;
			else if(result ==0)
				printf("All tests for run %i pass\n", i);
			
	}
	
	if(passCheck == 0){
		
			printf("All Tests Passed. Check Output Files For Results\n");
	}
	else{
		
			printf("%i Tests Failed. Check Output Files For Results\n", passCheck);
		
	}
		
	

	return 0;
}

int runRandomTest(){
	
	struct gameState testState, holdState;
	int j, currentPlayer, handPos, checkFail;

		handPos = setUpGameState(&testState);
		memcpy(&holdState, &testState, sizeof(struct gameState));
		cardEffect(adventurer, 0, 0, 0, &testState, handPos, 0);
		currentPlayer = testState.whoseTurn;
		
		checkFail = 0;
		
		//Hand Count Test 
		if(testState.handCount[currentPlayer] != holdState.handCount[currentPlayer] + 2)
		{
			printf("Hand Count Test: FAIL\nExpected Result: %d\nActual Result: %d\n", holdState.handCount[currentPlayer] + 2, testState.handCount[currentPlayer]);
			checkFail = 1;

		}

		//Deck Count Test 
		if(holdState.deckCount[currentPlayer] - 2 < testState.deckCount[currentPlayer])
		{
			printf("Deck Count Test: FAIL\nExpected Result: less than or equal to %d \nActual: %d\n", holdState.handCount[currentPlayer] - 2, testState.deckCount[currentPlayer]);
			checkFail = 1;

		}

		//Coin Test 
		if((testState.hand[currentPlayer][testState.handCount[currentPlayer] - 1] != copper && 
			testState.hand[currentPlayer][testState.handCount[currentPlayer] - 1] != silver && 
			testState.hand[currentPlayer][testState.handCount[currentPlayer] - 1] != gold) ||
			(testState.hand[currentPlayer][testState.handCount[currentPlayer] - 2] != copper && 
			testState.hand[currentPlayer][testState.handCount[currentPlayer] - 2] != silver && 
			testState.hand[currentPlayer][testState.handCount[currentPlayer] - 2] != gold))
		{
			
			printf("Added Cards Test: FAIL\nExpected Results: 6 Gold/ 5 Silver/ 4 Copper\nActual Count: %d, %d\n", 
				testState.hand[currentPlayer][testState.handCount[currentPlayer] - 1], testState.hand[currentPlayer][testState.handCount[currentPlayer] - 2]);
				checkFail = 1;
		}

		//Discard Test 	
		if(testState.discardCount[currentPlayer] + testState.deckCount[currentPlayer] != holdState.discardCount[currentPlayer] + holdState.deckCount[currentPlayer] - 2)
		{
			printf("Discard Count: FAIL\nExpected Result: %d\nActual Result: %d\n", 
				holdState.discardCount[currentPlayer] + holdState.deckCount[currentPlayer] - 2, testState.discardCount[currentPlayer] + testState.deckCount[currentPlayer]);
			checkFail = 1;
		}

		//Hand and Deck Count Test 
		for(j = 0; j < testState.numPlayers; j++)
		{
			if(j != currentPlayer)
			{
				if(testState.handCount[j] != holdState.handCount[j])
				{
					printf("Player %d's Hand Count Test: FAIL\nExpected Result: %d\nActual Result: %d\n", j, holdState.handCount[j], testState.handCount[j]);
					checkFail = 1;
				}
				if(testState.deckCount[j] != holdState.deckCount[j])
				{
					printf("Player %d's Deck Count Test: FAIL\nExpected Result: %d\nActual Result: %d\n", j, holdState.deckCount[j], testState.deckCount[j]);
					checkFail = 1;
				}
			}
		}

		//Supply Count Test 
		for(j = 0; j < 25; j++)
		{
			if(testState.supplyCount[j] != holdState.supplyCount[j])
			{
				checkFail = 1;
				printf("Supply Count Test: FAIL\nExpected Result: %d\nActual Result: %d\n", holdState.supplyCount[j], testState.supplyCount[j]);
			}
		}
if(checkFail == 1)
		{
			return 1; 
		}
		else
		{
			return 0; 
		}
	
}

int setUpGameState(struct gameState *testState)
{
	int i, hP, hC, dC, disCount, curPlayer;
	int numPlayers = (rand() % 3) + 2;								
	int seed = 599;
	
	int k[10] = {gardens, council_room, village, adventurer, mine, smithy, remodel, baron, steward, great_hall};
	int deck[16] = {gold, silver, copper, great_hall, duchy, province, 
		adventurer, council_room, steward, gardens, mine, village, smithy, remodel, baron, sea_hag};
		

	//Set memory and (re)initializegame
	memset(testState, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, testState);

	
	//randomization of player, actions, hand-deck-discard counts
	testState->whoseTurn = (rand() % numPlayers);							
	testState->numActions = (rand() % 10 + 1);								
	testState->handCount[testState->whoseTurn] = (rand() % MAX_HAND) + 1;		
	testState->deckCount[testState->whoseTurn] = (rand() % (MAX_DECK - 4)) + 5;	
	testState->discardCount[testState->whoseTurn] = 
		(rand() % (testState->deckCount[testState->whoseTurn] - 3) + 1);		
	
	curPlayer = testState->whoseTurn;									
	hC = testState->handCount[curPlayer];
	dC = testState->deckCount[curPlayer];
	disCount = testState->discardCount[curPlayer];

	// Randomize cards in hand 
	for(i = 0; i < hC; i++)
	{
		testState->hand[curPlayer][i] = deck[rand() % 16];
	}

	//place Village card 
	hP = rand() % hC;
	testState->hand[curPlayer][hP] = village;

	//One more randomization 
	for(i = 0; i < dC; i++)
	{
		testState->deck[curPlayer][i] = deck[rand() % 16];
	}

	//Discard randomization 
	for(i = 0; i < disCount; i++)
	{	
		if(dC > 2)
		{
			testState->discard[curPlayer][i] = testState->deck[curPlayer][dC - 1];
			testState->deckCount[curPlayer]--;
			dC--;
		}
	}

	return hP;
}
