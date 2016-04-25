#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/* Using testUpdateCoins.c template

According to documentation: isGameOver()
Description: Checks the number of provinces or if three supply piles are empty to determine if
the game is over.
Input: struct gameState state – holds a pointer to a gameState variable
Return: Returns 1 if the game is over Returns 0 on if the game i
---------------------------------------------------------------------------
unittest3: unittest3.c dominion.o rngs.o
    gcc -o unittest3 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

*/

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int victorySupply = 8; //Supplies for 2 players
    int goldSupply = 30;
    int curseSupply = 10;
    int successFlag = 0;
    //int maxHandCount = 5;
    int result;
    struct gameState originalG, testingG;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};


    printf ("TESTING isGameOver():\n");

    initializeGame(numPlayer, k, seed, &originalG);
    // -------------------------------------------------------

    printf ("TEST 1: Test if province is negative.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i = 0; i < victorySupply; i++) {
        // province (3)
        testingG.supplyCount[3] -= 2;
    }

    result = isGameOver(&testingG);
    printf ("# of province card in supply: %d. Dominion need condition state->supplyCount[province] =< 0!\n", testingG.supplyCount[3]);
    printf ("Result value: %d. Expected value: 0 (Game Not Over). \n", result);
    if (testingG.coins == 0) {
      printf ("Test 1 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 1 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 2: Test if dutchy empty.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i = 0; i < victorySupply; i++) {
        // duchy (2)
        testingG.supplyCount[2] -= 1;
    }

    result = isGameOver(&testingG);

    printf ("Result value: %d. Expected value: 0 (Game Not Over). \n", result);
    if (result == 0) {
      printf ("Test 2 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 2 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 3: Test if estate empty.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i = 0; i < victorySupply; i++) {
        // estate (1)
        testingG.supplyCount[1] -= 1;
    }

    result = isGameOver(&testingG);

    printf ("Result value: %d. Expected value: 0 (Game Not Over). \n", result);
    if (result == 0) {
      printf ("Test 3 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 3 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 4: Test when 4 supplies zero\n");
    printf ("Testing with duchy, estate, curse and gold\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i = 0; i < victorySupply; i++) {
        // estate (1)
        testingG.supplyCount[1] -= 1;
    }
    for (i = 0; i < victorySupply; i++) {
        // duchy (2)
        testingG.supplyCount[2] -= 1;
    }
    for (i = 0; i < curseSupply; i++) {
        // curse (0)
        testingG.supplyCount[0] -= 1;
    }
    for (i = 0; i < goldSupply; i++) {
        // gold (6)
        testingG.supplyCount[6] -= 1;
    }

    result = isGameOver(&testingG);

    printf ("Result value: %d. Expected value: 1 (Game Is Over). \n", result);
    if (result == 1) {
      printf ("Test 4 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 4 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 5: Test when 2 supplies zero but 1 with province.\n");
    printf ("Testing with provice and gold\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i = 0; i < victorySupply; i++) {
        // province (3)
        testingG.supplyCount[3] -= 1;
    }
    for (i = 0; i < goldSupply; i++) {
        // gold (6)
        testingG.supplyCount[6] -= 1;
    }

    result = isGameOver(&testingG);

    printf ("Result value: %d. Expected value: 1 (Game Is Over). \n", result);
    if (result == 1) {
      printf ("Test 5 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 5 Failed.\n");
    }

    // -------------------------------------------------------

    if (successFlag == 4) {
      printf ("All tests passed, except test # 1 since it is intentional.\n");
    }
  
  return 0;

}