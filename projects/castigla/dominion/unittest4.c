//Ashley Castiglione
//Assignment3
//unittest4.c
//unit test testing supplyCount() function


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {

	printf("starting unittest4.c\n");
    
    struct gameState G;

    G.supplyCount[adventurer] = 10;
    G.supplyCount[smithy] = 10;
    G.supplyCount[council_room] = 10;

    G.numPlayers = 1;

    int count1 = supplyCount(adventurer, &G);
    int count2 = supplyCount(smithy, &G);
    int count3 = supplyCount(council_room, &G);


    if (count1 == 10)
    {
    	printf("count1 test passed\n");
    }

    else

    {
    	printf("count1 test failed\n");
    }

    if (count2 == 10)
    {
    	printf("count2 test passed\n");
    }

    else
    {
    	printf("count2 test failed\n");
    }

    if (count3 == 10)
    {
    	printf("count3 test passed\n");
    }

    else
    {
    	printf("count3 test failed\n");
    }


    return 0;
}