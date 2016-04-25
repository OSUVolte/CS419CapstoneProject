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

        printf("This is testing the get cost function\n");
        int seed = 1000;
        int numPlayer = 2;

        int p, r, handCount;

        int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
        struct gameState G;

        p =0;
        handCount=1;

        memset(&G, 23, sizeof(struct gameState));

        r = initializeGame(numPlayer, k, seed, &G);
	//initializing a new game

        G.handCount[p] = handCount;

        if(r==-1)
        {
                exit(0);
        }

	//testing for a normal value
	int i;

        i = getCost(2);
        if (i==5)
	{
	printf("This test passed.\n");
	}
        else
	printf("This test failed.\n");
	
	//testing if value is above any card level value

	int v;
	v = getCost(30);
	if (v==-1)
	{
	 printf("This test passed.\n");
        }
        else
        printf("This test failed.\n");
	//testing another value
	v = getCost(10);
	        if (v==4)
        {
         printf("This test passed.\n");
        }
        else
        printf("This test failed.\n");

        //one more test to make sure the correct
        //value is returned 
        v = getCost(25);
        if (v!=6)
        {
         printf("This test passed.\n");
        }
        else
        printf("This test failed.\n");

        return 0;
}

