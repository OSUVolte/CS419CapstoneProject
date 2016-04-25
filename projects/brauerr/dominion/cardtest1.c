//cardtest1.c for dominion assignment 3
//test is for smithy card 

//business rules
//User should have at least one action remaining
//number of actions remaining should be decremented by one
//Current player should receive exactly 3 cards
//3 cards should come from his own pile.
//No state change should occur for other players
//played smithy should be added to played card pile

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState *G;
  G = newGame();
  
  printf("Testing cardtest1 for smithy\n");
  //start game with 2 players
  initializeGame(2, k, 2, G);
  
  //store initial state
  int p2HandCount = G->handCount[1];
  int p2DeckCount = G->deckCount[1];
  int p2DiscardCount = G->discardCount[1];
  
  //add smithy card to player one's hand
  G->hand[0][G->handCount[0]] = smithy;
  G->handCount[0]++;
  int p1HandCount = G->handCount[0];
  int p1DeckCount = G->deckCount[0];
  int p1DiscardCount = G->discardCount[0];
  
  //decrement actions
  G->numActions = 0;
  printf("Testing that card won't play with zero actions left\n");
  if (playCard(G->handCount[0] - 1, 0, 0, 0, G) == 0) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }
  
  //play smithy card
  G->numActions = 1;
  playCard(G->handCount[0] - 1, 0, 0, 0, G);
  
  //test that deck has been decremented by 3
  printf("Testing that deck has been decremented by 3\n");
  if (G->deckCount[0] == p1DeckCount - 3) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  //test that hand has been incremented by 2 (minus the played card)
  printf("Testing that hand has been incremented by 2\n");
  if (G->handCount[0] == p1HandCount + 2) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL - hand count %d\n", G->handCount[0]);
  }
  
  //check state of other player to ensure no changes
  printf("Testing that state of other player hasn't changed\n");
  if (G->handCount[1] == p2HandCount && G->deckCount[1] == p2DeckCount && G->discardCount[1] == p2DiscardCount) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  //check that actions have been decremented
  printf("Checking that actions have been decremented\n");
  if (G->numActions == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  return 0;
}