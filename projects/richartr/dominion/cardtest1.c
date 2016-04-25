/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - cardtest1.c
* Description: CardTest for playSmithy()
*  1. Adds 3 cards from the current player's own deck or discarded pile to the current player's hand.
*  2. Adds the smithy card that was just played to the player's discard deck.
*
* References: cardTest4.c provided to use as example and template
* Notes: playSmithy is refactored code, so not all tests will pass.
**********************************************/
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
     int playerCount = 2;

     int seed = 1000;
     int k[10] = { adventurer, council_room, feast, gardens, mine,
       remodel, smithy, village, baron, great_hall };

     struct gameState newG; //new gamestate used for comparision
     struct gameState testG; //testing game state

     int result;

     int numTests = 1; //how many test iterations to run.
     int testsFailed = 0;
     int testsPassed = 0;

     printf("***********************************\n");
     printf("*       Testing playSmithy()      *\n");

     int i;
     for (i = 0; i < numTests; i++)
     {

          memset(&newG, 23, sizeof(struct gameState));   // clear the game state
          r = initializeGame(playerCount, k, seed, &newG); // initialize a new game

          for (player = 0; player < playerCount; player++)
          {

               newG.handCount[player] = 1;        // set the number of cards in player's hand
               int smithyHand[1];
               smithyHand[0] = smithy;
               memcpy(newG.hand[player], smithyHand, sizeof(int));

               newG.deckCount[player] = 5;        // set the number of cards in the draw deck
               int deckCards[5];
               deckCards[0] = copper;
               deckCards[1] = silver;
               deckCards[2] = gold;
               deckCards[3] = gardens;
               deckCards[4] = tribute;
               memcpy(newG.deck[player], deckCards, sizeof(int) * 5);

               memcpy(&testG, &newG, sizeof(struct gameState)); //create test game
               playSmithy(player, &testG, 0);

               //check that 2 cards were added to player's hand.  smithy will be discarded, then 3 added, netting 2 cards
#if (NOISY_TEST == 1)
               printf("Testing that player[%d] handCount has increased by 2....\r\n", player);
#endif

               result = testG.handCount[player];

               if (result == newG.handCount[player] + 2) //play smithy, then draw 3 cards, so count only increase 2
               {
                    testsPassed++;
               }
               else  //if two cards not added, then fail test
               {
                    testsFailed++;
               }
#if (NOISY_TEST == 1)
               printf("handCount = %d, Expected = %d\r\n", result, newG.handCount[player] + 2);
               printf("Testing that player[%d] playedCardCount has increased by 1....\r\n", player);
#endif
               //Check that playedCardCount increased by 1

               result = testG.playedCardCount;

               if (result == newG.playedCardCount + 1) //if played card has 1 additional card, pass (discarded card)
               {
                    testsPassed++;
               }
               else
               {
                    testsFailed++;
               }
#if (NOISY_TEST == 1)
               printf("playedCardCount = %d, Expected = %d\r\n", result, newG.playedCardCount + 1);
#endif
               //Check that the smithy card was added to the played cards pile

          }
     }

     printf("*         Tests Passed: %d        *\n", testsPassed);
     printf("*         Tests Failed: %d        *\n", testsFailed);
     printf("*         Total Tests: %d         *\n", testsPassed + testsFailed);
     printf("***********************************\n");

     return 0;
}
