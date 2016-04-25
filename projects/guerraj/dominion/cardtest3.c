/* -----------------------------------------------------------------------
 This unit test will test the remodel card in dominion.c  
we will test that after the remodel card is played the correct trade happends 
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
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int pass =0;

    printf ("TESTING remodel Card:\n"); //handpos = 6 in k
   
            

				p = 0;
				handCount =0;
      
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                gainCard(remodel, &G, 2, p);
				handCount++;
				gainCard(mine, &G, 2, p); //for trading later should be in hand[1]
				handCount++;
                playCard(0, 1,7, 0, &G);
			   // cardEffect(remodel, 1, 7, 0, &G, G.hand[p][0], 0);  //trade for adventeruer card
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
				for(j=0; j<G.handCount[p]; j++){
				if(G.hand[p][j] == adventurer)
				{
					if(j+1 == G.handCount[p])
					printf("Test 3 passed, adventurer card added \n");
				break;
				}
				else{
					if(j+1 == G.handCount[p]){
						printf("Test 3 failed, adventurer card not added \n");
						pass =2;
					}
				} }
       if(pass == 0){
    printf("All tests passed!\n");
	   }
    return 0;
}