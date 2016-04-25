/* -----------------------------------------------------------------------
 This unit test will test the updateCoins function in dominion.c  
we will test that after the updateCoins function works properly 
Created by James Guerra
 
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
    int j;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, salvager, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int pass =0;

    printf ("TESTING updateCoins function\n"); 
   
            
#if (NOISY_TEST == 1)
				p = 0;
				handCount =0;
                printf("Test player %d with %d card(s) in hand before given salvager and later mine \n", p, handCount);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                gainCard(salvager, &G, 2, p);
				handCount++;
				gainCard(mine, &G, 2, p); //for trading later should be in hand[1]
				handCount++;
                G.coins = 5;
				updateCoins(p, &G,0);

                if(G.coins == 0 ){ // check if the number of coins is correct
					printf("Test 1 passed, expected coins in gamestate \n");                
				}
				else{
					pass = 1;
					printf("Test 1 failed, incorrect coin count \n");
				}
				p =1; //bonus = 1
				gainCard(gold, &G, 2, p);
				gainCard(silver, &G, 2, p);
				updateCoins(p, &G, 1);
				if(G.coins == 6 ){ // check if the number of coins is correct
					printf("Test 2 passed, expected coins in gamestate \n");                
				}
				else{
					pass = 1;
					printf("Test 2 failed, incorrect coin count \n");
				}
       if(pass == 0){
    printf("All tests passed!\n");
	   }
    return 0;
}