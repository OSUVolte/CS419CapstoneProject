

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
int checkResults1(struct gameState*, struct gameState*, int);
int checkResults2(struct gameState*, struct gameState*, int);

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
  int j;
  int numPlayers;
  int player = 0; // always test first player
  int amountTreasure;
  int cardsDrawn;
  int results;
  int choice;
  int choice1;
  int choice2;
  int handPos;



  for (t = 0; t < 10000; t++) {
  	printf("******************* TEST #%d *******************\n", t);
    
  	numPlayers = rand() % (MAX_PLAYERS - 1) + MIN_PLAYERS; 
		memset(&preState, 23, sizeof(struct gameState));
		initializeGame(numPlayers, kingdomCards, randomSeed, &preState);

		preState.numActions = rand() % 10;
		choice = rand() % 2;
		if (choice == 0) {
			choice1 = TRUE;
			choice2 = FALSE;
      printf("CHOICE 1 - MINION CARD PLAYED BY PLAYER %d\n", player);
		}
		else {
			choice1 = FALSE;
			choice2 = TRUE;
      printf("CHOICE 2 - MINION CARD PLAYED BY PLAYER %d\n", player);
		}

    handPos = rand() % preState.handCount[player];

    for (i = 0; i < numPlayers; i++) {
			preState.handCount[i] = rand() % MAX_HAND;
			for (j = 0; j < preState.handCount[i]; j++) {
				preState.hand[i][j] = rand() % (treasure_map + 1);
			}
		}

    memcpy(&postState, &preState, sizeof(struct gameState)); 

    minionEffect(player, &postState, choice1, choice2, handPos);
    
		if (choice == 0) {
    	results = checkResults1(&preState, &postState, player);
		}
		else {
    	results = checkResults2(&preState, &postState, player);
		}
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

int checkResults2(
	struct gameState *preState, 
	struct gameState *postState,
  int player
	) 
{

  int players = preState->numPlayers;
  int i;
  int newDeckCount;
  int newHandCount;
  int newDiscardCount;
  int status = 1;
  
  if (postState->numActions != preState->numActions + 1) {
		printf("FAIL: NUM ACTIONS NOT INCREMENTED\n");
		status = -1;
	}
 
  if (postState->coins != preState->coins + 2) {
		printf("FAIL: TWO COINS WERE NOT ADDED\n");
	}

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

  return status;

}	


int checkResults1(
	struct gameState *preState, 
	struct gameState *postState,
  int player
	) 
{

  int players = preState->numPlayers;
  int i;
  int newDeckCount;
  int newHandCount;
  int newDiscardCount;
  int status = 1;
  
  if (postState->numActions != preState->numActions + 1) {
		printf("FAIL: NUM ACTIONS NOT INCREMENTED\n");
		status = -1;
	}
 
  for (i = 0; i < players; i++) {
		newDeckCount = preState->deckCount[i] - 4;
		newHandCount = 4;
		newDiscardCount = preState->discardCount[i] + preState->handCount[i];

	  if ((i != player && preState->handCount[i] >= 5) || i == player) {
			if (postState->handCount[i] != newHandCount) {
				printf("FAIL: Player #%d Hand Count\n", i, postState->handCount[i]);
			  status = -1;	
			}
			if (postState->deckCount[i] != newDeckCount) {
				printf("FAIL: Player #%d Deck Count\n", i);
			  status = -1;	
			}
			if (postState->discardCount[i] != newDiscardCount) {
				printf("FAIL: Player #%d Discard Count\n", i);
			  status = -1;	
			}
		}
 		printf("Player %d:\n", i);
		printf("\tBefore\tAfter\tCorrect\n");
		printf("Deck\t%d\t%d\t%d\n", preState->deckCount[i], postState->deckCount[i], newDeckCount);
		printf("Hand\t%d\t%d\t%d\n", preState->handCount[i], postState->handCount[i], newHandCount);
		printf("Discard\t%d\t%d\t%d\n\n", preState->discardCount[i], postState->discardCount[i], newDiscardCount);
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

  return status;

}	





