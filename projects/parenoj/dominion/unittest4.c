/* -----------------------------------------------------------------------
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
	
	int numPlayers = 2;
		int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, sea_hag, treasure_map};
    struct gameState G;
	
	initializeGame(numPlayers, k, seed, &G);
	
	printf("******************************* TESTING handCard *******************************\n\n");
	
	printf("TESTING current player has an ascending hand starting with first card\n");
	m = 0;
	for(n = 0; n < G.handCount[G.whoseTurn]; n++)
	{
		G.hand[G.whoseTurn][n] = m;
		
		r = handCard(n, &G);
		printf("Return value: %d\tExpected: %d\n", r, m);
		m++;
	}
	printf("\n");
		
	printf("TESTING current player has an ascending hand starting with fifth card\n");
	m = 4;
	for(n = 0; n < G.handCount[G.whoseTurn]; n++)
	{
		G.hand[G.whoseTurn][n] = m;
		
		r = handCard(n, &G);
		printf("Return value: %d\tExpected: %d\n", r, m);
		m++;
	}
	printf("\n");
		
	printf("TESTING current player has an ascending hand starting with twenty-third card\n");
	m = 22;
	for(n = 0; n < G.handCount[G.whoseTurn]; n++)
	{
		G.hand[G.whoseTurn][n] = m;
		
		r = handCard(n, &G);
		printf("Return value: %d\tExpected: %d\n", r, m);
		m++;
	}
	printf("\n");
	

	
	
	return 0;
}