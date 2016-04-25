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

	printf("This is testing the full deck function");
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
	//getting a new game all set
	
	G.handCount[p] = handCount;

        if(r==-1)
        {
                exit(0);
        }


	//making sure that the player has a legal amount of cards after 
	//this function	
	int d;
        
	d =fullDeckCount(1, 4, &G);
        if (d > MAX_DECK)
	{
	printf("Failed test. There are too many cards."); 
        }
	else
	printf("This passed the test. They have less than MAX_DECK.\n");

	int j;

        j =fullDeckCount(1, 4, &G);
        if (d > MAX_HAND)
        {
        printf("Failed test. There are too many cards.");
        }
        else
        printf("This passed the test. They have less than MAX_HAND.\n");

	//testing to make sure that the count is increasing
	//instead of decreasing
	if( G.deckCount[1]<0)
	{
	printf("This failed. Should be increasing not decreasing\n");
        }
	else
	printf("This passed the test. It is increasing\n");
	return 0;
}

