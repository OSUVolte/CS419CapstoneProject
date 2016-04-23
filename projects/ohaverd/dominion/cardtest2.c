/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: cardtest2.c
 *
 * Unit test of card in dominion.c:
 *      adventurer
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct gameState gameOrig;          // original game state
    // to initialize the game, you need the number of players, kingdom cards, a random seed, and the game state
    struct gameState gameTest;          // game state for testing
    int kc[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int i;                              // we'll probably need a counter at some point
    int player1 = 0;
    int player2 = 1;
    int players = 2;
    int numTests = 1;                   // run each test once
    int card = adventurer;
    int effect;
    int position = 1;

    /**************************************************
    * The following conditions occur by the end of the adventurer case:
    * - while drawntreasure is less than 2
    *       i. if deck is empty, discard is shuffled
    *       ii. player draws a card
    *       iii. card at the top of the hand is most recently drawn
    *       iv. if card drawn is a treasure card, drawn treasure increases by 1
    *       v. if not, player's hand count reduced by 1
    * - once drawntreasure is greater than 2
    *       i. all cards in play that have been drawn are discarded
    **************************************************/

     printf("** Card being tested: adventurer **\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        gameTest.whoseTurn = player1;

        /*** Testing when drawing two treasure cards in a row ***/
        // put some cards in the deck
        gameTest.deck[player1][0] = copper;     // drawntreasure +1
        gameTest.deck[player1][1] = copper;     // drawntreasure +1
        gameTest.deck[player1][2] = copper;     // should not reach this one
        gameTest.deck[player1][3] = duchy;
        gameTest.deck[player1][4] = copper;

        gameTest.deckCount[player1] = 5;

        // give the player a hand
        gameTest.hand[player1][0] = minion;
        gameTest.hand[player1][1] = adventurer;             // handPos = 1
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = great_hall;
        gameTest.hand[player1][4] = feast;

        gameTest.handCount[player1] = 5;

        int initHandCount = gameTest.handCount[player1];
        int initDeckCount = gameTest.deckCount[player1];

        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        int postHandCount = gameTest.handCount[player1];
        int postDeckCount = gameTest.deckCount[player1];

        printf("TEST 1\n\n");

        if (postHandCount == initHandCount + 2) {
            printf("*** Test passed ***\n");
            printf("Expected postHandCount of %d, actual postHandCount was %d\n\n", initHandCount+2, postHandCount);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected postHandCount of %d, actual postHandCount was %d\n\n", initHandCount+2, postHandCount);
        }

        printf("TEST 2\n\n");

        if (postDeckCount == initDeckCount - 2) {
            printf("*** Test passed ***\n");
            printf("Expected postDeckCount of %d, actual postDeckCount was %d\n\n", initDeckCount-2, postDeckCount);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected postDeckCount of %d, actual postDeckCount was %d\n\n", initDeckCount-2, postDeckCount);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        gameTest.whoseTurn = player1;

        /*** Testing that, if deck is empty, discard being shuffled and re-added to deck ***/
        initDeckCount = gameTest.deckCount[player1] = 0;

        gameTest.discard[player1][0] = copper;
        gameTest.discard[player1][1] = copper;
        gameTest.discard[player1][2] = copper;
        gameTest.discard[player1][3] = duchy;
        gameTest.discard[player1][4] = estate;
        gameTest.discard[player1][5] = estate;
        gameTest.discard[player1][6] = great_hall;

        int initDiscardCount = gameTest.discardCount[player1] = 7;

        // give the player a hand
        gameTest.hand[player1][0] = minion;
        gameTest.hand[player1][1] = adventurer;             // handPos = 1

        initHandCount = gameTest.handCount[player1] = 2;

        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        postDeckCount = gameTest.deckCount[player1];

        int postDiscardCount = gameTest.discardCount[player1];

        printf("TEST 3\n\n");

        // should be 1 for the discarded adventurer card
        if (postDiscardCount == initDeckCount + 1) {
            printf("*** Test passed ***\n");
            printf("Expected postDiscardCount of %d, actual postDiscardCount was %d\n\n", initDeckCount+1, postDiscardCount);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected postDiscardCount of %d, actual postDiscardCount was %d\n\n", initDeckCount+1, postDiscardCount);
        }

        printf("TEST 4\n\n");

        // should be 5 because the two copper cards drawn
        if (postDeckCount == initDiscardCount - 2) {
            printf("*** Test passed ***\n");
            printf("Expected postDeckCount of %d, actual postDiscardCount was %d\n\n", initDiscardCount-2, postDeckCount);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected [postDeckCount of %d, actual postDiscardCount was %d\n\n", initDiscardCount-2, postDeckCount);
        }

        /*** Testing that card draw has no impact on player2 ***/

        printf("TEST 5\n\n");
        if (gameTest.handCount[player2] == gameOrig.handCount[player2]) {
            printf("*** Test passed ***\n");
            printf("Expected hand size of %d for player2, actual hand size was %d\n\n", gameOrig.handCount[player2], gameTest.handCount[player2]);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected hand size of %d for player2, actual hand size was %d\n\n", gameOrig.handCount[player2], gameTest.handCount[player2]);
        }

    }
    return 0;
}
