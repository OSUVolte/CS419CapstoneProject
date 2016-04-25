/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	unittest1.c
*
*	Description: 
*		Test for card cost
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
	testGame->hand[currentPlayer][handPosition] = feast; //replace
	int deckSize = testGame->deckCount[currentPlayer];

	int tester = playFeast(testGame, handPosition);
	
	printf("Test - Feast \n");
	
		
	if (tester != 0)
		printf("Play feast - Fail \n");
	else
		printf("Play feast - check \n");
	
	if (testGame->handCount[currentPlayer] != handCount - 1)
		printf("feast Card Effect - Fail \n");
	else
		printf("feast Card Effect -  check \n");
	
	if (testGame->hand[currentPlayer][handPosition] != feast)
		printf("feast Card Not In Hand - check \n");
	else
		printf("feast Card Not In Hand  - check \n");
	
		if (testGame->playedCards[testGame->playedCardCount] == feast)
		printf("feast Card Placed in Played - check \n");
	else
		printf("feast Card Placed in Played - fail \n");
	
		
	if (testGame->deckCount[currentPlayer] != deckSize)
		printf("feast Card Draw - Fail \n");
	else
		printf("feast Card Draw - check \n");
	return 0;
	
}