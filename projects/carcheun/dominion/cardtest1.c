/*
 * Carolyn Cheung
 * Testing: Smithy
 *      Action: +3 cards
 *      cost: 4 coins
 * only current player receives 3 cards for their own deck
 * no hand/deck change for other player
 * no change in victory points pile
 * no change in kingdom cards pile
 */
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "smithy"

void testSmithy() {
    struct gameState gState, gStateTest;
    int newCards = 0;
    int discard = 1;
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

    printf("==== TESTING: %s ====\n", TESTCARD);
    cardEffect(smithy, choice1, choice2, choice3, &gStateTest, handPos, bonus);
    newCards = 3;
    printf("Expected p0 hand count = %d, p0 hand count = %d\n", gState.handCount[p] + newCards - discard, gStateTest.handCount[p]);
    printf("Expected p0 deck count = %d, p0 deck count = %d\n", gState.deckCount[p] - newCards, gStateTest.deckCount[p]);
    printf("Expected p1 hand count = %d, p1 hand count = %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf("Expected p1 deck count = %d, p1 deck count = %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf("Expected estate count = %d, estate count = %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf("Expected duchy count = %d, duchy count = %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf("Expected province count = %d, province count = %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    for (i = 0; i < 10; i++) {
        cardCount += supplyCount(k[i], &gState);
        cardCountTest += supplyCount(k[i], &gStateTest);
    }
    printf("Expected kingdom card count = %d, kingdom card count = %d\n", cardCount, cardCountTest);
    assert(gState.handCount[p] + newCards - discard == gStateTest.handCount[p]);
    assert(gState.deckCount[p] - newCards == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    assert(cardCount == cardCountTest);

    printf("\n      testSmithy(): PASS\n");
}

int main() {
    testSmithy();
    return 0;
}
