/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  cardtest1.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description: This card test will test the smithy card implementaion
** the main things that need to be verified is that...
** 		1. The current player gains 3 cards and discards 1 (+2 change)
**		2. The current players deckCount should be changed
**			a. others players should not.
**		3. cardEffect for SMITHY returns a value
** Makefile: gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	//Declare variables to initialize game
	struct gameState state;
	int pNum = 2;
	int rSeed = 100;
	int kCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy}; 
	int retVal = 1;
	
	//Test Variables
	int currPlayer =  0;
	int handCount = 5;
	int hcComp = handCount + 2;
	int testHandCount = 0;
	int dCountO;
	int dCount1;
	int dCount2;
	int i;
	
		//initialize game
		retVal = initializeGame(pNum, kCards, rSeed, &state);
			
		printf("SMITHY!!!\n");
		
		printf("*****TEST: cardtest1() - BEGIN *********\n\n");
		
			//Test1 - Verify that three cards are drawn...1 is discarded...plus 2 total.
			
			//initialize handCount for test player
			state.handCount[currPlayer] = 5;
			
			//store original deckCount for test player
			dCountO = state.deckCount[currPlayer];
			
			retVal = cardEffect(smithy, 0, 0, 0, &state, 4, 0);
			
				if (state.handCount[currPlayer] == hcComp)
				{
					printf("Test1: Appropriate Cards Add/Subtract (+3 - 1 = +2) Total: PASS\n");
				}
				else
				{
					printf("Test1: Appropriate Cards Add/Subtract (+3 - 1 = +2) Total: FAIL\n");
					printf("Expected: %d, Test: %d\n", hcComp, state.handCount[currPlayer]);
				}
				
				
			//Test 2 - Verify ONLY currPlayers deckCount has changed
			dCount1 = state.deckCount[currPlayer];
			dCount2 = state.deckCount[1];
			
				if (dCount1 != dCountO)
				{
					printf("Test2: Cards Drawn/Discarded to and from Appropriate Pile: PASS\n");
				}
				else
				{
					printf("Test2: Cards Drawn/Discarded to and from Appropriate Pile: FAIL\n");
				}
				
				if (dCount2 == 10)
				{
					printf("Test2: Other Players Discard Pile NOT Affected: PASS\n");
				}
				else
				{
					printf("Test2: Other Players Discard Pile NOT Affected: FAIL\n");
				}
			
				
			//Test 3 - Verify that smithy returned a value of zero
				
				if (retVal == 0)
				{
					printf("Test3: Card Effect for Smithy Returned Successfully: PASS\n");
				}
				else
				{
					printf("Test3: Card Effect for Smithy Returned Successfully: FAIL\n");
				}
			
			printf("\n");
		
		printf("*****TEST: cardtest1() - END ***********\n\n");
		
	return 0;
}