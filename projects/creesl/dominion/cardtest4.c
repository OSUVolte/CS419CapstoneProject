/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* cardtest4.c
* Lauren Crees
* Description: Tests the card sea_hag.
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
  int otherPlayer = 1;
  int i = 0;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState G, testG;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));

	printf("* * * * * * * * * * Testing sea_hag * * * * * * * * * *\n");

	printf("Test 1: Top of player's deck is same before and after\n");
	int topDeckBefore = testG.deck[player][testG.deckCount[player]-1];
	seahagEffect(&testG, player, i);
	if(testG.deck[player][testG.deckCount[player]-1] == topDeckBefore)
    printf("PASS\n");
  else
    printf("FAIL\n");

	printf("Test 2: Other player's discard was top of deck\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	topDeckBefore = testG.deck[otherPlayer][testG.deckCount[otherPlayer]-1];
	seahagEffect(&testG, player, i);
	if(testG.discard[otherPlayer][testG.discardCount[otherPlayer]-1] == topDeckBefore)
    printf("PASS\n");
  else
    printf("FAIL\n");

	printf("Test 3: Other player's top of deck is a curse card\n");
	if(testG.deck[otherPlayer][testG.deckCount[otherPlayer]-1] == curse)
    printf("PASS\n");
  else
    printf("FAIL\n");

	printf("Tests for sea_hag complete!\n\n");

  return 0;
}