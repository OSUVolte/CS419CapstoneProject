/*
 * unittest2.c
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"

#define TESTFUNCTION "updateCoins()"

int main() {
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, feast, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int bonus = 6;
    int GnewCoinCount = 0;
    int failedTests = 0;
    int passedTests = 0;
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
    
    // set cards in hand
    G.hand[thisPlayer][0] = smithy;
    G.hand[thisPlayer][1] = feast;
    G.hand[thisPlayer][2] = adventurer;
    G.hand[thisPlayer][3] = village;
    G.hand[thisPlayer][4] = council_room;
    updateCoins(thisPlayer, &G, 0);
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    updateCoins(thisPlayer, &testG, 0);
    
    printf("Current game state compared with expected state:\n");
    printf("\tcoin count = %d, expected = %d\n", testG.coins, G.coins);
    printf("\n");
    
    // add a copper
    testG.hand[thisPlayer][1] = copper;
    updateCoins(thisPlayer, &testG, 0);
    GnewCoinCount = G.coins + COPPER_VALUE;
    
    // ----------- Adding a copper. --------------
    printf("Testing: Adding a copper.\n");
    if(testG.coins != GnewCoinCount) {
        printf("\t**FAILED**: Coins did not update to reflect addition of copper.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Coin count is correct.\n\n");
        passedTests++;
    }
    
    // add a silver
    testG.hand[thisPlayer][4] = silver;
    updateCoins(thisPlayer, &testG, 0);
    GnewCoinCount = GnewCoinCount + SILVER_VALUE;
    
    // ----------- Adding a silver. --------------
    printf("Testing: Adding a silver.\n");
    if(testG.coins != GnewCoinCount) {
        printf("\t**FAILED**: Coins did not update to reflect addition of silver.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Coin count is correct.\n\n");
        passedTests++;
    }
    
    // add a gold
    testG.hand[thisPlayer][0] = gold;
    updateCoins(thisPlayer, &testG, 0);
    GnewCoinCount = GnewCoinCount + GOLD_VALUE;
    
    // ----------- Adding a gold. --------------
    printf("Testing: Adding a gold.\n");
    if(testG.coins != GnewCoinCount) {
        printf("\t**FAILED**: Coins did not update to reflect addition of gold.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Coin count is correct.\n\n");
        passedTests++;
    }
    
    // remove a copper
    testG.hand[thisPlayer][1] = feast;
    updateCoins(thisPlayer, &testG, 0);
    GnewCoinCount = GnewCoinCount - COPPER_VALUE;
    
    // ----------- Removing a copper. --------------
    printf("Testing: Removing a copper.\n");
    if(testG.coins != GnewCoinCount) {
        printf("\t**FAILED**: Coins did not update to reflect subtraction of copper.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Coin count is correct.\n\n");
        passedTests++;
    }
    
    // add a bonus
    updateCoins(thisPlayer, &testG, bonus);
    GnewCoinCount = GnewCoinCount + bonus;
    
    // ----------- Adding a bonus. --------------
    printf("Testing: Adding a bonus.\n");
    if(testG.coins != GnewCoinCount) {
        printf("\t**FAILED**: Coins did not update to reflect addition of bonus.\n\n");
        failedTests++;
    } else {
        printf("\tPASSED: Coin count is correct.\n\n");
        passedTests++;
    }
    
    //---------------------------------------------------------------------------
    
    printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n", TESTFUNCTION);
    printf("\t%d tests **FAILED**.\n", failedTests);
    printf("\t%d tests PASSED.\n\n", passedTests);
    
    
    return 0;
}