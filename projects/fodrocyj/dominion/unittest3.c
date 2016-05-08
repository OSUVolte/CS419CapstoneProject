/* -----------------------------------------------------------------------
 * Test isGameOver() function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

void compareIsGameOver(int expectedResult, struct state *gameState){
	if(expectedResult == isGameOver(gameState)){
		printf(" - PASSED\n");
	} else {
		printf(" - FAILED\n");
	}
}


int main() {
    int i;
    int seed = 1000;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
		int numPlayersTest = 0;
		
    printf ("TESTING isGameOver():\n");


#if (NOISY_TEST == 1)
		printf("Test if game is over when there are no victory cards left.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		//Edit the supply of victory cards
		G.supplyCount[estate] = 0;
		G.supplyCount[duchy] = 0;
		G.supplyCount[province] = 0;
		//Run the code
		compareIsGameOver(1, &G);
		
		
#if (NOISY_TEST == 1)
		printf("Test if game is over when there is just one province card left.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		//Edit the supply of victory cards
		G.supplyCount[estate] = 0;
		G.supplyCount[duchy] = 0;
		G.supplyCount[province] = 1;
		//Run the code
		compareIsGameOver(0, &G);
		
		
#if (NOISY_TEST == 1)
		printf("Test if game is over when there are no province cards but other cards.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		//Edit the supply of victory cards
		G.supplyCount[estate] = 5;
		G.supplyCount[duchy] = 5;
		G.supplyCount[province] = 0;
		//Run the code
		compareIsGameOver(1, &G);
		
		
#if (NOISY_TEST == 1)
		printf("Test if there are some cards in each pile.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));
		r = initializeGame(numPlayersTest, k, seed, &G);
		//Edit the supply of victory cards
		G.supplyCount[estate] = 5;
		G.supplyCount[duchy] = 5;
		G.supplyCount[province] = 5;
		//Run the code
		compareIsGameOver(0, &G);
		
		return 0;
		
}
