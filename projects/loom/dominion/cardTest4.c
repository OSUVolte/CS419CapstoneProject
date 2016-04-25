//
// Created by Michael Loo on 4/24/16.
//

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player;
    int i, initialAct, finalAct, initialHand, finalHand, initialDeck, finalDeck;
    struct gameState Game;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};


    printf("Testing Great Hall card\n");
    srand(time(NULL));

    int seed = rand() % 10;

    initializeGame(2, k, seed, &Game);

    player = Game.whoseTurn;

    for (i = 0; i < 5; i++){

        initialAct = Game.numActions;
        initialDeck = Game.deckCount[player];
        initialHand = Game.handCount[player];

        cardEffect(great_hall, 0,0,0, &Game, 0, 0);

        finalAct = Game.numActions;
        finalDeck = Game.deckCount[player];
        finalHand = Game.handCount[player];

        if (finalAct - initialAct != 1) {
            printf("The great hall card did not add an action!\n");
        }

        if (initialDeck - finalDeck != 1) {
            printf("One card was not drawn from the deck\n");
        }

        if (finalHand - initialHand != 1) {
            printf("One card was not added to the players hand!\n");
        }

    }

    return 0;


}