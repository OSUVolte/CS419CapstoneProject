#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include "testkit.h"

int main() {
    struct gameState G1, G2;
    int i = 0;
    int tempDeck[MAX_DECK];
    int numPlayers = 2;
    int seed = 1;
    int player1 = 0;
    int player2 = 1;
    int sameCardCount = 0;
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

    printf("Testing shuffle():\n");

    // make a copy of the deck so we can test that it is shuffled
    for (i = 0; i < G2.deckCount[0]; i++) {
        tempDeck[i] = G2.deck[0][i];
    }

    printf("\nTest player 1's deck is shuffled...\n");

    printf("Player 1's deck before shuffle:\n");
    printDeck(player1, &G2);

    shuffle(player1, &G2);

    printf("Player 1's deck after shuffle:\n");
    printDeck(player1, &G2);

    // count how many cards are still in the same position
    for (i = 0; i < G2.deckCount[player1]; i++) {
        if (G2.deck[player1][i] == tempDeck[i]) {
            sameCardCount++;
        }
    }

    printf("Number of cards in same position = %d, expected != %d...", sameCardCount, G2.deckCount[player1]);

    if (sameCardCount != G2.deckCount[player1]) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    printf("\nTest player 1 card counts are still the same (no cards lost or gained)...");
    int diffSupplies[MAX_HAND];
    int flag = 0;
    diffHandSupply(&G1, &G2, player1, diffSupplies);
    for (i = 0; i < G2.handCount[player1]; i++) {
        if (diffSupplies[i] != 0) {
            flag = 1;
        }
    }
    if (flag == 0) {
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

    return 0;

}