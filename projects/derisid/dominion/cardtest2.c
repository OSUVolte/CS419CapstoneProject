//Test for adventurerCard

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main()
{
	int seed = 1000;
    int numPlayer = 2;
    int thisPlayer = 0;
    int cardsBeforeHand;
    int z = 0;
    int cardDrawn = 0;
    int drawntreasure = 0;
    int temphand[MAX_HAND];
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	struct gameState G, testG;

	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing Card: Adventurer ----------------\n");

	printf("----------- Test 1:  Player hand card count should increase by 2 ----------\n");
	cardsBeforeHand = testG.handCount[thisPlayer];
	adventurerCard(drawntreasure, &testG, thisPlayer, cardDrawn, z, temphand);
	if(testG.handCount[thisPlayer] == cardsBeforeHand + 2)
		printf("TEST PASSED \n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 2:  Deck count should decrease ----------\n");
	if(testG.deckCount[thisPlayer] < G.deckCount[thisPlayer])
		printf("TEST PASSED \n");
	else
		printf("TEST FAILED \n");		

	printf("----------- Test 3:  Discard should increase or remain unchanged ----------\n");
	if(testG.discardCount[thisPlayer] >= G.discardCount[thisPlayer])
		printf("TEST PASSED \n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 4:  Difference in deck amt should reflect discard + 2 ----------\n");
	if(testG.deckCount[thisPlayer] >= G.deckCount[thisPlayer])
		printf("TEST PASSED \n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 5:  Opponents state should remain unchanged ----------\n");
	thisPlayer = 1;
	printf("--- Opponent handcount unchanged? ---\n");
    if(testG.handCount[thisPlayer] == G.handCount[thisPlayer])
    	printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");
	
	int j;
	printf("--- Opponent hand unchanged? ---\n");
	for (j = 0; j < G.handCount[thisPlayer]; j++)
  	{
	    if(testG.hand[thisPlayer][j] == G.hand[thisPlayer][j])
	      printf("TEST PASSED\n");
	    else
	      printf("TEST FAILED\n");
  	}
	printf("--- Opponent deckcount unchanged? ---\n");
	  if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");

	printf("--- Opponent deck unchanged? ---\n");
	for (j = 0; j < G.deckCount[thisPlayer]; j++)
	{
	   	if(testG.deck[thisPlayer][j] == G.deck[thisPlayer][j])
		   printf("TEST PASSED\n");
		else
		   printf("TEST FAILED\n");
	}
		
	printf("--- Opponent discardcount unchanged? ---\n");
	  if(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");

	printf("--- Opponent discard unchanged? ---\n");
	for (j = 0; j < G.discardCount[thisPlayer]; j++)
	{
	    if(testG.discard[thisPlayer][j] == G.discard[thisPlayer][j])
	      printf("TEST PASSED\n");
	    else
	      printf("TEST FAILED\n");
	}

	printf("---------- adventurerCard testing completed. ----------\n\n");

 return 0;
}