//cardtest4.c for dominion assignment 4
//test for council_room

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//player should have at least one action remaining
//number of actions should be decremented by one
//number of buys for player should be incremented
//exactly four cards should be added to hand
//four fewer cards in deck, or if less than four in deck at start - deck
  //should be shuffled and cards should equal discard plus initial count minus 4
//council room should be added to played card pile
//other players should have one card added to their hands

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState G;
  
  //start game with 4 players
  initializeGame(2, k, 4, &G);
  
  return 0;
}