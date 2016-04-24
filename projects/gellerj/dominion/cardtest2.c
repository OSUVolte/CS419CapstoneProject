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
    int i = 0;
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
    G1.hand[player1][handPos] = adventurer;
    memcpy(&G2, &G1, sizeof(struct gameState));

    printf("Testing ADVENTURER...\n");

    // simulate a Adventurer being played
    cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);

    printf("\nCheck new card #1 is a treasure card...\n");
    int card1 = G2.hand[player1][G2.handCount[player1] - 1];
    printf("Card #1 is %d, expected 4, 5, or 6...", card1);
    if ((card1 == copper) | (card1 == silver) | (card1 == gold)) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    printf("\nCheck new card #2 is a treasure card...\n");
    int card2 = G2.hand[player1][G2.handCount[player1] - 2];
    printf("Card #2 is %d, expected 4, 5, or 6...", card2);
    if ((card2 == copper) | (card2 == silver) | (card2 == gold)) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    printf("\nCheck that hand count is incremented by 2 (+2 new treasure cards)...\n");
    printf("Initial hand count was %d, new hand count is %d, expected 7...", G1.handCount[player1],
           G2.handCount[player1]);
    // make sure the new hand count is +2. two new treasure cards should be gained.
    if (G2.handCount[player1] == G1.handCount[player1] + 2) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    // ensure new cards came from player 1's deck
    printf("\nCheck new treasure cards came from player 1's deck...");
    int diffSupplies[MAX_DECK];
    diffDeckSupply(&G1, &G2, player1, diffSupplies);
    int copperDiff = diffSupplies[copper];
    int silverDiff = diffSupplies[silver];
    int goldDiff = diffSupplies[gold];
    int netDiff = copperDiff + silverDiff + goldDiff;
    printf("\nNet difference in deck treasure card supply is %d, expected 2...", netDiff);
    if (netDiff == 2) {
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

    printf("\nCheck that copper treasure cards are gained by adventurer...\n");
    memcpy(&G2, &G1, sizeof(struct gameState));
    for (i = 0; i < G2.deckCount[player1]; i++) {
        G2.deck[player1][i] = copper;
    }
    cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);
    printf("Initial hand count was %d, new hand count is %d, expected 7...", G1.handCount[player1],
           G2.handCount[player1]);
    // make sure the new hand count is +2. two new treasure cards should be gained.
    if (G2.handCount[player1] == G1.handCount[player1] + 2) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    printf("\nCheck that silver treasure cards are gained by adventurer...\n");
    memcpy(&G2, &G1, sizeof(struct gameState));
    for (i = 0; i < G2.deckCount[player1]; i++) {
        G2.deck[player1][i] = silver;
    }
    cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);
    printf("Initial hand count was %d, new hand count is %d, expected 7...", G1.handCount[player1],
           G2.handCount[player1]);
    // make sure the new hand count is +2. two new treasure cards should be gained.
    if (G2.handCount[player1] == G1.handCount[player1] + 2) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    printf("\nCheck that gold treasure cards are gained by adventurer...\n");
    memcpy(&G2, &G1, sizeof(struct gameState));
    for (i = 0; i < G2.deckCount[player1]; i++) {
        G2.deck[player1][i] = gold;
    }
    cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);
    printf("Initial hand count was %d, new hand count is %d, expected 7...", G1.handCount[player1],
           G2.handCount[player1]);
    // make sure the new hand count is +2. two new treasure cards should be gained.
    if (G2.handCount[player1] == G1.handCount[player1] + 2) {
        printf("PASSED.\n");
    } else {
        printf("FAILED.\n");
    }

    return 0;
}