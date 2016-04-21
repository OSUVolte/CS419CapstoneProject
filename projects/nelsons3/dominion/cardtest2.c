#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main () {
    struct gameState game;
    int newHand, oldHand;
    int randomSeed = rand();
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};

    printf("Running Unit Test: Adventurer\n");
//create game
//4 players, cards, seed, game struct
    initializeGame(4, k, randomSeed, &game);
    printf("\nstarting hand count Player: %d\n", game.handCount[0]);
    oldHand = game.handCount[0];
//play card
    cardEffect(adventurer, 0, 0, 0, &game, 0, 0);
    printf("\nending hand count Player: %d\n", game.handCount[0]);
    newHand = game.handCount[0];
    assert(newHand = oldHand+2);
    printf("unit Test: Adventurer test successful \n");
return 0;
}
