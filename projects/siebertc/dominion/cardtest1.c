#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Smithy"

int main() {
	int seed = 1000;
	int player = 1;
	int numPlayers = 2;
	int handPos = 0;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
			
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTCARD);
	
	//Card executes
	if (cardSmithy(&G, player, handPos) == 0) {
		printf("cardSmithy TEST#1: PASS smithy executes without errors.\n");
	}
	else {
		printf("cardSmithy TEST#1: FAIL smithy executes without errors.\n");
	}

	//draw cards, discard smithy played
	G.handCount[player] = 3;
	cardSmithy(&G, player, handPos);
	if(G.handCount[player] == 5) {
		printf("cardSmithy TEST#2: PASS Expected HandSize: %d - Result %d\n", 5, G.handCount[player]);
	}
	else {
		printf("cardSmithy TEST#2: FAIL Expected HandSize: %d - Result %d\n", 5, G.handCount[player]);
	}
	
	G.playedCardCount = 0;
	cardSmithy(&G, player, handPos);
	if(G.playedCardCount == 1) {
		printf("cardSmithy TEST#3: PASS Expected PlayedCount: %d - Result %d\n", 1, G.playedCardCount);
	}
	else {
		printf("cardSmithy TEST#3: FAIL Expected PlayedCount: %d - Result %d\n", 1, G.playedCardCount);
	}
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTCARD);
	
	return 0;
}