#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/* Using testUpdateCoins.c template

According to documentation: fullDeckCount()
Description: Returns the count of a specific card in a specific player’s discard deck and hand.
Input: struct gameState state – holds a pointer to a gameState variable, int card, int player
Return: count
---------------------------------------------------------------------------
unittest4: unittest4.c dominion.o rngs.o
    gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

*/

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int successFlag = 0;
    int maxHandCount = 5;
    int player = 0;
    int result;
    struct gameState originalG, testingG;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};


    printf ("TESTING fullDeckCount():\n");
    printf ("Specific card for this test: 'ADVENTURER'. Assume using Player 1 Point of View.\n");

    initializeGame(numPlayer, k, seed, &originalG);
    // -------------------------------------------------------

    printf ("TEST 1: No Adventurer at deck, discard and hand\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    for (i=0;i<maxHandCount;i++) {
      testingG.hand[player][i] = gold;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.discard[player][i] = gold;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.deck[player][i] = gold;
    }

    result = fullDeckCount(player, adventurer, &testingG);
    printf ("Result value: %d. Expected value: 0. \n", result);
    if (result == 0) {
      printf ("Test 1 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 1 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 2: No Adventurer at deck, discard. 1 Adventurer at hand\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    testingG.hand[player][0] = adventurer;
    for (i=1;i<maxHandCount;i++) {
      testingG.hand[player][i] = gold;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.discard[player][i] = gold;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.deck[player][i] = gold;
    }

    result = fullDeckCount(player, adventurer, &testingG);
    printf ("Result value: %d. Expected value: 1. \n", result);
    if (result == 1) {
      printf ("Test 2 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 2 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 3: No Adventurer at deck and discard. 1 Adventurer at player 1 and player 2 hand.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    testingG.hand[player][0] = adventurer;
    testingG.hand[player+1][i] = adventurer;
    for (i=1;i<maxHandCount;i++) {
      testingG.hand[player][i] = gold;
      testingG.hand[player+1][i] = gold;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.discard[player][i] = gold;
      testingG.hand[player+1][i] = gold;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.deck[player][i] = gold;
      testingG.hand[player+1][i] = gold;
    }

    result = fullDeckCount(player, adventurer, &testingG);
    printf ("Result value: %d. Expected value: 1. \n", result);
    if (result == 1) {
      printf ("Test 3 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 3 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 4: 1 Adventurer at Player 1 deck, discard and hand.\n");
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    testingG.hand[player][0] = adventurer;
    testingG.deck[player][0] = adventurer;
    testingG.discardCount[player] = 1;
    testingG.discard[player][0] = adventurer;
    for (i=1;i<maxHandCount;i++) {
      testingG.hand[player][i] = gold;
      testingG.hand[player+1][i] = gold;
    }
    for (i=1;i<maxHandCount;i++) {
      testingG.deck[player][i] = gold;
      testingG.deck[player+1][i] = gold;
    }
    for (i=1;i<maxHandCount;i++) {
      testingG.discard[player][i] = gold;
      testingG.discard[player+1][i] = gold;
    }

    result = fullDeckCount(player, adventurer, &testingG);
    printf ("Result value: %d. Expected value: 3. \n", result);
    if (result == 3) {
      printf ("Test 4 Passed.\n");
      successFlag += 1;
    }
    else {
      printf ("Test 4 Failed.\n");
    }

    // -------------------------------------------------------

    if (successFlag == 4) {
      printf ("All tests passed.\n");
    }
  
  return 0;

}