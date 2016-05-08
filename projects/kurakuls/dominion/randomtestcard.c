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
   printf("Testing Smithy.\n");
   
   int numOfGames = rand() % 100;


   struct gameState G;
   struct gameState freshCopy;
   
   for(i=0; i < numOfGames; i++) {

      printf("Game Number: %i\n", i+1);

      int numPlayers = 0;
      while(numPlayers == 0 || numPlayers == 1){
         numPlayers = rand() % (MAX_PLAYERS+1);
      }
      printf("Number of Players: %i\n", numPlayers);
      
      initializeGame(numPlayers, k, rand(), &G);
      
      int j;
      for(j = 0; j < numPlayers; j++) {

         int handCount = G.handCount[j];

         r = cardEffect(smithy, 0, 0, 0, &G, 0, 0);

         if (G.handCount[j] != handCount+2) {

            if (G.handCount[j] < handCount+2) {            
               printf("Smithy Changes the handCount by less than 2.\n");
            }
            else {
               printf("Smithy Changes the handCount by more than 2.\n");
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

