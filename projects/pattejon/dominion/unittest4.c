/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* unittest4.c
* isGameOver() method
* This was adapted from the testupdateCoins.c code provided by the instructor
* but I have added additional code to test the game state when random hands
* were populated with different cards
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
// set ASSERTS_ON to 0 to disable asserts for investigating gcov
#define ASSERTS_ON 1

int main() {
	srand(time(NULL));
    int seed = 1000;
    int numPlayer = 2;
    int p, r, i, t, a, b, c;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);

    // ensure that the values of all of the supply cards are are at least 2
    int j = 0;
    for(j = 0; j < 25; j++){
        G.supplyCount[j] = 2;
    }
    printf ("Testing isGameOver():\n");
    // first test to see if the number of provinces is > 0
    G.supplyCount[province] = 1;
    i = isGameOver(&G);
    printf("Expect isGameOver = 0, actual = %d.\n", i);
    assert(i == 0);
    // test if provinces == 0 ends the game
    G.supplyCount[province] = 0;
    i = isGameOver(&G);
    printf("Expect isGameOver = 1, actual = %d.\n", i);
    assert(i == 1);
    // Reset the province and try testing again
    G.supplyCount[province] = 1;
    i = isGameOver(&G);
    printf("Expect isGameOver = 0, actual = %d.\n", i);
    assert(i == 0);

    // now we'll try setting just one supply to 0 and see if it causes the expected behavior
    for(t = 0; t < 100; t++){
    	printf("Starting random test %d of empty piles\n", t);
    	a = rand() % 25; // pick a random position
    	while( a == 3){
    		a = rand() % 25; //can't pick 3!
    	}
    	printf("Setting position %d to empty.\n", a);
    	G.supplyCount[a] = 0;	// set to 0
    	// Expect game to continue
    	i = isGameOver(&G);
    	printf("Expect isGameOver = 0, actual = %d.\n", i);
    	assert(i == 0);
    	b = rand() % 25;
    	while(a == b || b == 3){
    		//rand until they are not
    		b = rand() % 25;
    	}
    	printf("Setting position %d to empty.\n", b);
    	G.supplyCount[b] = 0;
    	// Expect game to continue
    	i = isGameOver(&G);
    	printf("Expect isGameOver = 0, actual = %d.\n", i);
    	assert(i == 0);
    	c = rand() % 25;
    	while(c == a || c == b || c == 3){
    		c = rand() % 25;
    	}
    	printf("Setting position %d to empty.\n", c);
    	i = isGameOver(&G);
    	G.supplyCount[c] = 0;
    	// expect game to end
    	i = isGameOver(&G);
    	printf("Expect isGameOver = 1, actual = %d.\n", i);
    	assert(i == 1);
    	// loop again
    	for(j = 0; j < 25; j++){
        	G.supplyCount[j] = 2;
    	}

    }
    
    return 0;

}