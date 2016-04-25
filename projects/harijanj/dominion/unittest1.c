#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/* Using testUpdateCoins.c template
According to documentation: scoreFor()
Description: Calculates a specific player’s current score.
Input: 1) struct gameState state – holds a pointer to a gameState variable 
	     2) int player
Return: score

---------------------------------------------------------------------------
unittest1: unittest1.c dominion.o rngs.o
    gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

*/

int main() {
    int i;
    int player=1;
    int score;
    int seed = 1000;
    struct gameState originalG, testingG;
    int maxHandCount = 5;
    int successFlag = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    // -------------------------------------------------------

    printf ("TESTING scoreFor():\n");

    initializeGame(player, k, seed, &originalG);
    // -------------------------------------------------------

    printf ("TEST 1: Test score for all zero.\n");

    // Reset
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    // Zero value
    for (i=0;i<maxHandCount;i++) {
      testingG.hand[player][i] = adventurer;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.discard[player][i] = adventurer;
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.deck[player][i] = adventurer;
    }

/*
    // Score from hand
  	for (i = 0; i < maxHandCount; i++)
    {
      if (testingG.hand[player][i] == curse) { score = score - 1; };
      if (testingG.hand[player][i] == estate) { score = score + 1; };
      if (testingG.hand[player][i] == duchy) { score = score + 3; };
      if (testingG.hand[player][i] == province) { score = score + 6; };
      if (testingG.hand[player][i] == great_hall) { score = score + 1; };
      if (testingG.hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, &testingG) / 10 ); };
    }
*/
    testingG.handCount[player] = maxHandCount;
    testingG.discardCount[player] = maxHandCount;
    testingG.deckCount[player] = maxHandCount;
    score = scoreFor(player, &testingG);

    printf("Score value: %d. Expected value: 0. \n", score);
    if (score == 0) {
      printf ("Test 1 Passed.\n");
      successFlag += 1;
    } 
    else {
      printf ("Test 1 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 2: Test score combining positive & negative.\n");
    
    // Reset
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    // Combining positive and negative value
    testingG.hand[player][0] = province; // +6
    testingG.hand[player][1] = curse; //-1
    testingG.hand[player][2] = estate; //+1
    testingG.hand[player][3] = estate; //+1
    testingG.hand[player][4] = estate; //+1

    testingG.discard[player][0] = adventurer;
    testingG.discard[player][1] = curse; //-1
    testingG.discard[player][2] = estate; //+1
    testingG.discard[player][3] = province; //+6
    testingG.discard[player][4] = curse; //-1

    testingG.deck[player][0] = adventurer;
    testingG.deck[player][1] = adventurer;
    testingG.deck[player][2] = curse; //-1
    testingG.deck[player][3] = curse; //-1
    testingG.deck[player][4] = curse; //-1

    testingG.handCount[player] = maxHandCount;
    testingG.discardCount[player] = maxHandCount;
    testingG.deckCount[player] = maxHandCount;
    score = scoreFor(player, &testingG);

    printf("Score value: %d. Expected value: 10. \n", score);
    if (score == 10) {
      printf ("Test 2 Passed.\n");
      successFlag += 1;
    } 
    else {
      printf ("Test 2 Failed.\n");
    }

    // -------------------------------------------------------

    printf ("TEST 3: Test score combining positive only.\n");
    
    // Reset
    memcpy(&testingG, &originalG, sizeof(struct gameState));

    // Positive value only
    for (i=0;i<maxHandCount;i++) {
      testingG.hand[player][i] = estate; //5
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.discard[player][i] = province; //30
    }
    for (i=0;i<maxHandCount;i++) {
      testingG.deck[player][i] = estate; //5
    }

    testingG.handCount[player] = maxHandCount;
    testingG.discardCount[player] = maxHandCount;
    testingG.deckCount[player] = maxHandCount;
    score = scoreFor(player, &testingG);

    printf("Score value: %d. Expected value: 40. \n", score);
    if (score == 40) {
      printf ("Test 3 Passed.\n");
      successFlag += 1;
    } 
    else {
      printf ("Test 3 Failed.\n");
    }
  if (successFlag == 3) {
      printf ("All tests passed!\n");
  }
  return 0;

}