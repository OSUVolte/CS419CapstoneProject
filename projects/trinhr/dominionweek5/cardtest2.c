#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the card Adventurer function.
//int adventurerCard(struct gameState *state, int currentPlayer, int handPos);
//Input: int currentplayer --> current player
//	 struct gamestate
//	 int handPos
//Business Rules:
//1. It needs to draw cards from the players own deck until
//two treasure cards are revealed. 
//2. The two treasure cards are added to the the player's hand.
//3. The non-treasure cards drawn need to be discarded.
//4. Other players state should be unchanged.
//5. The supplyCount should be unchanged. 


int main () {

  struct gameState actual, expected;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  int num_players = 2;
  initializeGame(num_players, k, 1, &actual);

  int player = 0;
  int handpos = 0;
  //Set up player's deck.
  actual.deckCount[player] = 5;
  actual.deck[player][0] = village;
  actual.deck[player][1] = gold;
  actual.deck[player][2] = smithy;
  actual.deck[player][3] = feast;
  actual.deck[player][4] = copper;

  //Set up player's hand.
  actual.handCount[player] = 2;
  actual.hand[player][0] = adventurer;
  actual.hand[player][1] = mine;
  
  actual.discardCount[player] = 0;

  memcpy(&expected, &actual, sizeof(struct gameState));
  //Copy the game state to the pre game state test case.
  assert(memcmp(&expected, &actual, sizeof(struct gameState)) == 0);
  printf("The state of the actual and expected both initialized in the same state.\n");

  //Expected Results
  int discarded = 2;
  int discarded_adventurer = 1;
  int treasure_cards = 2;
  expected.handCount[player] = actual.handCount[player] - discarded_adventurer + treasure_cards;
  expected.deckCount[player] -= treasure_cards;
  expected.deckCount[player] -= discarded;
  expected.discardCount[player] = discarded_adventurer + discarded; 
 

  if( adventurerCard(&actual, player, handpos) == 0){
	printf("The adventurer card was called successfully.\n");
  }else{
	printf("The adventurer card failed to be called.i\n");
  }


  printf("ACTUAL HANDCOUNT:%i EXPECTED HANDCOUNT: %i\n", actual.handCount[player], expected.handCount[player]);
  assert( actual.handCount[player] == expected.handCount[player]);
  assert( actual.hand[player][handpos] != adventurer );

  printf("ACTUAL DISCARD COUNT:%i EXPECTED DISCARD COUNT: %i\n", actual.discardCount[player], expected.discardCount[player]);
 // assert( expected.discardCount[player] == actual.discardCount[player] );
 
  printf("ACTUAL DECKCOUNT:%i EXPECTED DECKCOUNT: %i\n", actual.deckCount[player], expected.deckCount[player]);
 // assert( actual.deckCount[player] == expected.deckCount[player]);

  
  int player2 = 1;
  //Check that no other players were altered.
  assert( expected.deckCount[player2] == actual.deckCount[player2] );
  assert( expected.handCount[player2] == actual.handCount[player2] );

  assert(memcmp(&actual.supplyCount, &expected.supplyCount, sizeof(expected.supplyCount)) == 0);
  printf("The kingdom and treasure piles were unaffected./n");

  return 0;
}
