
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_PLAYERS 4
#define MIN_PLAYERS 2 
#define MAX_CARD 27

int setDeck(struct gameState*, int, int);
int checkResults(struct gameState*, struct gameState*, int, int, int);

int main () {

  struct gameState preState;
  struct gameState postState;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, 
                          remodel, smithy, village, baron, great_hall};
  int randomSeed = 1000;   // from example unittest
  srand(time(0));

	// current player loop through the max number of players
  int t;
  int i;
  int numPlayers;
  int player = 0; // always test first player
  int amountTreasure;
  int cardsDrawn;
  int results;



  for (t = 0; t < 10000; t++) {
  	printf("******************* TEST #%d *******************\n", t);
    
  	numPlayers = rand() % (MAX_PLAYERS - 1) + MIN_PLAYERS; 
		memset(&preState, 23, sizeof(struct gameState));
		initializeGame(numPlayers, kingdomCards, randomSeed, &preState);

    for (i = 0; i < preState.deckCount[player]; i++) {
			preState.deck[player][i] = mine;
		}

    amountTreasure = rand() % preState.deckCount[player];

    cardsDrawn = setDeck(&preState, player, amountTreasure); 
    memcpy(&postState, &preState, sizeof(struct gameState)); 
    printf("Treasure Added: %d Cards Drawn: %d\n", amountTreasure, cardsDrawn);

    adventurerEffect(player, &postState);
    
    results = checkResults(&preState, &postState, amountTreasure, cardsDrawn, player);
		if (results == -1) {
			printf("TEST FAILED\n");
		}
    else {
			printf("TEST PASSED\n");
		}
  	printf("************************************************\n");
  }

	return 0;
}

int setDeck(struct gameState *state, int player, int amount) {

  int i;
  int count = 0;
  int duplicate;
  int treasureTypes = 3;
  int position;
  int positions[amount];
	int type;

	while (count < amount) {
    duplicate = FALSE;
		position = rand() % state->deckCount[player];
		for (i = 0; i < count; i++) {
			if (position == positions[i]) {
				duplicate = TRUE;
				break;
			} 
		}
		if (!duplicate) {
			positions[count] = position;
			count++;
		}
 	}
 	for (i = 0; i < count; i++) {
	  type = rand() % treasureTypes;
	  position = positions[i];

		switch (type) {
			case 0:
				state->deck[player][position] = copper;
        printf("Copper [%d] ", position);
				break;
			case 1:
				state->deck[player][position] = silver;
        printf("Silver [%d] ", position);
				break;
			case 2:
				state->deck[player][position] = gold;
        printf("Gold [%d] ", position);
				break;
		 }
	}
  printf("\n"); 
  count = 0; 
  for (i = 0; i < state->deckCount[player]; i++) {
		type = state->deck[player][i];
		if (type == copper || type == silver || type == gold) {
			count++;
			if (count == 2) {
				return i + 1;
			}
		}
	}	
	return state->deckCount[player];
}

int checkResults(
	struct gameState *preState, 
	struct gameState *postState,
	int treasureCount,
  int cardsDrawn,
  int player
	) 
{

  int players = preState->numPlayers;
  int i;
  int addedTreasure;
  int newDeckCount;
  int newHandCount;
  int newDiscardCount;
  int status = 1;
  
  addedTreasure = (treasureCount >= 2) ? 2 : treasureCount;
		
  
  for (i = 0; i < players; i++) {
	  if (i != player) {
			if (preState->handCount[i] != postState->handCount[i]) {
			  status = -1;	
				printf("FAIL: Player #%d Hand Count has changed\n", i);
			}
			if (preState->deckCount[i] != postState->deckCount[i]) {
			  status = -1;	
				printf("FAIL: Player #%d Deck Count has changed\n", i);
			}
			if (preState->discardCount[i] != postState->discardCount[i]) {
			  status = -1;	
				printf("FAIL: Player #%d Discard Count has changed\n", i);
			}
		}
  }
  for (i = 0; i < treasure_map + 1; i++) {
		if (preState->supplyCount[i] != postState->supplyCount[i]) {
			status = -1;	
			printf("FAIL: Supply Count for card %d has changed\n", i);
		}
		if (preState->embargoTokens[i] != postState->embargoTokens[i]) {
			status = -1;	
			printf("FAIL: Embargo Tokens for %d has changed\n", i);
		}
	}

  newDeckCount = preState->deckCount[player] - cardsDrawn;
  newHandCount = preState->handCount[player] + addedTreasure;
  newDiscardCount = preState->discardCount[player] + cardsDrawn - addedTreasure; 
  
	if (newDeckCount != postState->deckCount[player]) {
		status = -1;	
		printf("  Deck INCORRECT\n");
	}
	if (newHandCount != postState->handCount[player]) {
		status = -1;	
		printf("  Hand INCORRECT\n");
	}
	if (newDiscardCount != postState->discardCount[player]) {
		status = -1;	
		printf("  Discard INCORRECT\n");
	}
  
  if (status == -1) {
		printf("\tBefore\tAfter\tCorrect\n");
		printf("Deck\t%d\t%d\t%d\n", preState->deckCount[player], postState->deckCount[player], newDeckCount);
		printf("Hand\t%d\t%d\t%d\n", preState->handCount[player], postState->handCount[player], newHandCount);
		printf("Discard\t%d\t%d\t%d\n", preState->discardCount[player], postState->discardCount[player], newDiscardCount);
	}

  return status;

}	





