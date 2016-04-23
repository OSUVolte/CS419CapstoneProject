#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


// This is a test for the adventurer card / function from dominion.c


//
// int adventurerCardEffect(int currentPlayer, int handPos, struct gameState *state) {
//   int cardDrawn; //temp storage for card drawing
//   int drawntreasure = 0; //counter for treasure drawn
//   int z = 0; //counter for temp hand
//   int temphand[7]; //array to hold hands temporarily drawn
//
//   while (drawntreasure < 2) {
//     if (state->deckCount[currentPlayer] < 1) { //if the deck is empty we need to shuffle discard and add to deck
//       shuffle(currentPlayer, state);
//     }
//     drawCard(currentPlayer, state);
//
//     cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1]; //top card of hand is most recently drawn card.
//     if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
//       drawntreasure++;
//     else {
//       temphand[z] = cardDrawn;
//       state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
//       z++;
//     }
//   }
//   while (z - 1 >= 0) {
//     state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
//     z = z - 1;
//   }
//
//   return 0;
// }

int main() {
  printf("*** Testing adventurerCardEffect *** \n");

  struct gameState game;
  int cards[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
  int all_cards[17] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, copper, silver, gold, estate, duchy, province, curse };
  int player = 0;
  int other_player = 1;
  initializeGame(2, cards, 1, &game);

  //Test if two treatures added to hand with normal deck

  //Test if two treatures added to hand with empty deck

  //Test to make sure only two cards added to hand

  //Test to make sure additional treasures not added to deck

  //Test to make sure adventurer card is discarded

  //Test to make sure other player unaffected

  //Test to make sure global supply unaffected
}
