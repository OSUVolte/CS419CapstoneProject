/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*Unit Test # 1
*updateCoins() 
*Reference:testUpdateCoins.c  
*Test description:
*Calculate the number of player coins for a hand of 5 with copper,silver.gold treasure cards and bonus points 0 to 5 
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
    int maxBonus = 5;
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
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

	handCount=5;
    printf ("Unit Test #1 \n");
    printf ("TESTING updateCoins():\n");
    for (p = 0; p < numPlayer; p++)
    {
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {
                printf("Test player %d with %d COPPER treasure card(s) and %d bonus.\n", p, handCount, bonus);
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                updateCoins(p, &G, bonus);
				if(G.coins==handCount * 1 + bonus)
				{
					printf("PASS:test = %d, expected = %d\n", G.coins, handCount * 1 + bonus);

				}
				else
				{
					printf("FAIL:test = %d, expected = %d\n", G.coins, handCount * 1 + bonus);

				}
                printf("Test player %d with %d SILVER treasure card(s) and %d bonus.\n", p, handCount, bonus);
				memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);
				if(G.coins==handCount * 2 + bonus)
				{
					printf("PASS:test = %d, expected = %d\n", G.coins, handCount * 2 + bonus);

				}
				else
				{
					printf("FAIL:test = %d, expected = %d\n", G.coins, handCount * 2 + bonus);

				}
                printf("Test player %d with %d GOLD treasure card(s) and %d bonus.\n", p, handCount, bonus);
                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);
				if(G.coins==handCount * 3 + bonus)
				{
					printf("PASS:test = %d, expected = %d\n", G.coins, handCount * 3 + bonus);

				}
				else
				{
					printf("FAIL:test = %d, expected = %d\n", G.coins, handCount * 3 + bonus);

				}
            }
    }

    printf("End Unit Test #1\n");

    return 0;
}
