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
  for (i = 0; i < 30000; i++) {
    //Randomize the game
    initializeGame(2, cards, 1, &game);
    game.playedCardCount = 0;
    genRandomDeck(player, &game);
    genRandomHand(player, &game);
    genRandomDiscard(player, &game);
    game.numActions = (rand() % 20);
    printf("Random iteration #%d, Deck size: %d, Hand size: %d, Discard size: %d\n", i, game.deckCount[player], game.handCount[player], game.discardCount[player]);
    int card_pos = pickHandCard(player, &game);
    game.hand[player][card_pos] = village;


    //Capture preconditions
    int pre_actions = game.numActions;
    int pre_hand_size = game.handCount[player];
    int pre_deck_size = game.deckCount[player];
    int pre_discard_size = game.discardCount[player];

    int pre_deck_other = game.deckCount[other_player];
    int pre_hand_other = game.handCount[other_player];
    int pre_discard_other = game.discardCount[other_player];

    villageCardEffect(player, card_pos, &game);

    //Test postconditions
    int post_actions = game.numActions;
    int post_hand_size = game.handCount[player];
    int post_deck_size = game.deckCount[player];
    int post_discard_size = game.discardCount[player];

    int post_deck_other = game.deckCount[other_player];
    int post_hand_other = game.handCount[other_player];
    int post_discard_other = game.discardCount[other_player];

    int j;
    int orig_supplies[17];
    for (j = 0; j < 17; j++) {
      orig_supplies[j] = game.supplyCount[all_cards[j]];
    }


    //Check to see if actions happened
    if (pre_actions + 2 != post_actions) {
      printf("FAIL: Actions not increased by 2.\n");
      failed++;
      fail_iteration = i;
    }

    //Check to see if hand size correct
    if (pre_deck_size + pre_discard_size > 0) {
      if (pre_hand_size != post_hand_size) {
        printf("FAIL: hand size should be the same with one card discarded and one drawn.\n");
        failed++;
        fail_iteration = i;
      }
    } else if (pre_hand_size + pre_discard_size == 0) {
      if (pre_hand_size -1 != post_hand_size) {
        printf("FAIL: No cards in deck and discard, so hand size should decrease by 1.\n");
        failed++;
        fail_iteration = i;
      }
    }

    // Check to see if card drawn
    if (pre_deck_size > 0) {
      if (pre_deck_size -1 != post_deck_size) {
        printf("FAIL: Deck size did not decrease by 1 when cards available in deck to draw.\n");
        failed++;
        fail_iteration = i;
      }
    } else if (pre_deck_size == 0 && pre_discard_size > 0) {
      if (post_deck_size != pre_discard_size - 1) {
        printf("FAIL: Discard pile not shuffled into deck when empty deck.\n");
        failed++;
        fail_iteration = i;
      }
    }

    //Check to see if other player affected
    if (pre_deck_other != post_deck_other || pre_hand_other != post_hand_other || pre_discard_other != post_discard_other) {
      printf("Failed: other player's cards were affected.\n");
      failed++;
      fail_iteration = i;
    }

    //Check to see if global supply unaffected
    int changed = 0;
    int changed_card;

    for (j = 0; j < 17; j++) {
      if (orig_supplies[j] != game.supplyCount[all_cards[j]]) {
        changed = 1;
        changed_card = all_cards[j];
      }
    }
    if (changed != 0) {
      printf("FAIL: supplies changed. Last cards supply changed was #%d\n.", changed_card);
      failed++;
      fail_iteration = i;
    }
  }

  if (failed == 0) {
    printf("All tests passed!\n");
  } else {
    printf("FAILED:  Number of failed tests: %d. Last failure was for iteration #%d.\n", failed, fail_iteration);
  }

  return 0;
}
