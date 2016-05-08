/*******************************************************************************
** Program Filename: randomtestadventurer.c
** Author: Jason Loomis
** Date: 5/8/16
** Description: CS 362, Assignment 4
**		Random test for the Adventurer card effect.
** Rule: Reveal cards from your deck until you reveal 2 treasure cards.
**		Put those Treasure cards in your hand and discard the other revealed
**		cards.
** Randomized Parameters:
**		The gameState input is randomized using randomizeGameState, which
**		randomizes the parameters as follows:
**			numPlayers: 2 <= numPlayers <= MAX_PLAYERS
**			supplyCount: all kingdom, treasure, victory, curse cards between 0
**				and game initial counts
**			embargo: if embargo is in the kingdom, embargo tokens may be
**				may be applied to any kingdom supply piles; the number of
**				tokens applied is up to (10 - # embargoes remaining in supply)
**			outpostPlayed: if outpost is in the kingdom, with a 1/32 chance,
**				outpostPlayed flag is set to up to (10 - # outposts remaining
**				in supply)
**			outpostTurn: if the outpostPlayed flag is non-zero, outpostTurn
**				is set to a value between 0 and 2.
**			whoseTurn: a player between 0 and (numPlayers - 1) is selected
**			numActions: random value between 0 and 10 (arbitrary)
**			coins: random value between 0 and 20 (arbitrary)
**			numBuys: random value between 0 and 10 (arbitrary)
**			cards counts: a cardcount is selected, between 0 and MAX_HAND,
**				this value is then randomly divided among the deck, hand, and
**				discard for each player; for the current player (whoseTurn),
**				the distribution includes the played cards as well.
**			cards: for the count of cards specified, the deck, hand, and
**				discard are chosen randomly from among the kingdom, treasure
**				victory, and curse cards; for the current player (whoseTurn),
**				the playedCards are chosen as well.
**			cardToPlay + handpos: for the current player (whoseTurn), the
**				player's hand is specified to have at least 1 card and that
**				card is specified to be cardToPlay and is set at any valid
**				handpos for that player's hand.
** Oracles:
**		Note: If any oracle fails, the test is failed.
**		1) Check that the played card count has increased by exactly 1
**		2) Check that exactly 1 CARDUNDERTEST has been added to the played cards
**		3) Check that number of cards in player's hand/played has increased by
**			no more than 2
**		4) Check that the cards in player's hand have:
**			decreased by 1 CARDUNDERTEST and
**			increased by up to 2 treasure cards
**		5) Check that number of cards in player's deck/discard decreased by no
**			more than 2
**		6) Check that number of cards in player's hand/played increased by
**			exactly the number that the deck/discard decreased
**		7) Check that the cards in player's hand/played increased by exactly
**			the cards that the deck/discard decreased by
**		8) Check that the state of other players didn't change
**		9) Check that the state of the supply cards (kingdom, treasure,
**			victory, curse) are unchanged.
**		10) Check other gameState fields (numPlayers, whoseTurn, etc.)
** Seeds:
**		The random seed indicated with each test iteration provides a means of
**		reproducing that test (i.e. regenerating the same sequence of random
**		numbers that were used). And the sequence seed can be used to reproduce
**		a sequence of tests.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testhelpers.h"

#define CARDUNDERTEST adventurer
#define FILENAME "randomtestadventurer.c"

#define ITERATIONS 10000 /* number of random iterations to run */
#define ORACLES 10 /* number of oracle functions employed */

/*******************************************************************************
** Function: oracle1
** Description: Check that the played card count has increased by exactly 1
** Parameters:
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle1(struct gameState* pre, struct gameState* post)
{
	int result;

	/* check playedCardCount */
	if (OUTPUTLEVEL > 1) printf("Oracle 1: Count cards played...\n");
	result = deltaPlayedCardCount(pre, post);
	if (OUTPUTLEVEL > 1)
	{
		printf("Result: Played %d cards, expected %d. ", result, 1);
		printTestResult(result == 1);
	}

	if (result == 1) return TRUE;
	else return FALSE;
}

/*******************************************************************************
** Function: oracle2
** Description: Check that exactly 1 CARDUNDERTEST has been added to the played
**		cards.
** Parameters:
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle2(struct gameState* pre, struct gameState* post)
{
	int result;

	/* check that the played card is the only type added to playedCards */
	if (OUTPUTLEVEL > 1) printf("Oracle 2: Played exactly 1 " xstr(CARDUNDERTEST) " card...\n");
	result = checkSpecificPlayedCard(pre, post, CARDUNDERTEST);
	if (OUTPUTLEVEL > 1)
	{
		printf("Result: ");
		printTestResult(result == TRUE);
	}

	if (result == TRUE) return TRUE;
	else return FALSE;
}

/*******************************************************************************
** Function: oracle3
** Description: Check that number of cards in player's hand/played has increased
**		by no more than 2.
** Parameters:
**		player: the current player index
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		0 <= player < MAX_PLAYERS
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle3(int player, struct gameState* pre, struct gameState* post)
{
	int result;

	if (OUTPUTLEVEL > 1) printf("Oracle 3: Count cards added to hand...\n");

	/* check count of cards in play (player hand + played) */
	result = 0;
	result += deltaPlayedCardCount(pre, post);
	result += deltaPlayerHandCount(pre, post, player);

	if (OUTPUTLEVEL > 1)
	{
		printf("Result: Added %d cards, expected <= %d. ", result, 2);
		printTestResult(result >= 0 && result <= 2);
	}

	if (result >= 0 && result <= 2) return TRUE;
	else return FALSE;
}

/*******************************************************************************
** Function: oracle4
** Description: Check that the cards in player's hand have:
**		decreased by 1 CARDUNDERTEST and
**		increased by up to 2 treasure cards
** Parameters:
**		player: the current player index
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		0 <= player < MAX_PLAYERS
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle4(int player, struct gameState* pre, struct gameState* post)
{
	int i;
	int result;
	int treasures;
	int handDeltas[treasure_map + 1]; /* array of all card types */

	/* Cards added are treasure cards */
	if (OUTPUTLEVEL > 1) printf("Oracle 4: Hand lost 1 " xstr(CARDUNDERTEST) " and gained <= 2 treasures...\n");
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
	if (OUTPUTLEVEL > 1)
	{
		printf("Result: ");
		printTestResult(result == TRUE && treasures >= 0 && treasures <= 2);
	}

	if (result == TRUE && treasures >= 0 && treasures <= 2) return TRUE;
	else return FALSE;
}

/*******************************************************************************
** Function: oracle5
** Description: Check that number of cards in player's deck/discard decreased
**		by no more than 2.
** Parameters:
**		player: the current player index
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		0 <= player < MAX_PLAYERS
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle5(int player, struct gameState* pre, struct gameState* post)
{
	int result;
	if (OUTPUTLEVEL > 1) printf("Oracle 5: Count cards removed from deck/discard...\n");
	/* check count of cards drawn from player deck */
	result = 0;
	/* note the reversal of the pre and post args, returns a positive value if cards are removed */
	result += deltaPlayerDeckCount(post, pre, player); /* current deck, may include discards shuffled into new deck */
	result += deltaPlayerDiscardCount(post, pre, player); /* discard may have been shuffled into a new deck */
	if (OUTPUTLEVEL > 1)
	{
		printf("Result: Removed %d cards, expected <= %d. ", result, 2);
		printTestResult(result >= 0 && result <= 2);
	}

	if (result >= 0 && result <= 2) return TRUE;
	else return FALSE;
}

/*******************************************************************************
** Function: oracle6
** Description: Check that number of cards in player's hand/played increased by
**		exactly the number that the deck/discard decreased.
** Parameters:
**		player: the current player index
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		0 <= player < MAX_PLAYERS
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle6(int player, struct gameState* pre, struct gameState* post)
{
	int resultAdded, resultRemoved;

	if (OUTPUTLEVEL > 1) printf("Oracle 6: Count cards added to hand == count cards removed from deck...\n");

	/* check count of cards in play (player hand + played) */
	resultAdded = 0;
	resultAdded += deltaPlayedCardCount(pre, post);
	resultAdded += deltaPlayerHandCount(pre, post, player);

	/* check count of cards drawn from player deck */
	/* note the reversal of the pre and post args, returns a positive value if cards are removed */
	resultRemoved = 0;
	resultRemoved += deltaPlayerDeckCount(post, pre, player); /* current deck, may include discards shuffled into new deck */
	resultRemoved += deltaPlayerDiscardCount(post, pre, player); /* discard may have been shuffled into a new deck */

	if (OUTPUTLEVEL > 1)
	{
		printf("Result: Added %d cards, removed %d cards. ", resultAdded, resultRemoved);
		printTestResult(resultAdded == resultRemoved);
	}

	if (resultAdded == resultRemoved) return TRUE;
	else return FALSE;
}

/*******************************************************************************
** Function: oracle7
** Description: Check that the cards in player's hand/played increased by
**		exactly the cards that the deck/discard decreased by.
** Parameters:
**		player: the current player index
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		0 <= player < MAX_PLAYERS
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle7(int player, struct gameState* pre, struct gameState* post)
{
	int i;
	int result;

	/* arrays of counts of card types */
	int playedDeltas[treasure_map + 1];
	int handDeltas[treasure_map + 1];
	int deckDeltas[treasure_map + 1];
	int discardDeltas[treasure_map + 1];

	if (OUTPUTLEVEL > 1) printf("Oracle 7: Cards added to hand/played == Cards removed from deck/discard...\n");

	deltaPlayedCardTypes(pre, post, playedDeltas);
	deltaPlayerCardTypesInHand(pre, post, player, handDeltas);

	/* note the reversal of the pre and post args, returns a positive value if cards are removed */
	deltaPlayerCardTypesInDeck(post, pre, player, deckDeltas);
	deltaPlayerCardTypesInDiscard(post, pre, player, discardDeltas);

	result = TRUE;
	for (i = 0; i <= treasure_map; i++)
	{
		if ((playedDeltas[i] + handDeltas[i]) != (deckDeltas[i] + discardDeltas[i])) result = FALSE;
	}

	if (OUTPUTLEVEL > 1)
	{
		printf("Result: ");
		printTestResult(result == TRUE);
	}

	if (result == TRUE) return TRUE;
	else return FALSE;
}

/*******************************************************************************
** Function: oracle8
** Description: Check that the state of other players didn't change.
** Parameters:
**		players: the number of players
**		player: the current player index
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		2 <= players <= MAX_PLAYERS
**		0 <= player < MAX_PLAYERS
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle8(int players, int player, struct gameState* pre, struct gameState* post)
{
	int i;
	int changed;
	int result;

	if (OUTPUTLEVEL > 1) printf("Oracle 8: Other players' states unchanged...\n");
	result = FALSE;
	for (i = 0; i < players; i++)
	{
		if (i != player)
		{
			if (OUTPUTLEVEL > 1) printf("Result: Player %d state: ", i);
			changed = playerCardStateChanged(pre, post, i);
			if (changed == TRUE) result = TRUE;
			if (OUTPUTLEVEL > 1)
			{
				if (changed == TRUE) printf("changed. ");
				else printf("unchanged. ");
				printTestResult(changed == FALSE);
			}
		}
	}

	/* logic: result == FALSE indicates no player's state has changed */
	if (result == FALSE) return TRUE; /* passed */
	else return FALSE; /* failed */
}

/*******************************************************************************
** Function: oracle9
** Description: Check that the state of the supply cards (kingdom, treasure,
**		victory, curse) are unchanged.
** Parameters:
**		player: the current player index
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		0 <= player < MAX_PLAYERS
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle9(int player, struct gameState* pre, struct gameState* post)
{
	int changed;
	int result;
	if (OUTPUTLEVEL > 1) printf("Oracle 9: Supply cards' states unchanged...\n");

	result = FALSE;

	changed = curseCardStateChanged(pre, post);
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: Curse cards unchanged. ");
		else printf("Result: Curse cards changed. ");
	}
	printTestResult(changed == FALSE);

	changed = victoryCardStateChanged(pre, post);
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: Victory cards unchanged. ");
		else printf("Result: Victory cards changed. ");
	}
	printTestResult(changed == FALSE);

	changed = treasureCardStateChanged(pre, post);
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: Treasure cards unchanged. ");
		else printf("Result: Treasure cards changed. ");
	}
	printTestResult(changed == FALSE);

	changed = kingdomCardStateChanged(pre, post, Kingdom);
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: Kingdom cards unchanged. ");
		else printf("Result: Kingdom cards changed. ");
	}
	printTestResult(changed == FALSE);

	/* logic: result == FALSE indicates no player's state has changed */
	if (result == FALSE) return TRUE; /* passed */
	else return FALSE; /* failed */
}

/*******************************************************************************
** Function: oracle10
** Description:  Check other gameState fields (numPlayers, whoseTurn, etc.)
** Parameters:
**		pre: gameState before card effect execution
**		post: gameState after card effect execution
** Pre-Conditions:
**		pre and post are pointers to valid gameState structs
** Post-Conditions: returns TRUE if the test succeeds, otherwise FALSE
*******************************************************************************/
int oracle10(int player, struct gameState* pre, struct gameState* post)
{
	int i;
	int result;
	int changed;

	if (OUTPUTLEVEL > 1) printf("Oracle 10: Other game state unchanged...\n");

	result = FALSE;

	/* numPlayers */
	changed = pre->numPlayers == post->numPlayers ? FALSE : TRUE;
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: numPlayers unchanged. ");
		else printf("Result: numPlayers changed. ");
	}
	printTestResult(changed == FALSE);

	/* embargoTokens */
	changed = FALSE;
	for (i = 0; i <= treasure_map; i++)
	{
		if (pre->embargoTokens[i] != post->embargoTokens[i]) changed = TRUE;
	}
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: embargoTokens[] unchanged. ");
		else printf("Result: embargoTokens[] changed. ");
	}
	printTestResult(changed == FALSE);

	/* outpostPlayed */
	changed = pre->outpostPlayed == post->outpostPlayed ? FALSE : TRUE;
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: outpostPlayed unchanged. ");
		else printf("Result: outpostPlayed changed. ");
	}
	printTestResult(changed == FALSE);

	/* whoseTurn */
	changed = pre->whoseTurn == post->whoseTurn ? FALSE : TRUE;
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: whoseTurn unchanged. ");
		else printf("Result: whoseTurn changed. ");
	}
	printTestResult(changed == FALSE);

	/* phase */
	changed = pre->phase == post->phase ? FALSE : TRUE;
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: phase unchanged. ");
		else printf("Result: phase changed. ");
	}
	printTestResult(changed == FALSE);

	/* numActions */
	changed = pre->numActions == post->numActions ? FALSE : TRUE;
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: numActions unchanged. ");
		else printf("Result: numActions changed. ");
	}
	printTestResult(changed == FALSE);

	/* coins */
	changed = pre->coins == post->coins ? FALSE : TRUE;
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: coins unchanged. ");
		else printf("Result: coins changed. ");
	}
	printTestResult(changed == FALSE);

	/* numBuys */
	changed = pre->numBuys == post->numBuys ? FALSE : TRUE;
	if (changed == TRUE) result = TRUE;
	if (OUTPUTLEVEL > 1)
	{
		if (changed == FALSE) printf("Result: numBuys unchanged. ");
		else printf("Result: numBuys changed. ");
	}
	printTestResult(changed == FALSE);

	/* logic: result == FALSE indicates no player's state has changed */
	if (result == FALSE) return TRUE; /* passed */
	else return FALSE; /* failed */
}


/*******************************************************************************
** Function: main
** Description: entrypoint for random test.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Exit code 0 if all tests succeeded, otherwise 1.
*******************************************************************************/
int main()
{
	unsigned int seed;
	int i;
	int handpos;
	int bonus;
	int result;
	int passes;
	int failures;
	struct gameState pre;
	struct gameState post;
	int oraclepasses[ORACLES];
	int oraclefailures[ORACLES];

	if (OUTPUTLEVEL > 0) printf("\n*** BEGIN " FILENAME " (cardEffect random testing for " xstr(CARDUNDERTEST) ") ***\n");

	/* reset counters */
	passes = 0;
	failures = 0;
	for (i = 0; i < ORACLES; i++)
	{
		oraclepasses[i] = 0;
		oraclefailures[i] = 0;
	}

	/* initialize the random number generator */
	seed = time(NULL);
	srand(seed); /* initializing a specific seed here will produce define a specific output sequence */
	if (OUTPUTLEVEL > 1) printf("Sequence seed: %u\n", seed);


	for (i = 0; i < ITERATIONS; i++)
	{
		seed = randU32();

		/* set random number generator seed */
		srand(seed);

		/* get randomized input */
		randomizeGameState(&pre, Kingdom, adventurer, &handpos);

		if (OUTPUTLEVEL > 1) printf("Input State: seed=%u numPlayers=%d whoseTurn=%d handpos=%d\n", seed, pre.numPlayers, pre.whoseTurn, handpos);

		/* keep a copy of the initial state */
		copyGameState(&post, &pre);

		/* apply the card effect */
		cardEffect(CARDUNDERTEST, 0, 0, 0, &post, handpos, &bonus);

		/* use oracles to check the results of the effect */
		result = TRUE;
		if (oracle1(&pre, &post) == FALSE)
		{
			oraclefailures[0]++;
			result = FALSE;
		}
		else oraclepasses[0]++;

		if (oracle2(&pre, &post) == FALSE)
		{
			oraclefailures[1]++;
			result = FALSE;
		}
		else oraclepasses[1]++;

		if (oracle3(pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[2]++;
			result = FALSE;
		}
		else oraclepasses[2]++;

		if (oracle4(pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[3]++;
			result = FALSE;
		}
		else oraclepasses[3]++;

		if (oracle5(pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[4]++;
			result = FALSE;
		}
		else oraclepasses[4]++;

		if (oracle6(pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[5]++;
			result = FALSE;
		}
		else oraclepasses[5]++;

		if (oracle7(pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[6]++;
			result = FALSE;
		}
		else oraclepasses[6]++;

		if (oracle8(pre.numPlayers, pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[7]++;
			result = FALSE;
		}
		else oraclepasses[7]++;

		if (oracle9(pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[8]++;
			result = FALSE;
		}
		else oraclepasses[8]++;

		if (oracle10(pre.whoseTurn, &pre, &post) == FALSE)
		{
			oraclefailures[9]++;
			result = FALSE;
		}
		else oraclepasses[9]++;

		if (result == TRUE) passes++;
		else failures++;

		if (OUTPUTLEVEL > 1)
		{
			printf("Output Result for seed=%u: ", seed);
			printTestResult(result == TRUE);
			printf("\n");
		}
	}

	if (OUTPUTLEVEL > 0)
	{
		printf("SUMMARY for " FILENAME " (" xstr(CARDUNDERTEST) "):\n");
		if (failures == 0) printf("SUCCESS! All %d iterations passed.\n", passes);
		else
		{
			printf("FAILED! Failed %d of %d iterations.\n", failures, passes + failures);
			if (OUTPUTLEVEL > 1)
			{
				for (i = 0; i < ORACLES; i++)
				{
					printf("Oracle %d: ", i + 1);
					if (oraclefailures[i] == 0) printf("Passed all %d tests.\n", oraclepasses[i]);
					else printf("Failed %d of %d tests.\n", oraclefailures[i], oraclefailures[i] + oraclepasses[i]);
				}
				printf("See results output above.\n");
			}
		}
		printf("*** END " FILENAME " (cardEffect random test for " xstr(CARDUNDERTEST) ") ***\n");
	}

	return failures == 0 ? 0 : 1;
}