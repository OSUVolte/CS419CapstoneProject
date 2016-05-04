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

#define TESTCARD "cutpurse"


/*
	 Here for cardtest4.c we will create a test for a cutpurse card 
	 It will include 4 different tests:
		1) receive 2 cards that are copper
		2) players all discard a copper or have none on hand
        3) No other state changes for current player
		4) No other state in kidndom/victory
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
	cardEffect(cutpurse, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 0;
	xtraCoins = 2;

	printf("coins = %d\n", testG.coins, G.coins + xtraCoins);
	assert(testG.coins == (G.coins + xtraCoins));

	printf("\n");

	int hadCopper;

	for (i = 0; i < numPlayers; i++)
	{
		if (i != thisPlayer)
		{
			hadCopper = 0;
			for (j = 0; j < G.handCount[i]; j++)
			{
				if (G.hand[i][j] == copper)
				{
					hadCopper = 1;
				}
			}

			printf("Player %d: lost %d cards and had copper = %d\n", i, G.handCount[i] - testG.handCount[i], hadCopper);
			assert(((G.handCount[i] - testG.handCount[i]) == 1) || (hadCopper == 0));

		}
	}

	printf("\n");
	
	for(i = 0; i < (treasure_map + 1); i++)
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



	return 0;
}