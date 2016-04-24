/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  cardtest3.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description: card test for great_hall card. For this card we must
** look at these important features of the card effect:
**		1. Verify that a single additional card is added to the current
**		   players hand, and then discarded back to the players deck
**		2. Verify that the number of actions has been incremented
**		3. Verify that no other players decks have been altered.
**		4. Verify that the cardEffect for great_hall returns 0
**
** Makefile: gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
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
	int retVal;
	int oHandCount;
	int oDeckCount;
	int testDeckCount1;
	int testDeckCount2;
	int oNumActions;
	int tNumActions;
	int currPlayer = 0;
	
		//initialize game
		retVal = initializeGame(pNum, kCards, rSeed, &state);
		
		printf("GREAT_HALL!!!\n");
		
		printf("*****TEST: cardtest3() - BEGIN *********\n\n");
		
			//Test 1 - current players handCount should be unchanged + 1 - 1
		
			//record original hand count/deckCount for test 1/2
			oHandCount = state.handCount[currPlayer];
			oDeckCount = state.deckCount[currPlayer];
			oNumActions = state.numActions;
			
				retVal = cardEffect(great_hall, 0, 0, 0, &state, 0, 0); 
			
				if (state.handCount[currPlayer] == oHandCount)
				{
					printf("Test1: Players New Hand Count Should be Same(+1-1): PASS\n");
				}
				else
				{
					printf("Test1: Players New Hand Count Should be Same(+1-1): FAIL\n");
					printf("Expected: %d, Tested: %d\n", oHandCount, state.handCount[currPlayer]);
				}
				
				
			//Test 1 continued - Verify that the player's decks remains unchanged in total
			
				testDeckCount1 = state.deckCount[currPlayer];
				testDeckCount2 = state.deckCount[1];
				
				if (testDeckCount1 == oDeckCount)
				{
					printf("Test1b: Current Players Deck Count Remains Unchanged: PASS\n");
				}
				else
				{
					printf("Test1b: Current Players Deck Count Remains Unchanged: FAIL\n");
					printf("Expected: %d, Tested: %d\n", oDeckCount, state.deckCount[currPlayer]);
				}
				
			//Test 2 - verify numActions +1
				if (oNumActions + 1 == state.numActions)
				{
					printf("Test2: Num Actions + 1: PASS\n");
				}
				else
				{
					printf("Test2: Num Actions + 1: FAIL\n");
					printf("Expected: %d, Tested: %d\n", oNumActions + 1, state.numActions);
				}
				
				
			//Test3 - Verify other decks remain unchanged
			
				if (testDeckCount2 == 10)
				{
					printf("Test3: Other Players Deck Count Remains Unchanged: PASS\n");
				}
				else
				{
					printf("Test3: Other Players Deck Count Remains Unchanged: FAIL\n");
					printf("Expected: 10, Tested: %d\n", oDeckCount, state.deckCount[1]);
				}
				
		
			//Test 4 - Verify that Adventurer returned a value of zero
				
				if (retVal == 0)
				{
					printf("Test4: Card Effect for Great_Hall Returned Successfully: PASS\n");
				}
				else
				{
					printf("Test4: Card Effect for Great_Hall Returned Successfully: FAIL\n");
				}
		
		printf("*****TEST: cardtest3() - END ***********\n\n");
		
	return 0;
}