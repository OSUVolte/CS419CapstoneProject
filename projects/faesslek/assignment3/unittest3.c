/******************************************************************************
 * Author: Kelby Faessler
 * Class: CS362
 * Project: Assignment 3
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
    struct gameState stateNoBuys;
    struct gameState stateNoSupply;
    struct gameState stateNoCoins;
    struct gameState stateGoodBuy;
    struct gameState testState;

    memset(&stateNoBuys, 0, sizeof(stateNoBuys));
    memset(&stateNoSupply, 0, sizeof(stateNoSupply));
    memset(&stateNoCoins, 0, sizeof(stateNoCoins));
    memset(&stateGoodBuy, 0, sizeof(stateGoodBuy));
    memset(&testState, 0, sizeof(testState));
    
    //add special features to game states
    stateNoBuys.numBuys = 0;
    stateNoBuys.supplyCount[province] = 2;
    stateNoBuys.coins = 10;
    stateNoSupply.numBuys = 2;
    stateNoSupply.supplyCount[province] = 0;
    stateNoSupply.coins = 10;
    stateNoCoins.numBuys = 2;
    stateNoCoins.supplyCount[province] = 2;
    stateNoCoins.coins = 1;
    stateGoodBuy.numBuys = 2;
    stateGoodBuy.supplyCount[province] = 2;
    stateGoodBuy.coins = 10;

    printf("----------------- Unit Test 3, 4 Cases: buyCard() ----------------\n");
    // ------------------------- CASE 1: no buys available ---------------------------	
    // reset test game state
    memcpy(&testState, &stateNoBuys, sizeof(struct gameState));
    int case1Return = buyCard(province, &testState);
    if (case1Return < 0) {
        printf("buyCard(), case1: PASS detected no buys available\n");
    } else {
        printf("buyCard(), case1: FAIL did not detect no buys available\n");
    }   

    // ------------------------- CASE 2: no supply for card being bought ----------------------------
    // reset test game state
    memcpy(&testState, &stateNoSupply, sizeof(struct gameState));
    int case2Return = buyCard(province, &testState);
    if (case2Return < 0) {
        printf("buyCard(), case2: PASS detected non-zero provinces for non-game-over state\n");
    } else {
        printf("buyCard(), case2: FAIL gave game over state for >0 provinces\n");
    }

    // ------------------------- CASE 3: not enough coins ----------------------------
    memcpy(&testState, &stateNoCoins, sizeof(struct gameState));
    int case3Return = buyCard(province, &testState);
    if (case3Return < 0) {
        printf("buyCard(), case3: PASS detected not enough coins to buy province (8 required)\n");
    } else {
        printf("buyCard(), case3: FAIL did not detect not enough coins available\n");
    }

    // ------------------------- CASE 4: good buy ----------------------------
    memcpy(&testState, &stateGoodBuy, sizeof(struct gameState));
    int case4Return = buyCard(province, &testState);
    if (case4Return >= 0) {
        printf("buyCard(), case4: PASS return val indicates province card bought\n");
    } else {
        printf("buyCard(), case4: FAIL return val indicates buy province did not succeed when it should\n");
    }
    if (testState.supplyCount[province] == 1) {
        printf("buyCard(), case4: PASS province supply correctly updated\n");
    } else {
        printf("buyCard(), case4: FAIL province supply not correctly updated\n");
    }
    if (testState.coins == 2) {
        printf("buyCard(), case4: PASS number of coins correctly updated\n");
    } else {
        printf("buyCard(), case4: FAIL number of coins not correctly updated\n");
    }
    if (testState.discard[0][0] == province) {
        printf("buyCard(), case4: PASS province card correctly in discard pile\n");
    } else {
        printf("buyCard(), case4: FAIL province card not correctly in discard pile\n");
    }
    if (testState.discardCount[0] == 1) {
        printf("buyCard(), case4: PASS discard count correctly updated\n");
    } else {
        printf("buyCard(), case4: FAIL discard count not correctly updated\n");
    }

	return 0;
}


