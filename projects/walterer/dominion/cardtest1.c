#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"
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
    printf("\n Testing : %s \n", TESTCARD);
    
    G.hand[0][0] = smithy;
    hand1 = G.handCount[0];
    deck1 = G.deckCount[0];

    
    
    playSmithy(currentPlayer, &G, 0, 0);
    
    if(G.handCount[0] == hand1 + 2){
        printf("PASS -  Player recieved exactly 3 cards \n");
    }
    else{
        printf("FAIL - Player did not receive exactly 3 cards \n");
    }
    
    if(G.deckCount[0] == deck1 - 2){
        printf("PASS - The cards were correctly pulled from the deck \n");
    }
    else{
        printf("FAIL - The cards were not correctly pulled from the deck \n");
    }
    
    
    
    
    
    
    return 0;
    
    
    
}