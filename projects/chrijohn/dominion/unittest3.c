#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int r;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;


	printf("TESTING isGameOver:\n");

	// testing providence supply to 10
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	// set all supply counts to 10
	for (i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 10;
	}
	G.supplyCount[province] = 10;  // set province supply to 10
	assert(isGameOver(&G) == 0);  // test game isn't finished

	// testing providence supply to 0 (should end)
	G.supplyCount[province] = 0;  // set province supply to 0
	assert(isGameOver(&G) == 1);  // test game is finished

	// testing one supply count to 0
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	// set all supply counts to 10
	for (i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 10;
	}
	G.supplyCount[11] = 0;  // set one supply count to 0
	assert(isGameOver(&G) == 0);  // test game isn't finished

	//testing two supply counts to 0
	G.supplyCount[12] = 0;
	assert(isGameOver(&G) == 0);  // test game isn't finished

	//testing three supply counts to 0 (should end game)
	G.supplyCount[13] = 0;
	assert(isGameOver(&G) == 1);  // test game is= finished

	//testing four supply counts to 0 (should end game)
	G.supplyCount[14] = 0;
	assert(isGameOver(&G) == 1);  // test game is finished

	// testing all supply counts to 0 (should end game)
	for (i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 0;
	}
	assert(isGameOver(&G) == 1); // test agme is finished

	printf("All tests passed!\n");

	return 0;
}
