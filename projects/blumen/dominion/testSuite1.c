/*
 * testSuite1.c
 *

 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

/* Prototypes for test functions */
void randomtestcard();

int main(int argc, char *argv[]) {

    printf("\n\n\n  RANDOM TESTING OF REMODEL CARD  \n\n");

    //Begin testing
    randomtestcard();

    //Code coverage
    printf("\n\n\n  CODE COVERAGE  \n\n");
	//printf("\n\n\n >>>>> SUCCESS: unittestresult.out is complete <<<<<\n\n");


	return 0;
}
