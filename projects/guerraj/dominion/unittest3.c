/* -----------------------------------------------------------------------
 This unit test will test the getCost function in dominion.c  
we will test that after the getCost function works properly 
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
    
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, salvager, great_hall};
    struct gameState G;
    
    int pass =0;

    printf ("TESTING getCost function\n"); 
   
				p = 0;
				handCount =0;
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                gainCard(salvager, &G, 2, p);
				handCount++;
				gainCard(mine, &G, 2, p); //for trading later should be in hand[1]
				handCount++;
				int x = getCost(G.hand[p][0]);
				
                if(x == 4){ // check if the card value is correct
					printf("Test 2 passed, Card has correct value returned by function. \n");                
				}
				else{
					pass = 1;
					printf("Test 1 failed, incorect value returned by function \n");
				}
				gainCard(gold, &G, 2, p);
				gainCard(silver, &G, 2, p);
				x = getCost(G.hand[p][2]);
				if(x == 6){ // check if the player has actions remaining
					printf("Test 2 passed, Card has correct value returned by function. \n");                
				}
				else{
					pass = 1;
					printf("Test 2 failed, incorect value returned by function \n");
				}
				
       if(pass == 0){
    printf("All tests passed!\n");
	   }
    return 0;
}