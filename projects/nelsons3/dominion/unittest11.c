/*
 * unittest1.c
 * unit test for the playCard function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
   struct gameState pC;
   struct gameState testpC;
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
   int numPlayers = 2;
   int seed = 1000;
   int currentPlayer = 0;
   int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0;
   int result;
   int actionBefore, actionAfter;
   // initialize the game state and player cards
   initializeGame(numPlayers, k, seed, &pC);
   printf("---------- Testing Function: playCard()----------\n"); 
   printf("testpC.phase = 0 shoulde return -1 \n"); 
   memcpy(&testpC, &pC, sizeof(struct gameState));
   // testpC.phase = 0 should return -1
   testpC.phase = 0;
   result =  playCard(handpos, choice1, choice2, choice3, &testpC);
   printf("expected = -1\n", result);
   printf("result = %d\n\n", result);
   printf("testpC.numActions = 0 shoulde return -1 \n"); 
   memcpy(&testpC, &pC, sizeof(struct gameState));
   // testpC.numActions = 0 should return -1
   testpC.numActions = 0;
   result =  playCard(handpos, choice1, choice2, choice3, &testpC);
   printf("expected = -1\n", result);
   printf("result = %d\n\n", result);
   
   return 0;
}