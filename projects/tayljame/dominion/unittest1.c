/************
Author:James Taylor
Date: 4/24/16

Unit test 1 for testing isGameOver().
    Tests for correct detection of gameover =true when province cards stack is 0
        passes if true when province stack = 0
        fails if false when province stack = 0
        passes if false when province stack != 0
        fails if true when province stack != 0

    Tests for correct detection of gameover =true when three supply piles are at 0
        passes if true when 3 supply piles are 0
        fails if false when 3 supply piles are 0
        passes if false when there are not 3 supply piles at 0
        fails if true when there are not 3 supply piles at 0

*************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



//Initialize new game

//params needed for initializeGame()

void unitTest1()
{


    int numPlayer = 2;
    int seed = 1000;

    //create gameState struc, and available cards(copied from playdom.c)
    struct gameState G;
    struct gameState GG;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(numPlayer, k, seed, &G);
    initializeGame(numPlayer, k, seed, &GG);

            //printf("%d", G.supplyCount[province]); //test that game state populated province to correct starting of 8.
    int test = 0;


    //start test statements using G to test province conditions
    printf("\n********************************\n");
    printf("\nUnitTest1 - testing isGameOver()\n");
    printf("\n********************************\n");
    test = isGameOver(&G);
        printf("NEW GAME STATE: Province card default to 8:\n");
        printf("Game is over when province cards = 0\n\n");
    //printf("%d", G.supplyCount[province]); //starting gamestate should have province cards set to 0.
    if(test == 0)
        printf("PASS: Game started with 8 province cards. Game tested as not over.\n");
    else
        printf("FAIL: Game started with 8 province cards. Game tested as over.\n");

    G.supplyCount[province] = 1;
    test = isGameOver(&G);

    if(test == 0)
        printf("PASS: Game state changed to province cards = 1. Game tested as not over.\n");
    else
        printf("FAIL: Game state changed to province cards = 1. Game tested as over.\n");

    G.supplyCount[province] = 0;
    test = isGameOver(&G);

    if(test == 1)
        printf("PASS: Game state changed to province cards = 0. Game tested as over.\n");
    else
        printf("FAIL: Game state changed to province cards = 0. Game tested as not over.\n");

    //printf("%d\n%d\n%d\n", G.supplyCount[copper], G.supplyCount[silver], G.supplyCount[gold]);


    //start test statements using GG to test for 3 supply piles being at 0

    printf("\nNEW GAME STATE: 0 supply cards should be at 0.\n");
    printf("Game is over when 3 supply cards = 0\n\n");
    test = isGameOver(&GG);

    if(test == 0)
        printf("\nPASS: New game state does not result in game over. Game tested as not over.\n");
    else
        printf("FAIL: New game state resulted in game over. Game tested as over by default.\n");

    GG.supplyCount[adventurer] = 0;
    test = isGameOver(&GG);

    if(test == 0)
        printf("PASS: One supply card changed to 0. Game tested as not over.\n");
    else
        printf("FAIL: One supply card changed to 0. Game tested as over.\n");

    GG.supplyCount[gardens] = 0;
    test = isGameOver(&GG);

    if(test == 0)
        printf("PASS: Two supply cards changed to 0. Game tested as not over.\n");
    else
        printf("FAIL: Two supply cards changed to 0. Game test as over.\n");

    GG.supplyCount[embargo] = 0;
    test = isGameOver(&GG);

    if(test == 1)
        printf("PASS: Three supply cards changed to 0. Game tested as over.\n");
    else
        printf("FAIL: Three supply cards changed to 0. Game tested as not over.\n");

    GG.supplyCount[village] = 0;
    test = isGameOver(&GG);

    if(test == 1)
        printf("PASS: 3 or more supply cards change to 0. Game tested as over.\n");
    else
        printf("FAIL: 3 or more supply cards changed to 0. Game tested as not over.\n");


}

int main()
{
    unitTest1();
    return 0;

}
