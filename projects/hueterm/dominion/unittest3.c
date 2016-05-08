/**
Michael Hueter
CS 362 Assignment 3
unittest3.c - testing the numHandCards function
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
  int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, sea_hag, great_hall};
  struct gameState G;
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);

  printf ("\n******* FUNCTION UNDER TEST: numHandCards() *******\n");

  printf ("\n------- UNIT TEST 3 STARTING -------\n");
  int cards;

  cards = numHandCards(&G);
  failures += testAssert(5, cards, "Fresh game: Player 1 starts turn with 5 cards");

  G.handCount[0] += 7;
  cards = numHandCards(&G);
  failures += testAssert(12, cards, "Player 1 gains 7 cards to have 12");

  endTurn(&G);
  cards = numHandCards(&G);
  failures += testAssert(5, cards, "Player 2 starts turn with 5 cards");

  G.handCount[1] += 7;
  cards = numHandCards(&G);
  failures += testAssert(12, cards, "Player 2 gains 7 cards to have 12");

  printf ("\n------- UNIT TEST 3 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
