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
    //Testing supplyCount function
    int i, y;
    int test[10];
    struct gameState Game;

    srand(time(NULL));

    for(i = 0; i<11; i++) {
        test[i] = i;
        Game.supplyCount[i] = i;
    }

    for(i = 0; i<11; i++) {

        y = supplyCount(i, &Game);

        if(y != test[i]) {
            printf("Number of cards doesn't match!\n");
        }
    }

    return 0;
}