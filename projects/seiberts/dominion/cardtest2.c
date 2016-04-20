//Shawn Seibert
//Card Test 2
//smithyCard()
//gcc cardtest2.c dominion.c rngs.c -o cardtest2 -lm 

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
	int drawTotal = 3;
	int loopCount = 0;
	int currentPlayer = 1;
	int handPos = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
				smithy, council_room};

	printf("-------------------SMITHY CARD TEST---------------------\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &testState);
	
	int i = 0;
      //+3 Cards
      for (i = 0; i <= 3; i++) //Use i <= 3
	{
		loopCount++;
		printf("Drawing card: %d\n", loopCount);
	  drawCard(currentPlayer, &state);
	}
	if (loopCount != drawTotal)
	{
		printf("Test Failed: LoopCount = %d  |   Draw total should be: %d\n", loopCount, drawTotal);
	}
	else
	{
		printf("Test Passed: LoopCount = %d  |   Draw total should be: %d\n", loopCount, drawTotal);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, &state, 0);
      return 0;
		
}