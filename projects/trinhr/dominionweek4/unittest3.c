#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the isGameOver function.
//Input:
//struct gameState *state-> state of the game.
//Business Rules:
//1. If the game is out of Province Cards --> Game Over 
//2. If three supply piles are out of stock ---> Game Over 
//3. If neither is true --> No Game Over.
//4. Game State should remain unchanged. 
int main () {

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState expected, actual;
  int numPlayers = 2;
  int seed = 500;
  int player = 1;  
  int gameOver = 1;

  initializeGame(numPlayers, k, seed, &actual);

  //Copy the game state to the post game state test case.
  memcpy(&expected, &actual, sizeof(struct gameState));
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Both PRE & POST GAME STATES ARE EQUIVALENT before calling the function.\n");
  assert(isGameOver(&actual) != gameOver);
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Game Over was successfully handled when conditions were not met and game state was unchanged.\n");

  //Set Up Case for out of stock province cards Game Over.
  actual.supplyCount[province] = expected.supplyCount[province] = 0;
 
 //Copy the game state to the post game state test case.
  //Expected Results.
  assert(isGameOver(&actual) == gameOver );
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Game Over successfully handled with out of stock province cards and Game state was unchanged.\n");

  //Set Up Case for 3 out of stock supply piles Game Over.
  actual.supplyCount[province] = expected.supplyCount[province] = 3;
  actual.supplyCount[silver] = expected.supplyCount[silver] = 0;
  actual.supplyCount[gold] = expected.supplyCount[gold] = 0;
  actual.supplyCount[copper] = expected.supplyCount[copper] = 0;

  //Expected Results.
  assert(isGameOver(&actual) == gameOver );
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Game Over successfully handled with three out of supply cards and Game state was unchanged.\n");

  
  return 0;

}



