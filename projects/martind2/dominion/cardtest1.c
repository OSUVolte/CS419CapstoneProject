/* cardtest1.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the playSmithy function.
 * - Does playing a smithy increase hand size by 3?
 * - Does smithy go to played cards?
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
	printf("--------------- SMITHY TESTS --------------\n");

	printf("\nTEST 1: Does playing a smithy increase hand size by 3?\n");
	G.hand[0][ G.handCount[0] ] = smithy;
    G.handCount[0]++;

    playSmithy(&G, (G.handCount[0] - 1));
    printf("Player 0's hand count = %d, expected %d\n", G.handCount[0], testG.handCount[0] + 3);
    assert(G.handCount[0] == (testG.handCount[0] + 3));

    printf("\nTEST 2: Does smithy card go to played pile?\n");
    printf("Player 0's played card count = %d, expected %d\n", G.playedCardCount, testG.playedCardCount + 1);
    printf("Player 0's last played card = %d, expected %d\n", G.playedCards[G.playedCardCount - 1], smithy);
    assert(G.playedCardCount == (testG.playedCardCount + 1));
    assert(G.playedCards[G.playedCardCount - 1] == smithy);

	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}