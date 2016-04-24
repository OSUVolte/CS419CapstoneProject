/*
 * unittest4.c
 * tests isGameOver()
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testIsGameOver() {
	char* UNITTEST = "isGameOver()";
    int i;
    int seed = 1000;
	int provinceCount = 12;
	int kingdomCount = 10;
	int copperCount = 39;
	int silverCount = 40;
	int goldCount = 30;
    int numPlayers = 3;
    int thisPlayer = 0;
	struct gameState G, testG, realG;
	int k[10] = {adventurer, remodel, village, ambassador, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int prevHandCount;
	int prevDiscardCount;

	// Initialize the game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
	printf("\n\n----------------- Testing of Function: %s ----------------\n", UNITTEST);

	
	
	/****************************************************
	Test 1: All the supply piles and the Province card pile is full
	****************************************************/
	printf("\nTEST 1: All the supply piles and the Province card pile is full \n");
	
	// Theoretically, there should be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", G.supplyCount[province]);
	assert(G.supplyCount[province] == 12);
	printf("estate cards = %d\n", G.supplyCount[estate]);
	assert(G.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", G.supplyCount[duchy]);
	assert(G.supplyCount[duchy] == 12);
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], G.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", G.supplyCount[copper]);
	assert(G.supplyCount[copper] == 39);
	printf("silver cards = %d\n", G.supplyCount[silver]);
	assert(G.supplyCount[silver] == 40);
	printf("gold cards = %d\n", G.supplyCount[gold]);
	assert(G.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&G), 0);
	assert(isGameOver(&G) == 0);
	
	
	/****************************************************
	Test 2: One kingdom supply pile is empty and the rest are full
	****************************************************/
	printf("\nTEST 2: One kingdom supply pile is empty and the rest are full \n");
	
	// Theoretically, there should be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", G.supplyCount[province]);
	assert(G.supplyCount[province] == 12);
	printf("estate cards = %d\n", G.supplyCount[estate]);
	assert(G.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", G.supplyCount[duchy]);
	assert(G.supplyCount[duchy] == 12);
	
	// But now, we're going to take away all the adventurer cards
	G.supplyCount[adventurer] = 0;
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], G.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", G.supplyCount[copper]);
	assert(G.supplyCount[copper] == 39);
	printf("silver cards = %d\n", G.supplyCount[silver]);
	assert(G.supplyCount[silver] == 40);
	printf("gold cards = %d\n", G.supplyCount[gold]);
	assert(G.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&G), 0);
	assert(isGameOver(&G) == 0);
	
	/****************************************************
	Test 3: Two kingdom supply piles are empty and the rest are full
	****************************************************/
	printf("\nTEST 3: One kingdom supply pile is empty and the rest are full \n");
	
	// Theoretically, there should be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", G.supplyCount[province]);
	assert(G.supplyCount[province] == 12);
	printf("estate cards = %d\n", G.supplyCount[estate]);
	assert(G.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", G.supplyCount[duchy]);
	assert(G.supplyCount[duchy] == 12);
	
	// But now, we're going to take away all the adventurer cards
	G.supplyCount[remodel] = 0;
	
	// Theoretically, there should be 0-10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], G.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", G.supplyCount[copper]);
	assert(G.supplyCount[copper] == 39);
	printf("silver cards = %d\n", G.supplyCount[silver]);
	assert(G.supplyCount[silver] == 40);
	printf("gold cards = %d\n", G.supplyCount[gold]);
	assert(G.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&G), 0);
	assert(isGameOver(&G) == 0);

	/****************************************************
	Test 4: Three kingdom supply piles are empty and the rest are full
	****************************************************/
	printf("\nTEST 4: Three kingdom supply piles are empty and the rest are full \n");
	
	// Theoretically, there should be 12 province, estate, and duchy cards originally
	printf("province cards = %d\n", G.supplyCount[province]);
	assert(G.supplyCount[province] == 12);
	printf("estate cards = %d\n", G.supplyCount[estate]);
	assert(G.supplyCount[estate] == 12);
	printf("duchy cards = %d\n", G.supplyCount[duchy]);
	assert(G.supplyCount[duchy] == 12);
	
	// But now, we're going to take away all the adventurer cards
	G.supplyCount[village] = 0;
	
	// Theoretically, there should be 0-10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], G.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", G.supplyCount[copper]);
	assert(G.supplyCount[copper] == 39);
	printf("silver cards = %d\n", G.supplyCount[silver]);
	assert(G.supplyCount[silver] == 40);
	printf("gold cards = %d\n", G.supplyCount[gold]);
	assert(G.supplyCount[gold] == 30);
	
	// Therefore, the game should be over
	printf("game over = %d, expected = %d\n", isGameOver(&G), 1);
	assert(isGameOver(&G) == 1);
	
	
	/****************************************************
	Test 5: Estate and Duchy piles are empty and the rest are full
	****************************************************/
	printf("\nTEST 5: Estate and Duchy piles are empty and the rest are full \n");
	
	// Theoretically, there should be 12 province cards
	printf("province cards = %d\n", G.supplyCount[province]);
	assert(G.supplyCount[province] == 12);
	
	// Empty the estate cards
	G.supplyCount[estate] = 0;
	printf("estate cards = %d\n", G.supplyCount[estate]);
	
	// Empty the duchy cards
	G.supplyCount[duchy] = 0;
	printf("duchy cards = %d\n", G.supplyCount[duchy]);
	
	// First, we restore the adventurer, village, and remodel cards
	G.supplyCount[village] = 0;
	for (i = 0; i< 3; i++) {
		G.supplyCount[k[i]] = 10;	
	}
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], G.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", G.supplyCount[copper]);
	assert(G.supplyCount[copper] == 39);
	printf("silver cards = %d\n", G.supplyCount[silver]);
	assert(G.supplyCount[silver] == 40);
	printf("gold cards = %d\n", G.supplyCount[gold]);
	assert(G.supplyCount[gold] == 30);
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&G), 0);
	assert(isGameOver(&G) == 0);
	
	/****************************************************
	Test 6: All piles (except the Province pile) is full
	****************************************************/
	printf("\nTEST 6: Estate and Duchy piles are empty and the rest are full \n");
	
	// Theoretically, there should be 12 province cards
	G.supplyCount[province] = 0;
	printf("province cards = %d\n", G.supplyCount[province]);
	
	// Empty the estate cards
	G.supplyCount[estate] = 12;
	printf("estate cards = %d\n", G.supplyCount[estate]);
	
	// Empty the duchy cards
	G.supplyCount[duchy] = 12;
	printf("duchy cards = %d\n", G.supplyCount[duchy]);
	
	// Theoretically, there should be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], G.supplyCount[k[i]]);
	}
	
	// Theoretically, there should be 39 coppers, 40 silvers, and 30 gold
	printf("copper cards = %d\n", G.supplyCount[copper]);
	assert(G.supplyCount[copper] == 39);
	printf("silver cards = %d\n", G.supplyCount[silver]);
	assert(G.supplyCount[silver] == 40);
	printf("gold cards = %d\n", G.supplyCount[gold]);
	assert(G.supplyCount[gold] == 30);
	
	// Therefore, the game should be over
	printf("game over = %d, expected = %d\n", isGameOver(&G), 1);
	assert(isGameOver(&G) == 1);
	
	
	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", UNITTEST);


	return 0;
}


