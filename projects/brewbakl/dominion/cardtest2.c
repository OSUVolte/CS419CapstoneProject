/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/20/16
File: cardtest2.c

Overview: Testing the Adventurer Card function.  For now, I am just testing to see if +2 cards added to players hand, since treasure cards are implicated in the function.  Also checking the total discard amount to make sure its the same as drawncards - 2.


*******************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

int main(){
	//make new game 
	struct gameState game;
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int currentPlayer; 
	int startHandCount;
	int startDeckCount;	


	
	//start game
	initializeGame(2, kingdomCards, 4, &game);	
	currentPlayer = game.whoseTurn;
	startHandCount = game.handCount[currentPlayer];
	startDeckCount = game.deckCount[currentPlayer];


	printf("\n\n ---Testing Adventurer Card Start--- \n\n");
	
	//check number of cards received from currentPlayer. For now, just test if they draw 2 cards, since treasure cards are implicated in main function.
	if(game.handCount[currentPlayer] == startHandCount + 1){ 
		printf("	PASS: Player received 2 treasure cards\n");

	} 
	else {
		printf("	FAIL: Player did not receive 2 treasure cards\n");
	}
	
	//Compare starting deck count with number of cards drawn.  Should be deckcount - 2.
	int drawnCards = startDeckCount - game.deckCount[currentPlayer];
	if(game.deckCount[currentPlayer] == startDeckCount - 2){  

		printf("	PASS: Cards drawn: %d", drawnCards);
		printf("\n Cards in discard pile: %d \n", game.discardCount[currentPlayer]);
		printf(" Cards in discard should be -2 of drawn cards");
	} 
	//If fail, show how many cards drawn and how many in discard pile
	else {
		printf("	FAIL: Cards drawn: %d.", drawnCards);
		printf(" Cards in discard pile: %d.", game.discardCount[currentPlayer]);
        printf(" Cards in discard should be -2 of drawn cards. \n");
	}
	
	printf("\n ---End Adventurer Card Test---\n\n");
	return 0;
}
