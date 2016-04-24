/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Test for Adventurer
*************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

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

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	//change a card in the player's hand to be adventurer, keep the rest of the card default
	testG.hand[thisPlayer][0] = adventurer;
	testG.hand[thisPlayer][1] = estate;
	testG.hand[thisPlayer][2] = estate;
	testG.hand[thisPlayer][3] = estate;
	testG.hand[thisPlayer][4] = copper;
	testG.deck[thisPlayer][0] = smithy;
	testG.deck[thisPlayer][1] = smithy;
	testG.deck[thisPlayer][2] = copper;
	testG.deck[thisPlayer][3] = copper;
	testG.deck[thisPlayer][4] = copper;

	// Play adventurer
	cardEffect(adventurer, 0, 0, 0, &testG, handpos, 0);

	// Test 1: Verify 2 Cards have been drawn and that they are both copper
	printf("TEST 1: Verify 2 Cards have been drawn\n");

	// Only 1 cards gained in hand, becuase adventurer card is discarded
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1);
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

	// Test 2: Verify they are treasure cards
	printf("TEST 2: Verify they are treasure Cards\n");
	if(testG.hand[thisPlayer][4] == copper && testG.hand[thisPlayer][5] == copper) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

	// Test 3: Verify that the other player's states are the same
	printf("TEST 3: Verify the other player's states have not changed\n");
	for(i = 0; i < numPlayers; i++) {
		if(i != thisPlayer) {

			// Check that all of the cards in the other player's deck are the same
			int curPlayerDeckCount = G.deckCount[i];
			for(j = 0; j < curPlayerDeckCount; j++) {
				if(G.deck[i][j] == testG.deck[i][j]) {
			        printf("SUCCESS\n");
			    }
			    else {
			        printf("FAILURE\n");
    }

			}
			// Check hand
			if(G.handCount == testG.handCount) {
		        printf("SUCCESS\n");
		    }
		    else {
		        printf("FAILURE\n");
		    }
		}
	}

	// Test 4: Verify that the 3 cards came from own pile
	// Assert that other player's decks are the same as before and currentPlayer's deck is decremeted by 3
	printf("TEST 4: Verify treasure cards are from own deck\n");
	for(i = 0; i < G.numPlayers; i++) {
		if(i == thisPlayer) {
			if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] -2) {
		        printf("SUCCESS\n");
		    }
		    else {
		        printf("FAILURE\n");
    }
		}
		// testG and G should be the same for all other players
		else {
			if(testG.deckCount[i] == G.deckCount[i]) {
		        printf("SUCCESS\n");
		    }
		    else {
		        printf("FAILURE\n");
		    }
		}
	}

	// Test 5: Verify that if there are no treasure cards in the player's deck no cards get added to hand
	printf("TEST 4: Test for 0 tresure cards in deck\n");
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	testG.hand[thisPlayer][0] = adventurer;
	testG.hand[thisPlayer][1] = estate;
	testG.hand[thisPlayer][2] = estate;
	testG.hand[thisPlayer][3] = estate;
	testG.hand[thisPlayer][4] = copper;
	testG.deck[thisPlayer][0] = smithy;
	testG.deck[thisPlayer][1] = smithy;
	testG.deck[thisPlayer][2] = smithy;
	testG.deck[thisPlayer][3] = smithy;
	testG.deck[thisPlayer][4] = smithy;

	// Play adventurer
	cardEffect(adventurer, 0, 0, 0, &testG, handpos, 0);
	// Hand count is one less. No cards gained, asdventurer card played.
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] - 1) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

	// Test 6: verify that if there is one treasure card in the player's deck, one card gets added.
	printf("TEST 5: Test for 1 treasure card in deck");
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	testG.hand[thisPlayer][0] = adventurer;
	testG.hand[thisPlayer][1] = estate;
	testG.hand[thisPlayer][2] = estate;
	testG.hand[thisPlayer][3] = estate;
	testG.hand[thisPlayer][4] = copper;
	testG.deck[thisPlayer][0] = smithy;
	testG.deck[thisPlayer][1] = gold;
	testG.deck[thisPlayer][2] = smithy;
	testG.deck[thisPlayer][3] = smithy;
	testG.deck[thisPlayer][4] = smithy;

	// Play adventurer
	cardEffect(adventurer, 0, 0, 0, &testG, handpos, 0);
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] && testG.hand[thisPlayer][4] == gold) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
