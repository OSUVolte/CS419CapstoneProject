/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 24 April 2016
**
** Program Filename: unittest3.c
** Description: This is the source file for unit test 3 which covers
**				the scoreFor() method in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define PLAYERS 2  /* Must be 1 to 4 */
#define RANDOM_SEED 1  /* Must be positive number, 9 digits or less */

const char* getCardString(int card);
void loadAllCopper(int player, struct gameState *state);

int main() {
	printf("*** Unit test for method: scoreFor() ***\n");

	/* Initalize gamestate */
	struct gameState testGame;
	int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	assert(initializeGame(PLAYERS, cards, RANDOM_SEED, &testGame) == 0);  /* Initalize game and verify completion */

	/* Test players */
	int passCount = 0;  /* Number of tests passed */
	int failCount = 0;  /* Number of tests failed */

	/* Test score for cards: curse (-1), estate (+1), duchy (+3), province (+6), and great_hall (+1) */
	int testCards[5] = { curse, estate, duchy, province, great_hall };
	int testCardScore[5] = { -1, 1, 3, 6, 1 };

	/* Test player only having cards in hand */
	printf("\nTesting single card in player's hand (discard & deck empty)\n");
	loadAllCopper(0, &testGame);
	testGame.handCount[0] = 1;  /* Set player's hand to 1 card */
	testGame.discardCount[0] = 0;  /* Empty player discard */
	testGame.deckCount[0] = 0;  /* Empty player deck */

	for (int i = 0; i < 5; i++) {  /* Test scoring single card from hand */
		testGame.hand[0][0] = testCards[i];  /* Set card in player's hand */
		const char* cardString = getCardString(testCards[i]);  /* Get name of card */
		int playerScore = scoreFor(0, &testGame);
		if (playerScore == testCardScore[i]) {
			printf("  PASS: Correctly scored single %s card with total score of %d\n", cardString, playerScore);
			passCount++;
		}
		else {
			printf("  FAIL: Incorrectly scored single %s card with total score of %d\n", cardString, playerScore);
			failCount++;
		}
	}

	/* Test player only having cards in discard */
	printf("\nTesting single card in player's discard (hand & deck empty)\n");
	loadAllCopper(0, &testGame);
	testGame.handCount[0] = 0;  /* Empty player hand */
	testGame.discardCount[0] = 1;  /* Set player's discard to 1 card */
	testGame.deckCount[0] = 0;  /* Empty player deck */

	for (int i = 0; i < 5; i++) {  /* Test scoring single card from hand */
		testGame.discard[0][0] = testCards[i];  /* Set card in player's hand */
		const char* cardString = getCardString(testCards[i]);  /* Get name of card */
		int playerScore = scoreFor(0, &testGame);
		if (playerScore == testCardScore[i]) {
			printf("  PASS: Correctly scored single %s card with total score of %d\n", cardString, playerScore);
			passCount++;
		}
		else {
			printf("  FAIL: Incorrectly scored single %s card with total score of %d\n", cardString, playerScore);
			failCount++;
		}
	}

	/* Test player only having cards in deck */
	printf("\nTesting single card in player's deck (hand & discard empty)\n");
	loadAllCopper(0, &testGame);
	testGame.handCount[0] = 0;  /* Empty player hand */
	testGame.discardCount[0] = 0;  /* Empty player discard */
	testGame.deckCount[0] = 1;  /* Set player's deck to 1 card */

	for (int i = 0; i < 5; i++) {  /* Test scoring single card from hand */
		testGame.deck[0][0] = testCards[i];  /* Set card in player's hand */
		const char* cardString = getCardString(testCards[i]);  /* Get name of card */
		int playerScore = scoreFor(0, &testGame);
		if (playerScore == testCardScore[i]) {
			printf("  PASS: Correctly scored single %s card with total score of %d\n", cardString, playerScore);
			passCount++;
		}
		else {
			printf("  FAIL: Incorrectly scored single %s card with total score of %d\n", cardString, playerScore);
			failCount++;
		}
	}

	/* Test player having garden card */
	printf("\nSetup for testing garden card\n");
	testGame.handCount[0] = 5;
	printf("  Cards in Hand: %d\n", testGame.handCount[0]);
	testGame.discardCount[0] = 12;
	printf("  Cards in Discard: %d\n", testGame.discardCount[0]);
	testGame.deckCount[0] = 23;
	printf("  Cards in Deck: %d\n", testGame.deckCount[0]);
	int cardTotal = testGame.handCount[0] + testGame.discardCount[0] + testGame.deckCount[0];
	printf("  Total Number of Cards: %d\n", cardTotal);

	for (int i = 0; i < 3; i++) {
		loadAllCopper(0, &testGame);
		switch (i)
		{
		case 0:  /* Garden in hand */
			printf("\nTesting single gardens card in player's hand\n");
			testGame.hand[0][0] = gardens;
			break;
		case 1:  /* Garden in discard */
			printf("\nTesting single gardens card in player's discard\n");
			testGame.discard[0][0] = gardens;
			break;
		case 2:  /*Garden in deck*/
			printf("\nTesting single gardens card in player's deck\n");
			testGame.deck[0][0] = gardens;
			break;
		default:
			break;
		}
		int playerScore = scoreFor(0, &testGame);
		int testScore = cardTotal / 10;  /* Single garden: 1 point per 10 cards */
		if (playerScore == testScore) {
			printf("  PASS: Correctly scored %d points for %d cards\n", playerScore, cardTotal);
			passCount++;
		}
		else {
			printf("  FAIL: Incorrectly scored %d points for %d cards\n", playerScore, cardTotal);
			failCount++;
		}
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
	case duchy:
		return "duchy";
		break;
	case province:
		return "province";
		break;
	case great_hall:
		return "great_hall";
		break;
	default:
		return "";
		break;
	}
}

/* Load players deck, discard, and hand with copper */
void loadAllCopper(int player, struct gameState *state) {
	/* Load to maximum allowable size */
	for (int i = 0; i < MAX_DECK; i++) {  /* Load deck & discard with copper */
		state->deck[player][i] = copper;
		state->discard[player][i] = copper;
	}
	for (int i = 0; i < MAX_HAND; i++) {  /* Load hand with copper */
		state->hand[player][i] = copper;
	}

}