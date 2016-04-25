/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * unittest4.c
 */

/* -----------------------------------------------------------------------
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
	int i;
	int seed = 1000;
	int numPlayers = 2;
	int a;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
			remodel, smithy, village, baron, great_hall};	
	struct gameState G;
	printf ("****TESTING: buyCard()****\n");
#if (NOISY_TEST == 1)
	printf("Test buyCard() does not buy a card when numBuys is <= 0\n");
#endif
	memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
	a = initializeGame(numPlayers, k, seed, &G); 		// Initialize new game with no players
	assert(a == 0);
	for(i = 0; i < numPlayers; i++) {
		G.whoseTurn = i; // Set to current player
		G.coins = 20;
		// Test when numBuys exactly 0
		G.numBuys = 0;
		assert(buyCard(estate, &G) == -1);
		// Test when numBuys is less than 0
		G.numBuys = -1;	
		assert(buyCard(estate, &G) == -1);
		// Test when numBuys is greater than 0
		G.numBuys = 1;
		assert(buyCard(estate, &G) == 0);
		G.numBuys = 10000;
		assert(buyCard(estate, &G) == 0);
	}
	printf("buyCard(): PASS does not allow players to buy without buys\n");
#if (NOISY_TEST == 1)
	printf("\nTest buyCard() does not let player buy when no supply of card\n");
#endif	
	for(i = 0; i < numPlayers; i++) {
		memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
		a = initializeGame(numPlayers, k, seed, &G); 		// Initialize new game with no players
		assert(a == 0);
		G.whoseTurn = i;
		G.coins = 20;	
		G.numBuys = 5;	
		// Set supply of card to 0
		G.supplyCount[estate] = 0;
		G.supplyCount[curse] = 0;
		// Test that the buy failed
		assert(buyCard(estate, &G) == -1);
		assert(buyCard(curse, &G) == -1);
	}
	printf("buyCard(): PASS does not allow player to buy when supply of card is 0\n");
#if (NOISY_TEST == 1)
	printf("\nTest buyCard() does not allow player to buy card without correct amount of coins\n");
#endif	
	for(i = 0; i < numPlayers; i++) {
		memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
		a = initializeGame(numPlayers, k, seed, &G); 		// Initialize new game with no players
		assert(a == 0);
		G.whoseTurn = i;
		G.numBuys = 5;	
		G.coins = 0;	
		// Test that the buy failed at zero coins
		assert(buyCard(estate, &G) == -1);
		assert(buyCard(province, &G) == -1);
		assert(buyCard(smithy, &G) == -1);
		assert(buyCard(adventurer, &G) == -1);
		// Test buy failed at card cost - 1 coins
		G.coins = getCost(estate) - 1;	
		assert(buyCard(estate, &G) == -1);
		G.coins = getCost(province) - 1;	
		assert(buyCard(province, &G) == -1);
		G.coins = getCost(smithy) - 1;	
		assert(buyCard(smithy, &G) == -1);
		G.coins = getCost(adventurer) - 1;	
		assert(buyCard(adventurer, &G) == -1);
	}
	printf("buyCard(): PASS does not allow player to buy a card without correct amount of coins\n");
#if (NOISY_TEST == 1)
	printf("\nTest buyCard() allows player to buy when correct coins, number of buys, and not empty supply\n");
#endif
	for(i = 0; i < numPlayers; i++) {
		memset(&G, 23, sizeof(struct gameState)); 		// Clear game state
		a = initializeGame(numPlayers, k, seed, &G); 		// Initialize new game with no players
		assert(a == 0);
		G.whoseTurn = i;
		G.numBuys = 5;
		// Test buying estate
		G.coins = 20;
		assert(buyCard(estate, &G) == 0);
		assert(G.numBuys == 4);				// Test number of buys is decremented
		assert(G.phase == 1);				// Test phase set to one
		assert(G.coins == 20 - (getCost(estate)));	// Test proper number of coins decremented
		// Test buying province
		G.coins = 20;
		assert(buyCard(province, &G) == 0);
		assert(G.numBuys == 3);				// Test number of buys is decremented
		assert(G.phase == 1);				// Test phase set to one
		assert(G.coins == 20 - (getCost(province)));	// Test proper number of coins decremented
		// Test buying smithy
		G.coins = 20;	
		assert(buyCard(smithy, &G) == 0);
		assert(G.numBuys == 2);				// Test number of buys is decremented
		assert(G.phase == 1);				// Test phase set to one
		assert(G.coins == 20 - (getCost(smithy)));	// Test proper number of coins decremented
		// Test buying adventurer
		G.coins = 20;	
		assert(buyCard(adventurer, &G) == 0);
		assert(G.numBuys == 1);				// Test number of buys is decremented
		assert(G.phase == 1);				// Test phase set to one
		assert(G.coins == 20 - (getCost(adventurer)));	// Test proper number of coins decremented
	}	
	printf("buyCard(): PASS allows player to buy when correct coins, buys, and supply\n");
	
	printf("All tests passed!\n");

	return 0;
}

