/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* unittest1.c
* Lauren Crees
* Description: Tests the function isGameOver().
* * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main()
{
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState G, testG;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));

  printf("* * * * * * * * * * Testing isGameOver() * * * * * * * * * *\n");

  printf("Test 1: New game, with full decks and supplies, should not be over\n");
  assert(isGameOver(&testG) == 0);

  printf("Test 2: If province cards empty, game over\n");
  testG.supplyCount[province] = 0;
  assert(isGameOver(&testG) == 1);

  printf("Test 3: If three supply piles are 0, game over\n");
  // make sure province supply count isn't 0
  testG.supplyCount[province] = G.supplyCount[province];
  // set three piles to 0
  testG.supplyCount[treasure_map] = 0;
  testG.supplyCount[sea_hag] = 0;
  testG.supplyCount[salvager] = 0;
  assert(isGameOver(&testG) == 1);

  printf("Success! Tests for isGameOver() pass!");

  return 0;
}