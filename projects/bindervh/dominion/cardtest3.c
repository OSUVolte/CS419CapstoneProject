#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************
Unit test for great hall card
***************************************/

int main(int argc, char** argv){
	int p1, p2;		//players 1 and 2
	int numPlayers = 2;
	struct gameState game;		//starting game state
	struct gameState testGame;		//testing game state
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           great_hall, tribute, smithy};
    int result;		//test result
    int randomSeed = 5;

    printf("Testing great hall card \n");

    //set up players
    p1 = 0;
    p2 = 1;

    //set up game states
    initializeGame(numPlayers, k, randomSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));

    testGame.whoseTurn = p1;    //set current player to player 1
    result = cardEffect(great_hall, 0, 0, 0, &testGame, 0, 0);

    //test if hand count stays same (+1 card, discard great_hall card)
    printf("Test: One card added to hand\n");
    if(testGame.handCount[p1] == game.handCount[p1]){
        printf("PASSED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]);
    }
    //test if +1 action
    printf("Test: One action added\n");
    if(testGame.numActions == game.numActions+1){
        printf("PASSED. Returned %d   Expected %d\n", testGame.numActions, game.numActions+1);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.numActions, game.numActions+1);
    }



	return 0;
}