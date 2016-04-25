/******************************************************************************
 * Program:	unittest2.c	
 *
 * Author:	Jarrad Favre
 *
 * Date:	4-23-2016
 *
 * Description:	Part of assignment 3 for CS 362. Unit test for updateCoins() 
 * function from Dominion card game.
 ******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTFUNC "updateCoins()"

int main()
{
    //Declare variables
    struct gameState gOrig, gTest;	//Two gameState structures to make
					//one as original and one as test

    //Hardcore 10 kingdom cards into an array
    int kCards[10] = {adventurer, gardens, village, minion, council_room, 
                      embargo, sea_hag, tribute, smithy, steward};
    int seed         = 1000,
        numOfPlyers  = 2,
        plyer1	     = 0,
        plyer2	     = 1;

    //Initialize with number of players and kingdom cards being used
    initializeGame(numOfPlyers, kCards, seed, &gOrig);

    //Copy game state to test state
    memcpy(&gTest, &gOrig, sizeof(struct gameState));

    //Print header for card being tested
    printf("\n-------------------- Testing Function %s --------------------\n", TESTFUNC);
         
    // ----- Print header for test case 1 -----
    printf("\nTEST CASE 1: Test that has treasure cards in player's hand and function returns correct amount with 0 bonuses\n");

    //Assemble a card hand for player 1 with some treasure cards
    gTest.hand[plyer1][0] = adventurer;
    gTest.hand[plyer1][1] = gold;	//3 coins
    gTest.hand[plyer1][2] = minion;
    gTest.hand[plyer1][3] = copper;	//2 coins
    gTest.hand[plyer1][4] = silver;	//1 coin....total of 6 coins
   
    //Assign current hand card count to 5
    gTest.handCount[plyer1] = 5;

    //Call function with treasure in player 1's hand and zero for bonus
    updateCoins(plyer1, &gTest, 0);

    //Condition when coins equals amount of treasure in player 1's hand with no bonuses
    if (gTest.coins == 6)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print the expect amount of coins and actual amount 
        printf("Player 1's expect amount of treasure: %d\nActual amount of treasure: %d\n", 6, gTest.coins);
    }

    //Condition when coins is less or greater than treasure in player 1's hand
    else 
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print the expect amount of coins and actual amount 
        printf("Player 1's expect amount of treasure: %d\nActual amount of treasure: %d\n", 6, gTest.coins);
    }

    // ----- Print header for test case 2 -----
    printf("\nTEST CASE 2: Test that has treasure cards in player's hand and function returns correct amount with bonus\n");

    //Use the same amount of cards but with different amount of treasure cards
    gTest.hand[plyer1][0] = silver;	//2 coins
    gTest.hand[plyer1][1] = silver;	//2 coins
    gTest.hand[plyer1][2] = smithy;
    gTest.hand[plyer1][3] = copper;     //1 coin
    gTest.hand[plyer1][4] = gold;     	//3 coins....total of 8 + 2 for bonus = 10 coins

    //Call function with treasure in player 1's hand and 2 for bonus
    updateCoins(plyer1, &gTest, 2);

    //Condition when coins equals amount of treasure in player 1's hand with bonuses
    if (gTest.coins == 10)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print the expect amount of coins and actual amount 
        printf("Player 1's expect amount of treasure: %d\nActual amount of treasure: %d\n", 10, gTest.coins);
    }

    //Condition when coins is less or greater than treasure in player 1's hand with bonus
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print the expect amount of coins and actual amount 
        printf("Player 1's expect amount of treasure: %d\nActual amount of treasure: %d\n", 10, gTest.coins);
    }

    // ----- Print header for test case 3 -----
    printf("\nTEST CASE 3: Hand count shows 0 when player only has 1 card on hand to discard\n");

    //Use the same amount of cards but with no treausre cards
    gTest.hand[plyer1][0] = embargo; 
    gTest.hand[plyer1][1] = gardens;  
    gTest.hand[plyer1][2] = sea_hag;
    gTest.hand[plyer1][3] = village;   
    gTest.hand[plyer1][4] = tribute;       //0 coins

    //Call function with no treasure in player's hand and 0 bonuses
    updateCoins(plyer1, &gTest, 0);

    //Condition when coins equals amount of treasure in player 1's hand without bonuses 
    if (gTest.coins == 0)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print the expect amount of coins and actual amount 
        printf("Player 1's expect amount of treasure: %d\nActual amount of treasure: %d\n", 0, gTest.coins);
    }

    //Condition when coins is greater than 0
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print the expect amount of coins and actual amount 
        printf("Player 1's expect amount of treasure: %d\nActual amount of treasure: %d\n", 0, gTest.coins);
    }

    return 0;
}
