#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#include "testHelper.h"

#define TESTCARD "smithy"

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
	
	// Smithy Info: cost = +3 cards 	

	// boot up the perfect version
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Test 01 -----------------------------------------------------------------
	// handCount = handCount + 3 (-1, smithy)
	printf("Test 01: handCount = handCount + 3 (-1, smithy) \n");
	
	// setup test environment
	memcpy(&testG, &G, sizeof(struct gameState));	
	printf("initial hand count = %d\n", testG.handCount[thisPlayer]);	
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	newCoins = 0;
	newCards = 3;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.handCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + newCoins);
	
	if (testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards- discarded) {
		errorMessage("handCount does not match");
	}
	if (testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){ 
		errorMessage("deckCount does not match");
  	}
	if (testG.coins != G.coins + newCoins) {
		errorMessage("coins do not match");
	}
	
	genericTest(G, testG, otherPlayer, 0);
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

  return 0;
}


