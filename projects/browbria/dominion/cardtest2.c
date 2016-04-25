/*
 * cardtest2.c
 * Brian Brown
 * CS 362 - Software Engineering II
 *
 */

/* REMINDER TO DO THIS - Need to understand the particulars of Makefile better
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int drawnTreasure;
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
	origGS.hand[0][0] = adventurer;
	//put adventurer into player 1's hand, could use TESTCARD, but want obvious declaration

	testHandSize1 = origGS.handCount;
	testDeckSize1 = origGS.deckCount;

	//need to create an initial hand and some cards on the top of the deck to draw from

	testGS.hand[player1][0] = adventurer;
	testGS.hand[player1][1] = estate;
	testGS.hand[player1][2] = mine;
	testGS.hand[player1][3] = estate;
	testGS.hand[player1][4] = duchy;

	//change cards in deck set up as needed
	testGS.deck[player1][0] = estate;
	testGS.deck[player1][1] = estate;
	testGS.deck[player1][2] = gold;
	testGS.deck[player1][3] = duchy;
	testGS.deck[player1][4] = copper;
	testGS.deck[player1][5] = silver;
	testGS.deck[player1][6] = silver;
	testGS.deck[player1][7] = silver;
	testGS.deck[player1][8] = silver;

	int cardsBefore = testGS.handCount[player1];
	int cardDraw;
	int copperDraw, silverDraw, goldDraw;

	playAdventurer(player1, &origGS, 0, 0);


	printf("Test 1 -- should have two more cards in hand (both coin types of cards)\n");
	if(testGS.handCount[player1] - 2 == cardsBefore)
		{
		printf("PASS -- Hand size increased by 2.");
		printf("Starting card count. %d\tEnding card count.%d\n", cardsBefore, testGS.handCount[player1]);
		}
	else
		{
		printf("FAIL -- Hand size increased by amount other than 2.");
		printf("Starting card count. %d\tEnding card count.%d\n", cardsBefore, testGS.handCount[player1]);
		}

	printf("Test 1a -- cards should both be coins\n");
	drawnTreasure = 0;
	copperDraw = 0;
	silverDraw = 0;
	copperDraw = 0;

	for (int j=0; j<testGS.handCount[player1];j++){
		if (testGS.hand[player1][j]==copper || testGS.hand[player1][j]==silver || testGS.hand[player1][j]==gold)
			{
			drawnTreasure++;
			copperDraw++;
			silverDraw++;
			goldDraw++;
			}

		if(drawnTreasure == 2)
			{
			printf("PASS -- Both cards drawn were coins.");
			printf("Copper drawn: %d\tSilver drawn: %d\tGold drawn: %d\n", copperDraw, silverDraw, goldDraw);
			}
		else
			{
			printf("FAIL -- Cards drawn were not both coins.");
			printf("Copper drawn: %d\tSilver drawn: %d\tGold drawn: %d\n", copperDraw, silverDraw, goldDraw);
			}

	//make sure player2 hasn't had anything happen to their deck or hand
	printf("Test 3 - player 2 should have no change in their hand\n");
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

	printf("Test 4 - player 2 should have no change in their deck\n");
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

	printf("Test 5 - Ensuring appropriate number of cards discarded\n");
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

