/* -----------------------------------------------------------------------
 * Diana O'Haver
 * File: cardtest1.c
 *
 * Unit test of card in dominion.c:
 *      smithy
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
    int card = smithy;
    int effect;
    int initHandCount;
    int position;

    /**************************************************
    * The following conditions occur by the end of the smithy case:
    * - current player draws 3 cards
    * - current player discards a card from their hand
    **************************************************/

     printf("** Card being tested: smithy **\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        // give the player a hand
        gameTest.hand[player1][0] = minion;
        gameTest.hand[player1][1] = smithy;             // handPos = 1
        gameTest.hand[player1][2] = minion;
        gameTest.hand[player1][3] = great_hall;
        gameTest.hand[player1][4] = feast;

        initHandCount = gameTest.handCount[player1];
        position = gameTest.hand[player1][1];

        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        printf("TEST 1\n\n");
        /*** Testing that current player has drawn 3 cards ***/
        if (gameTest.handCount[player1] == initHandCount + 2) {
            printf("*** Test passed ***\n");
            printf("Expected hand count of %d, actual hand count is %d\n\n", initHandCount+2, gameTest.handCount[player1]);
        }
        else {
            printf("*** Test failed ***\n");
            printf("Expected hand count of %d, actual hand count is %d\n\n", initHandCount+2, gameTest.handCount[player1]);
        }

        printf("TEST 2\n\n");

        /*** Testing that card draw has no impact on player2 ***/

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
