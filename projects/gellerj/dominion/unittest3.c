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
    int result = -1;
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

    printf("Testing whoseTurn():\n");

    printf("\nTest player 1 has first turn in 2-player game...\n");
    result = whoseTurn(&G2);
    printf("Turn = %d, expected 0...", result);
    if (result == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    endTurn(&G2);

    printf("\nTest player 1 has second turn in 2-player game...\n");
    result = whoseTurn(&G2);
    printf("Turn = %d, expected 1...", result);
    if (result == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    endTurn(&G2);

    printf("\nTest player 2 has third turn in 2-player game...\n");
    result = whoseTurn(&G2);
    printf("Turn = %d, expected 0...", result);
    if (result == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    initializeGame(3, kingdomCards, seed, &G1);
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest player 1 has first turn in 3-player game...\n");
    result = whoseTurn(&G2);
    printf("Turn = %d, expected 0...", result);
    if (result == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    endTurn(&G2);

    printf("\nTest player 2 has second turn in 3-player game...\n");
    result = whoseTurn(&G2);
    printf("Turn = %d, expected 1...", result);
    if (result == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    endTurn(&G2);

    printf("\nTest player 3 has third turn in 3-player game...\n");
    result = whoseTurn(&G2);
    printf("Turn = %d, expected 2...", result);
    if (result == 2) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    endTurn(&G2);

    printf("\nTest player 1 has fourth turn in 3-player game...\n");
    result = whoseTurn(&G2);
    printf("Turn = %d, expected 0...", result);
    if (result == 0) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }


}