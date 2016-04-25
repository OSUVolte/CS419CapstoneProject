/********************************
Author: Luke Brewbaker
Date: 4/18/16
Modified:4/22/16
File: cardtest3.c

Overview: Testing the the Council Room Card. 

player1 should get 4 cards.
Every other player should get 1 card.  There are 2 players seeded in this game.

*******************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

int main()
{

	printf(" --- Council Room Card Test Start --- \n");
	
	struct gameState game;
	int buysBefore, handCountBeforeP1, handCountBeforeP2;
	int kingdomCards[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	int currentPlayer;
	
	//start game
	initializeGame(2, kingdomCards, 12, &game);
	
	//set player 1 first card to council room.
	currentPlayer = game.whoseTurn;
	game.hand[0][1] = council_room;

	//record hand count values before playing the card.
	buysBefore = game.numBuys;
	handCountBeforeP1 = game.handCount[currentPlayer];
	handCountBeforeP2 = game.handCount[1];
	
	//play the council_room card from player 1 hand.
	playCard(1, council_room, 0, 0, &game);

	
	//test buy count  should be 1
	if ((buysBefore - game.numBuys) != 1){
		printf("\nFAIL: buyCount not changed correctly.\n");
	}
	else{
		printf("\n PASS: buyCount changed correctly \n");
	}
	
	//test hand count.  Should be +4.  If not, test fails.
	int p1Current = game.handCount[currentPlayer];
	int p1difference = p1Current -handCountBeforeP1;
	if (p1difference != 4){
		printf("FAIL: P1 handCount not changed correctly.");

		printf(" Cards drawn: %d.  Should be 4. \n", p1Current);

	}	
	else{
		printf("PASS: P1 handCount changed correctly \n");
	}
	
	//test player2 handcount.  Should be +1.  If not, test Fails.
	if (((handCountBeforeP2 - game.handCount[2]) != 1)){
		printf("FAIL: P2 handCount not changed correctly.\n");
	}	
	else{
		printf("PASS: P2 handCount changed correctly \n");
	}

	
	printf("\n --- Council Room Card Test End --- \n\n");
	
	return 0;
}