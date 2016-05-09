/*
 * Carolyn Cheung
 * Testing: Smithy
 *      Action: +3 cards
 *      cost: 4 coins
 * only current player receives 3 cards for their own deck
 * no hand/deck change for other player
 * no change in supply cards pile
 */
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "smithy"

int MAX_TESTS = 2000;

int randomTestSmithy (int p, struct gameState *post) {
    struct gameState Gtest;
    memcpy(&Gtest, post, sizeof(struct gameState));
    if (Gtest.deckCount[p] != post->deckCount[p]){
        printf("WHAT???\n");
    }

    int r, i, a, b, c;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, handPos = 0;
    int numPlayers = post->numPlayers;
    int pass = 1;

    r = cardEffect(smithy, choice1, choice2, choice3, post, bonus, &handPos);

// draw 3 cards, discard smithy card, +3-1 = 2
    Gtest.handCount[p] += 2;
    Gtest.deckCount[p] -= 3;

// check other players to see if their hands have changed
    for (i = 0; i < numPlayers; i++) {
        if (i != p) {
            a = Gtest.handCount[i];
            b = post->handCount[i];
            if (a != b) {
                printf("FAILED PLAYER %d HANDCOUNT: EXPECTED = %d, REAL = %d\n", i, a, b);
                pass--;
            }
            a = Gtest.deckCount[i];
            b = post->deckCount[i];
            if (a != b) {
                printf("FAILED PLAYER %d DECKCOUNT: EXPECTED = %d, REAL = %d\n", i, a, b);
                pass--;
            }
        }
    }

// check if player got extra cards, deck got smaller
    a = Gtest.handCount[p];
    b = post->handCount[p];
    if (a != b) {
        printf("FAILED CURRENT PLAYER HANDCOUNT: EXPECTED = %d, REAL = %d\n", a, b);
        pass--;
    }
    a = Gtest.deckCount[p];
    b = post->deckCount[p];
    if (a != b) {
        printf("FAILED CURRENT PLAYER DECKCOUNT: EXPECTED = %d, REAL = %d\n", a, b);
        pass--;
    }
// check supplies to see if any were taken
    a = Gtest.supplyCount[estate];
    b = post->supplyCount[estate];
    if (a != b) {
        printf("FAILED CURRENT PLAYER ESTATE SUPPLYCOUNT: EXPECTED = %d, REAL = %d\n", a, b);
        pass--;
    }

    a = Gtest.supplyCount[duchy];
    b = post->supplyCount[duchy];
    if (a != b) {
        printf("FAILED CURRENT PLAYER DUCHY SUPPLYCOUNT: EXPECTED = %d, REAL = %d\n", a, b);
        pass--;
    }

    a = Gtest.supplyCount[province];
    b = post->supplyCount[province];
    if (a != b) {
        printf("FAILED CURRENT PLAYER PROVINCE SUPPLYCOUNT: EXPECTED = %d, REAL = %d\n", a, b);
        pass--;
    }

    return pass;
}

int main()
{
    srand(time(NULL));
    int seed;

    int i, n, r, p, decCount, discardCount, handCount, numPlayers;
    int a, b, handPos = 0, pass = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState Gtest;

    printf("==== TESTING: %s ====\n", TESTCARD);
    printf(" RANDOM TESTS: %d\n\n", MAX_TESTS);
    printf("    - Hand Count / Deck Count of: \n");
    printf("        -Current Player, Other Players\n");
    printf("    - Supply Count for: \n");
    printf("        -Duchy, Estate, Province\n\n");

    for (n = 0; n < MAX_TESTS; n++) {
        seed = rand() % 100 + 1;
        numPlayers = rand() %(MAX_PLAYERS - 1) + 2;
        initializeGame(numPlayers, k, seed, &G);

        p = floor(Random() * numPlayers);

        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.whoseTurn = p;

        pass += randomTestSmithy(p, &G);
    }
    printf("===========================\n");
    if (pass == MAX_TESTS)
        printf(" RANDOM TESTS PASSED\n");
    else
        printf(" RANDOM TESTS HAS FAILED\n");
    printf("===========================\n");

    return 0;
}
