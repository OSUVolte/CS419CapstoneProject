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
void randomtestadventurer();

int main(int argc, char *argv[]) {

    printf("\n\n\n  RANDOM TESTING OF ADVENTURER CARD  \n\n");

    //Begin testing
    randomtestadventurer();

    //Code coverage
    printf("\n\n\n  CODE COVERAGE  \n\n");


	return 0;
}
