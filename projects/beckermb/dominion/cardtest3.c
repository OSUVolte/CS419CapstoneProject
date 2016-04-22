#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// This is test of the village card / function from dominion.c

int main() {
  printf("*** Testing villageCardEffect *** \n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, outpost };
  int all_cards[17] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy, province, curse };
  int player = 0;
  int other_player = 1;
  initializeGame(2, cards, 1, &game);

  // Test if card drawn from player's deck
  int expec_deck_count = game.deckCount[player] - 1;
  villageCardEffect(player, 0, &game);
  if (expec_deck_count == game.deckCount[player]) {
    printf("Card correctly drawn from player's deck\n");
  } else {
    printf("FAIL: Deckcount not decremented correctly. Got %d and expected %d\n", game.deckCount[player], expec_deck_count);
  }

  // Test if card discarded from player's hand
  game.hand[player][1] = village;
  game.hand[player][0] = smithy;
  game.handCount[player] = 2;
  villageCardEffect(player, 1, &game);
  if (game.hand[player][1] != village) {
    printf("Card correctly discarded from player's hand\n");
  } else {
    printf("FAIL: village still in player's hand.\n");
  }


  // Test if actions given to player
  game.numActions = 1;
  villageCardEffect(player, 1, &game);
  if (game.numActions == 3) {
    printf("Actions correctly awarded to player.\n");
  } else {
    printf("FAIL: Actions not given to player. Expected %d and got %d.\n", 3, game.numActions);
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
  villageCardEffect(player, 0, &game);
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
}
