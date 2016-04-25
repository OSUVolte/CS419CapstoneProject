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

        printf("This is testing the is game over function\n");
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
	//setting up a new game
	
	G.handCount[p] = handCount;

        if(r==-1)
        {
                exit(0);
        }
	

	//the testing of the function
	int i;

        i = isGameOver(&G);
        if (G.supplyCount[province]!=0 && i==1)
        {
        printf("This test failed.\n");
        }
        else
        printf("This test passed.\n");
	
	if (G.supplyCount[duchy]==0&&G.supplyCount[remodel]==0&& G.supplyCount[mine]==0 && i ==0)
	printf("This test passed.\n");
	else
	printf("This test failed.\n");



	return 0;


}




















