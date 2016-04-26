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

    printf("----------------- Card Test 3, 1 Case: council_room card ----------------\n");
    // ------------------------- CASE 1: ---------------------------	
    // reset test game state
    memcpy(&testState, &state, sizeof(struct gameState));
    int case1HandCount = testState.handCount[currentPlayer];
    int case1NumBuys = testState.numBuys;
    int otherPlayer;
    if (currentPlayer == 0) {
        otherPlayer = 1;
    } else {
        otherPlayer = 0;
    }
    int case1OPHandCount = testState.handCount[otherPlayer];
    int case1Return = cardEffect(council_room, 0, 0, 0, &testState, 0, &bonus);
    if (case1Return >= 0) {
        printf("cardEffect() - council_room, case1: PASS good return value\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL return value indicates something went wrong\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case1HandCount + 3) {
        printf("cardEffect() - council_room, case1: PASS three new cards in hand\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL three new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.numBuys == (case1NumBuys + 1)) {
        printf("cardEffect() - adventurer, case1: PASS incremented number of buys\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL did not increment number of buys\n");
    }
    //make sure other player gets new card as well
    if (testState.handCount[otherPlayer] == case1OPHandCount + 1) {
        printf("cardEffect() - council_room, case1: PASS other player has new card in hand\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL other player does not have new card in hand\n");
    }

	return 0;
}


