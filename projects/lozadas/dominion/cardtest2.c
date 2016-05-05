/* -----------------------------------------------------------------------
*Name: Suyana Lozada 
*cardTest #2 
*adventurer() 
*Reference:testUpdateCoins.c cardtest4.c 
*Test description:
*
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
	int treasure=0;
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int expected=2;
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("Testing adventurer()\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 3;
	xtraCoins = 0;

	printf("Test 1: player 0 draws two treasury cards from deck\n");
	//Determine the number of treasure cards in player hand for G game  
	for(i=0;i<testG.handCount[thisPlayer];i++)
	{
		if (testG.hand[thisPlayer][i]==copper|| testG.hand[thisPlayer][i]== silver|| testG.hand[thisPlayer][i]==gold)
			treasure++;
	}
	//Determine number of treasure cards in	player hand for G game
	for(i=0;i<G.handCount[thisPlayer];i++)
	{
		if (G.hand[thisPlayer][i]==copper|| G.hand[thisPlayer][i]== silver|| G.hand[thisPlayer][i]==gold)
			expected++;
	}

	if (treasure == expected+2)
	{
		printf("PASS: test = %d, expected = %d\n",treasure,expected + 2);
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n",treasure,expected + 2);
	}

	printf("Test 2: player 1 deck remains unchanged\n");
	if (testG.deckCount[1] == G.deckCount[1] )
	{
		printf("PASS: test = %d, expected = %d\n",testG.deckCount[1],G.deckCount[1]);
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n",testG.deckCount[1],G.deckCount[1]);
	}

	printf("Test 3: discard deck should not have any treasure cads\n");

	treasure=0;
	expected=0;
	//Determine the number of treasure cards in player discard for G game  
	for(i=0;i<testG.discardCount[thisPlayer];i++)
	{
		if (testG.discard[thisPlayer][i]==copper|| testG.discard[thisPlayer][i]== silver|| testG.discard[thisPlayer][i]==gold)
			treasure++;
	}
	//Determine number of treasure cards in	player discard for G game
	for(i=0;i<G.discardCount[thisPlayer];i++)
	{
		if (G.discard[thisPlayer][i]==copper|| G.discard[thisPlayer][i]== silver|| G.discard[thisPlayer][i]==gold)
			expected++;
	}

	if (treasure == expected)
	{
		printf("PASS: test = %d, expected = %d\n",treasure,expected );
	}
	else
	{
		printf("FAIL: test = %d, expected = %d\n",treasure,expected );
	}

	printf("\nTesting complete \n\n");
	return 0;
}


