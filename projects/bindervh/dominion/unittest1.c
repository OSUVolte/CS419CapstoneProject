#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************
Unit test for gainCard function
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

    printf("Testing gainCard \n");

    //set up players
    p1 = 0;
    p2 = 1;

    //set up game states
    initializeGame(numPlayers, k, randomSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));

    //test if supply empty
    testGame.supplyCount[smithy] = 0;	//set smithy supply count to 0
    result = gainCard(smithy, &testGame, 1, p1);
    printf("Test: Attempt to gain card from empty pile \n");
    if(-1 == result){
    	printf("PASSED.  Returned %d    Expected %d\n", result, -1);
    } else{
    	printf("FAILED.  Returned %d    Expected %d\n", result, -1);
    }

    //test if card added to deck
    memcpy(&testGame, &game, sizeof(struct gameState));	//reset testGame
    result = gainCard(smithy, &testGame, 1, p1);
    printf("Test: Card added to player 1 deck \n");
    if(testGame.deckCount[p1] == game.deckCount[p1]+1){
    	printf("PASSED.  Returned %d    Expected %d\n", testGame.deckCount[p1], game.deckCount[p1]+1);
    } else{
    	printf("FAILED.  Returned %d    Expected %d\n", testGame.deckCount[p1], game.deckCount[p1]+1);
    }

    //test if card added to hand
    memcpy(&testGame, &game, sizeof(struct gameState));	//reset testGame
    result = gainCard(smithy, &testGame, 2, p1);
    printf("Test: Card added to player 1 hand \n");
    if(testGame.handCount[p1] == game.handCount[p1]+1){
    	printf("PASSED.  Returned %d    Expected %d\n", testGame.handCount[p1], game.handCount[p1]+1);
    } else{
    	printf("FAILED.  Returned %d    Expected %d\n", testGame.handCount[p1], game.handCount[p1]+1);
    }

    //test if card discarded
    memcpy(&testGame, &game, sizeof(struct gameState));	//reset testGame
    result = gainCard(smithy, &testGame, 0, p1);
    printf("Test: Card discarded \n");
    if(testGame.discardCount[p1] == game.discardCount[p1]+1){
    	printf("PASSED.  Returned %d    Expected %d\n", testGame.discardCount[p1], game.discardCount[p1]+1);
    } else{
    	printf("FAILED.  Returned %d    Expected %d\n", testGame.discardCount[p1], game.discardCount[p1]+1);
    }

    //test if supply pile count decreased
    printf("Test: Supply count decreased \n");
    if(testGame.supplyCount[smithy] == game.supplyCount[smithy]-1){
    	printf("PASSED.  Returned %d    Expected %d\n", testGame.supplyCount[smithy], game.supplyCount[smithy]-1);
    } else{
    	printf("FAILED.  Returned %d    Expected %d\n", testGame.supplyCount[smithy], game.supplyCount[smithy]-1);
    }


	return 0;
}