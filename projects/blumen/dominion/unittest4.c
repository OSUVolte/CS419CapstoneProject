/**
unittest4.c: Tests the isGameOver() method

// Basic requirements
1. If Set supply of province cards to 0 then return value is 1
2. If 3 piles are depleted then return value is 1
3. If < 3 piles are depleted, return value is 0

Include the following lines in your makefile:
unittest1: unittest1.c dominion.o rngs.o
    gcc -o unittest1 -g  unittest1.c dominion.o rngs.o -lm

    was:
    gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTMETHOD "isGameOver()"       //*******************>>>> change me

void unittest4() {
    int seed = 7;
    srand((unsigned) seed);
    int i, j, m;
    int numPlayers = 2;
//    int thisPlayer = 0;
//    int otherPlayer = 1;
	struct gameState G;
	int k[10] = {smithy, adventurer, feast, council_room, gardens, village, remodel, mine, cutpurse, embargo};

	printf("----------------- Testing Method: %s ----------------\n", TESTMETHOD);

    // ----------- TEST 1: If Set supply of province cards to 0 then return value is 1 --------------
	printf("TEST 1: If Set supply of province cards to 0 then return value is 1\n");
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	// set the supply of provinces to 0
    G.supplyCount[province] = 0;
	// apply the method and test return value
	printf("Return value = %d, expected: 1\n", isGameOver(&G));
	assert(isGameOver(&G) == 1);

    // ----------- TEST 2: If Set supply of province cards to 0 then return value is 1 --------------
	printf("TEST 2: If 3 piles are depleted then return value is 1\n");
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	// set the supply of 3 random piles to 0
    i = rand() % (treasure_map+1);
    j = i;
    m = i;
    while (j == i || j == m) {
        j = rand() % (treasure_map+1);
    }
    while (m == i || m == j) {
        m = rand() % (treasure_map+1);
    }
    G.supplyCount[i] = 0;
    G.supplyCount[j] = 0;
    G.supplyCount[m] = 0;
	// apply the method and test return value
	printf("Return value = %d, expected: 1\n", isGameOver(&G));
	assert(isGameOver(&G) == 1);

    // ----------- TEST 3: If < 3 piles are depleted, return value is 0 --------------
	printf("TEST 3: If < 3 piles are depleted, return value is 0\n");
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	// test when no pile is depleted
	printf("Return value when no pile is depleted = %d, expected: 0\n", isGameOver(&G));
	assert(isGameOver(&G) == 0);

	// test when 1 pile (other than province) is depleted
    i = rand() % (treasure_map+1);
    while (i == province) {
        i = rand() % (treasure_map+1);
    }
    G.supplyCount[i] = 0;
	printf("Return value when 1 pile is depleted = %d, expected: 0\n", isGameOver(&G));
	assert(isGameOver(&G) == 0);

    //test when 2 piles are depletedW
    j = i;
    while (j == i || j == province) {
        j = rand() % (treasure_map+1);
    }
    G.supplyCount[j] = 0;
	printf("Return value when 2 piles are depleted = %d, expected: 0\n", isGameOver(&G));
	assert(isGameOver(&G) == 0);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTMETHOD);

	return 0;
}


