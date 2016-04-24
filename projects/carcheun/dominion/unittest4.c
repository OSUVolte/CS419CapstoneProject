/*
 * Carolyn Cheung
 * Testing: scoreFor
 *      Player Score
 */
 #include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "DrawCard()"

void testScoreFor() {
    struct gameState gStateTest;
    int seed = 7;
    int discard = 1;
    int numPlayers = 2;
    int p = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, handPos = 0;
    int cardCount = 0, cardCountTest = 0;
    int i, j, total;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &gStateTest);
    for (i = 0; i < gStateTest.handCount[p]; i++) {
            gStateTest.hand[p][i] = province;
    }

    printf("==== TESTING: %s ====\n", TESTCARD);
    printf("\nCASE 1: Full hand of provinces\n");
    printf("        Expected vs Real\n");
    total = gStateTest.handCount[p] * 6;
    printf(" full hand province = %d vs %d\n", total, scoreFor(p, &gStateTest));
    assert(total == scoreFor(p, &gStateTest));

    initializeGame(numPlayers, k, seed, &gStateTest);
    for (i = 0; i < gStateTest.handCount[p]; i++) {
            gStateTest.hand[p][i] = great_hall;
    }

    printf("\nCASE 2: Full hand of great_hall\n");
    printf("        Expected vs Real\n");
    total = gStateTest.handCount[p] * 1;
    printf(" full hand province = %d vs %d\n", total, scoreFor(p, &gStateTest));
    assert(total == scoreFor(p, &gStateTest));

    initializeGame(numPlayers, k, seed, &gStateTest);

    gStateTest.handCount[p] = 6;
    gStateTest.discardCount[p] = 6;
    gStateTest.deckCount[p] = 6;

    for (i = 0; i < 6; i++) {
        if (i == 0) {
            gStateTest.hand[p][i] = curse;
            gStateTest.deck[p][i] = curse;
            gStateTest.discard[p][i] = curse;
        }
        if ( i == 1) {
            gStateTest.hand[p][i] = estate;
            gStateTest.deck[p][i] = estate;
            gStateTest.discard[p][i] = estate;
        }
        if ( i == 2) {
            gStateTest.hand[p][i] = duchy;
            gStateTest.deck[p][i] = duchy;
            gStateTest.discard[p][i] = duchy;
        }
        if ( i == 3) {
            gStateTest.hand[p][i] = province;
            gStateTest.deck[p][i] = province;
            gStateTest.discard[p][i] = province;
        }
        if (i == 4) {
            gStateTest.hand[p][i] = great_hall;
            gStateTest.deck[p][i] = great_hall;
            gStateTest.discard[p][i] = great_hall;
        }
        if (i == 5) {
            gStateTest.hand[p][i] = gardens;
            gStateTest.deck[p][i] = gardens;
            gStateTest.discard[p][i] = gardens;
        }
    }
    printf("\nCASE 3: 1 of every score card in hand, discard, deck\n");
    printf("        Expected vs Real\n");
    total = 0 -1 +1 + 3 + 6 + 1;
    total += ((gStateTest.handCount[p] + gStateTest.deckCount[p] + gStateTest.discardCount[p]) / 10);
    total *= 3;

    printf(" full hand province = %d vs %d\n", total, scoreFor(p, &gStateTest));
    //assert(total == scoreFor(p, &gStateTest));

    printf("\nCASE 4: hand = estate, deck = duchy, discard = province\n");
    initializeGame(numPlayers, k, seed, &gStateTest);
    gStateTest.discardCount[p] = 3;
    gStateTest.deckCount[p] = 2;

    for (i = 0; i < gStateTest.handCount[p]; i++) {
            gStateTest.hand[p][i] = estate;
            gStateTest.deck[p][i] = duchy;
            gStateTest.discard[p][i] = province;
    }

    total = (1 * gStateTest.handCount[p]) + (3 * 2) + (6 * 3);
    printf(" full hand province = %d vs %d\n", total, scoreFor(p, &gStateTest));
    //assert(total == scoreFor(p, &gStateTest));

    printf("\n      testScoreFor(): PASS\n");
}

int main() {
    testScoreFor();
    return 0;
}
