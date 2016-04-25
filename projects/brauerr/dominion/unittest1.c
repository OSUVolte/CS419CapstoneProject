//unittest1.c for dominion assignment3
//test buyCard()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//player should have enough money to buy the card
//number of buys should be decremented by one
//player should have at least one buy left to be allowed to buy
//amount of money left should be decremented by cost of card
//card should be added to players discard pile (discard increase by one)
//number of cards left in supplyIndex should be one less than at the start
//no state change for other players
//should be at least one card left at the supplyIndex

//assumptions
//2 player game

int main () {
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState *G;
  G = newGame();
  
  printf("Starting unittest1 of buyCard method\n");
  //start game with 2 players
  initializeGame(2, k, 2, G);
  
  //save player states as counts of cards in hand, deck, discard
  int p1HandCount = G->handCount[0];
  int p1DeckCount = G->deckCount[0];
  int p1DiscardCount = G->discardCount[0];
  int p2HandCount = G->handCount[1];
  int p2DeckCount = G->deckCount[1];
  int p2DiscardCount = G->discardCount[1];
  int silverCount = G->supplyCount[silver];
  
  //switch to second player, update coins
  G->whoseTurn = 1;
  G->coins = 5;
  
  //set user hand to contain 5 copper
  for (i = 0; i < 5; i++) {
    G->hand[1][i] = copper;
  }
  
  //set number of estates equal to zero
  G->supplyCount[estate] = 0;
  
  //buy an estate - should fail (none remaining)
  printf("Trying to buy estate, expected result buy not allowed, no estates remaining\n");
  if (buyCard(estate, G) == 0) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }
  
  //buy a gold - should fail (not enough money)
  printf("Trying to buy gold, expected result buy not allowed, not enough coins\n");
  if (buyCard(gold, G) == 0) {
    printf("FAIL\n");
  } else {
    printf("SUCCESS\n");
  }
  
  //buy a silver - should succeed 
  printf("Trying to buy silver, expected result buy succeeded\n");
  if (buyCard(silver, G) == 0) {
      printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  //check that silver has been added to discard pile
  printf("Checking if silver was added to discard pile\n");
  if (G->discard[1][G->discardCount[1] - 1] == silver) {
    if (G->discardCount[1] == p2DiscardCount + 1) {
      printf("SUCCESS\n");
    } else {
    printf("FAIL\n");
    }
  } else {
    printf("FAIL\n");
  }
  
  //check that 2 coins are left (decremented by 3)
  printf("Checking that coins have been decremented by 3\n");
  if (G->coins == 2) {
      printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  //check that number of silvers remaining has been decremented by 1
  printf("Checking that silvers have been decremented by 1\n");
  if (G->supplyCount[silver] == silverCount - 1) {
      printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  //buy a copper - should fail (not enough buys)
  printf("Checking that no more buys allowed, buys should be zero\n");
  if (buyCard(copper, G)) {
    printf("FAIL\n");
  } else {
      printf("SUCCESS\n");
  }
  
  //no state change for other player
  printf("Checking that no state change for other player\n");
  if (G->deckCount[0] == p1DeckCount && G->handCount[0] == p1HandCount && G->discardCount[0] == p1DiscardCount) {
      printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
  
  
  return 0;
}