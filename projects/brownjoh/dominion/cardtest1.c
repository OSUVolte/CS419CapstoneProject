#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//testing playSmithy(struct gameState *state, int handPos, int currentPlayer)

int testVals(int expected, int actual, char *testName);
int runTest(struct gameState *state, int handPos, int currentPlayer);

int main() {

//initializing game
int numPlayers = 2;
int seed = 555;
struct gameState Gstate, testGState;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &Gstate);
int i = 0;



//precondition, game state, card position and current player are passed to function
//post condition, three additional cards drawn, smithy is discarded

	
	printf("\n***Begin Testing playSmithy***\n");
	//copying gameState
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	gainCard(smithy, &testGState, 2, whoseTurn(&testGState));
	runTest(&testGState, 0, whoseTurn(&testGState));
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	gainCard(village, &testGState, 2, whoseTurn(&testGState));
	gainCard(smithy, &testGState, 2, whoseTurn(&testGState));
	runTest(&testGState, 1, whoseTurn(&testGState));

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	for(i = 0; i < 5; i++)
		gainCard(mine, &testGState, 2, whoseTurn(&testGState));
	gainCard(smithy, &testGState, 2, whoseTurn(&testGState));
	for(i = 0; i < 4; i++)
		gainCard(council_room, &testGState, 2, whoseTurn(&testGState));
	runTest(&testGState, 5, whoseTurn(&testGState));




	return 0;
}


int testVals(int expected, int actual, char *testName){

	printf("Testing %s\n", testName);

	printf("Expected %i\n", expected);
	printf("Actual %i\n", actual);


	if(expected == actual)
		printf("Passed!\n");
	else
		printf("Failed!\n");

	return 0;
}

int runTest(struct gameState *state, int handPos, int currentPlayer){

	int startingHand;
	int startingSmithy;
	int endingHand;
	int endingSmithy;

	startingHand = state->handCount[currentPlayer];
	startingSmithy = fullDeckCount(currentPlayer, smithy, state);
	playSmithy(state, handPos, currentPlayer);
	endingHand = state->handCount[currentPlayer];
	endingSmithy = fullDeckCount(currentPlayer, smithy, state);
	testVals(startingHand + 2, endingHand, "Testing HandSize");
	testVals(startingSmithy + 1, endingSmithy, "Testing Smithy Discarded");


	// toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand
	



	return 0;

}