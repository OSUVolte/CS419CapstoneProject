#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>


#define MAX_NUM_TESTS 2


int main(){
    
    
    printf("\n\n TESTING SMITHY \n\n");
    srand(time(NULL));
    
    int gameNumber, player, randomSeed, numPlayers, i, handPos, preDeck, postDeck, preDiscard, postDiscard, preHand, postHand;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int deckFail = 0;
    int discardFail = 0;
    int handFail = 0;
    int totalTests = 0;
    
    
    struct gameState preGame, postGame;
    memcpy(&preGame, &postGame, sizeof(struct gameState));
    
    
    /* Cycle through all of the games */
    for(gameNumber = 0; gameNumber < MAX_NUM_TESTS; gameNumber++){
        
        
        memcpy(&preGame, &postGame, sizeof(struct gameState));
        numPlayers = (rand() % MAX_PLAYERS) + 1;
        randomSeed = (rand() % 500) + 1;
        
        printf("\n Number of players = %i \n", numPlayers);
        initializeGame(numPlayers, k, randomSeed, &preGame);
        
        
        /* Cycle through all of the players */
        for(player = 0; player <  numPlayers; player++){
            
            /* Set random number for the deck */
            preGame.deckCount[player] = setRandomValue();
            
            /* Fill the deck with random cards */
            for(i = 0; i < preGame.deckCount[player]; i++){
                preGame.deck[player][i] = getRandomCard();
            }
            
            /* Set random number for the discard pile */
            preGame.discardCount[player] = setRandomValue();
            
            /* Fill the discard pile with random cards */
            for(i = 0; i < preGame.discardCount[player]; i++){
                preGame.deck[player][i] = getRandomCard();
            }
            
            /* Set random number for the hand count */
            preGame.handCount[player] = setRandomValue();
            
            /* Fill the hand with random cards */
            for(i = 0; i < preGame.handCount[player]; i++){
                preGame.hand[player][i] = getRandomCard();
            }
            
            /* Find the number of cards Pre */
            
            printf("Deck Count Pre = %i \n", preGame.deckCount[player]);
            printf("Discard Count Pre = %i \n", preGame.discardCount[player]);
            printf("Hand Count Pre = %i \n", preGame.handCount[player]);
            
            preDeck = preGame.deckCount[player];
            preDiscard = preGame.discardCount[player];
            preHand = preGame.handCount[player];
            
            
            handPos = rand() % preGame.handCount[player];
            preGame.hand[player][handPos] = adventurer;
            
            
            preGame.whoseTurn = player;
            
            /* Play the adventurer card to see the behavior */
            playSmithy(player, &preGame, handPos, 0);
        
            
            /* Find the number of cards Post */
            printf("Deck Count Post = %i \n", preGame.deckCount[player]);
            printf("Discard Count Post = %i \n", preGame.discardCount[player]);
            printf("Hand Count Post = %i \n", preGame.handCount[player]);
            
            postDeck = preGame.deckCount[player];
            postDiscard = preGame.discardCount[player];
            postHand = preGame.handCount[player];
            
            /* Count all of the tests */
            totalTests++;
            
            /* Check to make sure that the deck has decreased */
            if( postDeck < preDeck ){
                printf("PASS -- Deck count was properly decreased \n");
            }
            else{
                printf("FAIL -- Deck count was not properly decreased \n");
                deckFail++;
            }
            
            /* Check to make sure that the discard pile has gained cards */
            if( preDiscard < postDiscard ){
                printf("PASS -- Discard count was properly increased \n");
            }
            else{
                printf("FAIL -- Discard count was not properly increased \n");
                discardFail++;
            }
            
            /* Check to make sure that the player has two more cards in hand */
            if( postHand == preHand + 2){
                printf("PASS -- Hand was increased properly by 2 \n");
            }
            else{
                printf("FAIL -- Hand was not properly increased \n");
                handFail++;
            }
            
        }
    }
    
    /* Calculate and print out failure percentages for each count */
    
    double deckPercentageFail = ((double)deckFail/(double)totalTests) * 100;
    double discardPercentageFail = ((double)discardFail/(double)totalTests) * 100;
    double handPercentageFail = ((double)handFail/(double)totalTests) * 100;
    
    
    
    
    printf("Deck Count failed %f percent of the time \n", deckPercentageFail);
    printf("Discard Count failed %f percent of the time \n", discardPercentageFail);
    printf("Hand Count failed %f percent of the time \n", handPercentageFail);
    
    
    
    return 0;
    
    
}


int setRandomValue(){
    
    return rand() % 500;
    
}

int getRandomCard(){
    
    return rand() % 13;
}

