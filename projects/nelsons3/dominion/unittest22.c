/*
 * unittest2.c
 * unit test for the buyCard function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
   struct gameState bC;
   struct gameState testbC;
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
   int numPlayers = 2;
   int seed = 1000;
   int result;
   // initialize the game state and player cards
   initializeGame(numPlayers, k, seed, &bC);
   printf("---------- Testing Function: buyCard()----------\n"); 
   printf("testpC.numBuys = 0, supplyPos = 1, shoulde return -1 \n"); 
   memcpy(&testbC, &bC, sizeof(struct gameState));
   // testpC.phase = 0 should return -1
   testbC.numBuys = 0;
   result =  buyCard(1 , &testbC);
   printf("expected = -1\n");
   printf("result = %d\n\n", result);
   printf("testpC.numBuys = 1, supplyPos = 1, shoulde return 0 \n"); 
   memcpy(&testbC, &bC, sizeof(struct gameState));
   // testpC.phase = 0 should return -1
   testbC.numBuys = 1;
   result =  buyCard(1 , &testbC);
   printf("expected = 0\n");
   printf("result = %d\n\n", result);
   return 0;
}