/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/22/16
File: cardtest4.c

Overview: Testing the Feast Card.

Card should discard 1 and gain value of +5


*******************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>


int main()
{
	struct gameState game;
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("\n\n ---Feast Card Test  Start--- \n\n");
	
	initializeGame(2, kingdomCards, 12, &game);
	game.hand[0][1] = feast;
	playCard(1, village, 0, 0, &game);

	//testing feast discard function
	if(game.discardCount[0] ==1){
		printf("\nPASSED: Discarded 1 card\n");
	}
	else{
		printf("\nFAILED: Did not discard 1 card.");
	}
	
	//testing +5 card value
	if(game.handCount[0] == 5){
		printf("\nPASSED: +5 value added to hand. \n");
	}
	
	else{
		printf("\nFAILED: No value added to hand. \n");
	}
	
	printf("\n --- Feast Card Test End --- \n\n");
	
	return 0;
}