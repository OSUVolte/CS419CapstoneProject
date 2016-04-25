
/************
Author:James Taylor
Date: 4/24/16

Unit test 2 for supplyCount()
    test for correct detection of current supply counts for cards after game initialization.
        copper, silver, gold, estate, duchy, province, adventurer, smithy, mine.

*************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void unitTest2()
{
    int numPlayer = 2;
    int seed = 1000;

    //holds result from supplyCount()
    int test = 0;

    //create gameState struc, and available cards(copied from playdom.c)
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(numPlayer, k, seed, &G);

    printf("\n********************************\n");
    printf("\nUnitTest2 - testing supplyCount()\n");
    printf("\n********************************\n");

    printf("NEW GAME STATE:Testing treasure cards:\n");

    test = supplyCount(copper, &G);
    if(test == 46)
            printf("PASS: copper = 46.\n");
    else
        printf("FAIL: copper = %d\n", test);

    test = supplyCount(silver, &G);
    if(test == 40)
        printf("PASS: silver = %d.\n", test);
    else
        printf("FAIL: silver = %d.\n", test);

    test = supplyCount(gold, &G);
    if(test == 30)
            printf("PASS: gold = %d.\n", test);
    else
            printf("PASS: gold = %d.\n", test);

        printf("\nNEW GAME STATE:Testing victory cards:\n");

    test = supplyCount(province, &G);
    if(test == 8)
        printf("PASS: Province = 8.\n");
    else
        printf("FAIL: Province = %d\n", test);

    test = supplyCount(duchy, &G);
    if(test == 8)
        printf("PASS: Duchy = 8.\n");
    else
        printf("FAIL: Duchy = %d\n", test);

    test = supplyCount(estate, &G);
    if(test == 8)
        printf("PASS: Estate = 8.\n");
    else
        printf("FAIL: Estate = %d\n", test);

    printf("\nNEW GAME STATE: Testing selection of supply cards:\n");

    test = supplyCount(adventurer, &G);
    if(test == 10)
        printf("PASS: Adventure = %d\n", test);
    else
        printf("FAIL: Adventure = %d\n", test);

    test = supplyCount(smithy, &G);
    if(test == 10)
        printf("PASS: smithy = %d\n", test);
    else
        printf("FAIL: smithy = %d\n", test);

    test = supplyCount(mine, &G);
    if(test == 10)
        printf("PASS: mine = %d\n", test);
    else
        printf("FAIL: mine = %d\n", test);

    printf("\nCHANGED GAME STATE: Testing changing counts to 1 for gold, duchy, mine cards\n");

    G.supplyCount[gold] = 1;
    G.supplyCount[duchy] = 1;
    G.supplyCount[mine] = 1;

    test = supplyCount(gold, &G);
    if(test == 1)
        printf("PASS: gold = %d\n", test);
    else
        printf("FAIL: gold = %d\n", test);

    test = supplyCount(duchy, &G);
    if(test == 1)
        printf("PASS: duchy = %d\n", test);
    else
        printf("FAIL: duchy = %d\n", test);

    test = supplyCount(mine, &G);
    if(test == 1)
        printf("PASS: mine = %d\n", test);
    else
        printf("FAIL: mine = %d\n", test);
}

int main()
{
    unitTest2();
    return 0;

}
