#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


//This is a test of the isGameOver method in dominion.c

int main () {
  printf("Testing isGameOver\n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  initializeGame(4, cards, 1, &game);

  //Brand new game. Expect game to be in progress.
  assert(isGameOver(&game) == 0);

  // Zero provinces. Expect game to be over.
  game.supplyCount[province] = 0;
  assert(isGameOver(&game) == 1);
  game.supplyCount[province] = 5;

  //Two stacks empty. Expect game to be in progress.
  game.supplyCount[council_room] = 0;
  game.supplyCount[gardens] = 0;
  assert(isGameOver(&game) == 0);

  //Three stacks empty. Expect game to be over.
  game.supplyCount[smithy] = 0;
  assert(isGameOver(&game) == 1);
}
