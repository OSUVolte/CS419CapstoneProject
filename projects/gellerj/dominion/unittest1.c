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

    printf("Testing isGameOver():\n");

    if (VERBOSE) printf("\tTest game over when province supply equals zero...\n");
    int supplyCount = G.supplyCount[province];      // save current supply count
    G.supplyCount[province] = 0;                    // set province to supply to 0 (game over)
    gameOver = isGameOver(&G);
    if (VERBOSE) printf("\tGame over = %d, expected 1\n", gameOver);
    assert(gameOver == 1);

    if (VERBOSE) printf("\tTest game over when three supply pile counts equal zero...\n");
    G.supplyCount[province] = supplyCount;          // restore supply count for new test case
    G.supplyCount[0] = 0;                           // set three supply pile counts to zero (game over)
    G.supplyCount[1] = 0;
    G.supplyCount[2] = 0;
    gameOver = isGameOver(&G);
    if (VERBOSE) printf("\tGame over = %d, expected 1\n", gameOver);
    assert(gameOver == 1);

    printf("All tests passed.\n");
}