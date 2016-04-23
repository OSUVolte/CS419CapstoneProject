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
	assert(testG.handCount[player] == (cardsHandBefore + 2));

	printf("Test 2: Should be 3 less cards in player's pile\n");
	assert(testG.deckCount[player] == (cardsDeckBefore - 3));

	printf("Test 3: Other players should be in same state as before\n");
	player = 1;
	printf("Hand Count is same\n");
	assert(testG.handCount[player] == G.handCount[player]);
	int j;
	printf("Hand is same\n");
	for (j = 0; j < G.handCount[player]; j++)
		assert(testG.hand[player][j] == G.hand[player][j]);
	printf("Deck Count is same\n");
	assert(testG.deckCount[player] == G.deckCount[player]);
	printf("Deck is same\n");
	for (j = 0; j < G.deckCount[player]; j++)
		assert(testG.deck[player][j] == G.deck[player][j]);
	printf("Discard Count is same\n");
	assert(testG.discardCount[player] == G.discardCount[player]);
	printf("Discard is same\n");
	for (j = 0; j < G.discardCount[player]; j++)
		assert(testG.discard[player][j] == G.discard[player][j]);

	printf("Test 4: Victory Card piles should be same\n");
	printf("Estate\n");
  assert(testG.supplyCount[estate] == G.supplyCount[estate]);
  printf("Duchy\n");
  assert(testG.supplyCount[duchy] == G.supplyCount[duchy]);
  printf("Province\n");
  assert(testG.supplyCount[province] == G.supplyCount[province]);

  printf("Test 5: Kingdom Card piles should be same\n");
  printf("Adventurer\n");
  assert(testG.supplyCount[adventurer] == G.supplyCount[adventurer]);
  printf("Embargo\n");
  assert(testG.supplyCount[embargo] == G.supplyCount[embargo]);
  printf("Village\n");
  assert(testG.supplyCount[village] == G.supplyCount[village]);
  printf("Minion\n");
  assert(testG.supplyCount[minion] == G.supplyCount[minion]);
  printf("Mine\n");
  assert(testG.supplyCount[mine] == G.supplyCount[mine]);
  printf("Cutpurse\n");
  assert(testG.supplyCount[cutpurse] == G.supplyCount[cutpurse]);
  printf("Sea Hag\n");
  assert(testG.supplyCount[sea_hag] == G.supplyCount[sea_hag]);
  printf("Tribute\n");
  assert(testG.supplyCount[tribute] == G.supplyCount[tribute]);
  printf("Council Room\n");
  assert(testG.supplyCount[council_room] == G.supplyCount[council_room]);

  printf("Success! Tests for smithy pass!\n");

	return 0;
}