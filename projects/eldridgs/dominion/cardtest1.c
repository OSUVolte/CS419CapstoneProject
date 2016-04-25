/*
Susan Eldridge
Spring 2016
CS361
This card should cause the player to draw three cards from their draw pile.
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
    int cardsInHand;
    int otherPlayersHandCount;
    int coinCount;
    int actionCount;

    initializeGame(playerNumber, kCards, rSeed, &game);

    printf("----------TESTING Smithy()----------\n\n");
    //tell it whose turn it is
    game.whoseTurn = player;
    //put 5 cards in hand
    game.handCount[player] = 5;
    //put smithy card in hand
    game.hand[player][handP] = smithy;
    //put cards in deck to draw from
    game.deckCount[player] = 3;
    game.deck[player][0] = copper;
    game.deck[player][1] = adventurer;
    game.deck[player][2] = copper;

    memcpy(&testgame,&game,sizeof(struct gameState));//save state into test

    otherPlayersHandCount = game.handCount[player - 1];
    actionCount = game.numActions;
    coinCount = game.coins;

    //smithy should be played for gaining 3 cards for the current player

    cardEffect(smithy, 0, 0, 0, &game, handP, 0);
    //playCard(handP, 0, 0, 0, &game);

    cardsInHand = testgame.handCount[player];
    //draw 3 cards
    drawCard(player, &testgame);
    drawCard(player, &testgame);
    drawCard(player, &testgame);

    //play smithy card
    discardCard(handP, player, &testgame, 0);

    //hand count should be two more than started with (5+3-1=7)
    if(game.handCount[player] == testgame.handCount[player] && testgame.handCount[player] == cardsInHand + 2)
    {
        printf("Test 1 (right number of cards in hand) passed.\n");
    }
    else
    {
        printf("Test 1 (right number of cards in hand) failed.\n");
    }

    //see if other player's hand changed in size
    if(otherPlayersHandCount == game.handCount[player - 1])
    {
        printf("Test 2 (other player's hand has same number of cards as when starting) passed.\n");
    }
    else
    {
        printf("Test 2 (other player's hand has same number of cards as when starting) failed.\n");
    }

    //number of actions should not have changed
    if(actionCount == game.numActions)
    {
        printf("Test 3 (number of actions unchanged) passed.\n");
    }
    else
    {
        printf("Test 3 (number of actions unchanged) failed.\n");
    }
    //number of coins should remain the same
    if(coinCount == game.coins)
    {
        printf("Test 4 (number of coins unchanged) passed.\n");
    }
    else
    {
        printf("Test 4 (number of coins unchanged) failed.\n");
    }

    //make sure smitihy card was added to played pile
    if(game.playedCards[game.playedCardCount - 1] == smithy)
    {
        printf("Test 5 (smithy was discarded correctly) passed.\n");
    }
    else
    {
        printf("Test 5 (smithy was discarded correctly) failed.\n");
    }

    return 0;
}
