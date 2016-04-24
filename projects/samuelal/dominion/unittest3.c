/*
Alex Samuel
Assignment 3
unittest3.c
Tests isGameOver() function
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int numPlayers = 2;
    int PlayerID = 0;
    int seed = 2;
    int i;
    int errorFlag = 0;
	struct gameState G, testG;

    SelectStream(6);
    PutSeed(7);

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy, council_room};

    printf ("TEST 1: Testing isGameOver() - Province Check\n");

    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    int provinceNum;

    for (i = 0; i < 1000; i++) {
        provinceNum = floor(Random() * 3);
        testG.supplyCount[province] = provinceNum;
        if (testG.supplyCount[province] == 0) {
            if (isGameOver(&testG) != 1) {
                printf("TEST 1 HAS FAILED\n\n");
                errorFlag = 1;
            }
        }
        else {
            if (isGameOver(&testG) != 0) {
                printf("TEST 1 HAS FAILED\n\n");
                errorFlag = 1;
            }
        }
    }

    printf("TEST 2: Testing isGameOver() - Supply Piles Empty\n");

    int supplyEmpty;
    int supplyIndex;
    int j, pp;

    memset(&G, 23, sizeof(struct gameState));
    memset(&testG, 23, sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&testG, &G, sizeof(struct gameState));

    supplyEmpty = floor(Random() * 25);

    for (i = 0; i < 10000; i++) {
        int m = 0;
        supplyEmpty = floor(Random() * 25);
        for (j = 0; j < supplyEmpty; j++) {
            supplyIndex = floor(Random() * 25);
            testG.supplyCount[supplyIndex] = 0;
        }

        for (pp = 0; pp < 25; pp++) {
            if (testG.supplyCount[pp] == 0) {
                m++;
            }

        }
        if (m >= 3) {
            if (isGameOver(&testG) != 1) {
                printf("TEST 2 HAS FAILED\n\n");
                errorFlag = 1;
            }
        }
        else if (testG.supplyCount[province] == 0 && isGameOver(&testG) != 0) {
            printf("TEST 4 HAS FAILED\n\n");
            errorFlag = 1;
        }
    }

    if (errorFlag == 0) {
        printf("ALL TESTS PASSED");
    }


    return 0;

}
