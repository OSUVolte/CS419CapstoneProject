/******************************************************************************
** unittest2.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** This file contains unit tests for the shuffle() function 
******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PLAYERS 4
#define PILES 3  // hand, discard, deck

void testEmptyDeck(struct gameState *state);
void cardCounts(struct gameState*, int[PLAYERS+1][PILES]);
void playerCounts(int[PLAYERS+1][PILES], int[PLAYERS+1][PILES]);


/*enum pile {
	hand = 0,
	deck,
  discard,
  played 
};*/

int main() {
 
  struct gameState state;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                      smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest
  int numPlayers = 2;
  int player;
  int countsBefore[PLAYERS+1][PILES];
  int countsAfter[PLAYERS+1][PILES];

  int i;

  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);

  //test empty deck
  testEmptyDeck(&state);
  
  // test that all card piles remain the same size
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
	cardCounts(&state, countsBefore);
  shuffle(player, &state);
	cardCounts(&state, countsAfter);
  playerCounts(countsBefore, countsAfter);
  /*for (i = 0; i < numPlayers; i++) {
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
  }*/
/*
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
  */  
  return 0;
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

void playerCounts(
	int countsBefore[PLAYERS+1][PILES], 
	int countsAfter[PLAYERS+1][PILES]
	) 
{
  
	int i;

  printf("\n------- Status of Players' Piles -------\n");
	for (i = 0; i < PLAYERS; i++) {	
		printf("Player %d", i);
		printf("\tBefore\tAfter\n");
		printf("  Hand\t\t%d\t%d\n", countsBefore[i][hand], countsAfter[i][hand]); 
		if (countsAfter[i][hand] != countsBefore[i][hand]) {
			printf("ERROR - should not be altered\n");
		}
		printf("  Deck\t\t%d\t%d\n", countsBefore[i][deck], countsAfter[i][deck]); 
		if (countsAfter[i][deck] != countsBefore[i][deck]) {
			printf("ERROR - should not be altered\n");
		}
		printf("  Discard\t%d\t%d\n", countsBefore[i][discard], countsAfter[i][discard]); 
		if (countsAfter[i][discard] != countsBefore[i][discard]) {
			printf("ERROR - should not be altered\n");
		}
	}
}

