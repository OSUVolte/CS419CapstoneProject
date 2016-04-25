/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - cardtest3.c
* Description: Unit test for: playVillage()
*  1. Adds 1 card from the deck or discard pile to player hand
*  2. Increases the player action by 2
*  3. Moves played village card to the player's discard pile.
*
* Notes: playVillage is refactored code, so not all tests will pass.
**********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 0

int cardSearch(int player, struct gameState *state, int card, int flag);  //helper function

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

     printf("***************************\n");
     printf("*  Testing playVillage()  *\n");


     int i;
     for (i = 0; i < numTests; i++)
     {
          memset(&newG, 23, sizeof(struct gameState));   // clear the game state
          r = initializeGame(numPlayer, k, seed, &newG); // initialize a new game

          for (player = 0; player < numPlayer; player++)
          {
               newG.handCount[player] = 1;        // set the number of cards on hand
               int villageHand[1];
               villageHand[0] = village;
               memcpy(newG.hand[player], villageHand, sizeof(int));

               newG.deckCount[player] = 5;        // set the number of cards in deck
               int deckCards[5];
               deckCards[0] = copper;
               deckCards[1] = silver;
               deckCards[2] = gold;
               deckCards[3] = gardens;
               deckCards[4] = tribute;
               memcpy(newG.deck[player], deckCards, sizeof(int) * 5);

               memcpy(&testG, &newG, sizeof(struct gameState)); //create clone of game state to run tests on
               playVillage(player, &testG, 0);

               //Check that 1 card added to player hand
#if (NOISY_TEST == 1)
               printf("Testing player[%d] handCount...\n", player);
#endif

               result = testG.handCount[player];

               if (result == newG.handCount[player]) //hancount should not change because discard
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }
#if (NOISY_TEST == 1)
               printf("handCount = %d, Expected = %d\r\n", result, newG.handCount[player]);
               printf("Testing player[%d] playedCardCount...\r\n", player);
#endif
               //Check that playedCardCount is +1

               result = testG.playedCardCount;

               if (result == newG.playedCardCount + 1) //if increased by 1, test passed
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }
#if (NOISY_TEST == 1)
               printf("playedCardCount = %d, Expected = %d\n", result, newG.playedCardCount + 1);
               printf("Checking village card was played...\r\n");
#endif
               //Check to see that the village card has been added to discard pile

               result = cardSearch(player, &testG, village, 0);

               if (result == -1)
               {
                    testsFailed++;
               }
               else
               {
                    testsPassed++;
               }

#if (NOISY_TEST == 1)
               if (result == -1)
               {
                    printf("** Failed! Village card not found\r\n");
               }
               else
               {
                    printf("** Passed! Village card was found, postiion %d!\r\n", result);
               }
               printf("Testing village card not in player[%d]'s hand...\r\n", player);
#endif
               //Check that village card is not in player's hand

               result = cardSearch(player, &testG, village, 1);

               if (result == -1) //if card not found in player's hand, pass
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }

#if (NOISY_TEST == 1)
               if (result == -1)
               {
                    printf("** Passsed!r\n");
               }
               else
               {
                    printf("** Failed! Village card found in player's hand at position %d!\r\n", result);
               }
#endif

#if (NOISY_TEST == 1)
               printf("Testing that player[%d] deckCount decreased..\r\n", player);
#endif
               //Check that deckCount decreased by 1

               result = testG.deckCount[player];

               if (result == newG.deckCount[player] - 1) //passed if 1 less, compare to new game instance
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }
#if (NOISY_TEST == 1)
               printf("deckCount = %d, Expected = %d\r\n", result, newG.deckCount[player] - 1);
               printf("Checking number of actions have increased...\r\n");  //should fail
#endif


               //Check that number of actions have increased by 2

               result = testG.numActions;

               if (result == newG.numActions + 2) //passed +2
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }
#if (NOISY_TEST == 1)
               printf("numActions = %d, Expected = %d\r\n", result, newG.numActions + 2);
               printf("\n");
#endif

          }
     }

     printf("*     Tests Passed: %d    *\n", testsPassed);
     printf("*     Tests Failed: %d    *\n", testsFailed);
     printf("*     Total Tests: %d     *\n", testsPassed + testsFailed);
     printf("***************************\n");

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
