/* smithy */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PLAYERS 2
#define PILES 3  // hand, discard, deck

void cardCounts(struct gameState *state, int counts[PLAYERS+1][PILES]);
int otherPlayerCounts(int currentPlayer, int countsBefore[PLAYERS+1][PILES], int countsAfter[PLAYERS+1][PILES]);
int printComparison(int countsBefore[PLAYERS+1][PILES], int countsAfter[PLAYERS+1][PILES]);

enum pile 
  {hand = 0,
   deck,
   discard,
   played };


int main() {
 
  struct gameState state;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                      smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest

  int i;
  int player;
  int handPos;
  int handCount;
  int countsBefore[PLAYERS+1][3];
  int countsAfter[PLAYERS+1][3];

  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  handPos = 0;
  
  printf("\n------- Two extra cards in deck -------\n");
	countsBefore[PLAYERS+1][3];
	countsAfter[PLAYERS+1][3];
	cardCounts(&state, countsBefore); 
  state.hand[player][handPos] = smithy;
  smithyEffect(player, &state, handPos);
	cardCounts(&state, countsAfter); 
	if (countsAfter[player][deck] != (countsBefore[player][deck] - 3)) {
  	printf("ERROR three cards were not removed from the deck\n");
	}
  if (countsAfter[player][hand] != (countsBefore[player][hand] + 2)) { 
  	printf("ERROR three cards were not added and one discarded from hand for a total of +2\n");
	}
  if (countsAfter[PLAYERS][0] != (countsBefore[PLAYERS][0] + 1)) {
  	printf("ERROR card was not added to played cards count\n");
	}

  assert(otherPlayerCounts(player, countsBefore, countsAfter) == 0);
  printComparison(countsBefore, countsAfter);
  
  return 0;
}

void cardCounts(struct gameState *state, int counts[PLAYERS+1][PILES]) {
   
  int i;
  for (i = 0; i < PLAYERS; i++) {
    counts[i][0] = state->handCount[i];
    counts[i][1] = state->deckCount[i];
    counts[i][2] = state->discardCount[i];
  }
  counts[i][0] = state->playedCardCount;		
  return counts;
}

int otherPlayerCounts(int currentPlayer, int countsBefore[PLAYERS+1][PILES], int countsAfter[PLAYERS+1][PILES]) {
  
	int i;
	for (i = 0; i < PLAYERS; i++) {
		if (i != currentPlayer && countsAfter[i][hand] != countsBefore[i][hand]) {
				printf("  Hand Before: %d After %d\n", countsBefore[i][hand], countsAfter[i][hand]); 
				return 1;
		}
		if (i != currentPlayer && countsAfter[i][deck] != countsBefore[i][deck]) {
			printf("  Deck Before: %d After %d\n", countsBefore[i][deck], countsAfter[i][deck]); 
			return 1;
		}
		if (i != currentPlayer && countsAfter[i][discard] != countsBefore[i][discard]) {
			printf("  Discard Before: %d After %d\n", countsBefore[i][discard], countsAfter[i][discard]); 
			return 1;
		}
	}
  return 0;
}


int printComparison(int countsBefore[PLAYERS+1][PILES], int countsAfter[PLAYERS+1][PILES]) {

  int i;
  for (i = 0; i < PLAYERS; i++) {
    printf("Player %d\n", i);
		printf("  Hand Count Before: %d After %d\n", countsBefore[i][0], countsAfter[i][0]); 
		printf("  Deck Count Before: %d After %d\n", countsBefore[i][1], countsAfter[i][1]); 
		printf("  Discard Before: %d After %d\n", countsBefore[i][2], countsAfter[i][2]); 
  }
	printf("Played Card Count Before: %d After %d\n", countsBefore[i][0], countsAfter[i][0]); 
  
  return 0;
}

