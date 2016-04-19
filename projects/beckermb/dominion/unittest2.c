#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


//This is a test of the updateCoins method in dominion.c

int main () {

  printf("Testing updateCoins\n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int player = 0;
  initializeGame(2, cards, 1, &game);

  //With no cards in hand, expect 0
  game.handCount[player] = 0;
  updateCoins(0, &game, 0);
  assert(game.coins == 0);

  //With Bonus, expect bonus amount of 4
  game.handCount[player] = 0;
  updateCoins(0, &game, 4);
  assert(game.coins == 4);

  //With a single copper, expect 1
  game.handCount[player] = 1;
  game.hand[player][0] = copper;
  updateCoins(0, &game, 0);
  assert(game.coins == 1);

  //With a single silver, expect 2
  game.hand[player][0] = silver;
  updateCoins(0, &game, 0);
  assert(game.coins == 2);

  //With a single gold, expect 3
  game.hand[player][0] = gold;
  updateCoins(0, &game, 0);
  assert(game.coins == 3);

  //With multiple treasures, 7 total expected
  game.handCount[player] = 4;
  game.hand[player][0] = copper;
  game.hand[player][1] = copper;
  game.hand[player][2] = silver;
  game.hand[player][3] = gold;
  updateCoins(0, &game, 0);
  assert(game.coins == 7);

  //With non treasure cards in hand, expect 5
  game.handCount[player] = 5;
  game.hand[player][0] = copper;
  game.hand[player][1] = smithy;
  game.hand[player][2] = gold;
  game.hand[player][3] = copper;
  game.hand[player][4] = gardens;
  updateCoins(0, &game, 0);
  assert(game.coins == 5);
}
