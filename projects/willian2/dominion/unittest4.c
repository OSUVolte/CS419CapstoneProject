/******************************************************************************
* ASSIGNMENT 3 - unittest4.c
* AUTHOR: Nickolas A. Williams
* CLASS: CS362
* DATE: 04/24/2016
* NOTES: unit testing of the updateCoins() function
* REQUIREMENTS for updateCoins():
*  1. Add coins for each treasure card in hand
*  2. Add bonus to coin count if passed in
* TESTING tasks for updateCoins():
*  1. Test that correct values are given for treasure cards
*  2. Test that correct bonus value is added for bonus value
*  3. Test that coins are provided to the correct player from their hand
*  4. Test edge cases: negative bonuses, varied treasure types, no treasures
* CREDITS: Provided by the instructor as an example and template, I added
*     additional tests at the end for more examples
******************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
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
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
	
	//no treasure hand
	int noTreasures[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		noTreasures[i] = adventurer;
	}
	
	int oneOfEach[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		if (i % 3 == 0)
		{
			oneOfEach[i] = copper;
		}
		if (i % 3 == 1)
		{
			oneOfEach[i] = silver;
		}
		if (i % 3 == 2)
		{
			oneOfEach[i] = gold;
		}
	}

    printf ("TESTING updateCoins():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (bonus = -10; bonus <= maxBonus; bonus++)
            {
#if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
#endif
                assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
#endif
                assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct

                memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
#endif
                assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct


				memcpy(G.hand[p], noTreasures, sizeof(int) * handCount); // set all the cards adventurer
				updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("No treasures, G.coins = %d, expected = %d\n", G.coins, bonus);
#endif				
				
				int expectedTotal = 0;
				int q;
				for (q = 0; q < handCount; q++)
				{
					if (q % 3 == 0)
					{
						expectedTotal = expectedTotal + 1;
					}
					if (q % 3 == 1)
					{
						expectedTotal = expectedTotal + 2;
					}
					if (q % 3 == 2)
					{
						expectedTotal = expectedTotal + 3;
					}
				}
				expectedTotal = expectedTotal + bonus;
				memcpy(G.hand[p], oneOfEach, sizeof(int) * handCount); // set to one of each treasure type
				updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                printf("G.coins = %d, expected = %d\n", G.coins, expectedTotal);
#endif
            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}
