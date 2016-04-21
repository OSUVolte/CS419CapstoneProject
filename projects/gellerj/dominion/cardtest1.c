#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "testkit.h"

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
    G1.hand[player1][handPos] = smithy;
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("Testing SMITHY...\n");

    // simulate a Smithy being played
    cardEffect(smithy, c1, c2, c3, &G2, handPos, &bonus);

    printf("\nTest that hand count is incremented by 2 (+3 new cards, -1 existing smithy)...\n");
    printf("Initial hand count was %d, new hand count is %d, expected 7...", G1.handCount[player1],
           G2.handCount[player1]);
    // make sure the new hand count is +2. three cards should be gained and the smithy should
    // be discarded for a net gain of two cards.
    if (G2.handCount[player1] == G1.handCount[player1] + 2) {
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

    // ensure new cards came from player 1's deck
    printf("\nCheck new cards came from player 1's deck...\n");
    printf("Deck count was %d, new deck count is %d, expected 2...", G1.deckCount[player1], G2.deckCount[player1]);
    if (G1.deckCount[player1] - 3 == G2.deckCount[player1]) {
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

    // ensure card was last card played
    printf("\nCheck smithy card was added to played pile...");
    if (cardWasPlayed(&G2, smithy, G2.playedCardCount) == 1) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

}