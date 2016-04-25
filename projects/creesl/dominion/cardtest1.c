/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* cardtest1.c
* Lauren Crees
* Description: Tests the card smithy.
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
  int p = 0;
  int i = 0;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState G, testG;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));

	printf("* * * * * * * * * * Testing smithy * * * * * * * * * *\n");

	printf("Test 1: Player should have 3 more cards\n");
	int cardsHandBefore = testG.handCount[player];
	int cardsDeckBefore = testG.deckCount[player];
	smithyEffect(player, &testG, p, i);
	// 3 cards are drawn but 1 is discarded
  if(testG.handCount[player] == (cardsHandBefore + 2))
    printf("PASS\n");
  else
    printf("FAIL\n");

	printf("Test 2: Should be 3 less cards in player's pile\n");
  if(testG.deckCount[player] == (cardsDeckBefore - 3))
    printf("PASS\n");
  else
    printf("FAIL\n");

	printf("Test 3: Other players should be in same state as before\n");
	player = 1;
	printf("Hand Count is same\n");
  if(testG.handCount[player] == G.handCount[player])
    printf("PASS\n");
  else
    printf("FAIL\n");
	int j;
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

	printf("Test 4: Victory Card piles should be same\n");
	printf("Estate\n");
  if(testG.supplyCount[estate] == G.supplyCount[estate])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Duchy\n");
  if(testG.supplyCount[duchy] == G.supplyCount[duchy])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Province\n");
  if(testG.supplyCount[province] == G.supplyCount[province])
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Test 5: Kingdom Card piles should be same\n");
  printf("Adventurer\n");
  if(testG.supplyCount[adventurer] == G.supplyCount[adventurer])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Embargo\n");
  if(testG.supplyCount[embargo] == G.supplyCount[embargo])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Village\n");
  if(testG.supplyCount[village] == G.supplyCount[village])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Minion\n");
  if(testG.supplyCount[minion] == G.supplyCount[minion])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Mine\n");
  if(testG.supplyCount[mine] == G.supplyCount[mine])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Cutpurse\n");
  if(testG.supplyCount[cutpurse] == G.supplyCount[cutpurse])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Sea Hag\n");
  if(testG.supplyCount[sea_hag] == G.supplyCount[sea_hag])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Tribute\n");
  if(testG.supplyCount[tribute] == G.supplyCount[tribute])
    printf("PASS\n");
  else
    printf("FAIL\n");
  printf("Council Room\n");
  if(testG.supplyCount[council_room] == G.supplyCount[council_room])
    printf("PASS\n");
  else
    printf("FAIL\n");

  printf("Tests for smithy complete!\n\n");

	return 0;
}