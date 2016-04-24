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
    //Testing updateCoins
    int player = 0;
    int testCount = 0;
    int i;
    struct gameState Game;

    for (i = 0; i < 5; i++) {
        gainCard(copper, &Game, 2, player);
        testCount += 1;
    }

    for (i = 0; i < 2; i++) {
        gainCard(silver, &Game, 2, player);
        testCount += 2;
    }

    for (i = 0; i < 3; i++) {
        gainCard(gold, &Game, 2, player);
        testCount += 3;
    }

    updateCoins(player, &Game, 1);

    testCount += 1;

    int newCoins = Game.coins;

    if (newCoins != testCount) {
        printf("The coin count is not correct!\n");
    }

    return 0;


}