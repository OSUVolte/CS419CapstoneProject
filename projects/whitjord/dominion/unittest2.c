#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "isGameOver"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 999;
    int num_players = 3;
    int result;
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    printf(">>> testing %s \n", TESTFUNCTION);

    // test new game
    result = isGameOver(&tg);
    printf("%s returned %d expected 0 \n", TESTFUNCTION, result);
    assert(result == 0);
 
    // test empty provinces
    tg.supplyCount[province] = 0;
    result = isGameOver(&tg);
    printf("%s returned %d expected 1 \n", TESTFUNCTION, result);
    assert(result == 1);

    // reset game state
    memcpy(&tg, &og, sizeof(struct gameState));

    // test 2 supply piles at 0
    tg.supplyCount[adventurer] = 0;
    tg.supplyCount[smithy] = 0;
    result = isGameOver(&tg);
    printf("%s returned %d expected 0 \n", TESTFUNCTION, result);
    assert(result == 0);

    // test 3 supply piles at 0
    tg.supplyCount[great_hall] = 0;
    result = isGameOver(&tg);
    printf("%s returned %d expected 1 \n", TESTFUNCTION, result);
    assert(result == 1);

    printf(">>> end of %s test \n\n", TESTFUNCTION);

    return 0;

}
