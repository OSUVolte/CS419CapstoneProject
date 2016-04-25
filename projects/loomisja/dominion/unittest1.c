/*******************************************************************************
** Program Filename:unittest1.c
** Author: Jason Loomis
** Date: 4/24/16
** Description: CS 362, Assignment 3
**		Unit test for fullDeckCount() function.
** Expected Post-Conditions:
**		Returns the count of a particular card type
**		in player's hand + deck + discard
** Tests:
**		1) return value =
**			count of type in deck[player]
**			count of type in hand[player]
**			count of type in discard[player]
**		2) gameState unchanged
** Conditions Tested (for games of 2-MAX_PLAYERS, for each player):
**	1) No cards
**		0 in deck,0 in hand, 0 in discard (return = 0)
**	2) For each of the enumerated card types...
**		1 in deck, 0 in hand, 0 in discard (return = 1)
**		0 in deck, 1 in hand, 0 in discard (return = 1)
**		0 in deck, 0 in hand, 1 in discard (return = 1)
**		1 in deck, 1 in hand, 1 in discard (return = 3)
**		5 in deck, 5 in hand, 5 in discard (return = 15)
**	3) Needle in a haystack
**		Find one card (smithy) among deck of a different type (estate)
**		1 smithy + 4 estate in deck, 5 estate in hand, 5 estate in discard (return = 1)
**		5 estate in deck, 1 smithy + 4 estate in hand, 5 estate in discard (return = 1)
**		5 estate in deck, 5 estate in hand, 1 smithy + 4 estate in discard (return = 1)
**		1 smithy + 4 estate in deck,
**			1 smithy + 4 estate in hand,
**			1 smithy + 4 estate in discard
**			(return = 3)
*******************************************************************************/

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testhelpers.h"

#define TESTFUNC fullDeckCount
#define FILENAME "unittest1.c"

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
	struct gameState state;

	int i;
	int result, expected;
	int populatedcard, searchcard;

	int passes = 0; /* tests passed */
	int failures = 0; /* tests failed */

	if (OUTPUTLEVEL > 0) printf("\n*** BEGIN " FILENAME " (unit test for " xstr(TESTFUNC) ") ***\n");

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

			for (searchcard = 0; searchcard <= treasure_map; searchcard++)
			{
				/* retain a copy the initial game state for post-comparison */
				copyGameState(&post, &pre);

				if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", searchcard);

				/* execute function */
				result = TESTFUNC(player, searchcard, &post);

				/* 1) return value */
				if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, 0);
				updateTestResult(result == 0, &passes, &failures);

				/* 2) gameState unchanged */
				result = gameStateChanged(&pre, &post);
				if (OUTPUTLEVEL > 1)
				{
					if (result == FALSE) printf("Result: gameState unchanged. ");
					else printf("Result: gameState changed. ");
				}
				updateTestResult(result == FALSE, &passes, &failures);
			}


			/* 2) For each of the enumerated card types...*/
			for (populatedcard = 0; populatedcard <= treasure_map; populatedcard++)
			{
				/* 1 in deck, 0 in hand, 0 in discard (return = 1) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Card type in deck: %d\n", populatedcard);
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 1, hand = 0, discard = 0\n");
				pre.deckCount[player] = 1;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = populatedcard;
				pre.handCount[player] = 0;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = populatedcard;
				pre.discardCount[player] = 0;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = populatedcard;

				for (searchcard = 0; searchcard <= treasure_map; searchcard++)
				{
					/* retain a copy the initial game state for post-comparison */
					copyGameState(&post, &pre);

					if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", searchcard);

					/* execute function */
					result = TESTFUNC(player, searchcard, &post);

					/* 1) return value */
					expected = searchcard == populatedcard ? 1 : 0;
					if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, expected);
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

				/* 0 in deck, 1 in hand, 0 in discard (return = 1) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Card type in deck: %d\n", populatedcard);
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 0, hand = 1, discard = 0\n");
				pre.deckCount[player] = 0;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = populatedcard;
				pre.handCount[player] = 1;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = populatedcard;
				pre.discardCount[player] = 0;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = populatedcard;

				for (searchcard = 0; searchcard <= treasure_map; searchcard++)
				{
					/* retain a copy the initial game state for post-comparison */
					copyGameState(&post, &pre);

					if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", searchcard);

					/* execute function */
					result = TESTFUNC(player, searchcard, &post);

					/* 1) return value */
					expected = searchcard == populatedcard ? 1 : 0;
					if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, expected);
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

				/* 0 in deck, 0 in hand, 1 in discard (return = 1) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Card type in deck: %d\n", populatedcard);
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 0, hand = 0, discard = 1\n");
				pre.deckCount[player] = 0;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = populatedcard;
				pre.handCount[player] = 0;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = populatedcard;
				pre.discardCount[player] = 1;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = populatedcard;

				for (searchcard = 0; searchcard <= treasure_map; searchcard++)
				{
					/* retain a copy the initial game state for post-comparison */
					copyGameState(&post, &pre);

					if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", searchcard);

					/* execute function */
					result = TESTFUNC(player, searchcard, &post);

					/* 1) return value */
					expected = searchcard == populatedcard ? 1 : 0;
					if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, expected);
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

				/* 1 in deck, 1 in hand, 1 in discard (return = 3) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Card type in deck: %d\n", populatedcard);
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 1, hand = 1, discard = 1\n");
				pre.deckCount[player] = 1;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = populatedcard;
				pre.handCount[player] = 1;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = populatedcard;
				pre.discardCount[player] = 1;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = populatedcard;

				for (searchcard = 0; searchcard <= treasure_map; searchcard++)
				{
					/* retain a copy the initial game state for post-comparison */
					copyGameState(&post, &pre);

					if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", searchcard);

					/* execute function */
					result = TESTFUNC(player, searchcard, &post);

					/* 1) return value */
					expected = searchcard == populatedcard ? 3 : 0;
					if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, expected);
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

				/* 5 in deck, 5 in hand, 5 in discard (return = 15) */
				/* get a fresh copy of the base gamestate */
				copyGameState(&pre, &state);

				/* set card configuration */
				if (OUTPUTLEVEL > 1) printf("Card type in deck: %d\n", populatedcard);
				if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 5, hand = 5, discard = 5\n");
				pre.deckCount[player] = 5;
				for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = populatedcard;
				pre.handCount[player] = 5;
				for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = populatedcard;
				pre.discardCount[player] = 5;
				for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = populatedcard;

				for (searchcard = 0; searchcard <= treasure_map; searchcard++)
				{
					/* retain a copy the initial game state for post-comparison */
					copyGameState(&post, &pre);

					if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", searchcard);

					/* execute function */
					result = TESTFUNC(player, searchcard, &post);

					/* 1) return value */
					expected = searchcard == populatedcard ? 15 : 0;
					if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, expected);
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


			/* 3) Needle in a haystack */

			/* 4 estate + 1 smithy in deck, 5 estate in hand, 5 estate in discard (return = 1) */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 4 estate + 1 smithy, hand = 5 estate, discard = 5 estate\n");
			pre.deckCount[player] = 5;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = estate;
			pre.handCount[player] = 5;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = estate;
			pre.discardCount[player] = 5;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = estate;
			pre.deck[player][pre.deckCount[player] - 1] = smithy;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", smithy);
			/* execute function */
			result = TESTFUNC(player, smithy, &post);
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, 1);
			updateTestResult(result == 1, &passes, &failures);
			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);

			/* 5 estate in deck, 4 estate + 1 smithy in hand, 5 estate in discard (return = 1) */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 5 estate, hand = 4 estate + 1 smithy, discard = 5 estate\n");
			pre.deckCount[player] = 5;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = estate;
			pre.handCount[player] = 5;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = estate;
			pre.discardCount[player] = 5;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = estate;
			pre.hand[player][pre.handCount[player] - 1] = smithy;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", smithy);
			/* execute function */
			result = TESTFUNC(player, smithy, &post);
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, 1);
			updateTestResult(result == 1, &passes, &failures);
			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);

			/* 5 estate in deck, 5 estate in hand, 4 estate + 1 smithy in discard (return = 1) */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 5 estate, hand = 5 estate, discard = 4 estate + 1 smithy\n");
			pre.deckCount[player] = 5;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = estate;
			pre.handCount[player] = 5;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = estate;
			pre.discardCount[player] = 5;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = estate;
			pre.discard[player][pre.discardCount[player] - 1] = smithy;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", smithy);
			/* execute function */
			result = TESTFUNC(player, smithy, &post);
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, 1);
			updateTestResult(result == 1, &passes, &failures);
			/* 2) gameState unchanged */
			result = gameStateChanged(&pre, &post);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("Result: gameState unchanged. ");
				else printf("Result: gameState changed. ");
			}
			updateTestResult(result == FALSE, &passes, &failures);

			/* 4 estate + 1 smithy in deck, 4 estate + 1 smithy in hand, 4 estate + 1 smithy in discard (return = 1) */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);
			if (OUTPUTLEVEL > 1) printf("Test Condition: deck = 4 estate + 1 smithy, hand = 4 estate + 1 smithy, discard = 4 estate + 1 smithy\n");
			pre.deckCount[player] = 5;
			for (i = 0; i < pre.deckCount[player]; i++) pre.deck[player][i] = estate;
			pre.handCount[player] = 5;
			for (i = 0; i < pre.handCount[player]; i++) pre.hand[player][i] = estate;
			pre.discardCount[player] = 5;
			for (i = 0; i < pre.discardCount[player]; i++) pre.discard[player][i] = estate;
			pre.hand[player][pre.handCount[player] - 1] = smithy;
			pre.deck[player][pre.deckCount[player] - 1] = smithy;
			pre.discard[player][pre.discardCount[player] - 1] = smithy;
			/* retain a copy the initial game state for post-comparison */
			copyGameState(&post, &pre);
			if (OUTPUTLEVEL > 1) printf("Search Card Type: %d\n", smithy);
			/* execute function */
			result = TESTFUNC(player, smithy, &post);
			/* 1) return value */
			if (OUTPUTLEVEL > 1) printf("Result: count %d, expected %d. ", result, 3);
			updateTestResult(result == 3, &passes, &failures);
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