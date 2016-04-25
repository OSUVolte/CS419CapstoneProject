/* -----------------------------------------------------------------------
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 *
 *
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
    int toFlag;
    int currentPlayer = 0;
    int supplyPos = 1;
    
    // Initialize Game
    r = initializeGame(numPlayer, k, seed, &G);
    // Copy game to testG
    memcpy(&testG, &G, sizeof(struct gameState));
    
    printf ("TESTING gainCard():\n\n\n");
    printf("------------ Test 1 (toFlag = 0) -------------- \n");
    
    toFlag = 0;
    gainCard(supplyPos, &G, toFlag, currentPlayer);
    printf("Discard count: actual: %d, expected %d\n", G.discardCount[0], testG.discardCount[0] + 1);
    if (G.discardCount[0] == testG.discardCount[0] + 1 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("supplyPos is discarded: actual %d, expected %d\n", G.discard[currentPlayer][G.discardCount[0] - 1 ], supplyPos);
    
    if (G.discard[currentPlayer][G.discardCount[0] - 1 ] == supplyPos){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("SupplyCount: actual %d, expected: %d\n", G.supplyCount[supplyPos], testG.supplyCount[supplyPos] -1 );
    if (G.supplyCount[supplyPos] == testG.supplyCount[supplyPos] -1 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("\n------------ Test 2 (toFlag = 1) -------------- \n");
    
    r = initializeGame(numPlayer, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    
    toFlag = 1;
    gainCard(supplyPos, &G, toFlag, currentPlayer);
    printf("Deck count: actual: %d, expected %d\n", G.deckCount[0], testG.deckCount[0] + 1);
    if (G.deckCount[0] == testG.deckCount[0] + 1){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("supplyPos is added to deck: actual %d, expected %d\n", G.deck[currentPlayer][G.deckCount[0] - 1 ], supplyPos);
    
    if (G.deck[currentPlayer][G.deckCount[0] - 1 ] == supplyPos){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("SupplyCount: actual %d, expected: %d\n", G.supplyCount[supplyPos], testG.supplyCount[supplyPos] -1 );
    if (G.supplyCount[supplyPos] == testG.supplyCount[supplyPos] -1 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("\n------------ Test 3 (toFlag = 2) -------------- \n");
    
    r = initializeGame(numPlayer, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    
    toFlag = 2;
    gainCard(supplyPos, &G, toFlag, currentPlayer);
    
    printf("Hand count: actual: %d, expected %d\n", G.handCount[0], testG.handCount[0] + 1);
    if (G.deckCount[0] == testG.deckCount[0] + 1){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("supplyPos is added to hand: actual %d, expected %d\n", G.hand[currentPlayer][G.handCount[0] - 1 ], supplyPos);
    
    if (G.hand[currentPlayer][G.handCount[0] - 1 ] == supplyPos){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("SupplyCount: actual %d, expected: %d\n", G.supplyCount[supplyPos], testG.supplyCount[supplyPos] -1 );
    if (G.supplyCount[supplyPos] == testG.supplyCount[supplyPos] -1 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("\n------------ Test 4 supplyCount is 0 -------------- \n");
    
    r = initializeGame(numPlayer, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    G.supplyCount[currentPlayer] = 0;
    toFlag = 0;
    int result;
    result = gainCard(supplyPos, &G, toFlag, currentPlayer);
    
    if (result){
        printf("TEST FAILED\n\n");
    }
    else{
        printf("TEST PASSED\n\n");
    }
    
    printf(" --------------- TESTS FINISHED ---------------");
    
    return 0;
}