#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers_unit.h"
#include <assert.h>


/************************
 * Testing fullDeckCount
 * - Correctly calculates number of times a card appeares in
 *   the full deck (include hand, discard, and deck). 
 * - Cards from other players are not included in count.
 * - Cards are not added/removed in the course of counting.
 * *********************/

void fullDeckCountTest(){
	struct gameState game, compareGame, startState, compareStartState;
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	//int k[10] = {copper, silver, gold, copper, silver, gold, copper, silver, gold, gold};

	printf("Testing fullDeckCount.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 10;

	int problems = 0;
	struct compareReturn compres;

	for(int j = 0; j < 1; j++){

		initializeGame(numberOfPlayers, k, randomSeed, &game);
		memcpy(&compareGame, &game, sizeof(struct gameState));
		memcpy(&startState, &game, sizeof(struct gameState));
		memcpy(&compareStartState, &compareGame, sizeof(struct gameState));
	
		int count = 0;
		int countTest = 0;

		/*       Testing with empty hand, looking for copper      */
		printf("Testing with: empty hand, empty discard, looking for copper\n");
		countTest = fullDeckCount(1, copper, &game);
		for(int i = 0; i < compareGame.handCount[1]; i++)
			if(compareGame.hand[1][i] == copper) count ++;
		for(int i = 0; i < compareGame.discardCount[1]; i++)
			if(compareGame.discard[1][i] == copper) count ++;
		for(int i = 0; i < compareGame.deckCount[1]; i++)
			if(compareGame.deck[1][i] == copper) count ++;
		
		if(count == countTest) printf("count: %i  counttest: %i\n\n", count, countTest);	
		else{
			printf("Card count for game does not equal card count for compare game.\n\n");
			problems++;
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
	
		/*       Testing with 1 card in hand, looking for copper      */
		printf("Testing with: 1 card in hand, empty discard, looking for copper\n");
	
		count = 0;

		game.handCount[1]++;
		game.hand[1][0] = copper;
		compareGame.handCount[1]++;
		compareGame.hand[1][0] = copper;

		countTest = fullDeckCount(1, copper, &game);
		for(int i = 0; i < compareGame.handCount[1]; i++)
			if(compareGame.hand[1][i] == copper) count++;
		for(int i = 0; i < compareGame.discardCount[1]; i++)
			if(compareGame.discard[1][i] == copper) count++;
		for(int i = 0; i < compareGame.deckCount[1]; i++)
			if(compareGame.deck[1][i] == copper) count++;
		
		if(count == countTest) printf("count: %i  counttest: %i\n\n", count, countTest);	
		else{
			printf("Card count for game does not equal card count for compare game.\n\n");
			problems++;
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


		/*Testing with 1 card in hand, 1 in disard, looking for copper*/
		printf("Testing with: 1 card in hand, 1 in discard, looking for copper\n");
	
		count = 0;

		game.discardCount[1]++;
		game.discard[1][0] = copper;
		compareGame.discardCount[1]++;
		compareGame.discard[1][0] = copper;

		countTest = fullDeckCount(1, copper, &game);
		for(int i = 0; i < compareGame.handCount[1]; i++)
			if(compareGame.hand[1][i] == copper) count++;
		for(int i = 0; i < compareGame.discardCount[1]; i++)
			if(compareGame.discard[1][i] == copper) count++;
		for(int i = 0; i < compareGame.deckCount[1]; i++)
			if(compareGame.deck[1][i] == copper) count++;
	
		if(count == countTest) printf("count: %i  counttest: %i\n\n", count, countTest);	
		else{
			printf("Card count for game does not equal card count for compare game.\n\n");
			problems++;
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


		/*Testing with 1 card in hand, 1 in disard, looking for ambassador*/
		printf("Testing with: 1 card in hand, 1 in discard, looking for ambassador\n");
	
		count = 0;

		game.discardCount[1]++;
		game.discard[1][0] = copper;
		compareGame.discardCount[1]++;
		compareGame.discard[1][0] = copper;

		countTest = fullDeckCount(1, ambassador, &game);
		for(int i = 0; i < compareGame.handCount[1]; i++)
			if(compareGame.hand[1][i] == ambassador) count++;
		for(int i = 0; i < compareGame.discardCount[1]; i++)
			if(compareGame.discard[1][i] == ambassador) count++;
		for(int i = 0; i < compareGame.deckCount[1]; i++)
			if(compareGame.deck[1][i] == ambassador) count++;
	
		if(count == countTest) printf("count: %i  counttest: %i\n\n", count, countTest);	
		else{
			printf("Card count for game does not equal card count for compare game.\n\n");
			problems++;
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
	}


	printf("\n\nProblems found: %i\n\n", problems);	
	printf("<--- fullDeckCount Testing Completed successfully --->\n\n");
}

int main(){

	fullDeckCountTest();

	return 0;

}
