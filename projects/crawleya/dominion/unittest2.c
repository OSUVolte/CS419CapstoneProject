/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 3
 * 4/24/2016
 * unittest2.c
 * Test of getCost() function of dominion.c
 * Based on template provided in class for writing unit tests for
 * dominion-base
 *
 * Include the following lines in makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *     gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// set Max number of unique cards that have costs associtaed with them
#define MAX_CARDS 27

//Recall CARD is an enum with curse=0, estate=1, duchy, province, copper, silver, gold,
//adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall,
//minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag,
//treasure_map
//NOTE if any cards are added or removed, or the order changed, this unit test will need to be updated

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
    
    //Test getCost()
    //Input of tested function: card
    //Return of tested function: cost of card
    int testsPassed = 0;
    int testsCompleted = 0;

   //The expected cost of each card, numbers from Dominion documentation
    int realCost[MAX_CARDS] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};

    printf("----------TESTING getCost() FUNCTION----------:\n");

   for (i = -1; i < MAX_CARDS+1; i++)
    {
        testsCompleted++;
        switch (i)
        {
            case curse:
                printf("Testing curse card:\t\t ");
                break;
            case estate:
                printf("Testing estate card:\t\t ");
                break;
            case duchy:
                printf("Testing duchy card:\t\t ");
                break;
            case province:
                printf("Testing province card:\t\t ");
                break;
            case copper:
                printf("Testing copper card:\t\t ");
                break;
            case silver:
                printf("Testing silver card:\t\t ");
                break;
            case gold:
                printf("Testing gold card:\t\t ");
                break;
            case adventurer:
                printf("Testing adventurer card:\t ");
                break;
            case council_room:
                printf("Testing council room card:\t ");
                break;
            case feast:
                printf("Testing feast card:\t\t ");
                break;
            case gardens:
                printf("Testing gardens card:\t\t ");
                break;
            case mine:
                printf("Testing mine card:\t\t ");
                break;
            case remodel:
                printf("Testing remodel card:\t\t ");
                break;
            case smithy:
                printf("Testing smithy card:\t\t ");
                break;
            case village:
                printf("Testing village card:\t\t ");
                break;
            case baron:
                printf("Testing baron card:\t\t ");
                break;
            case great_hall:
                printf("Testing great hall card:\t ");
                break;
            case minion:
                printf("Testing minion card:\t\t ");
                break;
            case steward:
                printf("Testing steward card:\t\t ");
                break;
            case tribute:
                printf("Testing tribute card:\t\t ");
                break;
            case ambassador:
                printf("Testing ambassador card:\t ");
                break;
            case cutpurse:
                printf("Testing cutpurse card:\t\t ");
                break;
            case embargo:
                printf("Testing embargo card:\t\t ");
                break;
            case outpost:
                printf("Testing outpost card:\t\t ");
                break;
            case salvager:
                printf("Testing salvager card:\t\t ");
                break;
            case sea_hag:
                printf("Testing sea hag card:\t\t ");
                break;
            case treasure_map:
                printf("Testing treasure map card:\t ");
                break;
            case -1:
                printf("Testing illegal low value:\t ");
                break;
            case MAX_CARDS:
                printf("Testing illegal high value:\t ");
                break;
        }
        if (i > -1 && i < MAX_CARDS)
        {
            if (getCost(i) == realCost[i])
            {
                printf("PASS: ");
                testsPassed++;
            }
            else
                printf("FAIL: ");
            printf("Expected %d, got %d\n", realCost[i], getCost(i));
        }
        else
        {
            if (getCost(i) == -1)
            {
                printf("PASS: ");
                testsPassed++;
            }
            else
                printf("FAIL: ");
            printf("Expected %d, got %d\n", -1, getCost(i));
        }
        //Make sure game state did not change
            
    }
    if (testsPassed == testsCompleted)
        printf("All tests passed!\n");
    else
        printf("%d out of %d tests passed.\n", testsPassed, testsCompleted);
    printf("----------FINISHED TESTING getCost() FUNCTION----------:\n\n");
    return 0;
}
