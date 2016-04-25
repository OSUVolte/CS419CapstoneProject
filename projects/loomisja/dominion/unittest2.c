/*******************************************************************************
** Program Filename:unittest2.c
** Author: Jason Loomis
** Date: 4/24/16
** Description: CS 362, Assignment 3
**		Unit test for getCost() function.
** Expected Post-Conditions:
**		Returns the (purchase) cost of any game card
** Tests:
**		1) return value = purchase cost of card,
**			values as detailed in game card documentation
**			found here: https://dominionstrategy.com/all-cards/
**		2) gameState unchanged
** Conditions Tested (for games of 2-MAX_PLAYERS, for each player):
**	1) Tested for each of the enumerated card types
*******************************************************************************/

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testhelpers.h"

#define TESTFUNC getCost
#define FILENAME "unittest2.c"

/*******************************************************************************
** Function: test
** Description: execute tests (see above).
** Parameters:
**		card: the card type to test
**		expectedcost: the expected cost of the card type
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
**		passes: count of tests passed
**		failures: count of tests failed
** Pre-Conditions:
**		pre and post are pointers to valid gameState structs
**		passes and failures are pointers to valid integer accumulators
** Post-Conditions: passes and failures are incremented per test results
*******************************************************************************/
void test(int card, int expectedcost, struct gameState* pre, struct gameState* post, int* passes, int* failures)
{
	int result;

	/* retain a copy the initial game state for post-comparison */
	copyGameState(post, pre);

	/* 1) return value */
	result = TESTFUNC(card);
	if (OUTPUTLEVEL > 1) printf("Card %d cost %d, expected %d. ", card, result, expectedcost);
	updateTestResult(result == expectedcost, passes, failures);

	/* 2) gameState unchanged */
	result = gameStateChanged(pre, post);
	if (OUTPUTLEVEL > 1)
	{
		if (result == FALSE) printf("Result: gameState unchanged. ");
		else printf("Result: gameState changed. ");
	}
	updateTestResult(result == FALSE, passes, failures);
}

/*******************************************************************************
** Function: main
** Description: entrypoint for unit test.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Exit code 0 if all tests succeeded, otherwise 1.
*******************************************************************************/
int main()
{
	int players;
	int player;

	/* game states */
	struct gameState pre;
	struct gameState post;

	int passes = 0; /* tests passed */
	int failures = 0; /* tests failed */

	if (OUTPUTLEVEL > 0) printf("\n*** BEGIN " FILENAME " (unit test for " xstr(TESTFUNC) ") ***\n");

	/* test games with each allowed number of players */
	for (players = 2; players <= MAX_PLAYERS; players++)
	{
		/* initialize a standard game, using a pre-defined set of kingdom cards and random seed */
		initializeGame(players, Kingdom, SEED, &pre);

		/* test each player */
		for (player = 0; player < players; player++)
		{
			if (OUTPUTLEVEL > 1) printf("\nState: %d players, player index %d.\n", players, player);

			/* test each card, costs found here: https://dominionstrategy.com/all-cards/ */
			test(curse, 0, &pre, &post, &passes, &failures); /* curse = $0 */
			test(estate, 2, &pre, &post, &passes, &failures); /* estate = $2 */
			test(duchy, 5, &pre, &post, &passes, &failures); /* duchy = $5 */
			test(province, 8, &pre, &post, &passes, &failures); /* province = $8 */
			test(copper, 0, &pre, &post, &passes, &failures); /* copper = $0 */
			test(silver, 3, &pre, &post, &passes, &failures); /* silver = $3 */
			test(gold, 6, &pre, &post, &passes, &failures); /* gold = $6 */
			test(adventurer, 6, &pre, &post, &passes, &failures); /* adventurer = $6 */
			test(council_room, 5, &pre, &post, &passes, &failures); /* council_room = $5 */
			test(feast, 4, &pre, &post, &passes, &failures); /* feast = $4 */
			test(gardens, 4, &pre, &post, &passes, &failures); /* gardens = $4 */
			test(mine, 5, &pre, &post, &passes, &failures); /* mine = $5 */
			test(remodel, 4, &pre, &post, &passes, &failures); /* remodel = $4 */
			test(smithy, 4, &pre, &post, &passes, &failures); /* smithy = $4 */
			test(village, 3, &pre, &post, &passes, &failures); /* village = $3 */
			test(baron, 4, &pre, &post, &passes, &failures); /* baron = $4 */
			test(great_hall, 3, &pre, &post, &passes, &failures); /* great_hall = $3 */
			test(minion, 5, &pre, &post, &passes, &failures); /* minion = $5 */
			test(steward, 3, &pre, &post, &passes, &failures); /* steward = $3 */
			test(tribute, 5, &pre, &post, &passes, &failures); /* tribute = $5 */
			test(ambassador, 3, &pre, &post, &passes, &failures); /* ambassador = $3 */
			test(cutpurse, 4, &pre, &post, &passes, &failures); /* cutpurse = $4 */
			test(embargo, 2, &pre, &post, &passes, &failures); /* embargo = $2 */
			test(outpost, 5, &pre, &post, &passes, &failures); /* outpost = $5 */
			test(salvager, 4, &pre, &post, &passes, &failures); /* salvager = $4 */
			test(sea_hag, 4, &pre, &post, &passes, &failures); /* sea_hag = $4 */
			test(treasure_map, 4, &pre, &post, &passes, &failures); /* treasure_map = $4 */

			/* boundaries, all should return invalid -1  */
			test(curse - 1, -1, &pre, &post, &passes, &failures);
			test(treasure_map + 1, -1, &pre, &post, &passes, &failures);
		}
	}

	if (OUTPUTLEVEL > 0)
	{
		if (OUTPUTLEVEL > 1) printf("\n");
		printf("SUMMARY for " FILENAME " (" xstr(TESTFUNC) "): ");
		if (failures == 0) printf("passed all %d tests.\nTesting Outcome: SUCCESS!\n", passes);
		else
		{
			printf("failed %d of %d tests.\n", failures, passes + failures);
			printf("Testing Outcome: FAILED!\n");
			if (OUTPUTLEVEL > 1) printf("See results output above.\n");
		}
		if (OUTPUTLEVEL > 0) printf("*** END " FILENAME " (unit test for " xstr(TESTFUNC) ") ***\n");
	}

	return failures != 0 ? 1 : 0;
}