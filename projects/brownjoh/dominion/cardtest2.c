#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//testing playAdventurer(struct gameState *state, int currentPlayer)

int testVals(int expected, int actual, char *testName);
int runTest(struct gameState *state, int currentPlayer);

int getTCount(struct gameState *state, int currentPlayer);
int getCCount(struct gameState *state, int currentPlayer);

int main() {

printf("\n***Begin Testing playAdventurer***\n");
//initializing game
int numPlayers = 2;
int seed = 555;
struct gameState Gstate, testGState;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &Gstate);
int loadCards(int card, int numCard, int pos, struct gameState *state);
	// pos = 0 : add to discard
  // pos = 1 : add to deck
  // pos = 2 : add to hand



//precondition, the gamesState and current player is passed to the function
// post condition, the deck is searched for treasure cards.  After two treasure cards are found, these are placed 
// in the players hand and cards drawn looking for treasure cards are discarded.

	//copying gameState
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	loadCards(gold, 3, 1, &testGState);
	runTest(&testGState, whoseTurn(&testGState));

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	loadCards(gold, 3, 1, &testGState);
	loadCards(silver, 3, 1, &testGState);
	loadCards(copper, 3, 2, &testGState);
	runTest(&testGState, whoseTurn(&testGState));

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	loadCards(gold, 1, 1, &testGState);
	loadCards(silver, 1, 1, &testGState);
	loadCards(copper, 1, 1, &testGState);
	loadCards(copper, 3, 2, &testGState);
	loadCards(village, 5, 1, &testGState);
	loadCards(cutpurse, 5, 2, &testGState);
	runTest(&testGState, whoseTurn(&testGState));
	
	


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

