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


  printf("*******  TESTING FUNCTION: isGameOver  *******\n\n");
  
  for(i = 0; i < numTests; i++){
    
    // Set hand basics for the game
    pos = -1;
    p1 = 0;
    p2 = 1;


    // Test if the pile is empty
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.supplyCount[province] = 0;  
    result = isGameOver(&testState);   
    printf("Test 1: Province is empty, should be game over: \n");
    if(result == 1)
      printf("Passed. Expected %d    Returned %d\n", 1, result);
    else
      printf("FAILED. Expected %d    Returned %d\n", 1, result);


    
	// Test if three supply piles are at 0, game ends
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.supplyCount[silver] = 0;  
    testState.supplyCount[duchy] = 0;
    testState.supplyCount[estate] = 0;
    result = isGameOver(&testState);
    printf("\nTest 2: Three empty supply decks end the game: \n");
    if(result == 1)
      printf("Passed. Expected %d    Returned %d\n", 1, result);
    else
      printf("FAILED. Expected %d    Returned %d\n", 1, result);

    
	
	// Test that the game does not end early at lesser counts
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.supplyCount[duchy] = 0;
    testState.supplyCount[estate] = 0;
    result = isGameOver(&testState);
    printf("\nTest 3: Two empty supply decks should not end the game: \n");
    if(result == 0)
      printf("Passed. Expected %d    Returned %d\n", 0, result);
    else
      printf("FAILED. Expected %d    Returned %d\n", 0, result);

    
	
	// Test that the game does not end with cards still on pile
    initializeGame(numPlayers, k, 1000, &og);
    memcpy(&testState, &og, sizeof(struct gameState));
    testState.supplyCount[silver] = 1;  
    testState.supplyCount[duchy] = 1;
    testState.supplyCount[estate] = 1;
    result = isGameOver(&testState);
    printf("\nTest 4: Cards remaining in the decks should not end the game: \n");
    if(result == 0)
      printf("Passed. Expected %d    Returned %d\n", 0, result);
    else
      printf("FAILED. Expected %d    Returned %d\n", 0, result);


    
	// Test for changes in money supply that shouldn't happen
    printf("\nTest 5: Test supply counts for treasure that should have been distributed: \n");
    if(og.supplyCount[copper] != testState.supplyCount[copper])
      printf("FAILED. Copper Count Mismatch. Expected: %d  Received: %d\n\n", og.supplyCount[copper], testState.supplyCount[copper]);
    if(1 != testState.supplyCount[silver])
      printf("FAILED. Silver Count Mismatch. Expected: %d  Received: %d\n\n", og.supplyCount[silver], testState.supplyCount[silver]);
    if(og.supplyCount[gold] != testState.supplyCount[gold])
      printf("FAILED. Gold Count Mismatch. Expected: %d  Received: %d\n\n", og.supplyCount[gold], testState.supplyCount[gold]);
    else
      printf("Passed. Supply counts for treasure cards are correct\n\n");

  }
  return 0;
}