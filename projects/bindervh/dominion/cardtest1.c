#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************
Unit test for adventurer card
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

    printf("Testing adventurer card \n");

    //set up players
    p1 = 0;
    p2 = 1;

    //set up game states
    initializeGame(numPlayers, k, randomSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));

    //test if no treasure in deck
    //set up p1's deck
    testGame.deck[p1][0] = smithy;
    testGame.deck[p1][1] = gardens;
    testGame.deck[p1][2] = adventurer;
    testGame.deck[p1][3] = village;

    int coinsBefore = testGame.coins;   
    result = cardEffect(adventurer, 0, 0, 0, &testGame, 0, 0);
    int coinsAfter = testGame.coins;
    printf("Test: Coin value in hand unchanged if no treasure in deck\n");
    if(coinsAfter == coinsBefore){
        printf("PASSED.  Returned %d   Expected %d\n", coinsAfter, coinsBefore);
    } else{
        printf("FAILED.  Returned %d   Expected %d\n", coinsAfter, coinsBefore);
    }
    printf("Test: Handcount unchanged if no treasure in deck\n");
    if(testGame.handCount[p1] == game.handCount[p1]){
        printf("PASSED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]);
    }

    //test if coins correctly added
    memcpy(&testGame, &game, sizeof(struct gameState)); //reset game state
    //set up hand
    testGame.deck[p1][0] = gold;
    testGame.deck[p1][1] = feast;
    testGame.deck[p1][2] = silver;
    testGame.deck[p1][3] = smithy;
    int AmtAdded = 5;
    coinsBefore = testGame.coins;   
    result = cardEffect(smithy, 0, 0, 0, &testGame, 0, 0);
    coinsAfter = testGame.coins;
    printf("Test: Coin value in hand changed when treasure added\n");
    if(coinsAfter == coinsBefore+AmtAdded){
        printf("PASSED.  Returned %d   Expected %d\n", coinsAfter, coinsBefore+AmtAdded);
    } else{
        printf("FAILED.  Returned %d   Expected %d\n", coinsAfter, coinsBefore+AmtAdded);
    }
    printf("Test: Handcount changed when treasure added\n");
    if(testGame.handCount[p1] == game.handCount[p1]+2){
        printf("PASSED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]+2);
    } else{
        printf("FAILED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]+2);
    }


	return 0;
}