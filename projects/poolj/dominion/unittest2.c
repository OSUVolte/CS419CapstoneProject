/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 24 April 2016
**
** Program Filename: unittest2.c
** Description: This is the source file for unit test 2 which covers
**				the buyCard() method in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define PLAYERS 2  /* Must be 1 to 4 */
#define RANDOM_SEED 1  /* Must be positive number, 9 digits or less */

int main() {
	printf("*** Unit test for method: buyCard() ***\n");

	/* Initalize gamestate */
	struct gameState testGame;
	int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	assert(initializeGame(PLAYERS, cards, RANDOM_SEED, &testGame) == 0);  /* Initalize game and verify completion */

	/* Test players */
	int passCount = 0;  /* Number of tests passed */
	int failCount = 0;  /* Number of tests failed */

	for (int i = 0; i < PLAYERS; i++) {
		testGame.whoseTurn = i;  /* Set current player */
		printf("Testing Player %d of %d\n", i+1, PLAYERS);

		/* Player has no buys left */
		testGame.numBuys = 0;  /* Set player to having 0 buys left */
		testGame.coins = 10;  /* Set player coins to 10 (enough to buy any card */
		testGame.supplyCount[adventurer] = 10;  /* Set number of adventurer cards to 10 */
		if (buyCard(adventurer, &testGame) == -1) {  /* buyCard should return -1 */
			printf("  Pass: Player with 0 buys cannot buy a card\n");
			passCount++;
		}
		else {
			printf("  FAIL: Player with 0 buys can buy a card\n");
			failCount++;
		}
		
		/* There are none of the requested cards */
		testGame.numBuys = 10;  /* Set player to having 10 buys left */
		testGame.coins = 10;  /* Set player coins to 10 (enough to buy any card */
		testGame.supplyCount[council_room] = 0;  /* Set council room cards to 0 */
		if (buyCard(council_room, &testGame) == -1) {  /* buyCard should return -1 */
			printf("  Pass: Player cannot buy a card with no supply\n");
			passCount++;
		}
		else {
			printf("  FAIL: Player can buy a card with no supply\n");
			failCount++;
		}
		
		/* Player does not have enough coins */
		testGame.numBuys = 10;  /* Set player to having 10 buys left */
		testGame.coins = 0;  /* Set player coin amount to 0 */
		testGame.supplyCount[feast] = 10;  /* Set feast cards to 0 */
		if (buyCard(feast, &testGame) == -1) {  /* buyCard should return -1 */
			printf("  Pass: Player with 0 coins cannot buy a card\n");
			passCount++;
		}
		else {
			printf("  FAIL: Player with 0 coins can buy a card\n");
			failCount++;
		}
		
		/* Player buys card: # buys -1, card in supply -1, card to player discard, coins - cost */
		testGame.numBuys = 10;  /* Set player to having 10 buys left */
		testGame.coins = 10;  /* Set player coin amount to 10 */
		testGame.supplyCount[gardens] = 10;  /* Set gardens cards to 10 */
		testGame.discardCount[i] = 0;  /* Set number of discards to 0 */
		if (buyCard(gardens, &testGame) == 0) {  /* buyCard was successful*/
			printf("  PASS: buyCard function returned success\n");
			passCount++;
			
			printf("  --- Verifying Successful Game Update ---\n");
			
			/* Test correct card was moved to discard */
			if (testGame.discardCount[i] == 1 && testGame.discard[i][0] == gardens) {
				printf("    PASS: Bought card moved to discard pile\n");
				passCount++;
			}
			else {
				printf("    FAIL: Bought card was not moved to discard pile\n");
				failCount++;
			}

			/* Test if card cost was subtraced from coins */
			if ((testGame.coins + getCost(gardens)) == 10) {
				printf("    PASS: Cost of card correctly removed from coin count\n");
				passCount++;
			}
			else {
				printf("    FAIL: Cost of card incorrectly removed from coin count\n");
				failCount++;
			}

			/* Test if number of buy was reduced by 1 */
			if ((testGame.numBuys + 1) == 10) {
				printf("    PASS: Number of buys correctly reduced\n");
				passCount++;
			}
			else {
				printf("    FAIL: Number of buys incorrectly reduced\n");
				failCount++;
			}
		}
		else {
			printf("  FAIL: Player was unable to buy a card\n");
			failCount++;
		}

		printf("End of player %d testing\n\n", i);
	}

	/* Print overall results */
	printf("Overall test results\n");
	printf("  PASS: %d of %d\n", passCount, passCount + failCount);
	printf("  FAIL: %d of %d\n", failCount, passCount + failCount);

	return 0;
}