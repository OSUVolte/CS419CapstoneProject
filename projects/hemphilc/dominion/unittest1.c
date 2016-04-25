/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * unittest1.c
 */

/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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
	int numPlayer = 2;
	int a;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			remodel, smithy, village, baron, great_hall};
	struct gameState G;	
	printf ("****TESTING: isGameOver()****\n");
#if (NOISY_TEST == 1)
	printf("\nTest isGameOver() ends game when no province cards in deck\n");
#endif
	// Test with random province supply counts
	memset(&G, 23, sizeof(struct gameState));	// Clear Game state
	a = initializeGame(numPlayer, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);
	// When province supply is between 1 and 12
	G.supplyCount[province] = 12;
	assert(isGameOver(&G) == 0);
	G.supplyCount[province] = 1;
	assert(isGameOver(&G) == 0);	
	G.supplyCount[province] = 4;
	assert(isGameOver(&G) == 0);	
	G.supplyCount[province] = 7;
	assert(isGameOver(&G) == 0);	
	memset(&G, 23, sizeof(struct gameState));	// Clear Game state
	a = initializeGame(numPlayer, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);
	// When province supply is exactly 0
	G.supplyCount[province] = 0;
	assert(isGameOver(&G) == 1);
	// When province supply is less than 0, the game will not end (bug?)
	G.supplyCount[province] = -1;
	assert(isGameOver(&G) == 0);
	printf("isGameOver(): PASS ends the games when no Province cards are left\n");
#if (NOISY_TEST == 1)
	printf("\nTest isGameOver() ends game when 3 supply counts are 0\n");
#endif
	memset(&G, 23, sizeof(struct gameState));	// Clear Game state
	a = initializeGame(numPlayer, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);
	// Set 3 supply pile counts to 0
	G.supplyCount[estate] = 0;
	G.supplyCount[adventurer] = 0;
	G.supplyCount[smithy] = 0;
	// Assert that the game is now over
	assert(isGameOver(&G) == 1);
	memset(&G, 23, sizeof(struct gameState));	// Clear Game state
	a = initializeGame(numPlayer, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);
	// Set more than 3 supply pile counts to 0
	G.supplyCount[estate] = 0;
	G.supplyCount[adventurer] = 0;
	G.supplyCount[smithy] = 0;	
	G.supplyCount[duchy] = 0;
	G.supplyCount[council_room] = 0;
	// Assert that the game is now over
	assert(isGameOver(&G) == 1);
	printf("isGameOver(): PASS ends game when at least 3 supply counts are 0\n");
#if (NOISY_TEST == 1)
	printf("\nTest isGameOver() does not end game when only 1 or 2 empty piles\n");
#endif
	// Test 1 empty pile 
	memset(&G, 23, sizeof(struct gameState));	// Clear Game state
	a = initializeGame(numPlayer, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);
	G.supplyCount[duchy] = 0;
	assert(isGameOver(&G) == 0);
	// Test 2 empty piles 
	memset(&G, 23, sizeof(struct gameState));	// Clear Game state
	a = initializeGame(numPlayer, k, seed, &G); 	// Initialize new game with no players
	assert(a == 0);
	G.supplyCount[estate] = 0;
	G.supplyCount[duchy] = 0;
	assert(isGameOver(&G) == 0);
	printf("isGameOver(): PASS does not end game when only 1 or 2 empty supply piles\n");
	
	printf("All tests passed!\n");

	return 0;
}

