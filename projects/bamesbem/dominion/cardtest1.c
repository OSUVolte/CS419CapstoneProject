/*
* Include the following lines in your makefile:
*
* cardtest4: cardtest4.c dominion.o rngs.o
*      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: +3 cards --------------
    printf("TEST 1: player 0 = +3 cards\n");
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    //Send to cardEffect
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    newCards = 3;
    
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
 
    if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded){
        printf("handcount test passed\n");
    }
    else{
        printf("handcount test failed\n");
    }
    if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards){
        printf("deck count test passed\n");
    }
    else{
        printf("deck count test failed\n");
    }

    printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}

