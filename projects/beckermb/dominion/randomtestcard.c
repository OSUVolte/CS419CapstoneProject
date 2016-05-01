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
  int num_cards = (rand() % 30);

  game->discardCount[player] = num_cards;
  int i;
  for (i = 0; i < num_cards; i++) {
    game->discard[player][i] = genRandomCard();
  }
}

int main() {

  printf("Starting random testing for villageCardEffect.\n");

  srand(time(NULL));

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int all_cards[17] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy, province, curse };
  int player = 0;
  int other_player = 1;
  int failed = 0;
  int fail_iteration;

  int i;
  for (i = 0; i < 10000; i++) {
    //Randomize the game
    initializeGame(2, cards, 1, &game);
    game.playedCardCount = 0;
    genRandomDeck(player, &game);
    genRandomHand(player, &game);
    genRandomDiscard(player, &game);
    printf("Random iteration #%d, Deck size: %d, Hand size: %d, Discard size: %d\n", i, game.deckCount[player], game.handCount[player], game.discardCount[player]);
    int card_pos = pickHandCard(player, &game);
    game.hand[player][card_pos] = village;


    //Capture preconditions
    int pre_actions = game.numActions;
    int pre_hand_size = game.handCount[player];
    int pre_deck_size = game.deckCount[player];
    int pre_discard_size = game.discardCount[player];

    villageCardEffect(player, card_pos, &game);

    int pre_deck_other = game.deckCount[other_player];
    int pre_hand_other = game.handCount[other_player];
    int pre_discard_other = game.discardCount[other_player];

  }

  return 0;
}
