#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "updateCoins()"

int main() {
	int seed = 1000;
	int numPlayers = 2;
	int i = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
			
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTFUNCTION);
	
	//starting hand amount
	G.handCount[1] = 5;
	
	//initialize a hand of no coins
	for(i = 0; i < G.handCount[1]; i++) {
		G.hand[1][i] = k[0];
	}
	
	updateCoins(1, &G, 0);
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	if (testG.coins == 0) {
		printf("updateCoins TEST#1: PASS when no coins in hand.\n");
	}
	else {
		printf("updateCoins TEST#1: FAIL when no coins in hand.\n");
	}
	
	//testing mixed cards to count
	G.hand[1][0] = copper;
	G.hand[1][1] = silver;
	G.hand[1][2] = gold;
	G.hand[1][3] = estate;
	G.hand[1][4] = silver;
	
	updateCoins(1, &G, 0);
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing 1 copper, 2 silver, 1 gold ----------\n");
	if (testG.coins == 8) {
		printf("updateCoins TEST#2: PASS - expected: 8 - actual: %d.\n", testG.coins);
	}
	else {
		printf("updateCoins TEST#2: FAIL - expected: 8 - actual: %d.\n", testG.coins);
	}
	
	//Testing Copper value
	for(i = 0; i < G.handCount[1]; i++) {
		G.hand[1][i] = copper;
	}
	
	updateCoins(1, &G, 0);
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------------- Testing 5 copper ----------------\n");
	if (testG.coins == 5) {
		printf("updateCoins TEST#3: PASS - expected: 5 - actual: %d.\n", testG.coins);
	}
	else {
		printf("updateCoins TEST#3: FAIL - expected: 5 - actual: %d.\n", testG.coins);
	}
	
	//Testing Silver value
	for(i = 0; i < G.handCount[1]; i++) {
		G.hand[1][i] = silver;
	}
	
	updateCoins(1, &G, 0);
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	
	printf("\n----------------- Testing 5 silver ----------------\n");
	if (testG.coins == 10) {
		printf("updateCoins TEST#4: PASS - expected: 10 - actual: %d.\n", testG.coins);
	}
	else {
		printf("updateCoins TEST#4: FAIL - expected: 10 - actual: %d.\n", testG.coins);
	}
	
	//Testing Gold value
	for(i = 0; i < G.handCount[1]; i++) {
		G.hand[1][i] = gold;
	}
	
	updateCoins(1, &G, 0);
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------------- Testing 5 gold ----------------\n");
	if (testG.coins == 15) {
		printf("updateCoins TEST#5: PASS - expected: 15 - actual: %d.\n", testG.coins);
	}
	else {
		printf("updateCoins TEST#5: FAIL - expected: 15 - actual: %d.\n", testG.coins);
	}
	
	//Testing Bonus value
	for(i = 0; i < G.handCount[1]; i++) {
		G.hand[1][i] = copper;
	}
	
	updateCoins(1, &G, 10);
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n------------- Testing 10 bonus + 5 copper ------------\n");
	if (testG.coins == 15) {
		printf("updateCoins TEST#6: PASS - expected: 15 - actual: %d.\n", testG.coins);
	}
	else {
		printf("updateCoins TEST#6: FAIL - expected: 15 - actual: %d.\n", testG.coins);
	}
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTFUNCTION);
	return 0;
}