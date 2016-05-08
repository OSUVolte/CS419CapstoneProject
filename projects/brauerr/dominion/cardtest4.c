//cardtest4.c for dominion assignment 4
//test for council_room

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//number of buys for player should be incremented
//exactly four cards should be added to hand
//four cards gone from deck
//other players should have one card added to their hands
//other players should have one card less in their decks

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState *G;
  G = newGame();
  
  printf("Starting cardtest4 for council room\n");
  
  //start game with 3 players
  initializeGame(3, k, 3, G);
  int p2Hand = G->handCount[1];
  int p2Deck = G->deckCount[1];
  int p3Hand = G->handCount[2];
  int p3Deck = G->deckCount[2];
  
  //add council room to p1 hand
  G->hand[0][G->handCount[0]] = council_room;
  G->handCount[0]++;
  
  int p1Hand = G->handCount[0];
  int p1Deck = G->deckCount[0];
  int p1Buys = G->numBuys;
  
  printf("Testing that number of buys are incremented\n");
  if (playCard(G->handCount[0] - 1, 0, 0, 0, G) == 0) {
    if (G->numBuys == p1Buys + 1) {
      printf("SUCCESS\n"); 
    } else {
      printf("FAIL\n");
    }
  } else {
    printf("FAIL\n");
  }
  
  printf("Testing that four cards added to hand minus played card\n");
  if (G->handCount[0] == p1Hand + 3) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  printf("Testing that four cards removed from deck\n");
  if (G->deckCount[0] == p1Deck - 4) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  printf("Testing that other players have one more card drawn\n");
  if (G->handCount[1] == p2Hand + 1 && G->deckCount[1] == p2Deck - 1) {
    if (G->handCount[2] == p3Hand + 1 && G->deckCount[2] == p3Deck - 1) {
      printf("SUCCESS\n");
    } else {
      printf("FAIL P3, %d%d%d%d\n", G->handCount[2], p3Hand, G->deckCount[2], p3Deck);
    }
  } else {
    printf("FAIL P2, %d%d%d%d\n", G->handCount[1], p2Hand, G->deckCount[1], p2Deck);
  }
  
  
  return 0;
}