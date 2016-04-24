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

	// testing blach blach.. PASSED
	//testing blah... FAILED
	//output

	printf("Testing Player 2 hand count...\t\t");
	if (testG.handCount[otherPlayer] != G.handCount[otherPlayer] + otherDeck) {
		printf("ERROR\n");
		printf("Player 2 hand count = %d, expected = %d\n", testG.handCount[otherPlayer], 
		G.handCount[otherPlayer] + otherDeck);
	} else {
		printf("PASS\n");
	}

	printf("Testing Player 2 deck count... \t\t");
	if (testG.deckCount[otherPlayer] != G.deckCount[otherPlayer]- otherDeck) {
		printf("ERROR\n");
		printf("Player 2 deck count = %d, expected = %d\n", testG.deckCount[otherPlayer],
		G.deckCount[otherPlayer] - otherDeck);
	} else {
		printf("PASS\n");
	}

	printf("Testing state estate count... \t\t");
	if (testG.supplyCount[estate] != G.supplyCount[estate]) {
		printf("ERROR\n");
		printf("State estate count = %d, expected = %d\n", testG.supplyCount[estate], 
		G.supplyCount[estate]);
	} else {
		printf("PASS\n");
	}

	printf("Testing state duchy count... \t\t");
	if (testG.supplyCount[duchy] != G.supplyCount[duchy]) {
		printf("ERROR\n");
		printf("State duchy count = %d, expected = %d\n", testG.supplyCount[duchy], 
		G.supplyCount[duchy]);
	} else {
		printf("PASS\n");
	}

	printf("Testing state province count...\t\t");
	if (testG.supplyCount[province] != G.supplyCount[province]) {
		printf("ERROR\n");
		printf("State province count = %d, expected = %d\n", testG.supplyCount[province], 
		G.supplyCount[province]);
	} else {
		printf("PASS\n");
	}

	printf("Testing state cppper count... \t\t");
	if (testG.supplyCount[copper] != G.supplyCount[copper]) {
		printf("ERROR\n");
		printf("State copper count = %d, expected = %d\n", testG.supplyCount[copper], G.supplyCount[copper]);
	} else {
		printf("PASS\n");
	}

	printf("Testing state silver count..  \t\t");
	if (testG.supplyCount[silver] != G.supplyCount[silver]) {
		printf("ERROR\n");
		printf("State silver count = %d, expected = %d\n", testG.supplyCount[silver], G.supplyCount[silver]);
	} else {
		printf("PASS\n");
	}

	printf("Testing state gold count... \t\t");
	if (testG.supplyCount[gold] != G.supplyCount[gold] ) {
		printf("ERROR\n");
		printf("State gold count = %d, expected = %d\n", testG.supplyCount[gold], G.supplyCount[gold]);
	} else {
		printf("PASS\n");
	}
}

