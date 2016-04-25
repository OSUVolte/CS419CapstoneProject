/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - cardtest3.c
* Description: Unit test for: playSalvager()
*  1. Increase the game state number of buys by 1.
*  2. Trash a card and gain coins that equal trashed card.
*  3. Discard the played salvager card.

* References: cardTest4.c provided as example and template
*
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
     int i;
     int j;
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

     printf("****************************\n");
     printf("*  Testing playSalvager()  *\n");

     for (i = 0; i < numTests; i++)
     {
          for (player = 0; player < numPlayer; player++)
          {
               for (j = 0; j <= 26; j++) //iterate through every possible card in the game
               {
                    int otherPlayer = 0;
                    if (player == 0)
                    {
                         otherPlayer = 1;
                    }
#if (NOISY_TEST == 1)
                    printf("Testing player %d with %s card to be trashed...\n", player, cards[j]);

#endif
                    memset(&newG, 23, sizeof(struct gameState));   // clear the game state
                    r = initializeGame(numPlayer, k, seed, &newG); // initialize a new game

                    newG.handCount[player] = 2;        // set the number of cards on hand
                    int salvagerHand[2];
                    salvagerHand[0] = salvager;
                    salvagerHand[1] = j;

                    memcpy(newG.hand[player], salvagerHand, sizeof(int) *2 );
                    memcpy(&testG, &newG, sizeof(struct gameState)); //create test game to test

                    result = playSalvager(player, &testG, 0, 1);

#if (NOISY_TEST == 1)
                    printf("Checking that number of buys have increased...\r\n");
#endif

                    //Check that buys have incresed by 1

                    result = testG.numBuys;

                    if (result == newG.numBuys + 1) //if incrased by one, pass
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }
#if (NOISY_TEST == 1)
                    printf("numBuys = %d, Expected = %d\r\n", result, newG.numBuys + 1);
                    printf("Testing the correct amount of coins added for %s card...\r\n", cards[j]);
#endif
                    //check correct amount of coins was added

                    int expCoins;

                    if (j == -1) //no card
                    {
                         expCoins = 0;
                    }
                    else
                    {
                         expCoins = getCost(j);
                    }

                    result = testG.coins;

                    if (result == newG.coins + expCoins) //if equal to new game instance plus expCoins
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("testG.coins = %d, Expected = %d\r\n", result, newG.coins + expCoins);
                    printf("Testing player[%d] playedCardCount has increased...\r\n", player);
#endif

                    //Check that playedCardCount increased by 1

                    result = testG.playedCardCount;

                    if (result == newG.playedCardCount + 1)  //increase by 1 compared to new game, pass
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }
#if (NOISY_TEST == 1)
                    printf("playedCardCount = %d, Expected = %d\r\n", result, newG.playedCardCount + 1);
                    printf("Testing played salvager in played pile...\r\n");
#endif
                    //Check that the salvager card was added to the played cards pile

                    result = cardSearch(player, &testG, salvager, 0);

                    if (result == -1) // if -1, test failed, card not found
                    {
                         testsFailed++;
                    }
                    else
                    {
                         testsPassed++;
                    }

#if (NOISY_TEST == 1)
                    if (result == -1) //failed
                    {
                         printf("Failed! Salvager card was not found in played cards pile!\r\n");
                    }
                    else//passed
                    {
                         printf("Passed!\r\n", result);
                    }
                    printf("Testing Salvager is not in player[%d]'s hand...\r\n", player);
#endif

                    //Check that the card is not in player's hand

                    result = cardSearch(player, &testG, j, 1);

                    if (result == -1) // if card not found, then pass
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
                         printf("** Passsed!\r\n");
                    }
                    else
                    {
                         printf("** Failed! The card was found in player's hand at position %d!\r\n", result);
                    }
#endif
               }
          }
     }

     printf("*     Tests Passed: %d     *\n", testsPassed);
     printf("*     Tests Failed: %d     *\n", testsFailed);
     printf("*     Total Tests: %d      *\n", testsPassed + testsFailed);
     printf("****************************\n");

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
