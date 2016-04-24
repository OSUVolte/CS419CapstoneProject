//Ashley Castiglione
//Assignment3
//unittest1.c
//unit test testing isgameover() function

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {
    
    printf("starting unittest1.c\n");

    //struct for the state of the game
    struct gameState state;

    //k[10] for 10 cards
    int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    initializeGame(2, k, 2, &state);

    //provence count is 0
    state.supplyCount[province] = 0;

    int i = isGameOver(&state);

    if (i == 1)
    {
    	printf("isGameOver test part 1 passed\n");
    }
    else
    {
    	printf("isGameOver test part 1 failed\n");
    }

    state.supplyCount[1] = 0;
    state.supplyCount[5] = 0;
    state.supplyCount[9] = 0;

    i = isGameOver(&state);

    if (i == 1)
    {
    	printf("isGameOver test part 2 passed\n");
    }
    else
    {
    	printf("isGameOver test part 2 failed\n");
    }


    return 0;
}