/******************************************************************************
** unittest4.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** This file contains unit tests for the isGameOver() function 
******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
 
  struct gameState state;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, 
                          remodel, smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest
  int numPlayers = 4;

  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  
  printf("------ TESTING 0 PROVINCE CARDS ------\n");
  state.supplyCount[province] = 0;
  if (isGameOver(&state) == 1) {
	  printf("SUCCESS: game over when 0 province cards\n");
  }
  else {
    printf("ERROR: game NOT over when 0 province cards\n");	
  }

  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  printf("------ TESTING 1 PROVINCE CARDS ------\n");
  state.supplyCount[province] = 1;
  if (isGameOver(&state) == 0) {
	  printf("SUCCESS: game not over when 1 province cards\n");
  }
  else {
    printf("ERROR: game over when 1 province cards\n");	
  }

  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  printf("------ TESTING COMBINATIONS OF 3 Supply Piles -------\n");
  // num cards listed in dominion.h = 27
  int i, j, k;
  for (i = 0; i < 27; i++) {
    for (j = i + 1; j < 27; j++) {
      for (k = j + 1; k < 27; k++) {
        state.supplyCount[i] = 0;
        state.supplyCount[j] = 0;
        state.supplyCount[k] = 0;
				if (isGameOver(&state) == 0) {
					printf("ERROR: game NOT over when these supply piles are empty: ");
        	printf("%d, %d, %d\n", i, j, k);
				}
        state.supplyCount[i] = 1;
        state.supplyCount[j] = 1;
        state.supplyCount[k] = 1;
			}
		}
	}		
       
  return 0;
}
