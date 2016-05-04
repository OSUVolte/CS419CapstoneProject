/* Corey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 3
 * April 24, 2016
 * cardtest4.c
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
	int newCards = 4;
	int discarded = 1;
	int r;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int currentPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	printf("****TESTING: council_room Card****\n");
	memset(&G, 23, sizeof(struct gameState)); 	// Clear game state
	r = initializeGame(numPlayers, k, seed, &G);	// Initiatlize new game state
	assert(r == 0);
#if (NOISY_TEST == 1)
	printf("\nTest council_room draws four cards into the player's hand\n");
#endif
	// Copy game state
	handpos = 0;
	G.hand[currentPlayer][0] = council_room;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = feast;
	G.hand[currentPlayer][5] = -1;
	G.hand[currentPlayer][6] = -1;
	G.hand[currentPlayer][7] = -1;	
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer] + newCards - discarded);
	assert(testG.deckCount[currentPlayer] == G.deckCount[currentPlayer] - newCards);
	// Test the hand positions are not null
	assert(testG.hand[currentPlayer][4] != -1);
	assert(testG.hand[currentPlayer][5] != -1);
	assert(testG.hand[currentPlayer][6] != -1);
	assert(testG.hand[currentPlayer][7] != -1);
	printf("council_room: PASS draws exactly four cards into the current player's hand\n");
#if (NOISY_TEST == 1)
	printf("\nTest council_room plays exactly 1 card from the player's hand\n");
#endif
	// Copy game state
	handpos = 0;
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer] + newCards - discarded);
	assert(testG.deckCount[currentPlayer] == G.deckCount[currentPlayer] - newCards);
	// Test exactly one card is played
	assert(testG.playedCardCount == 1);
	printf("council_room: PASS plays exactly 1 card from the player's hand\n");
#if (NOISY_TEST == 1)
	printf("\nTest council_room each other player draws exactly 1 card\n");
#endif
	handpos = 0;
	memset(&G, 23, sizeof(struct gameState)); 	// Clear game state
	r = initializeGame(4, k, seed, &G);	// Initiatlize new game state
	assert(r == 0);
	G.hand[currentPlayer][0] = council_room;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	assert(cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus) == 0);
	// Player 2 draws	
	assert(testG.handCount[1] == G.handCount[1] + 1);
	assert(testG.deckCount[1] == G.deckCount[1] - 1);
	// Player 3 Draws
	assert(testG.handCount[2] == G.handCount[2] + 1);
	assert(testG.deckCount[2] == G.deckCount[2] - 1);
	// Player 4 Draws
	assert(testG.handCount[3] == G.handCount[3] + 1);
	assert(testG.deckCount[3] == G.deckCount[3] - 1);
	printf("council_room: PASS each other player draws exactly 1 card\n");
#if (NOISY_TEST == 1)
	printf("\nTest council_room discards itself from player's hand\n");
#endif	
	// Place council_room at hand position 0
	handpos = 0;
	G.hand[currentPlayer][0] = council_room;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = estate;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Test that council_room card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] != council_room);
	// Place council_room at hand position 3
	handpos = 3;
	G.hand[currentPlayer][0] = estate;
	G.hand[currentPlayer][1] = copper;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = council_room;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Test that smithy card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] != council_room);
	// Place council_room at hand position 1
	handpos = 1;
	G.hand[currentPlayer][0] = estate;
	G.hand[currentPlayer][1] = council_room;
	G.hand[currentPlayer][2] = duchy;
	G.hand[currentPlayer][3] = copper;
	G.hand[currentPlayer][4] = feast;
	// Copy game state
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
	// Test that council_room card was removed from its hand position
	assert(testG.hand[currentPlayer][handpos] != council_room);
	printf("council_room: PASS discards itself from the player's hand\n");

	printf("All tests passed!\n");
	
	return 0;
}

