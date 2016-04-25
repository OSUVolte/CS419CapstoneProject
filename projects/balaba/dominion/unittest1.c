/*
Unit test 1: updateCoins()
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
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

	printf("==============================================\r\n");
	printf("\n   Beginning testing for testUpdateCoins():\r\n");
	printf("==============================================\r\n");

    for (p = 0; p < numPlayer; p++) {
        for (handCount = 1; handCount <= maxHandCount; handCount++) {
            for (bonus = 0; bonus <= maxBonus; bonus++) {
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
				// clear the game state
                memset(&G, 23, sizeof(struct gameState)); 
				// initialize a new game
                r = initializeGame(numPlayer, k, seed, &G); 
				// set the number of cards on hand
                G.handCount[p] = handCount;       
				// set all the cards to copper
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
                updateCoins(p, &G, bonus);

                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
                if (G.coins == handCount * 1 + bonus) {
                	printf("Number of coins is correct\n");
                } // check if the number of coins is correct
                else {
                	printf("Number of coins is not correct\n");
                }
				// set all the cards to silver
                memcpy(G.hand[p], silvers, sizeof(int) * handCount);  
                updateCoins(p, &G, bonus);

				// check if the number of coins is correct
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
                if (G.coins == handCount * 2 + bonus){
                	printf("Number of coins is correct\n");
                }
                else {
                	printf("Number of coins is not correct\n");
                }
				// set all the cards to gold
                memcpy(G.hand[p], golds, sizeof(int) * handCount); 
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
                if (G.coins == handCount * 3 + bonus){
                	printf("Number of coins is correct\n");
                } // check if the number of coins is correct
                else {
                	printf("Number of coins is not correct\n");
                }
            }
        }
    }

	return 0;
}