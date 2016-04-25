/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * unittest2.c
 */

/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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
	int a, b, c, d, e, f, g;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			remodel, smithy, village, baron, great_hall};	
	int k2[10] = {mine, mine, mine, mine, mine, 
			mine, mine, mine, mine, mine};
	int k3[10] = {great_hall, council_room, feast, gardens, mine, 
			remodel, smithy, village, baron, great_hall};
	struct gameState G, G2, G3, G4, G5, G6, G7;	
	printf ("****TESTING: initializeGame()****\n");
	memset(&G, 23, sizeof(struct gameState)); 
	memset(&G2, 23, sizeof(struct gameState)); 
	memset(&G3, 23, sizeof(struct gameState)); 
	memset(&G4, 23, sizeof(struct gameState));
	memset(&G5, 23, sizeof(struct gameState));
	memset(&G6, 23, sizeof(struct gameState));
	memset(&G7, 23, sizeof(struct gameState));
#if (NOISY_TEST == 1)
	printf("\nTest the number of players the game allows (2 >= numPlayers < 5)\n");
#endif
	//Clear game states
	a = initializeGame(0, k, seed, &G); 			// Initialize new game with no players
	b = initializeGame(1, k, seed, &G2); 			// Initialize new game with only one player
	c = initializeGame(2, k, seed, &G3); 			// Initialize new game with two players
	d = initializeGame(3, k, seed, &G4); 			// Initialize new game with three players
	e = initializeGame(MAX_PLAYERS, k, seed, &G5); 		// Initialize new game with four (max) players
	f = initializeGame(5, k, seed, &G6); 			// Initialize new game with five players
	g = initializeGame(1000, k, seed, &G7); 		// Initialize new game with random number of players
	assert(a == -1);
	assert(b == -1);
	assert(c == 0);
	assert(d == 0);
	assert(e == 0);
	assert(f == -1);
	assert(g == -1);
	printf("initializeGame(): PASS allows the proper number of players\n");
#if (NOISY_TEST == 1)
	printf("\nTest that all of the kingdom cards must be different\n");
#endif
	memset(&G, 23, sizeof(struct gameState));   	// Clear game state
	memset(&G2, 23, sizeof(struct gameState));  	// Clear game state
	a = initializeGame(2, k2, seed, &G);		// Initialize new game with duplicate kingdom cards
	b = initializeGame(2, k3, seed, &G2);		// Initialize new game with duplicate kingdomcards
	assert(a == -1);
	assert(b == -1);
	printf("initializeGame(): PASS does not allow duplicate kingdom cards\n");
#if (NOISY_TEST == 1)
	printf("\nTest the number of curse, victory, and treasure cards supplied for a given number of players\n");
#endif
	// Curse Cards
	assert(G3.supplyCount[curse] == 10);
	assert(G4.supplyCount[curse] == 20);
	assert(G5.supplyCount[curse] == 30);
	// Victory Cards
	assert(G3.supplyCount[estate] == 8);
	assert(G3.supplyCount[duchy] == 8);
	assert(G3.supplyCount[province] == 8);
	assert(G4.supplyCount[estate] == 12);
	assert(G4.supplyCount[duchy] == 12);
	assert(G4.supplyCount[province] == 12);
	assert(G5.supplyCount[estate] == 12);
	assert(G5.supplyCount[duchy] == 12);
	assert(G5.supplyCount[province] == 12);
	//Treasure Cards
	assert(G3.supplyCount[copper] == 46);
	assert(G3.supplyCount[silver] == 40);
	assert(G3.supplyCount[gold] == 30);	
	assert(G4.supplyCount[copper] == 39);
	assert(G4.supplyCount[silver] == 40);
	assert(G4.supplyCount[gold] == 30);
	assert(G5.supplyCount[copper] == 32);
	assert(G5.supplyCount[silver] == 40);
	assert(G5.supplyCount[gold] == 30);
	printf("initializeGame(): PASS properly supplies victory, curse, and treasure cards for number of players\n");
#if (NOISY_TEST == 1)
	printf("\nTest player one is given a hand of five cards, not other players\n");
#endif
	// Two players
	assert(G3.handCount[0] == 5);
	assert(G3.deckCount[0] == 5);
	assert(G3.handCount[1] == 0);
	assert(G3.deckCount[1] == 10);
	// Three players
	assert(G4.handCount[0] == 5);
	assert(G4.deckCount[0] == 5);
	assert(G4.handCount[1] == 0);
	assert(G4.deckCount[1] == 10);
	assert(G4.handCount[2] == 0);
	assert(G4.deckCount[2] == 10);
	// Four Players
	assert(G5.handCount[0] == 5);
	assert(G5.deckCount[0] == 5);
	assert(G5.handCount[1] == 0);
	assert(G5.deckCount[1] == 10);
	assert(G5.handCount[2] == 0);
	assert(G5.deckCount[2] == 10);
	assert(G5.handCount[3] == 0);
	assert(G5.deckCount[3] == 10);
	printf("initializeGame(): PASS properly initializes player one with hand of 5 cards, not other players\n");
	
	printf("All tests passed!\n");

	return 0;
}
