#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#include "testHelper.h"

#define TESTCARD "Great_Hall"

int main() {
	int newCards = 0;
	int discarded = 1;
	int newCoins = 0;
	int shuffledCards = 0;

	int a, b, c;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int otherPlayer = 1;

	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	
	initializeGame(numPlayers, k, seed, &G);  
	printf("\t Testing Card: %s \n", TESTCARD);
	
	// boot up the perfect version
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Test 01 -----------------------------------------------------------------
	// Coints += $2  Buys +1 
	printf("Test 01: +1 card, +1 action \n");
	
	// setup test environment
	memcpy(&testG, &G, sizeof(struct gameState));	
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

	// Test 01	
	newCoins = 0;
	newCards = 1;
	a = 1;

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], 
		G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], 
		G.handCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + newCoins);
	printf("player actions = %d, expected = %d\n", testG.numActions, G.numActions + 1);
	
	if (testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards- discarded) {
		errorMessage("handCount does not match");
	}
	if (testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){ 
		errorMessage("deckCount does not match");
  	}
	if (testG.coins != G.coins + newCoins) {
		errorMessage("coins do not match");
	}
	if (testG.numActions != (G.numActions + a)) {
		errorMessage("player's actions do not match");
	}	
	
	genericTest(G, testG, otherPlayer, 0);
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

  return 0;
}


