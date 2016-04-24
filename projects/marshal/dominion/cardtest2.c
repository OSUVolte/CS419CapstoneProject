/*
 * cardtest2.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
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
    int numPlayers = 2, thisPlayer = 0, otherPlayer = 1;
    int newCards = 2, discarded = 1;
    int errors = 0;
    int seed = 1000;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int handpos = 0, bonus = 0;
    int testTreasureCount, realTreasureCount;
    int testHandCount, realHandCount;
    int handIndex, shuffledCards = 0;
    struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
    
    // initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
    //insert a adventurer card in players hand for testing
    G.hand[thisPlayer][0] = adventurer; 
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    // copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
    
    //get amount of treasure cards in hand before adventure card is played
    realHandCount = G.handCount[thisPlayer];  //get current num of cards in hand
    
    //print players hand for error checking. 
    realTreasureCount = 0;
//    if(realHandCount > 0) printf("#  Card\n");
    for(handIndex = 0; handIndex < realHandCount; handIndex++) {
        int card = G.deck[thisPlayer][handIndex];
        if(card == 4 || card == 5 || card == 6){
           realTreasureCount++;    
        }
    }
//    printf("Player %d's hand has %d treasure cards BEFORE:\n", thisPlayer, realTreasureCount);
//    printf("\n");  
    
    
    //call cardEffect
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    //check to see that 2 treasure cards 
    //test to make sure play is recieving 2 cards
    //and then discarding 1, resulting in the handCount
    //growing by 1
 //   printf("Player %d hand count = %d, expected = %d\n", thisPlayer, testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
        //check if hand is correct
            printf("****FAIL Player %d Returned Hand Count = %d, expected = %d\n", thisPlayer, testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded); 
            errors++;
    }
    
    //test to see that cards added are treasure cards
    //the enum for copper is 4, silver =5, and gold =6
    //get amount of treasure cards in hand before adventure card is played
    testHandCount = testG.handCount[thisPlayer];  //get current num of cards in hand
    
    //print players hand for error checking. 
    testTreasureCount = 0;
 //   if(testHandCount > 0) printf("#  Card\n");
    for(handIndex = 0; handIndex < testHandCount; handIndex++) {
        int card = testG.deck[thisPlayer][handIndex];
        if(card == 4 || card == 5 || card == 6){
           testTreasureCount++;    
        }
    }
//    printf("Player %d's test hand has %d treasure cards AFTER:\n", thisPlayer, testTreasureCount);
//    printf("\n");
//    printf("Player %d treasure count in hand= %d, expected = %d\n", thisPlayer, testTreasureCount, realTreasureCount+2);
    if(testTreasureCount != realTreasureCount+2){
        //check if hand is correct
            printf("****FAIL Player %d Returned Treasure Count in Hand = %d, expected = %d\n", thisPlayer, testTreasureCount, realTreasureCount+2); 
            errors++;
    }
    
    //
    //test to make sure player is drawing from their own pile
//    printf("Player %d deck count = %d, expected = %d\n", thisPlayer, testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
        //check if deck is correct
            printf("****FAIL Returned Deck Count for Player %d = %d, expected = %d\n", thisPlayer, testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards); 
            errors++;
    }
    
    //test to make sure other players game state has not changed
    //test to make sure other players hand is not changed
    int recievedResult = testG.handCount[otherPlayer];
    int expected = G.handCount[otherPlayer];
 //   printf("Player %d hand count = %d, expected = %d\n", otherPlayer, recievedResult, expected);
    if(recievedResult != expected){
        //check if hand is correct
            printf("****FAIL Returned Hand Count for Player %d = %d, expected = %d\n", otherPlayer, recievedResult, expected); 
            errors++;
    }
    
    //test to make sure other player deck is same and first player did not draw
    //from other players pile
//    printf("Player %d deck count = %d, expected = %d\n", otherPlayer, testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
    if(testG.deckCount[otherPlayer] != G.deckCount[otherPlayer]){
        //check if deck is correct
            printf("****FAIL Returned Deck Count for Player %d = %d, expected = %d\n", otherPlayer, testG.deckCount[thisPlayer], G.deckCount[thisPlayer]); 
            errors++;
    }
    
    //test to make sure victory card piles where untouched.
    //check curse
    if(testG.supplyCount[curse] != G.supplyCount[curse]){
         printf("****FAIL Curse Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[curse], G.supplyCount[curse]); 
            errors++;
    }
    //check estate
    if(testG.supplyCount[estate] != G.supplyCount[estate]){
         printf("****FAIL Estate Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[estate], G.supplyCount[estate]); 
            errors++;
    }
    //check duchy
    if(testG.supplyCount[duchy] != G.supplyCount[duchy]){
         printf("****FAIL Duchy Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[duchy], G.supplyCount[duchy]); 
            errors++;
    }
    //check province
    if(testG.supplyCount[province] != G.supplyCount[province]){
         printf("****FAIL Province Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[province], G.supplyCount[province]); 
            errors++;
    }
    
    //test to make sure the kingdom cards count have not been altered
    int i;
    for(i=0; i < 10; i++){
        if(testG.supplyCount[k[i]] != G.supplyCount[k[i]]){
         printf("****FAIL Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[k[i]], G.supplyCount[k[i]]); 
            errors++;
         printf("%d is incorrect\n", k[i]);    
        }
    }
    
    if(errors == 0){
     printf("ALL TESTS PASS for adventurer card.\n");   
    }
    else{
     printf("FAIL: There are %d errors for playing adventurer card.\n", errors);   
    }
 return 0; 
}