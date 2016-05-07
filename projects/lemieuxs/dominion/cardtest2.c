#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int checkAdventurer(int choice1, int choice2, int choice3, struct gameState *game, int handPos, int *bonus) {
	int r, i, treasureBefore = 0, treasureAfter = 0;
	struct gameState testGame;
	int thisPlayer = whoseTurn(game);
	int smithyFound = 0, minionFound = 0, adventurerFound = 0;

	game->deck[thisPlayer][0] = village;
	game->deck[thisPlayer][1] = copper;
	game->deck[thisPlayer][2] = minion;
	game->deck[thisPlayer][3] = silver;
	game->deck[thisPlayer][4] = smithy;

	memcpy(&testGame, game, sizeof(struct gameState));

	// keep track of how many treasure cards are in hand before
	for (i = 0; i < game->handCount[thisPlayer]; ++i) {
		//printf("\nCard number %d: %d\n", i + 1, game->hand[thisPlayer][i]);
		if (game->hand[thisPlayer][i] == copper || game->hand[thisPlayer][i] == silver || game->hand[thisPlayer][i] == gold)
			treasureBefore++;
	}

	printf("Treasures in hand before playing Adventurer: %d\n", treasureBefore);

	r = cardEffect(adventurer, choice1, choice2, choice3, game, handPos, bonus);
	assert(r == 0);

	printf("handcount: %d\n", game->handCount[thisPlayer]);
	printf("deckcount: %d\n", game->deckCount[thisPlayer]);
	
	printf("Checking +2 treasure:\n");
	// check that there are two more treasure in hand than there were before
	for (i = 0; i < game->handCount[thisPlayer]; ++i) {
		if (game->hand[thisPlayer][i] == copper || game->hand[thisPlayer][i] == silver || game->hand[thisPlayer][i] == gold)
			treasureAfter++;
	}

	printf("Treasures in hand after: %d\n", treasureAfter);
	//assert(treasureBefore + 2 == treasureAfter);


	printf("Checking discardCount:\n");
	printf("discard count = %d, expected = %d\n", game->discardCount[thisPlayer], testGame.discardCount[thisPlayer] + 2);
	//assert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer] + 2);

	printf("Checking that a smithy and village are in the discard pile:\n");
	// check that the discard pile contains a smithy and a village
	for (i = 0; i < game->discardCount[thisPlayer]; ++i) {
		printf("Discarded card: %d\n", game->discard[thisPlayer][i]);
		if (game->discard[thisPlayer][i] == minion)
			minionFound = 1;
		else if (game->discard[thisPlayer][i] == village)
			smithyFound = 1;
	}

	//assert(minionFound == 1);
	//assert(smithyFound == 1);

	// check that the adventurer card has been discarded
	printf("Checking that Adventurer has been discarded:\n");
	printf("Played cards: %d\n", game->playedCardCount);

	for (i = 0; i < game->playedCardCount; ++i) {
		if (game->playedCards[i] == adventurer)
			adventurerFound = 1;
	}

	//assert(adventurerFound == 1);

	printf("\nTesting other players' state:\n");

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

	printf("\nTesting victory and kingdom cards:\n");
	// check that the victory and kingdom card piles are ok
	for (i = 0; i <= treasure_map; ++i){
		assert(game->supplyCount[i] == testGame.supplyCount[i]);
	}

	// check that the card has been added to the played pile
	//assert(game->playedCardCount == testGame.playedCardCount + 1);

	return 0;
}



int main() {

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };


	struct gameState G;

	int seed = 1000;
	int numPlayers = 2;

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	printf("Testing Adventurer Card\n");

	initializeGame(numPlayers, k, seed, &G);


	checkAdventurer(choice1, choice2, choice3, &G, handpos, &bonus);



	return 0;
}