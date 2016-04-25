#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkSmithy(int choice1, int choice2, int choice3, struct gameState *game, int handPos, int *bonus) {
	int r, i;
	struct gameState testGame;
	int thisPlayer = whoseTurn(game);

	game->hand[thisPlayer][handPos] = smithy;

	memcpy(&testGame, game, sizeof(struct gameState));

	r = cardEffect(smithy, choice1, choice2, choice3, game, handPos, bonus);
	assert(r == 0);

	printf("Checking handCount:\n");
	// make sure the appropriate number of cards has been added to the player's hand
	printf("hand count = %d, expected = %d\n", game->handCount[thisPlayer], testGame.handCount[thisPlayer] + 2);
	//assert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer] + 2);

	printf("Checking deckCount:\n");
	// make sure the cards came from the player's deck
	printf("deck count = %d, expected = %d\n", game->deckCount[thisPlayer], testGame.deckCount[thisPlayer] - 3);
	//assert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer] - 3);

	printf("Checking discardCount:\n");
	// check that this card has been discarded
	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer] + 1);
	//assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 1);

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
		printf("pile %d count = %d, expected = %d\n", i, game->supplyCount[i], testGame.supplyCount[i]);
		assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}

	// check that the card has been added to the played pile
	assert(game->playedCardCount == testGame.playedCardCount + 1);




	return 0;
}



int main() {
	
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	struct gameState G;

	int seed = 1000;
	int numPlayers = 2;

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	printf("Testing Smithy Card\n");


	initializeGame(numPlayers, k, seed, &G);


	checkSmithy(choice1, choice2, choice3, &G, handpos, &bonus);



	return 0;
}