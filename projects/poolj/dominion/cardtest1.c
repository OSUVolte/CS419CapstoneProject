/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 24 April 2016
**
** Program Filename: cardtest1.c
** Description: This is the source file for card test 1 which covers
**				the Smithy card in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define PLAYERS 2  /* Must be 1 to 4 */
#define RANDOM_SEED 1  /* Must be positive number, 9 digits or less */
#define TEST_CARD "smithy"

int main() {
	printf("*** Card test for: %s ***\n", TEST_CARD);

	/* Smithy Card Modifications */
	int nActions = 0;  /* Number of additional actions */
	int nBuys = 0;  /* Number of additional buys */
	int nCards = 3;  /* Number of additional cards */
	int nCoins = 0;  /* Nmber of additional coins */
	int pCards = 1;  /* Number of cards played */
	int handPos = 0;  /* Initial location of card */
	int choice1 = 0, choice2 = 0, choice3 = 0;  /* Card choice options */
	

	/* Initalize gamestate */
	struct gameState testGame;
	struct gameState origGame;
	int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int baseCards[7] = { curse, estate, duchy, province, copper, silver, gold };
	int bonus = 0;  /* Player's bonus */
	int testValue;
	int origValue;
	assert(initializeGame(PLAYERS, cards, RANDOM_SEED, &testGame) == 0);  /* Initalize game and verify completion */

	/* Initalize test counters */
	int passCount = 0;  /* Number of tests passed */
	int failCount = 0;  /* Number of tests failed */

	/* The smithy card adds +3 cards to hand */
	int testPlayer = 0;
	testGame.whoseTurn = testPlayer;
	testGame.hand[testPlayer][handPos] = smithy;  /* Add smithy to test player's hand*/
	testGame.phase = 0;  /* Set phase to action */
	testGame.numActions = 1;  /* Set number of actions to 1*/
	memcpy(&origGame, &testGame, sizeof(struct gameState)); /* Copy to preserve original state */
	printf("\n--- Verify %s card effects are correct ---\n", TEST_CARD);
	if (cardEffect(smithy, choice1, choice2, choice3, &testGame, handPos, &bonus) == 0) { /* Play smithy card */
		printf("  PASS: cardEffect() method completed successfully\n");
		passCount++;
		
		/* Compare hand count with predicted */
		testValue = testGame.handCount[testPlayer];
		origValue = origGame.handCount[testPlayer] + nCards - pCards;
		if (testValue == origValue) {
			printf("  PASS: Hand Count - Actual = %d; Expected = %d\n", testValue, origValue);
			passCount++;
		}
		else {
			printf("  FAIL: Hand Count - Actual = %d; Expected = %d\n", testValue, origValue);
			failCount++;
		}
		
		/* Compare deck count with predicted */
		testValue = testGame.deckCount[testPlayer];
		origValue = origGame.deckCount[testPlayer] - nCards;
		if (testValue == origValue) {
			printf("  PASS: Deck Count - Actual = %d; Expected = %d\n", testValue, origValue);
			passCount++;
		}
		else {
			printf("  FAIL: Deck Count - Actual = %d; Expected = %d\n", testValue, origValue);
			failCount++;
		}

		/* Compare played count with predicted */
		testValue = testGame.playedCardCount;
		origValue = origGame.playedCardCount + pCards;
		if (testValue == origValue) {
			printf("  PASS: Played Count - Actual = %d; Expected = %d\n", testValue, origValue);
			passCount++;
		}
		else {
			printf("  FAIL: Played Count - Actual = %d; Expected = %d\n", testValue, origValue);
			failCount++;
		}

		/* Compare actions with predicted */
		testValue = testGame.numActions;
		origValue = origGame.numActions + nActions;
		if (testValue == origValue) {
			printf("  PASS: Action Count - Actual = %d; Expected = %d\n", testValue, origValue);
			passCount++;
		}
		else {
			printf("  FAIL: Action Count - Actual = %d; Expected = %d\n", testValue, origValue);
			failCount++;
		}

		/* Compare buys with predicted */
		testValue = testGame.numBuys;
		origValue = origGame.numBuys + nBuys;
		if (testValue == origValue) {
			printf("  PASS: Buy Count - Actual = %d; Expected = %d\n", testValue, origValue);
			passCount++;
		}
		else {
			printf("  FAIL: Buy Count - Actual = %d; Expected = %d\n", testValue, origValue);
			failCount++;
		}

		/* Compare coin count with predicted */
		testValue = testGame.coins;
		origValue = origGame.coins + nCoins;
		if (testValue == origValue) {
			printf("  PASS: Coin Count - Actual = %d; Expected = %d\n", testValue, origValue);
			passCount++;
		}
		else {
			printf("  FAIL: Coin Count - Actual = %d; Expected = %d\n", testValue, origValue);
			failCount++;
		}

		printf("\n--- Verify other players have not been effected ---\n");
		/* Verify other players were not effected */
		int passFlag = 1;
		for (int i = 0; i < PLAYERS; i++) {
			if (i == testPlayer) {
				printf("Player %d of %d is tested player\n", i+1, PLAYERS);
				continue;  /* Skip test player*/
			}
			printf("Verifying Player %d of %d\n", i+1, PLAYERS);
			
			/* Test other player's hand*/
			if (testGame.handCount[i] == origGame.handCount[i]) {
				passFlag = 1;
				for (int j = 0; j < testGame.handCount[i]; j++) {
					if (testGame.hand[i][j] != origGame.hand[i][j]) {
						passFlag = 0;
						break;
					}
				}
			}
			else {
				passFlag = 0;
			}
			if (passFlag == 1) {
				printf("  PASS: Player %d hand is uneffected\n", i + 1);
				passCount++;
			}
			else {
				printf("  FAIL: Player %d hand is effected\n", i + 1);
				failCount++;
			}

			/* Test other player's deck */
			if (testGame.deckCount[i] == origGame.deckCount[i]) {
				passFlag = 1;
				for (int j = 0; j < testGame.deckCount[i]; j++) {
					if (testGame.deck[i][j] != origGame.deck[i][j]) {
						passFlag = 0;
						break;
					}
				}
			}
			else {
				passFlag = 0;
			}
			if (passFlag == 1) {
				printf("  PASS: Player %d deck is uneffected\n", i+1);
				passCount++;
			}
			else {
				printf("  FAIL: Player %d deck is effected\n", i+1);
				failCount++;
			}

			/* Test other player's discard */
			if (testGame.discardCount[i] == origGame.discardCount[i]) {
				passFlag = 1;
				for (int j = 0; j < testGame.discardCount[i]; j++) {
					if (testGame.discard[i][j] != origGame.discard[i][j]) {
						passFlag = 0;
						break;
					}
				}
			}
			else {
				passFlag = 0;
			}
			if (passFlag == 1) {
				printf("  PASS: Player %d discard is uneffected\n", i + 1);
				passCount++;
			}
			else {
				printf("  FAIL: Player %d discard is effected\n", i + 1);
				failCount++;
			}
			
		}

		printf("\n--- Verify card supply has not been effected ---\n");
		/* Action Cards */
		passFlag = 1;
		for (int i = 0; i < 10; i++) { 
			testValue = supplyCount(cards[i], &testGame);
			origValue = supplyCount(cards[i], &origGame);
			if (testValue != origValue) {
				passFlag = 0;
				break;
			}
		}
		if (passFlag == 1) {
			printf("  PASS: Action Card Supply is uneffected\n");
			passCount++;
		}
		else {
			printf("  FAIL: Action Card Supply is effected\n");
			failCount++;
		}

		/* Basic Cards */
		passFlag = 1;
		for (int i = 0; i < 7; i++) {  
			testValue = supplyCount(baseCards[i], &testGame);
			origValue = supplyCount(baseCards[i], &origGame);
			if (testValue != origValue) {
				passFlag = 0;
				break;
			}
		}
		if (passFlag == 1) {
			printf("  PASS: Basic Card Supply is uneffected\n");
			passCount++;
		}
		else {
			printf("  FAIL: Basic Card Supply is effected\n");
			failCount++;
		}

	}
	else {
		printf("  FAIL: cardEffect() method did not complete successfully\n");
		failCount++;
	}

	/* Print overall results */
	printf("\n--- Overall test results ---\n");
	printf("  PASS: %d of %d\n", passCount, passCount + failCount);
	printf("  FAIL: %d of %d\n", failCount, passCount + failCount);

	return 0;
}