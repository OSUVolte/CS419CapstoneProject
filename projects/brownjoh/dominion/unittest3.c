#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//testing isGameOver
//int isGameOver(struct gameState *state)

int testVals(int expected, int actual, char *testName);
int runTest(struct gameState *state);

int main() {

//initializing game
int numPlayers = 2;
int seed = 555;
struct gameState Gstate, testGState;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &Gstate);



//precondition, current games state passed in to the function
//post, true false value returned indicating if the game is finished.

//int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
	//copying gameState
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	runTest(&testGState);
	

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	testGState.supplyCount[province] = 0;
	runTest(&testGState);

	 memcpy(&testGState, &Gstate, sizeof(struct gameState));
	 testGState.supplyCount[province] = 0;
	 runTest(&testGState);
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	int i;
	for(i = 0; i < 15; i++)
	 	gainCard(i, &testGState, 1, whoseTurn(&testGState));
	 runTest(&testGState);

	 memcpy(&testGState, &Gstate, sizeof(struct gameState));
	 for (i = 0; i < minion; i++)
			      testGState.supplyCount[i] = 0;
	 runTest(&testGState);


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

int runTest(struct gameState *state){
		int expectedState = 0;
		int i = 0;
		int j = 0;

		 if (state->supplyCount[province] == 0)
		 	expectedState = 1;


		 
  		for (i = 0; i < 25; i++)
			    {
			      if (state->supplyCount[i] == 0)
						{
						  j++;
						}
			    }
			  if ( j >= 3)
			    {
			      expectedState = 1;
			    }
   
		
		testVals(expectedState, isGameOver(state), "Game Over Status");

	}


	//testVals(1, 2, "badstuff");
	//testVals(1, 1, "goodstuff");

