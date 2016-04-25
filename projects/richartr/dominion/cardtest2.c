/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - cardtest2.c
* Description: Unit test for: playAdventurer()
*  1. Draw cards from discard and deck until two treasures drawn
*  2. Cards drawn must be put into discard pile if not treasure
*
* References: cardTest4.c provided used as template
* Notes: playAdventurer is refactored code, so not all tests will pass.
**********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 0

int cardSearch(int player, struct gameState *state, int card, int flag);  //helper function for searching

int main()
{
     int r;
     int player;
     int numPlayer = 2;

     int seed = 1000;
     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };


     struct gameState newG; //untouched game state to compare with after running tests
     struct gameState testG; //game state that will be used for tests

     int result;
     int numTests = 1; //how many test iterations to run.
     int testsFailed = 0;
     int testsPassed = 0;

     printf("******************************\n");
     printf("*  Testing playAdventurer()  *\n");


     int i;
     for (i = 0; i < numTests; i++)
     {
          memset(&newG, 23, sizeof(struct gameState));   // clear the game state
          r = initializeGame(numPlayer, k, seed, &newG); // initialize a new game

          for (player = 0; player < numPlayer; player++)
          {
               newG.handCount[player] = 1;        //set number of cards in player's hand
               int adventurerHand[1];
               adventurerHand[0] = adventurer;
               memcpy(newG.hand[player], adventurerHand, sizeof(int));

               newG.deckCount[player] = 5;        // set number of cards in deck
               int deckCards[5];
               deckCards[0] = copper;
               deckCards[1] = feast;
               deckCards[2] = gardens;
               deckCards[3] = gold;
               deckCards[4] = silver;
               memcpy(newG.deck[player], deckCards, sizeof(int) * 5);

               memcpy(&testG, &newG, sizeof(struct gameState)); //create test game
               playAdventurer(player, &testG);

               //check that players hand increased by 2
#if (NOISY_TEST == 1)
               printf("\r\n");
               printf("Testing that player[%d] handCount has increased by 2...\r\n", player);
#endif

               result = testG.handCount[player];

               if (result == newG.handCount[player] + 2)
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }
#if (NOISY_TEST == 1)
               printf("handCount = %d, Expected = %d\r\n", result, newG.handCount[player] + 2);
               printf("Testing that player[%d] hand contains two treasure cards..\r\n", player);
#endif
               //Check that the hand has the two treasure cards

               int treasureCount = 0;
               int j;
               int card;
               for (j = 0; j < 2; j++)
               {

                    if (j == 0) {
                      card = copper;
                    };
                    if (j == 1) {
                      card = gold;
                    };

                    result = cardSearch(player, &testG, card, 1);

                    if (result == -1) // card is not found, test fails
                    {
                         testsFailed++;
                    }
                    else
                    {
                         treasureCount++;
                         testsPassed++;
                    }
               }

               if (treasureCount == 2)  //if two treasureCount are found, test passes
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }

#if (NOISY_TEST == 1)
               printf("Number of treasure cards = %d, Expected = %d\r\n", treasureCount, 2);
               printf("Testing that player[%d]'s deckCount has decreased..\r\n", player);
#endif
               result = testG.deckCount[player];

               if (result < newG.deckCount[player])  //if result is less than new game instance, then pass
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }

#if (NOISY_TEST == 1)
               printf("Post deckCount = %d, Previous deckCount = %d\r\n", result, newG.deckCount[player]);
#endif

#if (NOISY_TEST == 1)
               printf("Testing that player[%d]'s discard pile has increased..\r\n", player);
#endif

               result = testG.discardCount[player];

               if (result > newG.discardCount[player]) //if discardCount increases compared to normal state, then pass
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }

#if (NOISY_TEST == 1)
               printf("Post discardCount = %d, Previous discardCount = %d\r\n", result, newG.discardCount[player]);
               printf("\r\n");
#endif
          }

     }

     printf("*      Tests Passed: %d      *\n", testsPassed);
     printf("*      Tests Failed: %d      *\n", testsFailed);
     printf("*      Total Tests: %d       *\n", testsPassed + testsFailed);
     printf("******************************\n");

     return 0;
}

int cardSearch(int player, struct gameState *state, int card, int flag)
{
     int found = -1;
     int count = 0;
     int i;

     if (flag == 0) {
       count = state->playedCardCount;
     };
     if (flag == 1) {
       count = state->handCount[player];
     };
     if (flag == 2){
       count = state->deckCount[player];
     };

     for (i = 0; i < count; i++)
     {

          if (flag == 0)
          {
               if (state->playedCards[i] == card)
               {
                    found = i;
               }
          }
          else if (flag == 1)
          {
               if (state->hand[player][i] == card)
               {
                    found = i;
               }
          }
          else if (flag == 2)
          {
               if (state->deck[player][i] == card)
               {
                    found = i;
               }
          }
     }

     return found;

}
