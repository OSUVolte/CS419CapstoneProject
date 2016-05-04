#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>



int main()
{

        printf("This is testing the great hall card.\n");
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
	//setting up a game
	int i;
        int counter;
	int counter2;
        counter= G.handCount[1];
        counter2= G.numActions;
        i = Great_Hall(1, &G, 1, 3);
        if (counter< G.handCount[1])
        {
        printf("This test passed.\n");
        }
        else
        printf("This test failed. Wrong amount of cards.\n");
	//above test is to make sure that the handcount is increasing 
 	if (counter2< G.numActions)
        {
        printf("This test passed.\n");
        }
        else
        printf("This test failed. Wrong amount of actions.\n");
	//above test is to make sure that numActions is increasing
        return 0;


}


