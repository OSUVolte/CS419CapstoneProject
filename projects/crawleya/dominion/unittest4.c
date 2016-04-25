/* Alisha Crawley-Davis
 * CS 362 Assn 3
 * 4/24/2016
 * unittest4.c
 * Test of scoreFor() function of dominion.c
 * Based on template provided in class for writing unit tests for
 * dominion-base
 *
 * Include the following lines in makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *     gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
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
    int numPlayer = 4;
    int r, p;
    int k[10] = {treasure_map, salvager, embargo, ambassador, steward,
                great_hall, village, remodel, mine, feast};
    struct gameState G;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    assert (r == 0); //Make sure game is initialized correctly
    
    //Test scoreFor()
    //Input of tested function: gamestate struct, player
    //Returns score of player
    //Score is made up of the points of the estate, duchy, and province cards
    //in the player's deck, hand, and discard pile, along with possible enhancements via the
    //Victory Kingdom cards (great_hall, gardens). A point is subtracted for each curse card the player has.
    int testsPassed = 0;
    int testsCompleted = 0;
    printf("----------TESTING scoreFor() FUNCTION----------:\n");

    //At beginning of game, all players should have 3 points
    for (p = 0; p < numPlayer; p++)
    {
        if (scoreFor(p, &G) == 3)
            theResult(1, &testsPassed, &testsCompleted);
        else
            theResult(0, &testsPassed, &testsCompleted);
        printf("Start score Player %d:\t\tExpected 3, Acutal %d\n", p + 1, scoreFor(p, &G));
    }

    //If no players have any point cards, all scores shold be 0
    for (p = 0; p < numPlayer; p++)
    {
        //Fill players piles with cards with no point values
        G.handCount[p] = 7;
        G.deckCount[p] = 7;
        G.discardCount[p] = 6;

        for (i = 0; i < 7; i++)
        {
            G.hand[p][i] = copper;
            G.deck[p][i] = salvager;
            if (i < 6)                    
                G.discard[p][i] = feast; //Discard pile has fewer cards
        }

        if (scoreFor(p, &G) == 0)
            theResult(1, &testsPassed, &testsCompleted);
        else
            theResult(0, &testsPassed, &testsCompleted);
        printf("No point cards for Player %d:\tExpected 0, Actual %d\n", p + 1, scoreFor(p, &G));
    }
   //Test if each type of card that affects score are calculated correctly in hand, deck, discard
   //Add curse card to player's hand, score should decrease by 1
   //Add estate card to hand, score should increase by 1
   //Add duchy to player's hand, score should incrase by 3
   //Add province to player's hand, score should increase by 6
   //Add great hall, score should increase by 1
   //Add gardens, score should increase by 1 for every 10 cards (rounded down 39 cards is worth 3)
   //Do same for discard and same for dek


    //Add scoring cards one by one to player's hand and make sure score updates appropriately
    //Note that all piles for all players hands are filled with non-scoring cards from last test
    G.hand[0][0] = curse;
    if (scoreFor(0, &G) == -1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score curse cards in hand:\tExpected -1, Actual %d\n", scoreFor(0, &G));
    G.hand[0][1] = estate;
    if (scoreFor(0, &G) == 0)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score estate cards in hand:\tExpected 0, Actual %d\n", scoreFor(0, &G));
   G.hand[0][2] = duchy;
    if (scoreFor(0, &G) == 3)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score duchy cards in hand:\tExpected 3, Actual %d\n", scoreFor(0, &G));
   G.hand[0][3] = province;
    if (scoreFor(0, &G) == 9)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score provine cards in hand:\tExpected 9, Actual %d\n", scoreFor(0, &G));
   G.hand[0][4] = great_hall;
    if (scoreFor(0, &G) == 10)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score great hall cards in hand:\tExpected 10, Actual %d\n", scoreFor(0, &G));
   G.hand[0][5] = gardens;
    if (scoreFor(0, &G) == 10)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score garden cards in hand:\tExpected 10, Actual %d\n", scoreFor(0, &G));
   G.hand[0][6] = curse;
    if (scoreFor(0, &G) == 9)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score curse cards in hand:\tExpected 9, Actual %d\n", scoreFor(0, &G));

//Repeat above test for player 2's discard pile (player 2's hand and deck have no score)
    G.discard[1][0] = curse;
    if (scoreFor(1, &G) == -1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(1, &testsPassed, &testsCompleted);
    printf("Score curse cards in discard:\tExpected -1, Actual %d\n", scoreFor(1, &G));
    G.discard[1][1] = estate;
    if (scoreFor(1, &G) == 0)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score estate cards in discard:\tExpected 0, Actual %d\n", scoreFor(1, &G));
   G.discard[1][2] = duchy;
    if (scoreFor(1, &G) == 3)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score duchy cards in discard:\tExpected 3, Actual %d\n", scoreFor(1, &G));
   G.discard[1][3] = province;
    if (scoreFor(1, &G) == 9)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score provine cards in discard:\tExpected 9, Actual %d\n", scoreFor(1, &G));
    G.discard[1][4] = great_hall;
    if (scoreFor(1, &G) == 10)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score great hall card in discard:\tExpected 10, Actual %d\n", scoreFor(1, &G));
    G.discard[1][5] = gardens;
    if (scoreFor(1, &G) == 10)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score garden cards in discard:\tExpected 10, Actual %d\n", scoreFor(1, &G));

//Repeat above test for player 3's deck pile (player 3's hand and discard have no score)
    G.deck[2][0] = curse;
    if (scoreFor(2, &G) == -1)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score curse cards in deck:\tExpected -1, Actual %d\n", scoreFor(2, &G));
    G.deck[2][1] = estate;
    if (scoreFor(2, &G) == 0)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score estate cards in deck:\tExpected 0, Actual %d\n", scoreFor(2, &G));
   G.deck[2][2] = duchy;
    if (scoreFor(2, &G) == 3)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score duchy cards in deck:\tExpected 3, Actual %d\n", scoreFor(2, &G));
   G.deck[2][3] = province;
    if (scoreFor(2, &G) == 9)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score provine cards in deck:\tExpected 9, Actual %d\n", scoreFor(2, &G));
   G.deck[2][4] = great_hall;
    if (scoreFor(2, &G) == 10)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score great hall cards in deck:\tExpected 10, Actual %d\n", scoreFor(2, &G));
   G.deck[2][5] = curse;
    if (scoreFor(2, &G) == 9)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score curse cards in deck:\tExpected 9, Actual %d\n", scoreFor(2, &G));
   G.deck[2][6] = province;
    if (scoreFor(2, &G) == 15)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Score province cards in deck:\tExpected 15, Actual %d\n", scoreFor(2, &G));

   if (testsPassed == testsCompleted)
        printf("All tests passed!\n");
    else
        printf("%d passed out of %d tests.\n", testsPassed, testsCompleted);
 
    printf("----------FINISHED TESTING scoreFor() FUNCTION----------:\n\n");
    return 0;
}
