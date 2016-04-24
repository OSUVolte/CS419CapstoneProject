/*
 * unittest2.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 *
 *      Test discardCard function
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>




int main() {

		int seed = 12;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
				tribute, smithy, council_room };\
		int totalCards=0;
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("-------------------------------------------------\n");
		printf("Trigger Trash Flag Test\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		assert(testG.playedCardCount == 0);
		discardCard(0,testG.whoseTurn, &testG, 1);
		assert(testG.playedCardCount == 0);
		printf("Test Passed! \n");
		printf("-------------------------------------------------\n");

		printf("-------------------------------------------------\n");
		printf("Trigger Trash Flag Not Triggered Test\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		assert(testG.playedCardCount == 0);
		discardCard(0,testG.whoseTurn, &testG, 0);
		if(testG.playedCardCount != 1)
		{
			printf("Test Failed! Played Card Count Not Incremented. \n");
		}
		else
		{
		printf("Test Passed! Trash Card Put In Played Pile\n");
		}
		printf("-------------------------------------------------\n");


		printf("-------------------------------------------------\n");
		printf("Check To See if Card is no longer in deck/discard after discard.\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		totalCards = testG.discardCount[testG.whoseTurn] + testG.deckCount[testG.whoseTurn] + testG.handCount[testG.whoseTurn];
		discardCard(0,testG.whoseTurn, &testG, 0);
		printf("Before is : %d \nAfter is: %d\n", totalCards, testG.discardCount[testG.whoseTurn] + testG.deckCount[testG.whoseTurn] + testG.handCount[testG.whoseTurn]);
		if(totalCards != (testG.discardCount[testG.whoseTurn] + testG.deckCount[testG.whoseTurn] + testG.handCount[testG.whoseTurn]))
		{
			printf("Test Failed! Card Incorrectly Removed From Game!\n");
		}
		else
		{
		printf("Test Passed! \n");
		}
		printf("-------------------------------------------------\n");

		printf("-------------------------------------------------\n");
		printf("Drawing from each hand position(0,1,2)\n");
		memcpy(&testG, &G, sizeof(struct gameState));
		discardCard(0,testG.whoseTurn, &testG,0);
		assert(testG.handCount[testG.whoseTurn] == 4);
		memcpy(&testG, &G, sizeof(struct gameState));
		discardCard(1,testG.whoseTurn, &testG,0);
		assert(testG.handCount[testG.whoseTurn] == 4);
		memcpy(&testG, &G, sizeof(struct gameState));
		discardCard(2,testG.whoseTurn, &testG,0);
		assert(testG.handCount[testG.whoseTurn] == 4);
		printf("-------------------------------------------------\n");
		printf("Test Passed. Card Drawn from all applicable hand positions.\n");


return 0;

}
