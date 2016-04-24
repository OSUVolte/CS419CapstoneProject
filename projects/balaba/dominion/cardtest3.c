/*
Card test 3: village
Aleksandr Balab
CS 362 Spring 2016
*/


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
    int p, r, handCount, correctActions;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    // arrays of all smithy
    int vil[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        vil[i] = village;
    }

	printf("==============================================\r\n");
	printf("\n   Beginning testing for card Village():\r\n");
	printf("==============================================\r\n");
 
    for (p = 0; p < numPlayer; p++) {
     	for (handCount = 0; handCount <= maxHandCount; handCount++) {
    		printf("Test player %d playing Village card, hand size: %d\n", p, handCount);
    		
    		memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.whoseTurn = p;
            G.handCount[p] = handCount;
            correctActions = G.numActions + 1;

            memcpy(G.hand[p], vil, sizeof(int) * handCount);

            r = playCard(0, 0, 0, 0, &G);

            printf("G.handCount = %d, expected = %d\n", G.handCount[p], handCount);
            printf("G.numActions = %d, expected = %d\n", G.numActions, correctActions);

            if (G.handCount[p] == handCount && G.numActions == correctActions) {
            	printf("The Village card worked correctly\n");
            }
            else {
            	printf("The Village card did not work correctly\n");
            }
    	}
    }

	return 0;
}