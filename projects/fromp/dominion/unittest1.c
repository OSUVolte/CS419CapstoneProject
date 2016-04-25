#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers.h"
#include <assert.h>


/************************
 * Testing:
 * - Correct destination (discard, deck, hand) has gained only 1 card
 * - Other players/destinations have not gained any cards
 * - Number of cards in supply pile has decreased
 * - If supply pile is empty or card is not used, -1 is returned
 * *********************/

void gainCardTest(){
	struct gameState game, compareGame, startState, compareStartState;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf("Testing gainCard.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 1000;

	int problems = 0;

	//Create 4 copies of the game states, game is normal game, compare game
	//is what *should* happen, startState/compareState are to make sure
	//unwanted changes do not happen.
	initializeGame(numberOfPlayers, k, randomSeed, &game);
	memcpy(&compareGame, &game, sizeof(struct gameState));
	memcpy(&startState, &game, sizeof(struct gameState));
	memcpy(&compareStartState, &compareGame, sizeof(struct gameState));

	//Struct for getting test comparison results
	struct compareReturn compres;

	printf("States before using gainCard\n\n");
	printResults(&game, &compareGame);

	int funcResults = 0;
	int compResults = 0;

	for(int i = 0; i < 10; i++){
		int testCard = k[i];
		printf("\nRound %i\n", i+1);
		printf("Adding card to discard. \n");
		funcResults = gainCard(testCard, &game, 0, 1);
		compareGame.discardCount[1]++;
		compareGame.discard[1][i] = testCard;
		compareGame.supplyCount[testCard]--;
		compResults = 0;
		
		if(compResults != funcResults){
			problems++;
			printf("Function call results do not match. \n");
		}

		compres = compareGameStates(&game, &compareGame, 1);
		printf("Testing game vs compare state for player 2.\n");
		if(printCompareResults(compres)) printf("Player 2: okay.\n");
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

		printf("Adding card to deck.\n");
		funcResults = gainCard(testCard, &game, 1, 1);
		compareGame.deckCount[1]++;
		compareGame.deck[1][10 + i] = testCard;
		compareGame.supplyCount[testCard]--;
		compResults = 0;

		if(compResults != funcResults){
			problems++;
			printf("Function call results do not match. \n");
		}

		compres = compareGameStates(&game, &compareGame, 1);
		printf("Testing game vs compare state for player 2.\n");
		if(printCompareResults(compres)) printf("Player 2: okay.\n");
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
		
		printf("Adding card to hand.\n");

		funcResults = gainCard(testCard, &game, 2, 1);
		compareGame.handCount[1]++;
		compareGame.hand[1][i] = testCard;
		compareGame.supplyCount[testCard]--;
		compResults = 0;

		if(compResults != funcResults){
			problems++;
			printf("Function call results do not match. \n");
		}
		compres = compareGameStates(&game, &compareGame, 1);
		printf("Testing game vs compare state for player 2.\n");
		if(printCompareResults(compres)) printf("Player 2: okay.\n");
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
		
	}

	int testCard = ambassador;
	printf("\nRound %i\n", 11);
	printf("Adding card to discard. \n");
	funcResults = gainCard(testCard, &game, 0, 1);
	for(int z = 0; z < 10; z++){
		if(k[z] == testCard){
			compareGame.discardCount[1]++;
			compareGame.discard[1][10] = testCard;
		}
	}
	compResults = -1;

	if(compResults != funcResults){
		problems++;
		printf("Function call results do not match. \n");
	}

	compres = compareGameStates(&game, &compareGame, 1);
	printf("Testing game vs compare state for player 2.\n");
	if(printCompareResults(compres)) printf("Player 2: okay.\n");
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

	printf("Adding card to deck.\n");
	funcResults = gainCard(testCard, &game, 1, 1);
	for(int z = 0; z < 10; z++){
		if(k[z] == testCard){
			compareGame.deckCount[1]++;
			compareGame.deck[1][10] = testCard;
			compareGame.supplyCount[testCard]--;
		}
	}
	compResults = -1;

	if(compResults != funcResults){
		problems++;
		printf("Function call results do not match. \n");
	}

	compres = compareGameStates(&game, &compareGame, 1);
	printf("Testing game vs compare state for player 2.\n");
	if(printCompareResults(compres)) printf("Player 2: okay.\n");
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
	
	printf("Adding card to hand.\n");

	funcResults = gainCard(testCard, &game, 2, 1);
	for(int z = 0; z < 10; z++){
		if(k[z] == testCard){
			compareGame.handCount[1]++;
			compareGame.hand[1][10] = testCard;
			compareGame.supplyCount[testCard]--;
		}
	}
	compResults = -1;

	if(compResults != funcResults){
		problems++;
		printf("Function call results do not match. \n");
	}


	compres = compareGameStates(&game, &compareGame, 1);
	printf("Testing game vs compare state for player 2.\n");
	if(printCompareResults(compres)) printf("Player 2: okay.\n");
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
	
	printf("\n\nFinal state of game and compareGame\n\n");

	printResults(&game, &compareGame);

	printf("Problems found: %i", problems);
	printf("\n\n<--- gainCard Testing Completed successfully --->\n\n");

}

int main(){

	gainCardTest();

	return 0;

}
