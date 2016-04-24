/* unittest4.c
 * By Dave Martinez
 * martind2@oregonstate.edu

 * This tests the updateCoins function.
 * - Does a copper add 1 coin? (yes)
 * - Does a silver add 2 coin? (yes)
 * - Does a gold add three coin? (yes)
 * - If the player has a bonus, do they get the bonus?
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
	// Game settings
	int seed = 1000,
		numPlayers = 2,
		cards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
					  sea_hag, tribute, smithy, council_room };

	// Game init
	struct gameState G, testG;
	initializeGame(numPlayers, cards, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	
	printf("--------------- UNIT TEST 4 ---------------\n");
	printf("------------ UPDATE COIN TESTS ------------\n");

	printf("\nTEST 1: Does having a copper increase coin by one?\n");
	
	G.hand[0][ G.handCount[0] ] = copper;
    G.handCount[0]++;
   	updateCoins(0, &G, 0);
   	printf("Player 0's coin = %d, expected %d\n", G.coins, testG.coins + 1);
   	assert(G.coins == (testG.coins + 1));

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\nTEST 2: Does having a silver increase coin by two?\n");
	
	G.hand[0][ G.handCount[0] ] = silver;
    G.handCount[0]++;
   	updateCoins(0, &G, 0);
   	printf("Player 0's coin = %d, expected %d\n", G.coins, testG.coins + 2);
   	assert(G.coins == (testG.coins + 2));

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\nTEST 3: Does having a gold increase coin by three?\n");
	
	G.hand[0][ G.handCount[0] ] = gold;
    G.handCount[0]++;
   	updateCoins(0, &G, 0);
   	printf("Player 0's coin = %d, expected %d\n", G.coins, testG.coins + 3);
   	assert(G.coins == (testG.coins + 3));

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\nTEST 1: Does getting a coin bonus increase coin by bonus amt?\n");

   	updateCoins(0, &G, 8);
   	printf("Player 0's coin = %d, expected %d\n", G.coins, testG.coins + 8);
   	assert(G.coins == (testG.coins + 8));

	memcpy(&G, &testG, sizeof(struct gameState));

	printf("\n------------ ALL TESTS PASSED -------------\n");

	return 0;
}