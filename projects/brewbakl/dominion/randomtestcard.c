#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "math.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h> 


int main() {
	int newCards = 0;
	int discarded = 1;
	int shuffledCards = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed;
	int numPlayers = 2;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int newActions;
	struct gameState game, testGame;
	int kindomCards[10] = {adventurer, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy, council_room};
	int i, j, m;


	printf("\n\n --- Random Test Card: Great Hall --- \n\n");
	//runs 10000 tests.
	for (i = 0; i < 10000; i++) {	
		seed = rand(); 
		for (m = 0; m < sizeof(struct gameState); m++) {
			((char*)&game)[m] = floor(Random() * 256);
		}
		// initialize a game state and player cards
		initializeGame(numPlayers, kindomCards, seed, &game);		

		game.handCount[currentPlayer] = floor(Random() * 10);
		game.deckCount[currentPlayer] = floor(Random() * 25);
		game.discardCount[currentPlayer] = floor(Random() * 25);

		//Randomly select cards for hand pile
		for (j = 0; j < game.handCount[currentPlayer]; j++) {
			game.hand[currentPlayer][j] = floor(Random() * (treasure_map + 1));
		}

		//Randomly select cards for discard pile
		for (j = 0; j < game.discardCount[currentPlayer]; j++) {
			game.discard[currentPlayer][j] = floor(Random() * (treasure_map + 1));
		}

		//Randomly select cards for deck 
		for (j = 0; j < game.deckCount[currentPlayer]; j++) {
			game.deck[currentPlayer][j] = floor(Random() * (treasure_map + 1));
		}

		// copy the game state to a test case
		memcpy(&testGame, &game, sizeof(struct gameState));
		cardEffect(great_hall, choice1, choice2, choice3, &testGame, handpos, &bonus);

		newCards = 1;
		newActions = 1;

		//print and check test results
		printf("--------------------------------------------------------------\n");
		printf("\nGreat Hall tests:\n\n");
		printf(" Hand count = %d, expected = %d\n", testGame.handCount[currentPlayer], \
		game.handCount[currentPlayer] + newCards - discarded);
		
		if (testGame.handCount[currentPlayer] == game.handCount[currentPlayer] + newCards - discarded) 
		printf(" PASS on hand count does not change on current player\n");    
		else 	
		printf(" FAIL on hand count does not change on current player\n");

		printf(" Deck count = %d, expected = %d\n", testGame.deckCount[currentPlayer], \
		game.deckCount[currentPlayer] - newCards + shuffledCards);
		
		if (testGame.deckCount[currentPlayer] == game.deckCount[currentPlayer] - newCards + shuffledCards)  
		printf(" PASS on deck count does not change\n");
		else 
		printf(" FAIL on deck count does not change\n");

		printf(" Hand count = %d, expected = %d\n", testGame.handCount[nextPlayer], \
		game.handCount[nextPlayer]);
		
		if (testGame.handCount[nextPlayer] == game.handCount[nextPlayer])
		printf(" PASS on hand count does not change on next player\n");    
		else 	
		printf(" FAIL on hand count does not change on next player\n");

		printf(" Deck count = %d, expected = %d\n", testGame.deckCount[nextPlayer], \
		game.deckCount[nextPlayer]);
		if (testGame.deckCount[nextPlayer] == game.deckCount[nextPlayer])  
		printf(" PASS on deck count does not change on next player\n");
		else 
		printf(" FAIL on deck count does not change on next player\n");

		printf(" Estate = %d, expected = %d, duchy = %d, expected = %d, province = %d, expected = %d\n", \
		testGame.supplyCount[estate], game.supplyCount[estate], testGame.supplyCount[duchy], \
		game.supplyCount[duchy], testGame.supplyCount[province], game.supplyCount[province]);
		
		if (testGame.supplyCount[estate] == game.supplyCount[estate])  
		printf(" PASS on estate count does not change\n");
		else 
		printf(" FAIL on estate count does not change\n");
	
		if (testGame.supplyCount[duchy] == game.supplyCount[duchy])  
		printf(" PASS on duchy count does not change\n");
		else 
		printf(" FAIL on duchy count does not change\n");    
	
		if (testGame.supplyCount[province] == game.supplyCount[province])  
		printf(" PASS on province count does not change\n");
		else 
		printf(" FAIL on province count does not change\n");

		printf(" adventurer = %d, expected = %d\n", testGame.supplyCount[adventurer], \
		game.supplyCount[adventurer]);
		
		if (testGame.supplyCount[adventurer] == game.supplyCount[adventurer])  
		printf(" PASS on adventurer count does not change\n");
		else 
		printf(" FAIL on adventurer count does not change\n");

		printf(" Actions = %d, expected = %d\n", testGame.numActions, \
		game.numActions + newActions);
		
		if (testGame.numActions == game.numActions + newActions)  
		printf(" PASS on number of actions count is correct\n");
		else 
		printf(" FAIL on number of actions count is not correct\n");

		printf("--------------------------------------------------------------\n");
	}

	printf("All tests completed!\n");

	return 0;
}