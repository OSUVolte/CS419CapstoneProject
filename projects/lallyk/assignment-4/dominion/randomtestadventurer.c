/********************************************************************
 * Kara Franco
 * randomtestadventurer.c
 * Due Date: May 8, 2016
 * ****************************************************************/

#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TEST 1500

int main(){
	printf("\n------------------------Random Test Adventurer Card-----------------------------\n\n");
	
	printf("Running %d tests of the Adventurer Card\n", MAX_TEST);
	int cards[10] = {adventurer, village, gardens, mine, minion, smithy, embargo, tribute, feast, great_hall};
	
	int i;
	int flag;	
	int numPlayers;
	int player;
	int preHandCount;
	int preDeckCount;
	int randGen;
	int failedCards = 0;
	int failedTreas = 0;
	int failedDecks = 0;

	srand(time(NULL));
	
	struct gameState G;

	
	for (i = 0; i < MAX_TEST; i++){
		// set the random number generator and the number of players to a random number 
		randGen = rand();
		numPlayers = rand() % 3 + 2;
		
		// printf("\nInitialize Game...\n");
	
		initializeGame(numPlayers, cards, randGen, &G);
			// after game is started set the deckCount, handCount and discardCount to a random number	
			player = 0;
			G.deckCount[player] = rand() % MAX_DECK;
			G.discardCount[player] = rand() % MAX_DECK;
			G.handCount[player] = rand() % MAX_HAND;
		
			preHandCount = G.handCount[player];
			preDeckCount = G.deckCount[player];
	
		// use cardEffect to check for function return value
		// printf("\nTesting that Adventurer cardEffect function return value is 0...\n");
		flag = cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
		if(flag == 0){
			// printf("PASS\n");
		}
		
		// adventurer() action should be take cards until you get two treasure cards, put back other cards
		// printf("\nTesting if Adventurer card gave player 2 new treasure cards...\n");
		
		if(G.handCount[player] != preHandCount + 2){
			// printf("FAIL: Player %d did not get 2 new cards\n", player);
			// printf("Current handCount: %d, Previous handCount: %d\n", G.handCount[player], preHandCount);
			failedCards++;
		}
			
		if(G.hand[player][G.handCount[player] - 2] != copper &&
			G.hand[player][G.handCount[player] - 2] != silver &&
			G.hand[player][G.handCount[player] - 2] != gold){
				
			// printf("FAIL: Player %d did not get 2 treasure cards\n", player);
			failedTreas++;   
		}

		// adventurer() action should result in 2 cards missing from the deck 
		// printf("\nTesting if Adventurer card removed 2 cards from the deck...\n");
		if(G.deckCount[player] != preDeckCount - 2){  
			// printf("FAIL\n");
			// printf("Current deckCount: %d, Previous deckCount: %d\n", G.deckCount[player], preDeckCount);
			failedDecks++;
		}
	}
	
	printf("\n--- Adventurer Tests Complete! Number of tests run: %d ---\n", MAX_TEST);
	printf("Adventurer card gave two new cards: Number of tests FAILED %d\n", failedCards);
	printf("Adventurer card gave two treasure cards: Number of tests FAILED %d\n", failedTreas);
	printf("Adventurer card removed two cards from deck: Number of tests FAILED %d\n\n", failedDecks);
	
	return 0;
}
