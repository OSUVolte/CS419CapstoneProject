//discardCard function
//unittest4.c
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define FUNCTION "discardCard"

void runDiscard(int handPos, int thisPlayer, struct gameState *state, int trashFlag);

int main() {
	int trashFlag = 0;
	int handPos = 0;
	int currCard, lastCard;
	int currHandCount;
	int numPlayedBefore, numPlayedAfter;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int k[10] = {curse, estate, village, remodel, 
		council_room, adventurer, province, smithy, steward, tribute};
	struct gameState G, testG;
	//printf("--------------------Start Game----------------------------\n");
	initializeGame(numPlayers, k, seed, &G);
	printf("\n\n\n\n----------------- Testing Function: %s ----------------\n", FUNCTION);
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("\n--------------------TEST 1: TRASH FLAG TEST------------------------\n");
	//check if card is in played cards?
	//revert to saved game state
	memcpy(&G, &testG, sizeof(struct gameState));
	currCard = testG.hand[thisPlayer][handPos];
	numPlayedBefore = testG.playedCardCount;
	trashFlag = 0;
	handPos = 0;
	//run function
	discardCard(handPos, thisPlayer, &testG, trashFlag);
	//check if played card count has increased by 1
	if (testG.playedCardCount == (numPlayedBefore + 1))
		printf("TrashFlag not set, Card Added to played pile: SUCCESS\n");
	else
		printf("Card not added to played pile: FAILURE\n");
	printf("\n--------------------TEST 2: TEST HAND COUNT------------------------\n");
	//revert to saved game state
	memcpy(&G, &testG, sizeof(struct gameState));
	trashFlag = 1;
	handPos = 0;
	currHandCount = testG.handCount[thisPlayer];
	printf("Current Hand Count: %d\n", testG.handCount[thisPlayer]);
	currCard = testG.hand[thisPlayer][handPos];
	//run function
	discardCard(handPos, thisPlayer, &testG, trashFlag);
	//get new hand count
	printf("NEW Current Hand Count: %d\n", testG.handCount[thisPlayer]);
	if (testG.handCount[thisPlayer] == (currHandCount - 1))
		printf("Hand Count Decreased: SUCCESS\n");
	else if (testG.handCount[thisPlayer] == currHandCount)
		printf("Hand Count Not Decreased: FAILURE\n");
	else 
		printf("Hand Count Changed but not correct: FAILURE\n");
	printf("\n------------TEST 3: Checking Behavor if Not Last Card-----------\n");
	//revert to saved game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//set trashflag
	trashFlag = 1;
	handPos = 0;
	//save current hand count
	currHandCount = testG.handCount[thisPlayer];
	lastCard = testG.hand[thisPlayer][(testG.handCount[thisPlayer] - 1)];
	currCard = testG.hand[thisPlayer][handPos];
	printf("Current Hand Count: %d\n", testG.handCount[thisPlayer]);
	printf("Running Function\n");
	//run function
	discardCard(handPos, thisPlayer, &testG, trashFlag);
	printf("NEW Current Hand Count: %d\n", testG.handCount[thisPlayer]);
	//check if hand count is correct
	if (testG.handCount[thisPlayer] == (currHandCount - 1))
		printf("Hand Count Decreased: SUCCESS\n");
	else if (testG.handCount[thisPlayer] == currHandCount)
		printf("Hand Count Not Decreased: FAILURE\n");
	else 
		printf("Hand Count Changed but not correct: FAILURE\n");
	//check if card swap occured
	if (testG.hand[thisPlayer][handPos] == lastCard)
		printf("Current Card Replaced with Last Card: SUCCESS\n");
	else if (testG.hand[thisPlayer][handPos] == currCard)
		printf("Current Card not Replaced: FAILURE\n");
	else
		printf("Current Card Replaced with wrong card: FAILURE");
	printf("-------------------TEST 4: CHECK BEHAVIOR IF LAST CARD IN HAND-----------------\n");
	//revert to saved game state
	memcpy(&G, &testG, sizeof(struct gameState));
	//set trashflag
	trashFlag = 1;
	//set handPos
	handPos = (testG.handCount[thisPlayer] - 1); 
	//run function and output result
	runDiscard(handPos, thisPlayer, &testG, trashFlag);
	printf("--------------------TEST 5: CHECK BEHAVIOR IF ONLY ONE CARD LEFT-----------------\n");
	//revert to saved game state
	memcpy(&G, &testG, sizeof(struct gameState));
	handPos = 0;
	trashFlag = 1;
	//run until last card left
	while(testG.handCount[thisPlayer] > 1)
	{
		discardCard(handPos, thisPlayer, &testG, trashFlag);
	}
	//run final function and output result
	runDiscard(handPos, thisPlayer, &testG, trashFlag);
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", FUNCTION);
	return 0;
}

void runDiscard(int handPos, int thisPlayer, struct gameState *testG, int trashFlag){
	int currHandCount = testG->handCount[thisPlayer];
	int lastCard = testG->hand[thisPlayer][(testG->handCount[thisPlayer] - 1)];
	int currCard = testG->hand[thisPlayer][handPos];
	printf("Current Hand Count: %d\n", testG->handCount[thisPlayer]);
	printf("Running Function\n");
	//run function
	discardCard(handPos, thisPlayer, testG, trashFlag);
	//output results
	printf("Current Hand Count: %d\n", testG->handCount[thisPlayer]);
	//check if hand count is correct
	if (testG->handCount[thisPlayer] == (currHandCount - 1))
		printf("Hand Count Decreased: SUCCESS\n");
	else if (testG->handCount[thisPlayer] == currHandCount)
		printf("Hand Count Not Decreased: FAILURE\n");
	else 
		printf("Hand Count Changed but not correct: FAILURE\n");
}
