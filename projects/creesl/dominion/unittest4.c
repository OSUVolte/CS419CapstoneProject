/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* unittest4.c
* Lauren Crees
* Description: Tests the function discardCard().
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
  int player = 0;
  int flag = 0;
  int p = 1;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState G, testG;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));

  printf("* * * * * * * * * * Testing discardCard() * * * * * * * * * *\n");

  printf("Test 1: Trash Flag of 1 should increase playedCardCount by 1\n");
  discardCard(p, player, &testG, flag);
  assert(testG.playedCardCount == (G.playedCardCount + 1));

  printf("Test 2: Last card in hand should decrease handCount by 1\n");
  p = testG.handCount[player] - 1;
  flag = 1;
  int hCountBefore = testG.handCount[player];
  discardCard(p, player, &testG, flag);
  assert(testG.handCount[player] == (hCountBefore - 1));

  printf("Test 3: One card in hand should decrease handCount by 1\n");
  testG.handCount[player] = 1;
  hCountBefore = testG.handCount[player];
  p = 0;
  discardCard(p, player, &testG, flag);
  assert(testG.handCount[player] == (hCountBefore - 1));

  printf("Test 4: More than one card should decrease handCount by 1\n");
  testG.handCount[player] = 3;
  p = 1;
  hCountBefore = testG.handCount[player];
  discardCard(p, player, &testG, flag);
  assert(testG.handCount[player] == (hCountBefore - 1));

  printf("Success! Tests for discardCard() pass!");

  return 0;
}