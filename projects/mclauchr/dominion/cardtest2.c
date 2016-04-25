/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  cardtest2.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description:  This card test will test the Adventurer card effect
** the most important portions of the card effect to verify include:
**		1. The current players handCount must be >= 2 more than original
**		2. The current player should have two additional TREASURES
**		3. All drawn cards / discarded cards are from current player's
**		   Deck.
**		4. cardEffect for Adventurer returns successfully
**		5. cardEffect for Adventurer returns a Zero even if discarded
**		   the player's deckCount = 0;
**
** Makefile: gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
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
	int oTreasureCount = 0;
	int tTreasureCount = 0;
	int currPlayer = 0;
	int i;
	
		//initialize game
		retVal = initializeGame(pNum, kCards, rSeed, &state);
		
		printf("ADVENTURER!!!\n");
		
		printf("*****TEST: cardtest2() - BEGIN *********\n\n");
		
			//Test 1 - current players handCount must be >= 2 more than original
		
			//record original hand count/deckCount for test 1/2
			oHandCount = state.handCount[currPlayer];
			oDeckCount = state.deckCount[currPlayer];
			
			//find original treasure card count for test 2
			for (i = 0; i < 5; i++)
			{
				if (state.hand[currPlayer][i] == copper)
					oTreasureCount++;
				else if (state.hand[currPlayer][i] == silver)
					oTreasureCount++;
				else if (state.hand[currPlayer][i] == gold)
					oTreasureCount++;
			}
			
			retVal = cardEffect(adventurer, 0, 0, 0, &state, 0, 0); 
			
				if (state.handCount[currPlayer] == oHandCount + 2)
				{
					printf("Test1: New Hand Count Should be +2: PASS\n");
				}
				else
				{
					printf("Test1: New Hand Count Should be +2: FAIL\n");
					printf("Expected: %d, Tested: %d\n", oHandCount + 2, state.handCount[currPlayer]);
				}
				
			//Test 2 - The current player should have + 2 TREASURE cards specifically...
		
				//find original treasure card count for test 2
				for (i = 0; i < state.handCount[currPlayer]; i++)
				{
					if (state.hand[currPlayer][i] == copper)
						tTreasureCount++;
					else if (state.hand[currPlayer][i] == silver)
						tTreasureCount++;
					else if (state.hand[currPlayer][i] == gold)
						tTreasureCount++;
				}
				
				if (oTreasureCount + 2 == tTreasureCount)
				{
					printf("Test2: Current Player has +2 Treasure Cards: PASS\n");
				}
				else
				{
					printf("Test2: Current Player has +2 Treasure Cards: FAIL\n");
					printf("Expected: %d, Tested: %d\n", oTreasureCount + 2, tTreasureCount);
				}
				
			//Test 3 - The card effect for adventurer should not effect other players
			
				testDeckCount1 = state.deckCount[currPlayer];
				testDeckCount2 = state.deckCount[1];
				
				if(oDeckCount != testDeckCount1 && testDeckCount2 == 10)
				{
					printf("Test3: Deck Changes Occurred Only in Current Players Deck: PASS\n");
				}
				else
				{
					printf("Test3: Deck Changes Occurred Only in Current Players Deck: FAIL\n");
				}
				
		
			//Test 4 - Verify that Adventurer returned a value of zero
				
				if (retVal == 0)
				{
					printf("Test4: Card Effect for Adventurer Returned Successfully: PASS\n");
				}
				else
				{
					printf("Test4: Card Effect for Adventurer Returned Successfully: FAIL\n");
				}
				
			//Test 5 - Returns zero, even if deckCount = 0;
			
				//initialize game
				retVal = initializeGame(pNum, kCards, rSeed, &state);
					
					//adjust players deckCount to 0
					state.deckCount[currPlayer] = 0;
					
					//call adventurer card effect
					retVal = cardEffect(adventurer, 0, 0, 0, &state, 0, 0); 
					
				if (retVal == 0)
				{
					printf("Test5: Card Effect for Adventurer Returned Successfully when Deck Count = 0: PASS\n");
				}
				else
				{
					printf("Test5: Card Effect for Adventurer Returned Successfully when Deck Count = 0: FAIL\n");
				}	
			
		printf("*****TEST: cardtest2() - END ***********\n\n");
		
	return 0;
}