#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "gainCard()"

int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
			
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTFUNCTION);
	
	//sets province supply count to 0, game should always end.
	G.supplyCount[province] = 0;
	G.deckCount[0] = 0;
	G.handCount[0] = 0;
	G.discardCount[0] = 0;
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing Empty Pile: 0 provinces ----------\n");
	if (gainCard(province, &testG, 0, 0) == -1) {
		printf("isGameOver TEST#1: PASS when no provinces left.\n");
	}
	else {
		printf("isGameOver TEST#1: FAIL when no provinces left.\n");
	}
	
	//Testing GainCard to Deck
	G.supplyCount[province] = 10;
	gainCard(province, &G, 1, 0);
	
	//Copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing GainCard to Deck----------\n");
	if (testG.deckCount[0] == 1) {
		printf("isGameOver TEST#2: PASS when card added to deck - total %d\n", testG.deckCount[0]);
	}
	else {
		printf("isGameOver TEST#2: FAIL when card added to deck - total %d\n", testG.deckCount[0]);
	}
	
	//Testing GainCard to Hand
	gainCard(province, &G, 2, 0);
	
	//Copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing GainCard to Hand----------\n");
	if (testG.deckCount[0] == 1) {
		printf("isGameOver TEST#3: PASS when card added to hand - total %d\n", testG.handCount[0]);
	}
	else {
		printf("isGameOver TEST#3: FAIL when card added to hand - total %d\n", testG.handCount[0]);
	}
	
	//Testing GainCard to Discard
	gainCard(province, &G, 0, 0);
	
	//Copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing GainCard to Discard----------\n");
	if (testG.discardCount[0] == 1) {
		printf("isGameOver TEST#4: PASS when card added to discard - total %d\n", testG.discardCount[0]);
	}
	else {
		printf("isGameOver TEST#4: FAIL when card added to discard - total %d.\n", testG.discardCount[0]);
	}
	
	//Testing Reduce supplyCount
	printf("\n----------- Testing Reduce supplyCount----------\n");
	if (testG.supplyCount[province] == 7) {
		printf("isGameOver TEST#5: PASS when province was gained each previous time - total %d\n", testG.supplyCount[province]);
	}
	else {
		printf("isGameOver TEST#5: FAIL when province was gained each previous time - total %d\n", testG.supplyCount[province]);
	}
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTFUNCTION);
	
	return 0;
}
	