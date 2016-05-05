//Rick Garnica
//CS 362
//Test:  Feast Card


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(int argc, char const *argv[]) {
	
    struct gameState game;
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("==============================================\r\n");
	printf("\n   Testing Feast card:\r\n");
	printf("==============================================\r\n");
	
	initializeGame(2, kingdomCards, 12, &game);
	game.hand[0][1] = feast;
	playCard(1, village, 0, 0, &game);

	//testing feast discard function
	if(game.discardCount[0] ==1){
		printf("\nDiscarded 1 card\n");
	}
	else{
		printf("\nDid not discard 1 card.");
	}
	
	//testing +5 card value
	if(game.handCount[0] == 5){
		printf("\n+5 value added to hand. \n");
	}
	
	else{
		printf("\nNo value added to hand. \n");
	}
	
	

	return 0;
}