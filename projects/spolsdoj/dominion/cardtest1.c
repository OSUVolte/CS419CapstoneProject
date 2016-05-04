#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

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

	printf("Testing Smithy\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	//choice1 = 0;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	printf("TEST 1: current player should get three cards\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 3);
	
	printf("TEST 2:  3 cards should come from his pile\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 3);
	
	printf("TEST 3: no state change should occur for other player\n");
	printf("next player deck count = %d, expected = %d\n", testG.handCount[1], G.handCount[1]); 
	
	printf("TEST 4: no state change should occur to the victory pile\n");
	printf("estate count = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate]); 

	//assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 3);
	assert(testG.handCount[1] == G.handCount[1]);
	assert(testG.supplyCount[estate] == G.supplyCount[estate]);

	printf("Test complete.\n");


	return 0;
}

