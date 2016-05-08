/*
*Alex Marsh
*CS362
*randomtestcard.c
*Last Modified: May 7, 2016
*
*This is a random test for the implementation of the village card in dominion.c. Format and some code taken from 'betterTestDrawCard.c' and 'cardtest2.c'
*
*When a player plays this card the player should gain 1 card and 
*two actions.
*
*
*Include the following lines in your makefile:
*
*randomtestcard.c: randomtestcard.c dominion.o rngs.o
*       gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTCARD "village"

int main() {
    int i, coins;
    int currPlayer, otherPlayer;
    int seed = 1000;
    int numPlayers = 2;
    int newCards = 2, discarded = 1;
    int num_copper = 60;
    int num_silver = 40;
    int num_gold = 30;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int handpos, bonus = 0;
    int errors = 0;
    int testTreasureCount = 0, realTreasureCount = 0;
    int testHandCount, realHandCount;
    int handIndex, shuffledCards = 0;


    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G, expected, played;

  printf("--------------Testing village Randomly--------------\n");
    
  srand(time(NULL)); //set rand
     
  SelectStream(2);
  PutSeed(3);    
    
  for(i=0; i<2000; i++){
    // initialize game environment & begin testing
    initializeGame(numPlayers, k, seed, &G);
    memcpy(&played, &G, sizeof(struct gameState));
    
    //initialize a random game 
    currPlayer = rand() % numPlayers; //get random player
    if(currPlayer == 0){
      otherPlayer = 1;   
    }
    else
        otherPlayer = 2;
      
    played.whoseTurn = currPlayer; //set player
     
    //randomize deck, hand, and discard  
    played.deckCount[currPlayer] = (rand() % (MAX_DECK+1));
    played.discardCount[currPlayer] = (rand() % ( MAX_DECK+1));
    played.handCount[currPlayer] = (rand() %  (MAX_HAND+1));
    
    //get random number for handposition
    handpos  = (rand() % 7);
      
    //insert a adventure card in players hand for testing
    played.hand[currPlayer][handpos] = village;   
      
    //randomize the number of coins 
    coins = (rand() % (num_copper + 1)); //copper coins
    //printf("coins = %d\n", coins);
    coins =+ (rand() % (num_silver +1)); //silver coins
    //printf("coins = %d\n", coins);
    coins =+ (rand() % (num_gold+1)); //gold coins
    //printf("coins = %d\n", coins);
      
    played.coins = coins;  

    //copy random test state for testing  
    memcpy(&expected, &played, sizeof(struct gameState));
  
 /***     
    //test printing
    printf("%d player handcount %d:\n", currPlayer, played.deckCount[currPlayer]);   
    printf("%d player deckcount %d:\n", currPlayer, played.deckCount[currPlayer]);   
    printf("%d player discardcount %d:\n", currPlayer, played.discardCount[currPlayer]);   
    printf("%d player coins %d:\n", currPlayer, countHandCoins(currPlayer, &played));   
    printf("*******************************************************\n");  
  
    printf("%d player handcount %d:\n", currPlayer, expected.deckCount[currPlayer]);   
    printf("%d player deckcount %d:\n", currPlayer, expected.deckCount[currPlayer]);   
    printf("%d player discardcount %d:\n", currPlayer, expected.discardCount[currPlayer]);   
    printf("%d player coins %d:\n", currPlayer, countHandCoins(currPlayer, &expected));   
    printf("*******************************************************\n");  
 ***/   
      
    //play village card
    cardEffect(village, choice1, choice2, choice3, &played, handpos, bonus); 
      
      
    //test to make sure play is recieving 1 cards
    //the player should draw 1 card and discard the village card
    //this should make the hand the same count
    
 //   printf("Player %d hand count = %d, expected = %d\n", currPlayer, recievedResult, expected);
    if(played.handCount[currPlayer] != expected.handCount[currPlayer] + newCards - discarded){
        //check if hand is correct
            printf("****FAIL Iteration: %d Returned Hand Count = %d, expected = %d\n", i, played.handCount[currPlayer], expected.handCount[currPlayer] + newCards - discarded); 
            errors++;
    }
    
    //test to make sure player is drawing from their own pile
 //   printf("Player %d deck count = %d, expected = %d\n", currPlayer, played.deckCount[currPlayer], expected.deckCount[currPlayer] - newCards + shuffledCards);
    if(played.deckCount[currPlayer] != expected.deckCount[currPlayer] - newCards + shuffledCards){
        //check if deck is correct
            printf("****FAIL Iteration: %d Returned Deck Count for Player %d = %d, expected = %d\n", i, currPlayer, played.deckCount[currPlayer], expected.deckCount[currPlayer] - newCards + shuffledCards); 
            errors++;
    }
    
    //test for players number of actions
    //the player shoud have 2 action moves
 //   printf("Player %d action count = %d, expected = %d\n", currPlayer, played.numActions, expected.numActions+2);
    if(played.numActions != expected.numActions+2){
        //check if deck is correct
            printf("****FAIL Iteration: %d Returned Action Count for Player %d = %d, expected = %d\n", i, currPlayer, played.numActions, expected.numActions+2); 
            errors++;
    }
    
        //test to make sure other players game state has not changed
    
    //test to make sure other players hand is not changed
    
 //   printf("Player %d hand count = %d, expected = %d\n", otherPlayer, recievedResult, expected);
    if(played.handCount[otherPlayer] != expected.handCount[otherPlayer]){
        //check if hand is correct
            printf("****FAIL Iteration: %d Returned Hand Count for Player %d = %d, expected = %d\n", i, otherPlayer, played.handCount[otherPlayer], expected.handCount[otherPlayer]); 
            errors++;
    }
    
    //test to make sure other player deck is same and first player did not draw
    //from other players pile
//    printf("Player %d deck count = %d, expected = %d\n", otherPlayer, played.deckCount[otherPlayer], expected.deckCount[otherPlayer]);
    if(played.deckCount[otherPlayer] != expected.deckCount[otherPlayer]){
        //check if deck is correct
            printf("****FAIL Iteration: %d Returned Deck Count for Player %d = %d, expected = %d\n", i, otherPlayer, played.deckCount[currPlayer], expected.deckCount[currPlayer]); 
            errors++;
    }
    
    //test to make sure victory card piles where untouched.
    //check curse
    if(played.supplyCount[curse] != expected.supplyCount[curse]){
         printf("****FAIL Iteration: %d Curse Count for Player %d = %d, expected = %d\n", i, currPlayer, played.supplyCount[curse], expected.supplyCount[curse]); 
            errors++;
    }
    //check estate
    if(played.supplyCount[estate] != expected.supplyCount[estate]){
         printf("****FAIL Iteration: %d Estate Count for Player %d = %d, expected = %d\n", i, currPlayer, played.supplyCount[estate], expected.supplyCount[estate]); 
            errors++;
    }
    //check duchy
    if(played.supplyCount[duchy] != expected.supplyCount[duchy]){
         printf("****FAIL Iteration: %d Duchy Count for Player %d = %d, expected = %d\n", i, currPlayer, played.supplyCount[duchy], expected.supplyCount[duchy]); 
            errors++;
    }
    //check province
    if(played.supplyCount[province] != expected.supplyCount[province]){
         printf("****FAIL Iteration: %d Province Count for Player %d = %d, expected = %d\n", i, currPlayer, played.supplyCount[province], expected.supplyCount[province]); 
            errors++;
    }
    
    //test to make sure the kingdom cards count have not been altered
    int i;
    for(i=0; i < 10; i++){
        if(played.supplyCount[k[i]] != expected.supplyCount[k[i]]){
         printf("****FAIL Iteration: %d Count for Player %d = %d, expected = %d\n", i, currPlayer, played.supplyCount[k[i]], expected.supplyCount[k[i]]); 
            errors++;
         printf("%d is incorrect\n", k[i]);    
        }
    }
    
    
    
  }
    
    
    
    
    if(errors == 0){
     printf("ALL TESTS PASS for village card.\n");   
    }
    else{
     printf("FAIL: There are %d errors for playing village card.\n", errors);   
    }  
      
      
      
      
      
    return 0; 
}
