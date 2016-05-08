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
  int k;
  int player;
  int numberPlayer;
  int handCount; 
  int deckCount;
  int discardCount;
  int seed;
  int numberOfCard[4];
  int notIncrease = 0;

  int cards[10] = {adventurer, council_room, feast, gardens, mine,
         remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Random Test: Smithy Card.\n");

  for (i = 0; i < MAX_TESTS; i++) {
    
    numberPlayer = (rand() % 4) + 1; // Range: 1 - 4 players

    player = rand() % numberPlayer;

    printf("Number of player playing: %d\n",numberPlayer);
    printf("YOU are playing as player number : %d\n",player);

    seed = rand();

    initializeGame(numberPlayer, cards, seed, &G);

    // Set hand cards and deck cards for each player
    for (k = 0; k < numberPlayer; k++) {
      G.deckCount[k] = rand() % MAX_DECK;
      G.discardCount[k] = rand() % MAX_DECK;
      G.handCount[k] = rand() % MAX_HAND;
      for(j = 0; j < G.handCount[k]; j++){
        G.hand[k][j] = rand() % (treasure_map);
      }
      for(j = 0; j < G.deckCount[k]; j++){
        G.deck[k][j] = rand() % (treasure_map);
      }
    }

    G.numPlayers = numberPlayer;
    G.whoseTurn = player;

    // copy state variable
    deckCount = G.deckCount[player];
    handCount = G.handCount[player];
    printf("<----- BEFORE SMITHY ----->\n");
    printf("Your total hand cards: %d\n",handCount);
    printf("Your total deck cards: %d\n",deckCount);

    // count number of card each player
    for (k = 0; k < numberPlayer; k++) {
      numberOfCard[k] = G.handCount[k];
      printf("Player %d hand cards: %d\n",k, numberOfCard[k]);
    }

    cardEffect(smithy, 0, 0, 0, &G, 0, 0);

    printf("<----- AFTER SMITHY ----->\n");
    printf("Your total hand cards: %d\n",G.handCount[player]);
    printf("Your total deck cards: %d\n",G.deckCount[player]);
    
    for (k = 0; k < numberPlayer; k++) {
      numberOfCard[k] = G.handCount[k];
      printf("Player %d hand cards: %d\n",k, numberOfCard[k]);
    }

    // check if current player gain 3 cards
    if (G.handCount[player] != (handCount + 3)) {
      printf("Current player FAILS to gain 3 cards!\n");
    }  

    // check if current player gain 3 cards from his/her deck
    if (G.deckCount[player] != deckCount - 3) {
      printf("Current player's deck FAILS to reduced by 3 cards!\n");
    }

    for (k = 0; k < numberPlayer; k++) {
      if ((k != player) && (G.handCount[k] == numberOfCard[k])) {
        notIncrease += 1;
      }
    }
    printf("There are %d players from %d number of players (exclude YOU) that's not effected by smithy.\n\n", notIncrease, numberPlayer-1);
    notIncrease = 0;
  }
  
  printf("\nTEST FOR SMITHY CARD COMPLETE!\n");
  return 0;
}
