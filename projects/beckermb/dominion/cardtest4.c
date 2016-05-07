#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


// This is a test for the adventurer card / function from dominion.c

int main() {
  printf("*** Testing adventurerCardEffect *** \n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int all_cards[17] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy, province, curse };
  int player = 0;
  int other_player = 1;
  initializeGame(2, cards, 1, &game);

  //Test if two treatures added to hand with normal deck
  int handSize = game.handCount[player] + 1;
  adventurerCardEffect(player, 0, &game);
  if (handSize == game.handCount[player]) {
    printf("Player hand size increased by one.\n");
  } else {
    printf("FAIL: Player hand size failed to increase. Got %d, expected %d.\n", game.handCount[player], handSize);
  }
  int hand_count = game.handCount[player];
  int top_hand = game.hand[player][hand_count - 1];
  int sec_hand = game.hand[player][hand_count - 2];

  if ((top_hand >= 4 && top_hand <=6) && (sec_hand >= 4 && sec_hand <=6) ) {
    printf("Two treasure cards added to hand.\n");
  } else {
    printf("FAIL: two treasure cards not drawn.\n");
  }

  //Test to make sure additional treasures not added to deck
  int orig_copp = fullDeckCount(player, copper, &game);
  int orig_silv = fullDeckCount(player, silver, &game);
  int orig_gold = fullDeckCount(player, gold, &game);
  adventurerCardEffect(player, 0, &game);
  int new_copp = fullDeckCount(player, copper, &game);
  int new_silv = fullDeckCount(player, silver, &game);
  int new_gold = fullDeckCount(player, gold, &game);
  if ((orig_copp == new_copp) && (orig_silv == new_silv) && (orig_gold == new_gold)) {
    printf("No new treasures added to take.\n");
  } else {
    printf("FAIL: treasures added or removed from deck.\n");
  }
  // Test if other players are unaffected.
  int orig_deck_count = game.deckCount[other_player];
  int orig_hand_count = game.handCount[other_player];
  villageCardEffect(player, 0, &game);
  if (orig_deck_count == game.deckCount[other_player]) {
    printf("Other player's deck unaffected.\n");
  } else {
    printf("FAIL: other player's deck changed\n");
  }

  if (orig_hand_count == game.handCount[other_player]) {
    printf("Other player's hand unaffected.\n");
  } else {
    printf("FAIL: other player's hand changed\n");
  }

  // Test if global supplies unaffected
  int i;
  int changed = 0;
  int changed_card;
  int orig_supplies[17];
  for (i = 0; i < 17; i++) {
    orig_supplies[i] = game.supplyCount[all_cards[i]];
  }
  adventurerCardEffect(player, 0, &game);
  for (i = 0; i < 17; i++) {
    if (orig_supplies[i] != game.supplyCount[all_cards[i]]) {
      changed = 1;
      changed_card = all_cards[i];
    }
  }
  if (changed == 0) {
    printf("Supplies unchanged.\n");
  } else {
    printf("FAIL: supplies changed. Last cards supply changed was #%d\n.", changed_card);
  }

  return 0;

}
