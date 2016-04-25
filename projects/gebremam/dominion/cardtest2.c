/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS362_SP2016
 * Assignment 3
 * Description: Unit test for smithy card in dominion.c
 * 
 * The following lines were also included makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 * gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main() {
	int seed = 1000;
	int player = 0;
	int numPlayers = 2;
	int handPos = 0;
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, mine, remodel, smithy, village, salvager, sea_hag, treasure_map};
	initializeGame(numPlayers, k, seed, &G);
        int testHand1[]= {copper, silver, estate, feast, smithy};
   	int origCount=G.handCount[player];	
	//int s=smithyRefactored(&G, player, handPos);
 
  	memcpy(G.hand[0], testHand1, sizeof(int)*5);


	cardEffect(smithy, 0, 0, 0, &G, 4, 0);
	printf("Expected HandSize: %d - Result %d\n", origCount+3-1, G.handCount[player]);
	assert(G.handCount[player] == origCount+3-1); 
			
	return 0;
}
