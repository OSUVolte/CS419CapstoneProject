#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//testing gainCard function

int testVals(int expected, int actual, char *testName);
int runTest(int supplyPos, struct gameState *state, int toFlag, int player);

int main() {

//initializing game
int numPlayers = 2;
int seed = 555;
struct gameState Gstate, testGState;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &Gstate);



//precondition, the card type, game state, position the card is going to hand (discard deck or hand)  and player number passed in.
// post condition, the chosen card should be added to the requested position for the selected player

//int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	//copying gameState
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	runTest(1 , &testGState, 0, whoseTurn(&testGState));
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	runTest(6 , &testGState, 5, whoseTurn(&testGState));

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	runTest(8 , &testGState, 1, whoseTurn(&testGState));
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	runTest(7 , &testGState, 2, whoseTurn(&testGState));

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	runTest(1 , &testGState, 3, whoseTurn(&testGState));
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	runTest(5 , &testGState, 0, whoseTurn(&testGState));


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


}

int runTest(int supplyPos, struct gameState *state, int toFlag, int player){


	// toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand
	switch(toFlag){
			int expectedCount = -1;

		case 0 :
		expectedCount = (state->discardCount[player]) + 1;
		gainCard(supplyPos, state, toFlag, player);
		testVals(expectedCount, state->discardCount[player], "discard size");
		break;

		case 1 :
		expectedCount = (state->deckCount[player]) + 1;
		gainCard(supplyPos, state, toFlag, player);
		testVals(expectedCount, state->deckCount[player], "deck size");

		break;

		case 2 :
		expectedCount = (state->handCount[player]) + 1;
		gainCard(supplyPos, state, toFlag, player);
		testVals(expectedCount, state->handCount[player], "hand size");

		break;


		default : //should be no change
		expectedCount = (state->handCount[player]);
		gainCard(supplyPos, state, toFlag, player);
		testVals(expectedCount, state->handCount[player], "hand size");

	}


	//testVals(1, 2, "badstuff");
	//testVals(1, 1, "goodstuff");

}