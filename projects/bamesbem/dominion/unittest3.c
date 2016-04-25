
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

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int currentPlayer = 0;
    
    r = initializeGame(numPlayer, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    printf ("TESTING isGameOver():\n\n\n");
    printf("--------- Test 1---------------\n");
    
    printf("If stack of province cards is empty\n");
    
    int gameResult;
    G.supplyCount[province] = 0;
    gameResult = isGameOver(&G);
    printf("isGameOver returns: %d\n", gameResult);
    if (gameResult == 1){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    printf("--------- Test 2---------------\n");
    r = initializeGame(numPlayer, k, seed, &G);
    gameResult = isGameOver(&G);
    
    printf("If no supply piles are empty\n\n");
    printf("isGameOver returns: %d\n", gameResult);
    if (gameResult == 1){
        printf("TEST FAILED\n\n");
        
    }
    else{
        printf("TEST PASSED\n\n");
    }
    
    
    printf("--------- Test 3---------------\n");
    r = initializeGame(numPlayer, k, seed, &G);
    G.supplyCount[4] = 0;
    G.supplyCount[2] = 0;
    gameResult = isGameOver(&G);
    
    printf("If two supply piles are empty\n\n");
    printf("isGameOver returns: %d\n", gameResult);
    if (gameResult == 1){
        printf("TEST FAILED\n\n");

    }
    else{
        printf("TEST PASSED\n\n");
    }
    
    
    printf("--------- Test 4---------------\n");
    r = initializeGame(numPlayer, k, seed, &G);
    G.supplyCount[4] = 0;
    G.supplyCount[2] = 0;
    G.supplyCount[5] = 0;
    gameResult = isGameOver(&G);
    
    printf("If three supply piles are empty\n\n");
    printf("isGameOver returns: %d\n", gameResult);
    if (gameResult == 1){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    printf("\n\n------- TESTS FINISHED ----------------\n");


    return 0;
}