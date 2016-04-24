/* unittest3.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the endTurn function.
 * - Does the player's hand get discarded?
 * - Is it the player + 1's turn?
 * - If player is last, does current player loop?
 * - Does new player have 5 cards?
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
	// Game settings
	int seed = 1000,
		numPlayers = 2,
		cards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
					  sea_hag, tribute, smithy, council_room };

	// Game init
	struct gameState G, testG;
	initializeGame(numPlayers, cards, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("--------------- UNIT TEST 3 ---------------\n");
	printf("----------- IS GAME OVER TESTS ------------\n");

	printf("\nTEST 1: Does player 0's hand get discarded?\n");
	endTurn(&G);
	printf("G.handCount[0] = %d, expected 0\n", G.handCount[0]);
	assert(G.handCount[0] == 0);

	printf("\nTEST 2: Is it the next player's turn (1)?\n");
	printf("G.whoseTurn = %d, expected 1\n", G.whoseTurn);
	assert(G.whoseTurn == 1);

	printf("\nTEST 3: If player is last, does turn loop back to zero?\n");
	endTurn(&G);
	printf("G.whoseTurn == %d, expected 0\n", G.whoseTurn);
	assert(G.whoseTurn == 0);

	printf("\nTEST 4: Does current player have 5 cards?\n");
	printf("Current player hand count = %d, expected 5\n", G.handCount[G.whoseTurn]);
	assert(G.handCount[G.whoseTurn] == 5);

	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}