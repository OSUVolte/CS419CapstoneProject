#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

#define VERBOSE 1

int main() {
    struct gameState G;
    int players = 2;
    int seed = 1;
    int player0 = 0;
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

    printf("Testing VILLAGE:\n");

    // record the current hand count
    int actionCountBefore = G.numActions;
    int handCountBefore = G.handCount[player0];

    // manually add a Village to player 0's hand
    G.hand[player0][0] = village;

    // simulate a Adventurer being played
    playCard(0, -1, -1, -1, &G);

    if (VERBOSE)
        printf("Test that action count is incremented by 2...\n");

    if (VERBOSE)
        printf(
                "\tInitial action count was %d, new action count is %d, expected 3...",
                actionCountBefore,
                G.numActions
        );

    if (G.numActions == 3) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    if (VERBOSE)
        printf("Test that a new card was drawn...\n");

    if (VERBOSE)
        printf(
                "\tInitial hand count was %d, new hand count is %d, expected 6...",
                handCountBefore,
                G.handCount[player0]
        );

    if (G.handCount[player0] == 6) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }


}