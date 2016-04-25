/*---------------------------------------
* Brett Irvin
* 4/20/16
* CS362_400 Software Engineering II
* Assignment 3--unittest3.c
* Unit test for the isGameOver function
*---------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*Citation: http://www.ultradominion.com/game-rules.php
The game should end when:
1. Provinces are depleted.
2. 3 supply piles are depleted.
*/

int main() {
	int seed = 1000;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
    int numPlayers = 2;
    int gameOver = 0;
	int i = 0;
	struct gameState G, testG;

    initializeGame(numPlayers, k, seed, &G);
	
	/*---------------------------------------------------------*/
	printf("\n---Testing the isGameOver function:---\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    printf("\nTest 1: Game ends when province cards are depleted.\n");
    testG.supplyCount[province] = 0;
    gameOver = isGameOver(&testG);
    if (gameOver == 1) {
        printf("Success: province cards triggered a game over condition.\n");
    } 
	else {
        printf("Failure: province cards failed to trigger a game over condition.\n");
    }
	/*---------------------------------------------------------*/
	
    printf("\nTest 2: Game over is triggered with three supply piles at 0.\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    for (i = 0; i < 3; i++){
		testG.supplyCount[i] = 0;
	}
    gameOver = isGameOver(&testG);
    if (gameOver == 1)
        printf("Success: three depleted supply piles triggered a game over condition.\n");
    else 
        printf("Failure: three depleted supply piles did not end the game.\n");
	/*---------------------------------------------------------*/
	
	printf("\nTest 3: Duchy and estate cards do not trigger a game over condition.\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    testG.supplyCount[estate] = 0;
	testG.supplyCount[duchy] = 0;
    gameOver = isGameOver(&testG);
    if (gameOver == 0) {
        printf("Success: game continued with duchy and estate cards depleted.\n");
    } 
	else {
        printf("Failure: estate and duchy cards triggered a game over condition.\n");;
    }
	printf("\n---isGameOver test complete---\n\n");
	return 0;
}