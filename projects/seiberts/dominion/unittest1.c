//Shawn Seibert
//Unit test 1
//updateCoins()
//Purpose: Test updateCoins by modifying the players hand
//		   and modifying the values of the coins.
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


	printf("-----------------Unit Test 1 ----------------------\n");	
	printf("--------------- updateCoins() ----------------------\n");

	// ----------- TEST 1: coins = 0  --------------
	printf("TEST 1: Set copper coins equal to 5\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	
  //reset coin count
   testState.coins = 0;
  
  testState.handCount[player] = 3;
  for (i = 0; i < 3; i++)
  {
	  testState.hand[player][i] = copper;
  }
  
 printf("Number of Copper Cards: %d\n", testState.handCount[player]);
  for (i = 0; i < testState.handCount[player]; i++)
  {
    if (testState.hand[player][i] == copper)
	{
	  testState.coins += 5;
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
  printf("Copper coin total: %d\n", testState.coins);
  if (testState.coins == 15)
  {
	  printf("Test 1 passed.\n");
  }
  else
  {
	  printf("Test 1 failed.\n");
  }
  testState.coins = 0;
  
  printf("-----------------Unit Test 2 ----------------------\n");	
  printf("--------------- updateCoins() ----------------------\n");

	// ----------- TEST 1: coins = 0  --------------
	printf("TEST 2: Set silver coins equal to 10\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	
  //reset coin count
   testState.coins = 0;
  
  testState.handCount[player] = 3;
  for (i = 0; i < 3; i++)
  {
	  testState.hand[player][i] = silver;
  }
  
 printf("Number of Silver Cards: %d\n", testState.handCount[player]);
  for (i = 0; i < testState.handCount[player]; i++)
  {
    if (testState.hand[player][i] == copper)
	{
	  testState.coins += 1;
	}
      else if (testState.hand[player][i] == silver)
	{
	  testState.coins += 10;
	}
      else if (testState.hand[player][i] == gold)
	{
	  testState.coins += 3;
	}	
  }	

  //add bonus
  testState.coins += bonus;
  printf("Silver coin total: %d\n", testState.coins);
  if (testState.coins == 30)
  {
	  printf("Test 2 passed.\n");
  }
  else
  {
	  printf("Test 2 failed.\n");
  }
  testState.coins = 0;
  
  printf("-----------------Unit Test 3 ----------------------\n");	
  printf("--------------- updateCoins() ----------------------\n");

	// ----------- TEST 1: coins = 0  --------------
	printf("TEST 3: Set Gold coins equal to 15\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	
  //reset coin count
   testState.coins = 0;
  
  testState.handCount[player] = 3;
  for (i = 0; i < 3; i++)
  {
	  testState.hand[player][i] = gold;
  }
  
  printf("Number of Gold Cards: %d\n", testState.handCount[player]);
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
	  testState.coins += 15;
	}	
  }	

  //add bonus
  testState.coins += bonus;
  printf("Gold coin total: %d\n", testState.coins);
  if (testState.coins == 45)
  {
	  printf("Test 3 passed.\n");
  }
  else
  {
	  printf("Test 3 failed.\n");
  }
  testState.coins = 0;
  
  printf("-----------------Unit Test 4 ----------------------\n");	
  printf("--------------- updateCoins() ----------------------\n");

	// ----------- TEST 1: coins = 0  --------------
	printf("TEST 4: Set copper to 5, silver to 10, gold to 15\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	
  //reset coin count
   testState.coins = 0;
  testState.handCount[player] = 3;
  testState.hand[player][0] = copper;
  testState.hand[player][1] = silver;
  testState.hand[player][2] = gold;
  
  printf("Total number cards: %d\n", testState.handCount[player]);
  for (i = 0; i < testState.handCount[player]; i++)
  {
    if (testState.hand[player][i] == copper)
	{
	  testState.coins += 5;
	}
      else if (testState.hand[player][i] == silver)
	{
	  testState.coins += 10;
	}
      else if (testState.hand[player][i] == gold)
	{
	  testState.coins += 15;
	}	
  }	

  //add bonus
  testState.coins += bonus;
  printf("All coin total: %d\n", testState.coins);
  if (testState.coins == 30)
  {
	  printf("Test 4 passed.\n");
  }
  else
  {
	  printf("Test 4 failed.\n");
  }
  testState.coins = 0;
  
  
  
  
  return 0;
}