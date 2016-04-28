/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
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

void printCards(int player, struct gameState *state){
	int i;
	printf("--Hand:\n");
	for(i = 0; i < state->handCount[player]; i++)
		printf(" - %i", state->hand[0][i]);
	printf("\n");
	printf("--Discard Pile:\n");
	for(i = 0; i < state->discardCount[player]; i++)
		printf(" - %i", state->discard[0][i]);
	printf("\n");
	printf("--Deck:\n");
	for(i = 0; i < state->deckCount[player]; i++)
		printf(" - %i", state->deck[0][i]);
	printf("\n");
}

void setExpectedScore(int *expectedScoreBuffer, int expectedScore){
	expectedScoreBuffer = 22;
}

void compareScores(int expectedScore, int playerNumber, struct state * gameState){
	if(expectedScore == scoreFor(playerNumber, gameState)){
		printf(" - PASSED\n");
	} else {
		printf(" - FAILED\n");
		printf("EXP: %i\n", expectedScore);
		printf("GOT: %i\n", scoreFor(playerNumber, gameState));
		printCards(0, gameState);
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
		
    printf ("TESTING scoreFor():\n");


#if (NOISY_TEST == 1)
		printf("Player with all coppers.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give all players noPoints
		for (i = 0; i < numPlayersTest; i++){
			memcpy(G.hand[i], noPoints, sizeof(int) * MAX_HAND);
		}
		//Run the code
		compareScores(0, 0, &G);

		
#if (NOISY_TEST == 1)
		printf("Player with one estate in hand.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give the player one estate
		memcpy(G.hand[0], noPoints, sizeof(int) * MAX_HAND);
		G.hand[0][G.handCount[0]-1] = estate;
		//Run the code
		compareScores(1, 0, &G);

		
#if (NOISY_TEST == 1)
		printf("Player with one duchy in hand.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give the player one duchy
		memcpy(G.hand[0], noPoints, sizeof(int) * MAX_HAND);
		G.hand[0][G.handCount[0]-1] = duchy;
		//Run the code
		compareScores(3, 0, &G);

		
#if (NOISY_TEST == 1)
		printf("Player with one province in hand.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give the player one province
		memcpy(G.hand[0], noPoints, sizeof(int) * MAX_HAND);
		G.hand[0][G.handCount[0]-1] = province;
		//Run the code
		compareScores(6, 0, &G);

		
#if (NOISY_TEST == 1)
		printf("Player with one estate and one duchy in hand.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give the player one estate and one duchy
		memcpy(G.hand[0], noPoints, sizeof(int) * MAX_HAND);
		G.hand[0][G.handCount[0]-1] = estate;
		G.hand[0][G.handCount[0]-2] = duchy;
		//Run the code
		compareScores(4, 0, &G);
		

#if (NOISY_TEST == 1)
		printf("Player with one estate, one duchy and one province in hand.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give the player one estate, one duchy and one province
		memcpy(G.hand[0], noPoints, sizeof(int) * MAX_HAND);
		G.hand[0][G.handCount[0]-1] = estate;
		G.hand[0][G.handCount[0]-2] = duchy;
		G.hand[0][G.handCount[0]-3] = province;
		//Run the code
		compareScores(10, 0, &G);

		
#if (NOISY_TEST == 1)
		printf("Player with one estate in discard.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		//Give the player one estate in discard
		for(i = 0; i < discardSize; i++)
			G.discard[0][i] = copper;
		G.discard[0][0] = estate;
		//Run the code
		compareScores(1, 0, &G);
		

#if (NOISY_TEST == 1)
		printf("Player with one estate in deck.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		
		G.deckCount[0] = 10;
		G.discardCount[0] = 2;
		
		//Give the player one estate in deck
		for(i = 0; i < G.handCount[0]; i++)
			G.hand[0][i] = copper;
		for(i = 0; i < G.discardCount[0]; i++)
			G.discard[0][i] = copper;
		for(i = 0; i < G.deckCount[0]; i++)
			G.deck[0][i] = copper;
		G.deck[0][0] = estate;
		
		//Run the code
		compareScores(1, 0, &G);
		

#if (NOISY_TEST == 1)
		printf("Player with one estate in hand, discard and deck.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		G.discardCount[0] = 2;
		//Give the player one estate in deck
		for(i = 0; i < G.handCount[0]; i++)
			G.hand[0][i] = copper;
		for(i = 0; i < G.discardCount[0]; i++)
			G.discard[0][i] = copper;
		for(i = 0; i < G.deckCount[0]; i++)
			G.deck[0][i] = copper;
		G.hand[0][0] = estate;
		G.discard[0][0] = estate;
		G.deck[0][0] = estate;
		
		//Run the code
		compareScores(3, 0, &G);
		

#if (NOISY_TEST == 1)
		printf("Player with multiple victory cards in hand, discard and deck.\n");
#endif
		numPlayersTest = 2;
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayersTest, k, seed, &G); // initialize a new game
		G.discardCount[0] = 2;
		//Give the player one estate in deck
		for(i = 0; i < G.handCount[0]; i++)
			G.hand[0][i] = copper;
		for(i = 0; i < G.discardCount[0]; i++)
			G.discard[0][i] = copper;
		for(i = 0; i < G.deckCount[0]; i++)
			G.deck[0][i] = copper;
		G.hand[0][0] = estate;
		G.hand[0][1] = province;
		G.discard[0][0] = estate;
		G.discard[0][1] = duchy;
		G.deck[0][0] = estate;
		G.deck[0][1] = estate;
		
		//Run the code
		compareScores(13, 0, &G);
		
		
		return 0;
		
}
