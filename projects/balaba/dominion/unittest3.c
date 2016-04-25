/*
Unit test 3: whoseTurn()
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
    int curPlayer;
    int numPlayer = 2;
    int p, r, turnRes, corRes;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

	printf("==============================================\r\n");
	printf("\n   Beginning testing for whoseTurn():\r\n");
	printf("==============================================\r\n");

    for (p = 0; p < numPlayer; p++)	{
    		for (curPlayer = 0; curPlayer <= numPlayer; curPlayer++) {
    				printf("Testing %d players with player %d's turn\n", p, curPlayer);
    				memset(&G, 23, sizeof(struct gameState));
    				r = initializeGame(p, k, seed, &G);
    				if (curPlayer == numPlayer) {
    					G.whoseTurn = 0;
    				}
    				else {
    					G.whoseTurn = curPlayer;
    				}			

    				turnRes = whoseTurn(&G);
    				if (curPlayer == numPlayer) {
    					corRes = 0;
    					printf("turn =  %d, expected = %d \n", turnRes, corRes);
    				}
    				else {
    					corRes = curPlayer;
    					printf("turn =  %d, expected = %d \n", turnRes, corRes);
					}
    				if (turnRes == corRes) {
    					printf("The turn is correct\n");
    				}
    				else {
    					printf("The turn is not correct\n");
    				}
    		}
    }

	return 0;
}