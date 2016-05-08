#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>
#include <string.h>

int main (int argc, char* argv[]) 
{
   int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};

   int r, i;

   srand(time(NULL));


   printf ("\n");
   printf ("\n");
   printf("Testing Adventurer.\n");
   
   int numOfGames = rand() % 100;


   struct gameState G;
   struct gameState freshCopy;
   
   for(i=0; i < numOfGames; i++) {

      printf("Game Number: %i\n", i);

      int numPlayers = 0;
      while(numPlayers == 0 || numPlayers == 1){
         numPlayers = rand() % (MAX_PLAYERS+1);
      }
      printf("Number of Players: %i\n", numPlayers);
      
      initializeGame(numPlayers, k, rand(), &G);
      
      int j;
      for(j = 0; j < numPlayers; j++) {

         int k;
         
         int moneyCount1 = 0;
         for(k=0; k< G.handCount[i]; k++) {
            if (G.hand[i][k] == copper || G.hand[i][k] == silver || G.hand[i][k] == gold) {
               moneyCount1++;
            }
         }

         r = cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

         int moneyCount2 = 0;
         for(k=0; k< G.handCount[i]; k++) {
            if (G.hand[i][k] == copper || G.hand[i][k] == silver || G.hand[i][k] == gold) {
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

      memcpy( &G, &freshCopy, sizeof(struct gameState));

   }
   



   if(r==0) {
      printf ("Test complete.\n\n");   
   }

   return 0;
}
