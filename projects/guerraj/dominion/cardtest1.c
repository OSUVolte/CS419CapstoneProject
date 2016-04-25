/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 
 This unit test will test the smithy card in dominion.c  
we will test that after the smithy card is played a card is discarded and three cards are drawn
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
    int pass =0;

    printf ("TESTING Smithy Card:\n"); //handpos = 6 in k
   
            
#if (NOISY_TEST == 1)
				p = 0;
				handCount =0;
                printf("Test player %d with %d card(s) in hand before given smithy \n", p, handCount);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                gainCard(smithy, &G, 2, p);
				handCount++;
                cardEffect(smithy, 0, 0, 0, &G, G.hand[p][0], 0);
#if (NOISY_TEST == 1)
                printf("G.handCount = %d, expected = %d\n", G.handCount[p], handCount + 2); //smithy card should draw three and discard 1
#endif
                if(G.handCount[p] == handCount + 2){ // check if the number of cards is correct
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
       if(pass == 0){
    printf("All tests passed!\n");
	   }
    return 0;
}