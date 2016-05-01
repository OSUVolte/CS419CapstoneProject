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

//Returns 1 if player has at least two money cards in deck or discard pile
int moneyCount(int player, struct gameState *game) {
  int total = 0;
  int i;
  for (i = 0; i < game->deckCount[player]; i++) {
    if (game->deck[player][i] >= copper && game->deck[player][i] <= gold ) {
      total++;
    }
  }

  for (i = 0; i < game->discardCount[player]; i++) {
    if (game->discard[player][i] >= copper && game->discard[player][i] <= gold) {
      total++;
    }
  }

  return total;
}

int main() {

  srand(time(NULL));

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int all_cards[17] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy, province, curse };
  int player = 0;
  int other_player = 1;
  int failed = 0;
  int fail_iteration;

  int i;
  for (i = 0; i < 100000; i++) {
    //Randomize the game
    initializeGame(2, cards, 1, &game);
    game.playedCardCount = 0;
    genRandomDeck(player, &game);
    genRandomHand(player, &game);
    genRandomDiscard(player, &game);
    printf("Random iteration #%d, Deck size: %d, Hand size: %d, Discard size: %d\n", i, game.deckCount[player], game.handCount[player], game.discardCount[player]);
    int card_pos = pickHandCard(player, &game);
    game.hand[player][card_pos] = adventurer;

    //Capture preconditions
    int money_count = moneyCount(player, &game);
    int start_hand_size = game.handCount[player];
    int total_cards = game.deckCount[player] + game.handCount[player] + game.discardCount[player];


    int j;
    int orig_supplies[17];
    for (j = 0; j < 17; j++) {
      orig_supplies[j] = game.supplyCount[all_cards[j]];
    }

    int orig_deck_count = game.deckCount[other_player];
    int orig_hand_count = game.handCount[other_player];
    int orig_disc_count = game.discardCount[other_player];

    //Run method
    adventurerCardEffect(player, card_pos, &game);

    //Check postconditions

    if (money_count == 0) {
      if (start_hand_size - 1 != game.handCount[player]) {
        printf("Failed: No money in deck or discard, so handsize should decrease by 1.\n");
        failed++;
        fail_iteration = i;
      }
    } else if (money_count == 1) {
      if (start_hand_size != game.handCount[player] ) {
        printf("Failed: One money in deck or discard, so handsize should stay the same.\n");
        failed++;
        fail_iteration = i;
      }
    } else if (money_count > 1) {
        if (start_hand_size + 1 != game.handCount[player]) {
          printf("Failed: At least two money in deck or discard, so handsize should increase by 1.\n");
          failed++;
          fail_iteration = i;
        }
    }

    int post_total_cards = game.deckCount[player] + game.handCount[player] + game.discardCount[player] + game.playedCardCount;
    if (total_cards != post_total_cards) {
      printf("Failed: started with %d cards total, ended with %d\n", total_cards, post_total_cards);
      failed += 1;
      fail_iteration = i;
    }

    int post_deck_count = game.deckCount[other_player];
    int post_hand_count = game.handCount[other_player];
    int post_disc_count = game.discardCount[other_player];
    if (post_deck_count != orig_deck_count || post_hand_count != orig_hand_count || post_disc_count != orig_disc_count) {
      printf("Failed: other player's cards were affected.\n");
      failed++;
      fail_iteration = i;
    }
  }

  if (failed == 0) {
    printf("All tests passed!\n");
  } else {
    printf("FAILED: Tests failed for %d iterations. Last failure was %d.\n", failed, fail_iteration);
  }
  return 0;
}
