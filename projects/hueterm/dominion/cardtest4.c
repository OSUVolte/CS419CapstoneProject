/**
Michael Hueter
CS 362 Assignment 3
cardtest4.c - testing the minion card
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
  int k[10] = {adventurer, feast, gardens, mine, remodel, smithy, village, baron, minion, great_hall};
  struct gameState G;
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);

  printf ("\n******* FUNCTION UNDER TEST: playMinionCard() *******\n");

  printf ("\n------- CARD TEST 4 STARTING -------\n");
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = minion; // manually give Player 1 an feast in new slot
  failures += testAssert(minion, G.hand[0][5], "Player 1 has minion card (17) in 6th slot");
  /*********************** Choice 1 ********************************************/
  playMinionCard(&G, 1, 0, 5);
  failures += testAssert(2, G.numActions, "[Choice 1] Player 1 should now have 2 actions");
  failures += testAssert(6, G.coins, "[Choice 1] Player 1 should now have 4 + 2 = 6 coins");
  /**** test player 2 status *****/
  failures += testAssert(0, G.handCount[1], "[Choice 1] Player 2's hand should be 0");
  failures += testAssert(10, G.deckCount[1], "[Choice 1] Player 2's deck should be unchanged at 10");
  failures += testAssert(0, G.discardCount[1], "[Choice 1] Player 2's discard pile should be 0");
  /**** test victory card status *****/
  failures += testAssert(8, G.supplyCount[estate], "[Choice 1] Estate supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[duchy], "[Choice 1] Duchy supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[province], "[Choice 1] Province supplyCount unchanged (8)");
  /**** End turn and check discarded pile *****/
  endTurn(&G);
  failures += testAssert(5, G.discardCount[0], "[Choice 1] Player 1 should have discarded all 5 cards");
  /*********************** Choice 2 ********************************************/
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = minion; // manually give Player 1 an feast in new slot
  G.handCount[1] = 5; // manually set player 2's hand count
  int x = 0;
  for (x = 0; x < 5; x++){
    G.hand[1][x] = village; // load P2's hand with villages
  }
  playMinionCard(&G, 0, 1, 5);
  failures += testAssert(2, G.numActions, "[Choice 2] Player 1 should now have 2 actions");
  failures += testAssert(4, G.handCount[0], "[Choice 2] Player 1's hand now should be 4");
  /**** test player 2 status *****/
  failures += testAssert(4, G.handCount[1], "[Choice 2] Player 2's hand should now be 4");
  failures += testAssert(6, G.deckCount[1], "[Choice 2] Player 2's deck should be 10 - 4 = 6");
  /**** test victory card status *****/
  failures += testAssert(8, G.supplyCount[estate], "[Choice 2] Estate supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[duchy], "[Choice 2] Duchy supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[province], "[Choice 2] Province supplyCount unchanged (8)");

  printf ("\n------- CARD TEST 4 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
