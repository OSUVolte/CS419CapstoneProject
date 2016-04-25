#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers.h"
#include <assert.h>


/************************
 * Testing council_room card
 ***********************/

void council_roomTest(){
	struct gameState game, compareGame;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	//int k[10] = {copper, silver, gold, copper, silver, gold, copper, silver, gold, gold};

	printf("Testing council room.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 900;

	struct compareReturn compres; 
	int problems = 0;

	initializeGame(numberOfPlayers, k, randomSeed, &game);
	memcpy(&compareGame, &game, sizeof(struct gameState));

	game.handCount[1] = 5;
	game.hand[1][0] = council_room;
	game.hand[1][1] = copper;
	game.hand[1][2] = copper;
	game.hand[1][3] = copper;
	game.hand[1][4] = copper;

	compareGame.handCount[1] = 5;
	compareGame.hand[1][0] = council_room;
	compareGame.hand[1][1] = copper;
	compareGame.hand[1][2] = copper;
	compareGame.hand[1][3] = copper;
	compareGame.hand[1][4] = copper;

	council_roomCard(1, 0, &game);

	//compareGame
	for(int i = 0; i < 4; i++){
		drawCard(1, &compareGame);
	}

	compareGame.numBuys++;

	for(int i = 0; i < compareGame.numPlayers; i++){
		if(i != 1){
			drawCard(i, &compareGame);
		}
	}

	discardCard(0, 1, &compareGame, 0);

	printf("+++++ Testing game vs compare state for player 2. +++++\n");
	printf("Comparing player 2 in game vs compare game. \n");
	compres = compareGameStates(&game, &compareGame, 1);
	if(printCompareResults(compres)) printf("Player 2: Added cards to game state okay.\n");
	else{
	   	printResults(&game, &compareGame);
		problems++;
	}	
	printf("Comparing player 1 in game vs compare game. \n");
	compres = compareGameStates(&game, &compareGame, 0);
	if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
	else {
		printResults(&game, &compareGame);
		problems++;
	}

	
	
	printf("\n\nNumber of operations where problems were found: %i\n\n", problems);

	printf("<--- Council room Testing Completed successfully --->\n\n");
}

int main(){

	council_roomTest();
	return 0;

}
