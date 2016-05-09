/***************************************************************************
** Author: James Pool
** ONID: 932664412
** OSU Email: poolj@oregonstate.edu
** Date: 24 April 2016
**
** Program Filename: randomtestadventurer.c
** Description: This is the source file for random card test which covers
**				the Adventurer card in dominion.c
***************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Global Defines */
#define TEST_CARD "adventurer"
#define NUM_TESTS 100  /* Number of random tests to perform (positive int)*/
#define TEST_DEBUG 1  /* Display debug messages: 1 (on), 0 (off) */

/* Test Structures */
struct cardTest {
	int card;  /* Enumerated card */
	int nActions;  /* Number of additional actions */
	int nBuys;  /* Number of additional buys */
	int nCards;  /* Number of additional cards to hand */
	int dCards;  /* Number of cards in deck*/
	int nCoins;  /* Nmber of additional coins */
	int pCards;  /* Number of cards played */
	int handPos;  /* Initial location of card */
	int choice[3];  /* Card choice options */
};

/* Function Prototypes */
int _addDeckTreasure(struct gameState *G, int p, int n);
void _printValidDeck(struct gameState *G, int p);
void _printValidHand(struct gameState *G, int p);
void _randomizeGameState(struct gameState *G);
void _testAll(struct gameState *B, struct gameState *T, struct cardTest *c, int *pass, int *fail);
int _testActionCount(struct gameState *B, struct gameState *T, struct cardTest *c);
int _testBuyCount(struct gameState *B, struct gameState *T, struct cardTest *c);
int _testCoinCount(struct gameState *B, struct gameState *T, struct cardTest *c);
int _testCurrentPlayer(struct gameState *B, struct gameState *T);
int _testDeckCount(struct gameState *B, struct gameState *T, struct cardTest *c, int p);
int _testDiscardCount(struct gameState *B, struct gameState *T, struct cardTest *c, int p);
int _testHandCount(struct gameState *B, struct gameState *T, struct cardTest *c, int p);
int _testNumPlayers(struct gameState *B, struct gameState *T);
int _testPlayedCount(struct gameState *B, struct gameState *T, struct cardTest *c);
int _testSupplyCards(struct gameState *B, struct gameState *T, int start, int end);

/***************************************************************************
**								Main
***************************************************************************/
int main() {
	printf("*** Random card test for: %s ***\n", TEST_CARD);
	srand(time(NULL));  //Replace with #include <time.h>'s time(NULL) for actual random

	// General Use Variables
	int n, status;
	int passCount = 0;  /* Number of tests passed */
	int failCount = 0;  /* Number of tests failed */

	/* Adventurer Card Modifications */
	struct cardTest cardMods;
	cardMods.card = adventurer;
	cardMods.nActions = 0;  /* Number of additional actions */
	cardMods.nBuys = 0;  /* Number of additional buys */
	cardMods.nCards = 2;  /* Number of additional cards to hand */
	cardMods.dCards = 0;  /* Number of cards in deck*/
	cardMods.nCoins = 0;  /* Nmber of additional coins */
	cardMods.pCards = 1;  /* Number of cards played */
	cardMods.handPos = 0;  /* Initial location of card */
	cardMods.choice[0] = 0;  /* Card choice options */
	cardMods.choice[1] = 0,
	cardMods.choice[2] = 0;

	/* Initalize gamestate */
	struct gameState testGame;
	struct gameState origGame;
	int bonus = 0;  /* Player's bonus */
	int curPlayer;

	for (n = 0; n < NUM_TESTS; n++) {

		_randomizeGameState(&testGame);
		curPlayer = testGame.whoseTurn;

		if (TEST_DEBUG) {
			printf("\nCurrent Player's deck before adding treasure cards ...\n");
			_printValidDeck(&testGame, curPlayer);
		}

		cardMods.dCards = _addDeckTreasure(&testGame, curPlayer, 2);

		if (TEST_DEBUG) {
			printf("\nCurrent Player's deck after adding treasure cards ...\n");
			_printValidDeck(&testGame, curPlayer);
		}

		if (TEST_DEBUG) {
			printf("\nCurrent Player's hand before adding adventurer card ...\n");
			_printValidHand(&testGame, curPlayer);
		}

		// Add adventurer card to hand
		cardMods.handPos = rand() % testGame.handCount[curPlayer];
		testGame.hand[curPlayer][cardMods.handPos] = cardMods.card;

		if (TEST_DEBUG) {
			printf("\nCurrent Player's hand after adding adventurer card ...\n");
			_printValidHand(&testGame, curPlayer);
		}

		// Copy game state
		memcpy(&origGame, &testGame, sizeof(struct gameState));

		// Run Card
		status = cardEffect(cardMods.card, cardMods.choice[0], cardMods.choice[1], cardMods.choice[2], &testGame, cardMods.handPos, &bonus);
		printf("Run %d Results:\n", n);
		if (status == 0) {
			printf("\tcardEffect Success\n");
			passCount++;
			_testAll(&origGame, &testGame, &cardMods, &passCount, &failCount);
		}
		else {
			printf("\tcardEffect Failure\n");
			failCount++;
		}
	}

	/* Print overall results */
	printf("\n--- Overall test results for %s (%d tests) ---\n", TEST_CARD, NUM_TESTS);
	printf("\tPASS: %d of %d\n", passCount, passCount + failCount);
	printf("\tFAIL: %d of %d\n", failCount, passCount + failCount);
	
	return 0;
}

/***************************************************************************
**						_addDeckTreasure
** This method adds the specified number of treasure cards to the deck in
** a random location.prints all of the valid cards in the deck and their position.
** Inputs:
**		G - game state (as pointer to struct gameState)
**		p - player's deck to add treasure to
**		n - number of treasure cards to add (int)
** Returns:
**	  int - Position of furthest treasure card added
****************************************************************************/
int _addDeckTreasure(struct gameState *G, int p, int n) {
	assert(G->deckCount[p] >= n);  // Require space for tresure cards

	int numTreasure;
	int cardType;
	int cardPos;
	int lastCardPos = MAX_DECK;

	// Due to low probability of generating actual treasure cards required
	// for successful completion of the Adventurer card, add 2 random 
	// treasure cards to the deck
	numTreasure = 0;
	while (numTreasure < n) {
		cardType = rand() % (gold - copper) + copper;  // Random treasure card
		cardPos = rand() % G->deckCount[p];  // Random card location
		// Check if random position already contains a treasure card
		if (G->deck[p][cardPos] != copper && G->deck[p][cardPos] != silver && G->deck[p][cardPos] != gold) {
			G->deck[p][cardPos] = cardType;
			numTreasure++;
			if (cardPos < lastCardPos) {
				lastCardPos = cardPos;
			}
		}
	}
	return lastCardPos;
}

/***************************************************************************
**						_printValidDeck
** This method prints all of the valid cards in the deck and their position.
** Inputs:
**		G - game state (as pointer to struct gameState)
**		p - player's deck to print (int)
****************************************************************************/
void _printValidDeck(struct gameState *G, int p) {
	int i;
	int validFlag = 0;

	printf("*** Player %d's Deck ***\n", p);
	for (i = 0; i < G->deckCount[p]; i++) {
		// Print cards that are valid
		if (G->deck[p][i] >= curse && G->deck[p][i] <= treasure_map) {
			printf("\tdeck[%d]: %d\n", i, G->deck[p][i]);
			validFlag = 1;
		}
	}
	if (validFlag == 0) {
		printf("\tNo Valid Cards in Deck\n");
	}
	printf("*** End Player %d's Deck ***\n", p);
}

/***************************************************************************
**						_printValidHand
** This method prints all of the valid cards in the hand and their position.
** Used for debugging.
** Inputs:
**		G - game state (as pointer to struct gameState)
**		p - player's hand to print (int)
****************************************************************************/
void _printValidHand(struct gameState *G, int p) {
	int i;
	int validFlag = 0;
	
	printf("*** Player %d's Hand ***\n", p);
	for (i = 0; i < G->handCount[p]; i++) {
		// Print cards that are valid
		if (G->hand[p][i] >= curse && G->hand[p][i] <= treasure_map) {
			printf("\thand[%d]: %d\n", i, G->hand[p][i]);
			validFlag = 1;
		}
	}
	if (validFlag == 0) {
		printf("\tNo Valid Cards in Hand\n");
	}
	printf("*** End Player %d's Hand ***\n", p);
}

/***************************************************************************
**						_randomizeGameStated
** This method randomizes the game state and adjusts the required parameters
** for the desired test.
** Inputs:
**		G - game state (as pointer to struct gameState)
****************************************************************************/
void _randomizeGameState(struct gameState *G) {
	int i, p;

	// Randomize gamestate
	for (i = 0; i < sizeof(struct gameState); i++) {
		((char*)G)[i] = rand() % 256;
	}

	// Set game properties to valid random values
	p = rand() % MAX_PLAYERS;  // Current Player
	G->whoseTurn = p;
	while (G->numPlayers < p + 1 || G->numPlayers < 2 || G->numPlayers > MAX_PLAYERS) {  // Randomize number of players
		G->numPlayers = rand() % MAX_PLAYERS + 1;
	}
	G->deckCount[p] = rand() % (MAX_DECK - 2) + 2;  // Random 2 to MAX_DECK
	G->discardCount[p] = rand() %
		(MAX_DECK - G->deckCount[p]);
	G->handCount[p] = rand() %
		(MAX_HAND - G->deckCount[p] - G->discardCount[p]) + 1;  // Min 1 card in hand
	G->playedCardCount = rand() % MAX_DECK;
}

/***************************************************************************
**							_testAll
** This method runs all of the various test cases.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
**   pass - number of tests passed (as pointer to int)
**   fail - number of tests failed (as pointer to int)
****************************************************************************/
void _testAll(struct gameState *B, struct gameState *T, struct cardTest *c, int *pass, int *fail) {
	if (_testCurrentPlayer(B, T)) {  // Verify current player matches
		(*pass)++;  // Increment pass for _testCurrentPlayer
		
		// Test current player specific items
		(_testPlayedCount(B, T, c)) ? ((*pass)++) : ((*fail)++);
		(_testActionCount(B, T, c)) ? ((*pass)++) : ((*fail)++);
		(_testBuyCount(B, T, c)) ? ((*pass)++) : ((*fail)++);
		(_testCoinCount(B, T, c)) ? ((*pass)++) : ((*fail)++);
		
		// Test all player items
		for (int i = 0; i < T->numPlayers; i++) {
			(_testHandCount(B, T, c, i)) ? ((*pass)++) : ((*fail)++);
			(_testDeckCount(B, T, c, i)) ? ((*pass)++) : ((*fail)++);
			(_testDiscardCount(B, T, c, i)) ? ((*pass)++) : ((*fail)++);
		}

		// Test supply cards
		(_testSupplyCards(B, T, curse, province)) ? ((*pass)++) : ((*fail)++);  //Victory
		(_testSupplyCards(B, T, copper, gold)) ? ((*pass)++) : ((*fail)++);  //Treasure
		(_testSupplyCards(B, T, adventurer, treasure_map)) ? ((*pass)++) : ((*fail)++);  //Action
	}
	else {
		(*fail)++;  // Increment fail for _testCurrentPlayer
	}
}

/***************************************************************************
**							_testActionCount
** This method tests if the action count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testActionCount(struct gameState *B, struct gameState *T, struct cardTest *c) {
	int testValue = T->numActions;
	int origValue = B->numActions + c->nActions;
	if (testValue == origValue) {
		printf("  PASS: Action Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Action Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 0;
	}
}

/***************************************************************************
**							_testBuyCount
** This method tests if the buy count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testBuyCount(struct gameState *B, struct gameState *T, struct cardTest *c) {
	int testValue = T->numBuys;
	int origValue = B->numBuys + c->nBuys;
	if (testValue == origValue) {
		printf("  PASS: Buy Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Buy Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 0;
	}
}

/***************************************************************************
**							_testCoinCount
** This method tests if the coin count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testCoinCount(struct gameState *B, struct gameState *T, struct cardTest *c) {
	int testValue = T->coins;
	int origValue = B->coins + c->nCoins;
	if (testValue == origValue) {
		printf("  PASS: Coin Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Coin Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 0;
	}
}

/***************************************************************************
**							_testCurrentPlayer
** This method tests if the current player matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testCurrentPlayer(struct gameState *B, struct gameState *T) {
	int testValue = T->whoseTurn;
	int origValue = B->whoseTurn;
	if (testValue == origValue) {
		printf("  PASS: Current Player - Actual = %d; Expected = %d\n", testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Current Player - Actual = %d; Expected = %d\n", testValue, origValue);
		return 0;
	}
}

/***************************************************************************
**							_testDeckCount
** This method tests if the deck count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
**		p - player to test (int)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testDeckCount(struct gameState *B, struct gameState *T, struct cardTest *c, int p) {
	int testValue = T->deckCount[p];
	int origValue;
	if (p == T->whoseTurn) {  // Active Player
		origValue = c->dCards;  // Modifier for adventurer cards drawn
		//origValue = B->deckCount[p] - c->nCards;
	}
	else {
		origValue = B->deckCount[p];
	}
	if (testValue == origValue) {
		printf("  PASS: Deck Count for Player %d - Actual = %d; Expected = %d\n", p, testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Deck Count for Player %d - Actual = %d; Expected = %d\n", p, testValue, origValue);
		return 0;
	}
}

/***************************************************************************
**							_testDiscardCount
** This method tests if the discard count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
**		p - player to test (int)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testDiscardCount(struct gameState *B, struct gameState *T, struct cardTest *c, int p) {
	int testValue = T->discardCount[p];
	int origValue;
	if (p == T->whoseTurn) {  // Active Player
		origValue = B->discardCount[p] + B->deckCount[p] - c->dCards - c->nCards;  // Modifier for adventurer cards drawn
		//origValue = B->discardCount[p] + c->nCards;
	}
	else {
		origValue = B->discardCount[p];
	}
	if (testValue == origValue) {
		printf("  PASS: Discard Count for Player %d - Actual = %d; Expected = %d\n", p, testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Discard Count for Player %d - Actual = %d; Expected = %d\n", p, testValue, origValue);
		return 0;
	}
}


/***************************************************************************
**							_testHandCount
** This method tests if the hand count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
**		p - player to test (int)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testHandCount(struct gameState *B, struct gameState *T, struct cardTest *c, int p) {
	int testValue = T->handCount[p];
	int origValue;
	if (p == T->whoseTurn) {  // Active Player
		origValue = B->handCount[p] + c->nCards - c->pCards;
	}
	else {
		origValue = B->handCount[p];
	}
	
	if (testValue == origValue) {
		printf("  PASS: Hand Count for Player %d - Actual = %d; Expected = %d\n", p, testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Hand Count for Player %d - Actual = %d; Expected = %d\n", p, testValue, origValue);
		return 0;
	}
}

/***************************************************************************
**							_testPlayedCount
** This method tests if the played card count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**		c - card modifies (as pointer to struct cardTest)
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testPlayedCount(struct gameState *B, struct gameState *T, struct cardTest *c) {
	int testValue = T->playedCardCount;
	int origValue = B->playedCardCount + c->pCards;
	if (testValue == origValue) {
		printf("  PASS: Played Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 1;
	}
	else {
		printf("  FAIL: Played Count - Actual = %d; Expected = %d\n", testValue, origValue);
		return 0;
	}
}


/***************************************************************************
**							_testSupplyCards
** This method tests if the supply card count matches the predicted values.
** Inputs:
**		B - base game state (as pointer to struct gameState)
**		T - test game state (as pointer to struct gameState)
**	start - enumerated card to start at
**    end - enumerated card to finish at
** Returns:
**		1 - PASS: test case matches predicted
**		0 - FAIL: test case does not match predicted
****************************************************************************/
int _testSupplyCards(struct gameState *B, struct gameState *T, int start, int end) {
	int passFlag = 1;
	int testValue;
	int origValue;
	for (int i = start; i <= end; i++) {
		testValue = supplyCount(i, T);
		origValue = supplyCount(i, B);
		if (testValue != origValue) {
			printf("  FAIL: Supply Card %d effected\n", i);
			passFlag = 0;
		}
	}
	if (passFlag == 1) {
		printf("  PASS: Supply Cards %d to %d uneffected\n", start, end);
	}
	return passFlag;
}