/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Test for village Card
*************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main() {

    int i, j;
    int handpos = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// Test 1: 1 card has been drawn
	printf("TEST 1: Verify 1 card has been drawn\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(village, 0, 0, 0, &testG, handpos, 0);

	// Change one of the cards in hand to village
	testG.hand[thisPlayer][0] = village;
	// Should have the same number of card in hand before and after card is played
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer]) {
		printf("SUCCESS\n");
	}
	else {
		printf("FAILURE\n");
	}


	// Test 2: Verify that the card came from own pile
	// Assert that other player's decks are the same as before and currentPlayer's deck is decremeted by 1
	printf("TEST 2: Verify card is from own deck and other decks are unchanged\n");
	for(i = 0; i < G.numPlayers; i++) {
		if(i == thisPlayer) {
			if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1) {
				printf("SUCCESS\n");
			}
			else {
				printf("FAILURE\n");
			}

		}
		// testG and G should be the same for all other players
		else {
			if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]) {
				printf("SUCCESS\n");
			}
			else {
				printf("FAILURE\n");
			}
		}
	}

	//Test 3: Verify that 2 actions have been added
	printf("TEST 3: Verify 2 actions have been added\n");
	if(testG.numActions == G.numActions + 1) {
		printf("SUCCESS\n");
	}
	else {
		printf("FAILURE\n");
	}



	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
