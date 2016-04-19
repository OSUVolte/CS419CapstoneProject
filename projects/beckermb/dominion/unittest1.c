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

  //Brand new game. Expect game to not be over.
  assert(isGameOver(game) == 0)

}
