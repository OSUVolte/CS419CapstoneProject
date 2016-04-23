/* -----------------------------------------------------------------------
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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
	
	printf("******************************* TESTING isGameOver *******************************\n\n");
	
	printf("TESTING with an empty province stack:\t\t\t\t\t\t\t");
	initializeGame(numPlayers, k, seed, &G);
	// Empty the Province stack
	G.supplyCount[province] = 0;
	r = isGameOver(&G);
	printf("\tReturn value: %d\tExpected Value: 1\n\n", r);
	
	printf("TESTING with no empty stacks:\t\t\t\t\t\t\t\t");
	initializeGame(numPlayers, k, seed, &G);
	r = isGameOver(&G);
	printf("\tReturn value: %d\tExpected Value: 0\n\n", r);
	
	printf("TESTING with empty adventurer and council_room stacks:(only 2 empty stacks)\t\t");
	initializeGame(numPlayers, k, seed, &G);
	G.supplyCount[adventurer] = 0;
	G.supplyCount[council_room] = 0;
	r = isGameOver(&G);
	printf("\tReturn value: %d\tExpected Value: 0\n\n", r);
	
	printf("TESTING with an empty adventurer, council_room, and feast stack:(first 3 'action cards')");
	initializeGame(numPlayers, k, seed, &G);
	// Empty the feast, mine, and smithy stack
	G.supplyCount[adventurer] = 0;
	G.supplyCount[council_room] = 0;
	G.supplyCount[feast] = 0;
	r = isGameOver(&G);
	printf("\tReturn value: %d\tExpected Value: 1\n\n", r);
	
	printf("TESTING with an empty salvager, sea_hag, and treasure_map stack:(last 3 'action cards')\t");
	initializeGame(numPlayers, k, seed, &G);
	// Empty the feast, mine, and sea_hag stack
	G.supplyCount[outpost] = 0;
	G.supplyCount[salvager] = 0;
	G.supplyCount[sea_hag] = 0;
	r = isGameOver(&G);
	printf("\tReturn value: %d\tExpected Value: 1\n\n", r);
	
	
	return 0;
}