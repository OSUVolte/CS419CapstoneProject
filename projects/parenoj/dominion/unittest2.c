/* -----------------------------------------------------------------------
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main()
{
	int seed = 1000;
	int m, n;
	int r;
	
	int numPlayers = 4;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, sea_hag, treasure_map};
    struct gameState G;
	
	printf("******************************* TESTING scoreFor *******************************\n\n");
	
	printf("TESTING where all players have no scoring cards\n\n");
	initializeGame(numPlayers, k, seed, &G);
	//Set all cards for all players as adventurer cards (no affect on score)
	for(m = 0; m < numPlayers; m++)
	{
		for(n = 0; n < G.handCount[m]; n++)
		{
			G.hand[m][n] = adventurer;
		}
		
		for(n = 0; n < G.discardCount[m]; n++)
		{
			G.discard[m][n] = adventurer;
		}
		
		for(n = 0; n < G.deckCount[m]; n++)
		{
			G.deck[m][n] = adventurer;
		}
	}
	//Run scoreFor for both players
	for(m = 0; m < numPlayers; m++)
	{
		r = scoreFor(m, &G);
		printf("\tPlayer %d - Return value: %d\tExpected Value: 0\n\n", m + 1, r);
	}
	
	printf("TESTING where all players have all estate cards\n\n");
	initializeGame(numPlayers, k, seed, &G);
	//Set handCount, discardCount, and deckCount to 5 for all players
	for(m = 0; m < numPlayers; m++)
	{
		G.handCount[m] = 5;
		G.discardCount[m] = 5;
		G.deckCount[m] = 5;
	}
	//Set all cards for all players as adventurer cards (no affect on score)
	for(m = 0; m < numPlayers; m++)
	{
		for(n = 0; n < G.handCount[m]; n++)
		{
			G.hand[m][n] = estate;
		}
		
		for(n = 0; n < G.discardCount[m]; n++)
		{
			G.discard[m][n] = estate;
		}
		
		for(n = 0; n < G.deckCount[m]; n++)
		{
			G.deck[m][n] = estate;
		}
	}
	//Run scoreFor for both players
	for(m = 0; m < numPlayers; m++)
	{
		r = scoreFor(m, &G);
		printf("\tPlayer %d - Return value: %d\tExpected Value: %d\n\n", m + 1, r, G.handCount[m] + G.discardCount[m] + G.deckCount[m]);
	}
	
	printf("TESTING where all players have all province cards\n\n");
	initializeGame(numPlayers, k, seed, &G);
	//Set handCount, discardCount, and deckCount to 5 for all players
	for(m = 0; m < numPlayers; m++)
	{
		G.handCount[m] = 5;
		G.discardCount[m] = 5;
		G.deckCount[m] = 5;
	}
	//Set all cards for all players as adventurer cards (no affect on score)
	for(m = 0; m < numPlayers; m++)
	{
		for(n = 0; n < G.handCount[m]; n++)
		{
			G.hand[m][n] = province;
		}
		
		for(n = 0; n < G.discardCount[m]; n++)
		{
			G.discard[m][n] = province;
		}
		
		for(n = 0; n < G.deckCount[m]; n++)
		{
			G.deck[m][n] = province;
		}
	}
	//Run scoreFor for both players
	for(m = 0; m < numPlayers; m++)
	{
		r = scoreFor(m, &G);
		printf("\tPlayer %d - Return value: %d\tExpected Value: %d\n\n", m + 1, r, (G.handCount[m] + G.discardCount[m] + G.deckCount[m]) * 6);
	}
	
	printf("TESTING where players have 19 smithy cards and 1 gardens card\n\n");
	initializeGame(numPlayers, k, seed, &G);
	//Set handCount, discardCount, and deckCount to 5 for all players
	for(m = 0; m < numPlayers; m++)
	{
		G.handCount[m] = 10;
		G.discardCount[m] = 10;
		G.deckCount[m] = 10;
	}
	//Set all cards for all players as smithy cards (no affect on score)
	for(m = 0; m < numPlayers; m++)
	{
		for(n = 0; n < G.handCount[m]; n++)
		{
			G.hand[m][n] = smithy;
		}
		
		for(n = 0; n < G.discardCount[m]; n++)
		{
			G.discard[m][n] = smithy;
		}
		
		for(n = 0; n < G.deckCount[m]; n++)
		{
			G.deck[m][n] = smithy;
		}
		
		G.deck[m][0] = gardens;
	}
	//Run scoreFor for both players
	for(m = 0; m < numPlayers; m++)
	{
		r = scoreFor(m, &G);
		printf("\tPlayer %d - Return value: %d\tExpected Value: %d\n\n", m + 1, r, (G.handCount[m] + G.discardCount[m] + G.deckCount[m]) / 10);
	}
	
	
	return 0;
	
	
}