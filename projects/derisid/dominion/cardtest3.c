//Test for treasure_mapCard

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
    int index = 0;
    int r;
    int j;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	struct gameState G, testG;

	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing Card: Treasure Map ----------------\n");

	printf("----------- Test 1:  Check for another treasure map ----------\n");
	testG.hand[thisPlayer][0] = treasure_map;
	r = treasure_mapCard(index, &testG, thisPlayer, i, handPos);

	if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer])
		printf("TEST PASSED\n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 2:  Trash treasure card ----------\n");
	if(testG.playedCards[testG.playedCardCount - 1] != treasure_map)
		printf("TEST PASSED\n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 3:  One map found returns -1  ----------\n");
	if(r == -1)
		printf("TEST PASSED\n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 4a:  2 maps and 4 gold  ----------\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[thisPlayer][0] = treasure_map;
	testG.hand[thisPlayer][1] = treasure_map;
	r = treasure_mapCard(index, &testG, thisPlayer, i, handPos);
	for (j = testG.deckCount[thisPlayer] - 1; j >= testG.deckCount[thisPlayer] - 4; j--)
	{
		if(testG.deck[thisPlayer][j] == gold)
			printf("TEST PASSED\n");
		else
			printf("TEST FAILED \n");
	}

	printf("----------- Test 4b:  2 maps trashed  ----------\n");
	if(testG.playedCards[testG.playedCardCount - 1] != treasure_map)
		printf("TEST PASSED\n");
	else
		printf("TEST FAILED \n");
	if(testG.playedCards[testG.playedCardCount - 2] != treasure_map)
		printf("TEST PASSED\n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 4c:  Returns 1 if two treasuremaps  ----------\n");
	if (r == 1)
		printf("TEST PASSED\n");
	else
		printf("TEST FAILED \n");

	printf("----------- Test 5:  Opponents state should remain unchanged ----------\n");
	thisPlayer = 1;
	printf("--- Opponent handcount unchanged? ---\n");
    if(testG.handCount[thisPlayer] == G.handCount[thisPlayer])
    	printf("TEST PASSED\n");
  	else
    	printf("TEST FAILED\n");
	
	//int j;
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

	printf("---------- treasure_mapCard testing completed. ----------\n\n");

 return 0;
}