//Shawn Seibert
//Card Test 4
//MinionCard()
//gcc cardtest4.c dominion.c rngs.c -o cardtest4 -lm

//minionCard(int choice1, int choice2, int choice3, int handPos, int currentPlayer, struct gameState *state)



#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int player = 1;
	struct gameState state, testState;
	int bonus;
	int c1, c2, c3;
	int seed = 100;
	int numPlayers = 2;
	int cardDrawCount = 0;
	int checkBuyAmount = 0;
	int oldCardCount, newCardCount;
	int choice1 = 0, choice2 = 0, choice3, choice4;
	int drawTotal = 3;
	int oldActionAmount, newActionAmount;
	int oldCoinCount, newCoinCount;
	int loopCount = 0;
	int currentPlayer = 1;
	int i = 0;
	 int j = 0;
	int handPos = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
				smithy, council_room};
	

	printf("-------------------MINION CARD TEST---------------------\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &testState);
	
	//Add 4 cards to current player hand
	for (i = 0; i <= 3; i++) 
	{
		loopCount++;
		drawCard(currentPlayer, &testState);
	}
	
	//+1 action
	printf("CHECKING INCREASE IN ACTIONS.\n");
	printf("Previous number of Actions %d\n",  testState.numActions);
	oldActionAmount = testState.numBuys;
	testState.numBuys++;
	printf("Increased number of Actions %d\n",  testState.numActions); 
	newActionAmount = testState.numActions;
	if ((oldActionAmount + 1) == newActionAmount)
	{
		printf("Test passed: Number of actions increased by one.\n");
	}
	else
	{
		printf("Test failed: Number of actions did not increase by one.\n");
	}
			
    //discard card from hand
    printf("CHECKING DISCARD.\n");
	printf("Current player hand count: %d\n", testState.handCount[currentPlayer] );
	oldCardCount = testState.handCount[currentPlayer];
    discardCard(handPos, currentPlayer, &testState, 0);
	printf("Current player hand count: %d\n", testState.handCount[currentPlayer] );
	newCardCount = testState.handCount[currentPlayer];
	if ((oldCardCount - 1) == newCardCount)
	{
		printf("Test Passed: Player discarded.\n");
	}
	else
	{
		printf("Test Failed: Player did not discard correctly.\n");
	}
	
	//Loop twice for both choices
	for (i = 0; i < 2; i++)
	{
		printf("I TOTAL: %d\n", i);
		//Increase coins by 2
		if (i == 0)		
		{
			//Check coin increase
			printf("CHECKING COIN INCREASE\n");
			printf("Current coin count %d.\n", testState.coins);
			oldCoinCount = testState.coins;
			testState.coins = testState.coins + 2;
			newCoinCount = testState.coins;
			printf("New coin count %d.\n", testState.coins);
			if ((oldCoinCount + 2) == newCoinCount)
			{
				printf("Test Passed: Player coin increased by two.\n");
			}
			else
			{
				printf("Test Failed: Player coins did not increase correctly.\n");
			}
		}
				
		  else if (i == 1)		//discard hand, redraw 4, other players with 5+ cards discard hand and draw 4
		{
		  //discard hand
			printf("CHECKING DISCARD.\n");
			printf("Current player hand : %d\n", testState.handCount[currentPlayer] );
			oldCardCount = testState.handCount[currentPlayer];

		 while(numHandCards(&testState) > 0)
			{
			  
			  discardCard(handPos, currentPlayer, &testState, 0);
			  newCardCount = testState.handCount[currentPlayer];
			}
			if (newCardCount <= 0)
			{
				printf("Test passed: Card count = %d.\n", numHandCards(&testState));
			}
			else
			{
				printf("Test failed: All cards were not discarded.\n");
			}
					
		  //draw 4
		  printf("CHECKING ADD 4 CARDS\n");
		  oldCardCount = testState.handCount[currentPlayer];
		  for (i = 0; i <= 4; i++)
			{
			  printf("Number of cards added: %d\n", i);
			  drawCard(currentPlayer, &testState);
			}
			 newCardCount = testState.handCount[currentPlayer];
			 if ((oldCardCount +4) == newCardCount)
			{
				printf("Test passed: New card count = 4.\n");
			}
			else
			{
				printf("Test failed: Incorrect number of cards added.\n");
			}
							
		  //other players discard hand and redraw if hand size > 4
		  for (i = 0; i < testState.numPlayers; i++)
		  {
			  if (i != currentPlayer)
			  {
				oldCardCount = testState.handCount[currentPlayer];
				if ( testState.handCount[i] > 4 )
				{
				  //discard hand
				  while( testState.handCount[i] > 0 )
				{
				  discardCard(handPos, i, &testState, 0);
				}
				printf("CHECKING OTHER PLAYERS ADDED CARDS\n");
				  //draw 4
				for (j = 0; j <= 4; j++)
				{
					 printf("Number of cards added: %d\n", j);
					drawCard(i, &testState);
				}
				newCardCount = testState.handCount[i];
				 if ((oldCardCount +4) == newCardCount)
				{
					printf("Test passed: New card count = 4.\n");
				}
				else
				{
					printf("Test failed: Incorrect number of cards added.\n");
				}
				}
			}
			}
					
		}
	}
     return 0;
}