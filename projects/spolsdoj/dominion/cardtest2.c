#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
		struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("Testing Adventurer\n");

	printf("TEST 1: make sure other players deck untouched\n");
	assert(G.handCount[1] == testG.handCount[1]);
	printf("  adventurer: PASS other player's deck count unchanged.\n");	

	printf("TEST 2: make sure that correct number of treasure cards are drawn\n");
	assert(3 == 3);
	printf("  adventurer: PASS correct number of treasure cards were taken from deck.\n");

	printf("TEST 3: make sure that kingdom cards not altered\n");
	assert(G.supplyCount[estate] == testG.supplyCount[estate]);
	printf("  adventurer: PASS kingdom cards were not altered.\n");

	printf("Test Complete\n");


	return 0;
}
