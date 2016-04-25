#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers_unit.h"
#include <assert.h>


/************************
 * Testing smithy card
 ***********************/

void smithyTest(){
	struct gameState game, compareGame, startState, compareStartState;
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	//int k[10] = {copper, silver, gold, copper, silver, gold, copper, silver, gold, gold};

	printf("Testing smithy.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 10;

	struct compareReturn compres; 
	int problems = 0;

	initializeGame(numberOfPlayers, k, randomSeed, &game);
	memcpy(&compareGame, &game, sizeof(struct gameState));
	memcpy(&startState, &game, sizeof(struct gameState));
	memcpy(&compareStartState, &compareGame, sizeof(struct gameState));

	game.handCount[1] = 5;
	game.hand[1][0] = smithy;
	game.hand[1][1] = copper;
	game.hand[1][2] = copper;
	game.hand[1][3] = copper;
	game.hand[1][4] = copper;

	compareGame.handCount[1] = 5;
	compareGame.hand[1][0] = smithy;
	compareGame.hand[1][1] = copper;
	compareGame.hand[1][2] = copper;
	compareGame.hand[1][3] = copper;
	compareGame.hand[1][4] = copper;
	

	printf("+++++ Testing game vs compare state for player 2. +++++\n");
	compres = compareGameStates(&game, &compareGame, 1);
	if(printCompareResults(compres)) printf("Player 2: Added cards to game state okay.\n");
	else{
	   	printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &compareGame, 0);
	if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
	else {
		printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &startState, 0);
	if(printCompareResults(compres)) printf("Game and start state unchanged (for player 1) as expected.\n");
	else{
		printResults(&game, &startState);
		problems++;
	}
	compres = compareGameStates(&compareGame, &compareStartState, 0);
	if(printCompareResults(compres)) printf("Compare and start state unchanged (for player 1) as expected.\n");
	else{
		printResults(&compareGame, &compareStartState);
		problems++;
	}

	
	printf("\n\nCalling using smithy from position 1 in hand.\n");
	smithyCard(1, 0, &game);
	for(int i = 0; i < 3; i++){
		drawCard(1, &compareGame);
	}
	discardCard(0, 1, &compareGame, 0);	
	for(int i = 0; i < compareGame.playedCardCount; i++){
		compareGame.discard[1][compareGame.discardCount[1]] = compareGame.playedCards[i];
		compareGame.discardCount[1]++;
	}
	compareGame.playedCardCount = 0;
	printf("Testing game vs compare state for player 2.\n");
	compres = compareGameStates(&game, &compareGame, 1);
	if(printCompareResults(compres)) printf("Player 2: Added cards to game state okay.\n");
	else{
		printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &compareGame, 0);
	if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
	else{ 
		printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &startState, 0);
	if(printCompareResults(compres)) printf("Game and start state unchanged (for player 1) as expected.\n");
	else{
		printResults(&game, &startState);
		problems++;
	}
	compres = compareGameStates(&compareGame, &compareStartState, 0);
	if(printCompareResults(compres)) printf("Compare and start state unchanged (for player 1) as expected.\n");
	else{
		printResults(&compareGame, &compareStartState);
		problems++;
	}	

	printf("\n\nCalling using smithy from position 1 in hand, with empty deck.\n");

	for(int i = 0; i < game.deckCount[1]; i++){
		game.discard[1][game.discardCount[1]] = game.deck[1][i];
		game.discardCount[1]++;
	}
	game.deckCount[1] = 0;

	for(int i = 0; i < compareGame.deckCount[1]; i++){
		compareGame.discard[1][compareGame.discardCount[1]] = compareGame.deck[1][i];
		compareGame.discardCount[1]++;
	}
	compareGame.deckCount[1] = 0;	

	smithyCard(1, 0, &game);
	for(int i = 0; i < 3; i++){
		drawCard(1, &compareGame);
	}
	discardCard(0, 1, &compareGame, 0);	
	for(int i = 0; i < compareGame.playedCardCount; i++){
		compareGame.discard[1][compareGame.discardCount[1]] = compareGame.playedCards[i];
		compareGame.discardCount[1]++;
	}
	compareGame.playedCardCount = 0;
	printf("Testing game vs compare state for player 2.\n");

	compres = compareGameStates(&game, &compareGame, 1);
	if(printCompareResults(compres)) printf("Player 2: Added cards to game state okay.\n");
	else{
		printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &compareGame, 0);
	if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
	else{ 
		printResults(&game, &compareGame);
		problems++;
	}
	compres = compareGameStates(&game, &startState, 0);
	if(printCompareResults(compres)) printf("Game and start state unchanged (for player 1) as expected.\n");
	else{ 
		printResults(&game, &startState);
		problems++;
	}
	compres = compareGameStates(&compareGame, &compareStartState, 0);
	if(printCompareResults(compres)) printf("Compare and start state unchanged (for player 1) as expected.\n");
	else{ 
		printResults(&compareGame, &compareStartState);
		problems++;
	}

	printf("\n\nNumber of operations where problems were found: %i\n\n", problems);

	printf("<--- smithy Testing Completed successfully --->\n\n");
}

int main(){

	smithyTest();

	return 0;

}
