/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: unittest4.c
 *
 * Unit test of function in dominion.c:
 *      isGameOver
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct gameState gameOrig;          // original game state
    // to initialize the game, you need the number of players, kingdom cards, a random seed, and the game state
    struct gameState gameTest;          // game state for testing
    int kc[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int i;                              // we'll probably need a counter at some point
    int players = 2;
    int numTests = 1;                   // run each test once
    int result;

    /**************************************************
    * The following conditions occur by the end of the isGameOver function:
    * - if there are no more provinces left, game is over
    * - if any three of the supply pile are at 0, the game is over
    * - return 1 if game over, 0 if not
    **************************************************/

     printf("** Function being tested: isGameOver **\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if provinces have been exhausted ***/
        gameTest.supplyCount[province] = 0;
        result = isGameOver(&gameTest);

        printf("TEST 1\n\n");
        printf("Expecting result to be 1, game is over because provinces exhausted.\n\n");

        if (result == 1) {
            printf("*** Test passed ***\n");
            printf("Result equals %d, which means the game is over.\n\n", result);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Result equals %d, which means the game is not over or alternate state.\n\n", result);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if 3 supply piles have been exhausted ***/
        gameTest.supplyCount[estate] = 0;
        gameTest.supplyCount[copper] = 0;
        gameTest.supplyCount[duchy] = 0;

        result = isGameOver(&gameTest);

        printf("TEST 2\n\n");
        printf("Expecting result to be 1, game is over because 3 supply cards are exhausted.\n\n");

        if (result == 1) {
            printf("*** Test passed ***\n");
            printf("Result equals %d, which means the game is over.\n", result);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Result equals %d, which means the game is not over or alternate state.\n", result);
        }
    }
    return 0;

}


