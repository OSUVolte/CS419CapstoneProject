#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**************************************
Unit test for updateCoins function
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

    printf("Testing updateCoins \n");

    //set up players
    p1 = 0;
    p2 = 1;

    //set up game states
    initializeGame(numPlayers, k, randomSeed, &game);
    memcpy(&testGame, &game, sizeof(struct gameState));

    //set player hand to have coins = 7
    int coinAmt = 7;
    testGame.hand[p1][0] = gold;
    testGame.hand[p1][1] = copper;
    testGame.hand[p1][2] = silver;
    testGame.hand[p1][3] = copper;
    testGame.hand[p1][4] = smithy;

    printf("Test: Correct coin value for cards in hand\n");
    result = updateCoins(p1, &testGame, 0);
    if(testGame.coins == coinAmt){
        printf("PASSED.  Returned %d    Expected %d\n", testGame.coins, coinAmt);
    } else{
        printf("FAILED.  Returned %d    Expected %d\n", testGame.coins, coinAmt);
    }


	return 0;
}