/*
Susan Eldridge
Spring 2016
CS361
This method should let a player gain a card (as from purchasing) if the card is available
to be gained.
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
    int player = 1;
    int kCards[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};
    int rSeed = 50;
    int returnValue;
    int numberLeft;

    initializeGame(playerNumber, kCards, rSeed, &game);

    printf("----------TESTING gainCard()----------\n\n");

    printf("----------Testing if card is not in game or is no longer available----------\n");

    //sea_hag card is not in game
    //when the card is not in the game it should return -1
    returnValue = gainCard(sea_hag, &game, 0, player);
    if(returnValue == -1)
    {
        printf("Test 1 (card not being used in game) passed.\n");
    }
    else
    {
        printf("Test 1 (card not being used in game) failed.\n");
    }

    //make card no longer available in game by setting it to zero
    game.supplyCount[council_room] = 0;
    returnValue = gainCard(council_room, &game, 0, player);
    if(returnValue == -1)
    {
        printf("Test 2 (card no longer available in game) passed.\n");
    }
    else
    {
        printf("Test 2 (card no longer available in game) failed.\n");
    }

    printf("----------Testing where card goes when it is gained----------\n");

    //toFlag = 0 means gained card goes to discard
    memcpy(&testgame,&game,sizeof(struct gameState)); //save game state

    gainCard(feast, &game, 0, player);

    testgame.discard[player][testgame.discardCount[player]] = feast;
    testgame.discardCount[player]++;

    if(testgame.discard[player][testgame.discardCount[player] -1] == game.discard[player][game.discardCount[player] - 1] && testgame.discardCount[player] == game.discardCount[player])
    {
        printf("Test 3 (toFlag=0) passed.\n");
    }
    else
    {
        printf("Test 3 (toFlag=0) failed.\n");
    }

    //toflag = 1 means card is added to deck
    memcpy(&testgame,&game,sizeof(struct gameState)); //save game state
    gainCard(adventurer, &game, 1, player);

    testgame.deck[player][testgame.deckCount[player]] = adventurer;
    testgame.deckCount[player]++;
    if(testgame.deck[player][testgame.deckCount[player] - 1] == game.deck[player][game.deckCount[player] - 1] && testgame.deckCount[player] == game.deckCount[player])
    {
        printf("Test 4 (toFlag=1) passed.\n");
    }
    else
    {
        printf("Test 4 (toFlag=1) failed.\n");
    }

    //toflag= 2 means card is added to hand
    memcpy(&testgame,&game,sizeof(struct gameState)); //save game state
    gainCard(gardens, &game, 2, player);

    testgame.hand[player][testgame.handCount[player]] = gardens;
    testgame.handCount[player]++;
    if(testgame.hand[player][testgame.handCount[player] - 1] == game.hand[player][testgame.handCount[player] - 1] && testgame.handCount[player] == game.handCount[player])
    {
        printf("Test 5 (toFlag=2) passed.\n");
    }
    else
    {
        printf("Test 5 (toFlag=2) failed.\n");
    }

    printf("----------Testing to make sure supply count is updated----------\n");
    memcpy(&testgame,&game,sizeof(struct gameState)); //save game state
    numberLeft = game.supplyCount[village];

    gainCard(village, &game, 2, player);

    testgame.supplyCount[village]--;

    if(testgame.supplyCount[village] == game.supplyCount[village])
    {
        printf("Test 6 (supply count updated) passed.\n");
    }
    else
    {
        printf("Test 6 (supply count updated) failed.\n");
    }
    return 0;
}
