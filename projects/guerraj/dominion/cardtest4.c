/* -----------------------------------------------------------------------
 This unit test will test the salvager card in dominion.c  
we will test that after the salvager card functions properly 
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

    printf ("TESTING salvager Card:\n"); 
   
            
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
                //playCard(0, 1, 0, 0, &G);
				handCount = 0; //discard both cards
			    cardEffect(salvager, 1, 0, 0, &G, G.hand[p][0], 0);  //trade for adventeruer card
#if (NOISY_TEST == 1)
                printf("G.handCount = %d, expected = %d\n", G.handCount[p], handCount); //smithy card should draw three and discard 1
#endif
                if(G.handCount[p] == handCount){ // check if the number of cards is correct
					printf("Test 1 passed, expected card number in hand \n");                
				}
				else{
					pass = 1;
					printf("Test 1 failed, expected card number not found in hand \n");
				}
				//check player 2 hand
				if(G.handCount[p+1] == 0){ // check if the number of cards is correct
					printf("Test 2 passed, expected card number in hand player 2 \n");                
				}
				else{
					pass = 1;
					printf("Test 2 failed, expected card number not found in hand player 2\n");
				}
				
				if(G.coins == 9)
					printf("test 3 passed, correct number of coins added \n");
				else{
					printf("test 3 failed, incorrect coincount %d \n", G.coins);
				pass=1;
				}
       if(pass == 0){
    printf("All tests passed!\n");
	   }
    return 0;
}