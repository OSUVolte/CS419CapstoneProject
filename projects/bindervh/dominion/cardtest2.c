#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************
Unit test for smithy card
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

    printf("Testing smithy card \n");

    //set up players
    p1 = 0;
    p2 = 1;

    //set up game states
    initializeGame(numPlayers, k, randomSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));

    testGame.whoseTurn = p1;    //set current player to player 1
    result = cardEffect(smithy, 0, 0, 0, &testGame, 0, 0);

    //test if hand count +=2 (three cards added, smithy card discarded)
    printf("Test: Three cards added to hand\n");
    if(testGame.handCount[p1] == game.handCount[p1]+2){
        printf("PASSED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]+2);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]+2);
    }


	return 0;
}