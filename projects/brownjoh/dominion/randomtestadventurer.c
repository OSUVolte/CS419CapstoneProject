#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

//testing playAdventurer(struct gameState *state, int currentPlayer)

int testVals(int expected, int actual, char *testName);
int runTest(struct gameState *state, int currentPlayer);

int getTCount(struct gameState *state, int currentPlayer);
int getCCount(struct gameState *state, int currentPlayer);
int loadCards(int card, int numCard, int pos, struct gameState *state);


int main() {

int NUM_ROUNDS = 3; // number of turns tested for each game
int NUM_TESTS = 2000; // number of games played
int i = 0;
int j = 0;
int l = 0;
int seed = rand();
int extraCards = 0;
int whichCard = 0;
struct gameState Gstate, testGState;



printf("\n***Begin Testing playAdventurer***\n");
//initializing game
srand(time(NULL));
int numPlayers = (rand() %(MAX_PLAYERS -1) +2);
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &Gstate);
int randomizer = 0;
int MAX_DRAW = 5;


for(i = 0 ; i < NUM_TESTS; i++){

		memcpy(&testGState, &Gstate, sizeof(struct gameState));	
		numPlayers = testGState.numPlayers = (rand() %(MAX_PLAYERS -1) +2);

// pos = 0 : add to discard
  // pos = 1 : add to deck
  // pos = 2 : add to hand
			


		for(j = 0 ; j < NUM_ROUNDS; j++){

			testGState.whoseTurn = rand() % numPlayers;
			randomizer = (rand() % 3) +1;
			switch(randomizer){

			case 1:

			extraCards = rand() % 4;
			whichCard = k[rand() % 10];
			loadCards(silver, ((rand() % MAX_DRAW) + 2), 1, &testGState);
			for(l = 0; l < extraCards; l++)
				loadCards(whichCard, extraCards, 1, &testGState);
			runTest(&testGState, whoseTurn(&testGState));

			break;

			case 2:

			extraCards = rand() % 4;
			whichCard = k[rand() % 10];
			for(l = 0; l < extraCards; l++)
				loadCards(whichCard, extraCards, 1, &testGState);
			loadCards(copper, ((rand() % MAX_DRAW) + 2), 1, &testGState);
			runTest(&testGState, whoseTurn(&testGState));

			break;

			case 3:


			extraCards = rand() % 4;
			whichCard = k[rand() % 10];
			loadCards(copper, ((rand() % MAX_DRAW) + 2), 1, &testGState);
			for(l = 0; l < extraCards; l++)
				loadCards(whichCard, extraCards, 1, &testGState);
			runTest(&testGState, whoseTurn(&testGState));

			break;


		}



		}// end inner for

	// pos = 0 : add to discard
  // pos = 1 : add to deck
  // pos = 2 : add to hand



//precondition, the gamesState and current player is passed to the function
// post condition, the deck is searched for treasure cards.  After two treasure cards are found, these are placed 
// in the players hand and cards drawn looking for treasure cards are discarded.

	
	
	
	} // end outer for

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

int runTest(struct gameState *state, int currentPlayer){

	int startingTreasure = 0; // starting treasure in hand
	int endingTreasure = 0;
	int startingCard = 0;    //starting total cards in players control
	int endingCard = 0;

	startingTreasure = getTCount(state, currentPlayer);
	startingCard = getCCount(state, currentPlayer);
	playAdventurer(state, currentPlayer);
	endingTreasure = getTCount(state, currentPlayer);
	endingCard = getCCount(state, currentPlayer);

	testVals(startingTreasure + 2, endingTreasure, "Treasures in hand");
	testVals(startingCard, endingCard, "Total Cards Controlled");

	//testVals(1, 2, "badstuff");
	//testVals(1, 1, "goodstuff");

		return 0;

}

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


int getTCount(struct gameState *state, int currentPlayer){

	int count = 0;
	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++)
    {
      if (state->hand[currentPlayer][i] == gold) count++;
      if (state->hand[currentPlayer][i] == silver) count++;
      if (state->hand[currentPlayer][i] == copper) count++;
    }



	return count;
}

int getCCount(struct gameState *state, int currentPlayer){

	int count = 0;
	count += state->handCount[currentPlayer];
	count += state->deckCount[currentPlayer];
	count += state->discardCount[currentPlayer];


	return count;
}

