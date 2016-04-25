/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - unittest1.c
* Description: Unit test for: updateCoins()
*  1. Reset game state coin count.
*  2. Iterate through the player's hand and add coins accordingly
*  3. Add a bonus if passed in
*
* References: Assignment 3 Assistance given in this module.  The basic outline for all testing
*             follows this format.  This particular one builds on the updateCoins() example given.
***************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

//if NOISY_TEST = 0, no printing to output, if NOISY_TEST = 1, then print outputs
#define NOISY_TEST 0

int main(){
    int i;
    int r;
    int player;
    int playerCount = 2;
    int handCount;
    int maxHandCount = 5;
    int bonus;
    int maxBonus = 10;
    int testsPassed = 0;
    int testsFailed = 0;
    int seed = 1000;
    struct gameState G;
    int k[10] = { adventurer, council_room, feast, gardens, mine,
    remodel, smithy, village, baron, great_hall };
     // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
      coppers[i] = copper;
      silvers[i] = silver;
      golds[i] = gold;
    }

    printf("***********************************\n");
    printf("*      Testing updateCoins()      *\n");

    for (player = 0; player < playerCount; player++)
    {
      for (handCount = 0; handCount <= maxHandCount; handCount++) //start with checking empty hands
      {
        for (bonus = 0; bonus <= maxBonus; bonus++)
        {

          memset(&G, 23, sizeof(struct gameState));   // clear the game state
          r = initializeGame(playerCount, k, seed, &G); // initialize a new game
          G.handCount[player] = handCount;        // set the number of cards on hand


/* Test copper treasure cards */
#if (NOISY_TEST == 1)
          printf("Testing player %d with %d copper card(s) and %d bonus.\n", player, handCount, bonus);
#endif

          memcpy(G.hand[player], coppers, sizeof(int) * handCount); // set all the cards to copper
          updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
          printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
#endif
          if(G.coins == handCount * 1 + bonus) {
            testsPassed++;
          }
          else {
            testsFailed++;
          }

/* Test silver treasure cards */
#if (NOISY_TEST == 1)
          printf("Testing player %d with %d silver card(s) and %d bonus.\n", player, handCount, bonus);
#endif
          memcpy(G.hand[player], silvers, sizeof(int) * handCount); // set all the cards to silver
          updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
          printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
#endif
          if(G.coins == handCount * 2 + bonus) {
            testsPassed++;
          }
          else {
            testsFailed++;
          }
/* Test gold treasure cards */
#if (NOISY_TEST == 1)
          printf("Testing player %d with %d gold card(s) and %d bonus.\n", player, handCount, bonus);
#endif
          memcpy(G.hand[player], golds, sizeof(int) * handCount); // set all the cards to gold
          updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
          printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
#endif
          if(G.coins == handCount * 3 + bonus) {
            testsPassed++;
          }
          else {
            testsFailed++;
          }
/* Test mixed hand - 1 of each treasure */

          if (handCount == 3)
          {
            int treasureMix[3];

/* 1 card of each: copper, silver, and gold */
#if (NOISY_TEST == 1)
            printf("Testing player %d with 1 copper, 1 silver, and 1 gold card(s) and %d bonus.\n", player, bonus);
#endif
            treasureMix[0] = copper;
            treasureMix[1] = silver;
            treasureMix[2] = gold;

            memcpy(G.hand[player], treasureMix, sizeof(int) * handCount); //set to 1 of each trasure card
            updateCoins(player, &G, bonus);
#if (NOISY_TEST == 1)
            printf("G.coins = %d, expected = %d\n", G.coins, 6 + bonus);
#endif
            if(G.coins == 6 + bonus) {
              testsPassed++;
            }
            else {
              testsFailed++;
            }
          }
        }
      }
    }
    printf("*         Tests Passed: %d        *\n", testsPassed);
    printf("*         Tests Failed: %d        *\n", testsFailed);
    printf("*         Total Tests: %d         *\n", testsPassed + testsFailed);
    printf("***********************************\n");
    return 0;
}
