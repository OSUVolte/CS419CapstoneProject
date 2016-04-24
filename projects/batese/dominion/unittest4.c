/*
File: unittest1.c
Author: Elliot Bates
Description: Unit test for full deck count function from dominion
*/

/*
int fullDeckCount(int player, int card, struct gameState *state) {
  int i;
  int count = 0;

  for (i = 0; i < state->deckCount[player]; i++)
    {
      if (state->deck[player][i] == card) count++;
    }

  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == card) count++;
    }

  for (i = 0; i < state->discardCount[player]; i++)
    {
      if (state->discard[player][i] == card) count++;
    }

  return count;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int supplyCounts[25];
	int gameOver;
	int card, deckCount;

	printf ("TESTING fullDeckCount():\n");
	
	for (p = 0; p < numPlayer; p++) {
		for (card = 1; card < 24; card++) {
			printf("Testing with player %d and card %d.\n", p, card);
			// Check with 3 cards in each place
			printf("Testing with 3 cards in each location.\n");
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.deck[p][card] = 3;
			G.hand[p][card] = 3;
			G.discard[p][card] = 3;
			deckCount = fullDeckCount(p, card, &G);
			if (deckCount == 9)
				printf("PASSED: fullDeckCount = %d, expected = 9.\n", deckCount);
			else
				printf("FAILED: fullDeckCount = %d, expected = 9.\n", deckCount);
			
			// Check with 3 cards in 2 places
			printf("Testing with 3 cards in both deck and discard.\n");
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.deck[p][card] = 3;
			G.hand[p][card] = 0;
			G.discard[p][card] = 3;
			deckCount = fullDeckCount(p, card, &G);
			if (deckCount == 6)
				printf("PASSED: fullDeckCount = %d, expected = 6.\n", deckCount);
			else
				printf("FAILED: fullDeckCount = %d, expected = 6.\n", deckCount);
			
			// Check with 3 cards in 1 places
			printf("Testing with 3 cards in just hand.\n");
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.deck[p][card] = 0;
			G.hand[p][card] = 3;
			G.discard[p][card] = 0;
			deckCount = fullDeckCount(p, card, &G);
			if (deckCount == 3)
				printf("PASSED: fullDeckCount = %d, expected = 3.\n", deckCount);
			else
				printf("FAILED: fullDeckCount = %d, expected = 3.\n", deckCount);
		}
	}
}



















