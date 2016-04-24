/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* cardtest2.c
* adventurer card tests
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

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int error;

    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    // ensure that the values of all of the supply cards are are at least 2
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
    // first, we'll make a card in hand adventurer
    G.hand[p][0] = adventurer;
    printf("G.handcount is %d\n", G.handCount[p]);
    for (i = 0; i < G.handCount[p]; i++){
        if (G.hand[p][i] == copper || G.hand[p][i] == silver || G.hand[p][i] == gold){
            numTreasures++;
        }
    }
    printf ("Number of treasures is %d before playing card.\n", numTreasures);
    printf ("Playing card...\n");
    // play it
    playCard(0, 0, 0, 0, &G);
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
    if(error == 1){
        printf("Errors were encountered.\n");
        return 1;
    }

    return 0;
}
