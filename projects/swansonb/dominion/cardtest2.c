#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include "rngs.h"
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {

    // Testing for playAdventurer function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Testing dominion.c int playAdventurer()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");


    const int NUM_TESTS = 30;
    const int CARDS_IN_DECK_AT_START = 15;
    int seed = 1000;
    int testsRun = 0;
    int testsPassed = 0;
    int numPlayers = 4;
    struct gameState G, before, after;
    int i;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy, council_room};


    for (i=0; i<NUM_TESTS; ++i){
        curPlayer = i%numPlayers;
        initializeGame(numPlayers, k, seed, &G);

        //after play players hand should have 2 extra treasure cards in hand
        //the rest of cards should be in discard
    }







    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;
}
