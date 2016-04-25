//Unit test 4: discardCard()
//Rick Garnica
//CS 362

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(int argc, char const *argv[]) {
    int seed = 1000;
    int numPlayer = 2;
    int p, r, d, handCount, playedCount, playedResult, curFlag;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
    int maxHandCount = 5;

    int cards[MAX_HAND];
    int i;
    for (i = 0; i < MAX_HAND; i++)
    {
        cards[i] = adventurer;
    }
	printf("==============================================\r\n");
	printf("\n   Testing for discardCard:\r\n");
	printf("==============================================\r\n");
    for (p = 0; p < numPlayer; p++) {
    	for(handCount=1; handCount <= maxHandCount; handCount++) {
    		for(playedCount=0; playedCount <= 6; playedCount++) {
    			for(curFlag=0; curFlag < 4; curFlag++) {
    				printf("Test player %d with %d in hand, %d in played, and %d flag\n",p, handCount, playedCount, curFlag);
    				memset(&game, 23, sizeof(struct gameState));
    				r = initializeGame(numPlayer, k, seed, &game);

    				game.handCount[p] = handCount;
    				game.playedCardCount = playedCount;

    				int x;
    				for (x = 0; x < handCount; x++) {
    					game.hand[p][x] = k[x];
    				}
    				for (x = 0; x < playedCount; x++) {
    					game.playedCards[x] = k[x];
    				}

    				d = discardCard(handCount/2, p, &game, curFlag);

    				if (curFlag < 1) {
    					playedResult = playedCount + 1;
    				}
    				else {
    					playedResult = playedCount;
    				}

    				printf("game.handCount = %d, should be = %d\n", game.handCount[p], handCount - 1);
    				printf("game.playedCardCount = %d, should be = %d\n", game.playedCardCount, playedResult);

    				if (game.handCount[p] == handCount - 1 && game.playedCardCount == playedResult) {
    					printf("The counts are correct\n");
    				}
    				else {
    					printf("The counts are not correct\n");
    				}

    			}
    		}
    	}
    
    }

	return 0;
}