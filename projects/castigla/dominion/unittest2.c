//Ashley Castiglione
//Assignment3
//unittest2.c
//unit test testing getcost() function

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main(int argc, const char * argv[]) {

    printf("starting unittest2.c\n");
    
    if (getCost(smithy) == 4)
    {
    	printf("smithy getcost passed\n");
    }
    else
    {
    	printf("smithy getcost failed\n");
    }

     if (getCost(adventurer) == 6)
    {
    	printf("adventurer getcost passed\n");
    }
    else
    {
    	printf("adventurer getcost failed\n");
    }

     if (getCost(province) == 8)
    {
    	printf("province getcost passed\n");
    }
    else
    {
    	printf("province getcost failed\n");
    }


    return 0;
}