/*
Susan Eldridge
Spring 2016
CS361
This card should cause the player to draw cards until they get to two treasure cards.
These two treasure cards are added to the players hand and all the other cards are discarded.
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

    printf("----------TESTING Adventurer()----------\n\n");
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

    cardEffect(adventurer, 0, 0, 0, &game, handP, 0);

    //hand should have increased by 1 card (add 2, discard adventurer)
    if(game.handCount[player] != testgame.handCount[player] + 1)
    {
        printf("Test 1 (correct number of cards gained) passed.\n");
    }
    else
    {
        printf("Test 1 (correct number of cards gained) failed.\n");
    }

    //other player's hand should be unaffected
    if(game.handCount[0] == testgame.handCount[0])
    {
        printf("Test 2 (opponent's hand not affected) passed.\n");
    }
    else
    {
        printf("Test 2 (opponent's hand not affected) failed.\n");
    }

    //number of actions should be unchanged
    if(game.numActions == testgame.numActions)
    {
        printf("Test 3 (actions not affected) passed.\n");
    }
    else
    {
        printf("Test 3 (actions not affected) failed.\n");
    }

    //number of coins should be unchanged
    if(game.coins == testgame.coins)
    {
        printf("Test 4 (coins not affected) passed.\n");
    }
    else
    {
        printf("Test 4 (coins not affected) failed.\n");
    }

    //number of buys should be unchanged
    if(game.numBuys == testgame.numBuys)
    {
        printf("Test 5 (number of buys not affected) passed.\n");
    }
    else
    {
        printf("Test 5 (number of buys not affected) failed.\n");
    }

    //hand should have gained two coppers
    if(game.hand[player][game.handCount[player] - 2] == copper && game.hand[player][game.handCount[player] - 1])
    {
        printf("Test 6 (2 treasure cards added to hand) passed.\n");
    }
    else
    {
        printf("Test 6 (2 treasure cards added to hand) failed.\n");
    }

    //should have discarded a council_room
    if(game.discard[player][game.discardCount[player] - 1] == council_room)
    {
        printf("Test 7 (correct card discarded) passed.\n");
    }
    else
    {
        printf("Test 7 (correct card discarded) failed.\n");
    }

    //adventurer card should go to played pile
    if(game.playedCards[game.playedCardCount - 1] == adventurer)
    {
        printf("Test 8 (correct card added to played pile) passed.\n");
    }
    else
    {
        printf("Test 8 (correct card added to played pile) failed.\n");
    }
    return 0;
}
