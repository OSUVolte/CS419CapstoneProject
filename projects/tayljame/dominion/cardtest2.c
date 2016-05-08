/************
Author:James Taylor
Date: 4/24/16

Card test for adventurer_ref()

    adventurer_ref: test that player coin count increase by the value of two added coin cards.
                    Test that all other drawn cards are sent to discard. Default implementation will draw 3 cards:
                        Estate, Copper, Copper.
                    Tests will verify that resulting game states reflects +2 to coin count of player hand and
                    adding Estate card to discard pile.


*************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"

void cardtest2()
{
    int numPlayer = 2;
    int seed = 10000;
    int player = 0; // 0=player 1
    int treasureCount = 0;
    int treasureCountAfter = 0;
    char cardName[20];


    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    struct gameState G;
    initializeGame(numPlayer, k, seed, &G);

    printf("\n********************************\n");
    printf("\nCardTest2 - testing adventurer_ref()\n");
    printf("\n********************************\n");

    //printHand(player, &G);
    printDeck(player, &G); //verify only coppers in Deck

    G.hand[player][0] = adventurer; // place adventurer card into Player hand
    printHand(player, &G); //verify only coppers in player hand
    printDiscard(player, &G); //verify 0 cards in discard

    treasureCount = countHandCoins(player, &G); //save state of Coin count
    adventurer_ref(&G, player);
    treasureCountAfter = countHandCoins(player, &G); //save new state of coin count
    if(treasureCountAfter == treasureCount + 2)
        printf("PASS: treasure count is 2 higher than previous count(Current Deck only contains Coppers)\n\n");
    else
        printf("FAIL: treasure count is not 2 higher than previous count(Current Deck only contains Coppers\n\n");


    printHand(player, &G); //verify coin count is +2 coppers


    printDiscard(player, &G); //verify discard now contains 1 discard (from position 0 in deck)

    cardNumToName(G.discard[0][0], cardName);
    if(strcmp(cardName, "Estate") == 0)
        printf("PASS: Discard contains 1 (Estate card from player discard[0]\n\n");
    else
        printf("FAIL: Discard contains incorrect discards\n\n");



}

int main()
{
    cardtest2();

    return 0;
}
