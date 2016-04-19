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

    printf("Testing ADVENTURER:\n");

    if (VERBOSE)
        printf("Test that hand count is incremented by 2...\n");

    // record the current hand count
    int handCountBefore = G.handCount[player0];

    // manually add a Adventurer to player 0's hand
    G.hand[player0][0] = adventurer;

    // simulate a Adventurer being played
    cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

    if (VERBOSE)
        printf(
                "\tInitial hand count was %d, new hand count is %d, expected 7...",
                handCountBefore,
                G.handCount[player0]
        );

    // make sure the new hand count is +3
    if(G.handCount[player0] == handCountBefore + 2) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    int sixthCard = G.hand[player0][5];
    int seventhCard = G.hand[player0][6];

    if (VERBOSE)
        printf("Test that new cards are treasure cards...\n");

    if (VERBOSE)
        printf("\tCard #6 is %d, expected 4, 5, or 6...", sixthCard);

    if(sixthCard == copper || sixthCard == silver || sixthCard == gold) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    if (VERBOSE)
        printf("\tCard #7 is %d, expected 4, 5, or 6...", G.hand[player0][6]);

    if(seventhCard == copper || seventhCard == silver || seventhCard == gold) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

}