/* ---------------------------------------------------------------------
* Jon Patterson
* Assignment 3
* cardtest3.c
* council room card tests
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
    int p, r, i;
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
    // store values of other players hands to test afterward
    int *player_card = calloc(numPlayer, sizeof(int));

    for (p = 0; p < numPlayer; p++){
        player_card[i] = G.handCount[p];
    }

    
    printf ("Testing council_room for playCard(0, 0, 0, 0, gamestate):\n");
    p = 0;
	printf("Testing for player %d:\n", p);
    int testActions = G.numActions;
    int testBuys = G.numBuys;
    int testHandCount = G.handCount[p];
    int testDeckCount = G.deckCount[p];

    // make card in hand a council_room
    G.hand[p][0] = council_room;
    //play it
    playCard(0, 0, 0, 0, &G);

 	//Upon execution, adjust test values
 	//test actions should be one less
 	testActions--;
    //Buys are incremented by 1
    testBuys++;
 	//net hand count should now be +3
 	testHandCount += 3;
 	//deck count should be 3 less
 	testDeckCount -= 4;

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
    if (G.deckCount[p] != testDeckCount	) error = 1;
    if (G.handCount[p] != testHandCount	) error = 1;

    //test other players hands to ensure that they were incremented by one
    for(p = 1; p < numPlayer; p++){
        #if (NOISY_TEST == 1)
        printf("Checking the hands of other players:\n");
        printf("Player %d Hand = %d, Expected = %d\n", p, G.handCount[p], player_card[i]+1);
        #endif
        #if (ASSERTS_ON == 1)
        assert(G.handCount[p] == player_card[i]+1);
        #endif
        if(G.handCount[p] != player_card[i]+1) error = 1;
    }
    free(player_card);
    if(error == 1){
    	printf("Errors were encountered.\n");
    	return 1;
    }


    return 0;
}