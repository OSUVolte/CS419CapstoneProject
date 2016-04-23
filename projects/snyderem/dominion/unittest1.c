/* endTurn */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>

int main() {
  struct gameState state;
  kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                      smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest


  int k;
  int i;
  int currentPlayer = whoseTurn(&state);


  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  
  initializeGame(numPlayers, kingdomCards[10], randomSeed, &state);
  
  // Set hand for currentPlayer
  int numTestCards = 3;
  state.handCount[currentPlayer] = numTestCards; 
  for (i = 0; i < state.handCount[currentPlayer]; i++) {
	  state.hand[currentPlayer][i] = mine;
  } 


  //Discard hand
  for (i = 0; i < state.handCount[currentPlayer]; i++){
    state.discard[currentPlayer][state.discardCount[currentPlayer]++] = state.hand[currentPlayer][i];//Discard
    state.hand[currentPlayer][i] = -1;//Set card to -1
  }
  state.handCount[currentPlayer] = 0;//Reset hand count
    
  //Code for determining the player
  if (currentPlayer < (state.numPlayers - 1)){ 
    state.whoseTurn = currentPlayer + 1;//Still safe to increment
  }
  else{
    state.whoseTurn = 0;//Max player has been reached, loop back around to player 1
  }

  state.outpostPlayed = 0;
  state.phase = 0;
  state.numActions = 1;
  state.coins = 0;
  state.numBuys = 1;
  state.playedCardCount = 0;
  state.handCount[state.whoseTurn] = 0;

  //int k; move to top
  //Next player draws hand
  for (k = 0; k < 5; k++){
    drawCard(state.whoseTurn, state);//Draw a card
  }

  return 0;
}
