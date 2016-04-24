#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"
int main(){
    
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int currentPlayer;
    int numPlayers = 2;
    
    int i, j, m;
    int hand1, deck1, cardsPlayed;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, 2, &G);
    if(G.whoseTurn != 0){
        printf("FAIL - game was initialized incorrectly \n");
    }
    
    currentPlayer = G.whoseTurn;
    printf("\n Testing: %s \n ", TESTCARD);
    
    G.hand[0][0] = village;
    
    hand1 = G.handCount[0];
    deck1 = G.deckCount[0];
    
    int numActions = G.numActions;
    
    playVillage(currentPlayer, &G, 0);
    
    if(G.handCount[0] == hand1){
        printf("PASS - The handCounts are the same because 1 card was drawn and 1 was discarded \n");
    }
    else{
        printf("FAIL - The handCounts are the different \n");
    }
    
    if(G.numActions == (numActions + 2)){
        printf("PASS - The Actions were incremented correctly \n");
    }
    else{
        printf("FAIL - The Actions were not incremented correctly \n");

    }


    
    return 0;
}