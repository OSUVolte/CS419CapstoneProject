/* -----------------------------------------------------------------------
 *
 * unittest1: unittest2.c dominion.o rngs.o
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
    int seed = 1000;
    int numPlayer = 2;
    int isOver;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    initializeGame(numPlayer, k, seed, &G); // initialize a new game

    printf ("TESTING isGameOver():\n");
   
    G.supplyCount[province] = 0;
    isOver = isGameOver(&G);
    printf("isOver = %d, expected = %d\n", isOver, 1);
    assert(isOver == 1);

    G.supplyCount[province] = 3;
    isOver = isGameOver(&G);
    printf("isOver = %d, expected = %d\n", isOver, 0);
    assert(isOver == 0);

    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    G.supplyCount[feast] = 0;
    isOver = isGameOver(&G);
    printf("isOver = %d, expected = %d\n", isOver, 1);
    assert(isOver == 1);

    G.supplyCount[village] = 0;
    G.supplyCount[smithy] = 0;
    G.supplyCount[feast] = 2;
    isOver = isGameOver(&G);
    printf("isOver = %d, expected = %d\n", isOver, 0);
    assert(isOver == 0);

    G.supplyCount[village] = 2;
    G.supplyCount[smithy] = 0;
    G.supplyCount[feast] = 2;
    isOver = isGameOver(&G);
    printf("isOver = %d, expected = %d\n", isOver, 0);
    assert(isOver == 0);
    
    printf("All tests passed!\n");

    return 0;
}