/***********************************************************************
* Class:  CS 362 - Software Engineering II 
* Author:  Ellard Gerritsen
* File:  randomtestadventurer.c
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
	int kingdom[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy}; 
	
	
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
	
	int StateTreasureCards; //this will be the State unchanged treasure Cards
	int testTreasureCards;  //this will be the testState treasure Cards
	

	
	//total number of tests and the test trackers
	int testCount = 500;  //change this if you want more tests
	int test1Pass = 0,
		test2Pass = 0,
		test3Pass = 0,
		test4Pass = 0;
	
	int test1Fail = 0,
		test2Fail = 0,
		test3Fail = 0,
		test4Fail = 0;
		
	//keep a tally of the total number of bugs
	int totalBugs = 0;
		
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("! randomtestadventurer               !\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
			

	//Iterating over total count of tests
	for (i = 0; i < testCount; i++)
	{
//		memset(&State, 0, sizeof(struct gameState));
//		memset(&testState, 0, sizeof(struct gameState));

		
		//setting player amount between 2 and 3
		if (rand() % 2 == 0)
			numberOfPlayers = 2;
		else
			numberOfPlayers = 3;
		
		
		
		seed = rand();
		
		///this begins the game with the specified parameters 
		initializeGame(numberOfPlayers, kingdom, seed, &State);
		currentPlayer = whoseTurn(&State);
	
			//we need to generate the deck, cards in players hand, as well as, discard
			for (j = 0; j < numberOfPlayers; j++)
			{
				
				
				
				
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
			
				//give a guaranteed adventurer 
				State.hand[j][0] = adventurer;
	
				
				State.discardCount[j] = floor(Random() * MAX_DECK);
				for (k = 0; k < State.discardCount[j]; k++)
				{
					State.discard[j][k] = floor(Random()  * treasure_map);
				}
			}
			
			
		
		
		// We memcpy so that we can look at the differences
		// between the changed testState that will undergo the changes
		// and State 
		memcpy(&testState, &State, sizeof(struct gameState));
		
		
		//Remember that the refactored version of Adventurer has an issue with the treasureCards
	
		StateTreasureCards = 0;
		
		for (j = 0; j < State.handCount[currentPlayer]; j++)
		{
			
			
			if (State.hand[currentPlayer][j] == copper || State.hand[currentPlayer][j] == silver || State.hand[currentPlayer][j] == gold)
			{
				StateTreasureCards++;
			}
		}
		
		//since we are testing the adventurer card, we need to call it of course
		cardEffect(adventurer, 0, 0, 0, &testState, 0, 0); 
		
		
		testTreasureCards = 0;
		
		for (j = 0; j < testState.handCount[currentPlayer]; j++)
		{
			
			
			if (testState.hand[currentPlayer][j] == copper || testState.hand[currentPlayer][j] == silver || testState.hand[currentPlayer][j] == gold)
			{
				testTreasureCards++;
			}
		}
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/****************************TEST 1***************************/
		//We check to see if the treasures we correctly added
					
		if (testTreasureCards == StateTreasureCards + 2)
		{
			test1Pass++;
		}
		else
		{
			test1Fail++;
			totalBugs++;
			
			printf("TEST 1 ERROR: Treasure Card Count off on Iteration %d\n", i);
			printf("Actual: %d             Expected: %d     \n", testTreasureCards, StateTreasureCards);
		}
		
		/****************************TEST 2***************************/
		//Check Supply Counts 
		
		
		if (State.supplyCount[copper] == testState.supplyCount[copper])
			totalBugs++;
		if (State.supplyCount[silver] == testState.supplyCount[silver])
			totalBugs++;
		if (State.supplyCount[gold] == testState.supplyCount[gold])
			totalBugs++;	
		
		if (State.supplyCount[copper] != testState.supplyCount[copper] || State.supplyCount[silver] != testState.supplyCount[silver] || State.supplyCount[gold] != testState.supplyCount[gold]){
			totalBugs++;
			test2Fail++;
			printf("TEST 2 ERROR: Supply Count shouldnt have changed for copper,silver,gold. Failed on Iteration %d\n", i);

		}
		else
			test2Pass++;
	



		/****************************TEST 3***************************/
		int test3Bugs = 0;
		
		for (j = 1; j < numberOfPlayers; j++)
		{
		
			if (testState.deckCount[j] != State.deckCount[j])
			{
				test3Bugs++;
			}
		}	
		

		if(test3Bugs != 0)
		{
			test3Fail++;
			printf("TEST 3 ERROR: Other Player's Deck Count Changed on  Iteration: %d\n", i);
			
			for (j = 1; j < numberOfPlayers; j++)
			{
		
				if (testState.deckCount[j] != State.deckCount[j])
				{	
					printf("Actual : %d                 Expected: %d \n", testState.deckCount[j], State.deckCount[j]);
				}
			}	
		


			totalBugs++;
			
			
		}
		else
		{
			test3Pass++;
			
			
		
			
		}
		
		
		
		/****************************TEST 4***************************/
		//since two cards where drawn, we expect 1 cards more in then hand of the current Player. 
		//  Handcount - 1 used card + 2 drawn treasures 
	
		if (testState.handCount[currentPlayer] == State.handCount[currentPlayer] + 1)
		{
			test4Pass++;
		}
		else
		{
			test4Fail++;
			totalBugs++;
			printf("TEST 4 ERROR: Hand Count is off on Iteration %d\n", i);
			printf("Actual:   %d                       Expected: %d\n", testState.handCount[currentPlayer], State.handCount[currentPlayer]+1);
		}
		
		
	}
				
			printf("--------------randomtestadventurer() Results --------------\n\n");	
			
			if (totalBugs != 0)
				printf("TEST FAILED\n");
			else
				printf("TEST PASSED\n");
			
			printf("Test 1  \n");
			printf("Amount Passed: %d, Failed: %d\n", test1Pass, test1Fail);
			printf("Test 2  \n");
			printf("Amount Passed: %d, Failed: %d\n", test2Pass, test2Fail);
			printf("Test 3 \n");
			printf("Amount Passed: %d, Failed: %d\n", test3Pass, test3Fail);
			printf("Test 4 \n");
			printf("Amount Passed: %d, Failed: %d\n\n", test4Pass, test4Fail);
			
			
			
	
	return 0;
}
