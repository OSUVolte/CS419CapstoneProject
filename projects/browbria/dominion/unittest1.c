#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TESTFUNCTION "updateCoins"

/* REMINDER TO DO THIS - Need to understand the particulars of Makefile better
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 */

int main(){

  int i;                                // counter
  int pos;                              // position
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

    // confirm one copper
    initializeGame(numPlayers, k, 1000, &origGS);
    memcpy(&testGS, &origGS, sizeof(struct gameState));
    testGS.hand[player1][0] = smithy;
    testGS.hand[player1][1] = duchy;
    testGS.hand[player1][2] = minion;
    testGS.hand[player1][3] = mine;
    testGS.hand[player1][4] = copper;
    updateCoins(player1, &testGS, 0);
    printf("\nTest 1: Copper should increase coins by 1: \n");
    if(testGS.coins == coinAmount + 1)
      printf("SUCCESS. Copper = +1 to coins. Expected: %d\tReturned: %d\n", coinAmount +1, testGS.coins);
    else
      printf("FAILED.  Copper = +1 to coins. Expected: %d\tReturned: %d\n", coinAmount +1, testGS.coins);


    // confirm one silver in hand
    // reinitialize game with silver instead of copper
    initializeGame(numPlayers, k, 1000, &origGS);
    memcpy(&testGS, &origGS, sizeof(struct gameState));
    	testGS.hand[player1][0] = smithy;
        testGS.hand[player1][1] = duchy;
        testGS.hand[player1][2] = minion;
        testGS.hand[player1][3] = mine;
        testGS.hand[player1][4] = silver;
    updateCoins(player1, &testGS, 0);
    printf("Test 3: Silver increases coins by 2: \n");
    if(testGS.coins == coinAmount +2)
      printf("SUCCESS. Silver = +2 to coins. Expected: %d\tReturned: %d\n", coinAmount +2, testGS.coins);
    else
      printf("FAILED. Silver = +2 to coins. Expected: %d\tReturned: %d\n", coinAmount +2, testGS.coins);

    // Confirm one gold in hand
    // reinitialize game with gold instead of copper
    initializeGame(numPlayers, k, 1000, &origGS);
    memcpy(&testGS, &origGS, sizeof(struct gameState));
    	testGS.hand[player1][0] = smithy;
        testGS.hand[player1][1] = duchy;
        testGS.hand[player1][2] = minion;
        testGS.hand[player1][3] = mine;
        testGS.hand[player1][4] = gold;
    updateCoins(player1, &testGS, 0);
    printf("Test 5: Gold increases coins by 3: \n");
    if(testGS.coins == coinAmount +3)
    	printf("SUCCESS. Gold = +3 to coins. Expected: %d\tReturned: %d\n", coinAmount +3, testGS.coins);
    else
    	printf("FAILED. Gold = +3 to coins. Expected: %d\tReturned: %d\n", coinAmount +3, testGS.coins);

    //need to add loops for multiple coins in player hand, check multiple players, different seed,
    //varying initial cards, card/deck quantity changes

  return 0;
}
