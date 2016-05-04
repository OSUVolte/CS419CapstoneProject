/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 3
 * 4/24/2016
 * unittest3.c
 * Test of isGameOver() function of dominion.c
 * Based on template provided in class for writing unit tests for
 * dominion-base
 *
 * Include the following lines in makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *     gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
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
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int r;
    int k[10] = {treasure_map, salvager, embargo, ambassador, steward,
                great_hall, village, remodel, mine, feast};
    struct gameState G;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    assert (r == 0); //Make sure game is initialized correctly
    
    //Test isGameOver()
    //Input of tested function: gamestate struct
    //Return of tested function: 0 if game is not over, 1 if game is over
    //Game is over if Province pile is empty or if 3 total piles are empty
    int testsPassed = 0;
    int testsCompleted = 0;
    printf("----------TESTING isGameOver() FUNCTION----------:\n");

    //At beginning of game, game is not over
    if (isGameOver(&G) == 0)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("At beginning of game:\t\t Expected value 0, returned value %d\n", isGameOver(&G));

    //when no piles are empty, game is not over
    for (i = 0; i < 27; i++)
        G.supplyCount[i] = 3;

    if (isGameOver(&G) == 0) 
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("None of the piles empty:\t\t Expected value 0, returned value %d\n", isGameOver(&G));

    //when all piles empty, game is over
    for (i = 0; i < 27; i++)
        G.supplyCount[i] = 0; //Empty all piles

    if (isGameOver(&G) == 1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("All of the piles empty:\t\t Expected value 1, returned value %d\n", isGameOver(&G));
  
    //When Province is the only empty pile, game is over
    for (i = 0; i < 27; i++)
        G.supplyCount[i] = 10;
    G.supplyCount[province] = 0;

    if (isGameOver(&G) == 1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Only Province empty:\t\t Expected value 1, returned value %d\n", isGameOver(&G));

    //When one pile (not Province) is empty, game not over
    //Note in the current card enum in dominion.h, province =3, but if this changes, the below test may
    //need to change as well
    
    //All non-Province decks are already not empty from previous test
    G.supplyCount[province] = 10; //Province pile not empty
    G.supplyCount[8] = 0; //arbitrarily chosen pile, not province
    if (isGameOver(&G) == 0)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("One non-Province pile empty:\t Expected value 0, returned value %d\n", isGameOver(&G));
 
    //When two piles (not Province) are empty, game not over
    //Note in the current card enum, province = 3, but if this changes, the below test may
    //need to change as well
    
    //From previous test, 1 non-Province deck is already empty, and province is not
    G.supplyCount[1] = 0; //arbitrarily chosen pile, not province or one from previous test
    if (isGameOver(&G) == 0)
       theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
   printf("Two non-Province piles empty:\t Expected value 0, returned value %d\n", isGameOver(&G));

    //When three piles (not Province) are empty, game over
    //Note in the current card enum, province = 3, but if this changes, the below test may
    //need to change as well
    
    //From previous tests, 2 non-Province decks are already empty, and province is not
    G.supplyCount[20] = 0; //arbitrarily chosen pile, not province or piles from previous tests
    if (isGameOver(&G) == 1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
   printf("Three non-Province piles empty:\t Expected value 1, returned value %d\n",isGameOver(&G));

    //When four piles (not Province) are empty, game over
    //Note in the current card enum, province = 3, but if this changes, the below test may
    //need to change as well
    
    //From previous tests, 3 non-Province decks are already empty, and province is not
    G.supplyCount[0] = 0; //arbitrarily chosen pile, not province or piles from previous tests
    if (isGameOver(&G) == 1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
   printf("Four non-Province piles empty:\t Expected value 1, returned value %d\n",isGameOver(&G));

    //When two piles (one non-Province, on Province) are empty, game over
    //Note in the current card enum, province = 3, but if this changes, the below test may
    //need to change as well
    
    for (i = 0; i < 27; i++)
        G.supplyCount[i] = 8; //Arbitrary number
    G.supplyCount[province] = 0;
    G.supplyCount[10] = 0;

    if (isGameOver(&G) == 1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Two piles empty (one Province):\t Expected value 1, returned value %d\n",isGameOver(&G));

    //When three piles (two non-Province, on Province) are empty, game over
    //Note in the current card enum, province = 3, but if this changes, the below test may
    //need to change as well
    //
    //From previous tests, one non-Province deck and Province decks are eempty
    
    G.supplyCount[11] = 0;

    if (isGameOver(&G) == 1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Three piles empty (one Province):\t Expected value 1, returned value %d\n",isGameOver(&G));

    //When the amount of cards in Province pile is not valid (negative), game not over
    //Note in current card enum, province = 3, but if this changes, the below test may need
    //to change as well

    for (i = 0; i < 27; i++)
        G.supplyCount[i] = 3;
    G.supplyCount[province] = -5;
    if (isGameOver(&G) == 0)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
   printf("Province card invalid value:\t Expected value 0, retured value %d\n", isGameOver(&G));

    //When the amount of three cards are not valid (negative), game not over
    //Note in current card enum, province = 3, but if this changes, the below test may need
    //to change as well
    G.supplyCount[province] = 3;  //Values chosen arbitrarily
    G.supplyCount[24] = -4;
    G.supplyCount[25] = -8;
    G.supplyCount[26] = -2;
    if (isGameOver(&G) == 0)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Three cards invalid values:\t Expected value 0, retured value %d\n", isGameOver(&G));

    if (testsPassed == testsCompleted)
        printf("All tests passed!\n");
    else
        printf("%d tests failed\n", testsCompleted - testsPassed);
    printf("----------FINISHED TESTING isGameOver() FUNCTION----------:\n\n");

    return 0;
}
