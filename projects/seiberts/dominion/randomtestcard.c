/******************************************************
Name: Shawn Seibert
File: randomtestcard.c
Date: 4/27/2016
Purpose: This program runs a series of random tests on
the smithy card.
******************************************************/
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 300

//This randomly tests Adventurer

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};

	int i, gameInit, cardEff, players, player, handCount, deckCount, discardCount, seed, numAction;
	int testsFailed = 0;
	int testsPassed = 0;
	int oldCoinCount = 0, newCoinCount = 0;
	struct gameState gs;
	printf("***Runnings Random Smithy Test***\n");

	srand(time(NULL));
	for (i = 0; i < MAX_TESTS; i++) {

		printf("<------------- Test %d ------------------>*\n", i);
		players = 2 + (rand() % 3); //Set players between 2 and 4
		printf("Current player: %d\n", players);

		player = rand() % players;

		seed = rand();		//pick random seed
		printf("Seed: %d\n", seed);
		gameInit = initializeGame(players, k, seed, &gs);	//initialize gsamestate
		assert(gameInit == 0);
		gs.whoseTurn = player;

		//Initiate valid state variables
		gs.deckCount[player] = 10 + (rand() % 400); //Pick random deck size out of MAX DECK size
		deckCount = gs.deckCount[player];
		gs.discardCount[player] = rand() % (deckCount);
		gs.handCount[player] = rand() % MAX_HAND;
		//Minus one to handCount to account for the smithy card about to be played
		handCount = gs.handCount[player]-1;
		printf("Current Hand Count: %d\n", handCount);



		cardEff = cardEffect(smithy, 0, 0, 0, &gs, 0, NULL);
		assert(cardEff == 0);
		
		if( (handCount + 3) != gs.handCount[player]){
			testsFailed++;
			handCount = gs.handCount[player];
			printf("After Hand Count is: %d\n", handCount);
			printf("TEST FAILED: Two cards were not discarded.\n");
			
			
		}
		else{
			handCount = gs.handCount[player];
			printf("After Hand Count is: %d\n", handCount);
			printf("TEST PASSED: Player discarded two cards.\n");
			testsPassed++;
		}
		printf("<-------------Test %d Completed. -------------->\n", i);
		printf("\n\n\n");
	}


	printf("Final Results.\n");
	printf("Number of passed tests: %d\n", testsPassed);
	printf("Number of failed tests: %d\n", testsFailed);
}

/*
int smithyCard(int handPos, int currentPlayer, struct gameState *state)
{
	int i = 0;
      //+3 Cards
      for (i = 0; i <= 3; i++) //Use i <= 3
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
		
}

*/