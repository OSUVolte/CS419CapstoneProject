#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"
int main(){
    
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int currentPlayer;
    int numPlayers = 2;
    int numTreasure = 0;
    int temphand[MAX_HAND];
    int z = 0;
    int i, j, m;
    int hand1, deck1, cardsPlayed;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int cardVal;
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, 2, &G);
    if( G.whoseTurn != 0 ){
        printf("FAIL - game was initialized incorrectly \n");
    }
    
    currentPlayer = G.whoseTurn;
    printf("\n Testing : %s \n", TESTCARD);
    
    G.hand[0][0] = adventurer;
    hand1 = G.handCount[0];
    deck1 = G.deckCount[0];
    
    for(i = 0; i < hand1; i ++){
        cardVal = G.hand[0][i];
        if ( cardVal >= 4 && cardVal <=6 ){
            numTreasure++;
        }
    }
    
    printf("\n numTreasure = %i", numTreasure);
    playAdventurer(0, &G, currentPlayer, temphand, z);
    
    int postNumTreasure = 0;
    int hand2 = G.handCount[0];
    deck1 = G.deckCount[0];
    
    for(i = 0; i < hand2; i ++){
        cardVal = G.hand[0][i];
        if ( cardVal >= 4 && cardVal <=6 ){
            postNumTreasure++;
        }
    }
    
    printf("\n postNumTreasure = %i\n", postNumTreasure);
    
    
    if( G.handCount[0] == hand1 + 1 ){
        printf("PASS -  Player received exactly 2 cards \n");
    }
    else{
        printf("FAIL -  Player did not receive exactly 2 cards \n");
    }
    
    if( postNumTreasure == ( numTreasure + 2 )){
        printf("PASS -  Player received exactly 2 treasure cards \n");
    }
    else{
        printf("FAIL -  Player did not receive exactly 2 treasure cards \n");
    }
    
    
    
    
    

    return 0;
}
