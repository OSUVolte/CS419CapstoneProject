/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* cardtest3.c
* Lauren Crees
* Description: Tests the card treasure_map.
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
  int index = 0;
  int i = 0;
  int p = 0;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState G, testG;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));

	printf("* * * * * * * * * * Testing treasure_map * * * * * * * * * *\n");

  printf("Test 1: 1 Treasure Map, no gold gained\n");
  testG.hand[player][0] = treasure_map;
  int r = treasuremapEffect(index, &testG, player, i, p);
  if(testG.deckCount[player] == G.deckCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 2: Treasure Map trashed\n");
  if(testG.playedCards[testG.playedCardCount-1] != treasure_map)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 3: 1 Treasure Map, should return -1\n");
  if(r == -1)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 4: 2 Treasure Maps, gain 4 golds on top of deck\n");
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.hand[player][0] = treasure_map;
  testG.hand[player][1] = treasure_map;
  r = treasuremapEffect(index, &testG, player, i, p);
  int j;
  for (j = testG.deckCount[player]-1; j >= testG.deckCount[player]-4; j--)
  {
    if(testG.deck[player][j] == gold)
      printf("PASS\n");
    else
      printf("FAIL\n");
  }

  printf("Test 5: Treasure Maps trashed\n");
  if(testG.playedCards[testG.playedCardCount-1] != treasure_map)
    printf("PASS\n");
  else
    printf("FAIL\n");
  if(testG.playedCards[testG.playedCardCount-2] != treasure_map)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 6: 2 Treasure Maps, should return 1\n");
  if(r == 1)
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 7: Other players should be in same state as before\n");
  player = 1;
  printf("Hand Count is same\n");
  if(testG.handCount[player] == G.handCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Hand is same\n");
  for (j = 0; j < G.handCount[player]; j++)
  {
    if(testG.hand[player][j] == G.hand[player][j])
      printf("PASS\n");
    else
      printf("FAIL\n");
  }
  printf("Deck Count is same\n");
  if(testG.deckCount[player] == G.deckCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Deck is same\n");
  for (j = 0; j < G.deckCount[player]; j++)
  {
    if(testG.deck[player][j] == G.deck[player][j])
      printf("PASS\n");
    else
      printf("FAIL\n");
  }
  printf("Discard Count is same\n");
  if(testG.discardCount[player] == G.discardCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Discard is same\n");
  for (j = 0; j < G.discardCount[player]; j++)
  {
    if(testG.discard[player][j] == G.discard[player][j])
      printf("PASS\n");
    else
      printf("FAIL\n");
  }

  printf("Tests for treasure_map complete!\n\n");

  return 0;
}