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

    printf("----------------- Card Test 2, 1 Case: adventurer card ----------------\n");
    // ------------------------- CASE 1: ---------------------------	
    // reset test game state
    memcpy(&testState, &state, sizeof(struct gameState));
    int case1HandCount = testState.handCount[currentPlayer];
    int case1Return = cardEffect(smithy, 0, 0, 0, &testState, 0, &bonus);
    if (case1Return >= 0) {
        printf("cardEffect() - adventurer, case1: PASS good return value\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL return value indicates something went wrong\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case1HandCount + 2) {
        printf("cardEffect() - adventurer, case1: PASS two new cards in hand\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL two new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.handCount[currentPlayer] == case1HandCount + 2) {
        printf("cardEffect() - adventurer, case1: PASS two new cards in hand\n");
        int secondCard = testState.hand[currentPlayer][case1HandCount + 1];
        int firstCard  = testState.hand[currentPlayer][case1HandCount];
        if ((secondCard == copper || secondCard == silver || secondCard == gold) &&
            (firstCard  == copper || firstCard  == silver || firstCard  == gold)) {
            printf("cardEffect() - adventurer, case1: PASS two new cards are both treasure\n");
        } else {
            printf("cardEffect() - adventurer, case1: FAIL two new cards are not both treasure\n");
        }
    } else {
        printf("cardEffect() - adventurer, case1: FAIL two new cards not in hand\n");
    }

	return 0;
}


