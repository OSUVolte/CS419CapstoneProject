#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/* Using testUpdateCoins.c template

According to documentation: updateCoins()
Description: Returns the count of a specific card in a specific player’s discard deck and hand.
Input: struct gameState state – holds a pointer to a gameState variable
       int player
       int bonus
Return: 0 on success
---------------------------------------------------------------------------
unittest2: unittest2.c dominion.o rngs.o
    gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

*/

int main() {
    int i;
    int seed = 1000;
    //int numPlayer = 2;
    //int maxBonus = 10;
    int player = 1;
    int bonus = 0;
    int successFlag = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    struct gameState originalG, testingG;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    
    //int coppers[MAX_HAND];
    //int silvers[MAX_HAND];
    //int golds[MAX_HAND];
    /*
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
    */ 

    printf ("TESTING scoreFor():\n");

    initializeGame(player, k, seed, &originalG);
    // -------------------------------------------------------

    printf ("TEST 1: Test if no coins.\n");
    testingG.coins = 0;
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i = 0; i < maxHandCount; i ++) {
      testingG.hand[player][i] = village;
    }

    testingG.handCount[player] = maxHandCount;
    updateCoins(player, &testingG, bonus);
    printf ("Coin value: %d. Expected value: 0. \n", testingG.coins);
    if (testingG.coins == 0) {
      printf ("Test 1 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 1 Failed.\n");
    }

    // -------------------------------------------------------

    // Assuming if "all coopers" works, then "all silvers" and "all golds" too
    printf ("TEST 2: Test all coopers.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i = 0; i < maxHandCount; i ++) {
      testingG.hand[player][i] = copper;
    }

    testingG.handCount[player] = maxHandCount;
    updateCoins(player, &testingG, bonus);
    printf ("Coin value: %d. Expected value: 5. \n", testingG.coins);
    if (testingG.coins == 5) {
      printf ("Test 2 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 2 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 3: Test mix between coopers,silvers,and golds.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    testingG.hand[player][0] = copper; // 1
    testingG.hand[player][1] = silver; // 2
    testingG.hand[player][2] = gold;   // 3 
    testingG.hand[player][3] = gold;   // 3
    testingG.hand[player][4] = copper; // 1

    testingG.handCount[player] = maxHandCount;
    updateCoins(player, &testingG, bonus);
    printf ("Coin value: %d. Expected value: 10. \n", testingG.coins);
    if (testingG.coins == 10) {
      printf ("Test 3 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 3 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 4: Test with bonus.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));
    bonus = 4;

    testingG.hand[player][0] = copper;  // 1
    testingG.hand[player][1] = silver;  // 2
    testingG.hand[player][2] = gold;    // 3 
    testingG.hand[player][3] = cutpurse;// 2 (Bonus)
    testingG.hand[player][4] = cutpurse;// 2 (Bonus)

    testingG.handCount[player] = maxHandCount;
    updateCoins(player, &testingG, bonus);
    printf ("Coin value: %d. Expected value: 10. \n", testingG.coins);
    if (testingG.coins == 10) {
      printf ("Test 4 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 4 Failed.\n");
    }

    if (successFlag == 4) {
      printf ("All tests passed!\n");
    }
  
  return 0;

}