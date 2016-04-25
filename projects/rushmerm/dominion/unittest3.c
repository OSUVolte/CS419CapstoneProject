/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Unit Test for discardCard()
*************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTFCN "discardCard()"

int main() {
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int thisPlayer = 0;
    int p, r, handCount;
    int bonus;
    int returnValue;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;

    printf("----------------- Testing Function: %s ----------------\n", TESTFCN);
    
    // Test 1
    printf("TEST 1: Test if trash flag is set\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &testG);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = estate;
    testG.deck[thisPlayer][4] = duchy;

    if(discardCard(0, thisPlayer, &testG, 1) == 0 && testG.playedCardCount == G.playedCardCount + 1) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    // Test 2
    printf("TEST 2: Discard last card in hand (card 5 out of 5)\n");
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = estate;
    testG.deck[thisPlayer][4] = duchy;
    if(discardCard(4, thisPlayer, &testG, 0) == 0 && testG.handCount[thisPlayer] == G.handCount[thisPlayer] -1) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    // Test 3
    printf("TEST 3: Discard only card in hand (1 of 1) \n");
	initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = estate;
    testG.deck[thisPlayer][4] = duchy;
    // Discard all but one
    discardCard(1, thisPlayer, &testG, 0);
    discardCard(2, thisPlayer, &testG, 0);
    discardCard(3, thisPlayer, &testG, 0);
    discardCard(4, thisPlayer, &testG, 0);

    if(discardCard(0, thisPlayer, &testG, 0) == 0 && testG.handCount[thisPlayer] == G.handCount[thisPlayer] -1) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

    // Test 4
    printf("TEST 4: Discard middle card in hand. Test it is replaced with last card \n");
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.deck[thisPlayer][0] = copper;
    testG.deck[thisPlayer][1] = silver;
    testG.deck[thisPlayer][2] = gold;
    testG.deck[thisPlayer][3] = estate;
    testG.deck[thisPlayer][4] = duchy;
    // Discard all but one
    returnValue = discardCard(2, thisPlayer, &testG, 0);

    if(returnValue == 0 && testG.handCount[thisPlayer] == G.handCount[thisPlayer] -1 && testG.deck[thisPlayer][2] == duchy) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }



    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFCN);

    return 0;
}



