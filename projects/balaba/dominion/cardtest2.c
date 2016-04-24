/*
Card test 2: Smithy
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
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    int smy[MAX_HAND];
    int i;
    for (i = 0; i < MAX_HAND; i++)
    {
        smy[i] = smithy;
    }

	printf("==============================================\r\n");
	printf("\n   Beginning testing for card Smithy():\r\n");
	printf("==============================================\r\n");
    for (p = 0; p < numPlayer; p++) {
    	// int x;
    	for (handCount = 0; handCount <= maxHandCount; handCount++) {
    		printf("Test player %d playing Smithy card, hand size: %d\n", p, handCount);
    		
    		memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.whoseTurn = p;
            G.handCount[p] = handCount;
            memcpy(G.hand[p], smy, sizeof(int) * handCount);

            r = playCard(0, 0, 0, 0, &G);

            printf("G.handCount = %d, expected = %d\n", G.handCount[p], handCount + 2);

            if (G.handCount[p] == handCount + 2) {
            	printf("The Smithy card worked correctly\n");
            }
            else {
            	printf("The Smithy card did not work correctly\n");
            }
    	}
    }

	return 0;
}