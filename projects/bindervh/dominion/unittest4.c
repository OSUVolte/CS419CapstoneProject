#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************
Unit test for playCard function
***************************************/

int main(int argc, char** argv){
	int p1, p2;		//players 1 and 2
	int numPlayers = 2;
	struct gameState game;		//starting game state
	struct gameState testGame;		//testing game state
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int result;		//test result
    int randomSeed = 5;

    printf("Testing playCard \n");

    //set up players
    p1 = 0;
    p2 = 1;

    //set up game states
    initializeGame(numPlayers, k, randomSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));

    //Test if playCard not allowed when numActions < 1
    testGame.numActions = 0;
    result = playCard(0, 0, 0, 0, &testGame);
    if(-1 == result){
        printf("PASSED.  Returned %d    Expected %d\n", result, -1);
    }else{
        printf("FAILED.  Returned %d    Expected %d\n", result, -1);
    }

    //if actions available, test if numActions decremented
    memcpy(&testGame, &game, sizeof(struct gameState)); //reset game state
    result = playCard(smithy, 0, 0, 0, &testGame);
    if(testGame.numActions == game.numActions-1){
        printf("PASSED.  Returned %d    Expected %d\n", testGame.numActions, game.numActions-1);
    }else{
        printf("FAILED.  Returned %d    Expected %d\n", testGame.numActions, game.numActions-1);
    }


	return 0;
}