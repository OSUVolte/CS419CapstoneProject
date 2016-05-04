#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkBuyCard(int numPlayers, int supply [], int seed, struct gameState * game) {
	int r, i;
	struct gameState testGame;
	int thisPlayer = whoseTurn(game);

	game->numBuys = 1;


	game->deck[thisPlayer][0] = village;
	game->deck[thisPlayer][1] = copper;
	game->deck[thisPlayer][2] = minion;
	game->deck[thisPlayer][3] = silver;
	game->deck[thisPlayer][4] = village;

	game->hand[thisPlayer][0] = silver;
	game->hand[thisPlayer][1] = copper;
	game->hand[thisPlayer][2] = copper;
	game->hand[thisPlayer][3] = gold;
	game->hand[thisPlayer][4] = village;

	updateCoins(thisPlayer, game, 0);


	memcpy(&testGame, game, sizeof(struct gameState));

	printf("\nTest 1: buying embargo\n");

	r = buyCard(embargo, game);
	assert(r == 0);

	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer] + 1);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);
	
	// make sure card has been added to the player's discard pile
	assert(game->discard[thisPlayer][0] == embargo);

	

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
	for (i = 0; i <= treasure_map; ++i){
		if (i == embargo) {
			printf("Supply count for embargo = %d, expected = %d\n", game->supplyCount[i], testGame.supplyCount[i] - 1);
			assert(game->supplyCount[i] == testGame.supplyCount[i] - 1);
		}
		else
			assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}


	// test on mine

	printf("\nTest 2: buying mine\n");


	game->numBuys = 1;

	game->deck[thisPlayer][0] = village;
	game->deck[thisPlayer][1] = copper;
	game->deck[thisPlayer][2] = minion;
	game->deck[thisPlayer][3] = silver;
	game->deck[thisPlayer][4] = village;

	game->hand[thisPlayer][0] = silver;
	game->hand[thisPlayer][1] = village;
	game->hand[thisPlayer][2] = adventurer;
	game->hand[thisPlayer][3] = gold;
	game->hand[thisPlayer][4] = village;

	updateCoins(thisPlayer, game, 0);

	memcpy(&testGame, game, sizeof(struct gameState));

	r = buyCard(mine, game);
	assert(r == 0);

	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer] + 1);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);

	// make sure card has been added to the player's discard pile
	assert(game->discard[thisPlayer][1] == mine);



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
	for (i = 0; i <= treasure_map; ++i){
		if (i == mine) {
			printf("Supply count for mine = %d, expected = %d\n", game->supplyCount[i], testGame.supplyCount[i] - 1);
			assert(game->supplyCount[i] == testGame.supplyCount[i] - 1);
		}
		else
			assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}


	printf("\nTest 3: attempting to buy adventurer\n");

	// test on adventurer (too expensive)

	game->numBuys = 1;

	game->deck[thisPlayer][0] = village;
	game->deck[thisPlayer][1] = copper;
	game->deck[thisPlayer][2] = minion;
	game->deck[thisPlayer][3] = silver;
	game->deck[thisPlayer][4] = village;

	game->hand[thisPlayer][0] = village;
	game->hand[thisPlayer][1] = village;
	game->hand[thisPlayer][2] = adventurer;
	game->hand[thisPlayer][3] = village;
	game->hand[thisPlayer][4] = village;

	updateCoins(thisPlayer, game, 0);

	memcpy(&testGame, game, sizeof(struct gameState));

	r = buyCard(adventurer, game);
	assert(r != 0);

	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer]);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer]);

	// make sure card has been added to the player's discard pile
	//assert(game->discard[thisPlayer][0] == mine);



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
	for (i = 0; i <= treasure_map; ++i){
			assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}


	// test with numBuys = 0

	printf("\nTest 4: attempting to buy embargo while numBuys = 0\n");


	game->numBuys = 0;


	game->deck[thisPlayer][0] = village;
	game->deck[thisPlayer][1] = copper;
	game->deck[thisPlayer][2] = minion;
	game->deck[thisPlayer][3] = silver;
	game->deck[thisPlayer][4] = village;

	game->hand[thisPlayer][0] = silver;
	game->hand[thisPlayer][1] = copper;
	game->hand[thisPlayer][2] = copper;
	game->hand[thisPlayer][3] = gold;
	game->hand[thisPlayer][4] = village;

	updateCoins(thisPlayer, game, 0);


	memcpy(&testGame, game, sizeof(struct gameState));

	r = buyCard(embargo, game);
	assert(r != 0);

	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

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
	for (i = 0; i <= treasure_map; ++i){
			assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}

	// test with a card that his out of supply

	printf("\nTest 5: attempting to buy a card that is out of supply\n");


	game->numBuys = 1;


	game->deck[thisPlayer][0] = village;
	game->deck[thisPlayer][1] = copper;
	game->deck[thisPlayer][2] = minion;
	game->deck[thisPlayer][3] = silver;
	game->deck[thisPlayer][4] = village;

	game->hand[thisPlayer][0] = silver;
	game->hand[thisPlayer][1] = copper;
	game->hand[thisPlayer][2] = copper;
	game->hand[thisPlayer][3] = gold;
	game->hand[thisPlayer][4] = village;

	game->supplyCount[embargo] = 0;

	updateCoins(thisPlayer, game, 0);


	memcpy(&testGame, game, sizeof(struct gameState));

	r = buyCard(embargo, game);
	assert(r != 0);

	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

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


	printf("Testing buyCard\n");


	initializeGame(numPlayers, k, seed, &G);


	checkBuyCard(numPlayers, k, seed, &G);



	return 0;
}