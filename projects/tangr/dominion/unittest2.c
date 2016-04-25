/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	unittest2.c
*
*	Description: 
*		Test for Discard 
*		
********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

void discardHelper (struct gameState *testGame, int currentPlayer)
{		
	int handSize = 6;
	int currentHand[handSize];
	int i;
	
	for (i = 0; i < handSize; i++)
		currentHand[i] = 0;
	
	currentHand[0] = copper;
	currentHand[1] = silver;
	currentHand[2] = gold;
	currentHand[3] = mine;
	currentHand[4] = gardens;
	currentHand[5] = baron;

	memcpy(testGame->hand[currentPlayer], currentHand, (sizeof(int) * handSize));
	
	int discardCountBefore = testGame->discardCount[currentPlayer];
	int handCountBefore = testGame->handCount[currentPlayer];
	
	printf("Discard Test \n");
	printf("-----------------------------\n");
	printf("Discard Count %d \n", discardCountBefore);
	printf("Hand Count %d \n", handCountBefore);
	
	int handPosition = 3;
	int trashFlag = 0;
	discardCard(handPosition, currentPlayer, testGame, trashFlag);
	printf("discarding card #%d \n\n", handPosition);

	if (discardCountBefore + 1 == testGame->discardCount[currentPlayer])
		printf("Discard Count - Check \n");
	else 
	{
		printf("Discard Count - Fail \n");
		printf("Discard Count %d \n", testGame->discardCount[currentPlayer]);
	}
	
	if (handCountBefore - 1 == testGame->handCount[currentPlayer])
		printf("Hand Count - Check \n");
	else
		printf("Hand Count - Fail \n");
	printf("Hand Count %d \n", testGame->handCount[currentPlayer]);
}




void cardDiscardTest()
// set up enough tests for all 27 cards
//		requires "3" test 10x3
{

	int numPlayer = 2;
	int seed = 1000;
	struct gameState* testGame = newGame();
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, baron, great_hall};
	// cards used are irrelevant for this test

		
	initializeGame(numPlayer, k, seed, testGame);
	//	retain the reference information for game;
	
	int currentPlayer = 0;
	printf("Test 1 - discard from hand\n");
	//	situation one - standard draw
	discardHelper (testGame, currentPlayer);
}

int main()
{
	cardDiscardTest();
	return 0;
}
