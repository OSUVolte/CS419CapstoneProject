/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - unittest3.c
* Description: Unit test for: fullDeckCount()
* 1. Count how many cards is in the player's hand.
* 2. Count how many cards is in the player's deck.
* 3. Count how many cards is in the player's discard pile.
***************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 0

int main()
{
  int r;
  int player;
  int numPlayer = 2;
  int seed = 1000;
  int k[10] = { adventurer, council_room, feast, gardens, mine,
  remodel, smithy, village, baron, great_hall };

  struct gameState Gstate;

  int totalCount;
  int deckCount;
  int handCount;
  int discardCount;
  int maxCards = 10; //How many cards to test up to for deck, hand, and discard pile.
  int result;

  int testsPassed = 0;
  int testsFailed = 0;
  int tests = 0;

  printf("**************************************\n");
  printf("*      Testing fullDeckCount()       *\n");

  for (player = 0; player < numPlayer; player++)
  {
    int i;
    int j;
    for (i = 0; i <= 26; i++) //iterate through game cards (27 total)
    {
       for (discardCount = 0; discardCount <= maxCards; discardCount++)
       {
         for (handCount = 0; handCount <= maxCards; handCount++)
         {
           for (deckCount = 0; deckCount <= maxCards; deckCount++)
           {
             totalCount = discardCount + handCount + deckCount;

#if (NOISY_TEST == 1)
              printf("Testing");
#endif

              int testDeck[deckCount];
              for (j = 0; j < deckCount; j++)
              {
                   testDeck[j] = i;
              }
              int testHand[handCount];
              for (j = 0; j < handCount; j++)
              {
                   testHand[j] = i;
              }

              int testDiscard[discardCount];
              for (j = 0; j < discardCount; j++)
              {
                   testDiscard[j] = i;
              }

              memset(&Gstate, 23, sizeof(struct gameState));   // clear the game state
              r = initializeGame(numPlayer, k, seed, &Gstate); // initialize a new game

              Gstate.handCount[player] = handCount;        // set the number of cards in player hand
              Gstate.deckCount[player] = deckCount;        // set the number of cards in the deck
              Gstate.discardCount[player] = discardCount;  // set the number of cards in the discard

              memcpy(Gstate.hand[player], testHand, sizeof(int) * handCount);
              memcpy(Gstate.deck[player], testDeck, sizeof(int) * deckCount);
              memcpy(Gstate.discard[player], testDiscard, sizeof(int) * discardCount);

              result = fullDeckCount(player, i, &Gstate);
              tests++;

              if (totalCount == result)
              {
                   testsPassed++;
              }
              else
              {
                   testsFailed++;

              }
#if (NOISY_TEST == 1)
              printf("fullDeckCount = %d, Expected = %d\r\n", result, totalCount);
              printf("\r\n");
#endif
            }
          }
        }
      }
    }

    printf("*          Tests Passed: %d          *\n", testsPassed);
    printf("*          Tests Failed: %d          *\n", testsFailed);
    printf("*          Total Tests: %d           *\n", testsPassed + testsFailed);
    printf("**************************************\n");
  return 0;
}
