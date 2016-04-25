#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


//This is a test of the isGameOver method in dominion.c

int main () {
  printf("******* Testing isGameOver ************\n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  initializeGame(4, cards, 1, &game);

  //Brand new game. Expect game to be in progress.
  if (isGameOver(&game) == 0) {
    printf("Correct status for new game.\n");
  } else {
    printf("FAIL: isGameOver returned true for new game.\n");
  }

  // Zero provinces. Expect game to be over.
  game.supplyCount[province] = 0;
  if (isGameOver(&game) == 1) {
    printf("Correct status with no provinces.\n");
  } else {
    printf("Fail: isGameOver returned false with no provinces\n");
  }
  game.supplyCount[province] = 5;

  //Two stacks empty. Expect game to be in progress.
  game.supplyCount[council_room] = 0;
  game.supplyCount[gardens] = 0;
  if (isGameOver(&game) == 0) {
    printf("Correct status for game with two empty stacks.\n");
  } else {
    printf("FAIL: isGameOver returned true for game with just two empty stacks.\n");
  }


  //Three stacks empty. Expect game to be over.
  game.supplyCount[smithy] = 0;
  if (isGameOver(&game) == 1) {
    printf("Correct status for game with three empty stacks.\n");
  } else {
    printf("FAIL: isGameOver returned false for game with three empty stacks.\n");
  }
}
