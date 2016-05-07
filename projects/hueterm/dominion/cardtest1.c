/**
Michael Hueter
CS 362 Assignment 3
cardtest1.c - testing the adventurer card
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

  printf ("\n******* FUNCTION UNDER TEST: playAdventurerCard() *******\n");

  printf ("\n------- CARD TEST 1 STARTING -------\n");
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = adventurer; // manually give Player 1 an adventurer in new slot
  failures += testAssert(adventurer, G.hand[0][5], "Player 1 has adventurer card (7) in 6th slot");

  int adventurerStatus;
  int hasTreasure;
  int discardedFlag = 0;
  adventurerStatus = playAdventurerCard(&G);
  failures += testAssert(0, adventurerStatus, "Adventurer card executes and returns 0");
  failures += testAssert(8, G.handCount[0], "Player 1 should now have 8 cards");
  /**** test first drawn card for treasure *****/
  if (G.hand[0][6] == copper || G.hand[0][6] == silver || G.hand[0][6] == gold ){
    hasTreasure = 1;
  }
  else {
    hasTreasure = 0;
  }
  failures += testAssert(1, hasTreasure, "Player 1's 7th card should be treasure");
  /**** test second drawn card for treasure *****/
  if (G.hand[0][7] == copper || G.hand[0][7] == silver || G.hand[0][7] == gold ){
    hasTreasure = 1;
  }
  else {
    hasTreasure = 0;
  }
  failures += testAssert(1, hasTreasure, "Player 1's 8th card should be treasure");
  /**** test player 2 status *****/
  failures += testAssert(0, G.handCount[1], "Player 2's hand should be 0");
  failures += testAssert(10, G.deckCount[1], "Player 2's deck should be unchanged at 10");
  failures += testAssert(0, G.discardCount[1], "Player 2's discard pile should be 0");
  /**** test victory card status *****/
  failures += testAssert(8, G.supplyCount[estate], "Estate supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[duchy], "Duchy supplyCount unchanged (8)");
  failures += testAssert(8, G.supplyCount[province], "Province supplyCount unchanged (8)");

  /**** Clear game state for additonal round of tests *****/
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = adventurer; // manually give Player 1 an adventurer in new slot
  G.deckCount[0] = 5; // set deck count to five
  int x = 0;
  for (x = 0; x < 5; x++){
    G.deck[0][x] = village; // load the deck with villages
  }
  /**** check to make sure player 1 discards all his deck *****/
  playAdventurerCard(&G);
  if (G.discardCount[0] > 0){
    discardedFlag = 1;
  }
  failures += testAssert(1, discardedFlag, "Player 1 has no treasure in deck and should have discarded at least 1 card");
  failures += testAssert(0, G.deckCount[0], "Player 1 deck should be empty");
  failures += testAssert(5, G.handCount[0], "Player 1 hand should have 5 still");

  /**** Clear game state for final round of tests *****/
  memset(&G, 0, sizeof(struct gameState));   // clear the game state
  initializeGame(2, k, 10, &G);
  G.handCount[0]++; // manually increment hand count
  G.hand[0][5] = adventurer; // manually give Player 1 an adventurer in new slot
  G.deckCount[0] = 0; // set deck empty
  G.discardCount[0] = 3;
  for (x = 0; x < 3; x++){
    G.discard[0][x] = gold; // load discard with gold
  }
  /**** Clear game state for additonal round of tests *****/
  playAdventurerCard(&G);
  if (G.hand[0][7] == copper || G.hand[0][7] == silver || G.hand[0][7] == gold ){
    hasTreasure = 1;
  }
  else {
    hasTreasure = 0;
  }
  failures += testAssert(1, hasTreasure, "Player 1 should shuffle in gold from discard pile");
  failures += testAssert(8, G.handCount[0], "Player 1 should now have 8 cards");



  printf ("\n------- CARD TEST 1 COMPLETE -------\n");
  if(failures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("  FAILURES: %d \n\n", failures);
  }
  return 0;
}
