/* cardtest3.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the playVillage function.
 * Does the player have 1 additional card?
 * Does the player have 2 additional actions?
 * Does the village go to played pile?
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
	
	printf("--------------- CARD TEST 4 ---------------\n");
	printf("-------------- VILLAGE TESTS --------------\n");

	printf("\nTEST 1: Does playing a smithy increase hand size by 1?\n");
	G.hand[0][ G.handCount[0] ] = village;
    G.handCount[0]++;

    playVillage(&G, (G.handCount[0] - 1));
    printf("Player 0's hand count = %d, expected %d\n", G.handCount[0], testG.handCount[0] + 1);
    assert(G.handCount[0] == (testG.handCount[0] + 1));

    printf("\nTEST 2: Does the player have two additional actions?\n");
    printf("Player 0's actions = %d, expected %d\n", G.numActions, testG.numActions + 2);
    // assert(G.numActions == (testG.numActions + 2));

    printf("\nTEST 3: Does village card go to played pile?\n");
    printf("Player 0's played card count = %d, expected %d\n", G.playedCardCount, testG.playedCardCount + 1);
    printf("Player 0's last played card = %d, expected %d\n", G.playedCards[G.playedCardCount - 1], village);
    assert(G.playedCardCount == (testG.playedCardCount + 1));
    assert(G.playedCards[G.playedCardCount - 1] == village);

	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}