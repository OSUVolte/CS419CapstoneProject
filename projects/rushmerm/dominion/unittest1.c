/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Unit Test for updateCoins()
*************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTFCN "updateCoins()"

int main() {
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int thisPlayer = 0;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf("----------------- Testing Function: %s ----------------\n", TESTFCN);
    
    // Test 1
    printf("TEST 1: Verify 5 coins added for all coppers in hand\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.hand[thisPlayer][0] = copper;
    testG.hand[thisPlayer][1] = copper;
    testG.hand[thisPlayer][2] = copper;
    testG.hand[thisPlayer][3] = copper;
    testG.hand[thisPlayer][4] = copper;
    updateCoins(thisPlayer, &testG, 0);
    if(testG.coins == G.coins + 5) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

     // Test 2
    printf("TEST 1: Verify 7 coins added for all coppers in hand and 2 bonus\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.hand[thisPlayer][0] = copper;
    testG.hand[thisPlayer][1] = copper;
    testG.hand[thisPlayer][2] = copper;
    testG.hand[thisPlayer][3] = copper;
    testG.hand[thisPlayer][4] = copper;
    updateCoins(thisPlayer, &testG, 2);
    if(testG.coins == G.coins + 7) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    // Test 3
    printf("TEST 3: Verify 10 coins added for all silvers in hand\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.hand[thisPlayer][0] = silver;
    testG.hand[thisPlayer][1] = silver;
    testG.hand[thisPlayer][2] = silver;
    testG.hand[thisPlayer][3] = silver;
    testG.hand[thisPlayer][4] = silver;
    updateCoins(thisPlayer, &testG, 0);
    if(testG.coins == G.coins + 10) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    // Test 4
    printf("TEST 4: Verify 15 coins added for all gold in hand\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.hand[thisPlayer][0] = gold;
    testG.hand[thisPlayer][1] = gold;
    testG.hand[thisPlayer][2] = gold;
    testG.hand[thisPlayer][3] = gold;
    testG.hand[thisPlayer][4] = gold;
    updateCoins(thisPlayer, &testG, 0);
    if(testG.coins == G.coins + 15) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFCN);

    return 0;
}



