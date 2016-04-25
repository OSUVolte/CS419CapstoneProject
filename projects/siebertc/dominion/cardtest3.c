#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"

void initDecks(int card, int num, int flag, struct gameState *G) {
	int i = 0;
	for(i = 0; i < num; i++) {
		gainCard(card, G, flag, whoseTurn(G));
	}
}

int main() {
	int seed = 1000;
	int player = 0;
	int numPlayers = 2;
	int tempHand[5];
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
			
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTCARD);
	
	//Card executes
	if (cardAdventurer(&G, player, tempHand) == 0) {
		printf("cardAdventurer TEST#1: PASS Adventurer executes without errors.\n");
	}
	else {
		printf("cardAdventurer TEST#1: FAIL Adventurer executes without errors.\n");
	}
	
	G.deckCount[player] = 3;
	cardAdventurer(&G, player, tempHand);
	
	if(G.deckCount[player] == 1) {
		printf("cardAdventurer TEST#2: PASS Adventurer when drew 2 treasures %d\n", G.deckCount[player]);
	}
	else {
		printf("cardAdventurer TEST#2: FAIL Adventurer when drew 2 treasures %d\n", G.deckCount[player]);
	}
	
	initDecks(gold, 3, 1, &G);
	
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTCARD);
	
	
	
	
	return 0;
}