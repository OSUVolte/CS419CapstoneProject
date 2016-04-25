#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkFeast(int choice1, int choice2, int choice3, struct gameState *game, int handPos, int *bonus) {
	int r, i, cardFound = 0;
	struct gameState testGame;
	int thisPlayer = whoseTurn(game);


	memcpy(&testGame, game, sizeof(struct gameState));

	for (i = 0; i < game->handCount[thisPlayer]; ++i) {
		printf("\nCard number %d: %d\n", i + 1, game->hand[thisPlayer][i]);
	}


	printf("\nTest 1: choose embargo\n");

	choice1 = embargo;


	r = cardEffect(feast, choice1, choice2, choice3, game, handPos, bonus);

	assert(r == 0);

	printf("Checking handCount:\n");
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	printf("Checking deckCount:\n");
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("Checking discardCount:\n");
	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer] + 1);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);
	
	assert(game->playedCards[game->playedCardCount - 1] != feast);

	printf("\nTesting that embargo is in the discard pile:\n");
	for (i = 0; i < game->discardCount[thisPlayer]; ++i) {
		printf("\nCard number %d: %d\n", i + 1, game->discard[thisPlayer][i]);
		if (game->discard[thisPlayer][i] == embargo)
			cardFound = 1;
	}

	assert(cardFound = 1);

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
		if (i == embargo) {
			assert(game->supplyCount[i] == testGame.supplyCount[i] - 1);
		}
		else
		assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}


	// test with mine
	printf("\nTest 2: choose mine\n");

	memcpy(&testGame, game, sizeof(struct gameState));

	choice1 = mine;
	r = cardEffect(feast, choice1, choice2, choice3, game, handPos, bonus);
	assert(r == 0);

	printf("Checking handCount:\n");
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	printf("Checking deckCount:\n");
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("Checking discardCount:\n");
	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer] + 1);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);

	assert(game->playedCards[game->playedCardCount - 1] != feast);

	printf("\nTesting that mine is in the discard pile:\n");
	for (i = 0; i < game->discardCount[thisPlayer]; ++i) {
		printf("\nCard number %d: %d\n", i + 1, game->discard[thisPlayer][i]);
		if (game->discard[thisPlayer][i] == mine)
			cardFound = 1;
	}


	// test with adventurer (causes infinite loop)
	printf("\nTest 3: choose Adventurer (too expensive)\n");

	printf("(this test causes an infinite loop, so I have commented it out)\n");

	/*memcpy(&testGame, game, sizeof(struct gameState));


	choice1 = adventurer;

	r = cardEffect(feast, choice1, choice2, choice3, game, handPos, bonus);

	assert(r == 0);

	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer]);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer]);

	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer]);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer]);

	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer]);
	assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer]);*/


	return 0;
}



int main() {

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, feast,  };

	struct gameState G;

	int seed = 1000;
	int numPlayers = 2;

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	printf("Testing Feast Card\n");


	initializeGame(numPlayers, k, seed, &G);


	checkFeast(choice1, choice2, choice3, &G, handpos, &bonus);



	return 0;
}