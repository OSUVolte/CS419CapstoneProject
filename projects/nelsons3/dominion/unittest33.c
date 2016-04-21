/*
 * unittest3.c
 * unit test for the endTurn function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
   struct gameState eT;
   struct gameState testeT;
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
   int numPlayers = 2;
   int seed = 1000;
   int result;
   // initialize the game state and player cards
   initializeGame(numPlayers, k, seed, &eT);
   printf("---------- Testing Function: endTurn()----------\n"); 
   memcpy(&testeT, &eT, sizeof(struct gameState));
   // testeT.whoseTurn = 0 
   printf("testeT.whoseTurn = 0 \n"); 
   testeT.whoseTurn = 0;
   result =  endTurn(&testeT);
   printf("expected = 0\n");
   printf("result = %d\n", result);
   printf("testeT.whoseTurn: expected = 1, actual = %d\n\n", testeT.whoseTurn);
   memcpy(&testeT, &eT, sizeof(struct gameState));
   // testeT.whoseTurn = 1
   printf("testeT.whoseTurn = 1 \n"); 
   testeT.whoseTurn = 1;
   result =  endTurn(&testeT);
   printf("expected = 0\n");
   printf("result = %d\n", result);
   printf("testeT.whoseTurn: expected = 0, actual = %d\n\n", testeT.whoseTurn);
   return 0;
}