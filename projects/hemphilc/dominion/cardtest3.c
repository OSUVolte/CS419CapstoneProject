/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * cardtest3.c
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
	int r;
	int handpos = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int currentPlayer = 0;
	struct gameState G, testG, testG2, testG3;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	printf("****TESTING: mine Card****\n");
	memset(&G, 23, sizeof(struct gameState)); 	// Clear game state
	r = initializeGame(numPlayers, k, seed, &G);	// Initiatlize new game state
	assert(r == 0);
	G.hand[currentPlayer][0] = mine;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = silver;
	G.hand[currentPlayer][3] = gold;
	G.hand[currentPlayer][4] = feast;
	G.hand[currentPlayer][5] = estate;
	G.whoseTurn = currentPlayer;
#if (NOISY_TEST == 1)
	printf("\nTest mine only accepts copper, silver from player's hand\n");
#endif
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	memcpy(&testG2, &G, sizeof(struct gameState));
	memcpy(&testG3, &G, sizeof(struct gameState));
	choice2 = province;
	// Test copper and silver
	assert(cardEffect(mine, 1, choice2, choice3, &testG, 1, &bonus) == 0);
	assert(cardEffect(mine, 2, choice2, choice3, &testG2, 2, &bonus) == 0);
	// Test gold and non-treasure cards
	assert(cardEffect(mine, 3, choice2, choice3, &testG3, 3, &bonus) != 0);
	assert(cardEffect(mine, 4, choice2, choice3, &testG3, 4, &bonus) != 0);
	assert(cardEffect(mine, 5, choice2, choice3, &testG3, 5, &bonus) != 0);
	printf("mine: PASS only accepts copper and silver from player's hand\n");
#if (NOISY_TEST == 1)
	printf("\nTest mine accepts only enumerated dominion cards\n");
#endif
	memcpy(&testG, &G, sizeof(struct gameState));
	// Test values outside enumerations domain in dominion
	assert(cardEffect(mine, 1, treasure_map + 1, choice3, &testG, 1, &bonus) != 0);
	assert(cardEffect(mine, 1, curse - 1, choice3, &testG, 1, &bonus) != 0);
	printf("mine: PASS accepts only enumerated dominion cards\n");
#if (NOISY_TEST == 1)
	printf("\nTest mine discards itself from player's hand\n");
#endif		
	// Place mine at hand position 0
	handpos = 0;
	G.hand[currentPlayer][0] = mine;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(mine, 1, province, choice3, &testG, handpos, &bonus);
	// Test that mine card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] != mine);
	// Place mine at hand position 3
	handpos = 3;
	G.hand[currentPlayer][0] = estate;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = mine;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG2, &G, sizeof(struct gameState));
	cardEffect(mine, 1, province, choice3, &testG, handpos, &bonus);
	// Test that mine card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] != mine);
	// Place mine at hand position 1
	handpos = 1;
	G.hand[currentPlayer][0] = estate;
	G.hand[currentPlayer][1] = mine;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = copper;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG3, &G, sizeof(struct gameState));
	cardEffect(mine, 3, province, choice3, &testG, handpos, &bonus);
	// Test that mine card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] != mine);
	printf("mine: PASS discards itself from the player's hand\n");

	printf("All tests passed!\n");
	
	return 0;
}

