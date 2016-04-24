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
  if(isGameOver(&testG) == 0)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 2: If province cards empty, game over\n");
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.supplyCount[province] = 0;
  if(isGameOver(&testG) == 1)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 3: If three supply piles are 0, game over\n");
  memcpy(&testG, &G, sizeof(struct gameState));
  // set three piles to 0
  testG.supplyCount[adventurer] = 0;
  testG.supplyCount[embargo] = 0;
  testG.supplyCount[village] = 0;
  if(isGameOver(&testG) == 1)
    printf("PASS\n");
  else
    printf("FAIL\n");


  printf("Tests for isGameOver() complete!\n\n");

  return 0;
}