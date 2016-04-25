/*
Susan Eldridge
Spring 2016
CS361
This card should cause the other players to discard the top card of their deck and then gain a curse
card to place on top of their deck.
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
    int kCards[10] = {adventurer, council_room, feast, gardens, sea_hag, smithy, village, baron, great_hall, minion};
    int rSeed = 50;

    initializeGame(playerNumber, kCards, rSeed, &game);

    printf("----------TESTING Sea_Hag()----------\n\n");
    //tell it whose turn it is
    game.whoseTurn = player;
    //put 5 cards in hand
    game.handCount[player] = 5;
    //put smithy card in hand
    game.hand[player][handP] = adventurer;
    //put cards in deck to draw from
    game.deckCount[player - 1] = 10;
    game.deck[player - 1][0] = copper;
    game.deck[player - 1][1] = adventurer;
    game.deck[player - 1][2] = copper;
    game.deck[player - 1][3] = smithy;
    game.deck[player - 1][4] = gold;
    game.deck[player - 1][5] = village;
    game.deck[player - 1][6] = silver;
    game.deck[player - 1][7] = copper;
    game.deck[player - 1][8] = council_room;
    game.deck[player - 1][9] = copper;
    game.supplyCount[curse] = 5;

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test

    cardEffect(sea_hag, 0, 0, 0, &game, handP, 0);

    //nothing should happen to player's hand, so it should be equal to the previous hand count minus one for subtracting the sea hag card
    if(game.handCount[player] == testgame.handCount[player] - 1)
    {
        printf("Test 1 (player's hand count reduced by one) passed.\n");
    }
    else
    {
        printf("Test 1 (player's hand count reduced by one) failed.\n");
    }

    //nothing should happen to player's deck
    if(game.deckCount[player] == testgame.deckCount[player])
    {
        printf("Test 2 (player's deck count not affected) passed.\n");
    }
    else
    {
        printf("Test 2 (player's deck count not affected) failed.\n");
    }

    //opponent discards top card of their deck but gains one back so net loss is 0
    if(game.deckCount[player -1] == testgame.deckCount[player -1])
    {
        printf("Test 3 (opponents's deck count remains the same) passed.\n");
    }
    else
    {
        printf("Test 3 (opponents's deck count remains the same) failed.\n");
    }

    //card most recently discarded should be the card that was previously on top of the deck
    if(game.discard[player - 1][game.discardCount[player - 1] - 1] == testgame.deck[player - 1][testgame.deckCount[player - 1] - 1])
    {
        printf("Test 4 (opponents's top card from deck placed in discard) passed.\n");
    }
    else
    {
        printf("Test 4 (opponents's top card from deck placed in discard) failed.\n");
    }


    //opponent gets a curse card for the top of their deck
    if(game.deck[player - 1][game.deckCount[player -1] - 1] == curse)
    {
        printf("Test 5 (opponent gained a curse card on top of deck) passed.\n");
    }
    else
    {
        printf("Test 5 (opponent gained a curse card on top of deck) failed.\n");
    }


    game.supplyCount[curse] = 0;

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test

    cardEffect(sea_hag, 0, 0, 0, &game, handP, 0);

    //if there are no curse cards the player does not get that card on their deck so deck size is reduced by 1
    if(game.deckCount[player - 1] == testgame.deckCount[player - 1] - 1)
    {
        printf("Test 6 (opponent deck size decrease - no curse cards left) passed.\n");
    }
    else
    {
        printf("Test 6 (opponent deck size decrease - no curse cards left) failed.\n");
    }

    //card would be second card from the top previously
    if(game.deck[player - 1][game.deckCount[player - 1] - 1] == testgame.deck[player - 1][testgame.deckCount[player - 1] - 2])
    {
        printf("Test 7 (opponent did not gain curse card-none left) passed.\n");
    }
    else
    {
        printf("Test 7 (opponent did not gain curse card-none left) failed.\n");
    }

    //player does not gain any actions or coins or buys
    if(game.numActions == testgame.numActions && game.numBuys == testgame.numBuys && game.coins == testgame.coins)
    {
        printf("Test 8 (player did not gain any actions, buys, or coins) passed.\n");
    }
    else
    {
        printf("Test 8 (player did not gain any actions, buys, or coins) failed.\n");
    }

    return 0;
}
