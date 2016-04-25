/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

Tests whoseTurn() function
Tested behavior:  Function returns the player whose turn it is
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, x;
	int seed = 1000;
	int player = 0;
	int numPlayers = 2;
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	struct gameState G;

    /////// Announce testing
    printf("Testing whoseTurn() function:\n");

	//Clean gamestates
	memset(&G, 23, sizeof(struct gameState));

    // Initialize game
    x = initializeGame(numPlayers, k, seed, &G);

    // Variables for expected and actual player
    int expected = G.whoseTurn;
    int actual = whoseTurn(&G);

    // Print results
    printf("TEST: whose turn = %d. Expected result = %d.\n", actual, expected);

    // Error message if player in G is not expected
    if (actual != expected){
        printf("TEST FAILED!\n");
    }
    else{
        printf("Test passed!\n");
    }

    return 0;
}
