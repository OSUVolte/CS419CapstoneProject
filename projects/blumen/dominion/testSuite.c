/*
 * testSuite.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * testSuite: testSuite.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
 *      gcc -o testSuite -g  testSuite.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

/* Prototypes for test functions */
int unittest1();
int unittest1();
int unittest2();
int unittest3();
int unittest4();
int cardtest1();
int cardtest2();
int cardtest3();
int cardtest4();

int main(int argc, char *argv[]) {

    int returnValue;
    printf("\n\n\n  ONE  \n\n");
    returnValue = unittest1();
    printf("\n\n\n  TWO  \n\n");
    returnValue = unittest2();
    printf("\n\n\n  THREE  \n\n");
    returnValue = unittest3();
    printf("\n\n\n  FOUR  \n\n");
    returnValue = unittest4();
    printf("\n\n\n  FIVE  \n\n");
    returnValue = cardtest1();
    printf("\n\n\n  SIX  \n\n");
    returnValue = cardtest2();
    printf("\n\n\n  SEVEN  \n\n");
    returnValue = cardtest3();
    printf("\n\n\n  EIGHT  \n\n");
    returnValue = cardtest4();

    printf("\n\n\n  CODE COVERAGE  \n\n");


	printf("\n\n\n >>>>> SUCCESS: unittestresult.out is complete <<<<<\n\n");


	return 0;
}
