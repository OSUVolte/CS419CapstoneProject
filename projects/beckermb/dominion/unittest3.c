#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


//This is a test of the fullDeckCount method in dominion.c

int main () {

  printf("******** Testing fullDeckCount **********\n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int player = 0;
  initializeGame(2, cards, 1, &game);
  int counter;

  //When no instances of card, expect 0
  counter = fullDeckCount(player, smithy, &game);
  if (counter == 0) {
    printf("Correctly returned 0 when no instances.\n");
  } else {
    printf("FAIL: returned %d when no instances.\n", counter);
  }

  //When card is in hand, expect 1
  game.hand[player][0] = smithy;
  counter = fullDeckCount(player, smithy, &game);
  if (counter == 1) {
    printf("Correctly returned 1 when instance in hand.\n");
  } else {
    printf("FAIL: returned %d when 1 instance.\n", counter);
  }

  //When card also in another player's hand, expect 1
  game.hand[player + 1][0] = smithy;
  counter = fullDeckCount(player, smithy, &game);
  if (counter == 1) {
    printf("Correctly returned 1 when 2 instances, but 1 in other players hand.\n");
  } else {
    printf("FAIL: returned %d when 2 instances, but 1 in other players hand.\n", counter);
  }

  //When card in player's Deck, expect 2
  game.deckCount[player] = 1;
  game.deck[player][0] = smithy;
  counter = fullDeckCount(player, smithy, &game);
  if (counter == 2) {
    printf("Correctly returned 2 when instance in hand and deck.\n");
  } else {
    printf("FAIL: returned %d when 2 instances (hand and deck).\n", counter);
  }

  //When card in player's Discard, expect 3
  game.discardCount[player] = 1;
  game.discard[player][0] = smithy;
  counter = fullDeckCount(player, smithy, &game);
  if (counter == 3) {
    printf("Correctly returned 3 when instance in hand and deck, and discard.\n");
  } else {
    printf("FAIL: returned %d when 3 instances (hand and deck, discard).\n", counter);
  }

  //With additional cards in deck and discard, should still be 3
  game.discardCount[player] = 3;
  game.deckCount[player] = 3;
  game.deck[player][1] = village;
  game.deck[player][2] = great_hall;
  game.discard[player][1] = council_room;
  game.discard[player][2] = adventurer;
  counter = fullDeckCount(player, smithy, &game);
  if (counter == 3) {
    printf("Correctly returned 3 with deck/hand/discard seeded.\n");
  } else {
    printf("FAIL: returned %d when 3 instances but other cards in hand/deck/discard.\n", counter);
  }

  //With additional cards at end of hand, deck, discard, expect 6
  game.hand[player][game.handCount[player] - 1] = smithy;
  game.discard[player][2] = smithy;
  game.deck[player][2] = smithy;
  counter = fullDeckCount(player, smithy, &game);
  if (counter == 6) {
    printf("Correctly counted cards at ends of hand, deck, discard.\n");
  } else {
    printf("FAIL: returned %d when 6 instances (including end of hand/deck/discard arrays).\n", counter);
  }
}
