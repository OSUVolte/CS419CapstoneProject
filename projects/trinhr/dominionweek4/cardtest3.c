#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the card Village function.
//int villageCard(int currentPlayer, struct gameState *state, int handPos);
// Input:   int currentplayer -> currentplayer
//          struct gameState *state -> data about the game
//          int handPos -> Position of where the card is so it can be discarded later.
//Business Rules:
//1. It adds one card to the player's hand.
//2. The card added has to be from the player's deck.
//3. It gives the player 2 actions. 
//4. Other players' states should be unchanged.

int main () {

  struct gameState actual, expected;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  int num_players = 2;
  initializeGame(num_players, k, 1, &actual);

  int player = 0;
  //Set up player's deck.
  actual.hand[player][0] = village;
  actual.hand[player][1] = gold;
  //+1 card from the deck -1 village card = the same.
  actual.handCount[player] = 2;

  memcpy(&expected, &actual, sizeof(struct gameState));

  //Copy the game state to the pre game state test case.
  assert(memcmp(&expected, &actual, sizeof(struct gameState)) == 0);
  printf("The state of the actual and expected both initialized the same.\n");

  //Set up expected results.
  expected.deckCount[player] = actual.deckCount[player] - 1;
  expected.numActions = 2;

  int handpos = 0;

  if( villageCard(player, &actual, handpos) == 0){
	printf("The village card was called successfully.\n");
  }else{
	printf("The village card failed to be called.i\n");
  }

  //Check results.
  //a card was taken from the deck successfully.
  assert( expected.deckCount[player] == actual.deckCount[player] );
  //+ 1 card from the deck -1 village card. Hand Count should be the same.
  assert( expected.handCount[player] == actual.handCount[player] );
  //Check that the player has two actions left.
  assert( expected.numActions == actual.numActions );
  //Check that the village card is discarded.
  assert( actual.hand[player][0] != village );
  printf("The function executed successfully for the player.\n");

  int player2 = 1;
  //Check that no other players were not altered.
  assert( expected.deckCount[player2] == actual.deckCount[player2] );
  assert( expected.handCount[player2] == actual.handCount[player2] );
  printf("The function didn't alter other player's state.\n");

  return 0;

}

