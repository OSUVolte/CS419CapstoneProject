/*
* Michael Bamesberger
*
* randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
*      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
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
    
#define TESTCARD "adventurer"

int howManyCoins(struct gameState state, int p){
    
    int coinNum = 0;
    int i;
    
    for (i = 0; i < state.handCount[p]; i++){
        if (state.hand[p][i] == copper){
            coinNum = coinNum + 1;
            
        }
        else if (state.hand[p][i] == silver){
            coinNum = coinNum +2;
            
        }
        else if (state.hand[p][i] == gold){
            coinNum = coinNum + 3;
            
        }
        
    }
    
    
    return coinNum;
}
    
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
    seed = rand() % 6000;
        
    printf("----------------- Random Testing, Card: %s ----------------\n", TESTCARD);
    
    int numTests = 2000;
    int counter;
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
        result = cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
        
        //tests
        if (result != 0){
            printf("cardEffect returned an error");
            didItFail++;
        };
        
        if (howManyCoins(testG, p) == howManyCoins(G, p)){
            printf("Coin number Error: %d should be larger than %d\n", howManyCoins(testG, p), howManyCoins(G, p));
            didItFail++;
        };
        if (testG.handCount[p] != G.handCount[p] + 2){
            printf("Error: Adventurer should result in 2 cards. Instead drew %d\n", testG.handCount[p] - G.handCount[p]);
            didItFail++;
        };
        if (testG.deckCount[p] + testG.discardCount[p] !=
            G.deckCount[p] + G.discardCount[p] - 2){
            printf("Error: deckCount - discardCount should be %d, instead %d\n", G.deckCount[p] + G.discardCount[p] - 2, testG.deckCount[p] + testG.discardCount[p]);
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
