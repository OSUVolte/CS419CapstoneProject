/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	unittest4.c
*
*	Description: 
*		Test for draw
*			hand - check number of cards
*				if card is drawn, +1
*				if no card is drawn, +0
*
*			deck
*				draw from deck
*				deck empty -> reshuffle
*				deck empty -> no cards left

*			handpos
*			
********************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

void cardDrawTestHelper (struct gameState *testGame)
{
	int i;
	
	int deckSize;
	int handSizeBefore;
	int handSizeAfter;
	int discardSizeBefore;
	int discardSizeAfter;
	int deckSizeBefore;
	int deckSizeAfter;
	int currentPlayer = 0;

	deckSize = fullDeckCount(currentPlayer, 0, testGame);
	
	handSizeBefore = numHandCards(testGame);
	deckSizeBefore = deckSize - handSizeBefore;
	discardSizeBefore = 0;

	drawCard(currentPlayer, testGame);
	
	handSizeAfter = numHandCards(testGame);
	
	discardSizeAfter = 0;
	for (i = 0; i < testGame->discardCount[currentPlayer]; i++)
		if (testGame->discard[currentPlayer][i] == 0) 
			discardSizeAfter++;
		
	deckSizeAfter = 0;
	for (i = 0; i < testGame->deckCount[currentPlayer]; i++)
		if (testGame->deck[currentPlayer][i] == 0) 
			deckSizeAfter++;
		
	// check hand size
	if (handSizeBefore + 1 == handSizeAfter)
		printf("Draw Test - Hand Size - Check\n");
	else
		printf("Draw Test - Hand Size - Fail\n");
	
	//	check deck/discard
	if (deckSizeBefore - 1 != deckSizeAfter)
		printf("Draw test - Deck Size - Check\n");
	else
	{
// Deck was empty, move discard
		if (discardSizeAfter == 0 
				&& deckSizeAfter == discardSizeBefore - 1)
			printf("Draw test - Deck Size - Check\n");
// Empty Deck and Discard
		else if (discardSizeBefore == 0 && discardSizeAfter == 0
				&& deckSizeBefore == 0 && deckSizeAfter == 0)
			printf("Draw test - Deck Size - Check\n");

		else
			printf("Draw test - Deck Size - Fail\n");
	}
}
void cardDrawTest()
//		requires "3" tests
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	// cards used are irrelevant for this test
	int i;
	
	int numPlayer = 2;
	int seed = 1000;
	struct gameState* testGame = newGame();
	
	initializeGame(numPlayer, k, seed, testGame);
	//	retain the reference information for game;
	
	int currentPlayer = 0;
	printf("Test 1 - draw from a deck\n");
	//	situation one - standard draw
	cardDrawTestHelper (testGame);
	
	printf("Test 2 - draw from empty deck\n");
	// situation 2 - empty deck
	int currentDeckSize = fullDeckCount(currentPlayer, 0, testGame);
	for (i = numHandCards(testGame); i < currentDeckSize; i++)
		drawCard(currentPlayer, testGame);
	cardDrawTestHelper (testGame);
	
	printf("Test 3 - draw from empty deck, with discard\n");
	discardCard (1, currentPlayer, testGame, 0);
	cardDrawTestHelper( testGame);
}

int main()
{
	cardDrawTest();
	return 0;
}