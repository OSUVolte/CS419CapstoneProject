/******************************************************************************
 * Program:	unittest3.c	
 *
 * Author:	Jarrad Favre
 *
 * Date:	4-23-2016
 *
 * Description:	Part of assignment 3 for CS 362. Unit test for isGameOver() 
 * function from Dominion card game.
 ******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTFUNC "isGameOver()"

int main()
{
    //Declare variables
    struct gameState gOrig, gTest;	//Two gameState structures to make
					//one as original and one as test

    //Hardcore 10 kingdom cards into an array
    int kCards[10] = {adventurer, gardens, village, minion, council_room, 
                      cutpurse, sea_hag, tribute, smithy, feast};
    int seed         = 1000,
        numOfPlyers  = 2,
        tempProv,
        tempSup1,
        tempSup2,
        tempSup3,
        gameOver;	//Boolean variable


    //Initialize with number of players and kingdom cards being used
    initializeGame(numOfPlyers, kCards, seed, &gOrig);

    //Copy game state to test state
    memcpy(&gTest, &gOrig, sizeof(struct gameState));

    //Print header for card being tested
    printf("\n-------------------- Testing Function %s --------------------\n", TESTFUNC);
         
    // ----- Print header for test case 1 -----
    printf("\nTEST CASE 1: Game does not end when stack of Province cards is not empty or when none of the supplies are empty\n");
 
    //Call isGameOver with zero supplies empty
    gameOver = isGameOver(&gTest);

    //Condition when gameOver is set false
    if (gameOver == 0)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 0, gameOver); 
    }
    
    //Condition when gameOver is set true
    else 
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 1, gameOver);
    }

    // ----- Print header for test case 2 -----
    printf("\nTEST CASE 2: Game does not end when 2 of supplies are empty\n");

    //Assign 2 of supply cards(gold and minion) to temp variables
    tempSup1 = gTest.supplyCount[gold];
    tempSup2 = gTest.supplyCount[minion];

    //Zero out the count of the above 2 cards
    gTest.supplyCount[gold] 	= 0;
    gTest.supplyCount[minion]	= 0;

    //Call isGameOver with 2 supplies empty
    gameOver = isGameOver(&gTest);

    //Condition when gameOver is set false
    if (gameOver == 0)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");
     
        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 0, gameOver);
    }

    //Condition when gameOver is set true
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 1, gameOver);
    }    

    // ----- Print header for test case 3 -----
    printf("\nTEST CASE 3: Game ends when 3 supplies are empty\n");

    //Assign a third supply card (smithy) to temp variable
    tempSup3 = gTest.supplyCount[smithy];

    //Zero out the supply count of the above card
    gTest.supplyCount[smithy] = 0;

    //Call isGameOver with 3 supplies empty
    gameOver = isGameOver(&gTest);

    //Condition when gameOver is set false
    if (gameOver == 0)
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 0, gameOver);
    }

    //Condition when gameOver is set true
    else
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 1, gameOver);
    }

    //True supply counts stored in temp variables to gold, minion and smithy
    gTest.supplyCount[gold]	= tempSup1;
    gTest.supplyCount[minion]   = tempSup2;
    gTest.supplyCount[smithy]	= tempSup3;

    // ----- Print header for test case 4 -----
    printf("\nTEST CASE 4: Game ends when province supply empties\n");

    //Assign supply count of province to temp variable
    tempProv = gTest.supplyCount[province];

    //Empty supply count of province
    gTest.supplyCount[province] = 0;

    //Call isGameOver with empty stack of province
    gameOver = isGameOver(&gTest);

    //Condition when gameOver is set false
    if (gameOver == 0)
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 0, gameOver);
    }

    //Condition when gameOver is set true
    else
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expect return value and actual return value from gameOver
        printf("Expected boolean value returned from isGameOver: %d\nActual boolean value: %d\n", 1, gameOver);
    }

    //Return value stored in tempProv back to province supply
    gTest.supplyCount[province] = tempProv;

    return 0;
}
