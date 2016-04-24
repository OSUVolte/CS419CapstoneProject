/*
 * Carolyn Cheung
 * Testing: Council Room
 *      Action: +4 cards, +1 buy, each other player draws a card
 *      cost: 5 coins
 * only current player receives 4 cards for their own deck
 * +1 buy for current player
 * +1 card for all other players
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

#define TESTCARD "council room"

void testCouncilRoom() {
    struct gameState gState, gStateTest;
    int newCards = 0;
    int buy = 1;
    int discard = 1;
    int otherPlayerNewCards = 0;
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

    printf("==== TESTING: %s ====\n", TESTCARD);
    cardEffect(council_room, choice1, choice2, choice3, &gStateTest, handPos, bonus);
    newCards = 4;
    otherPlayerNewCards = 1;
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d vs %d\n", gState.handCount[p] + newCards - discard, gStateTest.handCount[p]);
    printf(" p0 deck count = %d vs %d\n", gState.deckCount[p] - newCards + discard, gStateTest.deckCount[p]);
    printf(" p1 hand count = %d vs %d\n", gState.handCount[1] + otherPlayerNewCards, gStateTest.handCount[1]);
    printf(" p1 deck count = %d vs %d\n", gState.deckCount[1] - otherPlayerNewCards, gStateTest.deckCount[1]);
    printf(" p2 hand count = %d vs %d\n", gState.handCount[2] + otherPlayerNewCards, gStateTest.handCount[2]);
    printf(" p2 deck count = %d vs %d\n", gState.deckCount[2] - otherPlayerNewCards, gStateTest.deckCount[2]);
    printf(" estate count = %d vs %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d vs %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d vs %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    for (i = 0; i < 10; i++) {
        cardCount += supplyCount(k[i], &gState);
        cardCountTest += supplyCount(k[i], &gStateTest);
    }
    printf(" kingdom card count = %d vs %d\n", cardCount, cardCountTest);
    printf(" numBuys = %d vs %d\n", gState.numBuys + buy, gStateTest.numBuys);
    printf(" numActions = %d vs %d\n", gState.numActions, gStateTest.numActions);

    assert(gState.handCount[p] + newCards - discard == gStateTest.handCount[p]);
    assert(gState.deckCount[p] - newCards + discard == gStateTest.deckCount[p] + gStateTest.playedCards[p]);
    assert(gState.handCount[1] + otherPlayerNewCards == gStateTest.handCount[1]);
    assert(gState.deckCount[1] - otherPlayerNewCards == gStateTest.deckCount[1]);
    assert(gState.handCount[2] + otherPlayerNewCards == gStateTest.handCount[2]);
    assert(gState.deckCount[2] - otherPlayerNewCards == gStateTest.deckCount[2]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);

    printf("\n      testCouncilRoom(): PASS\n");
}

int main() {
    testCouncilRoom();
    return 0;
}
