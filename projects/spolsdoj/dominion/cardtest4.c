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

	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("Testing Village\n");

	printf("TEST 1: make sure that only one card is drawn\n");
	assert(G.handCount[thisPlayer] == testG.handCount[thisPlayer]);
	printf("  village: PASS only one card drawn.\n");	

	printf("TEST 2: make sure that the card is drawn from the correct players deck\n");
	assert(G.handCount[1] == testG.handCount[1]);
	printf("  village: PASS other player's deck count unchanged.\n");	

	printf("TEST 3: make sure the correct number of action points are calculted\n");
	assert(G.numActions + 2 == testG.numActions);
	printf("  village: PASS other player's deck count unchanged.\n");

	printf("Test Complete\n");

	return 0;
}