#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


// This is a test for the outpost card / function from dominion.c


// int outpostCardEffect(int currentPlayer, int handPos, struct gameState *state) {
//   //set outpost flag
//   state->outpostPlayed++;
//
//   //discard card
//   discardCard(handPos, currentPlayer, state, 0);
//   return 0;
// }

int main() {
  printf("*** Testing outpostCardEffect *** \n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, outpost };
  int all_cards[17] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy, province, curse };
  int player = 0;
  int other_player = 1;
  initializeGame(2, cards, 1, &game);

  //Test if card discarded from hand
  game.handCount[player] = 1;
  outpostCardEffect(player, 0, &game);
  if (game.handCount[player] == 0) {
    printf("handCount decremented correctly.\n");
  } else {
    printf("FAIL: handCount did not decrement correctly. Got %d, expected %d.\n", game.handCount[player], 0);
  }

  //test if outpost flag set
  game.outpostPlayed = 0;
  outpostCardEffect(player, 0, &game);
  if (game.outpostPlayed == 1) {
    printf("outpostPlayed incremented correctly.\n");
  } else {
    printf("FAIL: outPostPlayed did not increment correctly. Got %d, expected %d.\n", game.outpostPlayed, 1);
  }

  //Test if other players are unaffected.
  int orig_deck_count = game.deckCount[other_player];
  int orig_hand_count = game.handCount[other_player];
  outpostCardEffect(player, 0, &game);
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
  outpostCardEffect(player, 0, &game);
  game.supplyCount[gardens]--;
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
