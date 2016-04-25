/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
    
    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int z;
    int drawntreasure = 0;
    int expectedtreasure = 0;
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
    
    // ----------- TEST 1: --------------
    printf("TEST 1: Draw two treasure cards \n");
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));

    //Send to playAdventurer
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    
    // Get amount of treasure in deck previous
    for (i = 0; i < testG.handCount[0]; i++)
    {
        if (testG.hand[0][i] == copper || testG.hand[0][i] == silver || testG.hand[0][i] == gold)
        {
            drawntreasure++;
        }
    }
    
    for (i = 0; i < G.handCount[0]; i++)
    {
        if (G.hand[0][i] == copper || G.hand[0][i] == silver || G.hand[0][i] == gold)
        {
            expectedtreasure++;
        }
    }
    
    printf("Treasure in hand: actual %d, expected %d\n", drawntreasure, expectedtreasure + 2);
    if (drawntreasure == expectedtreasure + 2){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    
    // ----------- TEST 2: --------------
    printf("TEST 2: Deck count should reflect loss of treasure cards \n");
    
    printf("Deck Count: actual %d, expected %d\n", testG.deckCount[0], G.deckCount[0] - 2);
    
    if (testG.deckCount[0] == G.deckCount[0] - 2){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    
    // ----------- TEST 3: --------------
    printf("TEST 3: Hand count should reflect addition of treasure cards \n");
    
    printf("Deck Count: actual %d, expected %d\n", testG.handCount[0], G.handCount[0] + 2);
    
    if (testG.deckCount[0] == G.deckCount[0] - 2){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
 

    
    return 0;
    
}