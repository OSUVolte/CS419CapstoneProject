/* -----------------------------------------------------------------------
 This unit test will test the scoreFor function in dominion.c  
we will test that after the scoreFor function works properly 
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
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, salvager, great_hall};
    struct gameState G;
    
    int pass =0;

    printf ("TESTING scoreFor function\n"); 
   
				p = 0;
				handCount =0;
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                gainCard(great_hall, &G, 2, p);
				handCount++;
				gainCard(gardens, &G, 2, p); //for trading later should be in hand[1]
				handCount++;
				int x = scoreFor(p, &G);
				int y = scoreFor(p+1, &G);
				gainCard(great_hall, &G, 2, p+1);
				int z = scoreFor(p+1, &G);
                if(x == 1){  // check if score is correct given hand 
					printf("Test 2 passed, Card has correct value returned by function. \n");                
				}
				else{
					pass = 1;
					printf("Test 1 failed, incorect value returned by function \n");
				}
				
				if(y==0){ // check if score is correct given hand 
					printf("Test 2 passed, score has correct value returned by function. \n");                
				}
				else{
					pass = 1;
					printf("Test 2 failed, score has incorrect value returned by function \n");
				}
				
				if(z==1){  // check if score is correct given hand 
					printf("Test 3 passed, score has correct value returned by function. \n");                
				}
				else{
					pass = 1;
					printf("Test 3 failed, incorect value returned by function \n");
				}
				
       if(pass == 0){
    printf("All tests passed!\n");
	   }
    return 0;
}