#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>



int main()
{

        printf("This is testing the smithy card.\n");
        int seed = 1000;
        int numPlayer = 2;

        int p, r, handCount;

        int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
        struct gameState G;

        p =1;
        handCount=3;

        memset(&G, 23, sizeof(struct gameState));

        r = initializeGame(numPlayer, k, seed, &G);
	//setting up the game
	 G.handCount[p] = handCount;

        if(r==-1)
        {
                exit(0);
        }

	//for the smith card this will be making sure that 
	//3 cards will be added for the player

	int i;
	int counter;
	counter= G.handCount[1];
        i = Smithy(1, &G, 3, 3);
        if (counter < G.handCount[1])
        {
        printf("This test passed.\n");
        }
        else
        printf("This test failed. Three cards have not been added.\n");

        return 0;


}

