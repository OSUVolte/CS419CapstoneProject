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


enum pile {
	hand = 0,
	deck,
  discard,
  played 
};

int main() {
 
  struct gameState state;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, 
													remodel, smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest
  int player;
  int countsBefore[PLAYERS+1][PILES];
  int countsAfter[PLAYERS+1][PILES];
  int i;
  int bugFound = 0;
  int preShuffleCounts[10];
  int postShuffleCounts[10];

  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);

  printf("****************************************************************\n");
  printf("***                        shuffle()                         ***\n");
  printf("****************************************************************\n");
  //test empty deck
  printf("------- TESTING SHUFFLE ON EMPTY DECK -------\n");
  testEmptyDeck(&state);
  
  printf("\n------- TESTING SHUFFLE ON STANDARD DECK -------\n");
  // test that all card piles remain the same size
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
	cardCounts(&state, countsBefore);
  shuffle(player, &state);
	cardCounts(&state, countsAfter);
  playerCounts(countsBefore, countsAfter);

  printf("\n------- TESTING THAT CARDS ARE NOT CHANGED -------\n");
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  // test that cards remain the same before and after shuffle
  for (i = 0; i < state.deckCount[player]; i++) {
    preShuffleCounts[state.deck[player][i]]++;
  }
  shuffle(player, &state);
  for (i = 0; i < state.deckCount[player]; i++) {
    postShuffleCounts[state.deck[player][i]]++;
  }
  for (i = 0; i < 10; i++) {
    printf("Count of card %d - Before: %d  After: %d\n", i, preShuffleCounts[i], postShuffleCounts[i]);
		if(preShuffleCounts[i] != postShuffleCounts[i]) {
      printf("ERROR - count has changed\n");
      bugFound = 1;
    }
  }
  if (!bugFound) {
  	printf("SUCCESS: same cards are in the deck after shuffling\n");
  }
    
  return 0;
}

/******************************************************************************
** Counts the number of cards in each player's hand, deck and discard pile
** as well as the number of cards in the played card pile. These are saved
** in the 2d array that is passed in as a parameter.
******************************************************************************/
void cardCounts(
	struct gameState	*state, 
	int 							counts[PLAYERS+1][PILES]
	) 
{
   
  int i;

  for (i = 0; i < PLAYERS; i++) {
    counts[i][0] = state->handCount[i];
    counts[i][1] = state->deckCount[i];
    counts[i][2] = state->discardCount[i];
  }
  counts[i][0] = state->playedCardCount;		
}

/******************************************************************************
** Attempts the shuffle an empty deck and asserts that -1 is returned from the
** shuffle() function.
******************************************************************************/
void testEmptyDeck(
	struct gameState *state
	) 
{
  int player = state->whoseTurn;
  int i;
  for (i = state->deckCount[player]; i > 0; i--) {
    drawCard(player, state);
  }

  assert(state->deckCount[player] == 0);
  int shuffleResult = shuffle(player, state);
  assert(shuffleResult == -1);
  printf("SUCCESS: -1 returned when empty deck is shuffled\n");
}

/******************************************************************************
** Compares the number of cards in each player's hand, deck and discard pile
** as well as the played card count. Two arrays with counts to be compared
** must be passed as parameters. Function is successful if the values in all
** are the same before and after. 
******************************************************************************/
void playerCounts(
	int countsBefore[PLAYERS+1][PILES], 
	int countsAfter[PLAYERS+1][PILES]
	) 
{
  
	int i;
  int bugFound = 0;

  printf("\n------- Status of Players' Piles -------\n");
	for (i = 0; i < PLAYERS; i++) {	
		printf("Player %d", i);
		printf("\tBefore\tAfter\n");
		printf("  Hand\t\t%d\t%d\n", countsBefore[i][hand], countsAfter[i][hand]); 
		if (countsAfter[i][hand] != countsBefore[i][hand]) {
			printf("ERROR - should not be altered\n");
      bugFound = 1;
		}
		printf("  Deck\t\t%d\t%d\n", countsBefore[i][deck], countsAfter[i][deck]); 
		if (countsAfter[i][deck] != countsBefore[i][deck]) {
			printf("ERROR - should not be altered\n");
      bugFound = 1;
		}
		printf("  Discard\t%d\t%d\n", countsBefore[i][discard], countsAfter[i][discard]); 
		if (countsAfter[i][discard] != countsBefore[i][discard]) {
			printf("ERROR - should not be altered\n");
      bugFound = 1;
		}
	}

  if (!bugFound) {
		printf("SUCCESS: no card piles were changed\n");
  }
}

