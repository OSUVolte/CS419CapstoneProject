/************
Author:James Taylor
Date: 4/24/16

Card test for smithy_ref()

    test that played smithy card results in +3 to players hand count and that smithy is
    discarded from current hand. Net hand count should be 7, with 1 less smithy card in player
    hand.

*************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"

void cardtest1()
{

    int numPlayer = 2;
    int seed = 10000;
    int player = 0; // 0=player 1
    char cardName[20];


    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    struct gameState G;
    initializeGame(numPlayer, k, seed, &G);

    printf("\n********************************\n");
    printf("\nCardTest1 - testing smithy_ref()\n");
    printf("\n********************************\n");

    //printf("%d\n", G.handCount[player]); //print hand count

    //shuffle(player, &G);
    G.hand[player][0] = smithy;
    //printHand(player, &G); //print hand to check that smithy is available to play

    smithy_ref(&G, player, 0);
    //printHand(player, &G); //print updated hand to readily see if player hand updated correctly.

    if(G.handCount[player] == 7)
        printf("PASS: Player hand updated to %d cards after playing smithy (5+3- (1 played))\n", G.handCount[player]);
    else
        printf("FAIL: Player hand count of %d not equal to 7\n", G.handCount[player]);

    cardNumToName(G.playedCards[0], cardName);
    if(strcmp(cardName, "Smithy") == 0)
        printf("PASS: Smithy has been played and put into played pile.\n");
    else
        printf("FAIL: Smithy has not been put into played pile.\n");

//    for(i = 0; i < G.handCount[player]; i++)
//    {
//
//        cardNumToName(G.hand[player][i], cardName);
//        printf("%s\n", cardName);
//    }



}


int main()
{

    cardtest1();

    return 0;
}
