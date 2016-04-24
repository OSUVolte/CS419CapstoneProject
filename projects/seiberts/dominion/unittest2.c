//Shawn Seibert
//Unit test 2
//scoreFor()
// gcc unittest2.c dominion.c rngs.c -o unittest2 -lm
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	int supplyPos, i;
	int score = 0;
	struct gameState state, testState;
	int toFlag;
	int player;
	int seed = 100;
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, 
				smithy, council_room};

	printf("-----------------Unit Test 2-1 ----------------------\n");	
	printf("----------------- scoreFor() ----------------------\n");
	printf("Test 1: Score From Hand with 10 estate cards\n");

	memcpy(&testState, &state, sizeof(struct gameState));	 

	testState.handCount[player] = 10;
	  for (i = 0; i < testState.handCount[player]; i++)
	  {
		  testState.hand[player][i] = estate;
	  }
	//score from hand
	for (i = 0; i < testState.handCount[player]; i++)
		{
		  if (testState.hand[player][i] == curse) { score = score - 1; };
		  if (testState.hand[player][i] == estate) { score = score + 1; };
		  if (testState.hand[player][i] == duchy) { score = score + 3; };
		  if (testState.hand[player][i] == province) { score = score + 6; };
		  if (testState.hand[player][i] == great_hall) { score = score + 1; };
		  if (testState.hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, &testState) / 10 ); };
		}

		 printf("SCORE: %d\n", score);
		 printf("Calculated Score: 10\n");
		 if (score == 10)
		 {
			 printf("Test 1: Passed.\n");
		 }
		 else
		 {
			  printf("Test 1: Failed.\n");
		 }
		 score = 0;
		 
		 
	printf("-----------------Unit Test 2-2 ----------------------\n");	
	printf("----------------- scoreFor() ----------------------\n");
	printf("Test 2: Score From Discard with 10 province cards\n");

	memcpy(&testState, &state, sizeof(struct gameState));	 

	testState.discardCount[player] = 10;
	
	  for (i = 0; i < testState.discardCount[player]; i++)
	  {
		  testState.discard[player][i] = province;
	  }
	  //score from discard
	  for (i = 0; i < testState.discardCount[player]; i++)
		{
		  if (testState.discard[player][i] == curse) { score = score - 1; };
		  if (testState.discard[player][i] == estate) { score = score + 1; };
		  if (testState.discard[player][i] == duchy) { score = score + 3; };
		  if (testState.discard[player][i] == province) { score = score + 6; };
		  if (testState.discard[player][i] == great_hall) { score = score + 1; };
		  if (testState.discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, &testState) / 10 ); };
		}
  printf("Test SCORE: %d\n", score);
  printf("Calculated Score: 60\n");
		 if (score == 60)
		 {
			 printf("Test 2: Passed.\n");
		 }
		 else
		 {
			  printf("Test 2: Failed.\n");
		 }
		 score = 0;
		 
	
	printf("-----------------Unit Test 2-3 ----------------------\n");	
	printf("----------------- scoreFor() ----------------------\n");
	printf("Test 3: Score From Deck with 10 Great Hall cards\n");

	memcpy(&testState, &state, sizeof(struct gameState));	 

	testState.discardCount[player] = 10;
	
	  for (i = 0; i < testState.discardCount[player]; i++)
	  {
		  testState.deck[player][i] = great_hall;
	  }	
		 
		 //score from deck
  for (i = 0; i < testState.discardCount[player]; i++)
    {
      if (testState.deck[player][i] == curse) { score = score - 1; };
      if (testState.deck[player][i] == estate) { score = score + 1; };
      if (testState.deck[player][i] == duchy) { score = score + 3; };
      if (testState.deck[player][i] == province) { score = score + 6; };
      if (testState.deck[player][i] == great_hall) { score = score + 1; };
      if (testState.deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, &state) / 10 ); };
    }
  printf("Test SCORE: %d\n", score);
  printf("Calculated Score: 10\n");
		 if (score == 10)
		 {
			 printf("Test 3: Passed.\n");
		 }
		 else
		 {
			  printf("Test 3: Failed.\n");
		 }
		 score = 0;
		 
		 
		 
		 
  return 0;
}