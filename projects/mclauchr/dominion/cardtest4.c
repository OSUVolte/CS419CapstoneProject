/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  cardtest4.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description: this card test evaluates the embargo card effect. The
** important features to verify include:  
**		1. Verify +2 coins are added to the current state
**		2. Verify that the embargo card is trashed. This means that the 
**		   players deckCount should be decremented.
**		3. Verify that embargo token for a specific kCard is incremented
**		4. Verify that other players deckCounts are unaltered.
**		5. Verify that cardEffect will return without error with 
**		   an appropriate choice 1
**		6. Verify that the an incorrect "choice" of where to put an 
**		   embargo token will result in an error.  
**
** Makefile: gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
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
	int oDeckCount;
	int testDeckCount1;
	int testDeckCount2;
	int oCoins;
	int tCoins;
	int oETokens = 0;
	int tETokens;
	int currPlayer = 0;
	
	
		//initialize game
		retVal = initializeGame(pNum, kCards, rSeed, &state);
		
		//store all original data
		oDeckCount = state.deckCount[currPlayer];
		oETokens = state.embargoTokens[smithy];
		oCoins = state.coins;
		
		printf("EMBARGO!!!\n");
		
		printf("*****TEST: cardtest4() - BEGIN *********\n\n");
		
			//Test 1 - two coins added to state
			
				//call cardEffect for embargo, with choice1 = smithy = 9
				retVal = cardEffect(embargo, smithy, 0, 0, &state, 0, 0);
				
				tCoins = state.coins;
				
					if(tCoins == oCoins + 2)
					{
						printf("Test1: +2 Coins Added to Player State: PASS\n");
					}
					else
					{
						printf("Test1: +2 Coins Added to Player State: FAIL\n");
						printf("Expected: %d, Tested: %d\n", oCoins + 2, tCoins);
					}
				
				
			//Test 2 - Verify that the embargo coins is trashed.
			
				testDeckCount1 = state.deckCount[currPlayer];
				
				if (testDeckCount1 == oDeckCount - 1)
				{
					printf("Test2: Card is trashed when discarded, deckCount - 1: PASS\n");
				}
				else
				{
					printf("Test2: Card is trashed when discarded, deckCount - 1: FAIL\n");
					printf("Expected: %d, Tested: %d\n", oDeckCount - 1, state.deckCount[currPlayer]);
				}
				
			//Test 3 - Verify that the embargo token for smithy is increased

				tETokens = state.embargoTokens[smithy];
				
				if (tETokens == oETokens + 1)
				{
					printf("Test3: Embargo Token for Choice1 Increased: PASS\n");
				}
				else
				{
					printf("Test3: Embargo Token for Choice1 Increased: FAIL\n");
					printf("Expected: %d, Tested: %d\n", oETokens + 1, tETokens);
				}
				
			
			//Test 4 - Verify that other players decks are unaltered
				
				testDeckCount2 = state.deckCount[1];
				
				if (testDeckCount2 == 10)
				{
					printf("Test4: Other Players Deck Count Remains Unchanged: PASS\n");
				}
				else
				{
					printf("Test4: Other Players Deck Count Remains Unchanged: FAIL\n");
					printf("Expected: 10, Tested: %d\n", oDeckCount, state.deckCount[1]);
				}
				
				
			//Test 5 - cardEffect exits with 0 with appropriate choice1
			
				if (retVal == 0)
				{
					printf("Test5: Card Effect for Embargo Returned Successfully: PASS\n");
				}
				else
				{
					printf("Test5: Card Effect for Embargo Returned Successfully: FAIL\n");
				}
			
			
			//Test 6 - Verify that the function will exit with error with an inappropriate choice to put embargo on
			
				//initialize game
				retVal = initializeGame(pNum, kCards, rSeed, &state);
				
					//call cardEffect with inappropriate choice1, salvager not chosen for this game
					retVal = cardEffect(embargo, salvager, 0, 0, &state, 0, 0);
					
				if (retVal == -1)
				{
					printf("Test6: Caught Inappropriate Choice 1 Parameter: PASS\n");
				}
				else
				{
					printf("Test6: Caught Inappropriate Choice 1 Parameter: FAIL\n");
				}
			
			printf("\n");
		
		printf("*****TEST: cardtest4() - END ***********\n\n");
		
	return 0;
}