#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers_unit.h"
#include <assert.h>


/************************
 * Testing updateCoins
 * - Correctly calculates coins for correct player (including bonus)
 * - Other players' coin counts are not affected.
 * *********************/

void updateCoinsTest(){
	struct gameState game, compareGame, startState, compareStartState;
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	//int k[10] = {copper, silver, gold, copper, silver, gold, copper, silver, gold, gold};

	printf("Testing updateCoins.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 10;

	int problems = 0;
	struct compareReturn compres;

	for(int j = 0; j < 1; j++){

		initializeGame(numberOfPlayers, k, randomSeed, &game);
		memcpy(&compareGame, &game, sizeof(struct gameState));
		memcpy(&startState, &game, sizeof(struct gameState));
		memcpy(&compareStartState, &compareGame, sizeof(struct gameState));
	
		//int compres = 0;
	

		/*    Using empty hand.   */
		printf("\n***Testing 0 copper in hand for player 2.\n");
		
		updateCoins(0, &game, 0);
		compareGame.coins = 4;
		compres = compareGameStates(&game, &startState, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &startState);
			problems++;	
		}
		compres = compareGameStates(&compareGame, &startState, 0);	
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&compareGame, &startState);
			problems++;	
		}
		printf("Coins in regular state for player 1: %i\n", game.coins);
		printf("Coins in compare state for player 1: %i\n\n", compareGame.coins);

		updateCoins(1, &game, 0);
		compareGame.coins = 0;
		compres = compareGameStates(&game, &compareGame, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		compres = compareGameStates(&game, &compareGame, 1);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		printf("Coins in regular state for player 2: %i\n", game.coins);
		printf("Coins in compare state for player 2: %i\n", compareGame.coins);


		/*   Testing with only bonus    */	
		printf("\n***Testing with only a bonus of 5 (no coins).\n");

		updateCoins(0, &game, 0);
		compareGame.coins = 4;
		compres = compareGameStates(&game, &startState, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &startState);
			problems++;	
		}
		compres = compareGameStates(&compareGame, &startState, 0);	
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&compareGame, &startState);
			problems++;	
		}
		printf("Coins in regular state for player 1: %i\n", game.coins);
		printf("Coins in compare state for player 1: %i\n\n", compareGame.coins);

		updateCoins(1, &game, 5);
		compareGame.coins = 5;
		compres = compareGameStates(&game, &compareGame, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		compres = compareGameStates(&game, &compareGame, 1);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		printf("Coins in regular state for player 2: %i\n", game.coins);
		printf("Coins in compare state for player 2: %i\n", compareGame.coins);


		/*   Adding 1 copper to hand.    */	
		printf("\n***Testing 1 copper in hand.\n");
		game.handCount[1]++;
		game.hand[1][0] = copper;
		compareGame.handCount[1]++;
		compareGame.hand[1][0] = copper;

		updateCoins(0, &game, 0);
		compareGame.coins = 4;
		compres = compareGameStates(&game, &startState, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &startState);
			problems++;	
		}
		compres = compareGameStates(&compareGame, &startState, 0);	
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&compareGame, &startState);
			problems++;	
		}
		printf("Coins in regular state for player 1: %i\n", game.coins);
		printf("Coins in compare state for player 1: %i\n\n", compareGame.coins);

		updateCoins(1, &game, 0);
		compareGame.coins = 1;
		compres = compareGameStates(&game, &compareGame, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		compres = compareGameStates(&game, &compareGame, 1);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		printf("Coins in regular state for player 2: %i\n", game.coins);
		printf("Coins in compare state for player 2: %i\n", compareGame.coins);


		/*   Adding 1 silver to hand.    */	
		printf("\n***Testing 1 copper and 1 silver in hand.\n");
		game.handCount[1]++;
		game.hand[1][1] = silver;
		compareGame.handCount[1]++;
		compareGame.hand[1][1] = silver;

		updateCoins(0, &game, 0);
		compareGame.coins = 4;
		compres = compareGameStates(&game, &startState, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &startState);
			problems++;	
		}
		compres = compareGameStates(&compareGame, &startState, 0);	
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&compareGame, &startState);
			problems++;	
		}
		printf("Coins in regular state for player 1: %i\n", game.coins);
		printf("Coins in compare state for player 1: %i\n\n", compareGame.coins);

		updateCoins(1, &game, 0);
		compareGame.coins = 3;
		compres = compareGameStates(&game, &compareGame, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		compres = compareGameStates(&game, &compareGame, 1);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		printf("Coins in regular state for player 2: %i\n", game.coins);
		printf("Coins in compare state for player 2: %i\n", compareGame.coins);

		/*   Adding 1 gold to hand.    */	
		printf("\n***Testing 1 copper, 1 silver, and 1 gold in hand.\n");
		game.handCount[1]++;
		game.hand[1][2] = gold;
		compareGame.handCount[1]++;
		compareGame.hand[1][2] = gold;

		updateCoins(0, &game, 0);
		compareGame.coins = 4;
		compres = compareGameStates(&game, &startState, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &startState);
			problems++;	
		}
		compres = compareGameStates(&compareGame, &startState, 0);	
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&compareGame, &startState);
			problems++;	
		}
		printf("Coins in regular state for player 1: %i\n", game.coins);
		printf("Coins in compare state for player 1: %i\n\n", compareGame.coins);

		updateCoins(1, &game, 0);
		compareGame.coins = 6;
		compres = compareGameStates(&game, &compareGame, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		compres = compareGameStates(&game, &compareGame, 1);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		printf("Coins in regular state for player 2: %i\n", game.coins);
		printf("Coins in compare state for player 2: %i\n", compareGame.coins);

		/*   Adding 1 smithy to hand.    */	
		printf("\n***Testing 1 copper, 1 silver, 1 gold, and 1 smithy in hand.\n");
		game.handCount[1]++;
		game.hand[1][3] = smithy;
		compareGame.handCount[1]++;
		compareGame.hand[1][3] = smithy;
		
		updateCoins(0, &game, 0);
		compareGame.coins = 4;
		compres = compareGameStates(&game, &startState, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &startState);
			problems++;	
		}
		compres = compareGameStates(&compareGame, &startState, 0);	
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&compareGame, &startState);
			problems++;	
		}
		printf("Coins in regular state for player 1: %i\n", game.coins);
		printf("Coins in compare state for player 1: %i\n\n", compareGame.coins);

		updateCoins(1, &game, 0);
		compareGame.coins = 6;
		compres = compareGameStates(&game, &compareGame, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		compres = compareGameStates(&game, &compareGame, 1);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		printf("Coins in regular state for player 2: %i\n", game.coins);
		printf("Coins in compare state for player 2: %i\n", compareGame.coins);

		/*   Adding 1 steward to hand.    */	
		printf("\n***Testing 1 copper, 1 silver, 1 gold, 1 smithy, and 1 steward in hand with a bonus of 5.\n");
		game.handCount[1]++;
		game.hand[1][4] = steward;
		compareGame.handCount[1]++;
		compareGame.hand[1][4] = steward;
		
		updateCoins(0, &game, 0);
		compareGame.coins = 4;
		compres = compareGameStates(&game, &startState, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &startState);
			problems++;	
		}
		compres = compareGameStates(&compareGame, &startState, 0);	
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&compareGame, &startState);
			problems++;	
		}
		printf("Coins in regular state for player 1: %i\n", game.coins);
		printf("Coins in compare state for player 1: %i\n\n", compareGame.coins);

		updateCoins(1, &game, 5);
		compareGame.coins = 11;
		compres = compareGameStates(&game, &compareGame, 0);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		compres = compareGameStates(&game, &compareGame, 1);
		if(printCompareResults(compres)) printf("Player 1: No changes (as expected).\n");
		else {
			printResults(&game, &compareGame);
			problems++;	
		}
		printf("Coins in regular state for player 2: %i\n", game.coins);
		printf("Coins in compare state for player 2: %i\n", compareGame.coins);


	}

	printf("\n\nProblems found: %i\n\n", problems);
		
	printf("<--- updateCoins Testing Completed successfully --->\n\n");
}

int main(){

	updateCoinsTest();

	return 0;

}
