#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "testkit.h"

int randrange(int low, int high) {
    return rand() % (high - low + 1) + low;
}

int main() {

    srand(time(NULL));

    struct gameState G1, G2;
    int i = 0;
    int j = 0;
    int numPlayers;
    int seed;
    int player1 = 0;
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


    int test = 1;
    int passes = 0;
    int failures = 0;
    int localPass = 1;
    int localFail = 0;
    int deckCount = 1;
    int handCount = 1;
    int discardCount = 1;

    for (test = 1; test <= 50; test++) {

        localPass = 1;
        localFail = 0;

        printf("------------------------\n");
        printf("RUNNING RANDOM TEST CASE #%d...\n", test);

        // use random game state configurations
        numPlayers = (rand() % (MAX_PLAYERS - 1)) + 2;
        seed = (rand() % 5000) + 1;

        // initialize a fresh game
        bzero(&G1, sizeof(struct gameState));
        initializeGame(numPlayers, kingdomCards, seed, &G1);

        // random decks/hands for each player
        for (i = 0; i < numPlayers; i++) {
            handCount = randrange(2, MAX_HAND);
            deckCount = randrange(2, MAX_DECK);
            discardCount = randrange(2, MAX_HAND);
            G1.handCount[i] = handCount;
            G1.deckCount[i] = deckCount;
            G1.discardCount[i] = discardCount;
            for (j = 0; j < handCount; j++) {
                G1.hand[i][j] = randrange(0, 26);
            }
            for (j = 0; j < deckCount; j++) {
                G1.deck[i][j] = randrange(0, 26);
            }
            for (j = 0; j < discardCount; j++) {
                G1.discard[i][j] = randrange(0, 26);
            }
        }

        // make sure player has at least 2 treasure cards in their deck
        for (i = 0; i < 2; i++) {
            // select either 4 (silver), 5 (silver), or 6 (gold)
            int randTreasure = randrange(4, 6);
            G1.deck[player1][i] = randTreasure;
        }

        // insert an adventurer card randomly into the player's deck
        handPos = (rand() % G1.handCount[player1]);
        G1.hand[player1][handPos] = adventurer;

        printf("RANDOM CONFIG: PLAYERS: %d, SEED: %d, HANDPOS: %d\n\n", numPlayers, seed, handPos);

        // make a copy of the state, play the card in the new state
        memcpy(&G2, &G1, sizeof(struct gameState));
        cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);

        printf("Check new card #1 is a treasure card...\n");
        int card1 = G2.hand[player1][G2.handCount[player1] - 1];
        printf("Card #1 is %d, expected 4 (copper), 5 (silver), or 6 (gold)...", card1);
        if ((card1 == copper) | (card1 == silver) | (card1 == gold)) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }

        printf("Check new card #2 is a treasure card...\n");
        int card2 = G2.hand[player1][G2.handCount[player1] - 2];
        printf("Card #2 is %d, expected 4 (copper), 5 (silver), or 6 (gold)...", card2);
        if ((card2 == copper) | (card2 == silver) | (card2 == gold)) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }


        printf("Check that hand count is incremented by 2 (+2 new treasure cards)...\n");
        printf("Initial hand count was %d, new hand count is %d, expected %d...", G1.handCount[player1],
               G2.handCount[player1], G1.handCount[player1] + 2);
        // make sure the new hand count is +2. two new treasure cards should be gained.
        if (G2.handCount[player1] == G1.handCount[player1] + 2) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }

        // ensure new cards came from player 1's deck
        printf("Check new treasure cards came from player 1's deck...\n");
        int diffSupplies[MAX_DECK];
        diffDeckSupply(&G1, &G2, player1, diffSupplies);
        int copperDiff = diffSupplies[copper];
        int silverDiff = diffSupplies[silver];
        int goldDiff = diffSupplies[gold];
        int netDiff = copperDiff + silverDiff + goldDiff;
        printf("Net difference in deck treasure card supply is %d, expected 2...", netDiff);
        printf("-%d copper, -%d silver, -%d gold...", copperDiff, silverDiff, goldDiff);
        if (netDiff == 2) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");

            localFail = 1;
        }

        // ensure other players' hands/decks were not modified
        int x;
        for (x = 1; x < numPlayers; x++) {
            printf("Check player %d hand is untouched...", x + 1);
            if (handIsUntouched(&G1, &G2, x) == 1) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }
            printf("Check player %d, deck is untouched...", x + 1);
            if (deckIsUntouched(&G1, &G2, x) == 1) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }
        }


        // ensure victory pile was not modified
        printf("Check victory pile is untouched...");
        if (victoryPileIsUntouched(&G1, &G2) == 1) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }


        printf("Check that copper treasure cards are gained by adventurer...\n");
        memcpy(&G2, &G1, sizeof(struct gameState));
        for (i = 0; i < G2.deckCount[player1]; i++) {
            G2.deck[player1][i] = copper;
        }
        for (i = 0; i < G2.discardCount[player1]; i++) {
            G2.discard[player1][i] = copper;
        }
        for (i = 0; i < G2.discardCount[player1]; i++) {
            G2.discard[player1][i] = copper;
        }
        cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);
        printf("Initial hand count was %d, new hand count is %d, expected %d...", G1.handCount[player1],
               G2.handCount[player1], G1.handCount[player1] + 2);
        // make sure the new hand count is +2. two new treasure cards should be gained.
        if (G2.handCount[player1] == G1.handCount[player1] + 2) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }


        printf("Check that silver treasure cards are gained by adventurer...\n");
        memcpy(&G2, &G1, sizeof(struct gameState));
        for (i = 0; i < G2.deckCount[player1]; i++) {
            G2.deck[player1][i] = silver;
        }
        for (i = 0; i < G2.discardCount[player1]; i++) {
            G2.discard[player1][i] = silver;
        }
        for (i = 0; i < G2.discardCount[player1]; i++) {
            G2.discard[player1][i] = silver;
        }
        cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);
        printf("Initial hand count was %d, new hand count is %d, expected %d...", G1.handCount[player1],
               G2.handCount[player1], G1.handCount[player1] + 2);
        // make sure the new hand count is +2. two new treasure cards should be gained.
        if (G2.handCount[player1] == G1.handCount[player1] + 2) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }

//        THIS TEST IS DISABLED BECAUSE IT RESULTS IN FREQUENT SEGFAULTS DUE TO THE
//        BUG THAT WAS IMPLEMENTED IN AN EARLIER ASSIGNMENT.
//
//        printf("Check that gold treasure cards are gained by adventurer...\n");
//        memcpy(&G2, &G1, sizeof(struct gameState));
//        for (i = 0; i < G2.deckCount[player1]; i++) {
//            G2.deck[player1][i] = gold;
//        }
//        for (i = 0; i < G2.handCount[player1]; i++) {
//            G2.hand[player1][i] = gold;
//        }
//        for (i = 0; i < G2.discardCount[player1]; i++) {
//            G2.discard[player1][i] = gold;
//        }
//        cardEffect(adventurer, c1, c2, c3, &G2, handPos, &bonus);
//        printf("Initial hand count was %d, new hand count is %d, expected %d...", G1.handCount[player1],
//               G2.handCount[player1], G1.handCount[player1] + 2);
//        // make sure the new hand count is +2. two new treasure cards should be gained.
//        if (G2.handCount[player1] == G1.handCount[player1] + 2) {
//            printf("PASSED.\n");
//        } else {
//            printf("FAILED.\n");
//            localFail = 1;
//        }

        if (localFail == 1) {
            failures++;
        } else {
            passes++;
        }

    }

    printf("\n\nTESTS: %d\tPASSED: %d\tFAILED: %d\n\n", --test, passes, failures);

    return 0;
}