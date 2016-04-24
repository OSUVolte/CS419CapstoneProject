/* adventurer */
/* Reveal cards from your deck until you reveal 2 Treasure cards. 
Put those Treasure cards into your hand and discard the other revealed cards.*/
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

void testFirst(struct gameState*, int, int);
void testLast(struct gameState*, int, int);
void testMiddle(struct gameState*, int, int);
void testAll(struct gameState*, int, int);
void testNone(struct gameState*, int);
void printResults(int, int, int, int, int, int, int, int, int, int, int, int, int, int);  

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
  int countsBefore[PLAYERS+1][3];
  int countsAfter[PLAYERS+1][3];

  memset(&state, '\0', sizeof(struct gameState)); // clear game state

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  cardCounts(&state, countsBefore);
  adventurerEffect(player, &state);
  cardCounts(&state, countsAfter);
  otherPlayerCounts(player, countsBefore, countsAfter);
  
  
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testFirst(&state, player, copper); 
  
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testMiddle(&state, player, copper); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testLast(&state, player, copper); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testAll(&state, player, copper); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testFirst(&state, player, silver); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testMiddle(&state, player, silver); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testLast(&state, player, silver); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testAll(&state, player, silver); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testFirst(&state, player, gold); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testMiddle(&state, player, gold); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testLast(&state, player, gold); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testAll(&state, player, gold); 

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  testNone(&state, player);

  return 0;
}

void testFirst(
	struct gameState  *state, 
	int 							player, 
	int 							treasureType
	) 
{

  int i;
  int handSizeAfter; 

  int deckSize = state->deckCount[player];
  int handSize = state->handCount[player];
  int playedCount = state->playedCardCount;
  int discardSize = state->discardCount[player];
  int treasureCount = 0;


  printf("\n------- First Card -------\n");
  for (i = 0; i < handSize; i++) {
		state->hand[player][i] = minion;
  }

  state->deck[player][0] = treasureType;
  for (i = 1; i < deckSize; i++) {
	  state->deck[player][i] = mine;
  }
  
  adventurerEffect(player, state);
  
  handSizeAfter = state->handCount[player];
  for (i = 0; i < handSizeAfter; i++) {
    if (state->hand[player][i] == treasureType) {
      treasureCount++;
    }
  }

  printResults(handSize, handSizeAfter, handSize + 1, deckSize, 
               state->deckCount[player], 0, discardSize, 
               state->discardCount[player], discardSize + deckSize, playedCount, 
               state->playedCardCount, playedCount + 1, treasureCount, 1);
}

void testLast(
	struct gameState  *state, 
	int 							player, 
	int 							treasureType
  ) 
{

  int i;
  int handSizeAfter; 

  int deckSize = state->deckCount[player];
  int handSize = state->handCount[player];
  int playedCount = state->playedCardCount;
  int discardSize = state->discardCount[player];
  int treasureCount = 0;


  printf("\n------- Last Card -------\n");
  for (i = 0; i < handSize; i++) {
		state->hand[player][i] = minion;
  }

  for (i = 0; i < deckSize - 1; i++) {
	  state->deck[player][i] = mine;
  }
  state->deck[player][i] = treasureType;
  
  adventurerEffect(player, state);

  handSizeAfter = state->handCount[player];
  for (i = 0; i < handSizeAfter; i++) {
    if (state->hand[player][i] == treasureType) {
      treasureCount++;
    }
  }
 
  printResults(handSize, handSizeAfter, handSize + 1, deckSize, 
               state->deckCount[player], 0, discardSize, 
               state->discardCount[player], discardSize + deckSize, playedCount, 
               state->playedCardCount, playedCount + 1, treasureCount, 1);

}

void testMiddle(
 	struct gameState  *state, 
	int 							player, 
	int 							treasureType
  ) 
{

  int i;
  int middle;
  int handSizeAfter; 

  int deckSize = state->deckCount[player];
  int handSize = state->handCount[player];
  int playedCount = state->playedCardCount;
  int discardSize = state->discardCount[player];
  int treasureCount = 0;

  printf("\n------- Middle Card -------\n");
  for (i = 0; i < handSize; i++) {
		state->hand[player][i] = minion;
  }

  middle = deckSize/2;
  for (i = 0; i < deckSize; i++) {
    if (i == middle) {
      state->deck[player][i] = treasureType;
    }
    else {
	    state->deck[player][i] = mine;
    }
  }
  
  adventurerEffect(player, state);
  
  handSizeAfter = state->handCount[player];
  for (i = 0; i < handSizeAfter; i++) {
    if (state->hand[player][i] == treasureType) {
      treasureCount++;
    }
  }

  printResults(handSize, handSizeAfter, handSize + 1, deckSize, 
               state->deckCount[player], 0, discardSize, 
               state->discardCount[player], discardSize + deckSize, playedCount, 
               state->playedCardCount, playedCount + 1, treasureCount, 1);

}

void testAll(
 	struct gameState  *state, 
	int 							player, 
	int 							treasureType
  ) 
{

  int i;
  int handSizeAfter; 

  int deckSize = state->deckCount[player];
  int handSize = state->handCount[player];
  int playedCount = state->playedCardCount;
  int discardSize = state->discardCount[player];
  int treasureCount = 0;

  printf("\n------- All Treasure Cards -------\n");
  for (i = 0; i < handSize; i++) {
		state->hand[player][i] = minion;
  }

  for (i = 0; i < deckSize; i++) {
	  state->deck[player][i] = treasureType;
  }
  
  adventurerEffect(player, state);

  handSizeAfter = state->handCount[player];
  for (i = 0; i < handSizeAfter; i++) {
    if (state->hand[player][i] == treasureType) {
      treasureCount++;
    }
  }

  printResults(handSize, handSizeAfter, handSize + 2, deckSize, 
               state->deckCount[player], deckSize - 2, discardSize, 
               state->discardCount[player], discardSize, playedCount, 
               state->playedCardCount, playedCount + 1, treasureCount, 2);
}

void testNone(
 	struct gameState  *state, 
	int 							player 
  ) 
{

  int i;
  int handSizeAfter; 

  int deckSize = state->deckCount[player];
  int handSize = state->handCount[player];
  int playedCount = state->playedCardCount;
  int discardSize = state->discardCount[player];
  int treasureCount = 0;

  printf("\n------- No Treasure Cards -------\n");
  for (i = 0; i < handSize; i++) {
		state->hand[player][i] = minion;
  }

  for (i = 0; i < deckSize; i++) {
	  state->deck[player][i] = mine;
  }
  
  adventurerEffect(player, state);

  handSizeAfter = state->handCount[player];
  for (i = 0; i < handSizeAfter; i++) {
    if (state->hand[player][i] != mine) {
      treasureCount++;
    }
  }

  printResults(handSize, handSizeAfter, handSize, deckSize, 
               state->deckCount[player], 0, discardSize, 
               state->discardCount[player], discardSize + deckSize, playedCount, 
               state->playedCardCount, playedCount + 1, treasureCount, 0);
}

void printResults(  
  int	handBefore, 
  int	handAfter, 
  int handDesired,
	int	deckBefore, 
	int	deckAfter, 
  int deckDesired,
	int	discardBefore,
  int	discardAfter, 
  int discardDesired,
	int	playedBefore, 
	int playedAfter, 
  int playedDesired,
	int treasure,
  int treasureDesired)  
{
  printf("\tBefore\tAfter\n");

  printf("Hand\t%d\t%d", handBefore, handAfter);
  if (handAfter != handDesired) {
    printf("\tERROR - should be %d\n", handDesired);
  }
  else {
    printf("\n");
  }

  printf("Deck\t%d\t%d", deckBefore, deckAfter);
  if (deckAfter != deckDesired) {
    printf("\tERROR - should be %d\n", deckDesired);
  }
  else {
    printf("\n");
  }

  printf("Discard\t%d\t%d", discardBefore, discardAfter);
  if (discardAfter != discardDesired) {
    printf("\tERROR - should be %d\n", discardDesired);
  }
  else {
    printf("\n");
  }
  printf("Played\t%d\t%d", playedBefore, playedAfter);
  if (playedAfter != playedDesired) {
    printf("\tERROR - should be %d\n", playedDesired);
  }
  else {
    printf("\n");
  }
  printf("Treasure\t%d", treasure);
  if (treasure != treasureDesired) {
    printf("\tERROR - should be %d\n", treasureDesired);
  }
  else {
    printf("\n");
  }

}

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

void otherPlayerCounts(
	int	currentPlayer, 
	int countsBefore[PLAYERS+1][PILES], 
	int countsAfter[PLAYERS+1][PILES]
	) 
{
  
	int i;

  printf("\n------- Status of Other Players' Piles -------\n");
	for (i = 0; i < PLAYERS; i++) {	
		printf("Player %d", i);
		if (i != currentPlayer) {
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
		else {
			printf(" - current player\n");
		}
	}
}

