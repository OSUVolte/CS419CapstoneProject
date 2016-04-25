/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Test for Smithy Card
*************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// Test 1: Verify 3 Cards have been drawn
	printf("TEST 1: Verify 3 Cards have been drawn\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	cardEffect(smithy, 0, 0, 0, &testG, handpos, 0);

	newCards = 2;
	xtraCoins = 0;
	// Only 2 cards gained in hand, becuase smithy card is played
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
	
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 2) {
        printf("SUCCESS\n");
    }
    else {
        printf("FAILURE\n");
    }

	// Test 2: Verify that the 3 cards came from own pile
	// Assert that other player's decks are the same as before and thisPlayer's deck is decremeted by 3
	printf("TEST 2: Verify 3 Cards are from own deck\n");
	for(i = 0; i < G.numPlayers; i++) {
		if(i == thisPlayer) {
			if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] -3) {
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
			if(G.handCount[thisPlayer] == testG.handCount[thisPlayer]) {
					printf("SUCCESS\n");
			}
			else {
				printf("FAILURE\n");
			}

		}
	}



	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
