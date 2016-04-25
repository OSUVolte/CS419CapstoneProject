//unittest2.c for dominion assignment3
//test isGameOver()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//game should end if count of provinces is 0 - return 1
//game should end if 3 of supply pile are at 0 - return 1
//game should end if both the count of provinces and 3 of supply pile are 0 - return 1
//game should not end if neither of these are true - return 0

//assumptions
//2 player game

int main () {
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  printf("Starting unittest2 of isGameOver method\n");
  struct gameState *G;
  G = newGame();
  
  //start game with 2 players
  initializeGame(2, k, 2, G);
  
  //test case at initialization - should return 0
  printf("Testing at beginning - game shouldn't be over\n");
  if (isGameOver(G)) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }
  
  //set smithy pile to 0 - should return 0 one pile depleted
  G->supplyCount[smithy] = 0;
  printf("Set smithy to zero - game shouldn't be over\n");
  if (isGameOver(G)) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }
  
  //set adventurer pile to 0 - should return 0 two piles depleted
  G->supplyCount[adventurer] = 0;
  printf("Set adventurer to zero - game shouldn't be over\n");
  if (isGameOver(G)) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }
  
  //set provinces to 0 - should return 1
  G->supplyCount[province] = 0;
  printf("Set provinces to zero - game should be over\n");
  if (isGameOver(G)) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  //set provinces to 1 and set treasure_map pile to zero - should return 1 three piles depleted
  G->supplyCount[province] = 1;
  printf("Set provinces to 1 but treasure map to zero - game should be over\n");
    if (isGameOver(G)) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  //set province pile to 0 - return 1 
  G->supplyCount[province] = 0;
  printf("Set provinces to zero - game should be over\n");
  if (isGameOver(G)) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  return 0;
}