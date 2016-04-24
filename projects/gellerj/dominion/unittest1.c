#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    struct gameState G1, G2;
    int numPlayers = 2;
    int seed = 1;
    int gameOver = 0;
    int kingdomCards[10] = {
            adventurer,
            gardens,
            embargo,
            village,
            minion,
            mine,
            cutpurse,
            sea_hag,
            tribute,
            smithy
    };

    initializeGame(numPlayers, kingdomCards, seed, &G1);
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("Testing isGameOver()...\n");

    printf("\nTest game over when province supply equals zero...\n");
    G2.supplyCount[province] = 0;
    gameOver = isGameOver(&G2);
    printf("Game over = %d, expected 1...", gameOver);
    if (gameOver == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // reset state for next test
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest game NOT over when duchy supply equals zero...\n");
    G2.supplyCount[duchy] = 0;
    gameOver = isGameOver(&G2);
    printf("Game over = %d, expected 0...", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // reset state for next test
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest game NOT over when estate supply equals zero...\n");
    G2.supplyCount[estate] = 0;
    gameOver = isGameOver(&G2);
    printf("Game over = %d, expected 0...", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // reset state for next test
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest game NOT over when two supply pile counts equal zero...\n");
    G2.supplyCount[0] = 0;
    G2.supplyCount[1] = 0;
    gameOver = isGameOver(&G2);
    printf("Game over = %d, expected 0...", gameOver);
    if (gameOver == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // reset state for next test
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest game over when three supply pile counts equal zero...\n");
    G2.supplyCount[0] = 0;
    G2.supplyCount[1] = 0;
    G2.supplyCount[2] = 0;
    gameOver = isGameOver(&G2);
    printf("Game over = %d, expected 1...", gameOver);
    if (gameOver == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // reset state for next test
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest game over when four supply pile counts equal zero...\n");
    G2.supplyCount[0] = 0;
    G2.supplyCount[1] = 0;
    G2.supplyCount[2] = 0;
    G2.supplyCount[3] = 0;
    gameOver = isGameOver(&G2);
    printf("Game over = %d, expected 1...", gameOver);
    if (gameOver == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    return 0;

}