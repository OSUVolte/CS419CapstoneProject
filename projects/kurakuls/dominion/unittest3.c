
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char* argv[]) 
{
	struct gameState G;
	int i;
   int player;
   int r;
	srand(time(NULL));


   int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};

   printf ("\n");
   printf ("\n");
   printf ("Testing WhoseTurn.\n");
 
   r = initializeGame(4, k, 1, &G);


	for(i = 0; i < 100; i ++)
	{
      player = rand()%4;
      G.whoseTurn = player;
      assert(whoseTurn(&G) == player);
	}

   if(r==0) {
      printf ("Test complete.\n\n");
   }
   else {
      printf ("Error initializing game.\n");
   }

  	return 0;

}