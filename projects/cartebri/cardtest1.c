#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Smithy: Smithy allows the player to draw three cards 
before discarding it from their hand. 

case smithy:
      //+3 Cards
      for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;

*/
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int expectedHandSize;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , sea_hag, smithy, village, cutpurse, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
   

    //Test drawcard()
    	p = 0; 
    	G.handCount[1] = 5;
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
           
			#if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s)\n", p, handCount);
			#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                expectedHandSize = handCount + 2;
                for(i = 0; i < 3; i++){
                	drawCard(p, &G);
                }
                discardCard(2, p, &G, 0);
			#if (NOISY_TEST == 1)
                printf("G.handCount = %d, expected = %d\n", G.handCount[p], expectedHandSize);
			#endif
                if(expectedHandSize == G.handCount[p]){
                	printf("Player %d with %d cards PASSED\n", p, handCount);
                	}
                else
                	printf("Player %d with %d cards FAILED\n"); // check if the number of coins is correct

                if(G.handCount[1] == 5)
                	{printf("Player 2 hand count unchanged, PASSED");}
                else
                	{printf("Player 2 hand count changed, FAILED\n");}

                
		}


    return 0;
