#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 1

int main() {
    struct gameState G;
    int players = 2;
    int seed = 1;
    int gameOver = 0;
    int result = -1;
    int kingdomCards[10] = {
            adventurer,
            gardens,
            embargo, village,
            minion, mine,
            cutpurse,
            sea_hag,
            tribute,
            smithy
    };

    initializeGame(players, kingdomCards, seed, &G);

    printf("Testing whoseTurn():\n");

    if (VERBOSE)
        printf("Test player 0 has first turn in 2-player game...\n");
    result = whoseTurn(&G);
    printf("\t\tPlayer %d turn, expected 0\n", result);
    assert(result == 0);

    endTurn(&G);

    if (VERBOSE)
        printf("\tTest player 1 has second turn in 2-player game...\n");
    result = whoseTurn(&G);
    printf("\t\tPlayer %d turn, expected 1\n", result);
    assert(result == 1);

    endTurn(&G);

    if (VERBOSE)
        printf("\tTest player 0 has third turn in 2-player game...\n");
    result = whoseTurn(&G);
    printf("\t\tPlayer %d turn, expected 0\n", result);
    assert(result == 0);

    printf("All tests passed.\n");
}