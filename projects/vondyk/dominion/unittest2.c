#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int i;            					// counter
  int p1, p2;          					// players
  int pos;          					// position
  int numPlayers = 2;     				// players for valid gamestate
  int numTests = 1;     				// large testing spread
  struct gameState og;     				// original gameState
  struct gameState testState;   		// test gameState
  int k[10] = {feast, gardens, embargo, remodel, tribute, mine, cutpurse, ambassador, great_hall, village};
  int result;         					// return test


  printf("*******   TESTING FUNCTION: gainCard   *******\n\n");
  
  for(i = 0; i < numTests; i++){
    
    // Set hand basics for the game
    pos = -1;
    p1 = 0;
    p2 = 1;

	
    // Test if the pile is empty
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.supplyCount[feast] = 0;  								// No feast in supply
    result = gainCard(feast, &testState, 0, p1);   					// Gain feast in teststate, discard set for current player
    printf("Test 1: Cannot gain a card which is out of stock: \n");
    if(result == -1)
      printf("Passed. Expected %d    Returned %d\n", -1, result);
    else
      printf("FAILED. Expected %d    Returned %d\n", -1, result);


    // Test if the card is not in the game
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    result = gainCard(sea_hag, &testState, 0, p1);   				// Not in game
    printf("\nTest 2: Cannot gain a card which is not in game: \n");
    if(result == -1)
      printf("Passed. Expected %d    Returned %d\n", -1, result);
    else
      printf("FAILED. Expected %d    Returned %d\n", -1, result);

	
    
	// Test if the card is added to the deck
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    result = gainCard(feast, &testState, 1, p1);   					// Gain feast in teststate
    printf("\nTest 3: Flag One, Card is added to player 1's deck: \n");
    if(testState.deckCount[p1] == og.deckCount[p1] +1)
      printf("Passed. Expected %d    Returned %d\n", og.deckCount[p1] +1, testState.deckCount[p1]);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.deckCount[p1] +1, testState.deckCount[p1]);
    
	
	// Make sure the card didn't go to the player 2's deck
    if(testState.deckCount[p2] != og.deckCount[p2])
      printf("FAILED. Expected player 2's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    
	
	// Make sure the card is added to the hand
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    result = gainCard(feast, &testState, 2, p1);   					// Gain feast in teststate, disard set for current player
    printf("\nTest 4: Flag Two, Card is added to player 1's hand: \n");
    if(testState.handCount[p1] == og.handCount[p1] +1)
      printf("Passed. Expected %d    Returned %d\n", og.handCount[p1] +1, testState.handCount[p1]);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.handCount[p1] +1, testState.handCount[p1]);
    
	
	// Check that the card didn't go into player 2's deck
    if(testState.handCount[p2] != og.handCount[p2])
      printf("FAILED. Expected player 2's deck to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);

	
	// Make sure the card is discarded
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    result = gainCard(feast, &testState, 0, p1);   					// Gain feast in teststate, disard set for current player
    printf("\nTest 5: Flag zero, Card is discarded: \n");
    if(testState.discardCount[p1] == og.discardCount[p1] +1)
      printf("Passed. Expected %d    Returned %d\n", og.discardCount[p1] +1, testState.discardCount[p1]);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.discardCount[p1] +1, testState.discardCount[p1]);

    
	// Check that the card didn't go into player 2's deck
    if(testState.discardCount[p2] != og.discardCount[p2])
      printf("FAILED. Expected player 2's deck to remain %d   It's now: %d\n", og.discardCount[p2], testState.discardCount[p2]);


	// Make supply count decrease
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    result = gainCard(feast, &testState, 0, p1);   					// Gain feast in teststate, disard set for current player
    printf("\nTest 6: Supply count is decreased: \n");
    if(testState.supplyCount[feast] == og.supplyCount[feast] -1)
      printf("Passed. Expected %d    Returned %d\n", og.supplyCount[feast] -1, testState.supplyCount[feast]);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.supplyCount[feast] -1, testState.supplyCount[feast]);
	
    
	// Test for any victory cards given out inappropriately
    printf("\nTest 7: : Test supply counts for points and curses that should not have been distributed: \n");
    if(og.supplyCount[estate] != testState.supplyCount[estate])
      printf("FAILED. Estate Count Mismatch. Expected: %d  Received: %d\n", og.supplyCount[estate], testState.supplyCount[estate]);
    if(og.supplyCount[duchy] != testState.supplyCount[duchy])
      printf("FAILED. Duchy Count Mismatch. Expected: %d  Received: %d\n", og.supplyCount[duchy], testState.supplyCount[duchy]);
    if(og.supplyCount[province] != testState.supplyCount[province])
      printf("FAILED. Province Count Mismatch. Expected: %d  Received: %d\n", og.supplyCount[province], testState.supplyCount[province]);
    if(og.supplyCount[curse] != testState.supplyCount[curse])
      printf("FAILED. Province Count Mismatch. Expected: %d  Received: %d\n", og.supplyCount[curse], testState.supplyCount[curse]);
    else
      printf("Passed. Supply counts for curses and victory cards are correct\n");
    
	
	// Test for changes in money supply that shouldn't happen
    printf("\nTest 8: Test supply counts for treasure that should have been distributed: \n");
    if(og.supplyCount[copper] != testState.supplyCount[copper])
      printf("FAILED. Copper Count Mismatch. Expected: %d  Received: %d\n\n", og.supplyCount[copper], testState.supplyCount[copper]);
    if(og.supplyCount[silver] != testState.supplyCount[silver])
      printf("FAILED. Silver Count Mismatch. Expected: %d  Received: %d\n\n", og.supplyCount[silver], testState.supplyCount[silver]);
    if(og.supplyCount[gold] != testState.supplyCount[gold])
      printf("FAILED. Gold Count Mismatch. Expected: %d  Received: %d\n\n", og.supplyCount[gold], testState.supplyCount[gold]);
    else
      printf("Passed. Supply counts for treasure cards are correct\n\n");

  }
  return 0;
}
