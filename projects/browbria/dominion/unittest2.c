#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TESTFUNCTION "isGameOver"

/* REMINDER TO DO THIS - Need to understand the particulars of Makefile better
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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

    printf("\nTest 1: 1 land pile is empty: \n");
    testGS.supplyCount[duchy] = 0; //force a land pile to zero
    result=isGameOver(&testGS);
    if(result == 1)
      printf("SUCCESS. Game over, man! Game over! Expected: %d\tReturned: %d\n", 1, result);
    else
      printf("FAILED.  Car, Game on! Expected: %d\tReturned: %d\n", 1, result);


    // confirm three empty piles ends game

    initializeGame(numPlayers, k, 1000, &origGS);
       memcpy(&testGS, &origGS, sizeof(struct gameState));

       printf("\nTest 2: 3 card piles empty: \n");
       testGS.supplyCount[mine] = 0; //force a land pile to zero
       testGS.supplyCount[gold] = 0; //force a land pile to zero
       testGS.supplyCount[smithy] = 0; //force a land pile to zero
      result=isGameOver(&testGS);
       if(result == 1)
         printf("SUCCESS. Game over, man! Game over! Expected: %d\tReturned: %d\n", 1, result);
       else
         printf("FAILED.  Car, Game on! Expected: %d\tReturned: %d\n", 1, result);

    // Confirm that 2 piles doesn't end the game if one isn't land
       initializeGame(numPlayers, k, 1000, &origGS);
              memcpy(&testGS, &origGS, sizeof(struct gameState));

              printf("\nTest 3: 3 card piles empty: \n");
              testGS.supplyCount[mine] = 0;
              testGS.supplyCount[gold] = 0;
              testGS.supplyCount[smithy] = 6;

             result=isGameOver(&testGS);
              if(result == 1)
                printf("SUCCESS. Game over, man! Game over! Expected: %d\tReturned: %d\n", 1, result);
              else
                printf("FAILED.  Car, Game on! Expected: %d\tReturned: %d\n", 1, result);

              // Confirm that piles with things on them doesn't end the game
                     initializeGame(numPlayers, k, 1000, &origGS);
                            memcpy(&testGS, &origGS, sizeof(struct gameState));

                            printf("\nTest 3: 3 card piles empty: \n");
                            testGS.supplyCount[mine] = 1;
                            testGS.supplyCount[gold] = 1;
                            testGS.supplyCount[smithy] = 6;

                           result=isGameOver(&testGS);
                            if(result == 1)
                              printf("SUCCESS. Game over, man! Game over! Expected: %d\tReturned: %d\n", 1, result);
                            else
                              printf("FAILED.  Car, Game on! Expected: %d\tReturned: %d\n", 1, result);


    //need to add loops for multiple coins in player hand, check multiple players, different seed,
    //varying initial cards, card/deck quantity changes

  return 0;
}
