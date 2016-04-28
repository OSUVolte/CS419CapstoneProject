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
   printf("Testing Adventurer.\n");

   for(i = 0; i < 4; i++) {

      int j;
      
      int moneyCount1 = 0;
      for(j=0; j< G.handCount[i]; j++) {
         if (G.hand[i][j] == copper || G.hand[i][j] == silver || G.hand[i][j] == gold){
            moneyCount1++;

         }
      }

      r = cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

      int moneyCount2 = 0;
      for(j=0; j< G.handCount[i]; j++) {
         if (G.hand[i][j] == copper || G.hand[i][j] == silver || G.hand[i][j] == gold){
            moneyCount2++;
         }
      }

      if (moneyCount1+2 != moneyCount2) {

         if (moneyCount1 + 2 > moneyCount2) {            
            printf("Adventurer adds less than two coins.\n");
         }
         else {
            printf("Adventurer adds more than two coins.\n");
         }

      }

      endTurn(&G);

   }

   if(r==0) {
      printf ("Test complete.\n\n");   
   }

   return 0;
}
