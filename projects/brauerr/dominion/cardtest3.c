//cardtest3.c for dominion assignment 3
//test is for village

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//number of actions should increase by one
//one card should be added to hand
//number of cards in deck should be decreased by one or 
  //deck should be shuffled if zero cards were in the deck before drawing
  //and cards in deck should equal discard minus one

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState *G;
  G = newGame();
  
  printf("Starting cardtest3 for village card\n");
  
  //start game with 2 players
  initializeGame(2, k, 2, G);
 
  
  //add village to player ones hand
  G->hand[0][G->handCount[0]] = village;
  G->handCount[0]++;
  
  int p1HandCount = G->handCount[0];
  int p1DeckCount = G->deckCount[0];
  int p1DiscardCount = G->discardCount[0];
  int p1Coins = G->coins;
  int p1Actions = G->numActions;
  
  //discard Deck
  for (i = 0; i < G->deckCount[0]; i++) {
    G->discard[0][i] = G->deck[0][i];
    G->deck[0][i] = -1;
    G->discardCount[0]++;
  }
  G->deckCount[0] = 0;
  
  int p1Cards = G->deckCount[0] + G->discardCount[0];
  
  printf("Testing that discard will be shuffled if no cards in deck\n");
  if (playCard(G->handCount[0] - 1, 0, 0, 0, G) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  printf("Testing that number of cards in deck has decreased by one\n");
  if (G->deckCount[0] == p1Cards - 1) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL - currentCards: %d, original cards: %d\n", G->deckCount[0], p1Cards);
  }
  
  printf("Testing that number of cards in hand has stayed the same\n");
  if (G->handCount[0] == p1HandCount) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  printf("Testing that number of actions has increased by one\n");
  if (G->numActions == p1Actions + 1) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL - currentActions: %d, original: %d\n", G->numActions, p1Actions);
  }
  
  return 0;
}