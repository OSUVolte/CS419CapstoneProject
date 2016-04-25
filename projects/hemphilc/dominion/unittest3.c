/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * unittest3.c
 */

/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
	int seed = 1000;
	int i, j, a;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			remodel, smithy, village, baron, great_hall};	
	struct gameState G;
	printf ("****TESTING: endTurn()****\n");
#if (NOISY_TEST == 1)
	printf("\nTest endTurn() properly discards the player's hand\n");
#endif
	memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
	a = initializeGame(numPlayers, k, seed, &G); 		// Initialize new game with no players
	assert(a == 0);
	for(i = 0; i < numPlayers; i++) {
		G.whoseTurn = i;
		G.handCount[i] = 5;			// Set player hand count
		G.discardCount[i] = 0;			// Zero player discard count
		assert(endTurn(&G) == 0);		// End the player's turn
		for(j = 0; j < G.handCount[i]; j++) {
			assert(G.hand[i][j] == -1);	// Test each hand position is -1
		}
		assert(G.discardCount[i] == 5);		// Test player discard count is now 5
		assert(G.handCount[i] == 0);		// Test player hand count is now 0
	}
	printf("endTurn(): PASS properly discards the player's hand\n");
#if (NOISY_TEST == 1)
	printf("\nTest endTurn() properly determines next player's turn\n");
#endif
	// Test for two players
	memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
	a = initializeGame(2, k, seed, &G); 		// Initialize new game with no players
	assert(a == 0);	
	G.whoseTurn = 0;			// Player 1's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 1);		// Now player 2's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 0);		// Now player 1's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 1);		// Now player 2's turn
	//Test for three players
	memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
	a = initializeGame(3, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);	
	G.whoseTurn = 0;			// Player 1's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 1);		// Now player 2's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 2);		// Now player 3's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 0);		// Now player 1's turn
	//Test for four players
	memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
	a = initializeGame(4, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);	
	G.whoseTurn = 0;			// Player 1's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 1);		// Now player 2's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 2);		// Now player 3's turn
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 3);		// Now player 4's turn	
	assert(endTurn(&G) == 0);		// End the player's turn
	assert(G.whoseTurn == 0);		// Now player 1's turn
	printf("endTurn(): PASS properly determines whose turn is next\n");
#if (NOISY_TEST == 1)
	printf("\nTest endTurn() resets the proper state variables\n");
#endif	
	memset(&G, 23, sizeof(struct gameState)); 	// Clear game state
	a = initializeGame(numPlayers, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);
	// Test player 1's end of turn
	G.whoseTurn = 0;
	assert(endTurn(&G) == 0);
	assert(G.outpostPlayed == 0);	
	assert(G.phase == 0);
	assert(G.numActions == 1);
	assert(G.coins == 3);				// Coins gets zeroed then to 3
	assert(G.numBuys == 1);
	assert(G.playedCardCount == 0);
	assert(G.handCount[0] == 0);			// Hand count gets set to 5
	assert(G.handCount[1] == 5);			// Hand count gets set to 0
	// Test player 2's end of turn
	G.whoseTurn = 1;
	assert(endTurn(&G) == 0);
	assert(G.outpostPlayed == 0);	
	assert(G.phase == 0);
	assert(G.numActions == 1);
	assert(G.coins == 3);				// Coins gets zeroed then set to 3
	assert(G.numBuys == 1);
	assert(G.playedCardCount == 0);
	assert(G.handCount[1] == 0);			// Hand count gets set to 0
	assert(G.handCount[0] == 5);			// Hand count gets set to 5
	printf("endTurn(): PASS resets the proper state variables\n");
	
	printf("All tests passed!\n");

	return 0;
}
