#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Village"

int main() {
	int seed = 1000;
	int player = 0;
	int numPlayers = 2;
	int handPos = 0;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
			
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTCARD);
	
	//Card executes
	if (cardVillage(&G, player, handPos) == 0) {
		printf("cardVillage TEST#1: PASS village executes without errors.\n");
	}
	else {
		printf("cardVillage TEST#1: FAIL village executes without errors.\n");
	}
	
	G.playedCardCount = 0;
	G.handCount[player] = 3;
	G.numActions = 0;
	
	
	cardVillage(&G, player, handPos);
	
	if(G.numActions == 2) {
		printf("cardVillage TEST#2: PASS Expected numActions: %d - result: %d\n", 2, G.numActions);
	}
	else {
		printf("cardVillage TEST#2: FAIL Expected numActions: %d - result: %d\n", 2, G.numActions);
	}
	
	if(G.handCount[player] == 1) {
		printf("cardVillage TEST#3: PASS Expected CardHand: %d - result: %d\n", 3, G.handCount[player]);
	}
	else {
		printf("cardVillage TEST#3: FAIL Expected CardHand: %d - result: %d\n", 3, G.handCount[player]);
	}
	
	if(G.playedCardCount == 1) {
		printf("cardVillage TEST#4: PASS Cards Played: %d - result: %d\n", 1, G.playedCardCount);
	}
	else {
		printf("cardVillage TEST#4: FAIL Cards Played: %d - result: %d\n", 1, G.playedCardCount);
	}
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTCARD);
	
	return 0;
}