#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"

void errorMessage(char *message) {
        printf("ERROR: %s ... TEST FAILED\n", message);
}


void linePrint() {
	printf("\n-------------------------------------------\n");
}


void genericTest(struct gameState G, struct gameState testG, int otherPlayer, int otherDeck){

	int pass = 1;

	// testing blach blach.. PASSED
	//testing blah... FAILED
	//output

	if (testG.handCount[otherPlayer] != G.handCount[otherPlayer] + otherDeck) {
		printf("ERROR: Player 2 hand count = %d, expected = %d\n", testG.handCount[otherPlayer], 
		G.handCount[otherPlayer] + otherDeck);
		pass = 0;
	}
	if (testG.deckCount[otherPlayer] != G.deckCount[otherPlayer]- otherDeck) {
		printf("ERROR: Player 2 deck count = %d, expected = %d\n", testG.deckCount[otherPlayer],
		G.deckCount[otherPlayer] - otherDeck);
		pass = 0;
	} 
	if (testG.supplyCount[estate] != G.supplyCount[estate]) {
		printf("ERROR: State estate count = %d, expected = %d\n", testG.supplyCount[estate], 
		G.supplyCount[estate]);
		pass = 0;
	}
	if (testG.supplyCount[duchy] != G.supplyCount[duchy]) {
		printf("ERROR: State duchy count = %d, expected = %d\n", testG.supplyCount[duchy], 
		G.supplyCount[duchy]);
		pass = 0;
	}
	if (testG.supplyCount[province] != G.supplyCount[province]) {
		printf("ERROR: State province count = %d, expected = %d\n", testG.supplyCount[province], 
		G.supplyCount[province]);
		pass = 0;
	}
	if (testG.supplyCount[copper] != G.supplyCount[copper]) {
		printf("ERROR: State copper count = %d, expected = %d\n", testG.supplyCount[copper], G.supplyCount[copper]);
		pass = 0;
	}
	if (testG.supplyCount[silver] != G.supplyCount[silver]) {
		printf("ERROR: State silver count = %d, expected = %d\n", testG.supplyCount[silver], G.supplyCount[silver]);
		pass = 0;
	}
	if (testG.supplyCount[gold] != G.supplyCount[gold] ) {
		printf("ERROR: State gold count = %d, expected = %d\n", testG.supplyCount[gold], G.supplyCount[gold]);
		pass = 0;
	}
	
	if (pass ==1) {
		printf("SUPPLEMENTARY TESTING COMPLETE\t\n");
	}
}
