/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 24 April 2016
**
** Program Filename: unittest4.c
** Description: This is the source file for unit test 4 which covers
**				the fullDeckCount() method in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define PLAYERS 2  /* Must be 1 to 4 */
#define RANDOM_SEED 1  /* Must be positive number, 9 digits or less */

const char* getCardString(int card);
void loadAllCard(int player, struct gameState *state, int card);

int main() {
	printf("*** Unit test for method: fullDeckCount() ***\n");
	int count;  /* Number of cards returned from fullDeckCount*/
	int numCards;  /* Number of cards to load */

	/* Initalize gamestate */
	struct gameState testGame;
	int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	assert(initializeGame(PLAYERS, cards, RANDOM_SEED, &testGame) == 0);  /* Initalize game and verify completion */

	/* Test players */
	int passCount = 0;  /* Number of tests passed */
	int failCount = 0;  /* Number of tests failed */

	/* Setup for testing full deck count*/
	printf("\nSetup for testing full deck\n");
	testGame.handCount[0] = 5;
	printf("  Cards in Hand: %d\n", testGame.handCount[0]);
	testGame.discardCount[0] = 12;
	printf("  Cards in Discard: %d\n", testGame.discardCount[0]);
	testGame.deckCount[0] = 23;
	printf("  Cards in Deck: %d\n", testGame.deckCount[0]);
	int cardTotal = testGame.handCount[0] + testGame.discardCount[0] + testGame.deckCount[0];
	printf("  Total Number of Cards: %d\n", cardTotal);

	/* Count estate cards in hand */
	printf("\nCounting estate cards in only hand\n");
	loadAllCard(0, &testGame, copper);  /* Full with copper */
	numCards = 2;
	for (int i = 0; i < numCards; i++) {
		testGame.hand[0][i] = estate;
	}
	count = fullDeckCount(0, estate, &testGame);
	if (count == numCards) {
		printf("  PASS: Correctly counted %d estate cards in hand\n", count);
		passCount++;
	}
	else {
		printf("  FAIL: Incorrectly counted %d estate cards in hand\n", count);
		failCount++;
	}

	/* Count estate cards in deck */
	printf("\nCounting estate cards in only deck\n");
	loadAllCard(0, &testGame, copper);  /* Full with copper */
	numCards = 3;
	for (int i = 0; i < numCards; i++) {
		testGame.deck[0][i] = estate;
	}
	count = fullDeckCount(0, estate, &testGame);
	if (count == numCards) {
		printf("  PASS: Correctly counted %d estate cards in deck\n", count);
		passCount++;
	}
	else {
		printf("  FAIL: Incorrectly counted %d estate cards in deck\n", count);
		failCount++;
	}

	/* Count estate cards in deck */
	printf("\nCounting estate cards in only discard\n");
	loadAllCard(0, &testGame, copper);  /* Full with copper */
	numCards = 5;
	for (int i = 0; i < numCards; i++) {
		testGame.discard[0][i] = estate;
	}
	count = fullDeckCount(0, estate, &testGame);
	if (count == numCards) {
		printf("  PASS: Correctly counted %d estate cards in discard\n", count);
		passCount++;
	}
	else {
		printf("  FAIL: Incorrectly counted %d estate cards in discard\n", count);
		failCount++;
	}
	
	/* Print overall results */
	printf("\nOverall test results\n");
	printf("  PASS: %d of %d\n", passCount, passCount + failCount);
	printf("  FAIL: %d of %d\n", failCount, passCount + failCount);

	return 0;
}
	

/* Return string matching enum */
const char* getCardString(int card) {
	switch (card)
	{
	case curse:
		return "curse";
		break;
	case estate:
		return "estate";
		break;
	case copper:
		return "copper";
		break;
	case mine:
		return "mine";
		break;
	default:
		return "";
		break;
	}
}

/* Load players deck, discard, and hand with card */
void loadAllCard(int player, struct gameState *state, int card) {
	/* Load to maximum allowable size */
	for (int i = 0; i < MAX_DECK; i++) {  /* Load deck & discard with card */
		state->deck[player][i] = card;
		state->discard[player][i] = card;
	}
	for (int i = 0; i < MAX_HAND; i++) {  /* Load hand with card */
		state->hand[player][i] = card;
	}

}