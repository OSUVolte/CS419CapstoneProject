/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/21/16
File: unittest3.c

Overview: Testing the isGameOver() function.

Set the correct end game criteria and test to see if the game ends correctly.

If the game ends, the isGameOver() function returns 1, else returns 0.

*******************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	//create game state
	struct gameState *game = newGame();
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	initializeGame(2, kingdomCards, 2, game);
	
	//Game should end when province cards = 0.  
	game->supplyCount[province] = 0;	

	printf("\n\n --- Start isGameOver() Test --- \n\n\n");
	if (isGameOver(game) == 1){
		printf("PASS: Game ended correctly.\n");
	}
	
	else
		printf("FAIL: Games did not end correctly");

	printf("\n\n --- isGameOver() Test End --- \n\n");
	
	return 0;
}