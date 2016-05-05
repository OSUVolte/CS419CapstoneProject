#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "whoseTurn"

int main(){
    struct gameState og, tg;
    int k[10] = {adventurer, smithy, great_hall, village, mine, minion, council_room, gardens, feast, baron};
    int seed = 999;
    int num_players = 3;
    int turn; // store the player # whos turn it is
    initializeGame(num_players, k, seed, &og);
    memcpy(&tg, &og, sizeof(struct gameState));
    printf(">>> testing %s \n", TESTFUNCTION);
    turn =  whoseTurn(&tg);
    printf("player %d's turn expecting %d \n", turn, 0);
    assert(turn == 0);
    tg.whoseTurn = 2;
    turn =  whoseTurn(&tg);
    printf("player %d's turn expecting %d \n", turn, 2);
    assert(turn == 2);
    printf(">>> end of %s test \n\n", TESTFUNCTION);
    return 0;
}
