#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void checkSupplyCount(int numPlayers, struct gameState *state) {


   switch ( numPlayers ) {
      case 2:
         assert(supplyCount(curse, state)  == 10);
         break;
      case 3:
        assert(supplyCount(curse, state) == 20);
        break;
      default:
        assert(supplyCount(curse, state) == 30);
        break;
   }

   if ( numPlayers <= 2 ) {
      assert(supplyCount(estate, state) == 8);
      assert(supplyCount(duchy, state) == 8);
      assert(supplyCount(province, state) == 8);
   }
   else {
      assert(supplyCount(estate, state) == 12);
      assert(supplyCount(duchy, state) == 12);
      assert(supplyCount(province, state) == 12);   
   }

   assert(supplyCount(copper, state) == (60 - (7 * numPlayers)));
   assert(supplyCount(silver, state) == 40);
   assert(supplyCount(gold, state) == 30);
   
}

int main (int argc, char* argv[]) 
{

   int numPlayers;
   int r;
	srand(time(NULL));

   int k[10] = {adventurer, council_room, feast, gardens, mine,
     remodel, smithy, village, baron, great_hall};

   printf ("\n");
   printf ("\n");
   printf ("Testing supplyCount and Initializing Game.\n");

   numPlayers = 2;
   struct gameState G2;
   r = initializeGame(2, k, 1, &G2);
   checkSupplyCount(numPlayers, &G2);

   numPlayers = 3;
   struct gameState G3;
   r = initializeGame(3, k, 1, &G3);    
   checkSupplyCount(numPlayers, &G3);

   numPlayers = 4;
   struct gameState G4;
   r = initializeGame(4, k, 1, &G4);
   checkSupplyCount(numPlayers, &G4);

   if (r==0) {      
      printf ("Test complete.\n\n");
   }
   else {
      printf ("Error in initializing game.\n\n");
   }

  	return 0;

}




