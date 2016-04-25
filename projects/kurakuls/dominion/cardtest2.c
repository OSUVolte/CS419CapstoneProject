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
   printf("Testing Gardens.\n");

   for(i = 0; i < 4; i++) {


      r = cardEffect(gardens, 0, 0, 0, &G, 0, 0);
      if(r != -1) {
         printf("Something is wrong with Gardens\n");   
      }

   }

   printf ("Test complete.\n\n");   

   return 0;
}