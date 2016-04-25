/**
Michael Hueter
CS 362 Assignment 3
unittest4.c - testing the gainCard() function
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
  printf ("\n******* FUNCTION UNDER TEST: gainCard() *******\n");

  printf ("\n------- UNIT TEST 4 STARTING -------\n");
  int gainCardStatus;

  /************* testing cards not in the game *************/
  gainCardStatus = gainCard(minion, &G, 0, 0);
  failures += testAssert(-1, gainCardStatus, "Add to discard a card not in the current game");

  gainCardStatus = gainCard(minion, &G, 1, 0);
  failures += testAssert(-1, gainCardStatus, "Add to deck a card not in the current game");

  gainCardStatus = gainCard(minion, &G, 2, 0);
  failures += testAssert(-1, gainCardStatus, "Draw a card not in the current game");

  /************* testing cards with zero supplyCount *************/
  G.supplyCount[k[0]] = 0; // set adventurer to zero

  gainCardStatus = gainCard(adventurer, &G, 0, 0);
  failures += testAssert(-1, gainCardStatus, "Add to discard a card with zero supplyCount");

  gainCardStatus = gainCard(adventurer, &G, 1, 0);
  failures += testAssert(-1, gainCardStatus, "Add to deck a card with zero supplyCount");

  gainCardStatus = gainCard(adventurer, &G, 2, 0);
  failures += testAssert(-1, gainCardStatus, "Draw a card not with zero supplyCount");

  /************* give player 1 hand a feast *************/
  gainCardStatus = gainCard(feast, &G, 2, 0);
  failures += testAssert(0, gainCardStatus, "Player 1 gains a feast successfully");
  failures += testAssert(feast, G.hand[0][5], "Player 1 now has a feast (9)");
  failures += testAssert(6, G.handCount[0], "Player 1 handCount incremented to 6");
  failures += testAssert(9, G.supplyCount[k[1]], "supplyCount of feast now decremented to 9");

  /************* give player 1 discard a village *************/
  gainCardStatus = gainCard(village, &G, 0, 0);
  failures += testAssert(0, gainCardStatus, "Player 1 gains a discarded village successfully");
  failures += testAssert(village, G.discard[0][0], "Player 1 discard pile now has a discarded village (14)");
  failures += testAssert(1, G.discardCount[0], "Player 1 discardCount incremented to 1");
  failures += testAssert(9, G.supplyCount[k[6]], "supplyCount of village now decremented to 9");

  /************* give player 1 deck a smithy *************/
  gainCardStatus = gainCard(smithy, &G, 1, 0);
  failures += testAssert(0, gainCardStatus, "Player 1 deck gains a smithy successfully");
  failures += testAssert(smithy, G.deck[0][5], "Player 1 deck now has a smithy (13) in 6th position");
  failures += testAssert(6, G.deckCount[0], "Player 1 deckCount incremented to 6");
  failures += testAssert(9, G.supplyCount[k[5]], "supplyCount of smithy now decremented to 9");

  printf ("\n------- UNIT TEST 4 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
