//Rick Garnica
//CS 362
//Test:  Adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(int argc, char const *argv[]) {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    int adven[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        adven[i] = adventurer;
    }

	printf("==============================================\r\n");
	printf("\n   Testing Adventurer card:\r\n");
	printf("==============================================\r\n");
 
    for (p = 0; p < numPlayer; p++) {
    	for (handCount = 1; handCount <= maxHandCount; handCount++) {
    		printf("Test %d the adventurer card. Hand size: %d\n", p, handCount);
    		
    		memset(&G, 23, sizeof(struct gameState));   
            r = initializeGame(numPlayer, k, seed, &G);
            G.whoseTurn = p;
            G.handCount[p] = handCount;
            memcpy(G.hand[p], adven, sizeof(int) * handCount);

            r = playCard(0, 0, 0, 0, &G);

            printf("Hand count = %d, %d <= expected <= %d\n", G.handCount[p], handCount - 1, handCount + 1);

            if (G.handCount[p] >= handCount - 1 && G.handCount <= handCount + 1) {
            	printf("The Adventurer card worked correctly\n");
            }
            else {
            	printf("The Adventurer card did not work correctly\n");
            }
    	}
    }

	return 0;
}