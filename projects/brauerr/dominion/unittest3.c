//unittest3.c for dominion assignment 3
//test scoreFor()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//business rules
//score should include all curses, estates, duchys, provinces, great_halls and gardens
//score should include all cards in hand, discard, and deckCount
//should return values specific to each player

int main () {
  
  int i, n, r, p, deckCount, discardCount, handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	  remodel, smithy, village, treasure_map, great_hall};

  struct gameState *G;
  G = newGame();
  
  printf("Starting testing of unittest3 scoreFor method\n");
  
  //start game with 2 players
  initializeGame(2, k, 2, G);
  int score = 0;
  
  //player one add one of each card to discard
  printf("Adding one of each VP card to p1 deck and discard, score should be 27\n");
  gainCard(curse, G, 0, 0);
  gainCard(estate, G, 0, 0);
  gainCard(duchy, G, 0, 0);
  gainCard(province, G, 0, 0);
  gainCard(great_hall, G, 0, 0);
  gainCard(gardens, G, 0, 0);
  gainCard(curse, G, 1, 0);
  gainCard(estate, G, 1, 0);
  gainCard(duchy, G, 1, 0);
  gainCard(province, G, 1, 0);
  gainCard(great_hall, G, 1, 0);
  gainCard(gardens, G, 1, 0);
  score = scoreFor(0, G);
  if (score == 27) {
    printf("SUCCESS - score is %d\n", score);
  } else {
    printf("FAIL - score is %d\n", score);
  }
  
  //player one add one of each card to deck
  printf("Adding one of each VP card to p1 deck and discard, score should be 56\n");
  gainCard(curse, G, 0, 1);
  gainCard(estate, G, 0, 1);
  gainCard(duchy, G, 0, 1);
  gainCard(province, G, 0, 1);
  gainCard(great_hall, G, 0, 1);
  gainCard(gardens, G, 0, 1);
  gainCard(curse, G, 1, 1);
  gainCard(estate, G, 1, 1);
  gainCard(duchy, G, 1, 1);
  gainCard(province, G, 1, 1);
  gainCard(great_hall, G, 1, 1);
  gainCard(gardens, G, 1, 1);
  gainCard(curse, G, 0, 1);
  gainCard(estate, G, 0, 1);
  gainCard(duchy, G, 0, 1);
  gainCard(province, G, 0, 1);
  gainCard(great_hall, G, 0, 1);
  gainCard(gardens, G, 0, 1);
  gainCard(curse, G, 1, 1);
  gainCard(estate, G, 1, 1);
  gainCard(duchy, G, 1, 1);
  gainCard(province, G, 1, 1);
  gainCard(great_hall, G, 1, 1);
  gainCard(gardens, G, 1, 1);
    score = scoreFor(1, G);
  if (score == 56) {
    printf("SUCCESS - score is %d\n", score);
  } else {
    printf("FAIL - score is %d\n", score);
  }
  
  //player two add two of each card to discard and deck
  
  return 0;
}