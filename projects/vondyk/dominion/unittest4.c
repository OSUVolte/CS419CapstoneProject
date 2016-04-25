#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int i, j;               				// counter
  int p1, p2;            				// players
  int pos;          					// position
  int numPlayers = 2;     				// players for valid gamestate
  int numTests = 1;     				// large testing spread
  struct gameState og;     				// original gameState
  struct gameState testState;   		// test gameState
  int k[10] = {feast, gardens, embargo, remodel, tribute, mine, cutpurse, ambassador, great_hall, village};
  int result;         					// return test


  printf("*******  TESTING FUNCTION: discardCard  *******\n\n");
  
  for(i = 0; i < numTests; i++){
    
    // Set hand basics for the game
    pos = -1;
    p1 = 0;
    p2 = 1;


    // Ensure the card is added to played pile if trash flag is not set
    initializeGame(numPlayers, k, 1000, &og);
    og.hand[p1][0] = steward;
    og.hand[p1][1] = estate;
    og.hand[p1][2] = duchy;
    og.hand[p1][3] = province;
    og.hand[p1][4] = great_hall;
    memcpy(&testState, &og, sizeof(struct gameState));
    result = discardCard(province, p1, &testState, 0);  // trash flag false
    
	printf("\nTest 1: Card added to played pile if w/trash flag 0: \n");
    if(testState.playedCardCount == og.playedCardCount + 1)
      printf("Passed. Expected %d    Returned %d\n", og.playedCardCount + 1, testState.playedCardCount);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.playedCardCount + 1, testState.playedCardCount);

    
	// Check that player 2's hand remains unchanged
    printf("Test 2: Other player didn't gain to hand: \n");
    if(testState.handCount[p2] != og.handCount[p2])
      printf("FAILED. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
    else
      printf("Passed. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
   
    
	// Check that player 2's deck remains unchanged
    printf("Test 3: Other player didn't gain to deck: \n");
    if(testState.deckCount[p2] != og.deckCount[p2])
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
       printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    
	
	// Ensure the card is trashed and not added to the played pile when the trash flag is set
    initializeGame(numPlayers, k, 1000, &og);
    og.hand[p1][0] = steward;
    og.hand[p1][1] = estate;
    og.hand[p1][2] = duchy;
    og.hand[p1][3] = province;
    og.hand[p1][4] = great_hall;
    memcpy(&testState, &og, sizeof(struct gameState));
    result = discardCard(province, p1, &testState, 1);  // trash flag false
    
	printf("\nTest 4: Card not added to played pile if trash flag set: \n");
    if(testState.playedCardCount == og.playedCardCount)
      printf("Passed. Expected %d    Returned %d\n", og.playedCardCount, testState.playedCardCount);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.playedCardCount, testState.playedCardCount);
    
	
	// Check that player 2's hand remains unchanged 
    printf("Test 5: Other player didn't gain to hand: \n");
    if(testState.handCount[p2] != og.handCount[p2])
      printf("FAILED. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
    else
      printf("Passed. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
   
    
	// Check that player 2's deck remains unchanged
    printf("Test 6: Other player didn't gain to deck: \n");
    if(testState.deckCount[p2] != og.deckCount[p2])
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
       printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);


    // Ensure the card is removed from hand when the trash flag is not set
    initializeGame(numPlayers, k, 1000, &og);
    og.hand[p1][0] = steward;
    og.hand[p1][1] = estate;
    og.hand[p1][2] = duchy;
    og.hand[p1][3] = province;
    og.hand[p1][4] = great_hall;
    memcpy(&testState, &og, sizeof(struct gameState));
    result = discardCard(province, p1, &testState, 0); 
    int gone = 0; 
    
	printf("\nTest 7: Card is removed from hand when discarded: \n");
    for(j = 0; j < testState.handCount[p1]; j++){
      if(testState.hand[p1][j] == province)
        gone = 1;
    }
    if(gone != 1)
      printf("Passed. Card not found in hand.\n");
    else
      printf("Failed. Card found in hand.\n");

    
	// Check that player 2's hand remains unchanged 
    printf("Test 8: Other player didn't gain to hand: \n");
    if(testState.handCount[p2] != og.handCount[p2])
      printf("FAILED. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
    else
      printf("Passed. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
   
    
	// Check that player 2's deck remains unchanged
    printf("Test 9: Other player didn't gain to deck: \n");
    if(testState.deckCount[p2] != og.deckCount[p2])
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
       printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);

    
	// Ensure the card is removed from hand when the trash flag is set
    initializeGame(numPlayers, k, 1000, &og);
    og.hand[p1][0] = steward;
    og.hand[p1][1] = estate;
    og.hand[p1][2] = duchy;
    og.hand[p1][3] = province;
    memcpy(&testState, &og, sizeof(struct gameState));
    result = discardCard(province, p1, &testState, 1);   // gain feast in teststate, disard set for current player
    
	printf("\nTest 10: Card is removed from hand when trashed: \n");
    if(testState.handCount[p1] == og.handCount[p1] -1)
      printf("Passed. Expected %d    Returned %d\n", og.handCount[p1] -1, testState.handCount[p1]);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.handCount[p1] -1, testState.handCount[p1]);
    
    
	// Check that player 2's hand remains unchanged 
    printf("Test 11: Other player didn't gain to hand: \n");
    if(testState.handCount[p2] != og.handCount[p2])
      printf("FAILED. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
    else
      printf("Passed. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
   
    
	// Check that player 2's deck remains unchanged
    printf("Test 12: Other player didn't gain to deck: \n");
    if(testState.deckCount[p2] != og.deckCount[p2])
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
       printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);

    
	// Check if reduces to 0
    initializeGame(numPlayers, k, 1000, &og);
    og.hand[p1][0] = province;
    og.handCount[p1] = 1;
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.handCount[p1] = 1;
    result = discardCard(province, p1, &testState, 0);   // gain feast in teststate, disard set for current player
    
	printf("\nTest 13: One card in hand, will reduce to 0: \n");
    if(testState.handCount[p1] == og.handCount[p1] -1)
      printf("Passed. Expected %d    Returned %d\n", og.handCount[p1] -1, testState.handCount[p1]);
    else
      printf("FAILED. Expected %d    Returned %d\n", og.handCount[p1] -1, testState.handCount[p1]);
 
    
	// Check that player 2's hand remains unchanged 
    printf("Test 14: Other player didn't gain to hand: \n");
    if(testState.handCount[p2] != og.handCount[p2])
      printf("FAILED. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
    else
      printf("Passed. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
   
    
	// Check that player 2's deck remains unchanged
    printf("Test 15: Other player didn't gain to deck: \n");
    if(testState.deckCount[p2] != og.deckCount[p2])
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
       printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);


    // Check last card set if more cards available
    initializeGame(numPlayers, k, 1000, &og);
    og.hand[p1][0] = steward;
    og.hand[p1][1] = estate;
    og.hand[p1][2] = duchy;
    og.hand[p1][3] = province;
    og.hand[p1][4] = great_hall;
    memcpy(&testState, &og, sizeof(struct gameState));
    result = discardCard(province, p1, &testState, 0);   // gain feast in teststate, disard set for current player
    
	printf("\nTest 16: Makes sure if more cards available, last card set: \n");
    if( testState.hand[p1][testState.handCount[p1]] == -1)  // handcount decreased, now at handcount
      printf("Passed. Expected %d    Returned %d\n", -1, testState.hand[p1][testState.handCount[p1]]);
    else
      printf("FAILED. Expected %d    Returned %d\n", -1, testState.hand[p1][testState.handCount[p1]]);
  
    
	// Check that player 2's hand remains unchanged 
    printf("Test 17: Other player didn't gain to hand: \n");
    if(testState.handCount[p2] != og.handCount[p2])
      printf("FAILED. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
    else
      printf("Passed. Expected other user's hand to remain %d   It's now: %d\n", og.handCount[p2], testState.handCount[p2]);
   
    
	// Check that player 2's deck remains unchanged
    printf("Test 18: Other player didn't gain to deck: \n");
    if(testState.deckCount[p2] != og.deckCount[p2])
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
       printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);

  
    // Test for any victory cards given out inappropriately
    printf("\nTest 19: : Test supply counts for points and curses that should not have been distributed: \n");
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
    printf("\nTest 20: Test supply counts for treasure that should have been distributed: \n");
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