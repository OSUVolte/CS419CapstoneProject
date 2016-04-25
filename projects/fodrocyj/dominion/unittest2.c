/* -----------------------------------------------------------------------
 * Unit test for the fullDeckCount() function
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

void compareFullDeckCount(int expectedFullDeckCount, int playerNumber, int cardNumber, struct state *gameState){
	if(expectedFullDeckCount == fullDeckCount(playerNumber, cardNumber, gameState)){
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
		int *scoreBuffer;
		int *expectedScoreBuffer;
		int numPlayersTest = 0;
		int handSize = MAX_HAND;
		int deckSize = 100;
		int discardSize = 2;
		
		//Initialize the hands to hold only coppers
		int noPoints[MAX_HAND];
		for (i = 0; i < MAX_HAND; i++){
			noPoints[i] = copper;
		}
		
    printf ("TESTING fullDeckCount():\n");


#if (NOISY_TEST == 1)
		printf("Player with all coppers. 5 - 5 - 5\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		G.handCount[0] = 5;
		G.discardCount[0] = 5;
		G.deckCount[0] = 5;
		//Give the player 5 coins in each stack
		for (i = 0; i < G.handCount[0]; i++){
			G.hand[0][i] = copper;
		}
		for (i = 0; i < G.discardCount[0]; i++){
			G.discard[0][i] = copper;
		}
		for (i = 0; i < G.deckCount[0]; i++){
			G.deck[0][i] = copper;
		}
		//Run the code
		compareFullDeckCount(15, 0, copper, &G);
		

#if (NOISY_TEST == 1)
		printf("Player with all coppers looking for silver. 0 - 0 - 0\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		G.handCount[0] = 5;
		G.discardCount[0] = 5;
		G.deckCount[0] = 5;
		//Give the player 5 coins in each stack
		for (i = 0; i < G.handCount[0]; i++){
			G.hand[0][i] = copper;
		}
		for (i = 0; i < G.discardCount[0]; i++){
			G.discard[0][i] = copper;
		}
		for (i = 0; i < G.deckCount[0]; i++){
			G.deck[0][i] = copper;
		}
		//Run the code
		compareFullDeckCount(0, 0, silver, &G);
		

	
#if (NOISY_TEST == 1)
		printf("Player with silver in hand. 5 - 0 - 0\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		G.handCount[0] = 5;
		G.discardCount[0] = 5;
		G.deckCount[0] = 5;
		//Give the player 5 coins in each stack
		for (i = 0; i < G.handCount[0]; i++){
			G.hand[0][i] = silver;
		}
		for (i = 0; i < G.discardCount[0]; i++){
			G.discard[0][i] = copper;
		}
		for (i = 0; i < G.deckCount[0]; i++){
			G.deck[0][i] = copper;
		}
		//Run the code
		compareFullDeckCount(5, 0, silver, &G);

	
#if (NOISY_TEST == 1)
		printf("Player with silver in discard. 0 - 5 - 0\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		G.handCount[0] = 5;
		G.discardCount[0] = 5;
		G.deckCount[0] = 5;
		//Give the player 5 coins in each stack
		for (i = 0; i < G.handCount[0]; i++){
			G.hand[0][i] = copper;
		}
		for (i = 0; i < G.discardCount[0]; i++){
			G.discard[0][i] = silver;
		}
		for (i = 0; i < G.deckCount[0]; i++){
			G.deck[0][i] = copper;
		}
		//Run the code
		compareFullDeckCount(5, 0, silver, &G);

	
#if (NOISY_TEST == 1)
		printf("Player with silver in deck. 0 - 0 - 5\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		G.handCount[0] = 5;
		G.discardCount[0] = 5;
		G.deckCount[0] = 5;
		//Give the player 5 coins in each stack
		for (i = 0; i < G.handCount[0]; i++){
			G.hand[0][i] = copper;
		}
		for (i = 0; i < G.discardCount[0]; i++){
			G.discard[0][i] = copper;
		}
		for (i = 0; i < G.deckCount[0]; i++){
			G.deck[0][i] = silver;
		}
		//Run the code
		compareFullDeckCount(5, 0, silver, &G);
		
		
		return 0;
		
}
