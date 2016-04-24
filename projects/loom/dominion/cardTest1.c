//
// Created by Michael Loo on 4/23/16.
//
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player = 0;
    int testCount = 0;
    int i, initialCard, finalCard;
    struct gameState Game;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    //testing smithy card
    printf("Testing smithy card\n");

    srand(time(NULL));

    int seed = rand() % 10;

    initializeGame(2, k, seed, &Game);

    for (i = 0; i < 5; i++){

        initialCard = Game.handCount[Game.whoseTurn];

        cardEffect(smithy, 0,0,0, &Game, 0, 0);

        finalCard = Game.handCount[Game.whoseTurn];

        if (finalCard != (initialCard + 2)) {
            printf("Smithy does not add correct number of cards\n");
        }
    }

    return 0;
}