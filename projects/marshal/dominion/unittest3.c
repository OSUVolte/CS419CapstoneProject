/* -----------------------------------------------------------------------
 * Name: Alex Marsh
 * CS362
 * unittest3.c
 * This tests the function fullDeckCount() function in dominion.c
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */


#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
//to include printfs set to 1
#define NOISY_TEST 0

int main(){
    int numPlayer = 2;
    int seed = 1000;
    int expected, returnedCount;
    int i, p, r;
    int numOfCards;
    int errors = 0;
    //to test the function adds correctly we add the same
    //amount of cards to each hand, deck, or discard.
    //MAX_HAND = 500 and divided by 3 is 166
    int equalDivCards = 166;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    printf("----------------- Testing fullDeckCount() ----------------\n");

    printf("\n");
    
 //   printf("Testing for cards in hand, deck, and discard:\n");
    for (p = 0; p <numPlayer; p++){
        for(numOfCards = 0; numOfCards <= equalDivCards; numOfCards++){
//        printf("Test player %d with %d card(s).\n", p, numOfCards);
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        
        //set the amount of cards in each pile    
        G.handCount[p] = numOfCards;
        G.deckCount[p] = numOfCards;
        G.discardCount[p] = numOfCards;    
        
        //set all the cards in players hand to the appropriate card
        int cardNum;
        for(cardNum = 0; cardNum <= numOfCards; cardNum++){
            G.hand[p][cardNum] = copper; 
            G.discard[p][cardNum] = copper;     
            G.deck[p][cardNum] = copper;    
        }    
            
        returnedCount = fullDeckCount(p, copper, &G);    
        
        expected =  numOfCards * 3; 
        if(returnedCount != expected){//check if score is correct
            printf("****FAIL Returned Count = %d, expected = %d\n", returnedCount, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1)
        else{
            printf("PASS Returned Count = %d, expected = %d\n", returnedCount, expected);}    
#endif            
        }
    }
    
 //   printf("Testing for cards only in hand:\n");
    for (p = 0; p <numPlayer; p++){
        for(numOfCards = 0; numOfCards <= equalDivCards; numOfCards++){
//        printf("Test player %d with %d card(s).\n", p, numOfCards);
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        
        //set the amount of cards in each pile    
        G.handCount[p] = numOfCards;
        G.deckCount[p] = numOfCards;
        G.discardCount[p] = numOfCards;    
        
        //set all the cards in players hand to the appropriate card
        int cardNum;
        for(cardNum = 0; cardNum <= numOfCards; cardNum++){
            G.hand[p][cardNum] = copper; 
            G.discard[p][cardNum] = estate;     
            G.deck[p][cardNum] = estate;    
        }    
            
        returnedCount = fullDeckCount(p, copper, &G);    
        
        expected =  numOfCards; 
        if(returnedCount != expected){//check if score is correct
            printf("****FAIL Returned Count = %d, expected = %d\n", returnedCount, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1) 
        else{
            printf("PASS Returned Count = %d, expected = %d\n", returnedCount, expected);}    
#endif            
        }
    }
    
 //   printf("Testing for cards only in deck:\n");
    for (p = 0; p <numPlayer; p++){
        for(numOfCards = 0; numOfCards <= equalDivCards; numOfCards++){
//        printf("Test player %d with %d card(s).\n", p, numOfCards);
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        
        //set the amount of cards in each pile    
        G.handCount[p] = numOfCards;
        G.deckCount[p] = numOfCards;
        G.discardCount[p] = numOfCards;    
        
        //set all the cards in players hand to the appropriate card
        int cardNum;
        for(cardNum = 0; cardNum <= numOfCards; cardNum++){
            G.hand[p][cardNum] = estate; 
            G.discard[p][cardNum] = estate;     
            G.deck[p][cardNum] = copper;    
        }    
            
        returnedCount = fullDeckCount(p, copper, &G);    
        
        expected =  numOfCards; 
        if(returnedCount != expected){//check if score is correct
            printf("****FAIL Returned Count = %d, expected = %d\n", returnedCount, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1) 
        else{
            printf("PASS Returned Count = %d, expected = %d\n", returnedCount, expected);}    
#endif            
        }
    }
    
 //   printf("Testing for cards only in discard:\n");
    for (p = 0; p <numPlayer; p++){
        for(numOfCards = 0; numOfCards <= equalDivCards; numOfCards++){
 //       printf("Test player %d with %d card(s).\n", p, numOfCards);
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        
        //set the amount of cards in each pile    
        G.handCount[p] = numOfCards;
        G.deckCount[p] = numOfCards;
        G.discardCount[p] = numOfCards;    
        
        //set all the cards in players hand to the appropriate card
        int cardNum;
        for(cardNum = 0; cardNum <= numOfCards; cardNum++){
            G.hand[p][cardNum] = estate; 
            G.discard[p][cardNum] = copper;     
            G.deck[p][cardNum] = estate;    
        }    
            
        returnedCount = fullDeckCount(p, copper, &G);    
        
        expected =  numOfCards; 
        if(returnedCount != expected){//check if score is correct
            printf("****FAIL Returned Count = %d, expected = %d\n", returnedCount, expected); 
            errors++;
        }  
#if (NOISY_TEST == 1) 
        else{
            printf("PASS Returned Count = %d, expected = %d\n", returnedCount, expected);}    
#endif            
        }
    }

    if(errors == 0){
     printf("ALL TESTS PASS for fullDeckCount().\n");   
    }
    else{
     printf("FAIL: There are %d errors.\n",errors);   
    }
    
 return 0;   
}