/**
Michael Hueter
CS 362 Assignment 3
cardtest2.c - testing the smithy card
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

  printf ("\n******* FUNCTION UNDER TEST: playSmithyCard() *******\n");

  printf ("\n------- CARD TEST 2 STARTING -------\n");
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = smithy; // manually give Player 1 an smithy in new slot
  failures += testAssert(smithy, G.hand[0][5], "Player 1 has smithy card (13) in 6th slot");
  G.deckCount[0] = 5; // set deck count to five
  int x = 0;
  for (x = 0; x < 5; x++){
    G.deck[0][x] = village; // load the deck with villages
  }

  int smithyStatus;
  smithyStatus = playSmithyCard(&G, 5);
  failures += testAssert(0, smithyStatus, "Smithy card executes and returns 0");
  failures += testAssert(8, G.handCount[0], "Player 1 should draw 3 cards and discard smithy to have 8 total");
  failures += testAssert(2, G.deckCount[0], "Player 1 should have 3 cards subtracted from deck (5 - 3 = 2)");

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
  failures += testAssert(8, G.discardCount[0], "Player 1 should have discarded all 8 cards");

  /**** Clear game state for next round of tests *****/
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = smithy; // manually give Player 1 an smithy in new slot
  G.deckCount[0] = 0; // set deck count to zero
  playSmithyCard(&G, 5);
  failures += testAssert(5, G.handCount[0], "Player 1 now should not be able to draw 3 cards but discard smithy to have 5 total");

  /**** Clear game state for final round of tests *****/
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = smithy; // manually give Player 1 an smithy in new slot
  G.deckCount[0] = 0; // set deck count to zero
  G.discardCount[0] = 3;
  for (x = 0; x < 3; x++){
    G.discard[0][x] = village; // load the discard pile with villages
  }
  playSmithyCard(&G, 5);
  failures += testAssert(8, G.handCount[0], "Player 1, with empty deck, now should draw 3 cards from shuffled discard pile to have 8 total");


  printf ("\n------- CARD TEST 2 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
