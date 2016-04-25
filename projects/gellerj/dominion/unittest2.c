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
    int player1 = 0;
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

    printf("Testing gainCard():\n");

    printf("\nTest card is not gained if supply count equals zero...\n");
    G2.supplyCount[smithy] = 0;
    result = gainCard(smithy, &G2, 1, player1);
    printf("Return value = %d, expected -1...", result);
    if (result == -1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest card gained is added to deck...\n");
    gainCard(smithy, &G2, 1, player1);
    int lastDeckCard = G2.deck[player1][G2.deckCount[player1] - 1];
    printf("Last card in deck = %d, expected 13 (smithy)...", lastDeckCard);
    if (lastDeckCard == smithy) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
    printf("Player 1 deck count = %d, expected %d...", G2.deckCount[player1], G1.deckCount[player1] + 1);
    if (G2.deckCount[player1] == G1.deckCount[player1] + 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest card gained is added to hand...\n");
    gainCard(smithy, &G2, 2, player1);
    int lastHandCard = G2.hand[player1][G2.handCount[player1] - 1];
    printf("Last card in hand = %d, expected 13 (smithy)...", lastHandCard);
    if (lastHandCard == smithy) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
    printf("P1 hand count = %d, expected %d...", G2.handCount[player1], G1.handCount[player1] + 1);
    if (G2.handCount[player1] == G1.handCount[player1] + 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("\nTest card gained is added to discard...\n");
    gainCard(smithy, &G2, 0, player1);
    int lastDiscardCard = G2.discard[player1][G2.discardCount[player1] - 1];
    printf("Last card in hand = %d, expected %d...", lastDiscardCard, smithy);
    if (lastDiscardCard == smithy) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }
    printf("Player 1 discard count = %d, expected 1...", G2.discardCount[player1]);
    if (G2.discardCount[player1] == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    printf("\nTest supply pile count is decremented...\n");
    printf("Supply count = %d, expected %d...", G2.supplyCount[smithy], G1.supplyCount[smithy] - 1);
    if (G2.supplyCount[smithy] == G1.supplyCount[smithy] - 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    return 0;
}