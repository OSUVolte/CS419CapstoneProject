/*
 * cardtest1.c
 * Brian Brown
 * CS 362 - Software Engineering II
 *
 */

/* REMINDER TO DO THIS - Need to understand the particulars of Makefile better
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int testHandSize1, testHandSize2, testDeckSize1, testDeckSize2;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int player1 = 0;
    int player2 = 1;
	struct gameState origGS, testGS;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &origGS);


	//make sure the game initialized
	if (origGS.whoseTurn != 0)
		printf("Error -- Game did not initialize correctly. \n");
	else
		printf("Game initialized successfully. Continuing test.");

	memcpy(&testGS, &origGS, sizeof(struct gameState));
		//need to make a copy of the game state for testing

	if (origGS != testGS)
			printf("Error -- Game state did not memcopy() correctly. \n");
		else
			printf("Game state memcopy() successful. Continuing test.");

	printf("---------------------------------------------------\n");
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	printf("---------------------------------------------------\n");

	player1 = origGS.whoseTurn;
	origGS.hand[0][0] = smithy;
	//put smithy into player 1's hand, could use TESTCARD, but want obvious declaration

	testHandSize1 = origGS.handCount;
	testDeckSize1 = origGS.deckCount;

	playSmithy(player1, &origGS, 0, 0);

	printf("Test 1\n");
	if(testGS.handCount[player1] == origGS.handCount[player1] +2)
		{
		printf("PASS -- Test for card draw has passed. Added 3 cards and removed the smithy. Net increase 2 cards.");
		printf("Starting card count. %d\tEnding card count.%d\n", origGS.handCount[player1] +2, testGS.handCount[player1]);
		}
	else
		{
		printf("FAIL -- Test for card draw has failed.");
		printf("Starting card count. %d\tEnding card count.%d\n", origGS.handCount[player1] +2, testGS.handCount[player1]);
		}

	//make sure player2 hasn't had anything happen to their deck or hand
	printf("Test 2\n");
	if(testGS.handCount[player2] == origGS.handCount[player2])
		{
		printf("PASS -- NO change in player2 hand count.");
		printf("Starting card count. %d\tEnding card count.%d\n", origGS.handCount[player2], testGS.handCount[player2]);
		}
		else
		{
		printf("FAIL -- Change in player2 hand count.");
		printf("Starting card count. %d\tEnding card count.%d\n", origGS.handCount[player2], testGS.handCount[player2]);
		}

	printf("Test 3\n");
	if(testGS.deckCount[player2] == origGS.deckCount[player2])
		{
		printf("PASS -- NO change in player2 deck count.");
		printf("Starting card count for player2. %d\tEnding card count for player2.%d\n", origGS.deckCount[player2] +2, testGS.deckCount[player2]);
		}
	else
		{
		printf("FAIL -- Change in player2 deck count.");
		printf("Starting card count for player2. %d\tEnding card count for player2.%d\n", origGS.deckCount[player2] +2, testGS.deckCount[player2]);
		}

	printf("Test 4 - Ensuring appropriate number of cards discarded\n");
	if(testGS.playedCardCount == 1)
		{
		printf("PASS - card was discarded after use.\n");
		printf("Total cards discarded:%d\tExpected: 1", testGS.playedCardCount);
		}
	else
		{
		printf("FAIL - card was not discarded after use.\n");
		printf("Total cards discarded:%d\tExpected: 1", testGS.playedCardCount);
		}

	/*
	 * Need to come up with other possibilities of things to check given time. What else in game
	 * state could be effected. Coins, estates, more than 2 players, different seed values, order
	 * of play, etc. Obviously there will be way too many things to test to cover all things.
	 */

	printf("\n === Testing complete for %s ===\n\n", TESTCARD);


	return 0;
}

