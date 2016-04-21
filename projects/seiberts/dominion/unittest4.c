//Shawn Seibert
//Unit test 4
//fullDeckCount()
//gcc unittest4.c dominion.c rngs.c -o unittest4 -lm

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
	int iterator = 1;
	int seed = 100;
	int numPlayers = 2;
	int count = 0;
	int card = 10;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
				smithy, council_room};


	printf("-----------------Unit Test 4-1 ----------------------\n");	
	printf("--------------- fullDeckCount() ----------------------\n");
	printf("Test 1: Set deck count equal to 10.\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	
	testState.deckCount[player] = 10;
	for (i = 0; i < testState.deckCount[player]; i++)
	{
		testState.deck[player][i] = card;
	}
	
	for (i = 0; i < testState.deckCount[player]; i++)
    {
      
	  if (testState.deck[player][i] == card) 
	  {
		  count++;
		  
	  }
    }
/*
  for (i = 0; i < testState.handCount[player]; i++)
    {
      if (testState.hand[player][i] == card) count++;
    }

  for (i = 0; i < testState.discardCount[player]; i++)
    {
      if (testState.discard[player][i] == card) count++;
    }
	*/

	printf("COUNT: %d\n", count);
	
	if(count == 10)
	{
		printf("Test 1: Passed.\n");
	}
	else
	{
		printf("Test 1: Failed.\n");
	}
	count = 0;
	
	printf("-----------------Unit Test 4-2 ----------------------\n");	
	printf("--------------- fullDeckCount() ----------------------\n");
	printf("Test 2: Set hand count equal to 6.\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	/*
	testState.deckCount[player] = 10;
	for (i = 0; i < testState.deckCount[player]; i++)
	{
		testState.deck[player][i] = card;
	}
	
	for (i = 0; i < testState.deckCount[player]; i++)
    {
      
	  if (testState.deck[player][i] == card) 
	  {
		  count++;
		  
	  }
    }
  */
  testState.handCount[player] = 6;
  for (i = 0; i < testState.handCount[player]; i++)
  {
     testState.hand[player][i] = card;
  }
	
  for (i = 0; i < testState.handCount[player]; i++)
  {
      if (testState.hand[player][i] == card) count++;
  }
  /*
  for (i = 0; i < testState.discardCount[player]; i++)
    {
      if (testState.discard[player][i] == card) count++;
    }
	*/

	printf("COUNT: %d\n", count);
	
	if(count == 6)
	{
		printf("Test 2: Passed.\n");
	}
	else
	{
		printf("Test 2: Failed.\n");
	}
	count = 0;
	
	printf("-----------------Unit Test 4-3 ----------------------\n");	
	printf("--------------- fullDeckCount() ----------------------\n");
	printf("Test 3: Set discard count equal to 12.\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	/*
	testState.deckCount[player] = 10;
	for (i = 0; i < testState.deckCount[player]; i++)
	{
		testState.deck[player][i] = card;
	}
	
	for (i = 0; i < testState.deckCount[player]; i++)
    {
      
	  if (testState.deck[player][i] == card) 
	  {
		  count++;
		  
	  }
    }

  testState.handCount[player] = 6;
  for (i = 0; i < testState.handCount[player]; i++)
  {
     testState.hand[player][i] = card;
  }
	
  for (i = 0; i < testState.handCount[player]; i++)
  {
      if (testState.hand[player][i] == card) count++;
  }
  */
  testState.discardCount[player] = 12;
  
  for (i = 0; i < testState.discardCount[player]; i++)
	{
	  testState.discard[player][i] = card;
	}
  
  for (i = 0; i < testState.discardCount[player]; i++)
    {
      if (testState.discard[player][i] == card)
	  {
		  count++;
	  }
    }
	

	printf("COUNT: %d\n", count);
	
	if(count == 12)
	{
		printf("Test 3: Passed.\n");
	}
	else
	{
		printf("Test 3: Failed.\n");
	}
	count = 0;
	
	
  return 0;
}