/***********************************************************************
** Class:  CS 362 - Software Engineering II - 400
** Author:  Chris McLaughlin
** File:  unittest3.c
** Date:  4/23/16
** Due Date: 4/24/16
**
** Description: This test will test the updateCoins() function from
** dominion.c.  The important portions of the function to verify
** are as follows:
**		1. Verify that state->coins is incremented appropriately
**			a. copper
**			b. silver
**			c. gold
**		2: Verify that updateCoins() can handle a variety of coins
**		3. Verify that a coin bonus is applied appropriately  
** Makefile: gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
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
	
	//declare variables to assist with testing
	//post initializeGame();
	int playerNumber;
	int testCoins;
	int testCoins2;
	int bonus =  0;
	int i;
	
		printf("*****TEST: updateCoins() - BEGIN *******\n\n");
			
		//Initialize game state for next test to see if state->coins is incremented appropriately
		retVal = initializeGame(pNum, kCards, rSeed, &state);
		
		state.handCount[1] = 5;
		state.handCount[2] = 5;
		state.handCount[3] = 5;
		
			//NOTE: WE will use players who are NOT the first player after initialization
			//this will avoid the handcounts of test players being prepopulated with cards
			//copper player
			playerNumber =  1;
			state.coins = 0;
			
				//initialize hand of player 1 to cointain 5 copper cards
				for (i = 0; i < 5; i++)
				{
					state.hand[playerNumber][i] = copper;
				}
				
					//call test coins to test
					testCoins = updateCoins(playerNumber, &state, bonus);
				
				if (state.coins == 5)
				{
					printf("TEST1: Copper Incremented Correctly: PASS\n");
				}
				else
				{
					printf("TEST1: Copper Incremented Correctly: FAIL\n");
				}
				
			//silver player	
			playerNumber = 2;
			state.coins = 0;
			
				for (i = 0; i < 5; i++)
				{
					state.hand[playerNumber][i] =  silver;
				}
				
					//call test coins to test
					testCoins = updateCoins(playerNumber, &state, bonus);
				
				if (state.coins == 10)
				{
					printf("TEST1: Silver Incremented Correctly: PASS\n");
				}
				else
				{
					printf("TEST1: Silver Incremented Correctly: FAIL\n");
				}
				
			//gold player	
			playerNumber = 3;
			state.coins = 0;
			
				for (i = 0; i < 5; i++)
				{
					state.hand[playerNumber][i] =  gold;
				}
				
					//call test coins to test
					testCoins = updateCoins(playerNumber, &state, bonus);
				
				if (state.coins == 15)
				{
					printf("TEST1: Gold Incremented Correctly: PASS\n");
				}
				else
				{
					printf("TEST1: Gold Incremented Correctly: FAIL\n");
				}
			
			
			//Test 2: Verify a variety of coins is incremented appropriately
			//note must change handCount for player 3
			playerNumber = 3;
			state.coins = 0;
			state.handCount[3] =  15;
			
				for (i = 0; i < 5; i++)
				{
					state.hand[playerNumber][i] =  copper;
				}
				
				for (i = 5; i < 10; i++)
				{
					state.hand[playerNumber][i] =  silver;
				}
				
				for (i = 10; i < 15; i++)
				{
					state.hand[playerNumber][i] =  gold;
				}
					//call test coins to test
					testCoins = updateCoins(playerNumber, &state, bonus);
				
				if (state.coins == 30)
				{
					printf("TEST2: Variety of Coins Incremented Correctly: PASS\n");
				}
				else
				{
					printf("TEST2: Variety of Coins Incremented Correctly: FAIL\n");
				}
			
			//Test 3: Verify that bonus is applied appropriately
			//note must reset handCount for player 3 back to 5.
			playerNumber = 1;
			state.coins = 0;
			state.handCount[3] = 5;
			
				for (i = 0; i < 5; i++)
				{
					state.hand[playerNumber][i] = copper;
				}
				
					//test case with no bonus
					testCoins = updateCoins(playerNumber, &state, bonus);
					testCoins = state.coins;
			
			//reinitialize for bonus case
			state.coins = 0;
			bonus = bonus + 1;
				
					//test case with bonus applied
					testCoins2 = updateCoins(playerNumber, &state, bonus);
					testCoins2 = state.coins;
			
				if (testCoins == testCoins2 - 1)
				{
					printf("TEST3: Bonus Applied Correctly: PASS\n");
				}
				else
				{
					printf("TEST3: BONUS Applied Correctly: FAIL\n");
				}
				
			printf("\n");
	
		printf("*****TEST: updateCoins() - END *********\n\n");
	
	return 0;
}