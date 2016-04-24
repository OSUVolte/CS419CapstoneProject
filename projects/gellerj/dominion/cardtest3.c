#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include "testkit.h"

#define VERBOSE 1

int main() {
    struct gameState G1, G2;
    int numPlayers = 2;
    int seed = 1;
    int player1 = 0;
    int player2 = 1;
    int bonus = 0;
    int handPos = 0;
    int c1 = 0, c2 = 0, c3 = 0;
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
    G1.hand[player1][handPos] = village;
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("Testing VILLAGE...\n");

    // simulate a Adventurer being played
    cardEffect(village, c1, c2, c3, &G2, handPos, &bonus);

    // test action effect
    printf("\nCheck number of actions is +2...\n");
    printf("Num actions is %d, expected %d...", G2.numActions, G1.numActions + 2);
    if (G2.numActions == (G1.numActions + 2)) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // test draw/discard count effects
    printf("\nCheck that hand count remains the same (+1 new draw card, -1 discard)...\n");
    printf("Initial hand count was %d, new hand count is %d, expected 5...", G1.handCount[player1],
           G2.handCount[player1]);
    if (G2.handCount[player1] == G1.handCount[player1]) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // ensure new cards came from player 1's deck
    printf("\nCheck new card came from player 1's deck...");
    // new hand card should be at front of deck due to discardCard shuffle effect
    int newHandCard = G2.hand[player1][0];
    int oldDeckCard = G2.deck[player1][G2.deckCount[player1] - 1];
    printf("\nNew deck card is %d, expected %d...", newHandCard, oldDeckCard);
    if (newHandCard == oldDeckCard) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // ensure village was discarded from hand
    printf("\nCheck village was discarded from player's hand...");
    int supplyBefore = countHandSupply(&G1, player1, village);
    int supplyAfter = countHandSupply(&G2, player1, village);
    printf("\nOld village supply count was %d, new count is %d, expected %d...", supplyBefore, supplyAfter, supplyBefore - 1);
    if (supplyAfter == (supplyBefore - 1)) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // ensure player 2's hand was not modified
    printf("\nCheck player 2 hand is untouched...");
    if (handIsUntouched(&G1, &G2, player2) == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // ensure player 2's deck was not modified
    printf("\nCheck player 2 deck is untouched...");
    if (deckIsUntouched(&G1, &G2, player2) == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // ensure kingdom pile was not modified
    printf("\nCheck kingdom pile is untouched...");
    if (kingdomPileIsUntouched(&G1, &G2) == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // ensure victory pile was not modified
    printf("\nCheck victory pile is untouched...");
    if (victoryPileIsUntouched(&G1, &G2) == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    return 0;
}