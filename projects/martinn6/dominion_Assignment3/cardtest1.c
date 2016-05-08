/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Assignement 3
 * Description: cardtest1 - smithy
 * *******************************************************************************************/

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
	int discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	//smithy = line 831
	printf("TEST: +3 cards\n");
	newCards = 3;
	discarded = 1;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	int before_handCount = testG.handCount[thisPlayer];
	int before_discardCount = testG.discardCount[thisPlayer];
	int before_deckCount = testG.deckCount[thisPlayer];
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	int after_handCount = testG.handCount[thisPlayer];
	int after_discardCount = testG.discardCount[thisPlayer];
	int after_deckCount = testG.deckCount[thisPlayer];
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);

	printf("hand count before=%d; hand count after=%d; expected=%d ", before_handCount, after_handCount,before_handCount + newCards - discarded);
	if(after_handCount == (before_handCount + newCards - discarded))
		printf("PASSED\n");
	else
		printf("FAILED\n");
	
	printf("discard count before=%d; discard count after=%d; expected = %d ", before_discardCount, after_discardCount,before_discardCount + discarded);
	if(after_discardCount == (before_discardCount + discarded))
		printf("PASSED\n");
	else
		printf("FAILED\n");

	printf("deck count before=%d; deck count after=%d; expected = %d ", before_deckCount, after_deckCount, after_deckCount + discarded);
	if(after_deckCount == (before_deckCount - newCards + discarded))
		printf("PASSED\n");
	else
		printf("FAILED\n");

	return 0;
}


