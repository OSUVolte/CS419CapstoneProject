/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Unit Test for scoreFor()
*************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTFCN "scoreFor()"

int main() {
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int thisPlayer = 0;
    int p, r, handCount;
    int bonus;
    int totalScore;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState testG;

    printf("----------------- Testing Function: %s ----------------\n", TESTFCN);
    
    // Test 1
    printf("TEST 1: No victory cards\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &testG);
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = copper;
    testG.deck[thisPlayer][4] = copper;
    testG.hand[thisPlayer][0] = copper;
    testG.hand[thisPlayer][1] = silver;
    testG.hand[thisPlayer][2] = gold;
    testG.hand[thisPlayer][3] = copper;
    testG.hand[thisPlayer][4] = copper;

    totalScore = scoreFor (thisPlayer, &testG);


    if(totalScore == 0) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    // Test 2
    printf("TEST 2: Victory cards in hand only\n");
    initializeGame(numPlayers, k, seed, &testG);
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = gold;
    testG.deck[thisPlayer][4] = gold;
    testG.hand[thisPlayer][0] = estate;
    testG.hand[thisPlayer][1] = duchy;
    testG.hand[thisPlayer][2] = province;
    testG.hand[thisPlayer][3] = copper;
    testG.hand[thisPlayer][4] = copper;

    totalScore = scoreFor (thisPlayer, &testG);


    if(totalScore == 10) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    // Test 3
    printf("TEST 3: Victory cards in deck only \n");
	initializeGame(numPlayers, k, seed, &testG);
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = province;
    testG.deck[thisPlayer][3] = gold;
    testG.deck[thisPlayer][4] = gold;
    testG.hand[thisPlayer][0] = copper;
    testG.hand[thisPlayer][1] = copper;
    testG.hand[thisPlayer][2] = copper;
    testG.hand[thisPlayer][3] = copper;
    testG.hand[thisPlayer][4] = copper;

    totalScore = scoreFor (thisPlayer, &testG);


    if(totalScore == 6) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }


    // Test 4
    printf("TEST 4:  Victory cards in discard only\n");
    initializeGame(numPlayers, k, seed, &testG);
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = gold;
    testG.deck[thisPlayer][4] = gold;
    testG.hand[thisPlayer][0] = copper;
    testG.hand[thisPlayer][1] = copper;
    testG.hand[thisPlayer][2] = copper;
    testG.hand[thisPlayer][3] = copper;
    testG.hand[thisPlayer][4] = copper;
    testG.discard[thisPlayer][0] = province;

    totalScore = scoreFor (thisPlayer, &testG);


    if(totalScore == 6) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }


    // Test 5
    printf("TEST 5: Only curse cards. Negative value\n");
    initializeGame(numPlayers, k, seed, &testG);
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = estate;
    testG.deck[thisPlayer][4] = duchy;
    testG.hand[thisPlayer][0] = curse;
    testG.hand[thisPlayer][1] = curse;
    testG.hand[thisPlayer][2] = curse;
    testG.hand[thisPlayer][3] = curse;
    testG.hand[thisPlayer][4] = curse;

    totalScore = scoreFor (thisPlayer, &testG);


    if(totalScore == 0) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }




    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFCN);

    return 0;
}



