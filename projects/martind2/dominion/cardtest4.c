/* cardtest4.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the playCouncil_Room function.
 * Does the player have 4 additional cards?
 * Does the player have 1 additional buy?
 * Do the other players get one card?
 * Does the council room go to played pile?
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
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
	
	printf("--------------- CARD TEST 4 ---------------\n");
	printf("----------- COUNCIL ROOM TESTS ------------\n");

	printf("\nTEST 1: Does playing a council room increase hand size by 3?\n");
	G.hand[0][ G.handCount[0] ] = village;
    G.handCount[0]++;

    playCouncil_Room(&G, (G.handCount[0] - 1));
    printf("Player 0's hand count = %d, expected %d\n", G.handCount[0], testG.handCount[0] + 4);
    assert(G.handCount[0] == (testG.handCount[0] + 4));

    printf("\nTEST 2: Does the player an additional buy?\n");
    printf("Player 0's actions = %d, expected %d\n", G.numBuys, testG.numBuys + 1);
    assert(G.numBuys == (testG.numBuys + 1));

    printf("\nTEST 3: Does each other player get a card?\n");
    for (i=0; i<numPlayers; i++) {
    	if (i != whoseTurn(&G)) {
    		printf("Player %d hand count = %d, expected %d\n", i, G.handCount[i], testG.handCount[i] + 1);
    		assert(G.handCount[i] == (testG.handCount[i] + 1));
    	}
    }

    printf("\nTEST 4: Does council room card go to played pile?\n");
    printf("Player 0's played card count = %d, expected %d\n", G.playedCardCount, testG.playedCardCount + 1);
    printf("Player 0's last played card = %d, expected %d\n", G.playedCards[G.playedCardCount - 1], council_room);
    assert(G.playedCardCount == (testG.playedCardCount + 1));
    assert(G.playedCards[G.playedCardCount - 1] == council_room);

	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}