/*
Susan Eldridge
Spring 2016
CS361
This card should cause 4 cards and gain a buy.  Each other player will gain a single card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int handP = 3;//hand position
    int player = 1;
    struct gameState game, testgame;
    int playerNumber = 2;
    int kCards[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};
    int rSeed = 50;

    initializeGame(playerNumber, kCards, rSeed, &game);

    printf("----------TESTING Council_Room()----------\n\n");
    //tell it whose turn it is
    game.whoseTurn = player;
    //put 5 cards in hand
    game.handCount[player] = 5;
    //put smithy card in hand
    game.hand[player][handP] = adventurer;
    //put cards in deck to draw from
    game.deckCount[player] = 10;
    game.deck[player][0] = copper;
    game.deck[player][1] = adventurer;
    game.deck[player][2] = copper;
    game.deck[player][3] = smithy;
    game.deck[player][4] = gold;
    game.deck[player][5] = village;
    game.deck[player][6] = silver;
    game.deck[player][7] = copper;
    game.deck[player][8] = council_room;
    game.deck[player][9] = copper;

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test

    cardEffect(council_room, 0, 0, 0, &game, handP, 0);

    //player should gain 4 cards and discard the council room card, so total increment of cards is 3
    if(game.handCount[player] == testgame.handCount[player] + 3)
    {
        printf("Test 1 (player gains 4 cards) passed.\n");
    }
    else
    {
        printf("Test 1 (player gains 4 cards) failed.\n");
    }

    //opponents should gain one card each
    if(game.handCount[player - 1] == testgame.handCount[player - 1] + 1)
    {
        printf("Test 2 (opponent gains 1 card) passed.\n");
    }
    else
    {
        printf("Test 2 (opponent gains 1 card) failed.\n");
    }

    //player gains a buy
    if(game.numBuys == testgame.numBuys + 1)
    {
        printf("Test 3 (player gained a buy) passed.\n");
    }
    else
    {
        printf("Test 2 (player gained a buy) failed.\n");
    }

    //player does not gain an action
    if(game.numActions == testgame.numActions)
    {
        printf("Test 4 (player actions unchanged) passed.\n");
    }
    else
    {
        printf("Test 4 (player actions unchanged) failed.\n");
    }

    //player adds council_room to played card pile
    if(game.playedCards[game.playedCardCount - 1] == council_room)
    {
        printf("Test 5 (player added council room to played pile) passed.\n");
    }
    else
    {
        printf("Test 5 (player added council room to played pile) failed.\n");
    }

    return 0;
}
