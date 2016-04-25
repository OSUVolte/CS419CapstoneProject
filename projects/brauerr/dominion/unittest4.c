//unittest4.c for dominion assignment3
//test shuffle()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//ensure discard is empty
//deck must have at least one card
//number of each card types in deck after shuffling should be identical to num cards before

int main () {
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState *G;
  G = newGame();
  
  printf("Starting unittest4 for shuffle() method\n");
  
  //start game with 2 players
  initializeGame(2, k, 2, G);
  
  //add a gold card to p2 discard pile
  G->discard[1][G->discardCount[1]] = gold;
  G->discardCount[1]++;
  G->supplyCount[gold]--;
  
  //number of card types of each in deck should be identical to before
  printf("Number of card types should be identical to before\n");
  if (shuffle(1, G) == 0) {
    int estateCount = 0;
    int copperCount = 0;
    for (i = 0; i < 10; i++) {
      if (G->deck[1][i] == copper) copperCount++;
      if (G->deck[1][i] == estate) estateCount++;
    }
    if (estateCount == 3 && copperCount == 7) {
      printf("SUCCESS\n");
    } else {
      printf("FAIL\n");
    }
  } else {
    printf("FAIL\n");
  }  
  
  //call shuffle - see if fails or discard is empty
  printf("Testing to see if shuffle fails due to discard not being empty\n");
  if (shuffle(1, G) == -1) {
    if (G->discardCount[1] == 0) {
      printf("SUCCESS\n");
    } else {
      printf("FAIL\n");
    }
  } else {
    printf("FAIL\n");
  }
  
  //make sure deck has at least one card
  printf("Testing to see if shuffle fails when no cards in deck\n");
  G->deckCount[1] = 0;
  if (shuffle(1, G) == 0) {
    printf("FAIL - %d\n", G->deckCount[1]);
  } else {
    printf("SUCCESS\n");
  }
  
  
  
  
  return 0;
}