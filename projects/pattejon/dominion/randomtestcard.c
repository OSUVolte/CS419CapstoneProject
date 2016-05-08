/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 4
* randomtestcard.c
* village card random tests
*---------------------------------------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
// set ASSERTS_ON to 0 to disable asserts for investigating gcov
#define ASSERTS_ON 0
// let's just define number of tests here
#define NUM_TESTS 1000

int main() {
    int seed = 1000;
    int numPlayer;
    int p, r, i, test;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState T;
    int error;
    int num_errors = 0;
    srand(time(NULL)); // set random seed prior to going into loop
    for( test = 0; test < NUM_TESTS; test++ ){
        // In the previous assignment this was a much shorter test but it had good coverage
        // For this assignment I'm going to try and add more cases and then ensure the 
        // random testing component keeps up the good coverage
        seed = rand(); // randomize
        numPlayer = (rand() % 3) + 2; // set randome number of players, minimum 2

        error = 0; // We're going to track the number of tests that have errors, just for fun
        memset(&G, 23, sizeof(struct gameState));
        memset(&T, 23, sizeof(struct gameState));

        r = initializeGame(numPlayer, k, seed, &G);
        // ensure that the values of all of the supply cards are are at least 2
        int j = 0;
        // start with the first player, since they're active
        p = 0;
        // make a random card in hand a village
        int temp = rand() % G.handCount[p];
        for(j = 0; j < 25; j++){
            G.supplyCount[j] = 2;
        }
        printf ("Testing village for playCard(%d, 0, 0, 0, gameState):\n", temp);
        printf("Testing for village card player %d:\n", p);
        int testActions = G.numActions;
        int testBuys = G.numBuys;
        int testHandCount = G.handCount[p];
        int testDeckCount = G.deckCount[p];

        //assign the card
        G.hand[p][temp] = village;
        // Copy the gameState to another place to test so we can compare
        memcpy(&T, &G, sizeof(struct gameState));
        //play the village card now
        playCard(temp, 0, 0, 0, &G);

        //Upon execution, adjust test values
        //test actions should be one more
        testActions++;
        //Buys unchanged
        //net hand count should be unchanged
        //deck count should be 1 less
        testDeckCount -= 1;

        #if (NOISY_TEST == 1)
        printf("Test actions updated correctly:\n");
        printf("Actions = %d, Expected = %d\n", G.numActions, testActions);
        printf("Test buys updated correctly:\n");
        printf("Buys = %d, Expected = %d\n", G.numBuys, testBuys);
        printf("Test deck updated correctly:\n");
        printf("Deck = %d, Expected = %d\n", G.deckCount[p], testDeckCount);
        printf("Test hand updated correctly:\n");
        printf("Hand = %d, Expected = %d\n", G.handCount[p], testHandCount);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.numActions == testActions);
        assert(G.numBuys == testBuys);
        assert(G.deckCount[p] == testDeckCount);
        assert(G.handCount[p] == testHandCount);
        #endif
        if (G.numActions != testActions) error = 1;
        if (G.numBuys != testBuys) error = 1;
        if (G.deckCount[p] != testDeckCount ) error = 1;
        if (G.handCount[p] != testHandCount ) error = 1;

        //Some additional sanity tests for other players
        for(p = 1; p < numPlayer; p++){
            #if NOISY_TEST
            printf("Test player %d unchanged:\n", p);
            printf("Deck = %d, Expected = %d\n", G.deckCount[p], T.deckCount[p]);
            printf("Hand = %d, Expected = %d\n", G.handCount[p], T.handCount[p]);
            #endif
            #if (ASSERTS_ON == 1)
            assert(G.deckCount[p] == T.deckCount[p]);
            assert(G.handCount[p] == T.handCount[p]);
            #endif 
            if(G.deckCount[p] != T.deckCount[p]) error = 1;
            if(G.handCount[p] != T.handCount[p]) error = 1;
        }
        if(error == 1){
            num_errors++;
        }

    }
    printf("Number of tests run: %d\n", test);
    printf("Number of tests that encountered errors: %d\n", num_errors);
    if(num_errors > 0){
        printf("Errors were encountered.\n");
        return 1;
    }

    return 0;
}