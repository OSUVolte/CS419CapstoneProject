#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TESTFUNCTION "whoseTurn"

/* REMINDER TO DO THIS - Need to understand the particulars of Makefile better
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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
 //need to check if update coins updates for each type of coin,
 //more than 1 of a type, multiple coins, etc

    // confirm player one should start game
    initializeGame(numPlayers, k, 1000, &origGS);
    memcpy(&testGS, &origGS, sizeof(struct gameState));

   result = testGS[whoseTurn];

   if (result==player1)
	   printf("SUCCESS. Player %d is currently active. Expected player 1.", result+1);
   else
	   printf("Failure. Player %d is currently active. Expected player 1.", result+1);

  return 0;
}
