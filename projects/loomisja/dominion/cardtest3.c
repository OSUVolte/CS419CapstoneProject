/*******************************************************************************
** Program Filename:cardtest3.c
** Author: Jason Loomis
** Date: 4/24/16
** Description: CS 362, Assignment 3
**		Unit test for the Council Room card effect.
** Rule: +4 cards, +1 buy, each other player draws a card
** The following standard conditions are tested for games of 2 to MAX_PLAYERS,
**		for each player, and for the card played from the beginning, end, and middle
**		of the player's hand:
** 1. The played card is added to the played cards pile
** 2. Current player receives N = 4 cards
** 3. N cards received came from the current player's deck
** 4. The number and type of the player's set of cards (in his deck, hand,
**		played, discard) are unchanged (no cards "magically" appear or disappear).
** 5. Current player gets buy counter incremented +1
** 6. Other players each add 1 card to their hands
** 7. Card added to other players' hands came from their decks
** 8. No state changes occur to the supply cards (kingdom, treasure, curse)
**		nor to the victory cards
*******************************************************************************/

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testhelpers.h"

#define CARDUNDERTEST council_room
#define FILENAME "cardtest3.c"


/*******************************************************************************
** Function: testStandardConditions
** Description: execute tests for standard conditions (see above).
** Parameters:
**		players: the number of players
**		player: the current player index
**		handpos: index in hand the card was played from
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
**		passes: count of tests passed
**		failures: count of tests failed
** Pre-Conditions:
**		2 <= players <= MAX_PLAYERS
**		0 <= player < MAX_PLAYERS
**		handpos valid for current player
**		pre and post are pointers to valid gameState structs
**		passes and failures are pointers to valid integer accumulators
** Post-Conditions: passes and failures are incremented per test results
*******************************************************************************/
void testStandardConditions(int players, int player, int handpos, struct gameState* pre, struct gameState* post, int* passes, int* failures)
{
	int i;
	int result, result1, result2;
	int playerDeltas[treasure_map + 1]; /* array of all card types */
	int playedDeltas[treasure_map + 1]; /* array of all card types */

	if (OUTPUTLEVEL > 1) printf("\nState: %d players, player index %d played " xstr(CARDUNDERTEST) " from hand position %d\n", players, player, handpos);

	/* VERIFY POST-CONDITIONS */

	/* 1. The played card is added to the played cards pile */
	/* check playedCardCount */
	if (OUTPUTLEVEL > 1) printf("Test: Count played cards...\n");
	result = deltaPlayedCardCount(pre, post);
	if (OUTPUTLEVEL > 1) printf("Result: Played %d cards, expected %d. ", result, 1);
	updateTestResult(result == 1, passes, failures);

	/* check that the played card is the only type added to playedCards */
	if (OUTPUTLEVEL > 1) printf("Test: Played exactly 1 " xstr(CARDUNDERTEST) " card...\n");
	result = checkSpecificPlayedCard(pre, post, CARDUNDERTEST);
	if (OUTPUTLEVEL > 1) printf("Result: ");
	updateTestResult(result == TRUE, passes, failures);

	/* 2. Current player receives 4 cards */
	if (OUTPUTLEVEL > 1) printf("Test: Count cards added to hand...\n");
	/* check count of cards in play (player hand + played) */
	result = 0;
	result += deltaPlayedCardCount(pre, post);
	result += deltaPlayerHandCount(pre, post, player);
	if (OUTPUTLEVEL > 1) printf("Result: Added %d cards, expected %d. ", result, 4);
	updateTestResult(result == 4, passes, failures);
	result1 = result;

	/* 3. 4 cards received from the current player's deck */
	if (OUTPUTLEVEL > 1) printf("Test: Count cards removed from deck...\n");
	/* check count of cards drawn from player deck */
	result = 0;
	result += deltaPlayerDeckCount(pre, post, player); /* current deck, may include discards shuffled into new deck */
	result += deltaPlayerDiscardCount(pre, post, player); /* discard may have been shuffled into a new deck */
	if (OUTPUTLEVEL > 1) printf("Result: Removed %d cards, expected %d. ", -result, 4); /* deck supply cards should decrease, so check negative of result */
	updateTestResult(-result == 4, passes, failures);
	result2 = -result;

	if (OUTPUTLEVEL > 1) printf("Test: Count cards added to hand == cards removed from deck...\n");
	if (OUTPUTLEVEL > 1) printf("Result: Added %d, removed %d. ", result1, result2);
	updateTestResult(result1 == result2, passes, failures);

	/*
	* 4. The cards of the player's set of cards (in deck, hand, played, discard)
	*    are unchanged(no cards "magically" appear or disappear).
	*/
	/* check count of cards */
	if (OUTPUTLEVEL > 1) printf("Test: Player overall card COUNT (hand + deck + discard + played) unchanged...\n");
	result = 0;
	result += deltaPlayedCardCount(pre, post);
	result += deltaPlayerCardCount(pre, post, player);
	if (OUTPUTLEVEL > 1) printf("Result: ");
	updateTestResult(result == 0, passes, failures);

	/* check type of cards */
	if (OUTPUTLEVEL > 1) printf("Test: Player overall card TYPES (hand + deck + discard + played) unchanged...\n");
	initCounts(playedDeltas);
	deltaPlayedCardTypes(pre, post, playedDeltas);
	initCounts(playerDeltas);
	deltaPlayerCardTypes(pre, post, player, playerDeltas);
	result = 0;
	for (i = 0; i <= treasure_map; i++) result += playedDeltas[i] + playerDeltas[i];
	if (OUTPUTLEVEL > 1) printf("Result: ");
	updateTestResult(result == 0, passes, failures);

	/* 5. Current player gets buy counter incremented +1 */
	if (OUTPUTLEVEL > 1) printf("Test: Current player buy counter incremented +1...\n");
	result = post->numBuys - pre->numBuys;
	if (OUTPUTLEVEL > 1) printf("Result: numBuys increased by %d, expected %d. ", result, 1);
	updateTestResult(result == 1, passes, failures);

	if (OUTPUTLEVEL > 1) printf("Test: Other players +1 card...\n");
	for (i = 0; i < players; i++)
	{
		if (i != player)
		{
			/* 6. Other players each add 1 card to their hands */
			/* check count of cards added to other's hand */
			result = deltaPlayerHandCount(pre, post, i);
			if (OUTPUTLEVEL > 1) printf("Result (player %d): Hand added %d cards, expected %d. ", i, result, 1);
			updateTestResult(result == 1, passes, failures);

			/* 7. Card added to other players' hands came from their decks */
			/* check count of cards removed from other's deck */
			result = deltaPlayerDeckCount(pre, post, i);
			if (OUTPUTLEVEL > 1) printf("Result (player %d): Deck removed %d cards, expected %d. ", i, -result, 1);
			updateTestResult(-result == 1, passes, failures);
		}
	}

	/* 8. No state changes occur to the supply cards(kingdom, treasure, curse) nor to the victory cards */
	if (OUTPUTLEVEL > 1) printf("Test: Curse, Victory, Treasure, Kingdom card COUNTS unchanged...\n");

	result = curseCardStateChanged(pre, post);
	if (OUTPUTLEVEL > 1)
	{
		if (result == FALSE) printf("Result: Curse cards unchanged. ");
		else printf("Result: Curse cards changed. ");
	}
	updateTestResult(result == FALSE, passes, failures);

	result = victoryCardStateChanged(pre, post);
	if (OUTPUTLEVEL > 1)
	{
		if (result == FALSE) printf("Result: Victory cards unchanged. ");
		else printf("Result: Victory cards changed. ");
	}
	updateTestResult(result == FALSE, passes, failures);

	result = treasureCardStateChanged(pre, post);
	if (OUTPUTLEVEL > 1)
	{
		if (result == FALSE) printf("Result: Treasure cards unchanged. ");
		else printf("Result: Treasure cards changed. ");
	}
	updateTestResult(result == FALSE, passes, failures);

	result = kingdomCardStateChanged(pre, post, Kingdom);
	if (OUTPUTLEVEL > 1)
	{
		if (result == FALSE) printf("Result: Kingdom cards unchanged. ");
		else printf("Result: Kingdom cards changed. ");
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
	int handpos;
	int bonus;

	/* game states */
	struct gameState pre;
	struct gameState post;
	struct gameState state;

	int passes = 0; /* tests passed */
	int failures = 0; /* tests failed */

	if (OUTPUTLEVEL > 0) printf("\n*** BEGIN " FILENAME " (cardEffect unit test for " xstr(CARDUNDERTEST) ") ***\n");

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
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* test several hand positions */
			for (handpos = 0; handpos < pre.handCount[player]; handpos++)
			{
				/* test hand positions at either end of the hand and in the middle, skip others */
				if (
					!(handpos == 0 ||
						handpos == pre.handCount[player] / 2 ||
						handpos == (pre.handCount[player] - 1))
					) continue;

				/* retain a copy the initial game state for post-comparison */
				copyGameState(&post, &pre);

				/* perform the card effect */
				bonus = 0;
				cardEffect(CARDUNDERTEST, 0, 0, 0, &post, handpos, &bonus);

				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);
			}
		}
	}

	if (OUTPUTLEVEL > 0)
	{
		if (OUTPUTLEVEL > 1) printf("\n");
		printf("SUMMARY for " FILENAME " (" xstr(CARDUNDERTEST) "): ");
		if (failures == 0) printf("passed all %d tests.\nTesting Outcome: SUCCESS!\n", passes);
		else
		{
			printf("failed %d of %d tests.\n", failures, passes + failures);
			printf("Testing Outcome: FAILED!\n");
			if (OUTPUTLEVEL > 1) printf("See results output above.\n");
		}
		printf("*** END " FILENAME " (cardEffect unit test for " xstr(CARDUNDERTEST) ") ***\n");
	}

	return failures != 0 ? 1 : 0;
}