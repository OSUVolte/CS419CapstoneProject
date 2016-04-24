/*
 * Carolyn Cheung
 * Testing: Great Hall
 *      Action: Reveal cards from deck until 2 treasure cards, put
 *              those treasure cards into your and and discard the
 *              rest of the revealed cards
 *              Only get 1 treasure card if only 1 is in the deck
 *      cost: 6 coins
 * +2 treasure cards
 * +? to deck
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

#define TESTCARD "Great Hall"

void testGreatHall() {

    struct gameState gState, gStateTest;
    int newCards = 0;
    int newActions = 0;
    int played = 1;
    int seed = 7;
    int numPlayers = 3;
    int p = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, handPos = 0;
    int cardCount = 0, cardCountTest = 0;
    int i, j;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &gStateTest);
    initializeGame(numPlayers, k, seed, &gState);

    cardEffect(great_hall, choice1, choice2, choice3, &gStateTest, handPos, bonus);
    newCards = 1;
    newActions = 1;

    printf("==== TESTING: %s ====\n", TESTCARD);
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d vs %d\n", gState.handCount[p] + newCards - played, gStateTest.handCount[p]);
    printf(" p0 deck count = %d vs %d\n", gState.deckCount[p] - newCards, gStateTest.deckCount[p]);
    printf(" p1 hand count = %d vs %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf(" p1 deck count = %d vs %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf(" p0 played count = %d vs %d\n", gState.playedCards[p] + played, gStateTest.playedCards[p]);
    printf(" p1 played count = %d vs %d\n", gState.playedCards[1], gStateTest.playedCards[1]);
    printf(" p0 actions %d vs %d\n", gState.numActions + newActions, gStateTest.numActions);
    printf(" estate count = %d vs %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d vs %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d vs %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    for (i = 0; i < 10; i++) {
        cardCount += supplyCount(k[i], &gState);
        cardCountTest += supplyCount(k[i], &gStateTest);
    }
    printf(" kingdom card count = %d vs %d\n", cardCount, cardCountTest);

    assert(gState.handCount[p] + newCards - played == gStateTest.handCount[p]);
    assert(gState.deckCount[p] - newCards == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.playedCards[p] + played == gStateTest.playedCards[p]);
    assert(gState.playedCards[1] == gStateTest.playedCards[1]);
    assert(gState.numActions + newActions == gStateTest.numActions);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    assert(cardCount == cardCountTest);

    printf("\n      testGreatHall(): PASS\n");
}

int main() {
    testGreatHall();
    return 0;
}
