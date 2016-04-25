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

	printf("Testing the  Whose Turn	function");
    	int seed = 100;
    	int numPlayer = 3;
    
    	int p, r, handCount;
    	
    	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    	struct gameState G;
    	//int maxHandCount = 5;
	p =0;
	handCount=1;

	memset(&G, 23, sizeof(struct gameState));

	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount; 

        if(r==-1)
	{
		exit(0);
	}
        //This is a unit test for the whose turn function
        //It is making sure the the number of players stays consistent
        int i;
        i =whoseTurn(&G);
        if(i>G.numPlayers)
	{
	 printf("Oh no, too many people!\n");
        }
	if(i<=G.numPlayers)
	{
	printf("This passed: there is still a legal number of players in game.\n");
	}

	numPlayer = 7;
	i =whoseTurn(&G);
        if(numPlayer > G.numPlayers)
        {
         printf("Oh no, too many people!\n");
        }
	numPlayer = 3;
        if(i<=G.numPlayers)
        {
        printf("This passed: there is still a legal number of players in game.\n");
        }
	return 0;
}
