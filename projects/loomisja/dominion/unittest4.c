/*******************************************************************************
** Program Filename:unittest4.c
** Author: Jason Loomis
** Date: 4/24/16
** Description: CS 362, Assignment 3
**		Unit test for isGameOver() function.
** Expected Post-Conditions:
**		Determines whether game is over.
**		According to rules found here:
**		http://riograndegames.com/getFile.php?id=348 (see page 8 of PDF)
**		End is when province supply cards are gone OR
**		when 3 supply piles are gone
** Tests:
**		1) return value
**		2) gameState unchanged
** Conditions Tested (for games of 2-MAX_PLAYERS, for each player):
**	Note: for newly initialize game, piles for all card types will
**		be initialized
**	1) No cards (all piles empty), return true
**	2) Newly initialized game (all piles > 0), return false
**	3) Newly initialized game, for each supply pile, empty just that pile
**		return false except for emptied provinces pile which returns true
**	4) Newly initialized game, empty all combinations of 3 piles
**		all combinations of 3 should return true
*******************************************************************************/

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testhelpers.h"

#define TESTFUNC isGameOver
#define FILENAME "unittest4.c"

/*******************************************************************************
** Function: test
** Description: execute tests (see above).
** Parameters:
**		expected: bool, the expected outcome
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
**		passes: count of tests passed
**		failures: count of tests failed
** Pre-Conditions:
**		pre and post are pointers to valid gameState structs
**		passes and failures are pointers to valid integer accumulators
** Post-Conditions: passes and failures are incremented per test results
*******************************************************************************/
test(int expected, struct gameState* pre, struct gameState* post, int* passes, int* failures)
{
	int result;

	/* retain a copy the initial game state for post-comparison */
	copyGameState(post, pre);
	/* execute function */
	result = TESTFUNC(post);
	/* 1) return value */
	if (OUTPUTLEVEL > 1) printf(
		"Result: %s, expected %s. ",
		result ? "true" : "false",
		expected ? "true" : "false");
	if (expected) updateTestResult(result, passes, failures);
	else updateTestResult(!result, passes, failures);
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
** Post-Conditions: Exit code reports the number of failed tests, 0 if all
**		tests succeeded, or greater than if some tests failed.
*******************************************************************************/
int main()
{
	int players;
	int player;

	/* game states */
	struct gameState pre;
	struct gameState post;
	struct gameState state;

	int i;
	int pile1, pile2, pile3;
	int card;
	int expected;

	int passes = 0; /* tests passed */
	int failures = 0; /* tests failed */

	if (OUTPUTLEVEL > 0) printf("*** BEGIN " FILENAME " (unit test for " xstr(TESTFUNC) ") ***\n");

	/* test games with each allowed number of players */
	for (players = 2; players <= MAX_PLAYERS; players++)
	{
		/* initialize a standard game, using a pre-defined set of kingdom cards and random seed */
		initializeGame(players, Kingdom, SEED, &state);

		/* reset all players' hands and decks */
		for (player = 0; player < players; player++)
		{
			state.deckCount[player] += state.handCount[player];
			state.handCount[player] = 0;
		}

		/* ensure ALL supply piles have at least 1 card */
		for (i = 0; i <= treasure_map; i++)
		{
			if (state.supplyCount[i] < 1) state.supplyCount[i] = 1;
		}

		/* test each player */
		for (player = 0; player < players; player++)
		{
			if (OUTPUTLEVEL > 1) printf("\nState: %d players, player index %d.\n", players, player);

			/* 1) No cards (all piles empty), return true */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: all supply piles empty.\n");
			/* set card configuration */
			for (i = 0; i <= treasure_map; i++) pre.supplyCount[i] = 0;
			test(TRUE, &pre, &post, &passes, &failures);

			/* 2) Newly initialized game (all piles > 0, return false */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: all supply piles > 0 cards.\n");
			test(FALSE, &pre, &post, &passes, &failures);

			/* 3) Newly initialized game, for each supply pile, empty just that pile */
			/*    return false except for emptied provinces pile which returns true */
			if (OUTPUTLEVEL > 1) printf("\nTest single empty supply piles (others > 0)...\n");

			for (card = 0; card <= treasure_map; card++)
			{
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);
				if (OUTPUTLEVEL > 1) printf("\nEmpty pile: %d\n", card);
				/* set card configuration */
				pre.supplyCount[card] = 0;
				expected = FALSE;
				if (card == province) expected = TRUE;
				test(expected, &pre, &post, &passes, &failures);
			}

			/*	4) Newly initialized game, empty all combinations of 3 piles */
			/*     all combinations of 3 should return true */
			if (OUTPUTLEVEL > 1) printf("\nTest all combinations of empty supply piles (others > 0)...\n");

			for (pile1 = 0; pile1 <= treasure_map; pile1++)
			{
				for (pile2 = pile1; pile2 <= treasure_map; pile2++)
				{
					for (pile3 = pile2; pile3 <= treasure_map; pile3++)
					{
						if (pile1 == pile2 ||
							pile1 == pile3 ||
							pile2 == pile3) continue; /* only want 3 distinct piles */

						/* get a fresh copy of the base gamestate */
						copyGameState(&pre, &state);
						if (OUTPUTLEVEL > 1) printf("\nEmpty piles: %d, %d, %d\n", pile1, pile2, pile3);
						/* set card configuration */
						pre.supplyCount[pile1] = 0;
						pre.supplyCount[pile2] = 0;
						pre.supplyCount[pile3] = 0;
						expected = TRUE;
						test(expected, &pre, &post, &passes, &failures);
					}
				}
			}
		}
	}

	if (OUTPUTLEVEL > 0)
	{
		printf("\nSUMMARY for " FILENAME " (" xstr(TESTFUNC) "): ");
		if (failures == 0) printf("passed all %d tests.\nTesting Outcome: SUCCESS!\n", passes);
		else
		{
			printf("failed %d of %d tests.\n", failures, passes + failures);
			printf("Testing Outcome: FAILED!\n");
			if (OUTPUTLEVEL > 1) printf("See results output above.\n");
		}
		if (OUTPUTLEVEL > 0) printf("*** END " FILENAME " (unit test for " xstr(TESTFUNC) ") ***\n");
	}

	return failures;
}