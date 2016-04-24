//
// Created by Michael Loo on 4/22/16.
//

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Testing numCards function
    int i, card;
    struct gameState Game;

    srand(time(NULL));

    for(i = 0; i<11; i++) {

        Game.whoseTurn = i;
        Game.handCount[i] = i;

        card = numHandCards(&Game);

        if (card != i) {
            printf("Number of cards doesn't match!\n");
        }
    }

    return 0;
}
