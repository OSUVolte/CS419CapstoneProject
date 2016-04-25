/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

Tests Great Hall card

Tested behavior: The player draws one card from his deck and adds it to his hand.
The player also gains an action. The card is discarded after use.
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, k, x, handPos;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	int maxHandPos = 5;
    struct gameState T, G;

    /////// Announce testing
    printf("Testing Great Hall card:\n");

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

            // Play Great Hall
			cardEffect(great_hall, 0, 0, 0, &G, handPos, 0);

            // Variables for expected values of handc count, played cards, and deck count
            int handC = (T.handCount[i] + 1);
            int playedC = (T.playedCardCount + 1);
            int deckC = (T.deckCount[i] - 1);
            int actionsC = (T.numActions[i] + 1);

            // Print results
            printf("TEST 1: hand count = %d. Expected result = %d.\n", G.handCount[i], handC));

            // Error message if hand count unexpected
			if (G.handCount[i] != handC){
                printf("TEST 1 FAILED!\n");
			}

            // Print results
            printf("TEST 2: played count = %d. Expected result = %d.\n", G.playedCardCount, playedC));

			// Error message if played cards unexpected
			if (G.playedCardCount != playedC){
                printf("TEST 2 FAILED!\n");
			}

            // Print results
            printf("TEST 3: deck count= %d. Expected result = %d.\n", G.deckCount[i], deckC));

			// Error message if deck count unexpected
			if (G.deckCount[i] != deckC){
                printf("TEST 3 FAILED!\n");
			}

            // Print results
            printf("TEST 4: number actions = %d. Expected result = %d.\n", G.numActions[i], actionsC));

			// Error message if number of actions unexpected
			if (G.numActions[i] != actionsC){
                printf("TEST 4 FAILED!\n");
			}

			// Print passed message if all tests passed
			if (G.handCount[i] == handC && G.playedCardCount == playedC && G.deckCount[i] == deckC && G.numActions[i] == actionsC){
                printf("All 4 tests passed!\n");
			}
		}
	}
    return 0;
}

