/* whoseTurn */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
 
  struct gameState state;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                      smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest
  int numPlayers = 4;

  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);

  int i;
  for (i = 0; i < numPlayers; i++) {
    printf("Turn: %d\n", whoseTurn(&state));
    assert(whoseTurn(&state) == i);
    playCard(0, -1, -1, -1, &state);
    endTurn(&state);
  }
  
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  state.whoseTurn = 10;
  assert(whoseTurn(&state) == 10);
  return 0;
}
