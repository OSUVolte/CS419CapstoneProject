/* -----------------------------------------------------------------------
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int  j;
    int seed = 1000;
    int numPlayer = 2;
    int p, handPos, flag = 1;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int maxHandPos = 5; int handCount;

    printf ("TESTING discardCard():\n");
    for (p = 0; p < numPlayer; p++)
    {
    	handCount = 7;
        for (handPos = 0; handPos <= maxHandPos; handPos++)
        {
        	handCount--;
            for (j = 0; j <= flag; j++)
            {

                printf("Test player %d with %d card(s) and flag %d.\n", p, handPos, j);

                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                memset(&testG, 23, sizeof(struct gameState));   // clear the game state
                initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;
                memcpy(&testG, &G, sizeof (struct gameState));
				
				if( j < 1){
					testG.playedCardCount++;
				}
				testG.handCount[p]--;
				
				assert(discardCard(handPos, p, &G, j) == 0);
				printf("playedCardCount = %d, expected = %d\n", G.playedCardCount, testG.playedCardCount);
				assert(G.playedCardCount == testG.playedCardCount);

				printf("handCount = %d, expected = %d\n", G.handCount[p], testG.handCount[p]);
				assert(G.playedCardCount == testG.playedCardCount);

            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}