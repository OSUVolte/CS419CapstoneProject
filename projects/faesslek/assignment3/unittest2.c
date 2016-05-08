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
    struct gameState stateNoProvinces;
    struct gameState stateOneProvince;
    struct gameState stateThreeAtZero;
    struct gameState stateTwoAtZero;
    struct gameState testState;

    memset(&stateNoProvinces, 0, sizeof(stateNoProvinces));
    memset(&stateOneProvince, 0, sizeof(stateOneProvince));
    memset(&stateThreeAtZero, 0, sizeof(stateThreeAtZero));
    memset(&stateTwoAtZero, 0, sizeof(stateTwoAtZero));
    memset(&testState, 0, sizeof(testState));
    
    //initialize all supply counts for various gamestates
    int i;
    for (i = 0; i < (treasure_map + 1); ++i) {
        stateNoProvinces.supplyCount[i] = 3;
        stateOneProvince.supplyCount[i] = 3;
        stateThreeAtZero.supplyCount[i] = 3;
        stateTwoAtZero.supplyCount[i] = 3;
    }
    //add special features to supply counts
    stateNoProvinces.supplyCount[province] = 0;
    stateOneProvince.supplyCount[province] = 1;
    stateThreeAtZero.supplyCount[curse] = 0;
    stateThreeAtZero.supplyCount[estate] = 0;
    stateThreeAtZero.supplyCount[treasure_map] = 0;
    stateTwoAtZero.supplyCount[council_room] = 0;
    stateTwoAtZero.supplyCount[feast] = 0;

    printf("----------------- Unit Test 2, 4 Cases: isGameOver() ----------------\n");
    // ------------------------- CASE 1: 0 provinces ----------------------------	
    // reset test game state
    memcpy(&testState, &stateNoProvinces, sizeof(struct gameState));
    int case1Return = isGameOver(&testState);
    if (case1Return > 0) {
        printf("isGameOver(), case1: PASS detected 0 provinces for game over state\n");
    } else {
        printf("isGameOver(), case1: FAIL did not detect 0 provinces for game over state\n");
    }
    

    // ------------------------- CASE 2: 1 province ----------------------------
    // reset test game state
    memcpy(&testState, &stateOneProvince, sizeof(struct gameState));
    int case2Return = isGameOver(&testState);
    if (case2Return == 0) {
        printf("isGameOver(), case2: PASS detected non-zero provinces for non-game-over state\n");
    } else {
        printf("isGameOver(), case2: FAIL gave game over state for >0 provinces\n");
    }

    // ------------------------- CASE 3: 3 cards at 0 supply ----------------------------
    // reset test game state
    memcpy(&testState, &stateThreeAtZero, sizeof(struct gameState));
    int case3Return = isGameOver(&testState);
    if (case3Return > 0) {
        printf("isGameOver(), case3: PASS detected three 0 supply cards for game-over state\n");
    } else {
        printf("isGameOver(), case3: FAIL did not give game over state for three 0 supply cards\n");
    }

    // ------------------------- CASE 4: 2 cards at 0 supply ----------------------------
    // reset test game state
    memcpy(&testState, &stateTwoAtZero, sizeof(struct gameState));
    int case4Return = isGameOver(&testState);
    if (case4Return == 0) {
        printf("isGameOver(), case4: PASS detected non-game-over state for two 0 supply cards\n");
    } else {
        printf("isGameOver(), case4: FAIL yielded game over state for two 0 supply cards\n");
    }

	return 0;
}


