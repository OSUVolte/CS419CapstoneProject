#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Council Room"

int main() {
	int seed = 1000;
	int player = 1;
	int numPlayers = 2;
	int handPos = 0;
	int i = 0;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
			
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTCARD);
	
	//Card executes
	if (cardCouncilRoom(&G, player, handPos) == 0) {
		printf("cardCouncilRoom TEST#1: PASS Council Room executes without errors.\n");
	}
	else {
		printf("cardCouncilRoom TEST#1: FAIL Council Room executes without errors.\n");
	}
	
	//initializing base state to check values
	for(i = 0; i < numPlayers; i++) {
		G.handCount[i] = 1;
	}
	
	G.numBuys = 0;
	G.playedCardCount = 0;
	cardCouncilRoom(&G, player, handPos);
	
	if (G.numBuys == 1) {
		printf("cardCouncilRoom TEST#2: PASS Council Room - Expected Buys: %d - Result: %d\n", 1, G.numBuys);
	}
	else {
		printf("cardCouncilRoom TEST#2: FAIL Council Room - Expected Buys: %d - Result: %d\n", 1, G.numBuys);
	}
	
	if (G.playedCardCount == 1) {
		printf("cardCouncilRoom TEST#3: PASS Council Room - Expected PlayedCount: %d - Result: %d\n", 1, G.numBuys);
	}
	else {
		printf("cardCouncilRoom TEST#3: FAIL Council Room - Expected PlayedCount: %d - Result: %d\n", 1, G.numBuys);
	}
	
	//other player draws 1 card when played
	if (G.handCount[player -1] == 2) {
		printf("cardCouncilRoom TEST#4: PASS Council Room - Expected Player#2 Cards in Hand: %d - Result: %d\n", 2, G.handCount[player-1]);
	}
	else {
		printf("cardCouncilRoom TEST#4: FAIL Council Room - Expected Player#2 Cards in Hand: %d - Result: %d\n", 2, G.handCount[player-1]);
	}
	
	//current player should have 4 cards left
	if (G.handCount[player] == 4) {
		printf("cardCouncilRoom TEST#5: PASS Council Room - Expected Player#1 Cards in Hand: %d - Result: %d\n", 4, G.handCount[player]);
	}
	else {
		printf("cardCouncilRoom TEST#5: FAIL Council Room - Expected Player#1 Cards in Hand: %d - Result: %d\n", 4, G.handCount[player]);
	}
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTCARD);
	
	return 0;
}