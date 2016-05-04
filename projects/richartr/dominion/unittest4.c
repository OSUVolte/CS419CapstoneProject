/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - unittest4.c
* Description: Unit test for: gainCard()
* Requirements:
* 1. Check if supply pile is empty
* 2. If not empty, add the card to either the player's hand, deck, or discard pile (toFLag)
* 3. Decrease the supplyCount
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
     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };
     struct gameState Gstate;
     int result;
     int prevCardCount;

     int testRun = 1; //tests to run, in this case 1
     int testsPassed = 0;
     int testsFailed = 0;

     printf("*************************************\n");
     printf("*        Testing gainCard()         *\n");


     int i;
     for (i = 0; i < testRun; i++)
     {
          for (player = 0; player < numPlayer; player++)
          {
               int j;
               for (j = 0; j <= 26; j++) //iterate through every possible card in the game
               {
                    memset(&Gstate, 23, sizeof(struct gameState));   // clear the game state
                    r = initializeGame(numPlayer, k, seed, &Gstate); // initialize a new game

                    /*===============================================================
                             Testing empty supply pile for spcecified card
                    ===============================================================*/
#if (NOISY_TEST == 1)
                    printf("\r\n");
                    printf("Testing empty supply pile for spcecified card: %s \r\n", cards[j]);
#endif

                    Gstate.supplyCount[j] = 0;

                    result = gainCard(j,&Gstate, 0, player);

                    if (result == -1)//supply pile is empty (0) or card is not used in game
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("gainCard() = %d, Expected = -1\r\n", result);
#endif

                    /*===============================================================
                                 Testing cards set to -1 (Not used in game)
                    ===============================================================*/
#if (NOISY_TEST == 1)
                    printf("Testing card set to -1 (Not used in game) for spcecified card: %s \r\n", cards[j]);
#endif

                    Gstate.supplyCount[j] = -1;

                    result = gainCard(j, &Gstate, 0, player);

                    if (result == -1)//supply pile is empty (0) or card is not used in game
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("gainCard() = %d, Expected = -1\r\n", result);
#endif

                    /*==========================================================================
                    Testing toFlag to deck, discard, and hand and that spupply is decreased
                    ===========================================================================*/
                    //added card for [whoseTurn] current player:
                    // toFlag = 0 : add to discard
                    // toFlag = 1 : add to deck
                    // toFlag = 2 : add to hand


                     //discard pile
                    //======================================================
#if (NOISY_TEST == 1)
                    printf("Testing toFlag set for discard pile for spcecified card: %s \r\n", cards[j]);
#endif

                    Gstate.supplyCount[j] = 5;

                    prevCardCount = Gstate.discardCount[player]; //Save current discardCount to be compared later

                    result = gainCard(j, &Gstate, 0, player);

                    if (result == 0)//supply pile is not empty (0) or card is used in game
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("gainCard() = %d, Expected = 0\r\n", result);
                    printf("Testing if supply count was decreased for spcecified card: %s \r\n", cards[j]);
#endif

                    result = Gstate.supplyCount[j];

                    if (result == 4)
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.supplyCount[%s] = %d, Expected = 4\r\n", cards[j], result);
                    printf("Testing discardCount was increased for player %d\r\n", player);
#endif

                    result = Gstate.discardCount[player];

                    if (result == prevCardCount + 1)//passed
                    {
                       testsPassed++;
                    }
                    else//failed
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.discardCount[%d] = %d, Expected = %d\r\n", player, result, prevCardCount + 1);
                    printf("Testing card added to player %d's discard pile..\r\n", player, cards[j]);
#endif

                    result = Gstate.discard[player][Gstate.discardCount[player]-1];

                    if (result == j)
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.discard[%d][%d] = %d, Expected = %d\r\n", player, prevCardCount, result, j);
                    printf("Testing toFlag set for deck for spcecified card: %s \r\n", cards[j]);
#endif

                    prevCardCount = Gstate.deckCount[player]; //Save current deckCount to compate

                    result = gainCard(j, &Gstate, 1, player);

                    if (result == 0)  //supply card used
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("gainCard() = %d, Expected = 0\r\n", result);
                    printf("Testing if supply count was decreased...\r\n", cards[j]);
#endif

                    result = Gstate.supplyCount[j];

                    if (result == 3)
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.supplyCount[%s] = %d, Expected = 3\r\n", cards[j], result);
                    printf("Testing deckCount was increased for player...\r\n", player);
#endif

                    result = Gstate.deckCount[player];

                    if (result == prevCardCount + 1)//passed
                    {
                         testsPassed++;
                    }
                    else//failed
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.deckCount[%d] = %d, Expected = %d\r\n", player, result, prevCardCount + 1);
                    printf("Testing card added to player deck...\r\n", player, cards[j]);
#endif

                    result = Gstate.deck[player][Gstate.deckCount[player]-1];

                    if (result == j)
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.deck[%d][%d] = %d, Expected = %d\r\n", player, prevCardCount, result, j);
                    printf("Testing toFlag set for hand for spcecified card: %s \r\n", cards[j]);
#endif
                    //hand


                    prevCardCount = Gstate.handCount[player]; //save to compare

                         result = gainCard(j, &Gstate, 2, player);

                    if (result == 0)
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("gainCard() = %d, Expected = 0\r\n", result);
                    printf("Testing supply count was decreased...\r\n", cards[j]);
#endif

                    result = Gstate.supplyCount[j];

                    if (result == 2)//passed
                    {
                         testsPassed++;
                    }
                    else//failed
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.supplyCount[%s] = %d, Expected = 2\r\n", cards[j], result);
                    printf("Testing handCount was increased for player\r\n", player);
#endif

                    result = Gstate.handCount[player];

                    if (result == prevCardCount + 1) //handcount increased by 1
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.handCount[%d] = %d, Expected = %d\r\n", player, result, prevCardCount + 1);
                    printf("Testing card added...\r\n", player, cards[j]);
#endif

                    result = Gstate.hand[player][Gstate.handCount[player]-1];

                    if (result == j)
                    {
                         testsPassed++;
                    }
                    else
                    {
                         testsFailed++;
                    }

#if (NOISY_TEST == 1)
                    printf("Gstate.hand[%d][%d] = %d, Expected = %d\r\n", player, prevCardCount, result, j);
#endif
               }
          }
     }

     printf("*          Tests Passed: %d         *\n", testsPassed);
     printf("*          Tests Failed: %d         *\n", testsFailed);
     printf("*          Total Tests: %d          *\n", testsPassed + testsFailed);
     printf("*************************************\n");
     return 0;
}
