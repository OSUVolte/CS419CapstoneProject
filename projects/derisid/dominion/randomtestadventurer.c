//Random test for adventurerCard

#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int oracleTest(struct gameState* G, struct gameState* testG);

int main()
{
	srand(time(NULL));
	int seed = 1000;
    int numPlayer = 2;
    struct gameState G, testG;
    int cardCount;
    int i, j, l;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int coins[3] = {copper, silver, gold};
	int numTests = 20;
	int coinCount;
	int thisPlayer = 0;
	int coinGoesHere;
	int randomCoin;
	int oracleResults;
	int randomCard;

    //generate a random deck size and populate deck with random card choice
    //generate random coin type and insert randomly into randomly generated deck

    for(i = 0; i < numTests; i++)
    {
    	initializeGame(numPlayer, k, seed, &G);
    	cardCount = (rand() % 30);
    	for(j = 0; j < cardCount; j++)
    	{
    		randomCard = rand() % 10;
    		G.deck[thisPlayer][j] = k[randomCard];
    	}

    	coinCount = rand() % (G.deckCount[thisPlayer] + 1);
    	for(l = 0; l < coinCount; l++)
    	{
    		coinGoesHere = rand() % G.deckCount[thisPlayer];
    		randomCoin = rand() % 3;
    		G.deck[thisPlayer][coinGoesHere] = coins[randomCoin];
    	}

    	memcpy(&testG, &G, sizeof(struct gameState));

    	oracleResults = oracleTest(&testG, &G);

    	printf("\n\nTest iteration: %d, Number of Failures: %d\n\n", i+1, oracleResults);

    	printf("---------- adventurerCard testing completed. ----------\n\n");

    }


return 0;

}

int oracleTest(struct gameState* G, struct gameState* testG)
{

    int thisPlayer = 0;
    int cardsBeforeHand;
    int z = 0;
    int cardDrawn = 0;
    int drawntreasure = 0;
    int temphand[MAX_HAND];
    int numFails = 0;
    

	printf("----------------- Testing Card: Adventurer ----------------\n");

	printf("----------- Test 1:  Player hand card count should increase by 2 ----------\n");
	cardsBeforeHand = testG->handCount[thisPlayer];
	adventurerCard(drawntreasure, testG, thisPlayer, cardDrawn, z, temphand);
	if(testG->handCount[thisPlayer] == cardsBeforeHand + 2)
		printf("TEST PASSED \n");
	else{
		printf("TEST FAILED \n");
		numFails++;
	}
	printf("----------- Test 2:  Deck count should decrease ----------\n");
	if(testG->deckCount[thisPlayer] < G->deckCount[thisPlayer])
		printf("TEST PASSED \n");
	else
	{
		printf("TEST FAILED \n");		
		numFails++;
	}

	printf("----------- Test 3:  Discard should increase or remain unchanged ----------\n");
	if(testG->discardCount[thisPlayer] >= G->discardCount[thisPlayer])
		printf("TEST PASSED \n");
	else{
		printf("TEST FAILED \n");
		numFails++;
	}
	printf("----------- Test 4:  Difference in deck amt should reflect discard + 2 ----------\n");
	if(testG->deckCount[thisPlayer] >= G->deckCount[thisPlayer])
		printf("TEST PASSED \n");
	else{
		printf("TEST FAILED \n");
		numFails++;
	}

	printf("----------- Test 5:  Opponents state should remain unchanged ----------\n");
	
	thisPlayer = 1;
	
	printf("--- Opponent handcount unchanged? ---\n");
    if(testG->handCount[thisPlayer] == G->handCount[thisPlayer])
    	printf("TEST PASSED\n");
  	else{
    	printf("TEST FAILED\n");
    	numFails++;
	}

	int j;
	printf("--- Opponent hand unchanged? ---\n");
	for (j = 0; j < G->handCount[thisPlayer]; j++)
  	{
	    if(testG->hand[thisPlayer][j] == G->hand[thisPlayer][j])
	      printf("TEST PASSED\n");
	    else{
	      printf("TEST FAILED\n");
	  	  numFails++;
	  	}
  	}
	printf("--- Opponent deckcount unchanged? ---\n");
	if(testG->deckCount[thisPlayer] == G->deckCount[thisPlayer])
	  printf("TEST PASSED\n");
	else{
	  printf("TEST FAILED\n");
	  numFails++;
	}

	printf("--- Opponent deck unchanged? ---\n");
	for (j = 0; j < G->deckCount[thisPlayer]; j++)
	{
	   	if(testG->deck[thisPlayer][j] == G->deck[thisPlayer][j])
		   printf("TEST PASSED\n");
		else{
		   printf("TEST FAILED\n");
		   numFails++;
		}
	}
		
	printf("--- Opponent discardcount unchanged? ---\n");
	if(testG->discardCount[thisPlayer] == G->discardCount[thisPlayer])
	  printf("TEST PASSED\n");
	else{
	  printf("TEST FAILED\n");
	  numFails++;
	}

	printf("--- Opponent discard unchanged? ---\n");
	for (j = 0; j < G->discardCount[thisPlayer]; j++)
	{
	    if(testG->discard[thisPlayer][j] == G->discard[thisPlayer][j])
	      printf("TEST PASSED\n");
	    else{
	      printf("TEST FAILED\n");
	  	  numFails++;
	  	}
	}

 return numFails;
}