#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//testing updateCoins function
//int updateCoins(int player, struct gameState *state, int bonus)

int testVals(int expected, int actual, char *testName);
int runTest(int player, struct gameState *state, int bonus);
int loadCoins(int c, int s, int g, struct gameState *state);

int main() {

//initializing game
int numPlayers = 2;
int seed = 555;
struct gameState Gstate, testGState;
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
initializeGame(numPlayers, k, seed, &Gstate);




//precondition, the current player, gamestate and bonus coins are passed to the updateCoins function
//post condition, the state->coins value updated to the correct amount based on hand and bonus

	//copying gameState
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	loadCoins(0, 0, 0, &testGState);
	runTest(whoseTurn(&testGState), &testGState, 0);
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	loadCoins(100, 100, 100, &testGState);
	runTest(whoseTurn(&testGState), &testGState, 1);

	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	loadCoins(1, 1, 1, &testGState);
	runTest(whoseTurn(&testGState), &testGState, 7000);
	
	memcpy(&testGState, &Gstate, sizeof(struct gameState));
	loadCoins(3, 75, 12, &testGState);
	runTest(whoseTurn(&testGState), &testGState, 2);



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

int runTest(int player, struct gameState *state, int bonus){


	// bonus is additional coins added to current total
		
		int expectedCoins = 0;
		int i = 0;

	 for (i = 0; i < state->handCount[player]; i++)
	    {
	      if (state->hand[player][i] == copper)
		{
		  expectedCoins += 1;
		}
	      else if (state->hand[player][i] == silver)
		{
		  expectedCoins += 2;
		}
	      else if (state->hand[player][i] == gold)
		{
		  expectedCoins += 3;
		}	
	    }	

	    expectedCoins += bonus;
	    updateCoins(player, state, bonus);
	    testVals(expectedCoins, state->coins, "value of coins");

	    return 0;

}

int loadCoins(int c, int s, int g, struct gameState *state){
	int i = 0;


	for(i = 0; i < c; i++)
		gainCard(copper, state, 2, whoseTurn(state));


	for(i = 0; i < s; i++)
		gainCard(silver, state, 2, whoseTurn(state));


	for(i = 0; i < g; i++)
		gainCard(gold, state, 2, whoseTurn(state));

	return 0;


}