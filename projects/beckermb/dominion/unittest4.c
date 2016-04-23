#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

//This is a test of the numHandCards method in dominion.c

int main () {

  printf("******** Testing numHandCards *********\n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  initializeGame(2, cards, 1, &game);


  game.whoseTurn = 0;
  int counter;

  //It returns 0 when no cards in hand
  game.handCount[0] = 0;
  counter = numHandCards(&game);
  if (counter == 0) {
    printf("Correctly returned 0 when no cards in hand.\n");
  } else {
    printf("FAIL: returned %d when no cards in hand.\n", counter);
  }

  //It correctly returns positive numbers, expect 8
  game.handCount[0] = 8;
  counter = numHandCards(&game);
  if (counter == 8) {
    printf("Correctly retrurns a positive number\n");
  } else {
    printf("FAIL: returned %d when 8 expected.\n", counter);
  }

  //It correctly calculates based on current turn, expect 1
  game.whoseTurn = 1;
  game.handCount[1] = 1;
  counter = numHandCards(&game);
  if (counter == 1) {
    printf("Correctly returned 1 when whoseTurn switched\n");
  } else {
    printf("FAIL: returned %d when 1 expected.\n", counter);
  }
}
