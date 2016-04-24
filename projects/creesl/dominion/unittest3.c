/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* unittest3.c
* Lauren Crees
* Description: Tests the function scoreFor().
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
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState testG, G;
  int i;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.handCount[player] = 10;
  testG.discardCount[player] = 10;
  testG.deckCount[player] = 10;

  printf("* * * * * * * * * * Testing scoreFor() * * * * * * * * * *\n");

  printf("Test 1: Score for hand correct\n");
  testG.hand[player][0] = curse;
  testG.hand[player][1] = estate;
  testG.hand[player][2] = duchy;
  testG.hand[player][3] = province;
  testG.hand[player][4] = great_hall;
  testG.hand[player][5] = gardens;
  testG.hand[player][6] = smithy;
  testG.hand[player][7] = smithy;
  testG.hand[player][8] = smithy;
  testG.hand[player][9] = smithy;
  for (i = 0; i < 10; i++)
  {
    testG.discard[player][i] = smithy;
    testG.deck[player][i] = smithy;
  }
  if(scoreFor(player, &testG) == 10)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 2: Score for discard correct\n");
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.handCount[player] = 10;
  testG.discardCount[player] = 10;
  testG.deckCount[player] = 10;
  testG.discard[player][0] = curse;
  testG.discard[player][1] = estate;
  testG.discard[player][2] = duchy;
  testG.discard[player][3] = province;
  testG.discard[player][4] = great_hall;
  testG.discard[player][5] = gardens;
  testG.discard[player][6] = smithy;
  testG.discard[player][7] = smithy;
  testG.discard[player][8] = smithy;
  testG.discard[player][9] = smithy;
  for (i = 0; i < 10; i++)
  {
    testG.hand[player][i] = smithy;
    testG.deck[player][i] = smithy;
  }
  if(scoreFor(player, &testG) == 10)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 3: Score for deck correct\n");
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.handCount[player] = 10;
  testG.discardCount[player] = 10;
  testG.deckCount[player] = 10;
  testG.deck[player][0] = curse;
  testG.deck[player][1] = estate;
  testG.deck[player][2] = duchy;
  testG.deck[player][3] = province;
  testG.deck[player][4] = great_hall;
  testG.deck[player][5] = gardens;
  testG.deck[player][6] = smithy;
  testG.deck[player][7] = smithy;
  testG.deck[player][8] = smithy;
  testG.deck[player][9] = smithy;
  for (i = 0; i < 10; i++)
  {
    testG.discard[player][i] = smithy;
    testG.hand[player][i] = smithy;
  }
  if(scoreFor(player, &testG) == 10)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 4: Score total correct\n");
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.handCount[player] = 10;
  testG.discardCount[player] = 10;
  testG.deckCount[player] = 10;
  testG.hand[player][0] = curse;
  testG.hand[player][1] = estate;
  testG.hand[player][2] = duchy;
  testG.hand[player][3] = province;
  testG.hand[player][4] = great_hall;
  testG.hand[player][5] = gardens;
  testG.hand[player][6] = smithy;
  testG.hand[player][7] = smithy;
  testG.hand[player][8] = smithy;
  testG.hand[player][9] = smithy;
  testG.discard[player][0] = curse;
  testG.discard[player][1] = estate;
  testG.discard[player][2] = duchy;
  testG.discard[player][3] = province;
  testG.discard[player][4] = great_hall;
  testG.discard[player][5] = gardens;
  testG.discard[player][6] = smithy;
  testG.discard[player][7] = smithy;
  testG.discard[player][8] = smithy;
  testG.discard[player][9] = smithy;
  testG.deck[player][0] = curse;
  testG.deck[player][1] = estate;
  testG.deck[player][2] = duchy;
  testG.deck[player][3] = province;
  testG.deck[player][4] = great_hall;
  testG.deck[player][5] = gardens;
  testG.deck[player][6] = smithy;
  testG.deck[player][7] = smithy;
  testG.deck[player][8] = smithy;
  testG.deck[player][9] = smithy;
  if(scoreFor(player, &testG) == 30)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 5: Score is 0 when no scorable cards\n");
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.handCount[player] = 10;
  testG.discardCount[player] = 10;
  testG.deckCount[player] = 10;
  for (i = 0; i < 10; i++)
  {
    testG.discard[player][i] = smithy;
    testG.deck[player][i] = smithy;
    testG.hand[player][i] = smithy;
  }
  if(scoreFor(player, &testG) == 0)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Tests for scoreFor() complete!\n\n");

  return 0;
}