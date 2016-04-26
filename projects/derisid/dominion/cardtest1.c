//Test for smithyCard

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
    int handPos = 0;
    int i = 0;
    int cardsBeforeHand;
    int cardsBeforeDeck;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	struct gameState G, testG;

	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing Card: Smithy ----------------\n");

	printf("----------- Test 1:  Player should have 3+ cards ----------\n");
	cardsBeforeHand = testG.handCount[thisPlayer];
	cardsBeforeDeck = testG.handCount[thisPlayer];
	smithyCard(thisPlayer, &testG, handPos, i);
	 
	if(testG.handCount[thisPlayer] == (cardsBeforeHand + 2))
    	printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");

	printf("------- Test 2: Player pile should have 3 fewer cards -------\n");
  	if(testG.deckCount[thisPlayer] == (cardsBeforeDeck - 3))
    	printf("TEST PASSED\n");
 	else
    	printf("TEST FAILED\n");

    printf("------- Test 3: Opponents state should remain unchanged -------\n");
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

	printf("------- Test 4: Victory Card state should remain unchanged -------\n");
	printf("--- Checking the estate state ---\n");
  	if(testG.supplyCount[estate] == G.supplyCount[estate])
    	printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");
  
  	printf("--- Checking the duchy state ---\n");
  	if(testG.supplyCount[duchy] == G.supplyCount[duchy])
    	printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");
  
  	printf("--- Checking the province state ---\n");
  	if(testG.supplyCount[province] == G.supplyCount[province])
    	printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");


    printf("------- Test 5: Kingdom Card state should remain unchanged -------\n");
	  printf("--- Checking adventurer ---\n");
	  if(testG.supplyCount[adventurer] == G.supplyCount[adventurer])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	  
	  printf("--- Checking embargo ---\n");
	  if(testG.supplyCount[embargo] == G.supplyCount[embargo])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	  
	  printf("--- Checking village ---\n");
	  if(testG.supplyCount[village] == G.supplyCount[village])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	  
	  printf("--- Checking minion ---\n");
	  if(testG.supplyCount[minion] == G.supplyCount[minion])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	 
	  printf("--- Checking mine ---\n");
	  if(testG.supplyCount[mine] == G.supplyCount[mine])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	 
	  printf("--- Checking cutpurse ---\n");
	  if(testG.supplyCount[cutpurse] == G.supplyCount[cutpurse])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	  
	  printf("--- Checking seahag ---\n");
	  if(testG.supplyCount[sea_hag] == G.supplyCount[sea_hag])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	  
	  printf("--- Checking tribute ---\n");
	  if(testG.supplyCount[tribute] == G.supplyCount[tribute])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");
	  
	  printf("--- Checking councilroom ---\n");
	  if(testG.supplyCount[council_room] == G.supplyCount[council_room])
	    printf("TEST PASSED\n");
	  else
	    printf("TEST FAILED\n");

  printf("---------- smithyCard testing completed. ----------\n\n");

 return 0;
}