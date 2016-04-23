#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//testing fullDeckCount(int player, int card, struct gameState *state)

int testVals(int expected, int actual, char *testName);
int runTest(int player, int card, struct gameState *state, int cardsExpected);
int loadCards(int card, int numCard, int pos, struct gameState *state);
	// pos = 0 : add to discard
  // pos = 1 : add to deck
  // pos = 2 : add to hand

int main() {

//initializing game
int numPlayers = 2;
int seed = 555;
struct gameState Gstate, testGState;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &Gstate);



//precondition, current player, card test value and game state are passed to the function
// postcondition, the function returns a value equal to the total cards held by player in deck, hand and discard

	//copying gameState
	int startingCards = 0;
	int cardsAdded = 0;
	int targetAdded = 0;
	int targetCard;


	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	targetCard = minion;
	cardsAdded = 0;
	targetAdded = 0;

	targetAdded = loadCards(targetCard, 5,  0, &testGState);
	cardsAdded += targetAdded;
	runTest(whoseTurn(&testGState), targetCard, &testGState, (startingCards + cardsAdded));

	

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	targetCard = sea_hag;
	cardsAdded = 0;
	targetAdded = 0;

	targetAdded = loadCards(targetCard, 1,  1, &testGState);
	cardsAdded += targetAdded;
	runTest(whoseTurn(&testGState), targetCard, &testGState, (startingCards + cardsAdded));


	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	targetCard = smithy;
	cardsAdded = 0;
	targetAdded = 0;

	targetAdded = loadCards(targetCard, 10,  2, &testGState);
	cardsAdded += targetAdded;
	loadCards(tribute, 55,  2, &testGState);
	runTest(whoseTurn(&testGState), targetCard, &testGState, (startingCards + cardsAdded));


	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	targetCard = village;
	cardsAdded = 0;
	targetAdded = 0;

	targetAdded = loadCards(targetCard, 0,  2, &testGState);
	cardsAdded += targetAdded;
	loadCards(embargo, 7,  3, &testGState);
	runTest(whoseTurn(&testGState), targetCard, &testGState, (startingCards + cardsAdded));



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

int runTest(int player, int card, struct gameState *state, int cardsExpected){
		int cardsReturned;
		cardsReturned = fullDeckCount(player, card, state);
		testVals(cardsExpected, cardsReturned, "Target Card Count");


		return 0;
	

	}


	//testVals(1, 2, "badstuff");
	//testVals(1, 1, "goodstuff");

int loadCards(int card, int numCard, int pos, struct gameState *state){
	// pos = 0 : add to discard
  // pos = 1 : add to deck
  // pos = 2 : add to hand
	int added = 0;

	int i = 0;
	for(i = 0; i < numCard; i++){
		gainCard(card, state, pos, whoseTurn(state));
		added++;

	}


	return added;


}