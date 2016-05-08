#include "dominion.h"
#include "dominion_helpers.h"
#include "math.h" 
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h> 


int main() {
	int newCards = 0;
	int discarded = 0;
	int shuffledCards = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed;
	int numPlayers = 2;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int newActions;
	int newBuys;
	int nextCards;
	struct gameState game, testGame;
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy, council_room};

	int i, j, m;
	printf("\n\n --- Random Test Card: Adventurer --- \n\n");
	//runs 10000 tests.
	for (m = 0; m < 10000; m++) {	
		//random number seed
		seed = rand(); 
		for (j = 0; j < sizeof(struct gameState); j++) {
			((char*)&game)[j] = floor(Random() * 256);
		}
		// initialize a game state and player cards
		initializeGame(numPlayers, kingdomCards, seed, &game);		
		game.handCount[currentPlayer] = floor(Random() * 10);
		game.deckCount[currentPlayer] = floor(Random() * 25);
		game.discardCount[currentPlayer] = floor(Random() * 25);
		

		//Randomly select cards for hand pile
		for (i = 0; i < game.handCount[currentPlayer]; i++) {
			game.hand[currentPlayer][i] = floor(Random() * (treasure_map + 1));
		}

		//Randomly select cards for discard pile
		for (i = 0; i < game.discardCount[currentPlayer]; i++) {
			game.discard[currentPlayer][i] = floor(Random() * (treasure_map + 1));
		}

		//Randomly select cards for deck 
		for (i = 0; i < game.deckCount[currentPlayer]; i++) {
			game.deck[currentPlayer][i] = floor(Random() * (treasure_map + 1));
		}

		// copy the game state to a test case
		memcpy(&testGame, &game, sizeof(struct gameState));

		cardEffect(adventurer, choice1, choice2, choice3, &testGame, handpos, &bonus);

		newCards = 2;
		nextCards = 0;
		newActions = 0;
		newBuys = 0;

		//print and check test results
		printf("--------------------------------------------------------\n");
		printf("\nAdventurer Card Test: \n\n");
		printf(" Hand count = %d, expected = %d\n", testGame.handCount[currentPlayer], \
		game.handCount[currentPlayer] + newCards - discarded);
		if (testGame.handCount[currentPlayer] == game.handCount[currentPlayer] + newCards - discarded) 
		printf(" PASS on handcount does not change on current player\n");    
		else 	
		printf(" FAIL on handcount does not change on current player\n");

		printf(" Deck count = %d, expected = %d\n", testGame.deckCount[currentPlayer], \
		game.deckCount[currentPlayer] - newCards + shuffledCards);
		if (testGame.deckCount[currentPlayer] == game.deckCount[currentPlayer] - newCards + shuffledCards)  
		printf(" PASS on deckcount does not change\n");
		else 
		printf(" FAIL on deckcount does not change\n");

		printf(" Discard count count = %d, expected = %d\n", testGame.discardCount[currentPlayer], \
		game.discardCount[currentPlayer]);
		if (testGame.discardCount[currentPlayer] == game.discardCount[currentPlayer])  
		printf(" PASS on discardcount does not change\n");
		else 
		printf(" FAIL on discardcount does not change\n");

		printf(" Hand count = %d, expected = %d\n", testGame.handCount[nextPlayer], \
		game.handCount[nextPlayer] + nextCards);
		if (testGame.handCount[nextPlayer] == game.handCount[nextPlayer] + nextCards)
		printf(" PASS on handcount does not change on next player\n");    
		else 	
		printf(" FAIL on handcount does not change on next player\n");

		printf("Deck count = %d, expected = %d\n", testGame.deckCount[nextPlayer], \
		game.deckCount[nextPlayer] - nextCards);
		if (testGame.deckCount[nextPlayer] == game.deckCount[nextPlayer] - nextCards)  
		printf(" PASS on deckcount does not change on next player\n");
		else 
		printf(" FAIL on deckcount does not change on next player\n");

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

		printf("--------------------------------------------------------\n");
	}

	printf("All tests completed!\n");

	return 0;
}