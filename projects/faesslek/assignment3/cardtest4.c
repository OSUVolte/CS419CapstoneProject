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
    int seed = 200;
    int numPlayers = 2;
    int bonus = 0;
    int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room };
    
    struct gameState state;
    struct gameState testState;

    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));

    // initialize game state and player cards
    initializeGame(numPlayers, k, seed, &state);

    //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

    int currentPlayer = state.whoseTurn;

    printf("----------------- Card Test 4, 1 Case: village card ----------------\n");
    // ------------------------- CASE 1: ---------------------------	
    // reset test game state
    memcpy(&testState, &state, sizeof(struct gameState));
    int case1HandCount = testState.handCount[currentPlayer];
    int case1NumActions = testState.numActions;
    int case1Return = cardEffect(village, 0, 0, 0, &testState, 0, &bonus);
    if (case1Return >= 0) {
        printf("cardEffect() - village, case1: PASS good return value\n");
    } else {
        printf("cardEffect() - village, case1: FAIL return value indicates something went wrong\n");
    }
    //make sure current player gets 1 new card and discarded played card (net gain of 0 cards)
    if (testState.handCount[currentPlayer] == case1HandCount) {
        printf("cardEffect() - council_room, case1: PASS gained new card while discarding card\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL did not gain new card while discarding card\n");
    }
    //make sure current player got 2 more actions
    if (testState.numActions == (case1NumActions + 2)) {
        printf("cardEffect() - adventurer, case1: PASS incremented number of actions\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL did not increment number of actions\n");
    }

	return 0;
}


