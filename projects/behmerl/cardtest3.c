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

        printf("This is testing the village card.\n");
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

        G.handCount[p] = handCount;

        if(r==-1)
        {
                exit(0);
        }
		//getting new game set up
	int i;
        int counter;
        counter= G.numActions;
        counter=counter+2;
        i = Village(1, &G, 3);
        if (counter== G.numActions)
        {
        printf("This test passed.\n");
        }
        else
        printf("This test failed. Wrong amount of actions.\n");

        return 0;


}

