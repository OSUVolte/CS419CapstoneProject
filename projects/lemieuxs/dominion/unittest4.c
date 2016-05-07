#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkGainCard(struct gameState * game) {
	int r, i;
	struct gameState testGame;
	int thisPlayer = whoseTurn(game);

	// toFlag = 0 : add to discard
	// toFlag = 1 : add to deck
	// toFlag = 2 : add to hand

	printf("\nTest 1: gain adventurer to discard\n");

	memcpy(&testGame, game, sizeof(struct gameState));

	r = gainCard(adventurer, game, 0, thisPlayer);
	assert(r == 0);

	printf("Checking player's state\n");
	// make sure the appropriate number of cards has been added to the player's hand
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	// make sure the cards came from the player's deck
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer] + 1);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);

	// check that other players' state hasn't been modified
	printf("\nTesting other players' state:\n");
	// start at 1 since the current player is 0.
	for (i = 1; i < game->numPlayers; ++i) {
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
		if (i == adventurer)
			assert(game->supplyCount[i] == testGame.supplyCount[i] - 1);
		else
			assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}



	printf("\nTest 2: gain adventurer to deck\n");

	memcpy(&testGame, game, sizeof(struct gameState));

	r = gainCard(adventurer, game, 1, thisPlayer);
	assert(r == 0);

	printf("Checking player's state\n");
	// make sure the appropriate number of cards has been added to the player's hand
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	// make sure the cards came from the player's deck
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer] + 1);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer] + 1);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer]);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer]);

	// check that other players' state hasn't been modified
	printf("\nTesting other players' state:\n");
	// start at 1 since the current player is 0.
	for (i = 1; i < game->numPlayers; ++i) {
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
		if (i == adventurer)
			assert(game->supplyCount[i] == testGame.supplyCount[i] - 1);
		else
			assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}

	printf("\nTest 3: gain adventurer to hand\n");

	memcpy(&testGame, game, sizeof(struct gameState));

	r = gainCard(adventurer, game, 2, thisPlayer);
	assert(r == 0);

	printf("Checking player's state\n");

	// make sure the appropriate number of cards has been added to the player's hand
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer] + 1);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer] + 1);

	// make sure the cards came from the player's deck
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer]);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer]);

	// check that other players' state hasn't been modified
	printf("\nTesting other players' state:\n");

	// start at 1 since the current player is 0.
	for (i = 1; i < game->numPlayers; ++i) {
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
		if (i == adventurer)
			assert(game->supplyCount[i] == testGame.supplyCount[i] - 1);
		else
			assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}

	printf("\nTest 4: try to gain card not in supply\n");

	game->supplyCount[adventurer] = 0;

	memcpy(&testGame, game, sizeof(struct gameState));


	r = gainCard(adventurer, game, 0, thisPlayer);
	assert(r != 0);

	// make sure the appropriate number of cards has been added to the player's hand
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	// make sure the cards came from the player's deck
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer]);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer]);

	// check that other players' state hasn't been modified

	// start at 1 since the current player is 0.
	for (i = 1; i < game->numPlayers; ++i) {
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

	// check that the victory and kingdom card piles are ok
	for (i = 0; i <= treasure_map; ++i) {
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


	printf("Testing gainCard\n");


	initializeGame(numPlayers, k, seed, &G);


	checkGainCard(&G);



	return 0;
}