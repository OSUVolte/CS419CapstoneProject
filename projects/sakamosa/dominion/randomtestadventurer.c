#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    //set the seed for random generation
    srand(time(NULL));
    int num_tests, fails;
    
     printf("*********************BEGIN RANDOM TESTING ADVENTURER *********************\n\n");
    for(num_tests = 0; num_tests < 500; num_tests++){
        numPlayers = (rand() % (MAX_PLAYERS - 1)) + 2;//Random num of players between 2 - max
        seed = rand() % 1234567 + 1;
        fails = 0;
    //compare returned value to correct value for each card type
        struct gameState T;
        int i, total_cards;
        int playerCount = T.handCount[0];
        int opponentCount = T.handCount[1];
        int playerDiscard = T.discardCount[0];
        int opponentDiscard = T.discardCount[1];
        int beg_count, end_count = 0;
        int k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};
        printf("Test #%d: num players = %d, seed = %d/n", num_tests, numPlayers, seed);
        //intialize game with random input        
        initializeGame(numPlayers, k, seed, &T);
        T.hand[0][0] = adventurer;
        total_cards = T.handCount[0] + T.deckCount[0] + T.discardCount[0];

        //count current treasure cards in hand
        for(i = 0; i < T.handCount[0]; i++){
            if(T.hand[0][i] == copper ||
                T.hand[0][i] == silver ||
                T.hand[0][i] == gold){
                    beg_count ++;
            }
        }
        //Play the adventurer card for the Test state player 0, position 0
        playAdventurer(&T, 0, 0);
    
        //check that two cards have added and one discarded
        if(T.handCount[0] != playerCount + 1){
            printf("FAIL incorrect number of cards in player hand\n");
            fails++;
        }

        //check that the treasure count has increased by 2
        for(i = 0; i < T.handCount[0]; i++){
            if(T.hand[0][i] == copper ||
                T.hand[0][i] == silver ||
                T.hand[0][i] == gold){
                    end_count ++;
            }
        }
        if(end_count != beg_count + 2){
            printf("FAIL two treasure cards were not added to hand\n");
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
        printf("Completed test #&d. Fails = %d\n", num_tests, fails);
    }

    printf("**********************TESTS COMPLETE*************************\n\n");
    return 0;

}

