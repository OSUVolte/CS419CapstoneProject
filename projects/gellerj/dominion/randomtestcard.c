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

    // loop control and pass/fail flags
    int test = 1;
    int passes = 0;
    int failures = 0;
    int localPass = 1;
    int localFail = 0;
    int deckCount = 1;
    int handCount = 1;
    int discardCount = 1;
    int randomCard = 16;

    // run 500 tests
    for (test = 1; test <= 500; test++) {

        // if sub-tests fail, entire unit test fails
        localPass = 1;
        localFail = 0;

        printf("------------------------\n");
        printf("GREAT HALL: RUNNING RANDOM TEST CASE #%d...\n", test);

        // use random configurations to initialize game
        numPlayers = (rand() % (MAX_PLAYERS - 1)) + 2;
        seed = (rand() % 50) + 1;

        // initialize a fresh game
        bzero(&G1, sizeof(struct gameState));
        initializeGame(numPlayers, kingdomCards, seed, &G1);

        // random number of game actions
        G1.numActions = randrange(0, 1000);

        // random hands, decks, and discard piles for each player
        for (i = 0; i < numPlayers; i++) {
            handCount = randrange(1, 15);
            deckCount = randrange(0, 15);
            discardCount = randrange(0, 15);
            G1.handCount[i] = handCount;
            G1.deckCount[i] = deckCount;
            G1.discardCount[i] = discardCount;
            for (j = 0; j < handCount; j++) {
                // don't add any great hall cards to this hand
                while (randomCard == 16) {
                    randomCard = randrange(0, 26);
                }
                G1.hand[i][j] = randrange(0, 26);
            }
            randomCard = 16;
            for (j = 0; j < deckCount; j++) {
                while (randomCard == 16) {
                    randomCard = randrange(0, 26);
                }
                G1.deck[i][j] = randrange(0, 26);
            }
            randomCard = 16;
            for (j = 0; j < discardCount; j++) {
                while (randomCard == 16) {
                    randomCard = randrange(0, 26);
                }
                G1.discard[i][j] = randrange(0, 26);
            }
        }

        // insert a great gall card randomly into the player's deck
        handPos = randrange(0, G1.handCount[player1] - 1);
        G1.hand[player1][handPos] = great_hall;

        printf("RANDOM CONFIG: PLAYERS: %d, SEED: %d, HANDPOS: %d\n\n", numPlayers, seed, handPos);

        // make a copy of the state, play the card in the new state
        // the two copies are used for state comparisons to determine pass/fail
        memcpy(&G2, &G1, sizeof(struct gameState));
        cardEffect(great_hall, c1, c2, c3, &G2, handPos, &bonus);

        printf("Check that hand count is incremented by 0 (+1 new draw cards, -1 discard)...\n");
        printf("Initial hand count was %d, new hand count is %d, expected %d...", G1.handCount[player1],
               G2.handCount[player1], G1.handCount[player1]);
        // make sure the new hand count is +0
        if (G1.deckCount[player1] == 0 && G1.discardCount[player1] == 0) {
            if (G2.handCount[player1] == G1.handCount[player1] - 1) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }
        } else {
            if (G2.handCount[player1] == G1.handCount[player1]) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }
        }

        printf("Check number of actions was incremented by 1...\n");
        printf("Initial action count was %d, new action count is %d, expected %d...", G1.numActions,
               G2.numActions, G1.numActions + 1);
        if (G2.numActions == G1.numActions + 1) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }


        // ensure new cards came from player 1's deck or discard
        printf("Check new card came from player 1's deck or discard...");
        int newHandCard = G2.hand[player1][handPos];
        if (G1.deckCount[player1] > 0) {
            int oldDeckCard = G1.deck[player1][G1.deckCount[player1] - 1];
            printf("\nNew deck card is %d, expected %d...", newHandCard, oldDeckCard);
            if (newHandCard == oldDeckCard) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }
        } else {
            int newDeckCount = G2.deckCount[player1];
            int oldDiscardCount = G1.discardCount[player1];
            printf("\nOld discard count was %d, new deck count is %d, expected %d...", oldDiscardCount, newDeckCount,
                   oldDiscardCount -1);
            if (oldDiscardCount == 0 && newDeckCount == 0) {
                printf("PASSED.\n");
            } else if (oldDiscardCount - 1 == newDeckCount) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }

        }


        // ensure great hall was discarded from hand
        printf("Check great hall was discarded from player's hand...\n");
        int supplyBefore = countHandSupply(&G1, player1, great_hall);
        int supplyAfter = countHandSupply(&G2, player1, great_hall);
        printf("Great Hall supply count was %d, new count is %d, expected <= %d...", supplyBefore, supplyAfter,
               supplyBefore);
        if (supplyAfter <= (supplyBefore)) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }

        // ensure other players' hands/decks were not modified
        for (i = 1; i < numPlayers; i++) {
            printf("Check player %d hand is untouched...", i + 1);
            if (handIsUntouched(&G1, &G2, i) == 1) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }
            printf("Check player %d deck is untouched...", i + 1);
            if (deckIsUntouched(&G1, &G2, i) == 1) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
                localFail = 1;
            }
        }

        // ensure kingdom pile was not modified
        printf("Check kingdom pile is untouched...");
        if (kingdomPileIsUntouched(&G1, &G2) == 1) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }


        // ensure victory pile was not modified
        printf("Check victory pile is untouched...");
        if (victoryPileIsUntouched(&G1, &G2) == 1) {
            printf("PASSED.\n");
        } else {
            printf("FAILED.\n");
            localFail = 1;
        }


        // if any of the sub-tests failed, mark this whole unit test as a failure
        if (localFail == 1) {
            failures++;
        } else {
            passes++;
        }

    }

    printf("\n\nTESTS: %d\tPASSED: %d\tFAILED: %d\n\n", --test, passes, failures);

    return 0;
}