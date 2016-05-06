/* -----------------------------------------------------------------------
 * Martha Gebremariam
 * CS352_SPRING2016
 * Descrirption: Unit test for updateCoin() function in dominion.c
 * It will test all treasure card combinations  
 *
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

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
    int c, s, g;
    int passedTest=0;
    int failedTest=0;
    printf("\n\n*************************\n");
    printf ("TESTING updateCoins()\n");
    printf("*************************\n\n");
    //int coins[MAX_HAND]={0};
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
	    for (bonus = 0; bonus <= maxBonus; bonus++)
            {
 		int coins[MAX_HAND]={0};
                // array of coins with various combinations of copper, silver, gold, and non-treasure coins
                for(c=0; c<=handCount; c++){
		    int coins[MAX_HAND]={0};
		    for (s=0; s<=handCount-c; s++){
			int coins[MAX_HAND]={0};
                        for(g=0; g<=handCount-c-s; g++){
                            //int coins[MAX_HAND]={0};
                            int nonTreasure=handCount-c-s-g;
                            printf("Test player %d with %d card(s) (%d copper, %d silver, %d gold, and %d non-treasure card(s)) and %d bonus.\n", p, handCount, c, s, g, nonTreasure, bonus);
                            memset(&G, 0, sizeof(struct gameState));   // clear the game state
                            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                            G.handCount[p] = handCount;                 // set the number of cards on hand
                            int expectedValue=0;                        //initialize expected value
                                for (i = 0; i<c; i++){
                                    coins[i]= copper;
                                    expectedValue=expectedValue+1;      //add 1 coin for each copper card
                                }
                                    
                                for (i=c; i<c+s; i++){
                                    coins[i]= silver;
                                    expectedValue=expectedValue+2;      //add 2 coins for each silver card
                                }    
                                    
                                for (i=c+s; i<c+s+g; i++){
                                    coins[i]= gold;
                                    expectedValue=expectedValue+3;      //add 3 coins for each gold card
                                }
                                    
                            memcpy(G.hand[p], coins, sizeof(int) * handCount); // set all the cards to copper
                            updateCoins(p, &G, bonus);
			                printf("G.coins = %d, expected = %d\n", G.coins, expectedValue + bonus);
                            // check if the number of coins is correct
                            if(G.coins == expectedValue + bonus){
                                printf("Passed test\n");
                                passedTest++;
                            }
                                
                            else{
                                printf("failed test\n");
                                failedTest++;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Passed %d and failed %d of the unittest1 tests\n", passedTest, failedTest);
    return 0;
}
