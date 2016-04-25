/* -----------------------------------------------------------------------
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p, cardCount;
    int deckCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxCardCount = 24;

    printf ("TESTING fullDeckCount():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (cardCount = 1; cardCount <= maxCardCount; cardCount++)
        {
            printf("Testing with player %d and card %d.\n", p, cardCount);
			// Check with 1 cards in each place
			printf("Testing with 1 card in each location.\n");
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.deck[p][0] = cardCount;
			G.deckCount[p] = 1;
			G.hand[p][0] = cardCount;
			G.handCount[p] = 1;
			G.discard[p][0] = cardCount;
			G.discardCount[p] = 1;
			deckCount = fullDeckCount(p, cardCount, &G);
			printf("deckCount = %d, expected = %d\n", deckCount, 3);
			assert(deckCount == 3); // check of count is correct
			
			// Check with 1 cards in 2 places
			printf("Testing with 1 card in both deck and discard.\n");
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.deck[p][0] = cardCount;
			G.deckCount[p] = 1;
			G.handCount[p] = 0;
			G.discard[p][0] = cardCount;
			G.discardCount[p] = 1;
			deckCount = fullDeckCount(p, cardCount, &G);
			printf("deckCount = %d, expected = %d\n", deckCount, 2);
			assert(deckCount == 2); // check of count is correct
			
			// Check with 1 card in 1 places
			printf("Testing with 1 card in just hand.\n");
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.deckCount[p] = 0;
			G.hand[p][0] = cardCount;
			G.handCount[p] = 1;
			G.discardCount[p] = 0;
			deckCount = fullDeckCount(p, cardCount, &G);
			printf("deckCount = %d, expected = %d\n", deckCount, 1);
			assert(deckCount == 1); // check of count is correct
        }
    }

    printf("All tests passed!\n");

    return 0;
}