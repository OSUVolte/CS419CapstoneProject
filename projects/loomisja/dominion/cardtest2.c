/*******************************************************************************
** Program Filename:cardtest2.c
** Author: Jason Loomis
** Date: 4/24/16
** Description: CS 362, Assignment 3
**		Unit test for the Adventurer card effect.
** Rule: Reveal cards from your deck until you reveal 2 treasure cards.
**		Put those Treasure cards in your hand and discard the other revealed
**		cards.
** The following standard conditions are tested for games of 2 to MAX_PLAYERS,
**		for each player, and for the card played from the beginning, end, and middle
**		of the player's hand:
** 1. The played card is added to the played cards pile
** 2. Player receives N <= 2 treasure (copper, silver, gold) cards in his hand
** 3. N treasure cards received came from the player's deck (+ discard)
** 4. The number and type of the player's set of cards (in his deck, hand,
**		played, discard) are unchanged (no cards "magically" appear or disappear).
** 5. No state changes occur to other players
** 6. No state changes occur to the supply cards (kingdom, treasure, curse)
**		nor to the victory cards
**
** Also test for the following extra conditions,
**		based by using the following player state permutations:
** note: hand always contains 5 adventurer cards
** 1) Ensure that card effect picks gold from revealed cards
**		deck: 3 gold cards
**		discard: empty
**		(verify 2 gold treasures drawn, discard empty)
** 2) Ensure that card effect picks silver from revealed cards
**		deck: 3 silver cards
**		discard: empty
**		(verify 2 silver treasures drawn, discard empty)
** 3) Ensure that card effect picks copper from revealed cards
**		deck: 3 copper cards
**		discard: empty
**		(verify 2 copper treasures drawn, discard empty)
** 4) Ensure that card effect picks only treasure cards when mixed with non-treasure cards;
**		also, does not skip treasure cards
**		deck: 1 estate on top, followed by gold, estate, silver, estate, copper, estate
**		discard: empty
**		(verify discard contains 1 estate card, hand contains gold + silver)
** 5) Ensure that card effect picks only treasure cards when mixed with non-treasure cards;
**		also, does not skip treasure cards
**		deck: 1 estate on top, followed by copper, estate, silver, estate, gold, estate
**		discard: empty
**		(verify discard contains only estate card, hand contains copper + silver)
** 6) Ensure card effect causes deck to be reshuffled when cards run out
**		deck: empty
**		discard: 1 gold, 1 silver, 1 copper
**		(verify shuffle and draw 2 treasures, no discards)
** 7) Ensure card effect will draw a single treasure card
**		deck: 1 gold
**		discard: empty
**		(verify exactly 1 gold added to hand)
** 8) Ensure card effect will draw a single treasure card
**		deck: 1 silver
**		discard: empty
**		(verify exactly 1 silver added to hand)
** 9) Ensure card effect will draw a single treasure card
**		deck: 1 copper
**		discard: empty
**		(verify exactly 1 copper added to hand)
** 10) Ensure card effect will draw no cards if no treasures are available
**		deck: 5 estates, 0 treasures
**		discard: empty
**		(verify 0 cards added to hand, all estates discarded)
*******************************************************************************/

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testhelpers.h"

#define CARDUNDERTEST adventurer
#define FILENAME "cardtest2.c"

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
	int treasures;
	int playerDeltas[treasure_map + 1]; /* array of all card types */
	int playedDeltas[treasure_map + 1]; /* array of all card types */
	int handDeltas[treasure_map + 1]; /* array of all card types */

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

	/* 2. Current player receives <= 2 cards */
	if (OUTPUTLEVEL > 1) printf("Test: Count cards added to hand...\n");
	/* check count of cards in play (player hand + played) */
	result = 0;
	result += deltaPlayedCardCount(pre, post);
	result += deltaPlayerHandCount(pre, post, player);
	if (OUTPUTLEVEL > 1) printf("Result: Added %d cards, expected <= %d. ", result, 2);
	updateTestResult(result <= 2 && result >= 0, passes, failures);
	result1 = result;

	/* Cards added are treasure cards */
	if (OUTPUTLEVEL > 1) printf("Test: Cards added to hand are treasures...\n");
	deltaPlayerCardTypesInHand(pre, post, player, handDeltas);
	result = TRUE;
	treasures = 0;
	for (i = 0; i <= treasure_map; i++)
	{
		if (i == copper || i == silver || i == gold)
		{
			if (handDeltas[i] < 0) result = FALSE;
			treasures += handDeltas[i];
		}
		else if (i == CARDUNDERTEST) /* card that was played */
		{
			if (handDeltas[i] != -1) result = FALSE;
		}
		else
		{
			if (handDeltas[i] != 0) result = FALSE;
		}
	}
	if (OUTPUTLEVEL > 1) printf("Result: ");
	updateTestResult(result == TRUE && treasures >= 0, passes, failures);

	/* 3. <= 2 cards received from the current player's deck */
	if (OUTPUTLEVEL > 1) printf("Test: Count cards removed from deck...\n");
	/* check count of cards drawn from player deck */
	result = 0;
	result += deltaPlayerDeckCount(pre, post, player); /* current deck, may include discards shuffled into new deck */
	result += deltaPlayerDiscardCount(pre, post, player); /* discard may have been shuffled into a new deck */
	if (OUTPUTLEVEL > 1) printf("Result: Removed %d cards, expected <= %d. ", -result, 2); /* deck supply cards should decrease, so check negative of result */
	updateTestResult(-result <= 2 && -result >= 0, passes, failures);
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

	/* 5. No state changes occur to other players */
	if (OUTPUTLEVEL > 1) printf("Test: Other players' states unchanged...\n");
	for (i = 0; i < players; i++)
	{
		if (i != player)
		{
			if (OUTPUTLEVEL > 1) printf("Result: Player %d state: ", i);
			result = playerCardStateChanged(pre, post, i);
			if (OUTPUTLEVEL > 1)
			{
				if (result == FALSE) printf("unchanged. ");
				else printf("changed. ");
			}
			updateTestResult(result == FALSE, passes, failures);
		}
	}

	/* 6. No state changes occur to the supply cards(kingdom, treasure, curse) nor to the victory cards */
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
** Post-Conditions: Exit code reports the number of failed tests, 0 if all
**		tests succeeded, or greater than if some tests failed.
*******************************************************************************/
int main()
{
	int players;
	int player;
	int handpos, deckpos;
	int bonus;
	struct gameState pre;
	struct gameState post;
	struct gameState state;

	int i;
	int result;
	int treasures;
	int handDeltas[treasure_map + 1]; /* array of all card types */
	int discardDeltas[treasure_map + 1]; /* array of all card types */

	int passes = 0; /* tests passed */
	int failures = 0; /* tests failed */

	if (OUTPUTLEVEL > 0) printf("*** BEGIN " FILENAME " (cardEffect unit test for " xstr(CARDUNDERTEST) ") ***\n");

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
			/* 1) Ensure that card effect picks gold from revealed cards */

			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 3 gold cards, discard : empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 3;
			for (deckpos = 0; deckpos < pre.deckCount[player]; deckpos++) pre.deck[player][deckpos] = gold;
			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck 3 gold cards, discard empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify exactly 2 gold treasures drawn */
				if (OUTPUTLEVEL > 1) printf("Test: Exactly 2 golds added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == gold)
					{
						if (handDeltas[i] != 2) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);

				/* verify discard state is unchanged */
				if (OUTPUTLEVEL > 1) printf("Test: Player discard state unchanged...\n");
				result = deltaPlayerDiscardCount(&pre, &post, player);
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == 0, &passes, &failures);
			}

			/* 2) Ensure that card effect picks silver from revealed cards */

			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 3 silver cards, discard : empty */
			pre.deckCount[player] = 3;
			pre.discardCount[player] = 0;
			for (deckpos = 0; deckpos < pre.deckCount[player]; deckpos++) pre.deck[player][deckpos] = silver;
			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck 3 silver cards, discard empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify exactly 2 silver treasures drawn */
				if (OUTPUTLEVEL > 1) printf("Test: Exactly 2 silvers added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == silver)
					{
						if (handDeltas[i] != 2) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);

				/* verify discard state is unchanged */
				if (OUTPUTLEVEL > 1) printf("Test: Player discard state unchanged...\n");
				result = deltaPlayerDiscardCount(&pre, &post, player);
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == 0, &passes, &failures);
			}

			/* 3) Ensure that card effect picks copper from revealed cards */

			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 3 copper cards, discard : empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 3;
			for (deckpos = 0; deckpos < pre.deckCount[player]; deckpos++) pre.deck[player][deckpos] = copper;
			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck 3 copper cards, discard empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify exactly 2 copper treasures drawn */
				if (OUTPUTLEVEL > 1) printf("Test: Exactly 2 coppers added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == copper)
					{
						if (handDeltas[i] != 2) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);

				/* verify discard state is unchanged */
				if (OUTPUTLEVEL > 1) printf("Test: Player discard state unchanged...\n");
				result = deltaPlayerDiscardCount(&pre, &post, player);
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == 0, &passes, &failures);
			}

			/* 
			 * 4) Ensure that card effect picks only treasure cards when mixed
			 *    with non-treasure cards; also, does not skip treasure cards
			 */

			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 1 estate on top, followed by gold, estate, silver, estate, copper, estate; discard: empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 7;
			pre.deck[player][6] = estate; /* top of deck */
			pre.deck[player][5] = gold;
			pre.deck[player][4] = estate;
			pre.deck[player][3] = silver;
			pre.deck[player][2] = estate;
			pre.deck[player][1] = copper;
			pre.deck[player][0] = estate;

			if (OUTPUTLEVEL > 1) printf("Card Configuration: 1 estate on top, followed by gold, estate, silver, estate, copper, estate; discard: empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify discard contains only 1 estate card */
				if (OUTPUTLEVEL > 1) printf("Test: Added 1 estate to discard...\n");
				deltaPlayerCardTypesInDiscard(&pre, &post, player, discardDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == estate)
					{
						if (discardDeltas[i] != 1) result = FALSE;
					}
					else
					{
						if (discardDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);

				/* verify hand added 1 gold, 1 silver card */
				if (OUTPUTLEVEL > 1) printf("Test: Added 1 gold, 1 silver to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == silver)
					{
						if (handDeltas[i] != 1) result = FALSE;
					}
					else if (i == gold)
					{
						if (handDeltas[i] != 1) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);
			}


			/*
			* 5) Ensure that card effect picks only treasure cards when mixed
			*    with non-treasure cards; also, does not skip treasure cards
			*/

			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 1 estate on top, followed by copper, estate, silver, estate, gold, estate; discard: empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 7;
			pre.deck[player][6] = estate; /* top of deck */
			pre.deck[player][5] = copper;
			pre.deck[player][4] = estate;
			pre.deck[player][3] = silver;
			pre.deck[player][2] = estate;
			pre.deck[player][1] = gold;
			pre.deck[player][0] = estate;

			if (OUTPUTLEVEL > 1) printf("Card Configuration: 1 estate on top, followed by copper, estate, silver, estate, gold, estate; discard: empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify discard contains only 1 estate card */
				if (OUTPUTLEVEL > 1) printf("Test: Added 1 estate to discard...\n");
				deltaPlayerCardTypesInDiscard(&pre, &post, player, discardDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == estate)
					{
						if (discardDeltas[i] != 1) result = FALSE;
					}
					else
					{
						if (discardDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);

				/* verify hand added 1 copper, 1 silver card */
				if (OUTPUTLEVEL > 1) printf("Test: Added 1 copper, 1 silver to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == copper)
					{
						if (handDeltas[i] != 1) result = FALSE;
					}
					else if (i == silver)
					{
						if (handDeltas[i] != 1) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);
			}

			/* 6) Ensure card effect causes deck to be reshuffled when cards run out */

			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: empty, discard 1 gold, 1 silver, 1 copper */
			pre.deckCount[player] = 0;
			pre.discardCount[player] = 3;
			pre.discard[player][2] = gold;
			pre.discard[player][1] = silver;
			pre.discard[player][0] = copper;

			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck empty, discard contains 1 gold, 1 silver, 1 copper.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify discard is empty */
				if (OUTPUTLEVEL > 1) printf("Test: Discard is empty...\n");
				result = post.discardCount[player];
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == 0, &passes, &failures);

				/* verify 2 treasures in hand */
				if (OUTPUTLEVEL > 1) printf("Test: 2 treasure cards added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				treasures = 0;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == copper || i == silver || i == gold)
					{
						if (handDeltas[i] < 0) result = FALSE;
						treasures += handDeltas[i];
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE && treasures == 2, &passes, &failures);
			}

			/* 7) Ensure card effect will draw a single treasure card */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 1 gold; discard: empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 1;
			pre.deck[player][0] = gold;

			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck 1 gold, discard empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify discard is empty */
				if (OUTPUTLEVEL > 1) printf("Test: Discard is empty...\n");
				result = post.discardCount[player];
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == 0, &passes, &failures);

				/* verify exactly 1 gold in hand */
				if (OUTPUTLEVEL > 1) printf("Test: 1 gold card added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == gold)
					{
						if (handDeltas[i] != 1) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);
			}

			/* 8) Ensure card effect will draw a single treasure card */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 1 silver; discard: empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 1;
			pre.deck[player][0] = silver;

			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck 1 silver, discard empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify discard is empty */
				if (OUTPUTLEVEL > 1) printf("Test: Discard is empty...\n");
				result = post.discardCount[player];
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == 0, &passes, &failures);

				/* verify exactly 1 silver in hand */
				if (OUTPUTLEVEL > 1) printf("Test: 1 silver card added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == silver)
					{
						if (handDeltas[i] != 1) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);
			}

			/* 9) Ensure card effect will draw a single treasure card */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 1 copper; discard: empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 1;
			pre.deck[player][0] = copper;

			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck 1 copper, discard empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify discard is empty */
				if (OUTPUTLEVEL > 1) printf("Test: Discard is empty...\n");
				result = post.discardCount[player];
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == 0, &passes, &failures);

				/* verify exactly 1 copper in hand */
				if (OUTPUTLEVEL > 1) printf("Test: 1 copper card added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == copper)
					{
						if (handDeltas[i] != 1) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);
			}

			/* Ensure card effect will draw no cards if no treasures are available */
			/* get a fresh copy of the base gamestate */
			copyGameState(&pre, &state);

			/* stack the current player's hand with the card under test and set current player */
			pre.handCount[player] = HANDCOUNT;
			for (handpos = 0; handpos < pre.handCount[player]; handpos++) pre.hand[player][handpos] = CARDUNDERTEST;
			pre.whoseTurn = player;

			/* deck: 5 estates, 0 treasures; discard: empty */
			pre.discardCount[player] = 0;
			pre.deckCount[player] = 5;
			for (deckpos = 0; deckpos < pre.deckCount[player]; deckpos++) pre.deck[player][deckpos] = estate;

			if (OUTPUTLEVEL > 1) printf("Card Configuration: deck 5 estates, discard empty.\n");

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

				if (OUTPUTLEVEL > 1) printf("Test Standard Conditions\n");
				testStandardConditions(players, player, handpos, &pre, &post, &passes, &failures);

				if (OUTPUTLEVEL > 1) printf("Test Extra Conditions\n");

				/* verify 0 treasures added to hand */
				if (OUTPUTLEVEL > 1) printf("Test: 0 treasure cards added to hand...\n");
				deltaPlayerCardTypesInHand(&pre, &post, player, handDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == CARDUNDERTEST) /* card that was played */
					{
						if (handDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (handDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);

				/* verify discard contains 5 estates */
				if (OUTPUTLEVEL > 1) printf("Test: 5 estates in discard...\n");
				deltaPlayerCardTypesInDiscard(&pre, &post, player, discardDeltas);
				result = TRUE;
				for (i = 0; i <= treasure_map; i++)
				{
					if (i == estate)
					{
						if (discardDeltas[i] != 5) result = FALSE;
					}
					else if (i == CARDUNDERTEST) /* card that was played */
					{
						if (discardDeltas[i] != -1) result = FALSE;
					}
					else
					{
						if (discardDeltas[i] != 0) result = FALSE;
					}
				}
				if (OUTPUTLEVEL > 1) printf("Result: ");
				updateTestResult(result == TRUE, &passes, &failures);
			}
		}
	}

	if (OUTPUTLEVEL > 0)
	{
		printf("\nSUMMARY for " FILENAME " (" xstr(CARDUNDERTEST) "): ");
		if (failures == 0) printf("passed all %d tests.\nTesting Outcome: SUCCESS!\n", passes);
		else
		{
			printf("failed %d of %d tests.\n", failures, passes + failures);
			printf("Testing Outcome: FAILED!\n");
			if (OUTPUTLEVEL > 1) printf("See results output above.\n");
		}
		printf("\n*** END " FILENAME " (cardEffect unit test for " xstr(CARDUNDERTEST) ") ***\n");
	}

	return failures;
}