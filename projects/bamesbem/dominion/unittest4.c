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


int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int trashFlag = 0;
    int currentPlayer = 0;
    int handPos = 4;
    int bonus;
    int maxHandCount = 5;
    int maxBonus = 10;
    // arrays of all coppers, silvers, and golds
    int coppers[maxHandCount];
    int silvers[maxHandCount];
    int golds[maxHandCount];
    for (i = 0; i < maxHandCount; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

   
    // Initialize Game
    r = initializeGame(numPlayer, k, seed, &G);
    
    printf ("TESTING updateCoins():\n");
    
    printf("--------- Test 1---------------\n");
    printf("Testing all copper. No bonus\n");
    bonus = 0;
    G.handCount[currentPlayer] = maxHandCount;
    memcpy(G.hand[currentPlayer], coppers, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  5);
    if (G.coins == 5 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }

    printf("Testing all silver. No bonus\n");
    bonus = 0;
    G.handCount[currentPlayer] = maxHandCount;
    memcpy(G.hand[currentPlayer], silvers, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  10);
    if (G.coins == 10 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("Testing all gold. No bonus\n");
    bonus = 0;
    G.handCount[currentPlayer] = maxHandCount;
    memcpy(G.hand[currentPlayer], golds, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  15);
    if (G.coins == 15 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("--------- Test 2---------------\n");
    printf("Testing all copper. 3 bonus\n");
    r = initializeGame(numPlayer, k, seed, &G);
    bonus = 3;
    G.handCount[currentPlayer] = maxHandCount;
    memcpy(G.hand[currentPlayer], coppers, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  8);
    if (G.coins == 8 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("Testing all silver. 3 bonus\n");
    bonus = 3;
    G.handCount[currentPlayer] = maxHandCount;
    memcpy(G.hand[currentPlayer], silvers, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  13);
    if (G.coins == 13 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("Testing all gold. 3 bonus\n");
    bonus = 3;
    G.handCount[currentPlayer] = maxHandCount;
    memcpy(G.hand[currentPlayer], golds, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  18);
    if (G.coins == 18 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("--------- Test 3---------------\n");
    printf("Testing no treasure. No bonus\n");
    r = initializeGame(numPlayer, k, seed, &G);
    bonus = 0;
    G.handCount[currentPlayer] = maxHandCount;
    int emptyHand[maxHandCount];
    for (i = 0; i < maxHandCount; i++){
        emptyHand[i] = smithy;
    }
    memcpy(G.hand[currentPlayer], emptyHand, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  0);
    if (G.coins == 0 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
   
    printf("--------- Test 4---------------\n");
    printf("Testing no treasure. 5 bonus\n");
    r = initializeGame(numPlayer, k, seed, &G);
    bonus = 5;
    G.handCount[currentPlayer] = maxHandCount;
    emptyHand[maxHandCount];
    for (i = 0; i < maxHandCount; i++){
        emptyHand[i] = smithy;
    }
    memcpy(G.hand[currentPlayer], emptyHand, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  5);
    if (G.coins == 5 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("--------- Test 5---------------\n");
    printf("Mixed hand. 10 bonus\n");
    r = initializeGame(numPlayer, k, seed, &G);
    bonus = 10;
    G.handCount[currentPlayer] = maxHandCount;
    int mixedHand[maxHandCount];
    mixedHand[0] = copper;
    mixedHand[1] = smithy;
    mixedHand[2] = province;
    mixedHand[3] = gold;
    mixedHand[4] = village;

    memcpy(G.hand[currentPlayer], mixedHand, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  14);
    if (G.coins == 14 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    printf("--------- Test 6---------------\n");
    printf("Mixed hand. 0 bonus\n");
    r = initializeGame(numPlayer, k, seed, &G);
    bonus = 0;
    G.handCount[currentPlayer] = maxHandCount;
    mixedHand[maxHandCount];
    mixedHand[0] = copper;
    mixedHand[1] = smithy;
    mixedHand[2] = province;
    mixedHand[3] = gold;
    mixedHand[4] = silver;

    memcpy(G.hand[currentPlayer], mixedHand, sizeof(int) * maxHandCount);
    updateCoins(currentPlayer, &G, bonus);
    printf("Coin Count: actual: %d, expected %d\n", G.coins,  6);
    if (G.coins == 6 ){
        printf("TEST PASSED\n\n");
    }
    else {
        printf("TEST FAILED\n\n");
    }
    
    
    printf("------- TESTS FINISHED ---------- \n\n");
    
    return 0;
}