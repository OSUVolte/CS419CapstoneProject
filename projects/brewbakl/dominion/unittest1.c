/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/22/16
File: unittest1.c

Overview: This test is to make sure the game intializes correctly. Number of players is set to 2 by default.  Runs Pass or Fail on each category, records number of failures, if any.


*******************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>



int main()
{
	int result;
	int errors = 0;
	
	struct gameState *game = newGame();
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	int numPlayers = 2;
	
	result = initializeGame(numPlayers, kingdomCards, 2, game);
	printf("\n\n ---Testing Game Initialization Start--- \n\n");
	
	// Checking number of players intialized correctly.  
	if (game->numPlayers != numPlayers){
		printf("FAIL: Number of players not properly initialized.\n");
		errors++;
	}
	else{
		printf("PASS: Players initialized correctly\n");
	}
	
	//check kingdom cards
	if (result == -1){
		printf("FAIL: Kingdom cards are returned as containing copies.\n");
		errors++;
	}
	else{
		printf("PASS: Kingdom cards intialized correctly\n");
	}
	
	//check curse cards
	if ((game->supplyCount[curse] != 10) && (numPlayers == 2)){
		printf("FAIL: Supply count of curse didn't initalize correctly.\n");
		errors++;
	}
	else{
		printf("PASS: Curse cards intialized correctly\n");
	}
	
	//check victory cards
    if ((numPlayers == 2) && (game->supplyCount[estate] != 8) && (game->supplyCount[duchy] != 8) && (game->supplyCount[province] != 8)){
		printf("FAIL: Supply count of victory cards didn't initialize correctly.\n");
		errors++;
	}
	
	else if ((game->supplyCount[estate] != 12) && (game->supplyCount[duchy] != 12) && (game->supplyCount[province] != 12)){
		printf("FAIL: Supply count of victory cards didn't initialize correctly.\n");
		errors++;
	}
	
	else{
		printf("PASS: Victory cards intialized correctly\n");
	}
	
	//check treasure cards
	if (game->supplyCount[copper] != 60-(numPlayers*7) || game->supplyCount[silver] != 40 || game->supplyCount[gold] != 30){
		printf("FAIL: Supply count of treasure cards didn't initialize correctly.\n");
		errors++;
	}
	
	else{
		printf("PASS: Treasure cards intialized correctly\n");
	}
	
	//check deckCount 
	if ((game->deckCount[0] != 10) || (game->deckCount[1] != 10) && (game->deckCount[2] != 10)){
		printf("FAIL: Player deck counts were not initialized correctly.\n");
		errors++;
	}
	else{
		printf("PASS: Deck Count intialized correctly\n");
	}
	
	//check player 1 deck
	if ((game->deck[0][0] != copper) || (game->deck[0][3] != estate)){
		printf("FAIL: Player 1 deck was not initialized correctly.\n");
		errors++;
	}
	else{
		printf("PASS: P1 deck intialized correctly\n");
	}	
	
	//check player 2 deck
	if ((game->deck[1][0] != copper) || (game->deck[1][3] != estate)){
		printf("FAIL: Player 2 deck was not initialized correctly.\n");
		errors++;
	}
	else{
		printf("PASS:P2 deck intialized correctly\n");
	}

	//check embargo tokens
	if (game->embargoTokens[0] != 0){
		printf("FAIL: Embargo tokens were not initialized correctly.\n");
		errors++;
	}
	else{
		printf("PASS: Embargo tokens intialized correctly\n");
	}
	
	//check if P1 has first turn
	if (whoseTurn != 0){
		printf("FAIL: First player not set to the first turn.\n");
		errors++;
	}
	
	else{
		printf("PASS: Turn intialized correctly\n");
	}
	
	if (errors > 0){
		printf("There were %d errors in total\n", errors);
	}
	
	else {
		printf("Test was successful.");
	}
	
	printf("\n\n --- Game Initialization Test End --- \n\n");
	
	return 0;
}