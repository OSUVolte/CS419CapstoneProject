#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "test_helpers_unit.h"
#include <assert.h>


/************************
 * Testing buyCard:
 * - Correct destination has received correct card
 * - Other players/destinations have not received any cards
 * - Number of cards in supply pile has decreased
 * - Coins and buys have decreased
 * - If supply pile is empty or card is not used, -1 is returned
 * *********************/

void buyCardTest(){
	struct gameState game, compareGame, startState, compareStartState;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf("Testing gainCard.\n\n");

	int numberOfPlayers = 2;
	int randomSeed = 1000;

	int problems = 0;

	printf("States before using gainCard\n\n");
	for(int j = 0; j < 11; j++){
		int card; 
		if(j < 10) card = k[j];
		else card = ambassador;

		initializeGame(numberOfPlayers, k, randomSeed, &game);
		memcpy(&compareGame, &game, sizeof(struct gameState));
		memcpy(&startState, &game, sizeof(struct gameState));
		memcpy(&compareStartState, &compareGame, sizeof(struct gameState));

		struct compareReturn compres; 

		printf("Testing card number %i\n\n", j);
		for(int i = 0; i < 20; i++){
			int coins = i;
			int playerBuys = i % 2;
			
			printf("Num of Cards: %i  Card Cost: %i  Card: %i\n\n", supplyCount(card, &game), getCost(card), card);

			int player = i % 2;
			game.whoseTurn = player;	
			compareGame.whoseTurn = player;
			game.coins = coins;
			compareGame.coins = coins;
			game.numBuys = playerBuys;
			compareGame.numBuys = playerBuys;

			printf("\nRound %i\n", i+1);
			int buyResults = buyCard(card, &game);
			printf("Results of buy: %i\n", buyResults);
			if(supplyCount(card, &compareGame) > 0 && compareGame.coins >= getCost(card) && compareGame.numBuys > 0){
				compareGame.coins = compareGame.coins - getCost(card);
				compareGame.numBuys--;
				compareGame.phase = 1;
				gainCard(card, &compareGame, 0, player);
			}

			printf("Game State vs Compare Game State, player 1.\n");	
			
			compres = compareGameStates(&game, &compareGame, 0);
			printf("Testing game vs compare state for player 1.\n");
			if(printCompareResults(compres)) printf("Player 1: okay.\n");
			else {
				printResults(&game, &compareGame);
				problems++;
			}
			compres = compareGameStates(&game, &compareGame, 1);
			printf("Testing game vs compare state for player 2.\n");
			if(printCompareResults(compres)) printf("Player 2: okay.\n");
			else {
				printResults(&game, &compareGame);
				problems++;
			}
		}
		printf("\n\n");
		printResults(&game, &compareGame);
	}

	printf("Problems found: %i\n", problems);	
	printf("\n\n<--- buyCard Testing Completed successfully --->\n\n");

}

int main(){

	buyCardTest();

	return 0;

}
