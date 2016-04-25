/*
 * cardtest4.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 *
 *      This will test the Baron card.
 *      I have found *critical* *awful* errors in some of the cards implemented intentionally incorrectly,
 *      including some which I did not introduce. This code checks the Baron implementation.
 *
 *
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
void TestChoiceDrawEstate();

void TestChoiceDrawEstate()
{
	int i;
	int seed = 12;
	int numPlayers = 2;
	int numBefore;
	int numAfter;
	struct gameState gameOverTest, gameNotOverTest;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
	int bonus = 0;
	int testOver;

	initializeGame(numPlayers, k, seed, &gameOverTest);
	memcpy(&gameNotOverTest, &gameOverTest, sizeof(struct gameState));


	printf("-------------------------------------------------\n");
	if(isGameOver(&gameOverTest) == 1)
	{
		printf("Bug: Test Cannot Proceed - isGameOver function is likely broken. \n");
		return;
	}
	else
	{
		printf("Test to see if Game Over Triggers: \n");
	}

	gameOverTest.supplyCount[curse] = 0;
	gameOverTest.supplyCount[duchy] = 0;
	gameOverTest.supplyCount[estate] = 1;
	cardEffect(baron, 1, 0, 0, &gameOverTest, 0, &bonus);
	printf("Game over should be triggered at this point. If not TEST FAILED. \n");

	memcpy(&gameOverTest, &gameNotOverTest, sizeof(struct gameState));


	gameOverTest.supplyCount[curse] = 0;
	gameOverTest.supplyCount[duchy] = 0;
	gameOverTest.supplyCount[estate] = 1;
	printf("-------------------------------------------------\n");
	printf("Test to see if numbuys increases:\n");
	numBefore = gameOverTest.numBuys;
	testOver = baronPlay(gameOverTest.whoseTurn,1,0,&gameOverTest);
	numAfter = gameOverTest.numBuys;
	assert(numBefore+1 == numAfter);
	printf("Number of buys is correct. %d expected, %d had.\n", numBefore+1,numAfter);

	printf("-------------------------------------------------\n");

	printf("Testing BaronPlay Function(Directly instead of through cardEffect)\n");
	if(testOver == 1)
	{
		printf("Baron returns 1 when game is over (correct)\n");
	}
	else
	{
		printf("Bug: Baron returns 0 when the game is over(should return 1 or end game).\n");
	}

	printf("-------------------------------------------------\n");

	printf("Attempt to get four coin bonus with no estates:\n");
	memcpy(&gameOverTest, &gameNotOverTest, sizeof(struct gameState));

	for(i = 0; i < gameOverTest.handCount[gameOverTest.whoseTurn]; i++)
	{
		if(gameOverTest.hand[gameOverTest.whoseTurn][i] == estate)
		{
			gameOverTest.hand[gameOverTest.whoseTurn][i] = baron;
		}
	}
	numBefore = gameOverTest.coins;
	cardEffect(baron, 0, 0, 0, &gameOverTest, 0, &bonus);
	numAfter  = gameOverTest.coins;
	assert(numBefore == numAfter);
	printf("Test Succeeded. No un-deserved coins assigned.\n");

	printf("-------------------------------------------------\n");
	printf("Attempt to get four coin bonus with estate in hand.\n");
	memcpy(&gameOverTest, &gameNotOverTest, sizeof(struct gameState));
	gameOverTest.deck[gameOverTest.whoseTurn][0] = estate;
	numBefore = gameOverTest.coins;
	cardEffect(baron, 0, 0, 0, &gameOverTest, 0, &bonus);
	numAfter = gameOverTest.coins;
	assert(numBefore+4 == numAfter);
	printf("Test Succeed. 4 Additional, Deserved Coins Assigned.\n");
	printf("-------------------------------------------------\n");
}


int main() {


	int seed = 12;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
	initializeGame(numPlayers, k, seed, &G);

	printf("Smoke Test To See If Baron Card Crashes Program \n");
	memcpy(&testG, &G, sizeof(struct gameState));
	seahagPlay(testG.whoseTurn, &testG, 0);
	printf("Test Succeeded. \n **************** \n");


	printf("Test Suite Start:\n");
	TestChoiceDrawEstate();
	printf("Test Suite Complete.\n **************** \n");



	// Need is Game Over test. - CHECK (failed/bug)
	// Need test on NumBuys - CHECK
	// Need Test on Other players
	// Need to test on how many estates there are in hand. //
	// Need to test based on if there are estates in game. //
	// Need to test taking last estate in game and WINNING / or going forward. //

	return 0;

}

