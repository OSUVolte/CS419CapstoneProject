//Shawn Seibert
//Unit test 1
//updateCoins()
//gcc unittest1.c dominion.c rngs.c -o unittest1



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
	int i;
	int seed = 100;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
				smithy, council_room};
	initializeGame(numPlayers, k, seed, &testState);

	printf("-----------------Unit Test 1 ----------------------");	
	printf("--------------- updateCoins() ----------------------");

	// ----------- TEST 1: coins = 0  --------------
	printf("TEST 1: All coins = 0");
	memcpy(&testState, &state, sizeof(struct gameState));
	
  //reset coin count
  testState.coins = 0;
  //add coins for each Treasure card in player's hand
  for (i = 0; i < testState.handCount[player]; i++)
    {
      if (testState.hand[player][i] == copper)
	{
	  testState.coins += 1;
	}
      else if (testState.hand[player][i] == silver)
	{
	  testState.coins += 2;
	}
      else if (testState.hand[player][i] == gold)
	{
	  testState.coins += 3;
	}	
    }	

  //add bonus
  testState.coins += bonus;

  return 0;
}