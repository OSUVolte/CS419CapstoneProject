

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1


int main () {
   int r;

   int i;
   int j;
   int differentDeck = 0;

   int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

   struct gameState G;
   struct gameState beforeShuffle;

   r = initializeGame(4, k, 1, &G);

   printf ("\n");
   printf ("\n");
   printf ("Testing shuffle.\n");
	
   memcpy( &beforeShuffle, &G, sizeof(struct gameState));

   for ( i=0; i < 4; i++) {

      shuffle(i, &G);

      for(j=0; j < G.deckCount[i]; j++){

         if(beforeShuffle.deck[i][j] != G.deck[i][j]) {
            differentDeck = 1;
         }

      }

      assert(differentDeck == 1);

   }

   if (differentDeck == 1 && r==0) {
      printf ("Test complete.\n\n");
   }
   else {
      printf ("Error in shuffling.\n");
   }

   return 0;

}