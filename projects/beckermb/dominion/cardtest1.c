#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


// This is a test for the smithy card / function from dominion.c

int main() {
  printf("*** Testing smithyCardEffect *** \n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int all_cards[17] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy, province, curse };
  int player = 0;
  int other_player = 1;
  initializeGame(2, cards, 1, &game);

  // Test if hand size increased by two (+3, -1 for played card)
  game.handCount[player] = 2;
  smithyCardEffect(player, 0, &game);
  if (game.handCount[player] == 4) {
    printf("handCount incremented correctly.\n");
  } else {
    printf("FAIL: handCount did not increment correctly. Got %d, expected %d.\n", game.handCount[player], 4);
  }

  //Test if three cards drawn from player's deck
  game.deckCount[player] = 4;
  smithyCardEffect(player, 0, &game);
  if (game.deckCount[player] == 1) {
    printf("deckCount decremented correctly.\n");
  } else {
    printf("FAIL: deckCount did not increment correctly. Got %d, expected %d.\n", game.deckCount[player], 1);
  }

  //Test if smithy added to played cards
  game.deckCount[player] = 4;
  game.playedCardCount = 1;
  game.playedCards[game.playedCardCount] = gardens;
  smithyCardEffect(player, 0, &game);

  if (game.playedCardCount == 2) {
    printf("playedCardCount incremented correctly.\n");
  } else {
    printf("FAIL: playedCardCount did not increment correctly. Got %d, expected %d.\n", game.playedCardCount, 2);
  }

  if (game.playedCards[game.playedCardCount - 1] == smithy) {
    printf("smithy added to playedCards.\n");
  } else {
    printf("FAIL: smithy was not added to played cards.\n");
  }

  //Test if other players are unaffected.
  int orig_deck_count = game.deckCount[other_player];
  int orig_hand_count = game.handCount[other_player];
  smithyCardEffect(player, 0, &game);
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


  //Test if global supplies unaffected
  int i;
  int changed = 0;
  int changed_card;
  int orig_supplies[17];
  for (i = 0; i < 17; i++) {
    orig_supplies[i] = game.supplyCount[all_cards[i]];
  }
  smithyCardEffect(player, 0, &game);
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
