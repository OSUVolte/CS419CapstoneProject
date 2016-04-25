/*
Card test 4: Salvager
Aleksandr Balab
CS 362 Spring 2016
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(int argc, char const *argv[]) {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount, correctBuys, correctCoins, toTrash;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    // array fro the salvager test
    int salv[11];
    salv[0] = salvager;
    for (i = 1; i < 11; i++)
    {
        salv[i] = k[i - 1];
    }

	printf("==============================================\r\n");
	printf("\n   Beginning testing for card Salvager():\r\n");
	printf("==============================================\r\n");

    for (p = 0; p < numPlayer; p++) {
    	for (handCount = 2; handCount <= 11; handCount++) {
    		for(toTrash = 1; toTrash < handCount; toTrash++){
    			printf("Test player %d playing Salvager card, hand size: %d, hand to trash: %d\n", p, handCount, toTrash);
    		
    			memset(&G, 23, sizeof(struct gameState));   // clear the game state
        	    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        	    //Get selected card amount
        	    G.whoseTurn = p;
        	    G.handCount[p] = handCount;
        	    correctBuys = G.numBuys + 1;
        	    correctCoins = G.coins + getCost(salv[toTrash]);

        	    memcpy(G.hand[p], salv, sizeof(int) * handCount);

        	    r = playCard(0, toTrash, 0, 0, &G); //choice 1 will be changing

        	    printf("G.numBuys = %d, expected = %d\n", G.numBuys, correctBuys);
        	    printf("G.coins = %d, expected = %d\n", G.coins, correctCoins);

        	    if (G.numBuys == correctBuys + 2 && G.coins == correctCoins) {
        	    	printf("The Salvager card worked correctly\n");
        	    }
        	    else {
        	    	printf("The Salvager card did not work correctly\n");
        	    }
        	}
    	}
    }
	

	return 0;
}