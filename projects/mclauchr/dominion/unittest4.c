/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  unittest4.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description: This unit test will test the isGameOver function which
** takes as a single parameter (struct gameState).  We must verify that
** the function will return a 1 if the game is supposed to end and a 0
** if it should continue.  Important portions to verify are as follows:
**		1. If number of provinces reaches zero -> END
**		2. or of three supply piles reach zero -> END
**			a. test when two reach zero -> CONTINUE
**			b. test when three reach zero -> END
**
** Makefile: gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
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
	int pNum = 4;
	int rSeed = 100;
	int kCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy}; 
	int retVal;
	
	
		printf("*****TEST: isGameOver() - BEGIN ********\n\n");	
		printf("*****TEST: updateCoins() - BEGIN *******\n\n");
		//Test1 provinces != 0 and provinces = 0, should cause game to continue
		
			//NOTE we have already shown via testing, initializeGame to be "bug free" to our knowledge
			retVal = initializeGame(pNum, kCards, rSeed, &state);
		
			state.supplyCount[province] = 1;
			
			retVal = isGameOver(&state);
			
				//verify that retVal = 0, game will continue
				if (retVal == 0)
				{
					printf("Test1: Provinces Exists, Game Continues: PASS\n");
				}
				else
				{
					printf("Test1: Provinces Exists, Game Continues: FAIL\n");
				}
				
			state.supplyCount[province] = 0;
			
			retVal = isGameOver(&state);
			
				//verify that reVal = 1, game will end
				if (retVal == 1)
				{
					printf("Test1: Zero Provinces, Game Ends: PASS\n");
				}
				else
				{
					printf("Test1: Zero Procinces, Game Ends: FAIL\n");
				}
		
		//test situation when two supply piles are empty and three supply piles are empty
		//NOTE: initializeGame has already filled supply piles with default amounts
		
			//Lets change that
			state.supplyCount[embargo] = 0;
			state.supplyCount[village] = 0;
			
			//must change province back to a non zero
			state.supplyCount[province] = 1;
			
				//test two piles empty
				retVal = isGameOver(&state);
				
				//verify game will continue
				if (retVal == 0)
				{
					printf("Test2: Two Supply piles empty, Game Continues: PASS\n");
				}
				else
				{
					printf("Test2: Two Supply piles empty, Game Continues: FAIL\n");
				}
			
			//Lets remove one more pile to make 3 empty piles total
			state.supplyCount[mine] = 0;
			
				//test 3 empty piles
				retVal = isGameOver(&state);
				
				//verify game will end
				if (retVal == 1)
				{
					printf("Test2: Three Supply piles empty, Game Ends: PASS\n");
				}
				else
				{
					printf("Test2: Three Supply piles empty, Game Ends: FAIL\n");
				}
				
		printf("\n");		
		
		printf("*****TEST: isGameOver() - END **********\n\n");
	
	return 0;
}