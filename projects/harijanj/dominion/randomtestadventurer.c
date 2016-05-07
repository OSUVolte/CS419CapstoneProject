#include "dominion.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "rngs.h"

#define MAX_TESTS 2000

int main () {

  srand(time(NULL));

  int i; 
  int j; 
  int player;
  int numberPlayer;
  int handCount; 
  int deckCount;
  int discardCount;
  int seed;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
         remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Random Test: Adventurer Card.\n");

  for (i = 0; i < MAX_TESTS; i++) {
    
    numberPlayer = (rand() % 4) + 1; // Range: 1 - 4 players

    player = rand() % numberPlayer;

    seed = rand();

    initializeGame(numberPlayer, k, seed, &G);

    G.deckCount[player] = rand() % MAX_DECK;
    G.discardCount[player] = rand() % MAX_DECK;
    G.handCount[player] = rand() % MAX_HAND;
    G.whoseTurn = player;

    deckCount = G.deckCount[player];
    discardCount = G.discardCount[player];
    handCount = G.handCount[player];

    //Need to add stuff here
    for(j = 0; j < deckCount; j++){
      G.deck[player][j] = rand() % (treasure_map);
    }

    for(j = 0; j < discardCount; j++){
      G.discard[player][j] = rand() % (treasure_map);
    }

    for(j = 0; j < handCount; j++){
      G.hand[player][j] = rand() % (treasure_map);
    }

    if (seed % 3 == 0) {
      G.deckCount[player] = 0;
    }

    // TC stands for Treasure Card
    int deckTC_before = 0;
    int handTC_before = 0;
    int deckTC_after = 0;
    int handTC_after = 0;

    // Count # of Treasure Card BEFORE Adventurer
    for (j = 0; j < G.handCount[player]; j++) {
      if (G.hand[player][j] == copper || G.hand[player][j] == silver || G.hand[player][j] == gold) {
        handTC_before += 1;
      }
    }
    for (j = 0; j < G.deckCount[player]; j++) {
      if (G.deck[player][j] == copper || G.deck[player][j] == silver || G.deck[player][j] == gold) {
        deckTC_before += 1;
      }
    }

    cardEffect(adventurer, 0, 0, 0, &G, 0, NULL);

    // Count # of Treasure Card AFTER Adventurer
    for (j = 0; j < G.handCount[player]; j++) {
      if (G.hand[player][j] == copper || G.hand[player][j] == silver || G.hand[player][j] == gold) {
        handTC_after += 1;
      }
    }
    for (j = 0; j < G.deckCount[player]; j++) {
      if (G.deck[player][j] == copper || G.deck[player][j] == silver || G.deck[player][j] == gold) {
        deckTC_after += 1;
      }
    }

    if (G.handCount[player] != (handCount + 2)) {
      printf("FAIL to draw 2 cards!\n");
    }  

    if (deckTC_after != (deckTC_before - 2)) {
      printf("DECK: Treasure Cards didn't decrease by 2.\n");
    }

    if (handTC_after != (handTC_before + 2)) {
      printf("HAND: Treasure Cards didn't increase by 2\n");
    }
  }

  printf("\nTEST FOR ADVENTURER CARD COMPLETE!\n");
  return 0;
}
