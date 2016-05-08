/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  randomtestcard.c
** Date:  4/28/16
** Due Date: 5/1/16
**
** Description: card test for great_hall card. For this card we must
** look at these important features of the card effect:
**		1. Verify that a single additional card is added to the current
**		   players hand, and then discarded back to the players deck
**		2. Verify that the number of actions has been incremented
**		3. Verify that no other players decks have been altered.
**		4. Verify that the cardEffect for great_hall returns 0
**
** NOTE:  This test will be different from unit card tests as it will
** use random testing methods. 
**
** Reference:  Took reference from bettertestdrawcard.c
**
** Makefile: gcc -o randomtestcard -g  randomtestcard.c dominion.o 
**					rngs.o $(CFLAGS)
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 

//should have used this in unit tests, but I will start using it now...
#define NOISY_TEST 1


int main()
{
	//declare initial and test states
	struct gameState initState;
	struct gameState testState;
	
	//declare iterators
	int i,	
		j,
		k;

	//declare game variables
	int rSeed = 100;
	int kCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy}; 
	
	//declare player variables
	int pNum;
	int currPlayer;
	int handIdx;
	
	//declare compare variables
	int testVal;
	int oNumActions;
	
	//declare return variable
	int retVal = 0;
	
	//declare test variables
	int tNum = 1000;
	int tOnePA = 0,
		tOneFA = 0,
		tOnePB = 0,
		tOneFB = 0,
		tTwoP = 0,
		tTwoF = 0,
		tThreeP = 0,
		tThreeF = 0,
		tFourP = 0,
		tFourF = 0;
		
		//set random number generator
		srand(time(NULL));
	
			printf("************************************\n");
			printf("* Running randomtestcard...        *\n");
			printf("************************************\n\n");
			
			printf("*****TEST: randomtestcard() - BEGIN *****\n\n");
			
				for (i = 0; i < tNum; i++)
				{
					//generate a random seed, random number or players [2...4], initialize structs
					rSeed = rand();
					pNum =  ((rand()) % 3) + 2;
					memset(&initState, 0, sizeof(struct gameState));
					memset(&testState, 0, sizeof(struct gameState));
					retVal = 0;
					handIdx = 0;
					
					//initialize game
					retVal = initializeGame(pNum, kCards, rSeed, &initState);
					
						//randomly select player's state deck options SEE betterTestDrawCard
						for (j = 0; j < pNum; j++)
						{
							initState.deckCount[j] = floor(Random() * MAX_DECK);
							initState.discardCount[j] = floor(Random() * MAX_DECK);
							initState.handCount[j] = floor(Random() * MAX_HAND);
						
							//generate random cards in player's deck
							for (k = 0; k < initState.deckCount[k]; k++)
							{
								initState.deck[j][k] = floor(Random() * treasure_map);
							}
						
							//generate random cards in player's discard pile
							for (k = 0; k < initState.discardCount[k]; k++)
							{
								initState.discard[j][k] = floor(Random() * treasure_map);
							}
						
							//generate random cards in player's hand
							for (k = 0; k < initState.handCount[k]; k++)
							{
								initState.hand[j][k] = floor(Random() * treasure_map);
							}
						
							//add and adventurer card just in case one was not selected randomly
							//this will ensure that we know the index of an adventurer card exists
							handIdx = floor(Random() * initState.handCount[j]);
							initState.hand[j][handIdx] = adventurer;
						}
						
					//choose first player as currentPlayer, default initial
					currPlayer = 0;
						
					//copy initState to postState to be used for testing/comparison
					memcpy(&testState, &initState, sizeof(struct gameState));
					
					//call cardEffect for great_hall on random hand
					retVal = cardEffect(great_hall, 0, 0, 0, &testState, 0, 0); 
					
					
					//SubTest1 - Current Players handCount remains Unchanged
					testVal = testState.handCount[currPlayer];
					
					if (testVal == initState.handCount[currPlayer])
					{
						tOnePA++;
					}
					else
					{
						tOneFA++;
						
						#if (NOISY_TEST == 1)
							printf("SubTest1: Players Overall handCount Unchanged, FAILED at Iteration: %d\n", i);
							printf("Expected: %d, Tested: %d\n", initState.handCount[currPlayer], testVal);
						#endif
					}
	
					
					//SubTest1.1 AND the players deckCount remains Unchanged.
					testVal = testState.deckCount[currPlayer];
					
					if (testVal == initState.deckCount[currPlayer])
					{
						tOnePB++;
					}
					else
					{
						tOneFB++;
						
						#if (NOISY_TEST == 1)
							printf("SubTest1.1: Players Overall deckCount Unchanged, FAILED at Iteration: %d\n", i);
							printf("Expected: %d, Tested: %d\n", initState.deckCount[currPlayer], testVal);
						#endif
					}
					
					
					//SubTest2 - numActions has been incremented
					oNumActions = initState.numActions;
					testVal = testState.numActions;
						
					if (testVal == oNumActions + 1)
					{
						tTwoP++;
					}
					else
					{
						tTwoF++;
						
						#if (NOISY_TEST == 1)
							printf("SubTest2: numActions Incremented, FAILED at Iteration: %d\n", i);
							printf("Expected: %d, Tested: %d\n", oNumActions + 1, testVal);
						#endif
					}
					
					
					//SubTest3 - Other players decks remain unchanged.
					int tCount = 0;
					
					for (j = 1; j < pNum; j++)
					{
						testVal = testState.deckCount[j];
						
						if (testVal != initState.deckCount[j])
						{
							tCount++;
						}
					}
					
					//NOTE in Order to pass this test tCount must be == to 1, 
					//as only 1 player's deck should have changed
					if(tCount == 0)
					{
						tThreeP++;
					}
					else
					{
						tThreeF++;
						
						#if (NOISY_TEST == 1)
							printf("SubTest3: Other Player's Decks Unchanged FAILED at Iteration: %d\n", i);
							printf("Expected: %d, Tested: %d\n", 1, tCount);
							printf("Player initial handCount: %d\n", initState.handCount[currPlayer]);
							printf("Player initial deckCount: %d\n", initState.deckCount[currPlayer]);
							printf("Player initial discardCount: %d\n", initState.discardCount[currPlayer]);
							printf("Player post effect handCount: %d\n", testState.handCount[currPlayer]);
							printf("Player post effect deckCount: %d\n", testState.deckCount[currPlayer]);
							printf("Player post effect discardCount: %d\n", testState.discardCount[currPlayer]);
						#endif
					}
					
					
					//SubTest4 - CardEffect Returns with 0
					if(retVal == 0)
					{
						tFourP++;
					}
					else
					{
						tFourF++;
						
						#if (NOISY_TEST == 1)
							printf("SubTest4: Great_Hall cardEffect returns with 0 FAILED at Iteration: %d\n", i);
						#endif
					}
				}
				
			printf("*****TEST: randomtestcard() - END *******\n\n");	
			
			printf("OVERALL RESULTS randomtestcard:\n");
			printf("SubTest 1 - Players handCount Remains Unchanged Overall: \n");
			printf("Passed: %d, Failed: %d\n", tOnePA, tOneFA);
			printf("SubTest 1.1 - Players deckCount Unchanged Overall: \n");
			printf("Passed: %d, Failed: %d\n", tOnePB, tOneFB);
			printf("SubTest 2 - NumActions has been Incremented: \n");
			printf("Passed: %d, Failed: %d\n", tTwoP, tTwoF);
			printf("SubTest 3 - Other Player Decks Unchanged: \n");
			printf("Passed: %d, Failed: %d\n", tThreeP, tThreeF);
			printf("SubTest 4 - cardEffect for Great Hall Returns 0: \n");
			printf("Passed: %d, Failed: %d\n\n", tFourP, tFourF);
	
	return 0;
}