/**
Michael Hueter
CS 362 Assignment 3
unittest2.c - testing the isGameOver function
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int testAssert(int expected, int actual, char *a){
  if (expected != actual){
    printf ("\n ! ASSERTION FAILED: EXPECTED %s == %d, NOT %d). \n", a, expected, actual);
    return 1;
  }
  printf ("\n PASSED: %s == %d.\n", a, actual);
  return 0;
}


int main() {
  int failures = 0; // keep track of how many tests failed
  int gameOver;
  int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, sea_hag, great_hall};
  struct gameState G;
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);

  printf ("\n******* FUNCTION UNDER TEST: isGameOver() *******\n");

  printf ("\n------- UNIT TEST 2 STARTING -------\n");
  gameOver = isGameOver(&G);
  failures += testAssert(0, gameOver, "Fresh Game State");

  G.supplyCount[province] = 0;
  gameOver = isGameOver(&G);
  failures += testAssert(1, gameOver, "Province Cards Empty");

  G.supplyCount[province] = 6;
  gameOver = isGameOver(&G);
  failures += testAssert(0, gameOver, "Put 6 Province Cards Back");

  int i;
  for(i = 0; i < 3; i++){
    G.supplyCount[k[i]] = 0;
  }
  gameOver = isGameOver(&G);
  failures += testAssert(1, gameOver, "First 3 supply piles are empty");

  for(i = 0; i < 3; i++){
    G.supplyCount[k[i]] = 3;
  }
  gameOver = isGameOver(&G);
  failures += testAssert(0, gameOver, "First 3 supply piles made non-empty");

  for(i = 1; i < 10; i+=3){
    G.supplyCount[k[i]] = 0;
  }
  gameOver = isGameOver(&G);
  failures += testAssert(1, gameOver, "Feast, Remodel, Baron are empty");

  for(i = 1; i < 10; i+=3){
    G.supplyCount[k[i]] = 3;
  }
  gameOver = isGameOver(&G);
  failures += testAssert(0, gameOver, "Feast, Remodel, Baron made non-empty");

  printf ("\n------- UNIT TEST 2 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
