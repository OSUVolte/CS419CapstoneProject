#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "functionanmehere"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 999;
    int num_players = 3;
    int result;
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    printf(">>> testing %s \n", TESTFUNCTION);
 
    printf(">>> end of %s test \n\n", TESTFUNCTION);
    return 0;
}
