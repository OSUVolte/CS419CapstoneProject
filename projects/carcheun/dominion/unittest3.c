/*
 * Carolyn Cheung
 * Testing: drawCard
 *      Draw a card
 */
 #include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "DrawCard()"

void testDrawCard() {
    struct gameState gState, gStateTest;
    int newCards = 1;
    int seed = 7;
    int numPlayers = 2;
    int p = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, handPos = 0;
    int cardCount = 0, cardCountTest = 0;
    int i, j;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &gStateTest);
    initializeGame(numPlayers, k, seed, &gState);

    for (i = 0; i < gStateTest.deckCount[p]; i++) {
            gStateTest.deck[p][i] = baron;
            gState.deck[p][i] = baron;
    }

    drawCard(p, &gStateTest);


    printf("==== TESTING: %s ====\n", TESTCARD);
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d, p0 hand count = %d\n", gState.handCount[p] + newCards, gStateTest.handCount[p]);
    printf(" p0 deck count = %d, p0 deck count = %d\n", gState.deckCount[p] - newCards, gStateTest.deckCount[p]);
    printf(" p1 hand count = %d, p1 hand count = %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf(" p1 deck count = %d, p1 deck count = %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf(" estate count = %d, estate count = %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d, duchy count = %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d, province count = %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    printf(" Baron drawn from deck: %d vs %d\n", baron, gStateTest.hand[p][gStateTest.handCount[p]]);
    for (i = 0; i < 10; i++) {
        cardCount += supplyCount(k[i], &gState);
        cardCountTest += supplyCount(k[i], &gStateTest);
    }
    printf(" kingdom card count = %d, kingdom card count = %d\n", cardCount, cardCountTest);

    assert(gState.handCount[p] + newCards == gStateTest.handCount[p]);
    assert(gState.deckCount[p] - newCards == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    assert(cardCount == cardCountTest);
    assert(baron == gStateTest.hand[p][5]);

    printf("\n      testDrawCard(): PASS\n");
}

int main() {
    testDrawCard();
    return 0;
}
