/* -----------------------------------------------------------------------
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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
	int m, n, j;
	int r;
	
	int numPlayers = 2;
		int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, sea_hag, treasure_map};
    struct gameState G;
	
	printf("******************************* TESTING fullDeckCount *******************************\n\n");
	
	printf("TESTING all players have full hands of all cards\n\n");
	initializeGame(numPlayers, k, seed, &G);
	//Set all cards for all players as adventurer cards (no affect on score)
	for(m = 0; m < numPlayers; m++)
	{
		for(j = curse; j <= treasure_map; j++)
		{
			for(n = 0; n < G.handCount[m]; n++)
			{
				G.hand[m][n] = j;
			}
			
			for(n = 0; n < G.discardCount[m]; n++)
			{
				G.discard[m][n] = j;
			}
			
			for(n = 0; n < G.deckCount[m]; n++)
			{
				G.deck[m][n] = j;
			}
			
			r = fullDeckCount(m, j, &G);
			printf("Player %d - Count for Card %d:\tReturned %d\tExpected %d\n", m + 1, j, r, G.handCount[m] + G.discardCount[m] + G.deckCount[m]);
		}
	}
	
	printf("TESTING all players have full hands of cards that aren't the card we are checking\n\n");
	initializeGame(numPlayers, k, seed, &G);
	//Set all cards for all players as adventurer cards (no affect on score)
	for(m = 0; m < numPlayers; m++)
	{
		for(j = curse; j <= treasure_map; j++)
		{
			for(n = 0; n < G.handCount[m]; n++)
			{
				G.hand[m][n] = j + 1;
			}
			
			for(n = 0; n < G.discardCount[m]; n++)
			{
				G.discard[m][n] = j + 1;
			}
			
			for(n = 0; n < G.deckCount[m]; n++)
			{
				G.deck[m][n] = j + 1;
			}
			
			r = fullDeckCount(m, j, &G);
			printf("Player %d - Count for Card %d:\tReturned %d\tExpected %d\n", m + 1, j, r, 0);
		}
	}
	
	printf("TESTING all players have one card that we are checking\n\n");
	initializeGame(numPlayers, k, seed, &G);
	//Set all cards for all players as adventurer cards (no affect on score)
	for(m = 0; m < numPlayers; m++)
	{
		for(j = curse; j <= treasure_map; j++)
		{
			for(n = 0; n < G.handCount[m]; n++)
			{
				G.hand[m][n] = j + 1;
			}
			
			for(n = 0; n < G.discardCount[m]; n++)
			{
				G.discard[m][n] = j + 1;
			}
			
			for(n = 0; n < G.deckCount[m]; n++)
			{
				G.deck[m][n] = j + 1;
			}
			G.deck[m][0] = j;
			
			r = fullDeckCount(m, j, &G);
			printf("Player %d - Count for Card %d:\tReturned %d\tExpected %d\n", m + 1, j, r, 1);
		}
	}
	
	
	return 0;
	
	
}