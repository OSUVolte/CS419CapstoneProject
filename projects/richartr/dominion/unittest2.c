/************************************
* Name: Trent Richardson
* Class: CS362-400
* Assignment 3 - unittest2.c
* Description: Unit test for: isGameOver()
*  1. Game is over if supply of province cards is 0
*  2. Game is over if three supply piles are 0
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
     int j;
     int l;
     int m;
     int numPlayer = 2;
     int seed = 1000;
     int k[10] = { adventurer, council_room, feast, gardens, mine,
     remodel, smithy, village, baron, great_hall };
     struct gameState G;
     int result;
     int testRun = 1; //how many test iterations to run, in this case 1 time.
     int testsPassed = 0;
     int testsFailed = 0;

     printf("***********************************\n");
     printf("*      Testing isGameOver()       *\n");

     int i;
     for (i = 0; i < testRun;i++)
     {

          memset(&G, 23, sizeof(struct gameState));   // clear game state
          r = initializeGame(numPlayer, k, seed, &G); // initialize new game

/* Test a new game state */
#if (NOISY_TEST == 1)
          printf("Testing new gamestate...\r\n");
#endif
          result = isGameOver(&G);

          if (result == 1)
          {
               testsFailed++;
          }
          else //game is not over, test passes
          {
               testsPassed++;
          }

#if (NOISY_TEST == 1)
          printf("isGameover = %d, Expected = 0\r\n", result);
          printf("\r\n");
#endif

/* Test depleted province supply */
#if (NOISY_TEST == 1)
          printf("Testing depleted Province supply....\r\n");
#endif
          G.supplyCount[province] = 0;  //set province supply to 0

          result = isGameOver(&G);

          if (result == 1)//if game is over, test passes
          {
               testsPassed++;
          }
          else //game is not over, test fails
          {
               testsFailed++;
          }

#if (NOISY_TEST == 1)
          printf("isGameover = %d, Expected = 1\r\n", result);
          printf("\r\n");
#endif

/* Test 1 depleted supply pile */
          G.supplyCount[province] = 8; //set province supply back to 8


          for (j = 0; j <=26; j++) //iterate through cards
          {
               if (j != 3) //every card that is not province
               {
#if (NOISY_TEST == 1)
                    printf("Testing one depleted supply pile....\r\n");
#endif
                    G.supplyCount[j] = 0;

                    result = isGameOver(&G);

                    if (result == 1)//if game over, test fails
                    {
                         testsFailed++;
                    }
                    else //game is not over, test passes
                    {
                         testsPassed++;
                    }

#if (NOISY_TEST == 1)
                    printf("isGameover = %d, Expected = 0\r\n", result);
                    printf("\r\n");
#endif

                    G.supplyCount[j] = 8; //restore supply back to full
               }
          }


/* Test 2 depleted supply piles */
          for (j = 0; j < 26; j++) //iterate through possible combinations of cards
          {
               for (m = 0; m < 26; m++)
               {
                    if (j != 3 && m !=3 && j != m) //every card that is not province and the two supply piles are not the same
                    {
#if (NOISY_TEST == 1)
                         printf("Testing two depleted supply piles....\r\n");
#endif
                         G.supplyCount[j] = 0;  //set supply pile count to 0
                         G.supplyCount[m] = 0;

                         result = isGameOver(&G);

                         if (result == 1) //game over, test fails
                         {
                              testsFailed++;
                         }
                         else //game is not over, test passes
                         {
                              testsPassed++;
                         }

#if (NOISY_TEST == 1)
                         printf("isGameover = %d, Expected = 0\r\n", result);
                         printf("\r\n");
#endif

                         G.supplyCount[j] = 8; //restore supply
                         G.supplyCount[m] = 8; //restore supply
                    }
               }
          }

/* Test 3 depleted supply piles */
          for (j = 0; j < 25; j++) //iterate through possible combinations of cards
          {
               for (m = 0; m < 25; m++)
               {
                    for (l = 0; l < 25; l++)
                    {

                         if (j != 3 && m != 3 && l != 3 && j != m && j != l && m != l) //cards not province and not the same
                         {
#if (NOISY_TEST == 1)
                              printf("Testing three depleted supply piles...\r\n");
#endif
                              G.supplyCount[j] = 0;
                              G.supplyCount[m] = 0;
                              G.supplyCount[l] = 0;

                              result = isGameOver(&G);

                              if (result == 1)//if game is over, test passes
                              {
                                   testsPassed++;
                              }
                              else //if game not over, test fails
                              {
                                   testsFailed++;
                              }

#if (NOISY_TEST == 1)
                              printf("isGameover = %d, Expected = 1\r\n", result);
                              printf("\r\n");
#endif

                              G.supplyCount[j] = 8; //restore supply count for all piles
                              G.supplyCount[m] = 8;
                              G.supplyCount[l] = 8;
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
