/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

Tests handCard()
Tested behavior:  Function returns what card is at the given hand position
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, x,handPos;
	int seed = 1000;
	int numPlayers = 2;
	int player = 0;
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	struct gameState G;

    /////// Announce testing
    printf("Testing handCard() function:\n");

	//Clean gamestates
	memset(&G, 23, sizeof(struct gameState));

    // Initialize game
    x = initializeGame(numPlayers, k, seed, &G);

    // Variables for expected and actual
    int expected = G.hand[player][handPos];
    int actual = handCard(handPos, &G);

    // Print results
    printf("TEST: actual hand card= %d. Expected result = %d.\n", actual, expected);

    // Error message if hand card in G is not expected
    if (actual != expected){
        printf("TEST FAILED!\n");
    }
    else{
        printf("Test passed!\n");
    }

    return 0;
}
