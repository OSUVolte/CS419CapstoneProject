//Rick Garnica
//CS 362
//Test:  Council Room


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(int argc, char const *argv[]) {
    
	struct gameState game;
	int buysBefore, handCountBeforeP1, handCountBeforeP2;
	int k[10] = {adventurer, council_room, mine, remodel, village, smithy, ambassador, embargo, sea_hag, mine};
	int currentPlayer;
	
	printf("==============================================\r\n");
	printf("\n   Testing Council Room card:\r\n");
	printf("==============================================\r\n");
	
	//start game
	initializeGame(2, k, 12, &game);
	
	currentPlayer = game.whoseTurn;
	game.hand[0][1] = council_room;

	buysBefore = game.numBuys;
	handCountBeforeP1 = game.handCount[currentPlayer];
	handCountBeforeP2 = game.handCount[1];
	
	playCard(1, council_room, 0, 0,&game);

	
	if ((buysBefore - game.numBuys) != 1){
		printf("\nBuy count was not changed correctly.\n");
	}
	else{
		printf("\nBuy count was changed correctly \n");
	}
	
	int p1Current = game.handCount[currentPlayer];
	int p1difference = p1Current - handCountBeforeP1;
	if (p1difference != 4){
		printf("Player1 hand count not changed correctly.");

		printf("Hand count =  %d.  Should be 4. \n", p1Current);

	}	
	else{
		printf("Player 1 hand count changed correctly \n");
	}
	
	if (((handCountBeforeP2 - game.handCount[2]) != 1)){
		printf("Player 2 hand count not changed correctly.\n");
	}	
	else{
		printf("Player 2 hand count changed correctly \n");
	}

	return 0;
}