/* -----------------------------------------------------------------------
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 6;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING updateCoins():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {

                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);

                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                updateCoins(p, &G, bonus);

                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);

                assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);

                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);

                assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);

                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);

                assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct

                /*Combination of cards */

                if((handCount % 2) == 0){
                	memcpy(G.hand[p], golds, sizeof(int) * handCount/2); // set half cards to gold
                	memcpy(G.hand[p] + handCount/2, silvers, sizeof(int) * handCount/2); // set half cards to silvers
                	updateCoins(p, &G, bonus);

                	printf("G.coins = %d, expected = %d\n", G.coins, (handCount/2) * 3 + (handCount/2) * 2 + bonus);
                	assert(G.coins == (handCount/2) * 2 + (handCount/2) * 3 + bonus); // check if the number of coins is correct
                }

                if((handCount % 3) == 0){
                	memcpy(G.hand[p], golds, sizeof(int) * handCount/3); // set 1/3 cards to gold
                	memcpy(G.hand[p] + handCount/3, coppers, sizeof(int) * handCount/3); // set 1/3 cards to copper
                	memcpy(G.hand[p] + handCount/3 + handCount/3, silvers, sizeof(int) * handCount/3); // set 1/3 cards to silver
                	updateCoins(p, &G, bonus);

                	printf("G.coins = %d, expected = %d\n", G.coins, (handCount/3) * 3 + (handCount/3) * 1 + (handCount/3) * 2 + bonus);
                	assert(G.coins == (handCount/3) * 3 + (handCount/3) * 1 + (handCount/3) * 2 + bonus); // check if the number of coins is correct
                }
            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}