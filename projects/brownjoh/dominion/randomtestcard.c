#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

//testing playSmithy(struct gameState *state, int handPos, int currentPlayer)

int testVals(int expected, int actual, char *testName);
int runTest(struct gameState *state, int handPos, int currentPlayer);
int topCard(struct gameState *state, int playerTurn);

int main() {

srand(time(NULL));

//initializing game
struct gameState Gstate, testGState;
int i = 0; // iterator
int j = 0;// iterator
int NUM_ROUNDS = 3; // number of turns tested for each game
int NUM_TESTS = 2000; // number of games played
int numPlayers;
int seed;
int randomizer;
int smithPos;
int playerTurn;
int passed = 0;
int failed = 0;
int extraCards = 0;
int whichCard = 0;
int l = 0; // iterator

printf("\n***Begin Testing playSmithy***\n");

	seed = rand();
	numPlayers = (rand() %(MAX_PLAYERS -1) +2);
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(numPlayers, k, seed, &Gstate);



for(i = 0 ; i < NUM_TESTS; i++){

		memcpy(&testGState, &Gstate, sizeof(struct gameState));	
		testGState.numPlayers = (rand() %(MAX_PLAYERS -1) +2);
			


		for(j = 0 ; j < NUM_ROUNDS; j++){

			extraCards = 0;
			whichCard = 0;
			randomizer = 1;
			smithPos = 1;
			playerTurn = testGState.whoseTurn = rand() % numPlayers;


		//MAX_HAND
		// MAX_PLAYERS


		//precondition, game state, card position and current player are passed to function
		//post condition, three additional cards drawn, smithy is discarded

			
			randomizer = (rand() % 3) +1;
			//copying gameState
			switch(randomizer){

			case 1:

				gainCard(smithy, &testGState, 2, playerTurn);
				smithPos = topCard(&testGState, playerTurn);
				if (runTest(&testGState, smithPos, playerTurn) == 0)
					passed ++;

				else
					failed ++;


			break;

			case 2:

				extraCards = rand() % 4;
				whichCard = k[rand() % 10];
				gainCard(smithy, &testGState, 2, playerTurn);
				for(l = 0; l < extraCards; l++)
					gainCard(whichCard, &testGState, 2, playerTurn);
				smithPos = ((topCard(&testGState, playerTurn)) - extraCards);
				if (runTest(&testGState, smithPos, playerTurn) == 0)
					passed ++;

				else
					failed ++;

			break;

			case 3:

				extraCards = rand() % 4;
				whichCard = k[rand() % 10];
				for(l = 0; l < extraCards; l++)
					gainCard(whichCard, &testGState, 2, playerTurn);

				gainCard(smithy, &testGState, 2, playerTurn);
				smithPos = topCard(&testGState, playerTurn);
				if (runTest(&testGState, smithPos, playerTurn) == 0)
					passed ++;

				else
					failed ++;

			break;

				}



			} //end inner for loop


			

		}//end outer for

		// printf("\n***Passed Tests: %i\n", passed);
		// printf("\n***Failed Tests: %i\n", failed);

		return 0;
	
}


int testVals(int expected, int actual, char *testName){

	printf("Testing %s\n", testName);

	printf("Expected %i\n", expected);
	printf("Actual %i\n", actual);


	if(expected == actual){
		printf("Passed!\n");
		return 0;
	}

	else
		printf("Failed!\n");

	return -1;
}

int runTest(struct gameState *state, int handPos, int currentPlayer){

	int startingHand;
	int startingSmithy;
	int endingHand;
	int endingSmithy;
	int testSuccess = 0;

	startingHand = state->handCount[currentPlayer];
	startingSmithy = fullDeckCount(currentPlayer, smithy, state);
	playSmithy(state, handPos, currentPlayer);
	endingHand = state->handCount[currentPlayer];
	endingSmithy = fullDeckCount(currentPlayer, smithy, state);

	if(testVals(startingHand + 2, endingHand, "Testing HandSize") == -1);
		testSuccess = -1;

	if(testVals(startingSmithy + 1, endingSmithy, "Testing Smithy Discarded")== -1)
		testSuccess = -1;


	// toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand
	



	return testSuccess;

}

int topCard(struct gameState *state, int playerTurn){


	int	cardTop = state->handCount[playerTurn]-1;

	return cardTop;

}