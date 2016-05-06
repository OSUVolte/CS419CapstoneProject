/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*cardTest #1 
*smithy() 
*Reference:testUpdateCoins.c cardtest4.c 
*Test description:
*Ensure current player draws three cards from his own pile,no state change in other players 
* -----------------------------------------------------------------------
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int newCards = 0;
    int discarded = 1;
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

	printf("Testing smithy()\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 3;
	xtraCoins = 0;

	printf("Test 1: player 0 draws the correct number of cards (3 cards)\n");
	if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
	{
		printf("PASS: test = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	}
	
	printf("Test 1: correct number of cards in player 0 deck (1 card discarted)\n");
	if (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
	{
		printf("PASS: test = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	}
	printf("Test 2: player 0 draws cards from the correct pile\n");
	if (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards)
	{
		printf("PASS: test = %d, expected = %d\n", testG.deckCount[thisPlayer],G.deckCount[thisPlayer] - newCards);
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n", testG.deckCount[thisPlayer],G.deckCount[thisPlayer] - newCards);
	}
	printf("Test 3: player 1 deck remains unchanged\n");
	if (testG.deckCount[1] == G.deckCount[1] )
	{
		printf("PASS: test = %d, expected = %d\n",testG.deckCount[1],G.deckCount[1]);
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n",testG.deckCount[1],G.deckCount[1]);
	}

	
	printf("\nTesting complete \n\n");

	return 0;
}


