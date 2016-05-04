
/************
Author:James Taylor
Date: 4/24/16

Card test for great_hall_ref()

    great_hall_ref: test that player hand count increases by 1.
                    Test actioncount goes up 1.
                    Tests adding GreatHall card to discard pile.


*************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"

void cardtest3()
{
    int numPlayer = 2;
    int seed = 10000;
    int player = 0; // 0=player 1
    int actionCount = 0;
    int actionCountAfter = 0;
    int cardCount = 0;
    int cardCountAfter = 0;
    char cardName[20];


    int k[10] = {adventurer, gardens, great_hall, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    struct gameState G;
    initializeGame(numPlayer, k, seed, &G);

    printf("\n********************************\n");
    printf("\nCardTest3 - testing great_hall_ref()\n");
    printf("\n********************************\n");

    G.hand[player][0] = great_hall;
    //printHand(player, &G);
    //save state before great_hall_ref()
    actionCount = G.numActions;
    cardCount = G.handCount[player];

    great_hall_ref(&G, player, 0);

    //save state after playing great_hall_ref
    actionCountAfter = G.numActions;
    cardCountAfter = G.handCount[player];
    //printPlayed(player, &G);
    //printHand(player, &G);
    if(actionCount + 1 == actionCountAfter)
        printf("PASS: action count increased by 1\n");
    else
        printf("FAIL: action count did not increase by 1\n");
    if(cardCount == cardCountAfter)
        printf("PASS: card count stayed same\n");
    else
        printf("FAIL: card count did not stay the same\n");
    cardNumToName(G.playedCards[0], cardName);
    if(strcmp(cardName, "Great Hall") == 0)
        printf("PASS: great_hall has been played and put into played pile.\n");
    else
        printf("FAIL: great_hall has not been put into played pile.\n");
}

int main()
{
    cardtest3();

    return 0;
}
