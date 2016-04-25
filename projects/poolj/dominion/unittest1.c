/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 23 April 2016
**
** Program Filename: unittest1.c
** Description: This is the source file for unit test 1 which covers
**				the numHandCards() method in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define PLAYERS 2  /* Must be 1 to 4 */
#define RANDOM_SEED 1  /* Must be positive number, 9 digits or less */

int main() {
	printf("*** Unit test for method: numHandCards() ***\n");

	/* Initalize gamestate */
	struct gameState testGame;
	int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	assert(initializeGame(PLAYERS, cards, RANDOM_SEED, &testGame) == 0);  /* Initalize game and verify completion */

	/* Test players */
	int cardCount;  /* Number of cards in player's hand */
	int passCount = 0;  /* Number of tests passed */
	int failCount = 0;  /* Number of tests failed */

	for (int i = 0; i < PLAYERS; i++) {
		testGame.whoseTurn = i;  /* Set current player */
		printf("Testing Player %d of %d\n", i+1, PLAYERS);

		/* Test empty hand */
		testGame.handCount[i] = 0;
		cardCount = numHandCards(&testGame);
		if (cardCount == 0) {
			printf("  PASS: Empty hand count correctly returned %d cards\n", cardCount);
			passCount++;
		}
		else {
			printf("  FAIL: Empty hand count incorrectly returned %d cards\n", cardCount);
			failCount++;
		}

		/* Non-empty hand */
		testGame.handCount[i] = 5;
		cardCount = numHandCards(&testGame);
		if (cardCount == 5) {
			printf("  PASS: Hand of size %d correctly returned %d cards\n", 5, cardCount);
			passCount++;
		}
		else {
			printf("  FAIL: Hand of size %d incorrectly returned %d cards\n", 5, cardCount);
			failCount++;
		}

		printf("End of player %d testing\n\n", i + 1);
	}

	/* Print overall results */
	printf("Overall test results\n");
	printf("  PASS: %d of %d\n", passCount, passCount + failCount);
	printf("  FAIL: %d of %d\n", failCount, passCount + failCount);

	return 0;
}