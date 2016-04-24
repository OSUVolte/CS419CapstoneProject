#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************
Unit test for discardCard function
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

    printf("Testing discardCard \n");

    //set up players
    p1 = 0;
    p2 = 1;

    //set up game states
    initializeGame(numPlayers, k, randomSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));

   //test if trashFlag not set, card added to played pile
    printf("Test: Card added to played pile\n");
    result = discardCard(0, p1, &testGame, 0);  //trashFlag not set
    if(testGame.playedCardCount == game.playedCardCount+1){
        printf("PASSED.  Returned %d    Expected %d\n", testGame.playedCardCount, game.playedCardCount+1);
    } else{
        printf("FAILED.  Returned %d    Expected %d\n", testGame.playedCardCount, game.playedCardCount+1);
    }
    //test if card removed from player's hand
    printf("Test: Card removed from player's hand\n");
    if(testGame.handCount[p1] == game.handCount[p1]-1){
        printf("PASSED.  Returned %d    Expected %d\n", testGame.handCount[p1], game.handCount[p1]-1);
    } else{
        printf("FAILED.  Returned %d    Expected %d\n", testGame.handCount[p1], game.handCount[p1]-1);
    }


	return 0;
}