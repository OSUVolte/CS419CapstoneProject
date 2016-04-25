//cardtest2.c for dominion assignment 3
//test is for adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//user should have at least one action left
//number of actions remaining should be decremented by one
//should shuffle discard once to review contents
//after shuffling discard once - if still not 2 treasure cards found - should return with 
  //just 1 or 0
//should discard revealed cards that are not treasure
//should add 2 treasure cards to hand
//played adventurer should be added to played card pile
//No state change should occur for other players

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState G;
  
  //start game with 2 players
  initializeGame(2, k, 2, &G);
  
  
  
  return 0;
}