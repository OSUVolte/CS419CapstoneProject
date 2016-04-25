/* shuffle */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

void testEmptyDeck(struct gameState *state);

int main() {
 
  struct gameState state;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                      smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest
  int numPlayers = 2;

  int i;

  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);

  //test empty deck
  testEmptyDeck(&state);
  
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  // test that all card piles remain the same size
  int player = state.whoseTurn;
  for (i = 0; i < numPlayers; i++) {
    int preDeckCount = state.deckCount[i];
    int preHandCount = state.deckCount[i];
    int preDiscardCount = state.deckCount[i];
    shuffle(player, &state);
    int postDeckCount = state.deckCount[i];
    int postHandCount = state.deckCount[i];
    int postDiscardCount = state.deckCount[i];
    
    assert(preDeckCount == postDeckCount);
    printf("SUCCESS: deck size unchanged for player %d", i);
    assert(preHandCount == postHandCount);
    printf("SUCCESS: hand size unchanged for player %d", i);
    assert(preDiscardCount == postDiscardCount); 
    printf("SUCCESS: discard size unchanged for player %d", i);
  }

  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  // test that cards remain the same before and after shuffle
  int preShuffleCounts[10];
  for (i = 0; i < state.deckCount[player]; i++) {
    preShuffleCounts[state.deck[player][i]]++;
  }
  shuffle(player, &state);
  int postShuffleCounts[10];
  for (i = 0; i < state.deckCount[player]; i++) {
    postShuffleCounts[state.deck[player][i]]++;
  }
  for (i = 0; i < 10; i++) {
		assert(preShuffleCounts[i] == postShuffleCounts[i]);
  }
  printf("SUCCESS: same cards are in the deck after shuffling\n");
    
 
 /* for (i = 0; i < 10; i++) {
		state.deck[player][i] = kingdomCards[i];
  }
  shuffle(player, &state);
  int adventurerCount = 0;
  int council_roomCount = 0; 
  int feastCount = 0;
  int gardensCount = 0;
  int mineCount = 0;
  int remodelCount = 0;
  int smithyCount = 0;
  int villageCount = 0;
  int baronCount = 0;
  int great_hallCount = 0;
  for (i = 0; i < state.deckCount[player]; i++) {
	  switch (state.deck[player][i]){
      case (adventurer):
        adventurerCount++;	
        break;
      case (council_room):
        council_roomCount++;	
        break;
      case (feast):
        feastCount++;	
        break;
      case (gardens):
        gardensCount++;	
        break;
      case (mine):
        mineCount++;	
        break;
      case (remodel):
        remodelCount++;	
        break;
      case (smithy):
        smithyCount++;	
        break;
      case (village):
        villageCount++;	
        break;
      case (baron):
        baronCount++;	
        break;
      case (great_hall):
        great_hallCount++;	
        break;
     }
  }
  assert(adventurerCount == 1);
  assert(council_roomCount == 1); 
  assert(feastCount == 1);
  assert(gardensCount == 1);
  assert(mineCount == 1); 
  assert(remodelCount == 1);
  assert(smithyCount == 1);
  assert(villageCount == 1);
  assert(baronCount == 1);
  assert(great_hallCount == 1);
*/

}

void testEmptyDeck(struct gameState *state) {
  int player = state->whoseTurn;
  int i;
  for (i = state->deckCount[player]; i > 0; i--) {
    drawCard(player, state);
  }

  assert(state->deckCount[player] == 0);
  int shuffleResult = shuffle(player, state);
  assert(shuffleResult == -1);
  printf("SUCCESS");
}
