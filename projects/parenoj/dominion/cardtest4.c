/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


//Testing cutpurse card

int main()
{
	int seed = 2000;
    int numPlayers = 2;
    int thisPlayer = 0;
	
	int kingdomCount, kingdomCountTest, i;
	
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("******************************* TESTING cutpurse Card *******************************\n\n");		
	// initialize a game state
	initializeGame(numPlayers, k, seed, &G);
	//Create other player's hand
	G.handCount[thisPlayer + 1] = 5;
	G.hand[thisPlayer + 1][0] = copper;
	for(i = 1; i <= 4; i++)
	{
		G.hand[thisPlayer + 1][0] = smithy;
	}
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(cutpurse, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	printf("TESTING that current player gains two coins\n");
	printf("\tCoin Count: %d\tExpected: %d\n", testG.coins, G.coins + 2);
	
	printf("TESTING that hand count for current player has decreased by 1\n");
	printf("\tHand Count: %d\tExpected: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - 1);
	
	printf("TESTING that hand count for other player has decreased by 1\n");
	printf("\tHand Count: %d\tExpected: %d\n", testG.handCount[thisPlayer + 1], G.handCount[thisPlayer + 1] - 1);
	
	printf("TESTING that the victory cards stayed the same\n");
	printf("\tVictory Card Count: %d\tExpected: %d\n", testG.supplyCount[estate] + testG.supplyCount[duchy] + testG.supplyCount[province], G.supplyCount[estate] + G.supplyCount[duchy] + G.supplyCount[province]);
	
	kingdomCount = 0;
	for(i = adventurer; i <+ treasure_map; i++)
	{
		kingdomCount += G.supplyCount[i];
	}
	kingdomCountTest = 0;
	for(i = adventurer; i <+ treasure_map; i++)
	{
		kingdomCountTest += testG.supplyCount[i];
	}
	printf("TESTING that the kingdom cards stayed the same\n");
	printf("\tKingdom Card Count: %d\tExpected: %d\n", kingdomCountTest, kingdomCount);
	return 0;
	
}