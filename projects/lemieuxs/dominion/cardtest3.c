#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkCouncilRoom(int choice1, int choice2, int choice3, struct gameState *game, int handPos, int *bonus) {
	int r, i;
	struct gameState testGame;
	int thisPlayer = whoseTurn(game);

	memcpy(&testGame, game, sizeof(struct gameState));

	r = cardEffect(council_room, choice1, choice2, choice3, game, handPos, bonus);
	assert(r == 0);

	printf("Checking handCount\n");
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer] + 3);
	assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer] + 3);

	printf("Checking deckCount\n");
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer] -4);
	assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer] - 4);

	printf("Checking buys\n");
	printf("buys = %d, expected = %d\n", game->numBuys, testGame.numBuys + 1);
	assert(game->numBuys == testGame.numBuys + 1);


	printf("\nTesting other players' state:\n");
	// start at 1 since the current player is 0.
	for (i = 1; i < game->numPlayers; ++i) {
		printf("\nChecking Player Number %d:\n", i);

		printf("Checking handCount\n");
		printf("hand count = %d, expected = %d\n", game->handCount[i], testGame.handCount[i] + 1);
		assert(game->handCount[i] == testGame.handCount[i] + 1);

		printf("Checking deckCount\n");
		printf("deck count = %d, expected = %d\n", game->deckCount[i], testGame.deckCount[i] - 1);
		assert(game->deckCount[i] == testGame.deckCount[i] - 1);

		printf("Checking discardCount\n");
		printf("discard count = %d, expected = %d\n", game->discardCount[i], testGame.discardCount[i]);
		assert(game->discardCount[i] == testGame.discardCount[i]);
	}

	// check that the victory and kingdom card piles are ok
	for (i = 0; i <= treasure_map; ++i){
		assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}

	// check that the council room card has been added to the played pile
	assert(game->playedCardCount == testGame.playedCardCount + 1);

	return 0;
}



int main() {

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, council_room };


	struct gameState G;

	int seed = 1000;
	int numPlayers = 4;

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	printf("Testing Council Room Card\n");


	initializeGame(numPlayers, k, seed, &G);


	checkCouncilRoom(choice1, choice2, choice3, &G, handpos, &bonus);



	return 0;
}