#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "scoreFor()"

void testHand(struct gameState *G) {
	G->handCount[0] = 1;
	G->deckCount[0] = 0;
	G->discardCount[0] = 0;
	
	G->hand[0][0] = curse;
	
	if(scoreFor(0, G) == -1) {
		printf("scoreFor TEST#1: PASS when curse in hand - score: %d.\n", scoreFor(0, G));
	}
	else {
		printf("scoreFor TEST#1: FAIL when curse in hand - score: %d.\n", scoreFor(0, G));
	}
	
	G->hand[0][0] = estate;
	
	if(scoreFor(0, G) == 1) {
		printf("scoreFor TEST#2: PASS when estate in hand - score: %d.\n", scoreFor(0, G));
	}
	else {
		printf("scoreFor TEST#2: FAIL when estate in hand - score: %d.\n", scoreFor(0, G));
	}
	
	G->hand[0][0] = duchy;
	
	if(scoreFor(0, G) == 3) {
		printf("scoreFor TEST#3: PASS when duchy in hand - score: %d.\n", scoreFor(0, G));
	}
	else {
		printf("scoreFor TEST#3: FAIL when duchy in hand - score: %d.\n", scoreFor(0, G));
	}
	
	G->hand[0][0] = province;
	
	if(scoreFor(0, G) == 6) {
		printf("scoreFor TEST#4: PASS when province in hand - score: %d.\n", scoreFor(0, G));
	}
	else {
		printf("scoreFor TEST#4: FAIL when province in hand - score: %d.\n", scoreFor(0, G));
	}
	
	G->hand[0][0] = great_hall;
	
	if(scoreFor(0, G) == 1) {
		printf("scoreFor TEST#5: PASS when great hall in hand - score: %d.\n", scoreFor(0, G));
	}
	else {
		printf("scoreFor TEST#5: FAIL when great hall in hand - score: %d.\n", scoreFor(0, G));
	}
	
	G->hand[0][0] = gardens;
	
	if(scoreFor(0, G) == 0) {
		printf("scoreFor TEST#6: PASS when gardens hall in hand - score: %d.\n", scoreFor(0, G));
	}
	else {
		printf("scoreFor TEST#6: FAIL when gardens in hand - score: %d.\n", scoreFor(0, G));
	}
}

int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
			
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTFUNCTION);
	
	testHand(&G);
	
	G.handCount[0] = 6;
	G.deckCount[0] = 6;
	G.discardCount[0] = 6;
	
	//initialize each value into the hand.
	G.hand[0][0] = curse;
	G.hand[0][1] = estate;
	G.hand[0][2] = duchy;
	G.hand[0][3] = province;
	G.hand[0][4] = great_hall;
	G.hand[0][5] = gardens;

	//initialize each value into the deck
	G.deck[0][0] = curse;
	G.deck[0][1] = estate;
	G.deck[0][2] = duchy;
	G.deck[0][3] = province;
	G.deck[0][4] = great_hall;
	G.deck[0][5] = gardens;
	
	//initialize each value into the discard
	G.discard[0][0] = curse;
	G.discard[0][1] = estate;
	G.discard[0][2] = duchy;
	G.discard[0][3] = province;
	G.discard[0][4] = great_hall;
	G.discard[0][5] = gardens;

	if(scoreFor(0, &G) == 30) {
		printf("scoreFor TEST#7: PASS when game is initialized - score: %d.\n", scoreFor(0, &G));
	}
	else {
		printf("scoreFor TEST#7: FAIL when game is initialized - score: %d.\n", scoreFor(0, &G));
	}
	
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTFUNCTION);
	
	return 0;
}