//Shawn Seibert
//Card Test 3
//councilRoomCard()
//gcc cardtest3.c dominion.c rngs.c -o cardtest3 -lm


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
	int oldBuyAmount = 0, newBuyAmount = 0;
	int oldCardCount, newCardCount;
	int drawTotal = 3;
	int loopCount = 0;
	int currentPlayer = 1;
	int i = 0;
	int handPos = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
				smithy, council_room};

	printf("-------------------COUNCIL ROOM CARD TEST---------------------\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &testState);
	   //+4 Cards
	printf("CHECKING CARD DRAW AMOUNT.\n");
	for (i = 0; i <= 4; i++)
	{
		cardDrawCount++;
		printf("Drawing card: %d\n", cardDrawCount);
		drawCard(currentPlayer, &testState);
	}
	if (cardDrawCount == 4)
	{
		printf("Test Passed: LoopCount = %d  |   Draw total should be: 4\n", i);
	}
	else
	{
		printf("Test Failed: LoopCount = %d  |   Draw total should be: 4\n", i);
	}
		
	printf("CHECK BUY AMOUNT:\n");
	oldBuyAmount = testState.numBuys;
	printf("Number of buys before: %d\n",oldBuyAmount);
	oldBuyAmount = testState.numBuys;
	//+1 Buy
	testState.numActions++;
	newBuyAmount = testState.numBuys;
	printf("Number of buys after: %d\n",newBuyAmount);
	if (newBuyAmount == (oldBuyAmount + 1))
	{
		printf("Test Passed: Buy amount increased by 1\n");
	}
	else
	{
		printf("Test Failed: Buy amount did not increased by 1\n");
	}
		
      //Each other player draws a card
      for (i = 0; i < testState.numPlayers; i++)
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, &testState);
	    }
	}
	printf("CHECKING DISCARD.\n");
	printf("Current player hand count: %d\n", testState.handCount[currentPlayer] );
	oldCardCount = testState.handCount[currentPlayer];
	//Get player hand count.
      //put played card in played card pile
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
	 //write if else statement.
	  return 0;
}