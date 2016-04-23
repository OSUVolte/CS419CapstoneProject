#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>


#include "testHelper.h"

#define TESTCARD "shuffle"

int main() {

	int newCards = 0;
	int discarded = 1;
	int newCoins = 0;
	int shuffledCards = 0;
	int a = 0, b = 0, c= 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int otherPlayer = 1;
	int found = 0;

	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	
	initializeGame(numPlayers, k, seed, &G);
	printf("\t Testing Function: %s \n", TESTCARD);

	// boot up the perfect version
	memcpy(&testG, &G, sizeof(struct gameState));
	// Test 01 -----------------------------------------------------------------
	printf("Test 01: Run Shuffle and check positions \n");
	shuffle(thisPlayer, &testG);
	
	// testG.deck[thisPlayer][a]

	printf("Testing Player 1 Deck Size...\t");
	if (testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] ){ 
		printf("ERROR\n");
		printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], 
			G.handCount[thisPlayer] - newCards + shuffledCards);
	} else { 
		printf("PASS\n");
	}

	printf("Testing Player 1 deck integrity...\t");
	// Ensure cards are still in deck
	// sort deck cards into containers
	int GCont[MAX_DECK], testGCont[MAX_DECK];
	while (a < G.deckCount[thisPlayer]) {
		//sort into containers
		GCont[G.deck[thisPlayer][a]]++;
		testGCont[testG.deck[thisPlayer][a]]++;
		a++;
	}
	while(b < MAX_DECK) {
		if (GCont[b] != testGCont[b]) {
			printf("ERROR\n");
			printf("Card %d: count: %d, expected= %d\n", b, testGCont[b], GCont[b]);
			found = 1;
		}
		b++;
	}
	if (found == 0){
		printf("PASS\n");
	}
	printf("Testing Player 1 Hand Size...\t");
	if (testG.handCount[thisPlayer] != G.handCount[thisPlayer] ){ 
		printf("ERROR\n");
		printf("...");
	} else { 
		printf("PASS\n");
	}

	genericTest(G, testG, otherPlayer, 0);
	return 0;
}

