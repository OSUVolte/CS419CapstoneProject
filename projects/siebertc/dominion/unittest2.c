#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "isGameOver()"

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
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing Game Over: 0 provinces ----------\n");
	if (isGameOver(&testG) == 1) {
		printf("isGameOver TEST#1: PASS when no provinces left.\n");
	}
	else {
		printf("isGameOver TEST#1: FAIL when no provinces left.\n");
	}
	
	G.supplyCount[province] = 10;
	
	//Game will not end if less than 3 supply piles are empty
	G.supplyCount[copper] = 0;
	G.supplyCount[estate] = 0;
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing Not Game Over: 2 empty piles ----------\n");
	if (isGameOver(&testG) == 0) {
		printf("isGameOver TEST#2: PASS when 2 supply piles are empty\n");
	}
	else {
		printf("isGameOver TEST#2: FAIL when 2 supply piles are empty\n");
	}
	
	//Game will end when the third pile is introduced
	G.supplyCount[mine] = 0;
	
	//copy over state
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("\n----------- Testing Game Over: 3 empty piles ----------\n");
	if (isGameOver(&testG) == 1) {
		printf("isGameOver TEST#3: PASS when 3 supply piles are empty\n");
	}
	else {
		printf("isGameOver TEST#3: FAIL when 3 supply piles are empty\n");
	}
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTFUNCTION);
	return 0;
}