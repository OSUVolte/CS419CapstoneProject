/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

Tests the Smithy card

Tested behavior: The player draws three cards and adds them to his or her hand.
The cards must be drawn from his own deck.  The card is then discarded.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, x,handPos;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int maxHandPos = 5;
    struct gameState T, G;

    /////// Announce testing
    printf("Testing Smithy card:\n");

	for (i = 0; i < numPlayers; i++) {
		for (handPos = 0; handPos < maxHandPos; handPos++) {

			//Clean gamestates
			memset(&T, 23, sizeof(struct gameState));
			memset(&G, 23, sizeof(struct gameState));

			// Initialize game
			x = initializeGame(numPlayers, k, seed, &T);

			// Find current player, draw cards if needed
			T.whoseTurn = i;
			if (i != 0) {
				  for (j = 0; j < 5; j++){
					drawCard(T.whoseTurn, &T);
				  }
			}

			// Copy original game state T into G
			memcpy(&G, &T, sizeof(struct gameState));

            // Play Smithy
			cardEffect(smithy, 0, 0, 0, &G, handPos, 0);

            // Variables for expected values of handc count, played cards, and deck count
            int t1 = (T.handCount[i] + 3);
            int t2 = (T.playedCardCount + 1);
            int t3 = (T.deckCount[i] - 3);

            // Print results
            printf("TEST 1: hand count = %d. Expected result = %d.\n", G.handCount[i], t1);

            // Error message if hand count in G is not expected
			if (G.handCount[i] != t1){
                printf("TEST 1 FAILED!\n");
			}

            // Print results
            printf("TEST 2: played count = %d. Expected result = %d.\n", G.playedCardCount, t2);

			// Error message if there is not one discarded card added to played pile
			if (G.playedCardCount != t2){
                printf("TEST 2 FAILED!\n");
			}

            // Print results
            printf("TEST 3: deck = %d. Expected result = %d.\n", G.deckCount[i], t3);

			// Error message if deck not reduced as expected
			if (G.deckCount[i] != t3){
                printf("TEST 3 FAILED!\n");
			}

			// Print passed message if all tests passed
			if (G.handCount[i] == t1 && G.playedCardCount == t2 && G.deckCount[i] == t3){
                printf("All 3 tests passed!\n");
			}
		}
	}
    return 0;
}
