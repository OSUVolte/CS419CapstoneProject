/* greatHall 
http://wiki.dominionstrategy.com/index.php/Great_Hall
When you play it, you draw a card and may play another Action.*/
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

void testNone(struct gameState*, int);
void printResults(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);  

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
  int bonus;
  int countsBefore[PLAYERS+1][3];
  int countsAfter[PLAYERS+1][3];
  int i;
  int deckSize;
  int handSize;
  int playedCount;
  int discardSize;
	int handPos = 0;
  int actionsBefore;
  int actionsAfter;
 
  memset(&state, '\0', sizeof(struct gameState)); // clear game state

  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  deckSize = state.deckCount[player];
  handSize = state.handCount[player];
  playedCount = state.playedCardCount;
  discardSize = state.discardCount[player];

  for (i = 0; i < handSize; i++) {
		state.hand[player][i] = minion;
  }

  for (i = 0; i < deckSize; i++) {
		if (i == handPos) {
	  	state.deck[player][i] = great_hall;
		}
		else {
	  	state.deck[player][i] = mine;
		}
  }

	cardCounts(&state, countsBefore);
  actionsBefore = state.numActions;
	cardEffect(great_hall, -1, -1, -1, &state, handPos, &bonus);
  actionsAfter = state.numActions;
	cardCounts(&state, countsAfter);
	// After: hand + 1, numActions + 1, discard card

  printResults(handSize, state.handCount[player], handSize, deckSize, 
               state.deckCount[player], deckSize - 1, discardSize, 
               state.discardCount[player], discardSize + 1, playedCount, 
               state.playedCardCount, playedCount + 1, actionsBefore, 
							 actionsAfter, actionsBefore + 1);

	otherPlayerCounts(player, countsBefore, countsAfter);

  return 0;
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
  int actionsBefore,
	int actionsAfter,
	int actionsDesired
  )
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
	printf("Actions\t%d\t%d", actionsBefore, actionsAfter);
  if (actionsAfter != actionsDesired) {
    printf("\tERROR - should be %d\n", actionsDesired);
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

