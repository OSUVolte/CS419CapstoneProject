#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
   //set the seed for random generation
    srand(time(NULL));
    int num_tests, fails, numPlayers, seed;
    
     printf("*********************BEGIN RANDOM TESTING GREAT HALL *********************\n\n");
    for(num_tests = 0; num_tests < 500; num_tests++){
        numPlayers = (rand() % (MAX_PLAYERS - 1)) + 2;//Random num of players between 2 - max
        seed = rand() % 1234567 + 1;
        fails = 0;
        printf("***************************************************\n");
        printf("Test #%d: num players = %d, seed = %d\n", num_tests, numPlayers, seed);
    struct gameState T;
    int total_cards;
    int playerCount = T.handCount[0];
    int opponentCount = T.handCount[1];
    int playerDiscard = T.discardCount[0];
    int opponentDiscard = T.discardCount[1];
    int k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
    
    initializeGame(numPlayers, k, seed, &T);
    int pre_actions = T.numActions;
   

    T.hand[0][0] = great_hall;
    total_cards = T.handCount[0] + T.deckCount[0] + T.discardCount[0];

    cardEffect(great_hall, 0, 0, 0, &T, 0, 0);
   
    //check that one card has been added and one discarded
    if(T.handCount[0] != playerCount){
        printf("FAIL incorrect number of cards in player hand\n");
        fails++;
    }
    
    //check that actions are increased
    if(T.numActions != pre_actions + 1){
        printf("FAIL incorrect number of action cards\n");
        fails++;
    }

    //check that the card was added to discard pile
    if(T.discardCount[0] != playerDiscard + 1){
        printf("FAIL incorrect number of cards in player discard pile\n");
        fails++;
    }
    
    //check that no cards were thrown away
    if(total_cards != T.handCount[0] + T.deckCount[0] + T.discardCount[0]){
        printf("FAIL total player cards is incorrect\n");
        fails++;
    }
    
    //check that nothing else has changed
    if(T.handCount[1] != opponentCount){
        printf("FAIL incorrect number of cards in player hand\n");
        fails++;
    }
    
    if(T.discardCount[1] != opponentDiscard){
        printf("FAIL incorrect number of cards in player discard pile\n");
        fails++;
    }
   printf("Completed test #%d. Fails = %d\n", num_tests, fails);
    }

    printf("**********************TESTS COMPLETE*************************\n\n");
    return 0;

}

