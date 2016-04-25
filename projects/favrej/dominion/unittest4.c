/******************************************************************************
 * Program:	unittest4.c	
 *
 * Author:	Jarrad Favre
 *
 * Date:	4-23-2016
 *
 * Description:	Part of assignment 3 for CS 362. Unit test for scoreFor function
 * from Dominion card game.
 ******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTFUNC "scoreFor()"

int main()
{
    //Declare variables
    struct gameState gOrig, gTest;	//Two gameState structures to make
					//one as original and one as test

    //Hardcore 10 kingdom cards into an array
    int kCards[10] = {adventurer, gardens, village, minion, council_room, 
                      cutpurse, sea_hag, tribute, smithy, steward};
    int seed        = 1000,
        numOfPlyers = 2,
        plyer1	    = 0,
        plyer2      = 1,
        cardScore,
        i;		//Needed for "for" loop

    //Initialize with number of players and kingdom cards being used
    initializeGame(numOfPlyers, kCards, seed, &gOrig);

    //Copy game state to test state
    memcpy(&gTest, &gOrig, sizeof(struct gameState));

    //Print header for card being tested
    printf("\n-------------------- Testing Function %s --------------------\n", TESTFUNC);
         
    // ----- Print header for test case 1 -----
    printf("\nTEST CASE 1: All cards from Player 1 are tallied instead of Player 2's\n");

    //Player 1's hand with 3 estate, for a score of 3
    gTest.hand[plyer1][0] = estate;
    gTest.hand[plyer1][1] = estate;
    gTest.hand[plyer1][2] = estate;

    //Assign current hand card count to 3
    gTest.handCount[plyer1] = 3;

    //Player 2's hand with 3 ducky, for a score of 9
    gTest.hand[plyer2][0] = duchy;
    gTest.hand[plyer2][1] = duchy;
    gTest.hand[plyer2][2] = duchy;

    //Assign 3 to hand count
    gTest.handCount[plyer2] = 3;

    //Call function to get player 1's score
    cardScore = scoreFor(plyer1, &gTest);

    //Condition when cardScore returns 3 to reflect the score in player 1's hand
    if (cardScore == 3)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\nReturned score matches player 1's hand score\n");

        //Print the actual score returned from scoreFor and the score in player 1's hand
        printf("Score returned from scoreFor(): %d\nPlayer 1's hand score: %d\nPlayer 2's hand score: %d\n",
               cardScore, 3, 9);
    }

    //Condition when cardScore returns 9 to match the score in player 2's hand 
    else if (cardScore == 9)
    {
        //Print that test failed
        printf("\n**** Test Failed ****\nReturned score matches player 2's hand score\n");

        //Print the actual score returned from scoreFor and the score in player 1's hand
        printf("Score returned from scoreFor(): %d\nPlayer 1's hand score: %d\nPlayer 2's hand score: %d\n",
               cardScore, 3, 9);
    }

    //Condition when cardScore returns a number that doesn't match player 1's or 2's hand score
    else 
    {
        //Print that test failed
        printf("\n**** Test Failed ****\nReturn score does not match player 1's or 2's score\n");

        //Print the actual score returned from scoreFor and the score in player 1's hand
        printf("Score returned from scoreFor(): %d\nPlayer 1's hand score: %d\nPlayer 2's hand score: %d\n",
               cardScore, 3, 9);
    }

    // ----- Print header for test case 2 -----
    printf("\nTEST CASE 2: Combining positive scores only\n");

    //Combine positive numbers into player 1's hand, discard pile, and deck
    for (i = 0; i < 3; i++)	
        gTest.hand[plyer1][i]	 = estate;	//Score of 3
    for (i = 0; i < 3; i++)
        gTest.discard[plyer1][i] = duchy;	//Score of 9
    for (i = 0; i < 3; i++)
        gTest.deck[plyer1][i]	 = province; 	//Score of 18
                 
    gTest.deck[plyer1][3] = great_hall;		//Score of 1
    gTest.deck[plyer1][4] = gardens;             //Score of 0 as there is a total of 5 cards in deck 
                                                //**Total score = 31

    //Assign 3 to player 1's hand and discard pile count 
    gTest.handCount[plyer1] = gTest.discardCount[plyer1] = 3;

    //Assign 5 to player 1's deck count
    gTest.deckCount[plyer1] = 5; 

    //Call function for player 1's score
    cardScore = scoreFor(plyer1, &gTest);

    //Condition when cardScore equals 31
    if (cardScore == 31)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print returned score from function and victory points player 1 has
        printf("Score returned from scoreFor(): %d\nPlayer 1's victory points: %d\n", cardScore, 31);
    }

    //Condition when there is a state change for player 2
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print returned score from function and victory points player 1 has
        printf("Score returned from scoreFor(): %d\nPlayer 1's victory points: %d\n", cardScore, 31);
    }

    // ----- Print header for test case 3 -----
    printf("\nTEST CASE 3: Score when player 1 has zero victory points\n");

    //Assign kingdom cards with zero victory points to player 1's hand, discard pile, and deck
    for (i = 0; i < 3; i++)
        gTest.hand[plyer1][i]    = smithy;      //Score of 0
    for (i = 0; i < 3; i++)
        gTest.discard[plyer1][i] = sea_hag;     //Score of 0
    for (i = 0; i < 3; i++)
        gTest.deck[plyer1][i]    = minion;    	//Score of 0

    //Assign 3 to player 1's hand, deck, and discard pile count 
    gTest.handCount[plyer1] = gTest.discardCount[plyer1] = gTest.deckCount[plyer1] = 3;

    //Call function for player 1's score
    cardScore = scoreFor(plyer1, &gTest);

    //Condition when cardScore returns 0
    if (cardScore == 0)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print returned score from function and victory points player 1 has
        printf("Score returned from scoreFor(): %d\nPlayer 1's victory points: %d\n", cardScore, 0);
    }

    //Condition when cardScore is greater than 0
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print returned score from function and victory points player 1 has
        printf("Score returned from scoreFor(): %d\nPlayer 1's victory points: %d\n", cardScore, 0);
    }

    // ----- Print header for test case 4 -----
    printf("\nTEST CASE 4: Combining scores with positive and negative victory points\n");

    //Assign victory and kingdom cards that have victory points
    for (i = 0; i < 3; i++)
        gTest.hand[plyer1][i]    = curse;      //Score of -3
    for (i = 0; i < 3; i++)
        gTest.discard[plyer1][i] = estate;     //Score of 3
    for (i = 0; i < 3; i++)
        gTest.deck[plyer1][i]    = duchy;      //Score of 9

    gTest.deck[plyer1][3] = curse;        	//Score of -1
    gTest.deck[plyer1][4] = province;           //Score of 6....Total score of 14

    //Assign 3 to player 1's hand and discard pile count
    gTest.handCount[plyer1] = gTest.discardCount[plyer1] = 3;

    //Assign 5 to player 1's deck count
    gTest.deckCount[plyer1] = 5;

    //Call function for player 1's score
    cardScore = scoreFor(plyer1, &gTest);

    //Condition when returned score matches player 1's victory points
    if (cardScore == 14)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print returned score from function and victory points player 1 has
        printf("Score returned from scoreFor(): %d\nPlayer 1's victory points: %d\n", cardScore, 14);
    }

    //Condition when score is less or greater than player 1's victory points
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print returned score from function and victory points player 1 has
        printf("Score returned from scoreFor(): %d\nPlayer 1's victory points: %d\n", cardScore, 14);
    }

    return 0;
}
