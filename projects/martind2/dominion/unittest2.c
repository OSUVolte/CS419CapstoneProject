/* unittest3.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the isGameOver function.
 * - If province card pile empty, is game over? (yes)
 * - If three supply piles are at zero, is game over? (yes)
 * - If two supply piles are at zero, is game over? (no)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
	// Counters
	int i;

	// Game settings
	int seed = 1000,
		numPlayers = 2,
		cards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
					  sea_hag, tribute, smithy, council_room };

	// Game init
	struct gameState G, testG;
	initializeGame(numPlayers, cards, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("--------------- UNIT TEST 2 ---------------\n");
	printf("----------- IS GAME OVER TESTS ------------\n");

	printf("\nTEST 1: IF PROVINCE CARD PILE EMPTY, GAME IS OVER\n");
	
	G.supplyCount[province] = 0;
	i = isGameOver(&G);
	printf("isGameOver returned %d, expected 1\n", i);
	assert(isGameOver(&G) == 1);

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\nTEST 2: IF THREE SUPPY PILES EMPTY, GAME IS OVER\n");

	G.supplyCount[adventurer] = 0;
	G.supplyCount[embargo] = 0;
	G.supplyCount[village] = 0;
	i = isGameOver(&G);

	printf("isGameOver returned %d, expected 1\n", i);
	assert(isGameOver(&G) == 1);

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\nTEST 3: IF TWO SUPPLY PILES EMPTY, GAME IS NOT OVER\n");

	G.supplyCount[adventurer] = 0;
	G.supplyCount[embargo] = 0;
	i = isGameOver(&G);

	printf("isGameOver returned %d, expected 0\n", i);
	assert(isGameOver(&G) == 0);

	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}