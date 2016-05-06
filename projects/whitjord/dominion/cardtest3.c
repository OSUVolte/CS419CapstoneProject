#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "village cardEffect"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 999;
    int num_players = 3;
    int result;
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    printf(">>> testing %s \n", TESTFUNCTION);
    int player;
    player = whoseTurn(&tg);

    // set firs card to village
    tg.hand[player][0] = village;
   
    result = cardEffect(village, 0, 0, 0, &tg, 0, 0);

    printf("%d cards in hand, expecting %d\n", tg.handCount[player], og.handCount[player]);
    assert(tg.handCount[player] == og.handCount[player]);
    printf("%d actions, expecting %d\n", tg.numActions, og.numActions + 2);
    assert(tg.numActions == og.numActions + 2);
    printf("%s returned %d, expecting 0\n", TESTFUNCTION, result);
    assert(result == 0);
 
    printf(">>> end of %s test \n\n", TESTFUNCTION);
    return 0;
}
