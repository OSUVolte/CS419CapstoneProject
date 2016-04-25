//cardtest3.c for dominion assignment 3
//test is for village

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//player should have at least one action remaining
//number of actions should increase by one
//one card should be added to hand
//number of cards in deck should be decreased by one or 
  //deck should be shuffled if zero cards were in the deck before drawing
  //and cards in deck should equal discard minus one
//village should be added to played card pile
//no state change in other player

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState G;
  
  //start game with 2 players
  initializeGame(2, k, 2, &G);
  
  return 0;
}