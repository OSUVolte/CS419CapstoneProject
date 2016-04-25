//Rick Garnica
//CS 362
//Test:  Smithy card

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
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
    int maxHandCount = 5;

    int smith_card[MAX_HAND];
    int i;
    for (i = 0; i < MAX_HAND; i++)
    {
        smith_card[i] = smithy;
    }

	printf("==============================================\r\n");
	printf("\n   Testing Smithy card:\r\n");
	printf("==============================================\r\n");
    for (p = 0; p < numPlayer; p++) {
    	
    	for (handCount = 0; handCount <= maxHandCount; handCount++) {
    		printf("Test player %d playing Smithy card, hand size: %d\n", p, handCount);
    		
    		memset(&game, 23, sizeof(struct gameState));   
            r = initializeGame(numPlayer, k, seed, &game); 
            game.whoseTurn = p;
            game.handCount[p] = handCount;
            memcpy(game.hand[p], smith_card, sizeof(int) * handCount);

            r = playCard(0, 0, 0, 0, &game);

            printf("Hand count = %d, expected = %d\n", game.handCount[p], handCount + 2);

            if (game.handCount[p] == handCount + 2) {
            	printf("The Smithy card worked correctly\n");
            }
            else {
            	printf("The Smithy card did not work correctly\n");
            }
    	}
    }

	return 0;
}