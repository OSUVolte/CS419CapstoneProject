#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "smithy cardEffect"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 999;
    int num_players = 3;
    int result, player;
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    printf(">>> testing %s \n", TESTFUNCTION);
    player = whoseTurn(&tg);
    // make first card smithy
    tg.hand[player][0] = smithy;
    // get some info about state before play smithy
    int prevHandCount = tg.handCount[player];
    int player2HC = tg.handCount[1];
    int player3HC = tg.handCount[2];

    result = cardEffect(smithy, 0, 0, 0, &tg, 0, 0);
    printf("hand count is %d, expecting %d\n", tg.handCount[player], prevHandCount + 3 - 1); // +3 for the 3 new cards, -1 for playing smithy
    assert(tg.handCount[player] == prevHandCount + 3 - 1);
    printf("%s returned %d, expecting 0\n", TESTFUNCTION, result);
    assert(result == 0);
   
    // make sure other players hand counts remain the same
    printf("hand count for other player is %d, expecting %d\n", tg.handCount[1], player2HC);
    assert(tg.handCount[1] == player2HC);
    printf("hand count for other player is %d, expecting %d\n", tg.handCount[2], player3HC);
    assert(tg.handCount[2] == player3HC);

    printf(">>> end of %s test \n\n", TESTFUNCTION);
    return 0;
}
