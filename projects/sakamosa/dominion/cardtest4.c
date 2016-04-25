#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//testing of getCost function

int main(){
    printf("*********************BEGIN UNIT TESTS OF OUTPOST*********************\n\n");
//compare returned value to correct value for each card type
    struct gameState T;
    int total_cards;
    int playerCount = T.handCount[0];
    int opponentCount = T.handCount[1];
    int playerDiscard = T.discardCount[0];
    int opponentDiscard = T.discardCount[1];
    int k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
    
    initializeGame(2, k, 5, &T);

    T.hand[0][0] = great_hall;
    T.outpostPlayed = 0;
    total_cards = T.handCount[0] + T.deckCount[0] + T.discardCount[0];

    cardEffect(outpost, 0, 0, 0, &T, 0, 0);

    //check that outposts were updated
     if(T.outpostPlayed != 1){
        printf("FAIL incorrect number of outposts played\n");
    }
    
    //check that one card has been discarded
    if(T.handCount[0] != playerCount - 1){
        printf("FAIL incorrect number of cards in player hand\n");
    }
    
    //check that the card was added to discard pile
    if(T.discardCount[0] != playerDiscard + 1){
        printf("FAIL incorrect number of cards in player discard pile\n");
    }
    
    //check that no cards were thrown away
    if(total_cards != T.handCount[0] + T.deckCount[0] + T.discardCount[0]){
        printf("FAIL total player cards is incorrect\n");
    }
    
    //check that nothing else has changed
    if(T.handCount[1] != opponentCount){
        printf("FAIL incorrect number of cards in player hand\n");
    }
    
    if(T.discardCount[1] != opponentDiscard){
        printf("FAIL incorrect number of cards in player discard pile\n");
    }
   

    printf("**********************TESTS COMPLETE*************************\n\n");
    return 0;

}

