#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "steward cardEffect"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 999;
    int num_players = 3;
    int result;
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    printf(">>> testing %s \n", TESTFUNCTION);
    int player = whoseTurn(&tg);
    tg.hand[player][0] = steward;

    // +2 cards
    result = cardEffect(steward, 1, 0, 0, &tg, 0, 0);
    printf("%d cards in hand, expecting %d\n", tg.handCount[player], og.handCount[player] + 2 - 1);
    assert(tg.handCount[player] == og.handCount[player] + 2 - 1);
    printf("%d coins, expecting %d\n", tg.coins, og.coins);
    assert(tg.coins == og.coins);
    printf("%s returned %d, expecting 0\n", TESTFUNCTION, result);
    assert(result == 0);

    // reset state
    memcpy(&tg, &og, sizeof(struct gameState));
    tg.hand[player][0] = steward;

    // +2 coins
    result = cardEffect(steward, 2, 0, 0, &tg, 0, 0);
    printf("%d cards in hand, expecting %d\n", tg.handCount[player], og.handCount[player] - 1);
    assert(tg.handCount[player] == og.handCount[player] - 1);
    printf("%d coins, expecting %d\n", tg.coins, og.coins + 2);
    assert(tg.coins == og.coins + 2);
    printf("%s returned %d, expecting 0\n", TESTFUNCTION, result);
    assert(result == 0);

    // reset state
    memcpy(&tg, &og, sizeof(struct gameState));
    tg.hand[player][0] = steward;

    // trash 2 cards
    result = cardEffect(steward, 3, 0, 0, &tg, 0, 0);
    printf("%d cards in hand, expecting %d\n", tg.handCount[player], og.handCount[player] - 2 - 1);
    assert(tg.handCount[player] == og.handCount[player] - 2 - 1);
    printf("%d coins, expecting %d\n", tg.coins, og.coins);
    assert(tg.coins == og.coins);
    printf("%s returned %d, expecting 0\n", TESTFUNCTION, result);
    assert(result == 0);
    printf("%d cards discarded, expecting %d\n", tg.discardCount[player], og.discardCount[player]);
    assert(tg.discardCount[player] == og.discardCount[player]);

 
    printf(">>> end of %s test \n\n", TESTFUNCTION);
    return 0;
}
