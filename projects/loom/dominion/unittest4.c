//
// Created by Michael Loo on 4/23/16.
//

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player = 0;
    int testCount = 0;
    int i, turn, test;
    struct gameState Game;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};


    srand(time(NULL));

    int seed = rand() % 10;

    initializeGame(4, k, seed, &Game);

    struct gameState *gamePoint = &Game;

    for (i = 0; i < 10; i++) {
        turn = rand() % 4;

        gamePoint->whoseTurn = turn;

        test = whoseTurn(&Game);

        if (test != turn)
        {
            printf("whoseTurn does not work!");
        }

    }
}
