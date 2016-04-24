/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/20/16
File: cardtest1.c

Overview: Testing the Smithy card function.  Smithy should add +3 cards to players hand.  This test will check the amount of cards in the players hand before smithy is played, and compare it with the number of cards after smithy is played.

Pass is 3 cards added
Fail if 3 cards not added


*******************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

int main(){
	//make new game 
	struct gameState game;

	int kindomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int currentPlayer;
	int startHandCount;

	
	//starts game
	initializeGame(2, kindomCards, 4, &game);
	currentPlayer = game.whoseTurn;
	startHandCount = game.handCount[currentPlayer];



	printf("\n\n ---Testing Smithy Card ---\n\n");
	//check number of cards received from currentPlayer
	if(game.handCount[currentPlayer] == startHandCount + 3){
		printf("  PASS: Player draws 3 cards\n");

	} else {
		printf("	FAIL: Player does not draw 3 new cards\n");
	}
	
	
	printf("\n ---End Smithy Card Test---\n\n");
	return 0;
}
