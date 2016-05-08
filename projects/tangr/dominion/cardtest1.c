/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	cardtest1.c
*
*	Description: 
*		Test for Smithy
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
	
	printf("Test - Smithy \n");
	
	int currentPlayer = 0;
	int handSize = testGame->handCount[currentPlayer];
	int handPosition = handSize - 1;
	int deckSize = testGame->deckCount[currentPlayer];
//	int playedCards = testGame->playedCardCount;
	testGame->hand[currentPlayer][handPosition] = smithy;
	
	int tester = playSmithy(testGame, handPosition);
		printf("Smithy Card Play - ");
	if (tester != 0)
		printf(" Fail \n");
	else
		printf(" check \n");
	if (testGame->handCount[currentPlayer] != handSize - 1 + 3)
		printf("Smithy Card Effect - Fail \n");
	else
		printf("Smithy Card Effect -  check \n");
	
	if (testGame->hand[currentPlayer][handPosition] != smithy)
		printf("Smithy Card Not In Hand - check \n");
	else
		printf("Smithy Card Not In Hand  - check \n");
	
	if (testGame->playedCards[testGame->playedCardCount] != smithy)
		printf("Smith Card Placed in Played - check \n");
	else
		printf("Smith Card Placed in Played - fail \n");
	
	if (testGame->deckCount[currentPlayer] != deckSize - 3)
		printf("Smith Card Draw - Fail \n");
	else
		printf("Smith Card Draw - check \n");	
	return 0;
}