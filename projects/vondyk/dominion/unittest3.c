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
  int amount = 0; 						// update coins sets coins to 0

  printf("*******   TESTING FUNCTION: updateCoins   *******\n\n");
  
  for(i = 0; i < numTests; i++){
    
    // Set hand basics for the game
    pos = -1;
    p1 = 0;
    p2 = 1;


    // Test impact of copper on coin count
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.hand[p1][0] = feast;
    testState.hand[p1][1] = gardens;
    testState.hand[p1][2] = embargo;
    testState.hand[p1][3] = copper;
    testState.hand[p1][4] = mine;
    updateCoins(p1, &testState, 0);
    printf("Test 1: Copper increases coins by 1: \n");
    if(testState.coins == amount + 1)
      printf("Passed. Expected %d    Returned %d\n", amount +1, testState.coins);
    else
      printf("FAILED.  Expected %d    Returned %d\n", amount +1, testState.coins);

    
	// Test that player 2's deck did not change
    printf("\nTest 2: Other player gained nothing to deck: \n");
    if(testState.deckCount[p2] == og.deckCount[p2])
      printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);

	
	// Test impact of silver on coin count
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.hand[p1][0] = feast;
    testState.hand[p1][1] = gardens;
    testState.hand[p1][2] = embargo;
    testState.hand[p1][3] = silver;
    testState.hand[p1][4] = mine;
    updateCoins(p1, &testState, 0);
    printf("Test 3: Silver increases coins by 2: \n");
    if(testState.coins == amount +2)
      printf("Passed. Expected %d    Returned %d\n", amount +2, testState.coins);
    else
      printf("FAILED.  Expected %d    Returned %d\n", amount +2, testState.coins);

    
	// Test that player 2's deck did not change
    printf("\nTest 4: Other player gained nothing to deck: \n");
    if(testState.deckCount[p2] == og.deckCount[p2])
      printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);


    // Test impact of gold on coin count
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.hand[p1][0] = feast;
    testState.hand[p1][1] = gardens;
    testState.hand[p1][2] = embargo;
    testState.hand[p1][3] = gold;
    testState.hand[p1][4] = mine;
    updateCoins(p1, &testState, 0);
    printf("Test 5: Gold increases coins by 3: \n");
    if(testState.coins == amount +3)
      printf("Passed. Expected %d    Returned %d\n", amount +3, testState.coins);
    else
      printf("FAILED.  Expected %d    Returned %d\n", amount +3, testState.coins);

    
	// Test that player 2's deck did not change
    printf("\nTest 6: Other player gained nothing to deck: \n");
    if(testState.deckCount[p2] == og.deckCount[p2])
      printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);


    // Test that bonus equals input
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.hand[p1][0] = feast;
    testState.hand[p1][1] = gardens;
    testState.hand[p1][2] = embargo;
    testState.hand[p1][3] = gold;
    testState.hand[p1][4] = mine;
    updateCoins(p1, &testState, 1);
    printf("Test 7: Bonus produces incease equivalent to input (coins + 1): \n");
    if(testState.coins == amount +4)   // bonus + gold
      printf("Passed. Expected %d    Returned %d\n", amount +4, testState.coins);
    else
      printf("FAILED.  Expected %d    Returned %d\n", amount +4, testState.coins);

    
	// Test that player 2's deck did not change
    printf("\nTest 8: Other player gained nothing to deck: \n");
    if(testState.deckCount[p2] == og.deckCount[p2])
      printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
	
	
	// Test that bonus equals input
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.hand[p1][0] = feast;
    testState.hand[p1][1] = gardens;
    testState.hand[p1][2] = embargo;
    testState.hand[p1][3] = gold;
    testState.hand[p1][4] = mine;
    updateCoins(p1, &testState, 3);
    printf("Test 9: Bonus produces increase equivalent to input (coins + 3): \n");
    if(testState.coins == amount +6)
      printf("Passed. Expected %d    Returned %d\n", amount +6, testState.coins);
    else
      printf("FAILED.  Expected %d    Returned %d\n", amount +6, testState.coins);

    
	// Test that player 2's deck did not change
    printf("\nTest 10: Other player gained nothing to deck: \n");
    if(testState.deckCount[p2] == og.deckCount[p2])
      printf("Passed. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    else
      printf("FAILED. Expected other user's deck to remain %d   It's now: %d\n", og.deckCount[p2], testState.deckCount[p2]);
    
	
	// Test for any victory cards given out inappropriately
    printf("\nTest 11: : Test supply counts for points and curses that should not have been distributed: \n");
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
    printf("\nTest 12: Test supply counts for treasure that should have been distributed: \n");
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