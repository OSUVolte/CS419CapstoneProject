/* discardCard */
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
  
  // Trash Flag Not Set
  printf("-------Trash Flag Not Set -------\n");
  countsBefore[PLAYERS+1][3];
  countsAfter[PLAYERS+1][3];
  cardCounts(&state, countsBefore); 
  discardCard(handPos, player, &state, 0);
  cardCounts(&state, countsAfter); 
  if (countsAfter[player][discard] <= countsBefore[player][discard]) {
		printf("ERROR card was not added to discard pile\n");
  }
  if (countsAfter[PLAYERS][0] <= countsBefore[PLAYERS][0]) {
		printf("ERROR Cards played was not increased\n");
  }
  otherPlayerCounts(player, countsBefore, countsAfter);
  printComparison(countsBefore, countsAfter);

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  handPos = 0;

  // Trash Flag Set
  printf("\n-------Trash Flag Set -------\n");
  countsBefore[PLAYERS+1][3];
  countsAfter[PLAYERS+1][3];
  cardCounts(&state, countsBefore); 
  discardCard(handPos, player, &state, 1);
  cardCounts(&state, countsAfter); 
  if (countsAfter[player][discard] > countsBefore[player][discard]) {
		printf("ERROR card was added to discard pile\n");
  }
  if (countsAfter[PLAYERS][0] <= countsBefore[PLAYERS][0]) {
		printf("ERROR Cards played was not increased\n");
  }
  otherPlayerCounts(player, countsBefore, countsAfter);
  printComparison(countsBefore, countsAfter);

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;

  // Discard all cards in hand
  printf("\n------- Discard all cards -------\n");
  int cards = state.handCount[player]; 
  for (i = 0; i < cards; i++) {
    printf("CARD %d\n", i);
		countsBefore[PLAYERS+1][3];
		countsAfter[PLAYERS+1][3];
		cardCounts(&state, countsBefore); 
		discardCard(i, player, &state, 0);
		cardCounts(&state, countsAfter); 
		if (countsAfter[player][discard] <= countsBefore[player][discard]) {
			printf("ERROR card was not added to discard pile\n");
		}
		if (countsAfter[PLAYERS][0] <= countsBefore[PLAYERS][0]) {
			printf("ERROR Cards played was not increased\n");
		}
    otherPlayerCounts(player, countsBefore, countsAfter);
		printComparison(countsBefore, countsAfter);
  }

  printf("\n------- Attempt to discard when hand count = 0 -------\n");
  printf("CARD %d\n", i);
	countsBefore[PLAYERS+1][3];
	countsAfter[PLAYERS+1][3];
	cardCounts(&state, countsBefore); 
	discardCard(i, player, &state, 0);
	cardCounts(&state, countsAfter); 
	if (countsAfter[player][discard] <= countsBefore[player][discard]) {
  	printf("ERROR card was not added to discard pile\n");
	}
	if (countsAfter[PLAYERS][0] <= countsBefore[PLAYERS][0]) {
		printf("ERROR Cards played was not increased\n");
  }
  otherPlayerCounts(player, countsBefore, countsAfter);
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

