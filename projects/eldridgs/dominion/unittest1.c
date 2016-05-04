/*
Susan Eldridge
Spring 2016
CS361
This method should tally the copper, silver, gold, and bonus together.
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
    //initialize game
    struct gameState game, testgame;
    int playerNumber = 2;
    int kCards[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};
    int rSeed = 50;
    int coinTotal, testCoinTotal, i;

    printf("----------TESTING updateCoins()----------\n");

    initializeGame(playerNumber, kCards, rSeed, &game);

    int player = 0;
    int bonus = 3;
    game.handCount[player] = 5; //player has 5 cards for test
    //fill hand, copper is 4, silver is 5, gold is 6
    game.hand[player][0] = copper;
    game.hand[player][1] = copper;
    game.hand[player][2] = gold;
    game.hand[player][3] = council_room;
    game.hand[player][4] = silver;

    updateCoins(player, &game, bonus);
//expected value is 10 because 2 coppers, 1 silver and 3 bonus = 10
    if(game.coins == 10)
    {
        printf("Simple test Passed.\n");
    }
    else
    {
        printf("Simple test Failed.\n");
    }

    memcpy(&testgame,&game,sizeof(struct gameState)); //save game state

    //run method on game state
    updateCoins(player, &game, bonus);
    coinTotal = game.coins;

    //do what I think is supposed to be happening in the method
    testCoinTotal = 0;
    for(i = 0; i < testgame.handCount[player]; i++)
    {
       if(testgame.hand[player][i] == copper)
       {
           testCoinTotal += 1;
       }
       if(testgame.hand[player][i] == silver)
       {
           testCoinTotal += 2;
       }
       if(testgame.hand[player][i] == gold)
       {
           testCoinTotal += 3;
       }
    }
    testCoinTotal += bonus;
    testgame.coins = testCoinTotal;

    if(memcmp(&testgame, &game, sizeof(struct gameState)) == 0)
    {
        printf("Complex test passed.\n");
    }
    else
    {
        printf("Complex test failed.\n");
    }

    return 0;
}
