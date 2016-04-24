/*
File: unittest3.c
Author: Elliot Bates
Description: Unit test for is game over function from dominion
*/

/*
int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int main() {
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int supplyCounts[25];
	int gameOver;

	printf ("TESTING isGameOver():\n");
	
	// check function does not modify any supply counts
	printf("Testing effect of function on supply counts.\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	for (i = 0; i < 25; i++) {
		supplyCounts[i] = G.supplyCount[i];
	}
	isGameOver(&G);
	for (i = 0; i < 25; i++) {
		if (supplyCounts[i] != G.supplyCount[i])
			printf("PASSED: supplyCount[%d] = %d, expected = %d.\n", i, G.supplyCount[i], supplyCounts[i]);
		else
			printf("FAILED: supplyCount[%d] = %d, expected = %d.\n", i, G.supplyCount[i], supplyCounts[i]);
	}
	
	// check no provice cards causes game to end
	printf("Testing that no province cards causes end of game.\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game	
	G.supplyCount[province] = 0;
	gameOver = isGameOver(&G);
	if (gameOver == 1)
		printf("PASSED: isGameOver = %d, expected = 1.\n", gameOver);
	else
		printf("FAILED: isGameOver = %d, expected = 1.\n", gameOver);
	
	// check 3 empty piles causes game over
	printf("Testing that 3 empty piles causes end of game.\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game	
	G.supplyCount[copper] = 0;
	G.supplyCount[silver] = 0;
	G.supplyCount[smithy] = 0;
	gameOver = isGameOver(&G);
	if (gameOver == 1)
		printf("PASSED: isGameOver = %d, expected = 1.\n", gameOver);
	else
		printf("FAILED: isGameOver = %d, expected = 1.\n", gameOver);
	
	// check 2 empty piles does not cause game over
	printf("Testing that 2 empty piles does not cause end of game.\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game	
	G.supplyCount[copper] = 0;
	G.supplyCount[smithy] = 0;
	gameOver = isGameOver(&G);
	if (gameOver == 0)
		printf("PASSED: isGameOver = %d, expected = 0.\n", gameOver);
	else
		printf("FAILED: isGameOver = %d, expected = 0.\n", gameOver);
}



















