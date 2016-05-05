/***********************************************************************
* Class:  CS 362 - Software Engineering II 
* Author:  Ellard Gerritsen
* File:  randomtestcard.c


The format is similar to randomtestadventurer 
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 



int main()
{
	//set the random seed and pick the kingdom cards we are going to use 
	int seed;
	int kingdom[10] = {adventurer, gardens, embargo, council_room, minion, mine, cutpurse, sea_hag, great_hall, smithy}; 
	
	
	//declare initial and test states
	struct gameState State;
	struct gameState testState;
	
	//declare iterators
	int i = 0;
	int j = 0;
	int k = 0;

	
	
	srand(time(0));
	
	int numberOfPlayers;
	int currentPlayer;
	
	
	//total number of tests and the test trackers
	int testCount = 500;
	int test1Pass = 0,
		test2Pass = 0,
		test3Pass = 0,
		test3_2Pass = 0;
		
	
	int test1Fail = 0,
		test2Fail = 0,
		test3Fail = 0,
		test3_2Fail = 0;
	
		
	//keep a tally of the total number of bugs
	int totalBugs = 0;
		
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("! randomtestcard- Council Room       !\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
			

	//Iterating over total count of tests
	for (i = 0; i < testCount; i++)
	{
		memset(&State, 0, sizeof(struct gameState));
		memset(&testState, 0, sizeof(struct gameState));

		
		//setting player amount between 2 and 3
		if (rand() % 2 == 0)
			numberOfPlayers = 2;
		else
			numberOfPlayers = 3;
		
		
		
		seed = rand();
		
		///this begins the game with the specified parameters 
		initializeGame(numberOfPlayers, kingdom, seed, &State);
		
			//we need to generate the deck, cards in players hand, as well as, discard
			for (j = 0; j < numberOfPlayers; j++)
			{
				
				currentPlayer = whoseTurn(&State);
				

				State.deckCount[j] = floor(Random() * MAX_DECK);
				for (k = 0; k < State.deckCount[j]; k++)
				{
					State.deck[j][k] = floor(Random()  * treasure_map);
				}
				
				
	
				State.handCount[j] = floor(Random() * MAX_HAND);
				for (k = 0; k < State.handCount[j]; k++)
				{
					State.hand[j][k] =  floor(Random()  * treasure_map);
				}
			
			
				//give a guaranteed council room 
				State.hand[j][0] = council_room;
				
				
				State.discardCount[j] = floor(Random() * MAX_DECK);
				for (k = 0; k < State.discardCount[k]; k++)
				{
					State.discard[j][k] = floor(Random() * treasure_map);
				}
			}
			
			
		
		
		// We memcpy so that we can look at the differences
		// between the changed testState that will undergo the changes
		// and State 
		memcpy(&testState, &State, sizeof(struct gameState));
		
		cardEffect(council_room, 0, 0, 0, &testState, 0, 0); 
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		
		/****************************TEST 1***************************/
		//Check number of buys. It should change for the current player by 1
		
		if (testState.numBuys != State.numBuys+1)
		{
			printf("TEST 1 ERROR: Incorrect Number of Buys on Iteration: %d\n", i);
			totalBugs++;
			test1Fail++;
		}	
		else
			test1Pass++;
		
		

		/****************************TEST 2***************************/
		//Check played card count. Only one card should have been played. 


		if(testState.playedCardCount != State.playedCardCount + 1)
		{
			test2Fail++;
			printf("TEST 2 ERROR: Played Card count incorrect on Iteration: %d\n", i);
			totalBugs++;
			
			
		}
		else
		{
			test2Pass++;
			
			
		
			
		}
		
		
		
		/****************************TEST 3***************************/
		//since two cards where drawn, we expect 3 cards more in then hand of the current Player. Remember one gets removed as well so its just +3
	
		if (testState.handCount[currentPlayer] == State.handCount[currentPlayer] + 3)
		{
			test3Pass++;
		}
		else
		{
			test3Fail++;
			totalBugs++;
			printf("TEST 3 ERROR: Hand Count is off on Iteration %d\n", i);
		
		}
		

		//Sub Test for 3 
		//
		int errorFree = 0;
		for (j = 0; j < testState.numPlayers; j++)
		{
			if (j != currentPlayer)
			{
				if (testState.handCount[j] != State.handCount[j]+1){
					printf("TEST 3_2 ERROR: Hand Count is off for Player %d on Iteration %d\n",j,i);
					totalBugs++;
					test3_2Fail++;
					errorFree = 1;
				}
			}
		}
	

		if (errorFree == 0)
			test3_2Pass++;
		else
			test3_2Fail++;

		
	}
				
			printf("--------------randomtestcard Results --------------\n\n");	
			
			if (totalBugs != 0)
				printf("TEST FAILED\n");
			else
				printf("TEST PASSED\n");
			
			printf("Test 1  \n");
			printf("Amount Passed: %d, Failed: %d\n", test1Pass, test1Fail);
			printf("Test 2 \n");
			printf("Amount Passed: %d, Failed: %d\n", test2Pass, test2Fail);
			printf("Test 3 \n");
			printf("Amount Passed: %d, Failed: %d\n", test3Pass, test3Fail);
			printf("Test 3-2 \n");
			printf("Amount Passed: %d, Failed: %d\n", test3_2Pass, test3_2Fail);
			
			
	
	return 0;
}
