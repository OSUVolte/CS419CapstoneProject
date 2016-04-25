/**
Michael Hueter
CS 362 Assignment 3
cardtest3.c - testing the village card
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int testAssert(int expected, int actual, char *a){
  if (expected != actual){
    printf ("\n ! ASSERTION FAILED: EXPECTED %s == %d, NOT %d. \n", a, expected, actual);
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

  printf ("\n******* FUNCTION UNDER TEST: playVillageCard() *******\n");

  printf ("\n------- CARD TEST 3 STARTING -------\n");
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = village; // manually give Player 1 an feast in new slot
  failures += testAssert(village, G.hand[0][5], "Player 1 has village card (14) in 6th slot");
  playVillageCard(&G, 5);
  failures += testAssert(3, G.numActions, "Player 1 should now have 3 actions");
  /**** test player 2 status *****/
  failures += testAssert(0, G.handCount[1], "Player 2's hand should be 0");
  failures += testAssert(10, G.deckCount[1], "Player 2's deck should be unchanged at 10");
  failures += testAssert(0, G.discardCount[1], "Player 2's discard pile should be 0");
  /**** test victory card status *****/
  failures += testAssert(8, G.supplyCount[estate], "Estate supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[duchy], "Duchy supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[province], "Province supplyCount unchanged (8)");
  /**** End turn and check discarded pile *****/
  endTurn(&G);
  failures += testAssert(6, G.discardCount[0], "Player 1 should have discarded all 6 cards");

  printf ("\n------- CARD TEST 3 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
