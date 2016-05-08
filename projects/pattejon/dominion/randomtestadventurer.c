/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 4
* randomtestadventurer.c
* adventurer card random tests
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
    int numPlayer = 2;
    int p, r, i, test;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState T;
    int error;
    int num_errors = 0;
    srand(time(NULL));
    for( test = 0; test < NUM_TESTS; test++){
        // In the previous assignment this was a much shorter test but it had good coverage
        // For this assignment I'm going to try and add more cases and then ensure the 
        // random testing component keeps up the good coverage
        seed = rand(); // randomize
        numPlayer = (rand() % 3) + 2; // set random number of players, minimum 2
        error = 0; // We're going to track the number of tests that have errors, just for fun
        
        memset(&G, 23, sizeof(struct gameState));
        memset(&T, 23, sizeof(struct gameState));
        r = initializeGame(numPlayer, k, seed, &G);

        // player deck is already pre-seeded with a couple of estate cards
        // as well as coppers. I propose we modify this to randomly change
        // some of the cards to silver/gold to ensure that they are appropriately
        // detected by the adventurer card as treasures
        
        p = 0;
        int temp;
        for (i = 0; i < G.deckCount[p]; i++){
            // If it's a copper, roll to see what it turns into
            if (G.deck[p][i] == copper){
                temp = rand() % 3;
                switch(temp){
                    case 0 :
                        G.deck[p][i] = copper;
                    case 1 :
                        G.deck[p][i] = silver;
                    case 2 :
                        G.deck[p][i] = gold;
                }//end switch
            }//endif
        }// end deck modification

        int j = 0;
        for(j = 0; j < 25; j++){
            G.supplyCount[j] = 2;
        }

        printf ("Testing adventurer for playCard(0, 0, 0, 0, gamestate):\n");
        p = 0;
        printf("Testing for player %d:\n", p);
        int testActions = G.numActions;
        int testBuys = G.numBuys;
        int testHandCount = G.handCount[p];
        int numTreasures = 0;
        int numTreasuresPost = 0;
        int i;

        // We'll make a random card in hand a village, just for grins
        temp = rand() % G.handCount[p];
        // assign the card 
        G.hand[p][temp] = adventurer;
        // Copy the gameState to another place to test so we can compare
        memcpy(&T, &G, sizeof(struct gameState));
        
        printf("G.handcount is %d\n", G.handCount[p]);
        for (i = 0; i < G.handCount[p]; i++){
            if (G.hand[p][i] == copper || G.hand[p][i] == silver || G.hand[p][i] == gold){
                numTreasures++;
            }
        }
        printf("Testing for adventurer card player %d:\n", p);
        printf("Number of treasures is %d before playing card.\n", numTreasures);
        printf("Testing for adventurer for playcard(%d, 0, 0, 0, gameState):\n", temp);
        // play it
        playCard(temp, 0, 0, 0, &G);
        // we expect number of actions to be one less
        testActions--;
        // Reviewing the implementation of adventurer, we should always draw at least
        // 2 treasure cards. This is an error, but we can write the test anyway
        // Number of cards in hand should be net +1 after playing adventurer
        testHandCount++;
        // Check hand to verify the number of treasure cards has increased by 2
        for (i = 0; i < G.handCount[p]; i++){
            if (G.hand[p][i] == copper || G.hand[p][i] == silver || G.hand[p][i] == gold){
                numTreasuresPost++;
            }
        }

        #if (NOISY_TEST == 1)
        printf("Test actions updated correctly:\n");
        printf("Actions = %d, Expected = %d\n", G.numActions, testActions);
        printf("Test buys unchanged:\n");
        printf("Buys = %d, Expected = %d\n", G.numBuys, testBuys);
        printf("Test hand updated correctly:\n");
        printf("Hand = %d, Expected = %d\n", G.handCount[p], testHandCount);
        printf("Test number of treasures:\n");
        printf("numTreasuresPost = %d, Expected = %d\n", numTreasuresPost, numTreasures+2);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.numActions == testActions);
        assert(G.numBuys == testBuys);
        assert(G.handCount[p] == testHandCount);
        assert(numTreasuresPost == (numTreasures+2));
        #endif
        if (G.numActions != testActions) error = 1;
        if (G.numBuys != testBuys) error = 1;
        if (G.handCount[p] != testHandCount ) error = 1;
        if (numTreasuresPost != (numTreasures+2)) error = 1;

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
