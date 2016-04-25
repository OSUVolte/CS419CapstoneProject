/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	cardtest2.c
*
*	Description: 
*		Test for Adventure Card
********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

int main ()
{
	int seed = 1000;
	int numPlayer = 2;
	struct gameState* testGame = newGame();
	
	
 	
 	int k[10] = {adventurer, council_room, feast, gardens, mine,
 				remodel, smithy, village, baron, great_hall}; 

	initializeGame(numPlayer, k, seed, testGame);
	
	int currentPlayer = 0;	
	int handCount = testGame->handCount[currentPlayer];
	int handPosition = handCount - 1;
	int deckSize = testGame->deckCount[currentPlayer];
	testGame->hand[currentPlayer][handPosition] = council_room; //replace
	
	int test = playCouncil_Room (testGame, handPosition);
	if (test == 0)
		printf("Testing Council Room\n");
	else
		printf("Testing Council Room - Fail \n");
///////////////////////Draw Section////////////////////
	if (testGame->handCount[currentPlayer] != handCount - 1 + 4)
		printf("Council Room Card Effect1 - Fail \n");
	else
		printf("Council Room Effect -  check \n");
	
	if (testGame->hand[currentPlayer][handPosition] != smithy)
		printf("Council Room  Not In Hand - check \n");
	else
		printf("Council Room  Not In Hand  - check \n");
	
	if (testGame->playedCards[testGame->playedCardCount] != council_room)
		printf("Council Room  Placed in Played - check \n");
	else
		printf("Council Room  Placed in Played - fail \n");
	
	if (testGame->deckCount[currentPlayer] != deckSize - 4)
		printf("Council Room  Card Draw - Fail \n");
	else
		printf("Council Room  Card Draw - check \n");
	
/////////////////////Buy Section///////////////////////////
	if (testGame->numBuys != 2)
		printf("Council Room  Card Buy Increase - Fail \n");
	else
		printf("Council Room  Card Buy Increase - check \n");
	
	return 0;
	
}