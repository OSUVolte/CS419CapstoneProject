#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers.h"
#include <assert.h>


/************************
 * Testing remodel card
 ***********************/

void remodelCardTest(){
	struct gameState game, compareGame;
	int k[10] = {adventurer, gardens, embargo, village, province, mine, cutpurse, sea_hag, tribute, smithy};

	//int k[10] = {copper, silver, gold, copper, silver, gold, copper, silver, gold, gold};

	printf("Testing remodel.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 900;

	struct compareReturn compres; 
	int problems = 0;

	initializeGame(numberOfPlayers, k, randomSeed, &game);
	memcpy(&compareGame, &game, sizeof(struct gameState));

	game.handCount[1] = 5;
	game.hand[1][0] = adventurer;
	game.hand[1][1] = remodel;
	game.hand[1][2] = smithy;
	game.hand[1][3] = copper;
	game.hand[1][4] = copper;

	compareGame.handCount[1] = 5;
	compareGame.hand[1][0] = adventurer;
	compareGame.hand[1][1] = remodel;
	compareGame.hand[1][2] = smithy;
	compareGame.hand[1][3] = copper;
	compareGame.hand[1][4] = copper;

	int gameRemodelResult = remodelCard(1, 1, 2, adventurer, &game);

	//compareGame
	discardCard(2, 1, &compareGame, 1);
	discardCard(1, 1, &compareGame, 0);
	gainCard(adventurer, &compareGame, 0, 1);
	int compRemodelResult = 0;

	printf("+++++ Testing game vs compare state for player 2. +++++\n");

	if( gameRemodelResult == compRemodelResult )
		printf("Remodel function call results match.\n");
	else{
		printf("-- Remodel function call results do not match.\n");
		problems++;
	}

	compres = compareGameStates(&game, &compareGame, 1);
	if(printCompareResults(compres)) printf("Player 2: Added cards to game state okay.\n");
	else{
	   	printResults(&game, &compareGame);
		problems++;
	}

	initializeGame(numberOfPlayers, k, randomSeed, &game);
	memcpy(&compareGame, &game, sizeof(struct gameState));

	game.handCount[1] = 5;
	game.hand[1][0] = remodel;
	game.hand[1][1] = adventurer;
	game.hand[1][2] = smithy;
	game.hand[1][3] = copper;
	game.hand[1][4] = copper;

	compareGame.handCount[1] = 5;
	compareGame.hand[1][0] = remodel;
	compareGame.hand[1][1] = adventurer;
	compareGame.hand[1][2] = smithy;
	compareGame.hand[1][3] = copper;
	compareGame.hand[1][4] = copper;

	gameRemodelResult = remodelCard(1, 0, 4, adventurer, &game);

	//compareGame
	compRemodelResult = -1;

	printf("\n\n");

	printf("+++++ Testing game vs compare state for player 2. +++++\n");
	if( gameRemodelResult == compRemodelResult )
		printf("Remodel function call results match.\n");
	else{
		printf("-- Remodel function call results do not match.\n");
		printf("Game function call result: %i  Compare function call result: %i\n", gameRemodelResult, compRemodelResult);
		problems++;
	}
	compres = compareGameStates(&game, &compareGame, 1);
	if(printCompareResults(compres)) printf("Player 2: Added cards to game state okay.\n");
	else{
	   	printResults(&game, &compareGame);
		problems++;
	}

	printf("\n\nNumber of operations where problems were found: %i\n\n", problems);

	printf("<--- Remodel Testing Completed successfully --->\n\n");
}

int main(){

	remodelCardTest();
	return 0;

}
