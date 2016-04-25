/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


//Testing adventurer card


int main()
{
	int seed = 2000;
    int numPlayers = 2;
    int thisPlayer = 0;
	int kingdomCount, kingdomCountTest;
	int i;
	
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("******************************* TESTING adventurer Card *******************************\n\n");		
	// initialize a game state
	initializeGame(numPlayers, k, seed, &G);
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	printf("TESTING that hand count for current player is 1 more than it started at (Gain 2 treasures, but lose adventurer card)\n");
	printf("\tHand Count: %d\tExpected: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1);
	
	printf("TESTING that deck card count for current player stayed went down\n");
	printf("\tDeck Count: %d\tExpected: < %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);

	printf("TESTING that hand count for other player stayed the same\n");
	printf("\tHand Count: %d\tExpected: %d\n", testG.handCount[thisPlayer + 1], G.handCount[thisPlayer + 1]);
	
	printf("TESTING that total card count for other player stayed the same\n");
	printf("\tCard Count: %d\tExpected: %d\n", testG.deckCount[thisPlayer + 1] + testG.handCount[thisPlayer + 1] + testG.discardCount[thisPlayer + 1], G.deckCount[thisPlayer + 1] + G.handCount[thisPlayer + 1] + G.discardCount[thisPlayer + 1]);
	
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