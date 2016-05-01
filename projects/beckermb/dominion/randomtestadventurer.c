#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<stdlib.h>
#include<time.h>


int genRandomCard() {
  // Generate a random number of the legal cards
  int r = (rand() % treasure_map);
  return r;
}

int pickHandCard(int player, struct gameState *game) {
  int card_pos = (rand() % game->handCount[player]);
  return card_pos;
}

void genRandomDeck(int player, struct gameState *game) {
  //Generate a random deck size
  int num_cards = (rand() % 30);

  game->deckCount[player] = num_cards;
  int i;
  for (i = 0; i < num_cards; i++) {
    game->deck[player][i] = genRandomCard();
  }
}

void genRandomHand(int player, struct gameState *game) {
  //Generate a random hand size
  int num_cards = (rand() % 29) + 1;

  game->handCount[player] = num_cards;
  int i;
  for (i = 0; i < num_cards; i++) {
    game->hand[player][i] = genRandomCard();
  }
}

void genRandomDiscard(int player, struct gameState *game) {
  //Generate a random discard size
  int num_cards = (rand() % 12);

  game->discardCount[player] = num_cards;
  int i;
  for (i = 0; i < num_cards; i++) {
    game->discard[player][i] = genRandomCard();
  }
}
int main() {

  srand(time(NULL));

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  initializeGame(4, cards, 1, &game);
  int player = 0;

  int i;
  for (i = 0; i < 10000; i++) {
    printf("Random iteration #%d\n", i);
    genRandomDeck(player, &game);
    genRandomHand(player, &game);
    genRandomDiscard(player, &game);
    int card_pos = pickHandCard(player, &game);
    game.hand[player][card_pos] = adventurer;
    // adventurerCardEffect(player, card_pos, &game);
  }
  return 0;
}
