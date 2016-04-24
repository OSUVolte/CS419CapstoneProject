#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the card cutPurse function.
//Business Rules:
//1. The Player gets 2 coins.
//2. Other players have to discard a copper if they heve one.
//3. If the other players don't have a copper they show their hand.
//4. No other state change should occur.
//
int cutPurseCard(int currentPlayer, struct gameState *state, int handPos);

int main () {

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState expected, actual;
  int numPlayers = 2;
  int seed = 500;
  int player = 0;  
  int handpos = 0;

  initializeGame(numPlayers, k, seed, &actual);

  //Case for when the other player has a copper.
  int player2 = 1;
  //Set up player decks.
  actual.discardCount[player] = 0;
  actual.handCount[player] = 1;
  actual.hand[player][0] = cutpurse;
  actual.hand[player2][0] = village;
  actual.hand[player2][1] = copper;
  actual.handCount[player2] = 2;
  actual.coins = 0;

  //Copy the game state to the post game state test case.
  memcpy(&expected, &actual, sizeof(struct gameState));
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Both PRE & POST GAME STATES ARE EQUIVALENT before calling the function.\n");
 
 //Set up Expected Results for current Player after Playing the Card.
  expected.coins = actual.coins + 2;
  expected.handCount[player] -= 1;
  expected.discardCount[player] = actual.discardCount[player] + 1;
  expected.handCount[player2] = actual.handCount[player2] - 1;  
  expected.discardCount[player2] = actual.discardCount[player2] + 1;

  if( cutPurseCard(player, &actual, handpos) == 0){
	printf("The cutPurse card was called successfully.\n");
  }else{
	printf("The cutPurse card failed to be called.i\n");
  }

  //Set up exptected results for other player.
//  expected.handCount[player2] -= 1;
 // expected.discardCount[player2] += 1;
  
  //1.Current Player Gains 2 coins.
  //2.No other state change for the player.
  printf("EXPECTED COINS: %i, ACTUAL: %i\n", expected.coins, actual.coins);
  assert( expected.coins == actual.coins );
  printf("EXPECTED HAND COUNT: %i ACTUAL HAND COUNT: %i for CURRENT PLAYER.\n", expected.handCount[player], actual.handCount[player]);
  assert( expected.handCount[player] == actual.handCount[player] );
  printf("EXPECTED DISCARD COUNT: %i ACTUAL DISCARD COUNT: %i for CURRENT PLAYER.\n", expected.discardCount[player], actual.discardCount[player]);
//  assert( expected.discardCount[player] == actual.discardCount[player] ); 
  
  //Check that other players lose a copper.
//  assert( actual.handCount[player2] == expected.handCount[player2] );
  assert( actual.hand[player2][1] != copper );
  assert( actual.handCount[player2] == expected.handCount[player2]);
 // assert( actual.discardCount[player2] == expected.discardCount[player2]);
/*

  assert(memcmp(&actual.supplyCount, &expected.supplyCount, sizeof(expected.supplyCount)) == 0);
  printf("The kingdom and treasure piles were unaffected./n");
*/
  return 0;
 
}				




