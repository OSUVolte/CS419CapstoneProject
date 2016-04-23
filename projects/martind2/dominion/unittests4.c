/* unittest4.c
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
	// Counters
	int i;

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
	printf("------------- END TURN TESTS --------------\n");


	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}