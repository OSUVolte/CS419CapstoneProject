/********************************************************
*	Name: 	Robert Tang
*	Class:	CS 362
*	File:	cardtest4.c
*
*	Description: 
*		Test for adventurer
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
	
	printf("Test - Adventurer \n");
	
	int currentPlayer = 0;
	int handCount = testGame->handCount[currentPlayer];

//	int deckCount = testGame->deckCount[currentPlayer];
//	int discardCount = testGame->discardCount[currentPlayer];
	
	playAdventurer(testGame);
	
	int currentHandCount = testGame->handCount[currentPlayer];
	int treasure1 = testGame->hand[currentPlayer][currentHandCount - 1];	// last treasure
	int treasure2 = testGame->hand[currentPlayer][currentHandCount - 2];	//	first treasure
	int drawnDiscard = testGame->discardCount[currentPlayer];
	
	if (testGame->handCount[currentPlayer != handCount - 1 + 2])
		printf("Adventurer add 2 cards remove 1 - Fail \n");
	else
		printf("Adventurer add 2 cards remove 1 - check \n");
	
	if (treasure1 == copper || treasure1 == silver || treasure1 == gold)
		printf("Adventurer last Treasure Care - Check \n");
	else
		printf("Adventurer last Treasure Care - Fail \n");

	if (treasure2 == copper || treasure2 == silver || treasure2 == gold)
		printf("Adventurer first Treasure Care - Check \n");
	else
		printf("Adventurer first Treasure Care - Fail \n");
	
	if (drawnDiscard - 2 + 1 == testGame->discardCount[currentPlayer])
		printf("Adventurer drawn discards - check \n");
	else
		printf("Adventurer drawn discards - fail \n");


	return 0;
	
}