/******************************************************************************
 * Program:	cardtest2.c	
 *
 * Author:	Jarrad Favre
 *
 * Date:	4-23-2016
 *
 * Description:	Part of assignment 3 for CS 362. Unit test for Adventurer card
 * from Dominion card game.
 ******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "Adventurer"

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
    int kCards[10] = {adventurer, embargo, village, minion, mine, 
                      cutpurse, sea_hag, tribute, smithy, steward};
    int seed        = 1000,
        numOfPlyers = 2,
        plyer1	    = 0,
        plyer2      = 1,
        handCount,
        p1DeckCount,
        p2DeckCount,
        p1DiscardCount,
        p2DiscardCount,
        topCard,
        nxt2Top,
        pos,
        discardTreasure,	//Boolean variable
        i;			//Needed for "for" loops

    //Initialize with number of players and kingdom cards being used
    initializeGame(numOfPlyers, kCards, seed, &gOrig);

    //Copy game state to test state
    memcpy(&gTest, &gOrig, sizeof(struct gameState));

    //Create a hand for player 1 to use for testing, which must include TESTCARD
    gTest.hand[plyer1][0] = kCards[4];	//mine
    gTest.hand[plyer1][1] = kCards[5];  //cutpurse
    gTest.hand[plyer1][2] = kCards[0];  //adventurer **Position 2
    gTest.hand[plyer1][3] = kCards[8];  //smithy     
    gTest.hand[plyer1][4] = kCards[3];  //minion

    //Assign more cards to player 1's deck, including silver and gold treasure cards
    gTest.deck[plyer1][gTest.deckCount[plyer1]]   = silver;
    gTest.deck[plyer1][gTest.deckCount[plyer1]+1] = silver;
    gTest.deck[plyer1][gTest.deckCount[plyer1]+2] = smithy;
    gTest.deck[plyer1][gTest.deckCount[plyer1]+3] = gold;
    gTest.deck[plyer1][gTest.deckCount[plyer1]+4] = minion;
    gTest.deck[plyer1][gTest.deckCount[plyer1]+5] = gold;

    //Update player 1's deck count
    gTest.deckCount[plyer1] += 5;

    //Assign player 1's current hand count to variable
    handCount = gTest.handCount[plyer1];

    //Assign player 1's current deck count to variable
    p1DeckCount = gTest.deckCount[plyer1];

    //Assign player 2's current deck count to variable
    p2DeckCount = gTest.deckCount[plyer2];

    //Assign hand position of TESTCARD to pos variable
    pos = 2;

    //Play TESTCARD in cardEffect function
    cardEffect(kCards[0], 0, 0, 0, &gTest, pos, 0);

    //Assign current count of cards in players discard  pile to variable
    p1DiscardCount = gTest.discardCount[plyer1];
    p2DiscardCount = gTest.discardCount[plyer2];

    //Print header for card being tested
    printf("\n-------------------- Testing Card %s --------------------\n", TESTCARD);
         
    // ------ Print header for test case 1 -----
    printf("\nTEST CASE 1: Player 1 has 2 treasure cards added to hand\n");

    //Assign top 2 cards in hand to variables
    topCard = gTest.hand[plyer1][gTest.handCount[plyer1]-1];
    nxt2Top = gTest.hand[plyer1][gTest.handCount[plyer1]-2];

    //Condition when top card is a treasure card
    if (topCard == copper || topCard == silver || topCard == gold)
    {
        //Condition when 2nd top card is treasure card
        if (nxt2Top == copper || nxt2Top == silver || nxt2Top == gold)
        { 
            //Print that test was successful
            printf("\n**** Test Successful ****\n");

            //Print expected hand count and players hand count and that last
            //two cards are treasure cards
            printf("Player 1's expected hand count: %d\nActual hand count: %d\n", 
                   handCount + 2, gTest.handCount[plyer1]);
            printf("\nTop 2 cards on Player 1's hand should be treasure cards\nTop Card = %s\n2nd Top Card = %s\n", 
                   cardNames[topCard], cardNames[nxt2Top]);
        }

        //Condition when 2nd top card is not a treasure card
        else
        {
            //Print that test failed
            printf("\n**** Test Failed ****\n");

            //Print expected hand count and players hand count and that last
            //two cards are treasure cards
            printf("Player 1's expected hand count: %d\nActual hand count: %d\n",
                   handCount + 2, gTest.handCount[plyer1]);
            printf("\nTop 2 cards on Player 1's hand should be treasure cards\nTop Card = %s\n2nd Top Card = %s\n",       
                   cardNames[topCard], cardNames[nxt2Top]);
        }
    } 

    //Condition when top card is not a treasure card
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expected hand count and player's actual hand count
        printf("Player 1's expected hand count: %d\nActual hand count: %d\n",
               handCount + 2, gTest.handCount[plyer1]);
        printf("\nTop 2 cards on Player 1's hand should be treasure cards\nTop Card = %s\n2nd Top Card = %s\n",
               cardNames[topCard], cardNames[nxt2Top]);
    }

    // ----- Print header for test case 2 -----
    printf("\nTEST CASE 2: No state change for player 2\n");

    //Condition when there is no state change for player 2
    if (gOrig.handCount[plyer2] == gTest.handCount[plyer2])
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print player 2's expected hand and actual hand
        printf("Player's 2 expected hand count: %d\nActual hand count: %d\n",
               gOrig.handCount[plyer2], gTest.handCount[plyer2]);
    }

    //Condition when there is a state change for player 2
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print player 2's expected hand and actual hand
        printf("Player's 2 expected hand count: %d\nActual hand count: %d\n",
               gOrig.handCount[plyer2], gTest.handCount[plyer2]);
    }

    // ----- Print header for test case 3 -----
    printf("\nTEST CASE 3: Cards were drawn from Player 1's deck and not Player's 2\n");

    //Condition when cards drawn from player 1 is successful
    if (p2DeckCount == gTest.deckCount[plyer2])
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print Expected and actual deck counts for Players 1 and 2
        printf("Player 1's expected deck count: %d\nActual deck count: %d\n", 
               p1DeckCount - p1DiscardCount - p2DiscardCount-2, gTest.deckCount[plyer1]);

        printf("\nPlayer 2's expected deck count: %d\nActual deck count: %d\n", p2DeckCount,
               gTest.deckCount[plyer2]);
    }

    //Condition when cards drawn from Player 2
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print Expected and actual deck counts for Players 1 and 2
        printf("Player 1's expected deck count: %d\nActual deck count: %d\n", 
               p1DeckCount - p1DiscardCount - p2DiscardCount-2, gTest.deckCount[plyer1]);    

        printf("\nPlayer 2's expected deck count: %d\nActual deck count: %d\n", p2DeckCount,
               gTest.deckCount[plyer2]);
    }

    // ----- Print header for test case 4 -----
    printf("\nTEST CASE 4: All treasure cards found are being kept and not discarded\n");

    //Assign boolean variable as false
    discardTreasure = 0;

    //Access each element in player 1's discard pile
    for (i = 0; i < p1DiscardCount; i++)
    {
        //Condition when treasure card found in discard pile
        if (gTest.discard[plyer1][i] == copper || gTest.discard[plyer1][i] == silver || gTest.discard[plyer1][i] == gold)
        {
            //Set boolean to true
            discardTreasure = 1;

            //Print that test failed
            printf("\n**** Test Failed ****\n");
            
            break;	//Break from loop
        } 
    }

    //Condition when treasure card not sent to discard pile
    if (!discardTreasure)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");
    }

    //Print contents of player 1's discard pile
    printf("\nPlayer 1's discarded cards should not have treasure cards in them\n");

    for (i = 0; i < p1DiscardCount; i++)
        printf("%s\n", cardNames[gTest.discard[plyer1][i]]);
    
    // ----- Print header for test case 5 -----
    printf("\nTEST CASE 5: Cards to be discarded should not be discarded in Player 2's discard pile\n");

    //Condition when player 2's discard pile is empty
    if (p2DiscardCount == 0)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expected discard count and actual discard count
        printf("Player 2's discard pile count: %d\nActual discard count: %d\n", 0, p2DiscardCount);
    }

    //Condition when player 2's discard pile is greater than 0
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expected discard count and actual discard count
        printf("Player 2's discard pile count: %d\nActual discard count: %d\n", 0, p2DiscardCount);
    
        // ----- Print header for test case 6 -----
        printf("\nTEST CASE 6: Player 2's discard pile should not have treasure cards discarded\n");

        //Assign boolean variable as false
        discardTreasure = 0;

        //Access each element in player 2's discard pile
        for (i = 0; i < p2DiscardCount; i++)
        {
            //Condition treasure card is found in discard pile
            if (gTest.discard[plyer2][i] == copper || gTest.discard[plyer2][i] == silver || gTest.discard[plyer2][i] == gold)
            {
                //Set boolean to true
                discardTreasure = 1;
            
                //Print that test failed
                printf("\n**** Test Failed ****\n");
            
                break;      //Break from loop
            }
        }

        //Condition when treasure card not sent to discard pile
        if (!discardTreasure)
        {
            //Print that test was successful
            printf("\n**** Test Successful ****\n");
        }

        //Print contents of player 2's discard pile
        printf("\nPlayer 2's discarded cards should not have treasure cards in them\n");

        for (i = 0; i < p2DiscardCount; i++)
            printf("%s\n", cardNames[gTest.discard[plyer2][i]]);
    }

    return 0;
}
