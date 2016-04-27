/********************************************************************
 * Kara Franco
 * randomtestcard.c
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
	printf("\n------------------------Random Test Village Card-----------------------------\n\n");
	
	printf("Running %d tests of the Village Card\n", MAX_TEST);
	int cards[10] = {adventurer, village, gardens, mine, minion, smithy, embargo, tribute, feast, great_hall};
	
	int i;
	int flag;	
	int numPlayers;
	int player;
	int preHandCount;
	int preDiscCount;
	int preActionCount;
	int randGen;
	int failedCards = 0;
	int failedActions = 0;
	int failedDiscs = 0;

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
			preDiscCount = G.discardCount[player];
			preActionCount = G.numActions;

		// use cardEffect to check for function return value
		// printf("\nTesting that Village cardEffect function return value is 0...\n");
		flag = cardEffect(village, 0, 0, 0, &G, 0, 0);
		if(flag == 0){
			// printf("PASS\n");
		}
		
		// village card action should be take one card and get two actions
		// printf("\nTesting if Village card gave player a new card...\n");
		
		if(G.handCount[player] != preHandCount){
			// printf("FAIL: Player %d did not keep the right amount of cards\n", player);
			// printf("Current handCount: %d, Previous handCount: %d\n", G.handCount[player], preHandCount);
			failedCards++;
		}
			
		// village card should give two actions
		// printf("\nTesting if Village card gave player a two actions...\n");

		if(G.numActions != preActionCount + 2){
			// printf("FAIL: Player did not get two additional actions");
			failedActions++;
		}

		// village action should result in no change of discardCount  
		// printf("\nTesting if Village card did not change the deck count...\n");
		if(G.discardCount[player] != preDiscCount){  
			// printf("FAIL\n");
			failedDiscs++;
		}
	}
	
	printf("\n--- Village Tests Complete! Number of tests run: %d ---\n", MAX_TEST);
	printf("Village card gave one card: Number of tests FAILED %d\n", failedCards);
	printf("Village card gave two actions: Number of tests FAILED %d\n", failedActions);
	printf("Village card did not change the discardCount: Number of tests FAILED %d\n\n", failedDiscs);
	
	return 0;
}
