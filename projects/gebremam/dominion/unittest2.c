/* -----------------------------------------------------------------------
 * unit test for isGameOver() function in dominion.c
 * Include the following lines in your makefile:
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

int main() {
    
    int i;
    int seed = 1000;
    int numPlayer = 2;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, salvager, sea_hag, treasure_map};
    struct gameState G;

    printf ("TESTING isGameOver():\n\n");

    memset(&G, 0, sizeof(struct gameState));   // clear the game state

    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    // set all supply counts to 8
	for (i = 0; i < 27; i++)
	{
		G.supplyCount[i] = 8;
	}
    printf("all supply counts >0\n"); 
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 0);
    assert(isGameOver(&G) == 0);  // test game isn't finished
    

    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //set only 2 of the supply card piles to 0
    printf("Test: only 2 of the supply card piles set to 0\n");
    G.supplyCount[0] = 0;
    G.supplyCount[k[8]] = 0;
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 0);
    assert(isGameOver(&G) == 0);  // test game isn't finished
	
    
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    // set providence pile to 0 
    G.supplyCount[3]=0;
    printf("providence pile set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
    
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    // set all 3 treasure card piles to 0
    for (i = 4; i<=6; i++){
	G.supplyCount[i] = 0;
    }
    printf("3 treasure card piles set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
    
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //set the curse pile, 1 of the victory piles (not providence), and 1 of the treasure piles to 0
    G.supplyCount[0] = 0;
    G.supplyCount[1] = 0;
    G.supplyCount[4] = 0;
    printf("three piles (curse, estate, and copper) set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
    
   
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //set 1 of the victory piles, 1 of the treasure piles, and 1 of the kingdom piles to 0
    G.supplyCount[1] = 0;
    G.supplyCount[5] = 0;
    G.supplyCount[k[5]] = 0;
    printf("three piles (estate, silver, and remodel) set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
    
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //set 2 of the kingdom piles and 1 of the victory piles to 0
    G.supplyCount[k[0]] = 0;
    G.supplyCount[k[1]] = 0;
    G.supplyCount[2] = 0;
    printf("three piles (adventurer, council_room, and duchy) set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
    
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //set 2 of the kingdom piles and 1 of the treasury piles to 0
    G.supplyCount[k[2]] = 0;
    G.supplyCount[k[4]] = 0;
    G.supplyCount[5] = 0;
    printf("three piles(feast, gardens, and silver) set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
    
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //set 3 of the selected kingdom card piles to 0
    G.supplyCount[k[1]] = 0;
    G.supplyCount[k[8]] = 0;
    G.supplyCount[k[9]] = 0;
    printf("3 kingdom piles (adventurer, sea_hag, and treasure_map set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
    
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //set the curse pile, 1 of the victory piles (not providence), and 1 of the kingdom piles, to 0
    G.supplyCount[0] = 0;
    G.supplyCount[1] = 0;
    G.supplyCount[k[9]] = 0;
    printf("three piles (curse, estate, and treasure_map)set to 0\n");
    printf("returned = %d, expected = %d\n\n", isGameOver(&G), 1);
    assert(isGameOver(&G) == 1);  // test game isn't finished
   
    printf("All tests passed!\n");
    return 0;
   
}
