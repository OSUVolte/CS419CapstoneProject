/*******************************************************************************
** Program Filename:unittest3.c
** Author: Jason Loomis
** Date: 4/24/16
** Description: CS 362, Assignment 3
**		Unit test for scoreFor() function.
** Expected Post-Conditions:
**		Calculate the player's score by summing Victory cards
**		in player's hand + deck + discard
** Tests:
**		1) return value =
**			score from deck[player]
**			score from hand[player]
**			score from discard[player]
**		2) gameState unchanged
** Conditions Tested (for games of 2-MAX_PLAYERS, for each player):
**	1) No cards
**		0 in deck,0 in hand, 0 in discard (return = 0)
**	2) For each of the enumerated card types...
**		(note: gardens is special case)
**		1 in deck, 0 in hand, 0 in discard (return = 1 * card VP)
**		0 in deck, 1 in hand, 0 in discard (return = 1 * card VP)
**		0 in deck, 0 in hand, 1 in discard (return = 1 * card VP)
**		1 in deck, 1 in hand, 1 in discard (return = 3 * card VP)
**		2 in deck, 2 in hand, 2 in discard (return = 6 * card VP)
**	3) 1 of each card...
**		...in hand; deck, discard empty (return = 10 + 27/10 = 12)
**		...in deck; hand, discard empty (return = 10 + 27/10 = 12)
**		...in discard; deck, hand empty (return = 10 + 27/10 = 12)
**		...in hand, deck, and discard (return = 30 + 81/10 = 38)
*******************************************************************************/

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testhelpers.h"

#define TESTFUNC scoreFor
#define FILENAME "unittest3.c"

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
	int card;
	int result, expected;

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

		/* test each player */
		for (player = 0; player < players; player++)
		{
			if (OUTPUTLEVEL > 1) printf("\nState: %d players, player index %d.\n", players, player);

			/* 1) No cards */

			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* set card configuration */
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 0, hand = 0, discard = 0\n");
			pre.deckCount[player] = 0;
			pre.handCount[player] = 0;
			pre.discardCount[player] = 0;

			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);

			/* execute function */
			result = TESTFUNC(player, &post);

			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, 0);
			updateTestResult(result == 0, &passes, &failures);

			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);

			/* 2) For each of the enumerated card types...*/
			for (card = 0; card <= treasure_map; card++)
			{
				if (OUTPUTLEVEL > 1) printf("\nCard type in deck: %d\n", card);

				/* 1 in deck, 0 in hand, 0 in discard (return = 1 * card VP) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 1, hand = 0, discard = 0\n");
				pre.deckCount[player] = 1;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = card;
				pre.handCount[player] = 0;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = card;
				pre.discardCount[player] = 0;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = card;
				/* retain a copy the initial game state for post-comparison */
				copyGameState(&post, &pre);
				result = TESTFUNC(player, &post);
				expected = 0;
				if (card == curse) expected = -1;
				else if (card == estate) expected = 1;
				else if (card == duchy) expected = 3;
				else if (card == province) expected = 6;
				else if (card == gardens) expected = 1 / 10;
				else if (card == great_hall) expected = 1;

				/* 1) return value */
				if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
				updateTestResult(result == expected, &passes, &failures);

				/* 2) gameState unchanged */
				result = gameStateChanged(&pre, &post);
				if (OUTPUTLEVEL > 1)
				{
					if (result == FALSE) printf("Result: gameState unchanged. ");
					else printf("Result: gameState changed. ");
				}
				updateTestResult(result == FALSE, &passes, &failures);

				/* 0 in deck, 1 in hand, 0 in discard (return = 1 * card VP) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 0, hand = 1, discard = 0\n");
				pre.deckCount[player] = 0;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = card;
				pre.handCount[player] = 1;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = card;
				pre.discardCount[player] = 0;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = card;
				/* retain a copy the initial game state for post-comparison */
				copyGameState(&post, &pre);
				result = TESTFUNC(player, &post);
				expected = 0;
				if (card == curse) expected = -1;
				else if (card == estate) expected = 1;
				else if (card == duchy) expected = 3;
				else if (card == province) expected = 6;
				else if (card == gardens) expected = 1 / 10;
				else if (card == great_hall) expected = 1;

				/* 1) return value */
				if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
				updateTestResult(result == expected, &passes, &failures);

				/* 2) gameState unchanged */
				result = gameStateChanged(&pre, &post);
				if (OUTPUTLEVEL > 1)
				{
					if (result == FALSE) printf("Result: gameState unchanged. ");
					else printf("Result: gameState changed. ");
				}
				updateTestResult(result == FALSE, &passes, &failures);

				/* 0 in deck, 0 in hand, 1 in discard (return = 1 * card VP) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 0, hand = 0, discard = 1\n");
				pre.deckCount[player] = 0;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = card;
				pre.handCount[player] = 0;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = card;
				pre.discardCount[player] = 1;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = card;
				/* retain a copy the initial game state for post-comparison */
				copyGameState(&post, &pre);
				result = TESTFUNC(player, &post);
				expected = 0;
				if (card == curse) expected = -1;
				else if (card == estate) expected = 1;
				else if (card == duchy) expected = 3;
				else if (card == province) expected = 6;
				else if (card == gardens) expected = 1 / 10;
				else if (card == great_hall) expected = 1;

				/* 1) return value */
				if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
				updateTestResult(result == expected, &passes, &failures);

				/* 2) gameState unchanged */
				result = gameStateChanged(&pre, &post);
				if (OUTPUTLEVEL > 1)
				{
					if (result == FALSE) printf("Result: gameState unchanged. ");
					else printf("Result: gameState changed. ");
				}
				updateTestResult(result == FALSE, &passes, &failures);

				/* 1 in deck, 1 in hand, 1 in discard (return = 3 * card VP) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 1, hand = 1, discard = 1\n");
				pre.deckCount[player] = 1;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = card;
				pre.handCount[player] = 1;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = card;
				pre.discardCount[player] = 1;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = card;
				/* retain a copy the initial game state for post-comparison */
				copyGameState(&post, &pre);
				result = TESTFUNC(player, &post);
				expected = 0;
				if (card == curse) expected = -1 * 3;
				else if (card == estate) expected = 1 * 3;
				else if (card == duchy) expected = 3 * 3;
				else if (card == province) expected = 6 * 3;
				else if (card == gardens) expected = 3 / 10;
				else if (card == great_hall) expected = 1 * 3;

				/* 1) return value */
				if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
				updateTestResult(result == expected, &passes, &failures);

				/* 2) gameState unchanged */
				result = gameStateChanged(&pre, &post);
				if (OUTPUTLEVEL > 1)
				{
					if (result == FALSE) printf("Result: gameState unchanged. ");
					else printf("Result: gameState changed. ");
				}
				updateTestResult(result == FALSE, &passes, &failures);

				/* 2 in deck, 2 in hand, 2 in discard (return = 6 * card VP) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 2, hand = 2, discard = 2\n");
				pre.deckCount[player] = 1;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = card;
				pre.handCount[player] = 1;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = card;
				pre.discardCount[player] = 1;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = card;
				/* retain a copy the initial game state for post-comparison */
				copyGameState(&post, &pre);
				result = TESTFUNC(player, &post);
				expected = 0;
				if (card == curse) expected = -1 * 6;
				else if (card == estate) expected = 1 * 6;
				else if (card == duchy) expected = 3 * 6;
				else if (card == province) expected = 6 * 6;
				else if (card == gardens) expected = 6 / 10;
				else if (card == great_hall) expected = 1 * 6;

				/* 1) return value */
				if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
				updateTestResult(result == expected, &passes, &failures);

				/* 2) gameState unchanged */
				result = gameStateChanged(&pre, &post);
				if (OUTPUTLEVEL > 1)
				{
					if (result == FALSE) printf("Result: gameState unchanged. ");
					else printf("Result: gameState changed. ");
				}
				updateTestResult(result == FALSE, &passes, &failures);
			}

			/* 3) 1 of each card... */
			if (OUTPUTLEVEL > 1) printf("\nTest decks containing all card types...\n");

			/* ...in hand; deck, discard empty (return = 10 + 27/10 = 12) */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 1 of each card, hand = 0, discard = 0\n");
			pre.deckCount[player] = treasure_map + 1;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = i;
			pre.handCount[player] = 0;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = i;
			pre.discardCount[player] = 0;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = i;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			result = TESTFUNC(player, &post);
			expected = 10 + 27 / 10;
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
			updateTestResult(result == expected, &passes, &failures);
			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);

			/* ...in deck; hand, discard empty (return = 10 + 27/10 = 12) */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 0, hand = 1 of each card, discard = 0\n");
			pre.deckCount[player] = 0;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = i;
			pre.handCount[player] = treasure_map + 1;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = i;
			pre.discardCount[player] = 0;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = i;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			result = TESTFUNC(player, &post);
			expected = 10 + 27 / 10;
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
			updateTestResult(result == expected, &passes, &failures);
			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);

			/* ...in discard; deck, hand empty (return = 10 + 27/10 = 12) */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 0, hand = 0, discard = 1 of each card\n");
			pre.deckCount[player] = 0;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = i;
			pre.handCount[player] = 0;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = i;
			pre.discardCount[player] = treasure_map + 1;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = i;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			result = TESTFUNC(player, &post);
			expected = 10 + 27 / 10;
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
			updateTestResult(result == expected, &passes, &failures);
			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);

			/* ...in hand, deck, and discard (return = 30 + 81/10 = 38) */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 1 of each, hand = 1 of each, discard = 1 of each\n");
			pre.deckCount[player] = 0;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = i;
			pre.handCount[player] = 0;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = i;
			pre.discardCount[player] = treasure_map + 1;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = i;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			result = TESTFUNC(player, &post);
			expected = 30 + 81 / 10;
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: score %d, expected %d. ", result, expected);
			updateTestResult(result == expected, &passes, &failures);
			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);
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