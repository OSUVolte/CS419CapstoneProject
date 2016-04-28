#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main (int argc, char* argv[]) 
{
   int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};

   int r, i;
   struct gameState G;

   initializeGame(4, k, 1, &G);

   printf ("\n");
   printf ("\n");
   printf("Testing great_hall.\n");

   for(i = 0; i < 4; i++) {
      //store values
      int handCount = G.handCount[i];
      int numActions = G.numActions + 1;

      r = cardEffect(great_hall, 0, 0, 0, &G, 0, 0);

      if (G.handCount[i] != handCount) {
         printf("Great Hall Changes Hand Count");
      }
      
      if(G.numActions != numActions) {
         printf("Great Hall does not increase number of Actions.");
      }

   }

   if(r==0) {
      printf ("Test complete.\n\n");   
   }

   return 0;
}