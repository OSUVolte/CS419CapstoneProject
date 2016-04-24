/********************************************************************
 * Kara Franco
 * unittest4: whoseTurn() function
 * Due Date: April 24, 2016
 * ****************************************************************/

#include "dominion.h" 
#include <stdio.h>

int main(){

	printf("\n------------------------Unit Test 4-----------------------------\n\n");
	printf("---Test whoseTurn()---\n");
	
	// create a game to test
  	struct gameState game;
  	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	printf("Initialize Game...\n");
		
	initializeGame(2, cards, 10, &game);
	int currentPlayer; 
	int player1 = 0;
	int player2 = 1;
	
	printf("Testing if Player 1's turn is set...\n");
	game.whoseTurn = player1;
	currentPlayer = whoseTurn(&game);
	if(currentPlayer == 0){
		printf("PASS\n");
	}	
	else{
		printf("FAIL\n");
	}
	
	printf("Testing if Player 2's turn it set...\n");
	game.whoseTurn = player2;
	currentPlayer = whoseTurn(&game);
	if(currentPlayer == 1){
		printf("PASS\n");
	}	
	else{
		printf("FAIL\n");
	}

	printf("---whoseTurn() Test Complete---\n\n");
	
	return 0;
}