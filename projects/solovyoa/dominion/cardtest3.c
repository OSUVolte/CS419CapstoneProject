/*
	Andriy Solovyov
	CS-362
	Assignment 3
        cardtest3.c


Description:
	(20 points) Write unit tests for four Dominion cards implemented in dominion.c.  
	These tests should be checked in as cardtest1.c, cardtest2.c,cardtest3.c, and cardtest4.c. 
	(For example, create a test for smithy card.). It is mandatory to test smithy and adventurer card. 

*/


#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h>  
#include <stdlib.h>
#include "rngs.h"

#define TESTCARD "sea_hug"


/*
	 Here for cardtest3.c we will create a test for a sea_hug card 
	 It will include 4 different tests:
		1) deck size remains the same and discard 1
		2) puts a curse card on top of the players deck
                3) No other state changes for current player
		4) No change in state to the victory and kindom card piles
*/


int main() {
   	int i,j,m;
  	int equal;
    	int successFlag = 0;
    	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    	int seed = 1000;
    	int numPlayers = 2;
    	int thisPlayer = 0;
    	int secPlayer = 1;
        int remove1, remove2;
        int xtraCoins = 0;
	int shuffledCards = 0;
	
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int newCards = 0;
    	int discarded = 1;
   	int cardTemp = 0;
   
	
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(sea_hag, choice1, choice2, choice3, &testG, handpos, &bonus);

	for (i = 0; i < numPlayers; i++)
	{
		if (i != thisPlayer)
		{
			printf("Player %d deck size= %d, expected = %d\n", i, testG.deckCount[i], G.deckCount[i]);
			printf("Player %d discard size= %d, expected = %d\n", i, testG.discardCount[i], G.discardCount[i] + 1);
			assert(testG.discardCount[i] == (G.discardCount[i] + 1));
		}
	}

	for (i = 0; i < numPlayers; i++)
	{
		if (i != thisPlayer)
		{
			printf("Player %d: Top card = %d, expected = 0 (curse card)\n", i, testG.deck[i][testG.deckCount[i] - 1]);
		}	
	}


	for (j = 0; j < MAX_DECK; j++)
	{
		assert(testG.deck[thisPlayer][j] == G.deck[thisPlayer][j]);
	}

	printf("Current player: deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);

	printf("Asserting here that cards in current player's discard pile haven't changed.\n");
	for (j = 0; j < MAX_DECK; j++)
	{
		assert(testG.discard[thisPlayer][j] == G.discard[thisPlayer][j]);
	}

	printf("Current player: discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);
	printf("\n");


	for (i = 1; i < (treasure_map + 1); i++)
	{
		printf("Card %d: supply count = %d, expected = %d\n", i, testG.supplyCount[i], G.supplyCount[i]);
		assert(testG.supplyCount[i] == G.supplyCount[i]);
	}

	printf("\n");

	for(i = 0; i < (treasure_map + 1); i++)
	{
		printf("Card %d: embargo tokens = %d, expected = %d\n", i, testG.embargoTokens[i], G.embargoTokens[i]);
		assert(testG.embargoTokens[i] == G.embargoTokens[i]);
	}

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	

	return 0;
}