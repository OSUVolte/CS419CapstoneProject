/*
 * Carolyn Cheung
 * Testing: updateCoins
 *      update current players coins
 */
 #include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define TESTCARD "updateCoins()"

void testUpdateCoins() {
    struct gameState gState, gStateTest;
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
    for (i = 0; i < gStateTest.handCount[p]; i++) {
            gStateTest.hand[p][i] = gold;
            gState.hand[p][i] = baron;
    }
    updateCoins(p, &gStateTest, 0);
    updateCoins(p, &gState, 0);

    printf("==== TESTING: %s ====\n", TESTCARD);
    printf("\nCASE 1: Full baron hand vs Full gold hand coin calculations\n");
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d, p0 hand count = %d\n", gState.handCount[p], gStateTest.handCount[p]);
    printf(" p0 deck count = %d, p0 deck count = %d\n", gState.deckCount[p], gStateTest.deckCount[p]);
    printf(" p1 hand count = %d, p1 hand count = %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf(" p1 deck count = %d, p1 deck count = %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf(" estate count = %d, estate count = %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d, duchy count = %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d, province count = %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    printf(" Full Baron hand vs Full gold hand coin value = %d vs %d\n", gState.coins, gStateTest.coins);

    assert(gState.handCount[p] == gStateTest.handCount[p]);
    assert(gState.deckCount[p] == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    assert(gState.coins != gStateTest.coins);
    printf("    CASE 1 PASS\n");

    initializeGame(numPlayers, k, seed, &gStateTest);
    initializeGame(numPlayers, k, seed, &gState);
    for (i = 0; i < gStateTest.handCount[p]; i++) {
            gStateTest.hand[p][i] = copper;
            gState.hand[p][i] = baron;
    }
    bonus = 3;
    updateCoins(p, &gStateTest, bonus);
    updateCoins(p, &gState, 0);
    printf("\nCASE 2: Full baron hand vs Full copper hand + bonus %d coin calculations\n", bonus);
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d, p0 hand count = %d\n", gState.handCount[p], gStateTest.handCount[p]);
    printf(" p0 deck count = %d, p0 deck count = %d\n", gState.deckCount[p], gStateTest.deckCount[p]);
    printf(" p1 hand count = %d, p1 hand count = %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf(" p1 deck count = %d, p1 deck count = %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf(" estate count = %d, estate count = %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d, duchy count = %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d, province count = %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    printf(" Full Baron hand vs Full copper + bonus: %d hand coin value = %d vs %d\n", bonus, gState.coins, gStateTest.coins);

    assert(gState.handCount[p] == gStateTest.handCount[p]);
    assert(gState.deckCount[p] == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    assert(gState.coins != gStateTest.coins);
    printf("    CASE 2 PASS\n");

    initializeGame(numPlayers, k, seed, &gStateTest);
    initializeGame(numPlayers, k, seed, &gState);
    for (i = 0; i < gStateTest.handCount[p]; i++) {
            gStateTest.hand[p][i] = silver;
    }
    bonus = 3;
    updateCoins(p, &gStateTest, 0);
    updateCoins(p, &gState, 0);
    printf("\nCASE 3: Check silver calculations\n", bonus);
    printf("        Expected vs Real\n");
    printf(" p0 hand count = %d, p0 hand count = %d\n", gState.handCount[p], gStateTest.handCount[p]);
    printf(" p0 deck count = %d, p0 deck count = %d\n", gState.deckCount[p], gStateTest.deckCount[p]);
    printf(" p1 hand count = %d, p1 hand count = %d\n", gState.handCount[1], gStateTest.handCount[1]);
    printf(" p1 deck count = %d, p1 deck count = %d\n", gState.deckCount[1], gStateTest.deckCount[1]);
    printf(" estate count = %d, estate count = %d\n", gState.supplyCount[estate], gStateTest.supplyCount[estate]);
    printf(" duchy count = %d, duchy count = %d\n", gState.supplyCount[duchy], gStateTest.supplyCount[duchy]);
    printf(" province count = %d, province count = %d\n", gState.supplyCount[province], gStateTest.supplyCount[province]);
    printf(" SEED initialized vs full silver hand = %d vs %d\n", gState.coins, gStateTest.coins);

    assert(gState.handCount[p] == gStateTest.handCount[p]);
    assert(gState.deckCount[p] == gStateTest.deckCount[p]);
    assert(gState.handCount[1] == gStateTest.handCount[1]);
    assert(gState.deckCount[1] == gStateTest.deckCount[1]);
    assert(gState.supplyCount[duchy] == gStateTest.supplyCount[duchy]);
    assert(gState.supplyCount[estate] == gStateTest.supplyCount[estate]);
    assert(gState.supplyCount[province] == gStateTest.supplyCount[province]);
    assert(gState.coins != gStateTest.coins);
    printf("    CASE 3 PASS\n");

    printf("\n      testUpdateCoins(): PASS\n");
}

int main(int argc, char *argv[])
{
    testUpdateCoins();
    return 0;
}
