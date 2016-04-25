#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkWhoseTurn(struct gameState *game) {
	int i;
	struct gameState testGame;

	memcpy(&testGame, game, sizeof(struct gameState));

	game->whoseTurn = 0;

	printf("Setting game->whoseTurn to 0, checking that whoseTurn returns 0\n");
	assert(whoseTurn(game) == 0);

	game->whoseTurn = 1;

	printf("Setting game->whoseTurn to 1, checking that whoseTurn returns 1\n");

	assert(whoseTurn(game) == 1);

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

	printf("\nTesting victory and kingdom cards:\n");
	// check that the victory and kingdom card piles are ok
	for (i = 0; i <= treasure_map; ++i){
		assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}


	return 0;
}



int main() {
	
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	struct gameState G;

	int seed = 1000;
	int numPlayers = 2;

	printf("Testing whoseTurn()\n");


	initializeGame(numPlayers, k, seed, &G);


	checkWhoseTurn(&G);



	return 0;
}