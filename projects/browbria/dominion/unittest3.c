#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TESTFUNCTION "getCost"

/* REMINDER TO DO THIS - Need to understand the particulars of Makefile better
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 */

int main(){

  int i;                                // counter
  int pos;                              // position
  int result;
  int numPlayers = 2;
  int player1 = 0;
  int player2 = 1;
  struct gameState origGS, testGS;      // original and test gameState

  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room}; //grab same cards from cardtest1.c
  int coinAmount = 0;                       // update coins sets coins to 0

  printf("=====   TESTING FUNCTION: %s   =====\n\n", TESTFUNCTION);



    // Set hand basics for the game
    pos = -1;
    player1 = 0;
    player2 = 1;
 /*
  * Need to check if a 'land' pile is empty, or if 3 piles total are empty.
  */

    // confirm one land pile empty
    initializeGame(numPlayers, k, 1000, &origGS);
    memcpy(&testGS, &origGS, sizeof(struct gameState));

    printf("\nTest 1: get cost of cards \n");

result=getCost(curse);
if(result == 0)
printf("SUCCESS. Curse, %d, returns proper value of %d.\n", 0, result);
else
printf("FAILED.  Curse, %d, returns improper value of %d.\n", 0, result);

result=getCost(estate);
if(result == 2)
printf("SUCCESS. estate, %d, returns proper value of %d.\n", 2, result);
else
printf("FAILED.  estate, %d, returns improper value of %d.\n", 2, result);

result=getCost(duchy);
if(result == 5)
printf("SUCCESS. duchy, %d, returns proper value of %d.\n", 5, result);
else
printf("FAILED.  duchy, %d, returns improper value of %d.\n", 5, result);

result=getCost(province);
if(result == 8)
printf("SUCCESS. province, %d, returns proper value of %d.\n", 8, result);
else
printf("FAILED.  province, %d, returns improper value of %d.\n", 8, result);

result=getCost(copper);
if(result == 0)
printf("SUCCESS. copper, %d, returns proper value of %d.\n", 0, result);
else
printf("FAILED.  copper, %d, returns improper value of %d.\n", 0, result);

result=getCost(silver);
if(result == 3)
printf("SUCCESS. silver, %d, returns proper value of %d.\n", 3, result);
else
printf("FAILED.  silver, %d, returns improper value of %d.\n", 3, result);

result=getCost(gold);
if(result == 6)
printf("SUCCESS. gold, %d, returns proper value of %d.\n", 6, result);
else
printf("FAILED.  gold, %d, returns improper value of %d.\n", 6, result);

result=getCost(adventurer);
if(result == 6)
printf("SUCCESS. adventurer, %d, returns proper value of %d.\n", 6, result);
else
printf("FAILED.  adventurer, %d, returns improper value of %d.\n", 6, result);

result=getCost(council_room);
if(result == 5)
printf("SUCCESS. council_room, %d, returns proper value of %d.\n", 5, result);
else
printf("FAILED.  council_room, %d, returns improper value of %d.\n", 5, result);

result=getCost(feast);
if(result == 4)
printf("SUCCESS. feast, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  feast, %d, returns improper value of %d.\n", 4, result);

result=getCost(gardens);
if(result == 4)
printf("SUCCESS. gardens, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  gardens, %d, returns improper value of %d.\n", 4, result);

result=getCost(mine);
if(result == 5)
printf("SUCCESS. mine, %d, returns proper value of %d.\n", 5, result);
else
printf("FAILED.  mine, %d, returns improper value of %d.\n", 5, result);

result=getCost(remodel);
if(result == 4)
printf("SUCCESS. remodel, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  remodel, %d, returns improper value of %d.\n", 4, result);

result=getCost(smithy);
if(result == 4)
printf("SUCCESS. smithy, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  smithy, %d, returns improper value of %d.\n", 4, result);

result=getCost(village);
if(result == 3)
printf("SUCCESS. village, %d, returns proper value of %d.\n", 3, result);
else
printf("FAILED.  village, %d, returns improper value of %d.\n", 3, result);

result=getCost(baron);
if(result == 4)
printf("SUCCESS. baron, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  baron, %d, returns improper value of %d.\n", 4, result);

result=getCost(great_hall);
if(result == 3)
printf("SUCCESS. great_hall, %d, returns proper value of %d.\n", 3, result);
else
printf("FAILED.  great_hall, %d, returns improper value of %d.\n", 3, result);

result=getCost(minion);
if(result == 5)
printf("SUCCESS. minion, %d, returns proper value of %d.\n", 5, result);
else
printf("FAILED.  minion, %d, returns improper value of %d.\n", 5, result);

result=getCost(steward);
if(result == 3)
printf("SUCCESS. steward, %d, returns proper value of %d.\n", 3, result);
else
printf("FAILED.  steward, %d, returns improper value of %d.\n", 3, result);

result=getCost(tribute);
if(result == 5)
printf("SUCCESS. tribute, %d, returns proper value of %d.\n", 5, result);
else
printf("FAILED.  tribute, %d, returns improper value of %d.\n", 5, result);

result=getCost(ambassador);
if(result == 3)
printf("SUCCESS. ambassador, %d, returns proper value of %d.\n", 3, result);
else
printf("FAILED.  ambassador, %d, returns improper value of %d.\n", 3, result);

result=getCost(cutpurse);
if(result == 4)
printf("SUCCESS. cutpurse, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  cutpurse, %d, returns improper value of %d.\n", 4, result);

result=getCost(embargo);
if(result == 2)
printf("SUCCESS. embargo, %d, returns proper value of %d.\n", 2, result);
else
printf("FAILED.  embargo, %d, returns improper value of %d.\n", 2, result);

result=getCost(outpost);
if(result == 5)
printf("SUCCESS. outpost, %d, returns proper value of %d.\n", 5, result);
else
printf("FAILED.  outpost, %d, returns improper value of %d.\n", 5, result);

result=getCost(salvager);
if(result == 4)
printf("SUCCESS. salvager, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  salvager, %d, returns improper value of %d.\n", 4, result);

result=getCost(sea_hag);
if(result == 4)
printf("SUCCESS. sea_hag, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  sea_hag, %d, returns improper value of %d.\n", 4, result);

result=getCost(treasure_map);
if(result == 4)
printf("SUCCESS. treasure_map, %d, returns proper value of %d.\n", 4, result);
else
printf("FAILED.  treasure_map, %d, returns improper value of %d.\n", 4, result);


    //need to add loops for multiple coins in player hand, check multiple players, different seed,
    //varying initial cards, card/deck quantity changes

  return 0;
}
