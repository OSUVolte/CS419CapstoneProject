/********************************************************************
 * Kara Franco
 * unittest2: numHandCards() function
 * Due Date: April 24, 2016
 * ****************************************************************/

#include "dominion.h"
#include <stdio.h>

int main(){

	printf("\n------------------------Unit Test 2-----------------------------\n\n");
	printf("---Test numHandCards()---\n");
	// create a game to test
  	struct gameState game;
  	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	printf("Initialize Game...\n");
		
	initializeGame(2, cards, 1, &game);
	// set testing variables
	game.whoseTurn = 0;
  	int counter;
	// numHandCards() will 0 when handCount is 0
	printf("Testing if returns 0 when no cards in hand...\n");
	game.handCount[0] = 0;
  	counter = numHandCards(&game);
  		if (counter == 0) {
    			printf("PASS\n");
  		} 
		else {
	    		printf("FAIL: returned %d when no cards in hand.\n", counter);
  		}
	// numHandCards() will return the number of cards in handCount
	printf("Testing if returns 8 when handCount is set to 8\n");
  	game.handCount[0] = 8;
  	counter = numHandCards(&game);
  		if (counter == 8) {
    			printf("PASS\n");
  		} 
		else {
    			printf("FAIL: returned %d when 8 was expected.\n", counter);
  		}

  	printf("---numHandCards() Test Complete---\n\n");
	return 0;	
}