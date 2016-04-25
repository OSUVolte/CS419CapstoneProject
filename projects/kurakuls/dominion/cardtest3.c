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
   printf("Testing Smithy.\n");

   for(i = 0; i < 4; i++) {

      int handCount = G.handCount[i];

      r = cardEffect(smithy, 0, 0, 0, &G, 0, 0);

      if (G.handCount[i] != handCount+2) {

         if (G.handCount[i] < handCount+2) {            
            printf("Smithy Changes the handCount by less than 2.\n");
         }
         else {
            printf("Smithy Changes the handCount by more than 2.\n");
         }

      }

      endTurn(&G);

   }

   if(r==0) {
      printf ("Test complete.\n\n");   
   }

   return 0;
}
