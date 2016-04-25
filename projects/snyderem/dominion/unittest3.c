/******************************************************************************
** unittest3.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** This file contains unit tests for the discard() function 
******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PLAYERS 2
#define PILES 3  // hand, discard, deck

void cardCounts(struct gameState*, int[PLAYERS+1][PILES]);
void otherPlayerCounts(int, int[PLAYERS+1][PILES], int[PLAYERS+1][PILES]);
void printComparison(int[PLAYERS+1][PILES], int[PLAYERS+1][PILES]);

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

  int i;
  int player;
  int handPos;
  int countsBefore[PLAYERS+1][PILES];
  int countsAfter[PLAYERS+1][PILES];

  memset(&state, '\0', sizeof(struct gameState)); // clear game state
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  handPos = 0;
  
  printf("****************************************************************\n");
  printf("***                        discard()                         ***\n");
  printf("****************************************************************\n");
  // Trash Flag Not Set
  printf("-------Trash Flag Not Set -------\n");
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
  cardCounts(&state, countsBefore); 
  discardCard(handPos, player, &state, 1);
  cardCounts(&state, countsAfter); 
  if (countsAfter[player][discard] > countsBefore[player][discard]) {
    printf("ERROR: card was added to discard pile\n");
  }
  if (countsAfter[PLAYERS][0] <= countsBefore[PLAYERS][0]) {
    printf("ERROR: Cards played was not increased\n");
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
    cardCounts(&state, countsBefore); 
    discardCard(i, player, &state, 0);
    cardCounts(&state, countsAfter); 
    if (countsAfter[player][discard] <= countsBefore[player][discard]) {
      printf("ERROR: card was not added to discard pile\n");
    }
    if (countsAfter[PLAYERS][0] <= countsBefore[PLAYERS][0]) {
      printf("ERROR: Cards played was not increased\n");
    }
    printComparison(countsBefore, countsAfter);
    otherPlayerCounts(player, countsBefore, countsAfter);
  }

  printf("\n------- Attempt to discard when hand count = 0 -------\n");
  cardCounts(&state, countsBefore); 
  discardCard(i, player, &state, 0);
  cardCounts(&state, countsAfter); 
  if (countsAfter[player][discard] <= countsBefore[player][discard]) {
    printf("ERROR: card was not added to discard pile\n");
  }
  if (countsAfter[PLAYERS][0] <= countsBefore[PLAYERS][0]) {
    printf("ERROR: Cards played was not increased\n");
  }
  otherPlayerCounts(player, countsBefore, countsAfter);
  printComparison(countsBefore, countsAfter);
  
  return 0;
}

/******************************************************************************
** Counts the number of cards in each player's hand, deck and discard pile
** as well as the number of cards in the played card pile. These are saved
** in the 2d array that is passed in as a parameter.
******************************************************************************/
void cardCounts(
  struct gameState   *state, 
  int               counts[PLAYERS+1][PILES]
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
** Compares the number of cards in each player's hand, deck and discard pile
** as well as the played card count. Two arrays with counts to be compared
** must be passed as parameters. Function is successful if the values in all
** are the same before and after. 
******************************************************************************/
void otherPlayerCounts(
  int currentPlayer, 
  int countsBefore[PLAYERS+1][PILES], 
  int countsAfter[PLAYERS+1][PILES]
  ) 
{
  
  int i;
  int bugFound = 0;

  for (i = 0; i < PLAYERS; i++) {
    if (i != currentPlayer) {
      if (countsAfter[i][hand] != countsBefore[i][hand]) {
        printf("  Hand Before: %d After %d\n", countsBefore[i][hand], countsAfter[i][hand]); 
        bugFound = 1;
      }
      if (countsAfter[i][deck] != countsBefore[i][deck]) {
        printf("  Deck Before: %d After %d\n", countsBefore[i][deck], countsAfter[i][deck]); 
        bugFound = 1;
      }
      if (countsAfter[i][discard] != countsBefore[i][discard]) {
        printf("  Discard Before: %d After %d\n", countsBefore[i][discard], countsAfter[i][discard]); 
        bugFound = 1;
      }
    }
  }
  if (!bugFound) {
    printf("SUCCESS: other players' piles were not changed.\n\n");
  }
}


/******************************************************************************
** Prints the number of cards in each player's hand, deck and discard pile
** as well as the played card count. Two arrays with counts to be printed 
** must be passed as parameters. 
******************************************************************************/
void printComparison(
  int countsBefore[PLAYERS+1][PILES], 
  int countsAfter[PLAYERS+1][PILES]
  ) 
{

  int i;
  for (i = 0; i < PLAYERS; i++) {
    printf("Player %d\tBefore\tAfter\n", i);
    printf("  Hand\t\t%d\t%d\n", countsBefore[i][0], countsAfter[i][0]); 
    printf("  Deck\t\t%d\t%d\n", countsBefore[i][1], countsAfter[i][1]); 
    printf("  Discard\t%d\t%d\n", countsBefore[i][2], countsAfter[i][2]); 
  }
  printf("Played Cards -  Before: %d After: %d\n", countsBefore[i][0], countsAfter[i][0]); 
  
}

