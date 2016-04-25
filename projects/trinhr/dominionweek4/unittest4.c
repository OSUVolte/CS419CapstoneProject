#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the fullDeckCount() function.
//Input:
// fullDeckCount(int player, int card, struct gameState *state);
/* Here deck = hand + discard + deck */
//Business Rules:
//1. It needs to count out the correct number of the full deck. 
//2. The hand, discard, and deck amounts should not change. 
//3. Rest of the game state is unchanged. 
int main () {

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState expected, actual;
  int numPlayers = 2;
  int seed = 500;
  int player = 1;  

  initializeGame(numPlayers, k, seed, &actual);
  int card = 1;
  actual.handCount[player] = 3;
  actual.hand[player][0] = card;
  actual.hand[player][1] = card;
  actual.hand[player][2] = card;

  actual.deckCount[player] = 3;
  actual.deck[player][0] = card;
  actual.deck[player][1] = card;
  actual.deck[player][2] = card;

  actual.discardCount[player] = 3;
  actual.discard[player][0] = card;
  actual.discard[player][1] = card;
  actual.discard[player][2] = card;

  int fullDeck = 9;
  //Copy the game state to the post game state test case.
  memcpy(&expected, &actual, sizeof(struct gameState));
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Both PRE & POST GAME STATES ARE EQUIVALENT before calling the function.\n");

  assert( fullDeckCount(player, card, &actual) == fullDeck );
  printf("The player's full deck count was calculated correctly.\n");
  assert( expected.handCount[player] == actual.handCount[player] );
  assert( expected.deckCount[player] == actual.deckCount[player] );
  assert( expected.discardCount[player] == actual.discardCount[player] );
  printf( "The player's hand, deck, discard count piles were not altered.\n");
  assert(memcmp( &expected, &actual, sizeof(struct gameState)) == 0); 
  printf("The game state was unaltered.\n");

  return 0;

}


