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
    //test that card taken from p1's deck
    printf("Test: cards drawn from current player's deck\n");
    if(testGame.deckCount[p1] < game.deckCount[p1]){
        printf("PASSED. Returned %d   Expected %d\n", testGame.deckCount[p1], game.deckCount[p1]-1);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.deckCount[p1], game.deckCount[p1]-1);
    }

    //check that p2 hasn't changed
    printf("Test if p2 hand count changed\n");
    if(testGame.handCount[p2] == game.handCount[p2]){
        printf("PASSED. Returned %d   Expected %d\n", testGame.handCount[p2], game.handCount[p2]);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.handCount[p2], game.handCount[p2]);
    }


    //test if +1 action
    printf("Test: One action added\n");
    if(testGame.numActions == game.numActions+1){
        printf("PASSED. Returned %d   Expected %d\n", testGame.numActions, game.numActions+1);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.numActions, game.numActions+1);
    }

    //test that victory card piles remained the same
    printf("Test if victory card piles changed\n");
    if(testGame.supplyCount[estate] != game.supplyCount[estate]){
        printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[estate], game.supplyCount[estate]);
    }
    if(testGame.supplyCount[duchy] != game.supplyCount[duchy]){
        printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[duchy], game.supplyCount[duchy]);
    }
    if(testGame.supplyCount[province] != game.supplyCount[province]){
        printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[province], game.supplyCount[province]);
    }
    if(testGame.supplyCount[curse] != game.supplyCount[curse]){
        printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[curse], game.supplyCount[curse]);
    }
    else{
        printf("PASSED. Victory card count unchanged.\n");
    }
    
    //test that coin piles remained same
    printf("Test if coin card piles changed\n");
    if(testGame.supplyCount[copper] != game.supplyCount[copper]){
        printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[copper], game.supplyCount[copper]);
    }
    if(testGame.supplyCount[silver] != game.supplyCount[silver]){
        printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[silver], game.supplyCount[silver]);
    }
    if(testGame.supplyCount[gold] != game.supplyCount[gold]){
        printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[gold], game.supplyCount[gold]);
    }
    else{
        printf("PASSED. Coin card count unchanged.\n");
    }

    //test if kingdom cards remain unchanged
    printf("Test if kingdom card piles changed\n");
    int passed = 1;     //bool to keep track of failed tests
    for(int i = 0; i < 10; i++){
        if(testGame.supplyCount[k[i]] != game.supplyCount[k[i]]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[k[i]], game.supplyCount[k[i]]);
            passed = 0;
        }
    }
    if(passed)
        printf("PASSED. Kingdom card count unchanged.\n");

	return 0;
}