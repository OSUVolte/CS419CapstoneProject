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
    struct gameState stateNoSupply;
    struct gameState stateDiscard;
    struct gameState stateDeck;
    struct gameState stateHand;
    struct gameState testState;

    memset(&stateNoSupply, 0, sizeof(stateNoSupply));
    memset(&stateDiscard, 0, sizeof(stateDiscard));
    memset(&stateDeck, 0, sizeof(stateDeck));
    memset(&stateHand, 0, sizeof(stateHand));
    memset(&testState, 0, sizeof(testState));
    
    //add special features to game states
    stateDiscard.supplyCount[province] = 2;
    stateDeck.supplyCount[province] = 2;
    stateHand.supplyCount[province] = 2;


    printf("----------------- Unit Test 4, 4 Cases: gainCard() ----------------\n");
    // ------------------------- CASE 1: no supply of card left ---------------------------	
    // reset test game state
    memcpy(&testState, &stateNoSupply, sizeof(struct gameState));
    int case1Return = gainCard(province, &testState, 0, 0);
    if (case1Return < 0) {
        printf("gainCard(), case1: PASS detected no supply available\n");
    } else {
        printf("gainCard(), case1: FAIL did not detect no supply available\n");
    }

    // ------------------------- CASE 2: card to discard ----------------------------
    // reset test game state
    memcpy(&testState, &stateDiscard, sizeof(struct gameState));
    int case2Return = gainCard(province, &testState, 0, 0);
    if (case2Return >= 0) {
        printf("gainCard(), case2: PASS return val indicates card to discard successful\n");
    } else {
        printf("gainCard(), case2: FAIL eturn val indicates card to discard not successful\n");
    }
    if (testState.discard[0][0] == province) {
        printf("gainCard(), case2: PASS province in discard slot\n");
    } else {
        printf("gainCard(), case2: FAIL province not in discard slot\n");
    }
    if (testState.discardCount[0] == 1) {
        printf("gainCard(), case2: PASS discard count correctly incremented\n");
    } else {
        printf("gainCard(), case2: FAIL discard count not correctly incremented\n");
    }

    // ------------------------- CASE 3: card to deck ----------------------------
    memcpy(&testState, &stateDeck, sizeof(struct gameState));
    int case3Return = gainCard(province, &testState, 1, 0);
    if (case3Return >= 0) {
        printf("gainCard(), case3: PASS return val indicates card to deck successful\n");
    } else {
        printf("gainCard(), case3: FAIL eturn val indicates card to deck not successful\n");
    }
    if (testState.deck[0][0] == province) {
        printf("gainCard(), case2: PASS province in deck slot\n");
    } else {
        printf("gainCard(), case2: FAIL province not in deck slot\n");
    }
    if (testState.deckCount[0] == 1) {
        printf("gainCard(), case2: PASS deck count correctly incremented\n");
    } else {
        printf("gainCard(), case2: FAIL deck count not correctly incremented\n");
    }

    // ------------------------- CASE 4: card to hand ----------------------------
    memcpy(&testState, &stateHand, sizeof(struct gameState));
    int case4Return = gainCard(province, &testState, 2, 0);
    if (case4Return >= 0) {
        printf("gainCard(), case3: PASS return val indicates card to hand successful\n");
    } else {
        printf("gainCard(), case3: FAIL eturn val indicates card to hand not successful\n");
    }
    if (testState.hand[0][0] == province) {
        printf("gainCard(), case2: PASS province in hand slot\n");
    } else {
        printf("gainCard(), case2: FAIL province not in hand slot\n");
    }
    if (testState.handCount[0] == 1) {
        printf("gainCard(), case2: PASS hand count correctly incremented\n");
    } else {
        printf("gainCard(), case2: FAIL hand count not correctly incremented\n");
    }

	return 0;
}


