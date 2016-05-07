/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*Unit Test # 3 
*scoreFor() 
*Reference:testUpdateCoins.c  
*Test description:
*Ensure the score for handCount, discardCount, and deck hands is accurrate 
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
    int p, r;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int expected=24;
	int MAX_COUNT=5;   
	int deckCount=5,handCount=5,discardCount=5;	
	
    printf ("Unit Test #3 \n");
    printf ("TESTING scorFor():\n");
    for (p = 0; p < numPlayer; p++)
    {
     	printf("Test scoreFor player %d.\n", p );
    
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.handCount[p] = handCount;                 
        G.deckCount[p] = deckCount;                
        G.discardCount[p] = discardCount;              
		//Set cards to test deck,hand,and discard
		//Initialize test hand,discard, and deck cards. 	
		G.hand[p][0]=curse;
		G.hand[p][1]=estate;
		G.hand[p][2]=curse;
		G.hand[p][3]=province;
		G.hand[p][4]=great_hall;
		G.hand[p][5]=gardens;
	    
		G.discard[p][0]=curse;
		G.discard[p][1]=estate;
		G.discard[p][2]=estate;
		G.discard[p][3]=province;
		G.discard[p][4]=great_hall;
		G.discard[p][5]=gardens;

		G.deck[p][0]=curse;
		G.deck[p][1]=estate;
		G.deck[p][2]=duchy;
		G.deck[p][3]=province;
		G.deck[p][4]=great_hall;
		G.deck[p][5]=duchy;
		if(scoreFor(p,&G)==expected)
		{
			printf("PASS:test = %d, expected = %d\n", scoreFor(p,&G),expected);

		}
		else
		{
			printf("FAIL:test = %d, expected = %d\n", scoreFor(p,&G),expected);

		}
   	}

    printf("End Unit Test #3\n");

    return 0;
}
