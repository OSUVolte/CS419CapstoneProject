/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 3
 * unittest1.c
 * Test of numHandCards() function of dominion.c
 * Based on template provided in class for writing unit tests for
 * dominion-base
 *
 * Include the following lines in makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *     gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*****************************************************************************
 * Description: This function prints out whether the test passes or fails
 *              and updates the testsCompleted and testsPassed variables
 *              as appropriate
 * Input:       int i; Boolean 1 = pass, 0 = fail
 *              *tp testsPassed increments when test passes
 *              *tc testsCompleted increments each time the function
 *               is called
 **************************************************************************/
void theResult(int i, int *tp, int *tc)
{
    *tc = *tc + 1;
    if (i == 1) //test passed
    {
        *tp = *tp + 1;
        printf("PASS: ");
    }
    else if (i == 0) //test failed
        printf("FAIL: ");
    else            //bad input to function
        printf("BAD TEST");
}

int main() {

    //Set up the game
    int p;
    int seed = 1000;
//    int numPlayer = 2;
    int r;
    int k[10] = {treasure_map, salvager, embargo, ambassador, steward,
                great_hall, village, remodel, mine, feast};
    struct gameState G;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(MAX_PLAYERS, k, seed, &G); // initialize a new game
    assert (r == 0); //Make sure game is initialized correctly
    
    //Test numHandCards()
    //Input of tested function: gamestate struct
    //Return of tested function: The number of cards in the hand of the person whose turn it is
    int testsPassed = 0;
    int testsCompleted = 0;
         
    //Set player's hand count to arbitrary number
    for (p = 0; p < MAX_PLAYERS; p++)
       G.handCount[p] = p + 3;
   printf("----------TESTING numHandCards() FUNCTION----------\n");

    //Set whose turn to each player and check to see if game returns
    //that player's correct number of cards
    for (p = 0; p < MAX_PLAYERS; p++)
    {
        G.whoseTurn = p;
        if (numHandCards(&G) == p + 3)
            theResult(1, &testsPassed, &testsCompleted);
        else
            theResult(0, &testsPassed, &testsCompleted);
        printf("Number of cards in hand:\t Expected %d, got %d\n", p + 3, numHandCards(&G));  
    }

    if (testsPassed == testsCompleted)
        printf("All tests passed\n");
    else
        printf("%d out of %d tests passed", testsPassed, testsCompleted);

    printf("----------FINISHED TESTING numHandCards() FUNCTION----------\n\n");
    return 0;
}
