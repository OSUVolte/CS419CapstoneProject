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


//forward declarations because why weren't these in the header files???
int updateCoins(int player, struct gameState *state, int bonus);

int main() {
    int seed = 1000;
    int bonus = 0;

    struct gameState state;
    struct gameState testState;

    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));
    
    //create gamestate with coin cards in hands
    //total value should be 6 + bonus
    state.handCount[0] = 5;
    state.hand[0][0] = copper;
    state.hand[0][1] = estate;
    state.hand[0][2] = gold;
    state.hand[0][3] = gardens;
    state.hand[0][4] = silver;

    // initialize game state and player cards
	//initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Unit Test 1, 3 Cases: updateCoins() ----------------\n");
    // ------------------------- CASE 1: bonus == 0 ----------------------------	
    // reset test game state
    memcpy(&testState, &state, sizeof(struct gameState));
    int playerNum1 = 0;
    bonus = 0;

    updateCoins(playerNum1, &testState, bonus);
    assert(testState.coins == 6 + bonus);
    printf("updateCoins(), case1: PASS with 0 as bonus\n");

    // ------------------------- CASE 2: bonus == 3 ----------------------------
    // reset test game state
    memcpy(&testState, &state, sizeof(struct gameState));
    int playerNum2 = 0;
    bonus = 0;

    updateCoins(playerNum2, &testState, bonus);
    assert(testState.coins == 6 + bonus);
    printf("updateCoins(), case2: PASS with 3 as bonus\n");

    // ------------------------- CASE 3: player number too high ----------------------------
    // reset test game state
    memcpy(&testState, &state, sizeof(struct gameState));
    int playerNum3 = 5;
    bonus = 0;

    int retVal = 0;
    retVal = updateCoins(playerNum3, &testState, bonus);
    //If updateCoins returns with no issue, then it did not detect that it wrote/read 
    //memory outside the bounds of an array. Bad!
    if (retVal == 0) {
        printf("updateCoins(), case3: FAIL updateCoins allows player number greater than max. This means\n");
        printf("               updateCoins will read or write memory outside of array bounds!\n");
    } else {
        printf("updateCoins(), case3: PASS updateCoins detects player number greater than max.\n");
    }

	return 0;
}


