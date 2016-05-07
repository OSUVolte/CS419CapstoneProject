#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the discardCard function.
//Input:
//int handPos --> Pos of card in Player's Hand to be Discarded.
//int currentPlayer -> whose hand it is.
//struct gameState *state-> state of the game.
//int trashFlag -> 0 = not trashed 1 = trashed.
//Business Rules:
//1. Current Player's hand count is decrememnted by 1.
//2. The card trashed is no longer in the current player's hand.
//3. Handle correctly when the player has one card.
//4. Handle correctly when the player has multiple cards in hand.
int main () {

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState expected, actual;
  int numPlayers = 2;
  int seed = 500;
  int player = 1;  

  initializeGame(numPlayers, k, seed, &actual);

  //Set Up Case
  int handPos = 0;
  int nottrashed = 0;  
 
  actual.handCount[player] = 1;
  actual.hand[player][0] = baron;
  actual.playedCardCount = 0;
  //Copy the game state to the post game state test case.
  memcpy(&expected, &actual, sizeof(struct gameState));
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Both PRE & POST GAME STATES ARE EQUIVALENT before calling the function.\n");

  //Expected Results.
  expected.handCount[player] = actual.handCount[player] - 1;
  expected.playedCardCount = actual.playedCardCount + 1;

  if( discardCard(handPos, player, &actual, nottrashed) == 0){
	printf(" The discardCard() was called successfully for a played card with one card left in the hand.\n");
        assert( expected.handCount[player] == actual.handCount[player]);
        printf(" EXPECTED HAND COUNT: %i ACTUAL HAND COUNT: %i\n", expected.handCount[player], actual.handCount[player]);
        assert( expected.playedCardCount == actual.playedCardCount );
        printf(" EXPECTED PLAYED CARD COUNT: %i ACTUAL PLAYED CARD COUNT: %i\n", expected.playedCardCount, actual.playedCardCount);
        assert( actual.hand[player][handPos] != baron );
        printf(" The card was successfully discarded from the player's hand.\n"); 
  }else{
	printf("The discardCard() failed to be called for a played card with one card left in the hand.i\n");
  }

  struct gameState expected2, actual2;
  initializeGame(numPlayers, k, seed, &actual2);

  //Set Up Case
  int handPos1 = 1;
  int trashed = 1;  
 
  actual2.handCount[player] = 2;
  actual2.hand[player][0] = smithy;
  actual2.hand[player][handPos1] = baron;
  actual2.playedCardCount = 0;
 
 //Copy the game state to the post game state test case.
  memcpy(&expected2, &actual2, sizeof(struct gameState));
  assert(memcmp(&actual2, &expected2, sizeof(struct gameState)) == 0);
  printf("Both PRE & POST GAME STATES ARE EQUIVALENT before calling the function.\n");

  //Expected Results.
  expected2.handCount[player] = actual2.handCount[player] - 1;
  expected2.playedCardCount = actual2.playedCardCount;
 
  if( discardCard(handPos1, player, &actual2, trashed) == 0 ){
	printf("The discardCard() was called successfully for a nonplayed card with multiple cards in hand.\n");
        assert( expected2.handCount[player] == actual2.handCount[player]);
        printf(" EXPECTED HAND COUNT: %i ACTUAL HAND COUNT: %i\n", expected2.handCount[player], actual2.handCount[player]);
        assert( expected2.playedCardCount == actual2.playedCardCount );
        printf(" EXPECTED PLAYED CARD COUNT: %i ACTUAL PLAYED CARD COUNT: %i\n", expected2.playedCardCount, actual2.playedCardCount);
        assert( actual2.hand[player][handPos1] != baron );
        printf(" The card was successfully discarded from the player's hand.\n"); 

  }else{
	printf("The discardCard() failed to be calledi for a nonplayed card with multiple cards in hand.\n");
  }


  return 0;

}
