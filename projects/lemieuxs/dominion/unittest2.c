#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkSupplyCount(struct gameState *game, int supply[]) {
	int i;
	struct gameState testGame;

	memcpy(&testGame, game, sizeof(struct gameState));

	printf("\n\nChecking that supplyCount returns game->supplyCount[i]\n\n");
	for (i = 0; i <= treasure_map; ++i){
		printf("supply for card %d: %d, expected = %d\n", i, supplyCount(i, game), testGame.supplyCount[i]);
		//printf("supply for card %d: %d\n", i, supplyCount(i, game));
		assert(supplyCount(i, game) == testGame.supplyCount[i]);
	}

	printf("\nSubtracting 3 cards from each of the kingdom piles\n\n");

	// check kingdom piles
	for (i = 0; i < 10; ++i) {
		game->supplyCount[supply[i]] -= 3; // subtract three from each pile
		printf("supply for card %d: %d, expected = %d\n", supply[i], supplyCount(supply[i], game), testGame.supplyCount[supply[i]] - 3);
		assert(supplyCount(supply[i], game) == testGame.supplyCount[supply[i]] - 3);
	}

	printf("\nSubtracting 3 cards from each of the victory, curse, and treasure piles\n\n");
	// check victory, curse, treasure cards
	for (i = 0; i <= gold; ++i){
		game->supplyCount[i] -= 3; // subtract three from each pile
		printf("supply for card %d: %d, expected = %d\n", i, supplyCount(i, game), testGame.supplyCount[i] - 3);
		assert(supplyCount(i, game) == testGame.supplyCount[i] - 3);
	}

	printf("\nTesting other players' state:\n");
	// check that players' state hasn't been modified
	for (i = 0; i < game->numPlayers; ++i) {
		printf("\nChecking Player Number %d:\n", i);

		printf("Checking handCount\n");
		printf("hand count = %d, expected = %d\n", game->handCount[i], testGame.handCount[i]);
		assert(game->handCount[i] == testGame.handCount[i]);

		printf("Checking deckCount\n");
		printf("deck count = %d, expected = %d\n", game->deckCount[i], testGame.deckCount[i]);
		assert(game->deckCount[i] == testGame.deckCount[i]);

		printf("Checking discardCount\n");
		printf("discard count = %d, expected = %d\n", game->discardCount[i], testGame.discardCount[i]);
		assert(game->discardCount[i] == testGame.discardCount[i]);
	}

	return 0;
}



int main() {

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };


	struct gameState G;

	int seed = 1000;
	int numPlayers = 2;


	printf("Testing supplyCount()\n");


	initializeGame(numPlayers, k, seed, &G);


	checkSupplyCount(&G, k);



	return 0;
}