/*
 * Michael Bamesberger
 *
 * randomtestcard: randomtestcard.c dominion.o rngs.o
 *      gcc -o randomtestcard -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TESTCARD "Village"


int main() {
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int numPlayers;
    int seed;
    int bonus = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int handpos = 0;
    int didItFail = 0;
    int result;
    int p;
    srand(time(NULL));
    
    printf("----------------- Random Testing, Card: %s ----------------\n", TESTCARD);
    
    int numTests = 2000;
    int counter;
    seed = rand() % 5000;
    
    for (counter = 0; counter < numTests; counter++){
        
        struct gameState G, testG;
        
        numPlayers = rand() % (MAX_PLAYERS - 1 ) + 2;
        
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);
        
        p = floor(Random() * numPlayers);
        
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.whoseTurn = p;
        
        
        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        
        
        //Send to cardEffect
        result = cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
        
        //tests
        if (result != 0){
            printf("cardEffect returned an error");
            didItFail++;
        };
        
        if (testG.numActions != G.numActions + 2){
            printf("numActions error: Recieved %d, expecting %d\n", testG.numActions, G.numActions + 2);
                   didItFail++;
        };
        
        
        if (testG.deckCount[p] != G.deckCount[p] - 1 ){
            printf("Error: Deck count expected %d, actual %d\n", G.deckCount[p] - 1, testG.deckCount[p]);
            didItFail++;
        };
        
        if (testG.playedCardCount != G.playedCardCount + 1 ){
            printf("Error: Played Card Count expected %d, actual %d\n", G.playedCardCount +1, testG.playedCardCount);
            didItFail++;
        };
        
    }
    
    printf("ALL TESTS COMPLETED\n\n\n");
    if (didItFail == 0){
        printf("\n\nALL TESTS PASSED!!!\n\n");
    }
    else {
        printf("There were %d errors detected\n", didItFail);
        
    }
    
    
    return 0;
    
}