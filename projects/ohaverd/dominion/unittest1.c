/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: unittest1.c
 *
 * Unit test of function in dominion.c:
 *      endTurn
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
    int i, k;                              // we'll probably need a counter at some point
    int player1;
    int players = 2;
    int numTests = 1;                   // run each test once
    int numHands;
    int resetCount;

    /**************************************************
    * The following conditions occur by the end of the endTurn function:
    * - every card in the player's hand's value is set to -1
    * - the handCount of current player is set to 0
    * - outpostPlayed set to 0
    * - phase set to 0
    * - numBuys set to 1
    * - numActions set to 1
    * - playedCardCount set to 0
    * - handCount of whoseTurn set to 0
    * - whoseTurn is set to anything other than currentPlayer
    **************************************************/

    printf("** Function being tested: endTurn **\n\n");

    for (i = 0; i < numTests; i++) {

       // assign player number
        player1 = 0;

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if hand count becomes zero after game ends ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = province;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;

        // first create a state where all values listed above are not at endTurn state
        gameTest.outpostPlayed = 1;
        gameTest.phase = 1;
        gameTest.numActions = 0;
        gameTest.coins = 1;
        gameTest.numBuys = 0;
        gameTest.playedCardCount = 1;
        gameTest.handCount[gameTest.whoseTurn] = 1;

        // then call endTurn and test values
        endTurn(&gameTest);

        printf("TEST 1\n\n");
        printf("Expecting hand count to be zero\n\n");

        if (gameTest.handCount[player1] == 0) {
            printf("*** Test passed ***\n\n");
            printf("handCount is %d\n\n", gameTest.handCount[player1]);
        }
        else {
            printf("*** Test failed ***\n\n");
            printf("handCount is %d\n\n", gameTest.handCount[player1]);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if all cards in the hand are set to -1 after game ends ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = province;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;


        // first create a state where all values listed above are not at endTurn state
        gameTest.outpostPlayed = 1;
        gameTest.phase = 1;
        gameTest.numActions = 0;
        gameTest.coins = 1;
        gameTest.numBuys = 0;
        gameTest.playedCardCount = 1;

        // then call endTurn and test values
        endTurn(&gameTest);

        printf("TEST 2\n\n");
        printf("Expecting all cards in hand to have a value of -1\n\n");
        // reset hand count to five
        gameTest.handCount[player1] = 5;

        resetCount = 0;
        numHands = 0;

        for (k = 0; k < gameTest.handCount[player1]; k++) {
            numHands++;
            if (gameTest.hand[player1][k] == -1) {
                resetCount++;
            }
        }

        if (numHands == resetCount) {
            printf("*** Test passed ***\n");
            printf("There are %d cards in the hand and %d have a value of -1.\n\n", numHands, resetCount);
        }
        else {
            printf("*** Test failed ***\n");
            printf("There are %d cards in the hand and %d have a value of -1.\n\n", numHands, resetCount);
        }

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        /*** Testing if all other minor state changes are correctly set after game ends ***/
        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = province;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = minion;
        gameTest.hand[player1][4] = feast;


        // first create a state where all values listed above are not at endTurn state
        gameTest.outpostPlayed = 1;
        gameTest.phase = 1;
        gameTest.numActions = 0;
        gameTest.coins = 1;
        gameTest.numBuys = 0;
        gameTest.playedCardCount = 1;

        // then call endTurn and test values
        endTurn(&gameTest);

        printf("TEST 3\n\n");
        printf("Expecting outpostPlayed to have value of 0\n\n");

        if (gameTest.outpostPlayed == 0) {
            printf("*** Test passed ***\n");
            printf("outpostPlayed has a value of %d.\n\n", gameTest.outpostPlayed);
        }
        else {
            printf("*** Test failed ***\n");
            printf("outpostPlayed has a value of %d.\n\n", gameTest.outpostPlayed);
        }

        printf("TEST 4\n\n");
        printf("Expecting phase to have value of 0\n\n");

        if (gameTest.phase == 0) {
            printf("*** Test passed ***\n");
            printf("phase has a value of %d.\n\n", gameTest.phase);
        }
        else {
            printf("*** Test failed ***\n");
            printf("phase has a value of %d.\n\n", gameTest.phase);
        }


        printf("TEST 5\n\n");
        printf("Expecting numActions to have value of 1\n\n");

        if (gameTest.numActions == 1) {
            printf("*** Test passed ***\n");
            printf("numActions has a value of %d.\n\n", gameTest.numActions);
        }
        else {
            printf("*** Test failed ***\n");
            printf("numActions has a value of %d.\n\n", gameTest.numActions);
        }

        printf("TEST 6\n\n");
        printf("Expecting numBuys to have value of 1\n\n");

        if (gameTest.numBuys == 1) {
            printf("*** Test passed ***\n");
            printf("numBuys has a value of %d.\n\n", gameTest.numBuys);
        }
        else {
            printf("*** Test failed ***\n");
            printf("numBuys has a value of %d.\n\n", gameTest.numBuys);
        }


        printf("TEST 7\n\n");
        printf("Expecting playedCardCount to have value of 0\n\n");

        if (gameTest.playedCardCount == 0) {
            printf("*** Test passed ***\n");
            printf("playedCardCount has a value of %d.\n\n", gameTest.playedCardCount);
        }
        else {
            printf("*** Test failed ***\n");
            printf("playedCardCount has a value of %d.\n\n", gameTest.playedCardCount);
        }


        printf("TEST 8\n\n");
        printf("Expecting handCount of player1 to have value of 0\n\n");

        if (gameTest.handCount[player1] == 0) {
            printf("*** Test passed ***\n");
            printf("handCount[player1] has a value of %d.\n", gameTest.handCount[player1]);
        }
        else {
            printf("*** Test failed ***\n");
            printf("handCount[player1] has a value of %d.\n", gameTest.handCount[player1]);
        }

    }

    return 0;
}

