#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

//This is a test of the numHandCards method in dominion.c

// int numHandCards(struct gameState *state) {
//   return state->handCount[ whoseTurn(state) ];
// }


int main () {

  printf("Testing numHandCards\n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  initializeGame(2, cards, 1, &game);


  game.whoseTurn = 0;
  game.handCount[0] = 0;
  game.handCount[1] = 1;

  //It returns 0 when no cards in hand
  assert(numHandCards(&game) == 0);

  //It correctly calculates based on current turn, expect 1
  game.whoseTurn = 1;
  assert(numHandCards(&game) == 1);

  //It correctly increases, expect 55
  game.handCount[1] = 55;
  assert(numHandCards(&game) == 55);

}
