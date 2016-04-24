#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#include "testHelper.h"

#define TESTCARD "updateCoinst"

int main() {

	int newCards = 0;
	int discarded = 1;
	int newCoins = 0;
	int shuffledCards = 0;
	int bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int otherPlayer = 1;
	int a = 0;

	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	
	initializeGame(numPlayers, k, seed, &G);
	// set hand to estates:
	printf("handCount: %d\n", G.handCount[thisPlayer]);
	while (a < 5) {
		G.hand[thisPlayer][a] = estate;
		a++;
	}
	updateCoins(thisPlayer, &G, 0);

	printf("\t Testing Card: %s \n", TESTCARD);
	// boot up the perfect version
	memcpy(&testG, &G, sizeof(struct gameState));


//int updateCoins(int player, struct gameState *state, int bonus)

	// Test 01 -----------------------------------------------------------------
	linePrint();
	printf("Test 01: one copper to hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newCoins = 1;
	testG.hand[thisPlayer][0] = copper;
	updateCoins(thisPlayer, &testG, 0);
	
	printf("Testing coin with one copper in hand...\t");
	if (testG.coins != (G.coins + newCoins)) {
		printf("ERROR\n");
		printf("Player coins: %d, expected: %d\n", testG.coins, (G.coins + newCoins));
	} else {
		printf("PASS\n");
	}
	genericTest(G, testG, otherPlayer, 0);

	// Test 02 -----------------------------------------------------------------
	linePrint();
	printf("Test 02: one silver to hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newCoins = 2;
	testG.hand[thisPlayer][0] = silver;
	updateCoins(thisPlayer, &testG, 0);
	
	printf("Testing coin with one silver in hand...\t");
	if (testG.coins != (G.coins + newCoins)) {
		printf("ERROR\n");
		printf("Player coins: %d, expected: %d\n", testG.coins, (G.coins + newCoins));
	} else {
		printf("PASS\n");
	}
	genericTest(G, testG, otherPlayer, 0);


	// Test 03 -----------------------------------------------------------------
	linePrint();
	printf("Test 03: one gold to hand\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newCoins = 3;
	testG.hand[thisPlayer][0] = gold;
	updateCoins(thisPlayer, &testG, 0);
	
	printf("Testing coin with one silver in hand...\t");
	if (testG.coins != (G.coins + newCoins)) {
		printf("ERROR\n");
		printf("Player coins: %d, expected: %d\n", testG.coins, (G.coins + newCoins));
	} else {
		printf("PASS\n");
	}
	genericTest(G, testG, otherPlayer, 0);

	// Test 04 -----------------------------------------------------------------
	linePrint();
	printf("Test 04: one gold to hand and -1 bonus\n");
	memcpy(&testG, &G, sizeof(struct gameState));

	newCoins = 3;
	bonus = -1;
	testG.hand[thisPlayer][0] = gold;
	updateCoins(thisPlayer, &testG, bonus);
	
	printf("Testing coin with one silver in hand...\t");
	if (testG.coins != (G.coins + newCoins + bonus)) {
		printf("ERROR\n");
		printf("Player coins: %d, expected: %d\n", testG.coins, (G.coins + newCoins + bonus));
	} else {
		printf("PASS\n");
	}
	genericTest(G, testG, otherPlayer, 0);






	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}




