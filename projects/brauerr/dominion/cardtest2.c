//cardtest2.c for dominion assignment 3
//test is for adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//should shuffle discard once to review contents
//after shuffling discard once - if still not 2 treasure cards found - should return with 
  //just 1 or 0
//should discard revealed cards that are not treasure
//should add 2 treasure cards to hand
//played adventurer should be added to played card pile

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState *G;
  G = newGame();
  
  printf("Testing cardtest2 for adventurer card\n");
  
  //start game with 2 players
  initializeGame(2, k, 2, G);
  
  //set player two deck and discard to contain only a single treasure card
  printf("Test should successfully draw zero or one treasure card if that is all in deck and discard\n");
  printf("FAIL\n");
  /*abandoned due to hang in original code - infinite loop
  G->deck[1][0] = copper;
  for (i = 1; i < 10; i++) {
    G->deck[1][i] = curse;
  }
  for (i = 0; i < 3; i++) {
    G->discard[1][i] = curse;  
  }
  */
  
  int p1HandCount = G->handCount[0];
  int p1DeckCount = G->deckCount[0];
  int p1DiscardCount = G->discardCount[0];
  int p1Coins = G->coins;
  
  //set player one deck to contain one treasure card and discard to contain one
  G->deck[0][0] = copper;
  for (i = 1; i < G->deckCount[0]; i++) {
    G->deck[0][i] = estate;
  }
  G->discard[0][0] = copper;
  G->discard[0][1] = silver;
  
  //add adventurer card to hand
  G->hand[0][G->handCount[0]] = adventurer;
  G->handCount[0]++;
  printf("Testing that code shuffles once\n");
  if (playCard(G->handCount[0] - 1, 0, 0, 0, G) == 0) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  printf("Testing that other cards are added to discard\n");
  if (G->discardCount[0] > p1DiscardCount) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  printf("Testing that treasure cards are added to hand\n");
  updateCoins(G->whoseTurn, G, 0);
  if (G->coins >= p1Coins + 2) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL - p1Coins: %d, currentCoins: %d\n", p1Coins, G->coins);
  }
  
  printf("Testing that adventurer removed from hand and added to played pile\n");
  if (G->hand[0][G->handCount[0] - 1] == adventurer) {
    printf("FAIL\n");
  } else if (G->playedCards[G->playedCardCount - 1] == adventurer) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }

  
  return 0;
}