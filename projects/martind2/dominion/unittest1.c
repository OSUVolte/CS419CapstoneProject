/* unittest1.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the buyCard function.
 * 	- Does the function corectly determine whose turn it is? (yes)
 *	- If the player has no turns, does it allow the player to buy? (no)
 * 	- If there are no more cards of that type left, can it be purchased? (no)
 *	- If the player has no coin, can it be purchased? (no)
 * 	- Does the player have one less buy after purchasing? (yes)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
	// Counters
	int i;

	// Game settings
	int seed = 1000,
		numPlayers = 2,
		cards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
					  sea_hag, tribute, smithy, council_room };

	// Game init
	struct gameState G, testG;
	initializeGame(numPlayers, cards, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("--------------- UNIT TEST 1 ---------------\n");
	printf("------------- BUY CARD TESTS --------------\n");

	printf("\nTEST 1: Player 0 has no buys, buyCard returns -1\n");

	G.numBuys = 0;
	i = buyCard(1, &G);
	printf("buyCard returned %d\n", i);
	assert(i == -1);

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\nTEST 2: Player 0 tries to draw card where none left\n");

	G.supplyCount[1] = 0;
	G.numBuys = 1;
	i = buyCard(1, &G);
	printf("buyCard returned %d\n", i);
	assert(i == -1);

	memcpy(&G, &testG, sizeof(struct gameState));
	
	printf("\nTEST 3: Player 0 doesn't have enough coin to purchase");

	G.coins = 0;
	i = buyCard(1, &G);
	printf("buyCard returned %d\n", i);
	assert(i == -1);

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\nTEST 4: Player 0 purchases adventurer card, +1 discardCount");
	G.coins = 6;
	testG.coins = 6;
	i = buyCard(adventurer, &G);
	printf("buyCard returned %d, discardCount: %d, expected: %d\n", i, G.discardCount[0], testG.discardCount[0] + 1);
	assert(i == 0);
	assert(G.discardCount[0] == testG.discardCount[0] + 1);

	printf("\nTEST 5: Supply count for card 0 decremented by 1\n");
	printf("Supply count for adventurer: %d, expected %d\n", G.supplyCount[adventurer], testG.supplyCount[adventurer] - 1);
	assert(G.supplyCount[adventurer] == (testG.supplyCount[adventurer] - 1));

	printf("\nTEST 6: Number of buys decremented by 1\n");
	printf("Num of buys left: %d, expected %d\n", G.numBuys, testG.numBuys - 1);
	assert(G.numBuys == testG.numBuys - 1);

	printf("\nTEST 7: Amt. of coin has decremented.\n");
	printf("Coin: %d, expected %d\n", G.coins, testG.coins - getCost(adventurer));
	assert(G.coins == testG.coins - getCost(adventurer));

	printf("\n--------------- ALL TESTS PASSED ---------------\n");

	return 0;
}