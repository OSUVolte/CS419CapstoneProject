/*
Unit test 2: discardCard()
Aleksandr Balab
CS 362 Spring 2016
References: testUpdateCoins.c and cardTest4.c provided by instructor to use as examples and templates
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
    int p, r, d, handCount, playedCount, playedResult, curFlag;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    int cards[MAX_HAND];
    int i;
    for (i = 0; i < MAX_HAND; i++)
    {
        cards[i] = adventurer;
    }
	printf("==============================================\r\n");
	printf("\n   Beginning testing for discardCard():\r\n");
	printf("==============================================\r\n");
    for (p = 0; p < numPlayer; p++) {
    	for(handCount=1; handCount <= maxHandCount; handCount++) {
    		for(playedCount=0; playedCount <= 6; playedCount++) {
    			for(curFlag=0; curFlag < 4; curFlag++) {
    				printf("Test player %d with %d in hand, %d in played, and %d flag\n",p, handCount, playedCount, curFlag);
    				memset(&G, 23, sizeof(struct gameState));
    				r = initializeGame(numPlayer, k, seed, &G);

    				G.handCount[p] = handCount;
    				G.playedCardCount = playedCount;

    				int x;
    				for (x = 0; x < handCount; x++) {
    					G.hand[p][x] = k[x];
    				}
    				for (x = 0; x < playedCount; x++) {
    					G.playedCards[x] = k[x];
    				}

    				d = discardCard(handCount/2, p, &G, curFlag);

    				if (curFlag < 1) {
    					playedResult = playedCount + 1;
    				}
    				else {
    					playedResult = playedCount;
    				}

    				printf("G.handCount = %d, expected = %d\n", G.handCount[p], handCount - 1);
    				printf("G.playedCardCount = %d, expected = %d\n", G.playedCardCount, playedResult);

    				if (G.handCount[p] == handCount - 1 && G.playedCardCount == playedResult) {
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