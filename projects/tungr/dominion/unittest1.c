/*
	Rosa Tung
	CS362
	(20 points) Write unit tests for four functions (not card implementations or cardEffect) in dominion.c. 
	Check these tests in as unittest1.c,unittest2.c, unittest3.c, and unittest4.c. 
	(for example, you can create a test for updateCoins() method)
	
	Testing:
		int whoseTurn(struct gameState *state);
*/

#include "dominion.h" 

#include <stdio.h> //printf scanf

int main(){
	//create gameState object, initialize player turns and hand
	struct gameState G; 
	int currentPlayer; 
	int player1 = 0;
	int player2 = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	printf("---Testing whoseTurn function START---\n\n");
	
	printf("Initialize Game...\n");
	initializeGame(2, k, 4, &G); 
	
	printf("	Attempt to Set to Player 1's turn\n");
	G.whoseTurn = player1;
	currentPlayer = whoseTurn(&G);
	if(currentPlayer == 0){
		printf("		SUCCESS\n");
	}	
	else{
		printf("		FAILURE\n");
	}
	
	printf("	Attempt to Set to player 2's turn\n");
	G.whoseTurn = player2;
	currentPlayer = whoseTurn(&G);
	if(currentPlayer == 1){
		printf("		SUCCESS\n\n");
	}	
	else{
		printf("		FAILURE\n\n");
	}

	printf("---Testing whoseTurn function COMPLETE---\n\n");
	
	return 0;
}