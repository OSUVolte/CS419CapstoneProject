/******************************************************************************
 * Program:	unittest1.c	
 *
 * Author:	Jarrad Favre
 *
 * Date:	4-23-2016
 *
 * Description:	Part of assignment 3 for CS 362. Unit test for discardCard() 
 * function from Dominion card game.
 ******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTFUNC "discardCard()"

int main()
{
    //Assign strings that correspond to the order in enum CARDS
    char *cardNames[] = {"curse", "estate", "duchy", "province", "copper", "silver",
                        "gold", "adventurer", "council room", "feast", "gardens",
                        "mine", "remodel", "smithy", "village", "baron", "great hall",
                        "minion", "steward", "tribute", "ambassador", "cutpurse",
                        "embargo", "outpost", "salvager", "sea hag", "treasure map"};

    //Declare variables
    struct gameState gOrig, gTest;	//Two gameState structures to make
					//one as original and one as test

    //Hardcore 10 kingdom cards into an array
    int kCards[10] = {adventurer, gardens, village, minion, council_room, 
                      cutpurse, sea_hag, tribute, smithy, steward};
    int seed         = 1000,
        numOfPlyers  = 2,
        plyer1	     = 0,
        pos;

    //Initialize with number of players and kingdom cards being used
    initializeGame(numOfPlyers, kCards, seed, &gOrig);

    //Copy game state to test state
    memcpy(&gTest, &gOrig, sizeof(struct gameState));

    //Print header for card being tested
    printf("\n-------------------- Testing Function %s --------------------\n", TESTFUNC);
         
    // ----- Print header for test case 1 -----
    printf("\nTEST CASE 1: Trashed card does not show up in played cards pile\n");

    //Assemble a card hand for player 1
    gTest.hand[plyer1][0] = adventurer;
    gTest.hand[plyer1][1] = smithy;
    gTest.hand[plyer1][2] = minion;

    //Assign current hand card count to 3
    gTest.handCount[plyer1] = 3;
   
    //Assign 0 to pos to discard adventurer
    pos = 0;

    //Call function with position 0 for adventurer and trash parameter set true
    discardCard(pos, plyer1, &gTest, 1);

    //Condition when card is trash and nothing added to played cards pile
    if (gTest.playedCardCount == 0)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print the expect amout of cards in played cards pile and the actual amount
        printf("Expect amount of cards in played cards pile: %d\nActual amount: %d\n",
               0, gTest.playedCardCount);
    }

    //Condition when card is not trashed and added to played pile 
    else 
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print the expect amout of cards in played cards pile and the actual amount
        printf("Expect amount of cards in played cards pile: %d\nActual amount: %d\n",
               0, gTest.playedCardCount);
    }

    // ----- Print header for test case 2 -----
    printf("\nTEST CASE 2: Discarded card added to played cards pile\n");

    //Assemble a different card hand for player 1
    gTest.hand[plyer1][0] = sea_hag;
    gTest.hand[plyer1][1] = gold;
    gTest.hand[plyer1][2] = copper;
    gTest.hand[plyer1][3] = gardens; 

    //Assign 3 to player 1's hand count 
    gTest.handCount[plyer1] = 4;

    //Assign 1 to pos to discard gold
    pos = 1;

    //Call function with position 1 and trash parameter set false
    discardCard(pos, plyer1, &gTest, 0);

    //Condition when card is trash and nothing added to played cards pile
    if (gTest.playedCardCount == 0)
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print the expect amout of cards in played cards pile and the actual amount
        printf("Expect amount of cards in played cards pile: %d\nActual amount: %d\n",
               1, gTest.playedCardCount);
    }

    //Condition when card is not trashed and added to played pile 
    else
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print the expect amout of cards in played cards pile and the actual amount
        printf("Expect amount of cards in played cards pile: %d\nActual amount: %d\n",
               1, gTest.playedCardCount);
    }

    //Zero out played card counter
    gTest.playedCardCount = 0;

    // ----- Print header for test case 3 -----
    printf("\nTEST CASE 3: Hand count shows 0 when player only has 1 card on hand to discard\n");

    //Assemble a hand consisting of one card for player 1
    gTest.hand[plyer1][0] = province;

    //Assign 1 to player 1's hand 
    gTest.handCount[plyer1] = 1;

    //Assign 0 to pos to discard province
    pos = 0;

    //Call function with position 0 and trash parameter set false
    discardCard(pos, plyer1, &gTest, 0);

    //Condition when player 1's hand count equals 0
    if (gTest.handCount[plyer1] == 0)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expect count of cards Player 1 should have in their hand and the actual amount
        printf("Player 1's expected count of count for their hand: %d\nActual count: %d\n", 0, gTest.handCount[plyer1]);
    }

    //Condition when player 1's hand count is greater than 0
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expect count of cards Player 1 should have in their hand and the actual amount
        printf("Player 1's expected count of count for their hand: %d\nActual count: %d\n", 0, gTest.handCount[plyer1]);
    }

    //Zero out played card counter
    gTest.playedCardCount = 0;

    // ----- Print header for test case 4 -----
    printf("\nTEST CASE 4: Hand count has a value of 1 after player discards card with a hand of 2 cards\n");

    //Assemble a hand consisting of 2 cards for player 1
    gTest.hand[plyer1][0] = curse;
    gTest.hand[plyer1][1] = minion;

    //Assign 2 to player 1's hand count
    gTest.handCount[plyer1] = 2;

    //Assign 1 to pos to discard minion
    pos = 1;

    //Call function with position 0 and trash parameter set false
    discardCard(pos, plyer1, &gTest, 0);

    //Condition when player 1's hand count equals 1
    if (gTest.handCount[plyer1] == 1)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expect count of cards Player 1 should have in their hand and the actual amount
        printf("Player 1's expected count of count for their hand: %d\nActual count: %d\n", 1, gTest.handCount[plyer1]);
    }

    //Condition when player 1's hand count is greater than or less than 1
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expect count of cards Player 1 should have in their hand and the actual amount
        printf("Player 1's expected count of count for their hand: %d\nActual count: %d\n", 1, gTest.handCount[plyer1]);
    }

    //Zero out played card counter
    gTest.playedCardCount = 0;

    // ----- Print header for test case 5 -----
    printf("\nTEST CASE 5: When player has a hand greater than 3, the discarded card is replaced with the last card on hand\n");

    //Assemble a hand for player 1
    gTest.hand[plyer1][0] = gardens;
    gTest.hand[plyer1][1] = minion;
    gTest.hand[plyer1][2] = smithy;
    gTest.hand[plyer1][3] = great_hall;
    gTest.hand[plyer1][4] = village;

    //Assign 5 to to player 1's hand count
    gTest.handCount[plyer1] = 5;

    //Assign 3 for great hall to pos
    pos = 3;

    //Call function with position 3 and trash parameter set false
    discardCard(pos, plyer1, &gTest, 0);

    //Condition when hand pos is replace with last card in hand (village)
    if (gTest.hand[plyer1][pos] == village)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expected card to replaced the one discard and the one that replaced the discarded
        printf("Expected card to replaced discarded one in player 1's hand: %s\nThe actual card that replaced it: %s\n",
               cardNames[14], cardNames[gTest.hand[plyer1][pos]]);
    }

    //Condition when hand pos is replaced with card that is not the last hand card 
    else 
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expected card to replaced the one discard and the one that replaced the discarded
        printf("Expected card to replaced discarded one in player 1's hand: %s\nThe actual card that replaced it: %s\n",
               cardNames[14], cardNames[gTest.hand[plyer1][pos]]);
    }

    //Zero out played card counter
    gTest.playedCardCount = 0;

    return 0;
}
