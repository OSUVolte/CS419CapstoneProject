/*
 * Carolyn Cheung
 * Testing: discardCard
 *      discard a card
 */
 #include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "discardCard()"

void testDiscardCard() {
    struct gameState gState, gStateTest;
    int seed = 7;
    int discard = 1;
    int numPlayers = 2;
    int p = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, handPos = 0;
    int cardCount = 0, cardCountTest = 0;
    int i, j;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &gStateTest);
    initializeGame(numPlayers, k, seed, &gState);
    discardCard(0, p, &gStateTest, 0);  // not trash

    printf("==== TESTING: %s ====\n", TESTCARD);
    printf("\nCASE 1: Card is played, not trashed\n");
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d, p0 hand count = %d\n", gState.handCount[p] - discard, gStateTest.handCount[p]);
    printf(" p0 deck count = %d, p0 deck count = %d\n", gState.deckCount[p], gStateTest.deckCount[p]);
    printf(" p0 discardCount = %d vs %d\n", gState.discardCount[p], gStateTest.discardCount[p]);
    printf(" Played card count = %d vs %d\n", discard, gStateTest.playedCardCount);
    printf(" p1 hand count = %d, p1 hand count = %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf(" p1 deck count = %d, p1 deck count = %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf(" estate count = %d, estate count = %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d, duchy count = %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d, province count = %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    for (i = 0; i < 10; i++) {
        cardCount += supplyCount(k[i], &gState);
        cardCountTest += supplyCount(k[i], &gStateTest);
    }
    printf(" kingdom card count = %d, kingdom card count = %d\n", cardCount, cardCountTest);

    assert(gState.handCount[p] - discard == gStateTest.handCount[p]);
    assert(gState.deckCount[p] == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.discardCount[p] == gStateTest.discardCount[p]);
    assert(discard == gStateTest.playedCardCount);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    printf("    CASE 1 PASS\n");

    initializeGame(numPlayers, k, seed, &gStateTest);
    initializeGame(numPlayers, k, seed, &gState);
    discardCard(0, p, &gStateTest, 1);  // not trash

    printf("\nCASE 2: Card is trashed, not played\n");
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d, p0 hand count = %d\n", gState.handCount[p] - discard, gStateTest.handCount[p]);
    printf(" p0 deck count = %d, p0 deck count = %d\n", gState.deckCount[p], gStateTest.deckCount[p]);
    printf(" p0 discardCount = %d vs %d\n", gState.discardCount[p], gStateTest.discardCount[p]);
    printf(" Played card count = %d vs %d\n", gState.playedCardCount, gStateTest.playedCardCount);
    printf(" p1 hand count = %d, p1 hand count = %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf(" p1 deck count = %d, p1 deck count = %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf(" estate count = %d, estate count = %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d, duchy count = %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d, province count = %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    cardCount = 0;
    cardCountTest = 0;
    for (i = 0; i < 10; i++) {
        cardCount += supplyCount(k[i], &gState);
        cardCountTest += supplyCount(k[i], &gStateTest);
    }
    printf(" kingdom card count = %d, kingdom card count = %d\n", cardCount, cardCountTest);

    assert(gState.handCount[p] - discard == gStateTest.handCount[p]);
    assert(gState.deckCount[p] == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.discardCount[p] == gStateTest.discardCount[p]);
    assert(gState.playedCardCount == gStateTest.playedCardCount);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    printf("    CASE 2 PASS\n");

    printf("\n      testDiscardCard(): PASS\n");
}

int main() {
    testDiscardCard();
    return 0;
}
