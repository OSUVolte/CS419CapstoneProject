#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the Card Smithy.
//1. Adds 3 cards to the current player's hand.
//2. The 3 cards have to come from the player's deck.
//3. Other players state must be unchanged. 
//4. No state change should occur to the victory and kingdom card piles. 
int main () {

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState expected, actual;
  int numPlayers = 2;
  int seed = 500;
  int player = 1;  
  int handpos = 0;

  initializeGame(numPlayers, k, seed, &actual);
  actual.hand[player][0] = smithy;  

  //Copy the game state to the post game state test case.
  memcpy(&expected, &actual, sizeof(struct gameState));
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Both PRE & POST GAME STATES ARE EQUIVALENT before calling the function.\n");

  //Set up the Expected Results.
  int discardedSmithy = 1;
  int newCards = 3;

  if( smithyCard(player, &actual, handpos) == 0){
	printf("The smithy card was called successfully.\n");
  }else{
	printf("The smithy card failed to be called.i\n");
  }

  //Set up Expected Results.
  expected.deckCount[player] -= newCards;
  expected.handCount[player] = expected.handCount[player] - discardedSmithy + newCards;

  //smithyCard(currentplayer, &actual, handPos);  
  //1. +3 cards to the current player's hand. 
  assert( actual.deckCount[player] == expected.deckCount[player]);
  printf("The cards were drawn from the player's own deck.\n");

  //2. +3 cards -1 Discarded Smithy Card. 
  assert( actual.handCount[player] == expected.handCount[player]);
  assert( actual.hand[player][handpos] != smithy );
  printf("The player's hand count matched before and after the call to the function.\n");

  int player2 = 1;
  //Check that no other players were altered.
  assert( expected.deckCount[player2] == actual.deckCount[player2] );
  assert( expected.handCount[player2] == actual.handCount[player2] );

  assert(memcmp(&actual.supplyCount, &expected.supplyCount, sizeof(expected.supplyCount)) == 0);
  printf("The kingdom and treasure piles were unaffected./n");

  return 0;
}



