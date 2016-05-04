/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Assignement 3
 * Description: cardtest1 - adventurer
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

#define TESTCARD "adventurer"

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
	newCards = 2;
	discarded = 1;
	int before_treasureCardCount = 0,
		after_treasureCardCount = 0;
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	printf("\nBefore:");
	for(int x = 0; x<testG.handCount[thisPlayer]; x++ )
	{
		printf("card=%d; ", testG.hand[thisPlayer][x]);
		if(testG.hand[thisPlayer][x] == 4 || testG.hand[thisPlayer][x] == 5 || testG.hand[thisPlayer][x] == 6)
			before_treasureCardCount++;
	}
	int before_handCount = testG.handCount[thisPlayer];
	int before_discardCount = testG.discardCount[thisPlayer];
	int before_deckCount = testG.deckCount[thisPlayer];
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	int after_handCount = testG.handCount[thisPlayer];
	int after_discardCount = testG.discardCount[thisPlayer];
	int after_deckCount = testG.deckCount[thisPlayer];
	printf("\nAfter:");
	for(int x = 0; x<testG.handCount[thisPlayer]; x++ )
	{
		printf("card=%d; ", testG.hand[thisPlayer][x]);
		if(testG.hand[thisPlayer][x] == 4 || testG.hand[thisPlayer][x] == 5 || testG.hand[thisPlayer][x] == 6)
			after_treasureCardCount++;
	}

	printf("\nhand count before=%d; hand count after=%d; expected=%d ", before_handCount, after_handCount,before_handCount + newCards);
	if(after_handCount == (before_handCount + newCards))
		printf("PASSED\n");
	else
		printf("FAILED\n");
	
	printf("treaure card count before =%d; treaure card count after=%d; expected=%d ", before_treasureCardCount, 
		after_treasureCardCount, before_treasureCardCount + newCards);
	if(after_treasureCardCount == (before_treasureCardCount + newCards))
		printf("PASSED\n");
	else
		printf("FAILED\n");

	return 0;
}


