//cardtest4.c
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"

int main() {
  	int seed = 1000;
    	int numPlayers = 2;
    	int thisPlayer = 0;
   	int currDeckCount, currHandCount, currDiscardCount, currActions;
   	//int bonus = 0;
    	int handPos = 0;
    	//int choice1 = 0;
	//int choice2 = 0;
	//int choice3 = 0;
	struct gameState G, testG;
	
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("\n\n\n\n----------------- Testing Card: %s ----------------\n", TESTCARD);
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("---------------TEST 1: CHECKING DRAW CARD FUNCTION\n-----------");
	
	//get starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	currDeckCount = testG.deckCount[thisPlayer];
	currHandCount = testG.handCount[thisPlayer];
	currDiscardCount = testG.discardCount[thisPlayer];
	
	//currCard = testG.deck[player][currDeckCount - 1];
	printf("Deck Count Before: %d\n", testG.deckCount[thisPlayer]);
	printf("Current Hand Before: %d\n", testG.handCount[thisPlayer]);
	printf("Discard Count Before: %d\n", testG.discardCount[thisPlayer]);
	//run card function
	greatHallCard(handPos, thisPlayer, &testG);
	//check deck count
	printf("Deck Count After: %d\n", testG.deckCount[thisPlayer]);
	if ((currDeckCount - 1) == testG.deckCount[thisPlayer]){
		printf("DECK COUNT DECREASED BY 1: SUCCESS\n");
	}
	else if (currDeckCount == testG.deckCount[thisPlayer])
	{
		printf("DECK COUNT STAYED THE SAME: FAILURE\n");
	}
	else
		printf("DECK COUNT CHANGED INCORRECTLY: FAILURE\n");

	//check hand count
	printf("Current Hand After: %d\n", testG.handCount[thisPlayer]);
	if ((currHandCount + 1) == testG.handCount[thisPlayer]){
		printf("HAND COUNT INCREASED BY 1: SUCCESS\n");
	}
	else if (currHandCount == testG.handCount[thisPlayer])
	{
		printf("HAND COUNT DIDN'T CHANGE: FAILURE\n");
	}
	else
		printf("HAND COUNT CHANGE INCORRECT: FAILURE\n");
	
	//check discard count
	printf("Discard Count After: %d\n", testG.discardCount[thisPlayer]);
	if ((currDiscardCount + 1) == testG.discardCount[thisPlayer]){
		printf("DISCARD COUNT INCREASED BY 1: SUCCESS\n");	
	}
	else
		printf("DISCARD COUNT INCORRECT: FAILURE\n");
	
	//check action totals
	printf("---------------TEST 2: CHECKING ACTIONS TOTAL\n-----------");
	//get starting game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//store actions
	currActions = testG.numActions;
	printf("Current Actions Before: %d\n", testG.numActions);
	//run function
	greatHallCard(handPos, thisPlayer, &testG);
	//check effects
	printf("Current Actions After: %d\n", testG.numActions);
	if ((currActions + 1) == testG.numActions){
		printf("ACTION COUNT INCREASED BY 1: SUCCESS\n");
	}
	else if (currActions == testG.numActions)
	{
		printf("ACTION COUNT STAYED THE SAME: FAILURE\n");
	}
	else
		printf("ACTION COUNT CHANGED INCORRECTLY: FAILURE\n");
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n\n\n", TESTCARD);
return 0;
}
