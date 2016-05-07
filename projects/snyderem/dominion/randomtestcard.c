/******************************************************************************
** Filename: randomtestcard.c
** Emily Snyder
** Spring 2016
** CS 362-400
** Random tests for Minion Card
** Information about how the Minion Card should behave is from 
** wiki.dominionstrategy.com/index.php/Minion
******************************************************************************/ 

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
#define NUM_TEST 10000

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

  int t;
  int i;
  int j;
  int numPlayers;
  int player = 0; // always test first player
  int results;
  int choice;
  int choice1;
  int choice2;
  int handPos;



  for (t = 0; t < NUM_TEST; t++) {
    printf("******************* TEST #%d *******************\n", t);
    
    numPlayers = rand() % (MAX_PLAYERS - 1) + MIN_PLAYERS; 
    memset(&preState, 23, sizeof(struct gameState));
    initializeGame(numPlayers, kingdomCards, randomSeed, &preState);

    preState.numActions = rand() % 10;

    // Randomly select the player choice for how to use the minion card
    // Choice 1 = new hand of 4 cards + all other players with 5+ cards will
    //            discard and a new hand of 4 cards
    // Choice 2 = gain two coins
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

    // Randomly select the position in the hand
    handPos = rand() % preState.handCount[player];

    // Fill each player's hand with a random number of random cards
    // This must be done in order for them to discard and redraw a new hand for
    // choice 1
    for (i = 0; i < numPlayers; i++) {
      preState.handCount[i] = rand() % MAX_HAND;
      for (j = 0; j < preState.handCount[i]; j++) {
        preState.hand[i][j] = rand() % (treasure_map + 1);
      }
    }

    // Copy the state for the game before playing the card for comparison
    memcpy(&postState, &preState, sizeof(struct gameState)); 

    minionEffect(player, &postState, choice1, choice2, handPos);
    
    // Check the status of the game after playing the card depening on which
    // choice was used
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
  int               player
  ) 
{

  int players = preState->numPlayers;
  int i;
  int newDeckCount;
  int newHandCount;
  int newDiscardCount;
  int status = 1;
  
  // Number of actions should be increased by 1
  if (postState->numActions != preState->numActions + 1) {
    printf("FAIL: NUM ACTIONS NOT INCREMENTED\n");
    status = -1;
  }
 
  // Two coins should be added
  if (postState->coins != preState->coins + 2) {
    printf("FAIL: TWO COINS WERE NOT ADDED\n");
  }

  // None of the card piles for any of the other players should be changed
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

  // The card supply counts and embargo tokens should not change
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

  // Player's deck should not change, 1 card (the minion card) should be discarded
  // from their hand
  newDeckCount = preState->deckCount[player];
  newHandCount = preState->handCount[player] - 1;
  newDiscardCount = preState->playedCardCount + 1;

  if (postState->handCount[player] != newHandCount) {
    printf("FAIL: Hand Count\n");
    status = -1;  
  }
  if (postState->deckCount[player] != newDeckCount) {
    printf("FAIL: Deck Count\n");
    status = -1;  
  }
  if (postState->playedCardCount != newDiscardCount) {
    printf("FAIL: Discard Count\n");
    status = -1;  
  }

  printf("\tBefore\tAfter\tCorrect\n");
  printf("Deck\t%d\t%d\t%d\n", preState->deckCount[player], postState->deckCount[player], newDeckCount);
  printf("Hand\t%d\t%d\t%d\n", preState->handCount[player], postState->handCount[player], newHandCount);
  printf("Played\t%d\t%d\t%d\n", preState->playedCardCount, postState->playedCardCount, newDiscardCount);
  printf("Discard\t%d\t%d\n\n", preState->discardCount[player], postState->discardCount[player]);

  return status;

}  


int checkResults1(
  struct gameState *preState, 
  struct gameState *postState,
  int               player
  ) 
{

  int players = preState->numPlayers;
  int i;
  int newDeckCount;
  int newHandCount;
  int newPlayedCardCount = preState->playedCardCount;
  int status = 1;
  
  // Number of actions should be increased by 1
  if (postState->numActions != preState->numActions + 1) {
    printf("FAIL: NUM ACTIONS NOT INCREMENTED\n");
    status = -1;
  }
 
  for (i = 0; i < players; i++) {

    if ((i != player && preState->handCount[i] >= 5) || i == player) {
      // If it is the current player or a different player with 5 or more cards
      // in their hand, the hand is discarded and 4 cards are drawn
      // Deck count will be 4 less and hand count will now be 4
      newDeckCount = preState->deckCount[i] - 4;
      newHandCount = 4;
      newPlayedCardCount += preState->handCount[i];
      if (postState->handCount[i] != newHandCount) {
        printf("FAIL: Player #%d Hand Count\n", i);
        status = -1;  
      }
      if (postState->deckCount[i] != newDeckCount) {
        printf("FAIL: Player #%d Deck Count\n", i);
        status = -1;  
      }
      if (postState->discardCount[i] != preState->discardCount[i]) {
        printf("FAIL: Player #%d Discard Count\n", i);
        status = -1;  
      }
    }
    else if (preState->handCount[i] < 5) {
      // Nothing should change for other players with less than 5 cards in their
      // hand
      newDeckCount = preState->deckCount[i];
      newHandCount = preState->handCount[i];
       if (postState->handCount[i] != preState->handCount[i]) {
        printf("FAIL: Player #%d Hand Count\n", i);
        status = -1;  
      }
      if (postState->deckCount[i] != preState->deckCount[i]) {
        printf("FAIL: Player #%d Deck Count\n", i);
        status = -1;  
      }
      if (postState->discardCount[i] != preState->discardCount[i]) {
        printf("FAIL: Player #%d Discard Count\n", i);
        status = -1;  
      }
    }
    printf("Player %d:\n", i);
    printf("\tBefore\tAfter\tCorrect\n");
    printf("Deck\t%d\t%d\t%d\n", preState->deckCount[i], postState->deckCount[i], newDeckCount);
    printf("Hand\t%d\t%d\t%d\n", preState->handCount[i], postState->handCount[i], newHandCount);
    printf("Discard\t%d\t%d\t%d\n\n", preState->discardCount[i], postState->discardCount[i], preState->discardCount[i]);
  }

  // Discard function places cards in the played card pile, and it should be 
  // equal to the number of cards discarded by all of the players with 5 or
  // or more cards in their hands
  if (postState->playedCardCount != newPlayedCardCount) {
    printf("FAIL: Played Card Count\n");
    status = -1;
  }
  printf("Played Card Count:\n");  
  printf("\tBefore\tAfter\tCorrect\n");
  printf("Played\t%d\t%d\t%d\n", preState->playedCardCount, postState->playedCardCount, newPlayedCardCount);

  // Supply counts and embargo tokens should not be changed
  for (i = 0; i <= MAX_CARD; i++) {
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





