/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* unittest2.c
* Lauren Crees
* Description: Tests the function fullDeckCount().
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
  int card = 0;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState G, testG;
  int i;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));

  printf("* * * * * * * * * * Testing fullDeckCount() * * * * * * * * * *\n");

  printf("Test 1: Sum is correct when card present\n");
  for (i = 0; i < testG.deckCount[player]; i++)
    testG.deck[player][i] = card;
  for (i = 0; i < testG.handCount[player]; i++)
    testG.hand[player][i] = card;
  for (i = 0; i < testG.discardCount[player]; i++)
    testG.discard[player][i] = card;
  if(fullDeckCount(player, card, &testG) == (testG.deckCount[player] + testG.handCount[player] + testG.discardCount[player]))
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 2: Sum is 0 when card not present\n");
  for (i = 0; i < testG.deckCount[player]; i++)
    testG.deck[player][i] = card + 1;
  for (i = 0; i < testG.handCount[player]; i++)
    testG.hand[player][i] = card + 2;
  for (i = 0; i < testG.discardCount[player]; i++)
    testG.discard[player][i] = card + 3;
  if(fullDeckCount(player, card, &testG) == 0)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 3: Deck count is correct\n");
  // There are deckCount number of cards in deck and no cards in hand or discard
  for (i = 0; i < testG.deckCount[player]; i++)
    testG.deck[player][i] = card;
  for (i = 0; i < testG.handCount[player]; i++)
    testG.hand[player][i] = card + 1;
  for (i = 0; i < testG.discardCount[player]; i++)
    testG.discard[player][i] = card + 1;
  if(fullDeckCount(player, card, &testG) == testG.deckCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 4: Hand count is correct\n");
  for (i = 0; i < testG.deckCount[player]; i++)
    testG.deck[player][i] = card + 1;
  for (i = 0; i < testG.handCount[player]; i++)
    testG.hand[player][i] = card;
  for (i = 0; i < testG.discardCount[player]; i++)
    testG.discard[player][i] = card + 1;
  if(fullDeckCount(player, card, &testG) == testG.handCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 5: Discard count is correct\n");
  for (i = 0; i < testG.deckCount[player]; i++)
    testG.deck[player][i] = card + 1;
  for (i = 0; i < testG.handCount[player]; i++)
    testG.hand[player][i] = card + 1;
  for (i = 0; i < testG.discardCount[player]; i++)
    testG.discard[player][i] = card;
  if(fullDeckCount(player, card, &testG) == testG.discardCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Tests for fullDeckCount() complete!\n\n");

  return 0;
}