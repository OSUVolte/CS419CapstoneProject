/******************************************************************************
 * Program:	cardtest4.c	
 *
 * Author:	Jarrad Favre
 *
 * Date:	4-23-2016
 *
 * Description:	Part of assignment 3 for CS 362. Unit test for Sea Hag card
 * from Dominion card game.
 ******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "Sea Hag"

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
    int kCards[10] = {adventurer, embargo, village, minion, council_room, 
                      cutpurse, sea_hag, tribute, smithy, steward};
    int seed        = 1000,
        numOfPlyers = 2,
        plyer1	    = 0,
        plyer2      = 1,
        p2DeckCount,
        p1DiscardCount,
        p2DiscardCount,
        pos;

    //Initialize with number of players and kingdom cards being used
    initializeGame(numOfPlyers, kCards, seed, &gOrig);

    //Copy game state to test state
    memcpy(&gTest, &gOrig, sizeof(struct gameState));

    //Create a hand for player 1 to use for testing, which must include TESTCARD
    gTest.hand[plyer1][0] = kCards[4];	//council room 
    gTest.hand[plyer1][1] = kCards[6];  //cutpurse	**Position 1; kCard pos = 6
    gTest.hand[plyer1][2] = kCards[0];  //adventurer
    gTest.hand[plyer1][3] = kCards[8];  //smithy     
    gTest.hand[plyer1][4] = kCards[3];  //minion

    //Assign player 2's current deck count to variable
    p2DeckCount = gTest.deckCount[plyer2];

    //Assign hand position of TESTCARD to pos variable
    pos = 1;

    //Play TESTCARD in cardEffect function
    cardEffect(kCards[6], 0, 0, 0, &gTest, pos, 0);

    //Assign current count of cards in players discard  pile to variable
    p1DiscardCount = gTest.discardCount[plyer1];
    p2DiscardCount = gTest.discardCount[plyer2];

    //Print header for card being tested
    printf("\n-------------------- Testing Card %s --------------------\n", TESTCARD);
         
    // ----- Print header for test case 1 -----
    printf("\nTEST CASE 1: Player 1 should not have discarded top card in deck and replace it with curse card\n");

    //Condition when player 1's top card was not discarded and replaced with curse card
    if (gTest.deck[plyer1][gTest.deckCount[plyer1]-1] != curse)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print Expected and actual amount of cards in player 2's discard pile, then count of player 1's
        printf("Player 1's expected count of cards in discard pile: %d\nActual count of cards in discard pile: %d\n",
               0, p1DiscardCount);
        printf("Player 1's top card: %s\n", cardNames[gTest.deck[plyer1][gTest.deckCount[plyer1]-1]]);
    }

    //Condition when player 1's top card was discarded and replaced with curse card
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print Expected and actual amount of cards in player 2's discard pile, then count of player 1's
        printf("Player 1's expected count of cards in discard pile: %d\nActual count of cards in discard pile: %d\n",
               0, p1DiscardCount);
        printf("Player 1's top card: %s\n", cardNames[gTest.deck[plyer1][gTest.deckCount[plyer1]-1]]);
    }

    // ----- Print header for test case 2 -----
    printf("\nTEST CASE 2: Player 2's top card in deck was discarded and replaced with curse card\n");

    //Condition when player 2's top card in deck was discarded
    if (p2DeckCount == gTest.deckCount[plyer2])
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print the expected number of cards in Player 2's deck and actual number and top card from deck
        printf("Expected number of cards in deck: %d\nActual number of cards in deck: %d\n",
               p2DeckCount, gTest.deckCount[plyer2]);
        printf("Player 2's top card: %s\n", cardNames[gTest.deck[plyer2][gTest.deckCount[plyer2]-1]]);
    }

    //Condition when there is a state change for player 2
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print the expected number of cards in Player 2's deck and actual number and top card from deck
        printf("Expected number of cards in deck: %d\nActual number of cards in deck: %d\n",
               p2DeckCount, gTest.deckCount[plyer2]);
        printf("Player 2's top card: %s\n", cardNames[gTest.deck[plyer2][gTest.deckCount[plyer2]-1]]);
    }

    // ----- Print header for test case 3 -----
    printf("\nTEST CASE 3: Player 2's top card was discarded in their discard pile\n");

    //Condition when player 2's original top card was discarded in their discard pile
    if (1 == p2DiscardCount)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print Expected and actual amount of cards in player 2's discard pile, then count of player 1's
        printf("Player 2's expected count of cards in discard pile: %d\nActual count of cards in discard pile: %d\n", 
               1, p2DiscardCount);
        printf("Count of cards in player 1's discard pile: %d\n", p1DiscardCount);
    }

    //Condition when player 2's original top card was not discarded in their discard pile
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print Expected and actual amount of cards in player 2's discard pile, then count of player 1's
        printf("Player 2's expected count of cards in discard pile: %d\nActual count of cards in discard pile: %d\n", 
               1, p2DiscardCount);
        printf("Count of cards in player 1's discard pile: %d\n", p1DiscardCount);
    }

    return 0;
}
