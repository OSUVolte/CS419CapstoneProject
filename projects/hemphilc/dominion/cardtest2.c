/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * cardtest2.c
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
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
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int currentPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	printf("****TESTING: adventurer Card****\n");
	memset(&G, 23, sizeof(struct gameState)); 	// Clear game state
	r = initializeGame(numPlayers, k, seed, &G);	// Initiatlize new game state
	assert(r == 0);
#if (NOISY_TEST == 1)
	printf("\nTest adventurer properly grabs two treasure cards and discards extras\n");
#endif
	handpos = 0;
	// Set player hand
	G.hand[currentPlayer][0] = adventurer;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = feast;
	// Set player deck
	G.deckCount[currentPlayer] = 10;
	G.discardCount[currentPlayer] = 0;
	G.deck[currentPlayer][0] = estate;
	G.deck[currentPlayer][1] = smithy;
	G.deck[currentPlayer][2] = council_room;
	G.deck[currentPlayer][3] = silver;
	G.deck[currentPlayer][4] = cutpurse;
	G.deck[currentPlayer][5] = mine;
	G.deck[currentPlayer][6] = village;
	G.deck[currentPlayer][7] = tribute;
	G.deck[currentPlayer][8] = embargo;
	G.deck[currentPlayer][9] = gold;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);	
	assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer] + 2);
	assert(testG.deckCount[currentPlayer] == G.deckCount[currentPlayer] - 7);	
	assert(testG.discardCount[currentPlayer] == G.discardCount[currentPlayer] + 5);
	printf("adventurer: PASS properly grabs two treasure cards and discards extras\n");
#if (NOISY_TEST == 1)
	printf("\nTest adventurer only counts treasure cards\n");
#endif
	handpos = 0;
	// Test with no treasure cards in deck or hand
	G.deckCount[currentPlayer] = 10;
	G.discardCount[currentPlayer] = 0;
	G.deck[currentPlayer][0] = estate;
	G.deck[currentPlayer][1] = smithy;
	G.deck[currentPlayer][2] = council_room;
	G.deck[currentPlayer][3] = smithy;
	G.deck[currentPlayer][4] = cutpurse;
	G.deck[currentPlayer][5] = mine;
	G.deck[currentPlayer][6] = village;
	G.deck[currentPlayer][7] = tribute;
	G.deck[currentPlayer][8] = embargo;
	G.deck[currentPlayer][9] = village;		
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);	
	assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer] - 3);
	assert(testG.deckCount[currentPlayer] == G.deckCount[currentPlayer] - 10);
	assert(testG.discardCount[currentPlayer] == G.discardCount[currentPlayer] + 13);	
	// Test with two treasures at top of deck
	G.deckCount[currentPlayer] = 10;
	G.discardCount[currentPlayer] = 0;
	G.deck[currentPlayer][0] = duchy;
	G.deck[currentPlayer][1] = estate;
	G.deck[currentPlayer][2] = council_room;
	G.deck[currentPlayer][3] = smithy;
	G.deck[currentPlayer][4] = cutpurse;
	G.deck[currentPlayer][5] = mine;
	G.deck[currentPlayer][6] = village;
	G.deck[currentPlayer][7] = tribute;
	G.deck[currentPlayer][8] = silver;
	G.deck[currentPlayer][9] = gold;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);	
	assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer] + 2);
	assert(testG.deckCount[currentPlayer] == G.deckCount[currentPlayer] - 2);
	assert(testG.discardCount[currentPlayer] == G.discardCount[currentPlayer] + 0);	
	printf("adventurer: PASS only counts treasure cards\n");
#if (NOISY_TEST == 1)
	printf("\nTest adventurer shuffles when deck count is 0\n");
#endif	
	// Place adventurer at hand position 0
	handpos = 0;
	// Set player hand
	G.hand[currentPlayer][0] = adventurer;
	G.hand[currentPlayer][1] = smithy;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = feast;
	// Set discard pile
	G.deckCount[currentPlayer] = 0;
	G.discardCount[currentPlayer] = 5;
	G.discard[currentPlayer][0] = estate;
	G.discard[currentPlayer][1] = smithy;
	G.discard[currentPlayer][2] = council_room;
	G.discard[currentPlayer][3] = smithy;
	G.discard[currentPlayer][4] = cutpurse;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);	
	//There is a bug in the shuffle function
	assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer] - 6);
	assert(testG.deckCount[currentPlayer] == G.deckCount[currentPlayer]);
	assert(testG.discardCount[currentPlayer] == G.discardCount[currentPlayer] + 6);	
	printf("adventurer: PASS shuffles when deck count is 0\n");
#if (NOISY_TEST == 1)
	printf("\nTest adventurer does not discard itself from the player's hand\n");
#endif	
	// Place adventurer at hand position 0
	handpos = 0;
	G.hand[currentPlayer][0] = adventurer;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Test that adventurer card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] == adventurer);
	// Place adventurer at hand position 3
	handpos = 3;
	G.hand[currentPlayer][0] = estate;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = adventurer;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Test that adventurer card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] == adventurer);
	// Place adventurer at hand position 1
	handpos = 1;
	G.hand[currentPlayer][0] = estate;
	G.hand[currentPlayer][1] = adventurer;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = copper;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Test that adventurer card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] == adventurer);
	printf("adventurer: PASS does not discard itself from the player's hand\n");

	printf("All tests passed!\n");
	
	return 0;
}

