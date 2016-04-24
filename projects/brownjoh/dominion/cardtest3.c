#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//testing playVillage(struct gameState *state, int handPos, int currentPlayer)

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



//precondition, game state, card position and current player is passed to the function
// post condition, one additional card is added to the hand, two additional actions added

//int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)

	printf("\n***Begin Testing playVillage***\n");

	//copying gameState
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	gainCard(village, &testGState, 2, whoseTurn(&testGState));
	runTest(&testGState, 0, whoseTurn(&testGState));

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	gainCard(tribute, &testGState, 2, whoseTurn(&testGState));
	gainCard(village, &testGState, 2, whoseTurn(&testGState));
	runTest(&testGState, 1, whoseTurn(&testGState));

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	for(i = 0; i < 5; i++)
		gainCard(smithy, &testGState, 2, whoseTurn(&testGState));
	for(i = 0; i < 3; i++)
	gainCard(village, &testGState, 2, whoseTurn(&testGState));
	runTest(&testGState, 06, whoseTurn(&testGState));
	



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
		//precondition, game state, card position and current player is passed to the function
		// post condition, one additional card is added to the hand, two additional actions added

	// toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand
	int startingHand;
	int endingHand;
	int startingAction;
	int endingAction;

	startingAction = state->numActions;
	startingHand = state->handCount[currentPlayer];
	playVillage(state, handPos, currentPlayer);
	endingAction = state->numActions;
	endingHand = state->handCount[currentPlayer];
	testVals(startingAction + 2, endingAction, "Number of Actions");
	testVals(startingHand + 1, endingHand, "Number in Hand");


	//testVals(1, 2, "badstuff");
	//testVals(1, 1, "goodstuff");

	return 0;

}