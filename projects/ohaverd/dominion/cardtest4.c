/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: cardtest4.c
 *
 * Unit test of card in dominion.c:
 *      great_hall
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
    int player1 = 0;
    int player2 = 1;
    int players = 2;
    int numTests = 1;                   // run each test once
    int card = great_hall;
    int initHandSize;
    int initNumActions;
    int position = 3;
    int effect;
    int postNumActions;
    // char gh_string[] = "great_hall";

    /**************************************************
    * The following conditions occur by the end of the great_hall case:
    * - current player draws 1 card
    * - game's numActions increases by 1
    * - played card (handPos) is discarded
    **************************************************/

     printf("** Card being tested: great_hall **\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        // int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

        // give the player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = estate;
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = great_hall;         // handPos = 3
        gameTest.hand[player1][4] = feast;

        initHandSize = gameTest.handCount[player1];
        initNumActions = gameTest.numActions;


        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        // after this, player should have the same amount of cards (1 drawn, 1 discarded)
        int postHandSize1;          // check with function call
        int postHandSize2 = 0;          // check iteratively - may not be necessary

        postHandSize1 = gameTest.handCount[player1];

        for (k = 0; k < gameTest.handCount[player1]; k++) {
            postHandSize2++;
        }

        /*** Testing that hand size hasn't changed ***/
        printf("TEST 1\n\n");
        if ((postHandSize1 == initHandSize) && (postHandSize2 == initHandSize)) {
            printf("*** Test passed ***\n");
            printf("Expected hand size of %d; function check was %d and iterative check was %d\n\n", initHandSize, postHandSize1, postHandSize2);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected hand size of %d; function check was %d and iterative check was %d\n\n", initHandSize, postHandSize1, postHandSize2);
        }

        printf("TEST 2\n\n");

        postNumActions = gameTest.numActions;

        /*** Testing the numActions increments by 1 ***/
        if (postNumActions == initNumActions + 1) {
            printf("*** Test passed ***\n");
            printf("Expected numActions of %d, actual numActions was %d\n\n", initNumActions, postNumActions);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected numActions of %d, actual numActions was %d\n\n", initNumActions, postNumActions);
        }

        printf("TEST 3\n\n");

        /*** Testing that other player's hand wasn't impacted by the card ***/

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
