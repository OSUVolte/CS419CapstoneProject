#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


//This is a test of the fullDeckCount method in dominion.c

int main () {

  printf("Testing fullDeckCount\n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int player = 0;
  initializeGame(2, cards, 1, &game);

  //When no instances of card, expect 0
  assert(fullDeckCount(player, smithy, &game) == 0);

  //When card is in hand, expect 1
  game.hand[player][0] = smithy;
  assert(fullDeckCount(player, smithy, &game) == 1);

  //When card also in another player's hand, expect 1
  game.hand[player + 1][0] = smithy;
  assert(fullDeckCount(player, smithy, &game) == 1);

  //When card in player's Deck, expect 2
  game.deckCount[player] = 1;
  game.deck[player][0] = smithy;
  assert(fullDeckCount(player, smithy, &game) == 2);

  //When card in player's Discard, expect 3
  game.discardCount[player] = 1;
  game.discard[player][0] = smithy;
  assert(fullDeckCount(player, smithy, &game) == 3);

  //With additional cards in deck and discard, should still be 3
  game.discardCount[player] = 3;
  game.deckCount[player] = 3;
  game.deck[player][1] = village;
  game.deck[player][2] = great_hall;
  game.discard[player][1] = council_room;
  game.discard[player][2] = adventurer;
  assert(fullDeckCount(player, smithy, &game) == 3);

  //With additional cards at end of hand, deck, discard, expect 6
  game.hand[player][game.handCount[player] - 1] = smithy;
  game.discard[player][2] = smithy;
  game.deck[player][2] = smithy;
  assert(fullDeckCount(player, smithy, &game) == 6);

  printf("Deck Count: %d\n", fullDeckCount(1, smithy, &game));

}
