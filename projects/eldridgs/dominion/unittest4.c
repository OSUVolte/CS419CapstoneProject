/*
Susan Eldridge
Spring 2016
CS361
This method looks for the stipulations for the game to be over.
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
    struct gameState game;
    int playerNumber = 2;
    int kCards[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};
    int rSeed = 50;
    int isItOver;

    initializeGame(playerNumber, kCards, rSeed, &game);

    printf("----------TESTING isGameOver()----------\n\n");

    //game ends if province supply is empty
    game.supplyCount[province] = 0;
    isItOver = isGameOver(&game);

    if(isItOver == 1)
    {
        printf("Test 1 (province cards empty) passed.\n");
    }
    else
    {
        printf("Test 1 (province cards empty) failed.\n");
    }

    //if any 3 supply piles are empty game is over
    game.supplyCount[province] = 5;
    game.supplyCount[adventurer] = 0;
    game.supplyCount[copper] = 0;
    game.supplyCount[village] = 0;

    isItOver = isGameOver(&game);
    if(isItOver == 1)
    {
        printf("Test 2 (3 supply decks empty) passed.\n");
    }
    else
    {
        printf("Test 2 (3 supply decks empty) failed.\n");
    }

    //if these arent true the game is not over
    game.supplyCount[adventurer] = 1;
    isItOver = isGameOver(&game);
    if(isItOver == 0)
    {
        printf("Test 3 (game not over) passed.\n");
    }
    else
    {
        printf("Test 3 (game not over) failed.\n");
    }
    return 0;
}
